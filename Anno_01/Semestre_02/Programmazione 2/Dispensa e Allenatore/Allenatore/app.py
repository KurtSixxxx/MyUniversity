#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Allenatore Prog2 - app desktop per allenarsi all'esame di Programmazione 2.

Interfaccia: HTML/CSS/JS (cartella web/) in una finestra WebView2 (pywebview).
Logica: motore.py (lettura della dispensa, compilazione con g++, progressi).

Sviluppo:      .ambiente\\Scripts\\python app.py
Eseguibile:    crea_app.bat
"""
import os
import sys
import threading

import webview

import motore as M


class Api:
    """Metodi chiamabili dal JavaScript come window.pywebview.api.<nome>(...)."""

    def __init__(self):
        self._finestra = None
        self._blocco = threading.Lock()
        M.migra_vecchi_dati()
        self._imp = M.carica_impostazioni()
        self._gpp = M.trova_gpp()
        self._catalogo = None
        self._errore = None
        self._carica()

    def _carica(self):
        try:
            self._catalogo = M.carica_catalogo(self._imp.get('dispensa', ''))
            self._errore = None
        except Exception as e:  # mostrato nell'interfaccia
            self._catalogo, self._errore = None, str(e)

    # ---------------------------------------------------------------- avvio
    def avvio(self):
        return {'catalogo': self._catalogo, 'errore': self._errore,
                'progressi': M.carica_progressi(), 'impostazioni': self._imp,
                'gpp': self._gpp, 'versione': M.APP_VERSIONE, 'cartella_dati': M.DATI_UTENTE}

    def ricarica(self):
        self._carica()
        return self.avvio()

    # ---------------------------------------------------------------- salvataggi
    def salva_progressi(self, progressi):
        with self._blocco:
            M.salva_progressi(progressi)
        return True

    def salva_impostazioni(self, impostazioni):
        with self._blocco:
            self._imp.update(impostazioni or {})
            M.salva_impostazioni(self._imp)
        return True

    def azzera_progressi(self):
        with self._blocco:
            M.salva_progressi({'quiz': {}, 'orale': {}, 'esercizi': {}, 'simulazioni': []})
        return M.carica_progressi()

    # ---------------------------------------------------------------- codice
    def leggi_codice(self, id_):
        return M.leggi_lavoro(id_)

    def salva_codice(self, id_, codice):
        M.salva_lavoro(id_, codice)
        return True

    def esegui(self, id_, codice, ingresso, tempo_max=10):
        if not self._gpp:
            self._gpp = M.trova_gpp()
        if not self._gpp:
            return {'compilato': False, 'senza_compilatore': True, 'diagnostica': [],
                    'messaggi': 'Non trovo il compilatore g++. Installa MSYS2/MinGW e aggiungi '
                                'la cartella di g++ al PATH, poi riavvia l\'app.'}
        try:
            return M.esegui_codice(self._gpp, id_, codice, ingresso or '', int(tempo_max or 10))
        except Exception as e:
            return {'compilato': False, 'diagnostica': [], 'messaggi': 'Errore interno: %s' % e}

    def confronta(self, atteso, ottenuto):
        return M.confronta_output(atteso, ottenuto)

    # ---------------------------------------------------------------- sistema
    def scegli_dispensa(self):
        scelta = self._finestra.create_file_dialog(webview.FileDialog.FOLDER) if self._finestra else None
        if not scelta:
            return None
        cartella = scelta[0] if isinstance(scelta, (list, tuple)) else scelta
        if not M.e_dispensa(cartella):
            return {'errore': 'In questa cartella non c\'è la dispensa (manca modulo01.tex o codice/).'}
        self._imp['dispensa'] = cartella
        M.salva_impostazioni(self._imp)
        return self.ricarica()

    def copia_appunti(self, testo):
        """Copia testo ASCII (il codice dei progressi) negli appunti di Windows."""
        try:
            import subprocess
            subprocess.run(['clip'], input=testo.encode('ascii', 'ignore'), check=True,
                           creationflags=0x08000000 if os.name == 'nt' else 0)
            return True
        except Exception:
            return False

    def apri_link(self, url):
        import webbrowser
        if isinstance(url, str) and url.startswith('https://'):
            webbrowser.open(url)
        return True

    def accedi_spotify(self):
        """Finestra di accesso a Spotify. Condivide i cookie con l'app (stesso profilo
        WebView2), quindi dopo l'accesso il lettore incorporato suona i brani interi."""
        f = webview.create_window(
            'Accedi a Spotify', 'https://accounts.spotify.com/it/login?continue=https%3A%2F%2Fopen.spotify.com%2F',
            width=520, height=800, background_color='#000000')

        def chiusa():
            try:
                self._finestra.evaluate_js('window.dopoLoginSpotify && window.dopoLoginSpotify()')
            except Exception:
                pass
        f.events.closed += chiusa
        return True

    # ---------------------------------------------------------------- VS Code
    def _cartella_vscode(self):
        return self._imp.get('cartella_vscode') or M.cartella_vscode_predefinita(self._catalogo or {})

    def stato_vscode(self):
        c = self._cartella_vscode()
        return {'cartella': c, 'esiste': os.path.isfile(os.path.join(c, '.vscode', 'tasks.json')),
                'vscode': bool(M.trova_vscode())}

    def crea_vscode(self, apri=False):
        if not self._catalogo:
            return {'errore': 'Contenuti non caricati.'}
        try:
            r = M.crea_cartella_vscode(self._catalogo, self._cartella_vscode(), self._gpp)
        except OSError as e:
            return {'errore': 'Non riesco a scrivere la cartella: %s' % e}
        if apri and not M.apri_in_vscode(r['cartella']):
            r['senza_vscode'] = True
        return r

    def scegli_cartella_vscode(self):
        scelta = self._finestra.create_file_dialog(webview.FileDialog.FOLDER) if self._finestra else None
        if not scelta:
            return None
        cartella = scelta[0] if isinstance(scelta, (list, tuple)) else scelta
        if os.listdir(cartella) and not os.path.isfile(os.path.join(cartella, '.vscode', 'tasks.json')):
            cartella = os.path.join(cartella, 'Esercizi VS Code')   # non sporcare una cartella piena
        self._imp['cartella_vscode'] = cartella
        M.salva_impostazioni(self._imp)
        return self.stato_vscode()

    def apri_vscode(self, id_):
        """Apre l'esercizio in VS Code (crea la cartella o il file se mancano)."""
        c = self._cartella_vscode()
        f = M.trova_file_vscode(c, id_)
        if not f:
            r = self.crea_vscode()
            if r.get('errore'):
                return r
            f = M.trova_file_vscode(c, id_)
        if not M.apri_in_vscode(c, f):
            return {'errore': 'Non trovo VS Code. Il file è qui: %s' % (f or c)}
        return {'file': f}

    def importa_vscode(self, id_):
        f = M.trova_file_vscode(self._cartella_vscode(), id_)
        if not f:
            return {'errore': 'Questo esercizio non c\'è ancora nella cartella di VS Code.'}
        with open(f, encoding='utf-8', errors='replace') as h:
            codice = h.read().replace('\r\n', '\n')
        return {'file': f, 'codice': M.togli_consegna(codice)}

    def apri_cartella_dati(self):
        os.makedirs(M.DATI_UTENTE, exist_ok=True)
        os.startfile(M.DATI_UTENTE)
        return True

    def barra_titolo(self, scuro, colore):
        """Colora la barra del titolo di Windows 11 come lo sfondo dell'app."""
        if os.name != 'nt' or not self._finestra:
            return False
        try:
            import ctypes
            from ctypes import wintypes
            hwnd = ctypes.windll.user32.FindWindowW(None, self._finestra.title)
            if not hwnd:
                return False
            dwm = ctypes.windll.dwmapi.DwmSetWindowAttribute
            valore = ctypes.c_int(1 if scuro else 0)
            dwm(wintypes.HWND(hwnd), 20, ctypes.byref(valore), 4)            # modalità scura
            c = colore.lstrip('#')
            rgb = int(c[4:6] + c[2:4] + c[0:2], 16)                         # COLORREF = 0x00BBGGRR
            dwm(wintypes.HWND(hwnd), 35, ctypes.byref(ctypes.c_int(rgb)), 4)  # colore della barra
            testo = 0xF5F5F5 if scuro else 0x1F1D1D
            dwm(wintypes.HWND(hwnd), 36, ctypes.byref(ctypes.c_int(testo)), 4)
            return True
        except Exception:
            return False


def avvia(dopo_avvio=None):
    api = Api()
    tema = api._imp.get('tema', 'auto') if api._imp.get('tema_terminale_proposto') else 'hacker'
    scuro = tema in ('scuro', 'hacker') or (tema == 'auto' and windows_scuro())
    # il tema salvato, letto da index.html prima del primo disegno (niente lampo di colore)
    try:
        with open(os.path.join(M.RISORSE, 'web', 'tema-iniziale.js'), 'w', encoding='utf-8') as f:
            f.write('window.TEMA_INIZIALE = %r;\n' % tema)
    except OSError:
        pass
    # musica dell'intro senza dover prima premere un tasto
    os.environ['WEBVIEW2_ADDITIONAL_BROWSER_ARGUMENTS'] = (
        '--disable-features=ElasticOverscroll --allow-file-access-from-files --autoplay-policy=no-user-gesture-required')
    larg, alt, x, y, ingrandita = 1440, 900, None, None, False
    if os.name == 'nt':
        try:
            import ctypes
            from ctypes import wintypes
            # area di lavoro (senza barra delle applicazioni) in pixel logici:
            # il processo qui non ha ancora dichiarato la consapevolezza DPI
            # (lo fa pywebview all'avvio), quindi Windows restituisce misure logiche
            area = wintypes.RECT()
            ctypes.windll.user32.SystemParametersInfoW(0x0030, 0, ctypes.byref(area), 0)
            lw, lh = area.right - area.left, area.bottom - area.top
            # schermo da portatile: si apre a tutto schermo, come le app di sistema
            ingrandita = lw < larg + 80 or lh < alt + 80
            larg, alt = min(larg, lw - 40), min(alt, lh - 40)
            x, y = area.left + (lw - larg) // 2, area.top + (lh - alt) // 2
        except Exception:
            pass
    finestra = webview.create_window(
        M.APP_NOME, url=os.path.join(M.RISORSE, 'web', 'index.html'), js_api=api,
        width=larg, height=alt, x=x, y=y, maximized=ingrandita,
        min_size=(min(1100, larg), min(660, alt)),
        background_color='#000000' if scuro else '#F5F5F7', text_select=True)
    api._finestra = finestra
    icona = os.path.join(M.RISORSE, 'icona.ico')
    if not os.path.isfile(icona):
        icona = os.path.join(M.QUI, 'risorse', 'icona.ico')
    opzioni = {'icon': icona} if os.path.isfile(icona) else {}
    # server locale (http://127.0.0.1): YouTube non suona da file://
    # profilo persistente: l'accesso a Spotify resta valido tra un avvio e l'altro
    opzioni.update(http_server=True, private_mode=False, storage_path=os.path.join(M.DATI_UTENTE, 'webview'))
    if dopo_avvio:
        webview.start(dopo_avvio, finestra, **opzioni)
    else:
        webview.start(**opzioni)


def windows_scuro():
    """True se Windows usa il tema scuro per le app."""
    try:
        import winreg
        with winreg.OpenKey(winreg.HKEY_CURRENT_USER,
                            r'Software\Microsoft\Windows\CurrentVersion\Themes\Personalize') as k:
            return winreg.QueryValueEx(k, 'AppsUseLightTheme')[0] == 0
    except Exception:
        return False


if __name__ == '__main__':
    avvia()
