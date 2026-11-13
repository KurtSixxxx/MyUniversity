#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Motore dell'Allenatore Prog2: lettura della dispensa, compilazione, progressi.

Legge i contenuti direttamente dai sorgenti LaTeX della dispensa:
  - quiz a crocette con risposte commentate (moduli + simulazione d'esame)
  - domande d'orale con risposta modello
  - esercizi al PC, laboratori a step, pattern e laboratorio della simulazione,
    con compilazione g++, esecuzione e confronto con l'output atteso.
Se la dispensa non si trova, usa la copia dei contenuti inclusa nell'app (contenuti.json).

Verifica senza interfaccia:  python motore.py --test
Copia dei contenuti per l'eseguibile:  python motore.py --copia contenuti.json
"""
import datetime
import difflib
import html
import io
import json
import os
import random
import re
import shutil
import subprocess
import sys
import time

APP_NOME = 'Allenatore Prog2'
APP_VERSIONE = '3.5'
CONGELATO = getattr(sys, 'frozen', False)
QUI = os.path.dirname(os.path.abspath(__file__))
RISORSE = getattr(sys, '_MEIPASS', QUI)                       # file inclusi nell'app
CARTELLA_EXE = os.path.dirname(sys.executable) if CONGELATO else QUI
MAC = sys.platform == 'darwin'
# dati dello studente: %APPDATA% su Windows, ~/Library/Application Support sul Mac
DATI_UTENTE = os.environ.get('ALLENATORE_DATI') or (
    os.path.join(os.path.expanduser('~'), 'Library', 'Application Support', APP_NOME) if MAC
    else os.path.join(os.environ.get('APPDATA') or os.path.expanduser('~'), APP_NOME))
DISPENSA = os.path.normpath(os.path.join(QUI, '..', 'Dispensa'))
LAVORI = os.path.join(DATI_UTENTE, 'lavori')
FILE_PROGRESSI = os.path.join(DATI_UTENTE, 'progressi.json')
FILE_IMPOSTAZIONI = os.path.join(DATI_UTENTE, 'impostazioni.json')
DATA_ESAME_PREDEFINITA = ''   # ognuno imposta il suo appello al primo avvio

# =====================================================================
#  1. CONVERSIONE LaTeX -> testo con marcatori di stile
# =====================================================================
B_S, B_E = '\x01', '\x02'      # grassetto
C_S, C_E = '\x03', '\x04'      # codice in linea
K_S, K_E = '\x05', '\x06'      # blocco di codice
I_S, I_E = '\x0e', '\x0f'      # corsivo
APERTURE = {B_S: 'b', C_S: 'code', K_S: 'blocco', I_S: 'i'}
CHIUSURE = {B_E, C_E, K_E, I_E}
NL, PAR, RIENTRO = '\x15', '\x16', '\x18'
GRAFFA_A, GRAFFA_C, DOLLARO, BACKSLASH = '\x12', '\x13', '\x14', '\x17'

SIMBOLI = {
    'ldots': '…', 'dots': '…', 'textquotedbl': '"', 'quad': '  ', 'qquad': '    ',
    'S': '§', 'euro': '€', 'times': '×', 'textasciitilde': '~', 'checkmark': '✓',
    'textasciicircum': '^', 'textless': '<', 'textgreater': '>', 'textbar': '|',
    'square': '☐', 'LaTeX': 'LaTeX', 'TeX': 'TeX', 'newline': NL, 'linebreak': NL,
    'par': PAR, 'Rightarrow': '⇒', 'rightarrow': '→', 'to': '→', 'leftarrow': '←',
}
MATE = {
    'log': 'log', 'Theta': 'Θ', 'Omega': 'Ω', 'theta': 'θ', 'omega': 'ω', 'leq': '≤',
    'le': '≤', 'geq': '≥', 'ge': '≥', 'cdot': '·', 'times': '×', 'to': '→',
    'rightarrow': '→', 'Rightarrow': '⇒', 'leftarrow': '←', 'infty': '∞', 'ldots': '…',
    'dots': '…', 'cdots': '…', 'neq': '≠', 'ne': '≠', 'approx': '≈', 'lfloor': '⌊',
    'rfloor': '⌋', 'lceil': '⌈', 'rceil': '⌉', 'alpha': 'α', 'beta': 'β', 'gamma': 'γ',
    'delta': 'δ', 'Delta': 'Δ', 'sum': 'Σ', 'pi': 'π', 'in': '∈', 'pm': '±', 'max': 'max',
    'min': 'min', 'ln': 'ln', 'lg': 'lg', 'square': '☐', 'mid': '|', 'quad': '  ',
    'emptyset': '∅', 'equiv': '≡', 'll': '≪', 'gg': '≫', 'sim': '~', 'subseteq': '⊆',
}
APICE = dict(zip('0123456789n+-()ik', '⁰¹²³⁴⁵⁶⁷⁸⁹ⁿ⁺⁻⁽⁾ⁱᵏ'))
PEDICE = dict(zip('0123456789+-()', '₀₁₂₃₄₅₆₇₈₉₊₋₍₎'))
CMD_STILE = {'textbf': (B_S, B_E), 'emph': (I_S, I_E), 'textit': (I_S, I_E),
             'texttt': (C_S, C_E), 'underline': (B_S, B_E), 'textsl': (I_S, I_E)}
CMD_VIA = {'label', 'ref', 'pageref', 'hspace', 'vspace', 'setcounter', 'index',
           'codice', 'uscita', 'ingresso', 'includegraphics', 'addtocounter', 'phantom',
           'cite', 'lstinputlisting', 'input', 'livello', 'hypersetup', 'color',
           'definecolor', 'pagecolor', 'hyperref'}


def _trasforma(testo, tabella, prefisso):
    if testo and all(c in tabella for c in testo):
        return ''.join(tabella[c] for c in testo)
    return prefisso + (testo if len(testo) == 1 else '(' + testo + ')')


def _mate(m):
    t = m.group(1)
    t = re.sub(r'\\frac\{([^{}]*)\}\{([^{}]*)\}', r'\1/\2', t)
    t = re.sub(r'\\sqrt\{([^{}]*)\}', r'√\1', t)
    t = re.sub(r'\\([a-zA-Z]+)', lambda x: MATE.get(x.group(1), ''), t)
    t = re.sub(r'\\[,;!: ]', ' ', t)
    t = re.sub(r'\^\{([^{}]*)\}', lambda x: _trasforma(x.group(1), APICE, '^'), t)
    t = re.sub(r'\^(\w)', lambda x: _trasforma(x.group(1), APICE, '^'), t)
    t = re.sub(r'_\{([^{}]*)\}', lambda x: _trasforma(x.group(1), PEDICE, '_'), t)
    t = re.sub(r'_(\w)', lambda x: _trasforma(x.group(1), PEDICE, '_'), t)
    t = t.replace('{', '').replace('}', '')
    return t


_RE_LISTA = re.compile(
    r'\\begin\{(itemize|enumerate|description)\}(\[[^\]]*\])?'
    r'((?:(?!\\begin\{(?:itemize|enumerate|description)\}).)*?)\\end\{\1\}', re.S)


def _lista(m):
    tipo, opz, corpo = m.group(1), m.group(2) or '', m.group(3)
    pezzi = re.split(r'\\item\b', corpo)[1:]
    righe = []
    for n, p in enumerate(pezzi, 1):
        etichetta = None
        mm = re.match(r'\s*\[([^\]]*)\]', p)
        if mm:
            etichetta, p = mm.group(1), p[mm.end():]
        if etichetta is None:
            if tipo == 'enumerate':
                if 'Alph' in opz:
                    etichetta = chr(64 + n) + '.'
                elif 'alph' in opz:
                    etichetta = chr(96 + n) + ')'
                else:
                    etichetta = '%d.' % n
            else:
                etichetta = '•'
        righe.append(etichetta + ' ' + p.strip().replace(NL, NL + RIENTRO))
    return NL + NL.join(righe) + NL


_RE_CMD = re.compile(r'\\([a-zA-Z]+)\*?(?:\[[^\[\]{}]*\])?\{([^{}]*)\}')


def _cmd(m):
    nome, arg = m.group(1), m.group(2)
    if nome == 'q':
        return '“' + arg + '”'
    if nome in CMD_VIA or nome in ('begin', 'end'):
        return ''
    a, b = CMD_STILE.get(nome, ('', ''))
    return a + arg + b


def latex_a_testo(s):
    """Converte un frammento LaTeX della dispensa in testo leggibile con marcatori."""
    if not s:
        return ''
    salvati = []

    def salva(contenuto, blocco):
        salvati.append((contenuto, blocco))
        return '\x10%d\x11' % (len(salvati) - 1)

    # 1. parti letterali: codice, disegni
    s = re.sub(r'\\begin\{lstlisting\}(\[[^\]]*\])?\n?(.*?)\\end\{lstlisting\}',
               lambda m: salva(m.group(2).rstrip(), True), s, flags=re.S)
    s = re.sub(r'\\begin\{tikzpicture\}.*?\\end\{tikzpicture\}',
               lambda m: I_S + '[figura: vedi la dispensa]' + I_E, s, flags=re.S)
    s = re.sub(r'\\(?:cc|lstinline|verb)(?:\[[^\]]*\])?([^a-zA-Z\s{])(.*?)\1',
               lambda m: salva(m.group(2), False), s, flags=re.S)
    s = re.sub(r'\\nl(?![a-zA-Z])', lambda m: salva('\\n', False), s)
    # 2. commenti e caratteri protetti
    s = re.sub(r'(?<!\\)%[^\n]*', '', s)
    s = s.replace('\\textbackslash{}', BACKSLASH).replace('\\textbackslash', BACKSLASH)
    s = (s.replace('\\{', GRAFFA_A).replace('\\}', GRAFFA_C).replace('\\$', DOLLARO)
          .replace('\\%', '%').replace('\\&', '\x19').replace('\\_', '_')
          .replace('\\#', '#'))
    s = re.sub(r'\\\\(\[[^\]]*\])?', NL, s)
    # 3. matematica, tabelle, liste
    s = re.sub(r'\$([^$]*)\$', _mate, s)
    s = re.sub(r'\\begin\{tabular\*?\}(\{[^{}]*\})?\{(?:[^{}]|\{[^{}]*\})*\}', NL, s)
    s = s.replace('&', ' | ')
    while True:
        s2 = _RE_LISTA.sub(_lista, s)
        if s2 == s:
            break
        s = s2
    # 4. tipografia
    s = s.replace('``', '“').replace("''", '”').replace('---', '—').replace('--', '–')
    s = s.replace('~', '\u00a0')
    # 5. comandi con argomento (dall'interno verso l'esterno), poi senza argomento
    while True:
        s2 = _RE_CMD.sub(_cmd, s)
        if s2 == s:
            break
        s = s2
    s = re.sub(r'\\([a-zA-Z]+)\*?', lambda m: SIMBOLI.get(m.group(1), ''), s)
    s = re.sub(r'\\[,;:! ]', ' ', s)
    s = re.sub(r'\\(.)', r'\1', s)
    s = s.replace('{', '').replace('}', '')
    # 6. spazi: a capo singolo = spazio, riga vuota = paragrafo
    s = re.sub(r'\n[ \t]*\n\s*', PAR, s)
    s = s.replace('\n', ' ')
    s = re.sub(r'[ \t]+', ' ', s)
    s = s.replace(PAR, '\n\n').replace(NL, '\n')
    s = re.sub(r' *\n *', '\n', s)
    s = re.sub(r'\n{3,}', '\n\n', s)
    s = s.replace(RIENTRO, '    ')
    s = (s.replace(GRAFFA_A, '{').replace(GRAFFA_C, '}').replace(DOLLARO, '$')
          .replace(BACKSLASH, '\\').replace('\x19', '&'))

    def ripristina(m):
        contenuto, blocco = salvati[int(m.group(1))]
        if blocco:
            righe = contenuto.split('\n')
            rientri = [len(r) - len(r.lstrip()) for r in righe if r.strip()]
            togli = min(rientri) if rientri else 0
            contenuto = '\n'.join(r[togli:] for r in righe)
            return '\n' + K_S + contenuto + K_E + '\n'
        return C_S + contenuto + C_E

    s = re.sub(r'\x10(\d+)\x11', ripristina, s)
    s = re.sub(r'\n{3,}', '\n\n', s)
    return s.strip()


def senza_marcatori(s):
    for c in list(APERTURE) + list(CHIUSURE):
        s = s.replace(c, '')
    return s


# =====================================================================
#  2. LETTURA DELLA DISPENSA
# =====================================================================
def leggi(nome):
    with io.open(os.path.join(DISPENSA, nome), encoding='utf-8') as f:
        return f.read().replace('\r\n', '\n')


def gruppo(s, i, apri='{', chiudi='}'):
    """s[i...] inizia (dopo eventuali spazi) con 'apri': restituisce (contenuto, fine)."""
    while i < len(s) and s[i].isspace():
        i += 1
    if i >= len(s) or s[i] != apri:
        raise ValueError('atteso %r alla posizione %d' % (apri, i))
    prof, j = 0, i
    while j < len(s):
        c = s[j]
        if c == '\\':
            j += 2
            continue
        if c == apri:
            prof += 1
        elif c == chiudi:
            prof -= 1
            if prof == 0:
                return s[i + 1:j], j + 1
        j += 1
    raise ValueError('gruppo non chiuso')


def ambienti(s, nome, nargs=0):
    """Tutti gli ambienti \\begin{nome}[opz]{arg}...\\end{nome}: lista di (opz, args, corpo)."""
    risultato, pos = [], 0
    inizio, fine = '\\begin{%s}' % nome, '\\end{%s}' % nome
    while True:
        i = s.find(inizio, pos)
        if i < 0:
            break
        j = i + len(inizio)
        opz = None
        k = j
        while k < len(s) and s[k] in ' \t':
            k += 1
        if k < len(s) and s[k] == '[':
            opz, j = gruppo(s, k, '[', ']')
        args = []
        for _ in range(nargs):
            a, j = gruppo(s, j)
            args.append(a)
        e = s.find(fine, j)
        risultato.append((opz, args, s[j:e]))
        pos = e + len(fine)
    return risultato


def sezione(s, titolo, comando='\\section{'):
    i = s.find(comando + titolo)
    if i < 0:
        return ''
    j = s.find(comando, i + 1)
    return s[i:j if j >= 0 else len(s)]


def dividi_item(corpo):
    """Divide un corpo di lista nei suoi \\item di primo livello."""
    inizi, prof = [], 0
    for m in re.finditer(r'\\begin\{(?:itemize|enumerate|description)\}|'
                         r'\\end\{(?:itemize|enumerate|description)\}|\\item\b', corpo):
        t = m.group(0)
        if t.startswith('\\begin'):
            prof += 1
        elif t.startswith('\\end'):
            prof -= 1
        elif prof == 0:
            inizi.append(m)
    pezzi = []
    for a, b in zip(inizi, inizi[1:] + [None]):
        pezzi.append(corpo[a.end(): b.start() if b else len(corpo)])
    return pezzi


def risposte_soluzione(blocco):
    """Dal corpo di un box soluzione: lista di (lettera, etichetta, commento)."""
    a = blocco.find('\\begin{enumerate}')
    j = a + len('\\begin{enumerate}')
    if blocco[j:j + 1] == '[':
        _, j = gruppo(blocco, j, '[', ']')
    b = blocco.rfind('\\end{enumerate}')
    risposte = []
    for item in dividi_item(blocco[j:b]):
        m = re.match(r'\s*\\textbf\{([A-D])\}\s*(\(M\d+\))?\s*\.?\s*(.*)', item, re.S)
        if m:
            risposte.append((m.group(1), (m.group(2) or '').strip('()'), m.group(3)))
        else:
            risposte.append((None, '', item))
    return risposte


def file_se_esiste(rel):
    return rel if rel and os.path.exists(os.path.join(DISPENSA, rel)) else None


class Dati:
    """Tutti i contenuti letti dalla dispensa."""

    def __init__(self):
        self.moduli = {}          # numero -> titolo
        self.quiz = []
        self.orale = []
        self.esercizi = []        # esercizi, laboratori, pattern, laboratorio d'esame
        self.calendario = []      # (giorno, argomento, obiettivo)
        self.avvisi = []
        for n in range(1, 15):
            try:
                self._modulo(n)
            except Exception as e:  # un modulo difettoso non blocca gli altri
                self.avvisi.append('Modulo %d: %s' % (n, e))
        try:
            self._simulazione()
        except Exception as e:
            self.avvisi.append('Simulazione d\'esame: %s' % e)
        try:
            self._calendario()
        except Exception as e:
            self.avvisi.append('Calendario: %s' % e)

    # --- un modulo ---------------------------------------------------
    def _modulo(self, n):
        nome = 'modulo%02d.tex' % n
        if not os.path.exists(os.path.join(DISPENSA, nome)):
            return
        s = leggi(nome)
        titolo, _ = gruppo(s, s.find('\\chapter') + len('\\chapter'))
        titolo = re.sub(r'^Modulo\s+\d+\s*--\s*', '', titolo)
        self.moduli[n] = senza_marcatori(latex_a_testo(titolo))

        # quiz + soluzioni
        sez = sezione(s, 'Quiz')
        quiz = ambienti(sez, 'quiz', 1)
        sol = ambienti(sez, 'soluzione', 0)
        risposte = risposte_soluzione(sol[0][2]) if sol else []
        for k, (_, args, corpo) in enumerate(quiz):
            opzioni = [latex_a_testo(x) for x in dividi_item(corpo)]
            lettera, _, commento = risposte[k] if k < len(risposte) else (None, '', '')
            if lettera is None or len(opzioni) < 2:
                self.avvisi.append('M%d quiz %d senza risposta' % (n, k + 1))
                continue
            self.quiz.append({
                'id': 'm%02d-q%02d' % (n, k + 1), 'modulo': n, 'numero': k + 1,
                'domanda': latex_a_testo(args[0]), 'opzioni': opzioni,
                'giusta': ord(lettera) - 65, 'commento': latex_a_testo(commento)})

        # orale
        for k, (opz, _, corpo) in enumerate(ambienti(s, 'orale', 0)):
            domanda = re.sub(r'^\s*D\d+\.\s*', '', opz or '')
            self.orale.append({'id': 'm%02d-o%02d' % (n, k + 1), 'modulo': n,
                               'domanda': latex_a_testo(domanda),
                               'risposta': latex_a_testo(corpo)})

        cartella = 'codice/m%02d' % n

        # pattern da riscrivere a memoria
        for nomefile in sorted(os.listdir(os.path.join(DISPENSA, cartella))):
            if re.match(r'pattern\w*\.cpp$', nomefile):
                base = nomefile[:-4]
                self.esercizi.append({
                    'id': 'm%02d-%s' % (n, base), 'modulo': n, 'tipo': 'pattern',
                    'titolo': 'Pattern da riscrivere a memoria' +
                              ('' if base == 'pattern' else ' (%s)' % base),
                    'difficolta': 'kit',
                    'testo': (B_S + 'Obiettivo: ' + B_E + 'riscrivere da zero, senza guardare, '
                              'il codice della sezione “Pattern di Codice di Laboratorio” del '
                              'Modulo %d (%s).\n\n' % (n, self.moduli[n]) +
                              '1. Rileggi il pattern nella dispensa e capisci ogni riga.\n'
                              '2. Chiudi la dispensa e riscrivilo qui, con il cronometro avviato.\n'
                              '3. Compila ed esegui, poi confronta con l\'output atteso.\n'
                              '4. Se hai dovuto guardare, rifallo domani.\n\n'
                              'È il “kit da sapere a memoria” del capitolo “Superare l\'esame”.'),
                    'soluzione': {'commento': 'Il pattern della dispensa.',
                                  'files': [cartella + '/' + nomefile],
                                  'input': file_se_esiste('%s/input/%s.txt' % (cartella, base)),
                                  'output': file_se_esiste('%s/output/%s.txt' % (cartella, base))}})

        # laboratorio a step
        sez = sezione(s, 'Laboratorio')
        if sez:
            parti = []
            for opz, _, corpo in ambienti(sez, 'traccia', 0):
                if opz:
                    t = latex_a_testo(opz.lstrip(': '))
                    parti.append(B_S + t[:1].upper() + t[1:] + B_E)
                parti.append(latex_a_testo(corpo))
            for k, (_, args, corpo) in enumerate(ambienti(sez, 'step', 1), 1):
                parti.append(B_S + 'Step %d – %s' % (k, senza_marcatori(latex_a_testo(args[0])))
                             + B_E + '\n' + latex_a_testo(corpo))
            self.esercizi.append({
                'id': 'm%02d-lab' % n, 'modulo': n, 'tipo': 'lab',
                'titolo': 'Laboratorio a step', 'difficolta': 'esame',
                'testo': '\n\n'.join(parti) + '\n\nScrivi un solo file e fallo compilare '
                         'alla fine di ogni step, come in laboratorio.',
                'soluzione': {'commento': 'La soluzione è divisa in blocchi '
                                          + C_S + '// ===== STEP n =====' + C_E + '.',
                              'files': [cartella + '/lab.cpp'],
                              'input': file_se_esiste(cartella + '/input/lab.txt'),
                              'output': file_se_esiste(cartella + '/output/lab.txt')}})

        # esercizi + soluzioni dal volume Soluzioni
        soluzioni = {}
        nome_sol = 'soluzioni%02d.tex' % n
        if os.path.exists(os.path.join(DISPENSA, nome_sol)):
            parti = re.split(r'\\textbf\{Esercizio\s+(\d+)\.(\d+)\}', leggi(nome_sol))
            for i in range(1, len(parti) - 2, 3):
                pezzo = parti[i + 2]
                fine_commento = pezzo.find('\\codice')
                commento = latex_a_testo(pezzo[:fine_commento if fine_commento >= 0 else len(pezzo)])
                commento = commento.lstrip('—–- \n')
                ingressi = re.findall(r'\\ingresso\{([^}]*)\}', pezzo)
                uscite = re.findall(r'\\uscita\{([^}]*)\}', pezzo)
                soluzioni[int(parti[i + 1])] = {
                    'commento': commento,
                    'files': re.findall(r'\\codice\{([^}]*)\}', pezzo),
                    'input': ingressi[0] if ingressi else None,
                    'output': uscite[0] if uscite else None,
                    'altre_uscite': uscite[1:]}
        for k, (_, args, corpo) in enumerate(ambienti(s, 'esercizio', 2), 1):
            sol = soluzioni.get(k, {'commento': 'Soluzione non trovata.',
                                    'files': [], 'input': None, 'output': None})
            testo = latex_a_testo(corpo)
            if len(sol['files']) > 1:
                cpp = [os.path.basename(f) for f in sol['files'] if f.endswith('.cpp')]
                testo += ('\n\n' + B_S + 'Nota: esercizio su più file.' + B_E + ' Qui nell\'editor '
                          'scrivi tutto in un unico file, nell\'ordine: contenuto dell\'header, '
                          'definizioni, main. Per provare la compilazione separata vera crea i '
                          'file in una cartella e compila da terminale con ' + C_S +
                          'g++ -Wall ' + ' '.join(cpp) + ' -o prog' + C_E + '.')
            self.esercizi.append({
                'id': 'm%02d-e%02d' % (n, k), 'modulo': n, 'tipo': 'es', 'numero': k,
                'titolo': senza_marcatori(latex_a_testo(args[0])),
                'difficolta': senza_marcatori(latex_a_testo(args[1])).strip(),
                'testo': testo, 'soluzione': sol})

    # --- simulazione d'esame -----------------------------------------
    def _simulazione(self):
        s = leggi('verso-esame.tex')
        i, j = s.find('Prova 1'), s.find('Prova 2')
        quiz = ambienti(s[i:j], 'quiz', 1)
        sol = ambienti(leggi('soluzioni-esame.tex'), 'soluzione', 0)
        risposte = risposte_soluzione(sol[0][2]) if sol else []
        for k, (_, args, corpo) in enumerate(quiz):
            if k >= len(risposte) or risposte[k][0] is None:
                continue
            lettera, etichetta, commento = risposte[k]
            m = re.match(r'M(\d+)', etichetta or '')
            self.quiz.append({
                'id': 'esame-q%02d' % (k + 1), 'modulo': 0, 'numero': k + 1,
                'modulo_rif': int(m.group(1)) if m else None,
                'domanda': latex_a_testo(args[0]),
                'opzioni': [latex_a_testo(x) for x in dividi_item(corpo)],
                'giusta': ord(lettera) - 65, 'commento': latex_a_testo(commento)})
        k = s.find('Prova 3')
        tracce = ambienti(s[j:k], 'traccia', 0)
        if tracce:
            opz, _, corpo = tracce[0]
            self.esercizi.append({
                'id': 'esame-lab', 'modulo': 0, 'tipo': 'esame',
                'titolo': 'Laboratorio: ' + senza_marcatori(latex_a_testo((opz or '').lstrip(': '))),
                'difficolta': 'esame',
                'testo': (B_S + 'Simulazione d\'esame – 2 ore di orologio.' + B_E +
                          ' Avvia il cronometro, stacca Internet, non guardare la soluzione '
                          'prima della fine.\n\n' + latex_a_testo(corpo)),
                'soluzione': {'commento': 'Una soluzione completa, punto per punto. Non è '
                                          'l\'unica possibile: conta che ogni punto funzioni.',
                              'files': ['codice/esame/lab.cpp'], 'input': None,
                              'output': file_se_esiste('codice/esame/output/lab.txt')}})
        self.moduli[0] = 'Simulazione d\'esame'

    def _calendario(self):
        s = leggi('verso-esame.tex')
        sez = s[s.find('Il calendario'):]
        sez = sez[:sez.find('\\end{tabular}')]
        for m in re.finditer(r'^\s*(\d+)\s*&(.*?)&(.*?)\\\\', sez, re.M):
            self.calendario.append((int(m.group(1)), senza_marcatori(latex_a_testo(m.group(2))),
                                    senza_marcatori(latex_a_testo(m.group(3)))))


# =====================================================================
#  3. COMPILAZIONE ED ESECUZIONE
# =====================================================================
def trova_gpp():
    if MAC:
        # /usr/bin/g++ c'è sempre, ma senza gli strumenti di sviluppo di Apple è solo un
        # segnaposto che apre la finestra di installazione: prima si controlla xcode-select
        for c in ('/opt/homebrew/bin/g++', '/usr/local/bin/g++'):
            if os.path.isfile(c):
                return c
        try:
            ok = subprocess.run(['xcode-select', '-p'], capture_output=True, timeout=10).returncode == 0
        except (OSError, subprocess.SubprocessError):
            ok = False
        return '/usr/bin/g++' if ok and os.path.isfile('/usr/bin/g++') else None
    g = shutil.which('g++')
    if g:
        return g
    for c in (r'C:\msys64\mingw64\bin\g++.exe', r'C:\msys64\ucrt64\bin\g++.exe',
              r'C:\MinGW\bin\g++.exe', r'C:\mingw64\bin\g++.exe'):
        if os.path.exists(c):
            return c
    return None


NO_FINESTRA = 0x08000000 if os.name == 'nt' else 0
CODICI_USCITA = {
    3221225477: 'accesso a memoria non valida (segmentation fault): un puntatore nullo '
                'o già cancellato? un indice fuori dall\'array?',
    3221225725: 'stack overflow: probabilmente una ricorsione senza caso base.',
    3221225620: 'divisione intera per zero.',
    3221226505: 'errore grave del programma (spesso un delete fatto due volte o su un '
                'puntatore non valido).',
    3: 'il programma si è fermato con abort(): spesso un\'eccezione non catturata.',
    -11: 'segmentation fault: un puntatore nullo o già cancellato? un indice fuori dall\'array? '
         '(anche una ricorsione senza caso base finisce così).',
    -6: 'il programma si è fermato con abort(): spesso un\'eccezione non catturata, '
        'o un delete fatto due volte.',
    -8: 'divisione intera per zero.',
    -10: 'accesso a memoria non valida (bus error): un puntatore non inizializzato?',
}


def ambiente_gpp(gpp):
    env = dict(os.environ)
    env['PATH'] = os.path.dirname(gpp) + os.pathsep + env.get('PATH', '')
    return env


def compila(gpp, sorgente, eseguibile):
    """Restituisce (ok, messaggi)."""
    try:
        r = subprocess.run([gpp, '-Wall', '-Wextra', '-std=c++17', '-o', eseguibile, sorgente],
                           capture_output=True, text=True, encoding='utf-8', errors='replace',
                           timeout=90, env=ambiente_gpp(gpp), creationflags=NO_FINESTRA)
    except subprocess.TimeoutExpired:
        return False, 'La compilazione ha superato i 90 secondi.'
    return r.returncode == 0, (r.stdout + r.stderr).strip()


def esegui(gpp, eseguibile, ingresso, tempo_max=10):
    """Restituisce (codice, stdout, stderr, nota)."""
    try:
        r = subprocess.run([eseguibile], input=ingresso, capture_output=True, text=True,
                           encoding='utf-8', errors='replace', timeout=tempo_max,
                           cwd=LAVORI, env=ambiente_gpp(gpp), creationflags=NO_FINESTRA)
    except subprocess.TimeoutExpired as e:
        out = e.stdout.decode('utf-8', 'replace') if isinstance(e.stdout, bytes) else (e.stdout or '')
        return None, out, '', ('Il programma non è terminato entro %d secondi. È un ciclo '
                               'infinito, oppure sta aspettando dati da tastiera: scrivili '
                               'nel riquadro “Input”.' % tempo_max)
    except PermissionError:
        if MAC:
            return None, '', '', 'macOS non permette di eseguire il programma (Permission denied).'
        return None, '', '', ('Windows ha bloccato l\'eseguibile (Permission denied). Di solito '
                              'è l\'antivirus che lo scambia per un virus: modifica un po\' il '
                              'codice e ricompila.')
    except OSError as e:
        return None, '', '', 'Impossibile eseguire il programma: %s' % e
    nota = ''
    if r.returncode != 0:
        nota = 'Il programma è terminato con codice %d' % r.returncode
        if r.returncode in CODICI_USCITA:
            nota += ': ' + CODICI_USCITA[r.returncode]
    return r.returncode, r.stdout, r.stderr, nota


def normalizza_output(t):
    righe = [r.rstrip() for r in t.replace('\r\n', '\n').split('\n')]
    while righe and not righe[-1]:
        righe.pop()
    return righe


# =====================================================================
#  4. PROGRESSI, IMPOSTAZIONI, VECCHI DATI
# =====================================================================
def _leggi_json(percorso, base):
    try:
        with io.open(percorso, encoding='utf-8') as f:
            dati = json.load(f)
        if isinstance(dati, dict):
            base.update(dati)
    except (OSError, ValueError):
        pass
    return base


def _scrivi_json(percorso, dati):
    os.makedirs(os.path.dirname(percorso), exist_ok=True)
    tmp = percorso + '.tmp'
    with io.open(tmp, 'w', encoding='utf-8') as f:
        json.dump(dati, f, ensure_ascii=False, indent=1)
    os.replace(tmp, percorso)


def carica_progressi():
    return _leggi_json(FILE_PROGRESSI, {'quiz': {}, 'orale': {}, 'esercizi': {}, 'simulazioni': []})


def salva_progressi(p):
    _scrivi_json(FILE_PROGRESSI, p)


def carica_impostazioni():
    return _leggi_json(FILE_IMPOSTAZIONI, {
        'tema': 'auto', 'data_esame': DATA_ESAME_PREDEFINITA, 'nome': '', 'dispensa': '',
        'vista': 'oggi', 'ultimo_esercizio': None, 'durata_lab': 120})


def salva_impostazioni(i):
    _scrivi_json(FILE_IMPOSTAZIONI, i)


def migra_vecchi_dati():
    """Importa progressi e codice della prima versione (Allenatore/progressi.json, lavori/)."""
    if os.path.exists(FILE_PROGRESSI):
        return False
    for base in (QUI, os.path.join(CARTELLA_EXE, 'Allenatore'), CARTELLA_EXE):
        vecchio = os.path.join(base, 'progressi.json')
        if not os.path.isfile(vecchio):
            continue
        p = _leggi_json(vecchio, {})
        imp = carica_impostazioni()
        if p.get('data_esame'):
            imp['data_esame'] = p['data_esame']
        salva_impostazioni(imp)
        salva_progressi({k: p.get(k, v) for k, v in
                         {'quiz': {}, 'orale': {}, 'esercizi': {}, 'simulazioni': []}.items()})
        vecchi = os.path.join(base, 'lavori')
        if os.path.isdir(vecchi):
            os.makedirs(LAVORI, exist_ok=True)
            for nome in os.listdir(vecchi):
                if nome.endswith('.cpp') and not os.path.exists(os.path.join(LAVORI, nome)):
                    shutil.copy2(os.path.join(vecchi, nome), os.path.join(LAVORI, nome))
        return True
    return False


def campione_pesato(lista, pesi, k):
    """k elementi senza ripetizione, con probabilità proporzionale al peso."""
    chiavi = [(random.random() ** (1.0 / max(p, 1e-6)), i) for i, p in enumerate(pesi)]
    chiavi.sort(reverse=True)
    return [lista[i] for _, i in chiavi[:k]]


# =====================================================================
#  5. CATALOGO DEI CONTENUTI (per l'interfaccia)
# =====================================================================
def e_dispensa(c):
    return bool(c) and os.path.isfile(os.path.join(c, 'modulo01.tex')) \
        and os.path.isdir(os.path.join(c, 'codice'))


def trova_dispensa(preferita=''):
    candidati = [preferita, os.environ.get('ALLENATORE_DISPENSA', ''),
                 os.path.join(CARTELLA_EXE, 'Dispensa'), os.path.join(CARTELLA_EXE, '..', 'Dispensa'),
                 os.path.join(QUI, '..', 'Dispensa')]
    for c in candidati:
        if c and e_dispensa(c):
            return os.path.normpath(os.path.abspath(c))
    return None


_RE_VOCE = re.compile(r'^(\s*)(•|\d+\.|[A-Za-z][.)])\s+(.*)$')
_TAG = ((B_S, '<b>'), (B_E, '</b>'), (I_S, '<i>'), (I_E, '</i>'), (C_S, '<code>'), (C_E, '</code>'))


def html_in_linea(t):
    t = html.escape(t or '', quote=False)
    for a, b in _TAG:
        t = t.replace(a, b)
    return t.replace(K_S, '<code>').replace(K_E, '</code>').replace('\n', '<br>')


def a_html(testo):
    """Testo con marcatori -> HTML (paragrafi, elenchi, codice)."""
    if not testo:
        return ''
    out = []
    pezzi = re.split(K_S + '(.*?)' + K_E, testo, flags=re.S)
    for i, p in enumerate(pezzi):
        if i % 2:
            out.append('<pre class="cpp">' + html.escape(p, quote=False) + '</pre>')
            continue
        for par in re.split(r'\n\s*\n', p):
            par = par.strip('\n')
            if not par.strip():
                continue
            righe = par.split('\n')
            if any(_RE_VOCE.match(r) for r in righe):
                voci = []
                for r in righe:
                    m = _RE_VOCE.match(r)
                    if m:
                        voci.append(['<div class="voce" style="--l:%d"><span class="segno">%s</span><span>'
                                     % (len(m.group(1)) // 4, html.escape(m.group(2))), html_in_linea(m.group(3))])
                    elif voci:
                        voci[-1][1] += ' ' + html_in_linea(r.strip())
                    else:
                        voci.append(['<p>', html_in_linea(r), '</p>'])
                out.append('<div class="elenco">' + ''.join(
                    v[0] + v[1] + (v[2] if len(v) > 2 else '</span></div>') for v in voci) + '</div>')
            else:
                out.append('<p>' + '<br>'.join(html_in_linea(r) for r in righe) + '</p>')
    return ''.join(out)


def _leggi_rel(rel):
    if not rel:
        return None
    try:
        with io.open(os.path.join(DISPENSA, rel), encoding='utf-8') as f:
            return f.read().replace('\r\n', '\n')
    except (OSError, UnicodeDecodeError):
        return None


def costruisci_catalogo():
    d = Dati()
    cat = {'versione_app': APP_VERSIONE,
           'generato': datetime.datetime.now().isoformat(timespec='minutes'),
           'moduli': {str(k): v for k, v in d.moduli.items()},
           'calendario': [{'giorno': g, 'argomento': a, 'obiettivo': o} for g, a, o in d.calendario],
           'avvisi': d.avvisi, 'quiz': [], 'orale': [], 'esercizi': []}
    for q in d.quiz:
        cat['quiz'].append({'id': q['id'], 'modulo': q['modulo'], 'rif': q.get('modulo_rif'),
                            'domanda': a_html(q['domanda']),
                            'opzioni': [html_in_linea(o) for o in q['opzioni']],
                            'giusta': q['giusta'], 'commento': a_html(q['commento'])})
    for o in d.orale:
        cat['orale'].append({'id': o['id'], 'modulo': o['modulo'],
                             'domanda': html_in_linea(o['domanda']), 'risposta': a_html(o['risposta'])})
    for e in d.esercizi:
        sol = e['soluzione']
        files = [{'nome': f.split('/', 2)[-1] if len(sol.get('files', [])) > 1 else os.path.basename(f),
                  'contenuto': _leggi_rel(f) or ''} for f in sol.get('files', [])]
        cat['esercizi'].append({
            'id': e['id'], 'modulo': e['modulo'], 'tipo': e['tipo'], 'numero': e.get('numero'),
            'titolo': e['titolo'], 'difficolta': e['difficolta'], 'testo': a_html(e['testo']),
            'soluzione': {'commento': a_html(sol.get('commento', '')), 'files': files,
                          'input': _leggi_rel(sol.get('input')), 'output': _leggi_rel(sol.get('output')),
                          'altre_uscite': [{'nome': os.path.basename(x), 'contenuto': _leggi_rel(x) or ''}
                                           for x in sol.get('altre_uscite', [])]}})
    return cat


def carica_catalogo(preferita=''):
    """Contenuti dalla dispensa se c'è, altrimenti dalla copia inclusa nell'app."""
    global DISPENSA
    trovata = trova_dispensa(preferita)
    errore = None
    if trovata:
        DISPENSA = trovata
        try:
            cat = costruisci_catalogo()
            cat['fonte'] = 'dispensa'
            cat['percorso'] = trovata
            return cat
        except Exception as e:  # dispensa illeggibile: si usa la copia
            errore = str(e)
    copia = os.path.join(RISORSE, 'contenuti.json')
    if os.path.isfile(copia):
        with io.open(copia, encoding='utf-8') as f:
            cat = json.load(f)
        cat['fonte'] = 'copia'
        cat['percorso'] = None
        if errore:
            cat.setdefault('avvisi', []).append('Dispensa non leggibile: ' + errore)
        return cat
    raise RuntimeError('Non trovo né la dispensa né la copia dei contenuti.')


# =====================================================================
#  6. COMPILAZIONE PER L'INTERFACCIA
# =====================================================================
_RE_DIAG = re.compile(r'^(?:[A-Za-z]:)?[^:\n]*?\.(?:cpp|h|hpp|cc):(\d+):(\d+):\s*'
                      r'(fatal error|error|warning):\s*(.*)$', re.M)
_RE_ID = re.compile(r'^[A-Za-z0-9_-]{1,40}$')


def percorso_lavoro(id_):
    if not _RE_ID.match(id_ or ''):
        raise ValueError('identificativo non valido')
    return os.path.join(LAVORI, id_ + '.cpp')


def leggi_lavoro(id_):
    p = percorso_lavoro(id_)
    if not os.path.isfile(p):
        return None
    with io.open(p, encoding='utf-8', errors='replace') as f:
        return f.read()


def salva_lavoro(id_, codice):
    p = percorso_lavoro(id_)
    os.makedirs(LAVORI, exist_ok=True)
    with io.open(p, 'w', encoding='utf-8', newline='\n') as f:
        f.write(codice)


def esegui_codice(gpp, id_, codice, ingresso='', tempo_max=10):
    salva_lavoro(id_, codice)
    sorgente = percorso_lavoro(id_)
    os.makedirs(os.path.join(LAVORI, 'build'), exist_ok=True)
    eseguibile = os.path.join(LAVORI, 'build', id_ + '.exe')
    t0 = time.time()
    ok, msg = compila(gpp, sorgente, eseguibile)
    msg = msg.replace(os.path.join(LAVORI, ''), '').replace(LAVORI.replace('\\', '/') + '/', '')
    diag = []
    for m in _RE_DIAG.finditer(msg):
        diag.append({'riga': int(m.group(1)), 'colonna': int(m.group(2)),
                     'tipo': 'errore' if 'error' in m.group(3) else 'avviso', 'testo': m.group(4).strip()})
    ris = {'compilato': ok, 'messaggi': msg, 'diagnostica': diag[:60],
           'tempo_compilazione': round(time.time() - t0, 2)}
    if not ok:
        return ris
    if ingresso and not ingresso.endswith('\n'):
        ingresso += '\n'
    t0 = time.time()
    codice_uscita, out, err, nota = esegui(gpp, eseguibile, ingresso, tempo_max)
    ris.update({'uscita': codice_uscita, 'stdout': (out or '')[:300000], 'stderr': (err or '')[:50000],
                'nota': nota, 'tempo_esecuzione': round(time.time() - t0, 2)})
    return ris


_RE_DIAG_FILE = re.compile(r'^(.*?):(\d+):(\d+):\s*(fatal error|error|warning):\s*(.*)$', re.M)


def controlla_sintassi(gpp, id_, codice):
    """Controllo «dal vivo» mentre si scrive: g++ -fsyntax-only (niente eseguibile, niente
    esecuzione). Su una copia a parte, così non tocca il file salvato. Restituisce solo
    i messaggi che riguardano il file dell'esercizio (non quelli dentro le librerie)."""
    percorso_lavoro(id_)                        # valida l'identificativo
    cartella = os.path.join(LAVORI, 'controllo')
    os.makedirs(cartella, exist_ok=True)
    sorgente = os.path.join(cartella, id_ + '.cpp')
    with io.open(sorgente, 'w', encoding='utf-8', newline='\n') as f:
        f.write(codice)
    try:
        r = subprocess.run([gpp, '-fsyntax-only', '-Wall', '-Wextra', '-std=c++17', '-fmax-errors=30', sorgente],
                           capture_output=True, text=True, encoding='utf-8', errors='replace',
                           timeout=20, env=ambiente_gpp(gpp), creationflags=NO_FINESTRA, cwd=cartella)
    except subprocess.TimeoutExpired:
        return {'ok': False, 'diagnostica': [], 'scaduto': True}
    diag, nome = [], os.path.normcase(os.path.abspath(sorgente))
    for m in _RE_DIAG_FILE.finditer(r.stderr or ''):
        if os.path.normcase(os.path.abspath(os.path.join(cartella, m.group(1)))) != nome:
            continue
        diag.append({'riga': int(m.group(2)), 'colonna': int(m.group(3)),
                     'tipo': 'errore' if 'error' in m.group(4) else 'avviso', 'testo': m.group(5).strip()})
    return {'ok': r.returncode == 0, 'diagnostica': diag[:60]}


def confronta_output(atteso, ottenuto):
    a, b = normalizza_output(atteso or ''), normalizza_output(ottenuto or '')
    if a == b:
        return {'uguale': True, 'righe': []}
    righe = []
    for r in list(difflib.unified_diff(a, b, 'atteso', 'tuo', lineterm='', n=2))[2:500]:
        if r.startswith('@@'):
            m = re.match(r'@@ -(\d+)', r)
            righe.append({'tipo': 'sezione', 'testo': 'Dalla riga %s dell\'output atteso' % (m.group(1) if m else '?')})
        else:
            righe.append({'tipo': {'-': 'meno', '+': 'piu'}.get(r[:1], 'uguale'), 'testo': r[1:]})
    return {'uguale': False, 'righe': righe}


# =====================================================================
#  7. CARTELLA DI ESERCIZI PER VS CODE
# =====================================================================
#  Un file .cpp per esercizio, con la consegna in commento in testa, più
#  .vscode/tasks.json (Ctrl+Shift+B = compila con g++ -Wall -Wextra ed esegui).
#  I .cpp già esistenti NON vengono mai sovrascritti: dentro c'è il lavoro.
INIZIO_CONSEGNA = '// ======================== CONSEGNA ========================'
FINE_CONSEGNA = '// ===================== FINE DELLA CONSEGNA ====================='
LARGHEZZA = 92


def html_a_testo(h):
    """HTML della traccia -> testo semplice (codice e elenchi conservati)."""
    blocchi = []

    def salva(m):
        blocchi.append(html.unescape(re.sub(r'<[^>]+>', '', m.group(1))))
        return '\n\n\x05%d\x05\n\n' % (len(blocchi) - 1)
    t = re.sub(r'<pre[^>]*>(.*?)</pre>', salva, h or '', flags=re.S)
    t = re.sub(r'<div class="voce" style="--l:(\d+)"><span class="segno">(.*?)</span><span>(.*?)</span></div>',
               lambda m: '\x07' + '\x06' * int(m.group(1)) + m.group(2) + ' ' + m.group(3) + '\n', t, flags=re.S)
    t = re.sub(r'<br\s*/?>', '\n', t)
    t = re.sub(r'</p>|</div>', '\n\n', t)
    t = html.unescape(re.sub(r'<[^>]+>', '', t))
    return t, blocchi


def consegna_in_commento(e):
    import textwrap
    testo, blocchi = html_a_testo(e['testo'])
    righe = []
    for par in re.split(r'\n\s*\n', testo):
        par = par.strip('\n')
        if not par.strip():
            continue
        m = re.fullmatch(r'\s*\x05(\d+)\x05\s*', par)
        if m:
            righe += ['    ' + r if r.strip() else '' for r in blocchi[int(m.group(1))].rstrip('\n').split('\n')]
        else:
            for r in par.split('\n'):
                rientro = '    ' * r.count('\x06')
                e_voce = '\x07' in r
                r = re.sub(r'\s+', ' ', r.replace('\x06', '').replace('\x07', '')).strip()
                if not r:
                    continue
                voce = re.match(r'(\S{1,4}) ', r) if e_voce else None
                seguito = rientro + (' ' * (len(voce.group(1)) + 1) if voce else '')
                righe += textwrap.wrap(r, LARGHEZZA, initial_indent=rientro, subsequent_indent=seguito,
                                       break_long_words=False, break_on_hyphens=False) or ['']
        righe.append('')
    return righe


def _ascii(t):
    """Senza accenti né simboli: i nomi dei file devono piacere a g++ e a Code Runner."""
    import unicodedata
    t = unicodedata.normalize('NFKD', t).encode('ascii', 'ignore').decode('ascii')
    return re.sub(r'\s+', ' ', re.sub(r'[^A-Za-z0-9\- ]+', ' ', t)).strip()


def nome_file_vscode(e):
    # NIENTE SPAZI: Code Runner non mette tra virgolette $fileName e il comando si spezza
    titolo = _ascii(e['titolo'])
    if len(titolo) > 48:
        titolo = titolo[:48].rsplit(' ', 1)[0]
    titolo = titolo.replace(' ', '_')
    return '%s_%s.cpp' % (e['id'], titolo) if titolo else e['id'] + '.cpp'


def nome_cartella_modulo(cat, n):
    if n == 0 or str(n) not in cat['moduli']:
        return 'M15 Simulazione d esame'
    t = _ascii(cat['moduli'][str(n)])
    if len(t) > 50:
        t = t[:50].rsplit(' ', 1)[0]
    return 'M%02d %s' % (n, t)


def contenuto_file_vscode(cat, e):
    sol = e['soluzione']
    tipo = {'lab': 'Laboratorio a step', 'pattern': 'Pattern da riscrivere a memoria',
            'esame': 'Simulazione d\'esame'}.get(e['tipo'], 'Esercizio %s' % (e.get('numero') or ''))
    modulo = 'Modulo %d - %s' % (e['modulo'], cat['moduli'].get(str(e['modulo']), '')) if e['modulo'] else 'Esame'
    c = [INIZIO_CONSEGNA, '', modulo, '%s  |  difficoltà: %s' % (tipo.strip(), e['difficolta']), '',
         e['titolo'].upper(), '']
    c += consegna_in_commento(e)
    if sol.get('input'):
        c += ['INPUT DI PROVA (da tastiera; il task «con l\'input di prova» lo inserisce da solo):']
        c += ['    ' + r for r in sol['input'].rstrip('\n').split('\n')] + ['']
    c += ['COME CONSEGNARE: Ctrl+Shift+B compila ed esegue. Quando funziona, nell\'Allenatore',
          'apri questo esercizio e premi «Importa da VS Code» (oppure Ctrl+A, Ctrl+C e incolla).',
          'L\'output atteso è nella scheda «Confronto» dell\'app.']
    righe = [('// ' + r).rstrip() for r in c[1:]]
    return '\n'.join([INIZIO_CONSEGNA] + righe + [FINE_CONSEGNA, '',
                     '#include <iostream>', 'using namespace std;', '', 'int main() {', '    ',
                     '    return 0;', '}', ''])


def togli_consegna(codice):
    """Toglie il blocco della consegna (se c'è) dal codice importato da VS Code."""
    i, j = codice.find(INIZIO_CONSEGNA), codice.find(FINE_CONSEGNA)
    if i < 0 or j < i:
        return codice
    return (codice[:i] + codice[j + len(FINE_CONSEGNA):]).lstrip('\r\n')


def cartella_vscode_predefinita(cat):
    if cat.get('fonte') == 'dispensa' and cat.get('percorso'):
        return os.path.join(os.path.dirname(os.path.normpath(cat['percorso'])), 'Esercizi VS Code')
    return os.path.join(os.path.expanduser('~'), 'Documents', 'Esercizi Prog2 VS Code')


def _tasks_vscode_mac(gpp):
    exe = "${workspaceFolder}/.build/${fileBasenameNoExtension}"
    inp = "${workspaceFolder}/.input/${fileBasenameNoExtension}.txt"
    presenta = {'echo': False, 'reveal': 'always', 'focus': True, 'panel': 'shared',
                'clear': True, 'showReuseMessage': False}
    opzioni = {'cwd': '${fileDirname}'}
    return {'version': '2.0.0', 'tasks': [
        {'label': 'Compila', 'type': 'process', 'command': gpp or 'g++',
         'args': ['-Wall', '-Wextra', '-std=c++17', '-g', '${file}', '-o', exe],
         'options': opzioni, 'problemMatcher': ['$gcc'], 'presentation': dict(presenta, focus=False)},
        {'label': 'Compila ed esegui', 'type': 'shell', 'dependsOn': 'Compila',
         'command': '"%s"' % exe, 'options': opzioni, 'problemMatcher': [],
         'group': {'kind': 'build', 'isDefault': True}, 'presentation': presenta},
        {'label': 'Compila ed esegui con l\'input di prova', 'type': 'shell', 'dependsOn': 'Compila',
         'command': 'if [ -f "%s" ]; then "%s" < "%s"; else echo "Questo esercizio non ha un input di prova."; "%s"; fi'
                    % (inp, exe, inp, exe),
         'options': opzioni, 'problemMatcher': [], 'group': 'build', 'presentation': presenta}]}


def _tasks_vscode(gpp):
    if MAC:
        return _tasks_vscode_mac(gpp)
    gpp = gpp or 'g++'
    bin_ = os.path.dirname(gpp) if os.path.isabs(gpp) else ''
    exe = "${workspaceFolder}\\.build\\${fileBasenameNoExtension}.exe"
    inp = "${workspaceFolder}\\.input\\${fileBasenameNoExtension}.txt"
    utf8 = '[Console]::OutputEncoding = [Text.Encoding]::UTF8; '
    shell = {'executable': 'powershell.exe', 'args': ['-NoProfile', '-ExecutionPolicy', 'Bypass', '-Command']}
    opzioni = {'cwd': '${fileDirname}', 'shell': shell}
    if bin_:
        opzioni['env'] = {'PATH': bin_ + ';${env:PATH}'}
    presenta = {'echo': False, 'reveal': 'always', 'focus': True, 'panel': 'shared',
                'clear': True, 'showReuseMessage': False}
    return {'version': '2.0.0', 'tasks': [
        {'label': 'Compila', 'type': 'process', 'command': gpp,
         'args': ['-Wall', '-Wextra', '-std=c++17', '-g', '${file}', '-o', exe],
         'options': {k: v for k, v in opzioni.items() if k != 'shell'},
         'problemMatcher': ['$gcc'], 'presentation': dict(presenta, focus=False)},
        {'label': 'Compila ed esegui', 'type': 'shell', 'dependsOn': 'Compila',
         'command': utf8 + "& '%s'" % exe, 'options': opzioni, 'problemMatcher': [],
         'group': {'kind': 'build', 'isDefault': True}, 'presentation': presenta},
        {'label': 'Compila ed esegui con l\'input di prova', 'type': 'shell', 'dependsOn': 'Compila',
         'command': utf8 + "if (Test-Path -LiteralPath '%s') { Get-Content -LiteralPath '%s' | & '%s' } "
                           "else { Write-Host 'Questo esercizio non ha un input di prova.'; & '%s' }"
                           % (inp, inp, exe, exe),
         'options': opzioni, 'problemMatcher': [], 'group': 'build', 'presentation': presenta}]}


LEGGIMI_VSCODE = """ESERCIZI DELL'ALLENATORE PROG2 PER VS CODE
==========================================

Ogni cartella è un modulo, ogni file .cpp un esercizio: la consegna è scritta
nel commento in testa al file. Scrivi la soluzione sotto il commento.

  ▷ (Code Runner) compila con g++ -Wall -Wextra ed esegue nel terminale, come sempre.
                 I nomi dei file non hanno spazi apposta: Code Runner non li sopporta.
  Ctrl+Shift+B   compila (g++ -Wall -Wextra -std=c++17) ed esegue il file aperto.
                 Gli errori compaiono nel pannello «Problemi» (Ctrl+Shift+M).
  Terminale > Esegui attività… > «Compila ed esegui con l'input di prova»
                 esegue il programma dandogli in ingresso l'input di prova.

Per consegnare: nell'Allenatore apri lo stesso esercizio e premi «Importa da
VS Code» (oppure copia tutto il file e incollalo nell'editor dell'app). Poi
Esegui e guarda la scheda «Confronto».

Il numero davanti al nome del file (es. m11-e03) è lo stesso dell'app.
Rigenerare la cartella dall'app non tocca i file che esistono già: per
ricominciare un esercizio da zero cancella il suo file e rigenera.
"""


def crea_cartella_vscode(cat, cartella, gpp=None):
    """Crea (o completa) la cartella. Restituisce {'cartella', 'nuovi', 'esistenti'}."""
    nuovi = esistenti = 0
    os.makedirs(os.path.join(cartella, '.vscode'), exist_ok=True)
    os.makedirs(os.path.join(cartella, '.build'), exist_ok=True)
    os.makedirs(os.path.join(cartella, '.input'), exist_ok=True)

    def scrivi(rel, testo):
        with io.open(os.path.join(cartella, rel), 'w', encoding='utf-8', newline='\n') as f:
            f.write(testo)
    scrivi('.vscode/tasks.json', json.dumps(_tasks_vscode(gpp), ensure_ascii=False, indent=2))
    impostazioni = {'files.encoding': 'utf8', 'files.eol': '\n',
                    'files.exclude': {'.build': True, '.input': True, '**/*.exe': True},
                    'C_Cpp.default.cppStandard': 'c++17',
                    'C_Cpp.default.intelliSenseMode': 'macos-clang-arm64' if MAC else 'windows-gcc-x64',
                    'editor.rulers': [LARGHEZZA + 3],
                    # Code Runner (il ▷ in alto): stesso schema del suo comando predefinito, così
                    # funziona sia in PowerShell sia nel Prompt; in più gli avvisi come all'esame
                    'code-runner.executorMap': {'cpp': 'cd $dir && g++ -Wall -Wextra -std=c++17 $fileName '
                                                       '-o $fileNameWithoutExt && $dir$fileNameWithoutExt'},
                    'code-runner.runInTerminal': True, 'code-runner.saveFileBeforeRun': True,
                    'code-runner.clearPreviousOutput': True, 'code-runner.ignoreSelection': True}
    if gpp:
        impostazioni['C_Cpp.default.compilerPath'] = gpp
    scrivi('.vscode/settings.json', json.dumps(impostazioni, ensure_ascii=False, indent=2))
    scrivi('.vscode/extensions.json', json.dumps({'recommendations': ['ms-vscode.cpptools']}, indent=2))
    scrivi('LEGGIMI.txt', LEGGIMI_VSCODE)
    for f in os.listdir(os.path.join(cartella, '.input')):      # gli input si riscrivono sempre
        os.remove(os.path.join(cartella, '.input', f))
    for e in cat['esercizi']:
        rel = os.path.join(nome_cartella_modulo(cat, e['modulo']), nome_file_vscode(e))
        dest = os.path.join(cartella, rel)
        base = os.path.splitext(os.path.basename(rel))[0]
        if e['soluzione'].get('input'):
            scrivi(os.path.join('.input', base + '.txt'), e['soluzione']['input'])
        os.makedirs(os.path.dirname(dest), exist_ok=True)
        vecchio = trova_file_vscode(cartella, e['id'])
        if vecchio:
            esistenti += 1
            if os.path.normcase(vecchio) != os.path.normcase(dest) and not os.path.exists(dest):
                os.replace(vecchio, dest)        # vecchio nome (con spazi/accenti): si sposta, il lavoro resta
                vecchio_exe = os.path.splitext(vecchio)[0] + '.exe'
                if os.path.isfile(vecchio_exe):
                    os.remove(vecchio_exe)
            continue
        scrivi(rel, contenuto_file_vscode(cat, e))
        nuovi += 1
    for sotto in os.listdir(cartella):                          # cartelle dei vecchi nomi rimaste vuote
        p = os.path.join(cartella, sotto)
        # SICUREZZA: si toccano solo le cartelle dei moduli (M01 ..), mai altre cartelle dell'utente
        if sotto.startswith('.') or not os.path.isdir(p) or not re.match(r'^M\d\d ', sotto):
            continue
        contenuto = os.listdir(p)
        if all(x.lower().endswith('.exe') and os.path.isfile(os.path.join(p, x)) for x in contenuto):
            for x in contenuto:
                os.remove(os.path.join(p, x))
            os.rmdir(p)
    return {'cartella': cartella, 'nuovi': nuovi, 'esistenti': esistenti}


def trova_file_vscode(cartella, id_):
    """Il file dell'esercizio, cercato per prefisso (il titolo può cambiare)."""
    if not _RE_ID.match(id_ or '') or not os.path.isdir(cartella):
        return None
    for sotto in sorted(os.listdir(cartella)):
        p = os.path.join(cartella, sotto)
        if sotto.startswith('.') or not os.path.isdir(p):
            continue
        for f in sorted(os.listdir(p)):
            if f.endswith('.cpp') and (f == id_ + '.cpp' or f.startswith(id_ + '_') or f.startswith(id_ + ' ')):
                return os.path.join(p, f)
    return None


def trova_vscode():
    if MAC:
        for app in ('/Applications', os.path.expanduser('~/Applications')):
            c = os.path.join(app, 'Visual Studio Code.app', 'Contents', 'Resources', 'app', 'bin', 'code')
            if os.path.isfile(c):
                return c
    for c in (shutil.which('code'),
              os.path.join(os.environ.get('LOCALAPPDATA', ''), 'Programs', 'Microsoft VS Code', 'bin', 'code.cmd'),
              r'C:\Program Files\Microsoft VS Code\bin\code.cmd'):
        if c and os.path.isfile(c):
            return c
    return None


def apri_in_vscode(cartella, file=None):
    code = trova_vscode()
    if not code:
        return False
    # SICUREZZA: code.cmd passerebbe da cmd.exe (shell=True), dove un percorso con & o %
    # diventerebbe un comando: si lancia direttamente Code.exe, che sta due cartelle sopra
    if code.lower().endswith('.cmd'):
        exe = os.path.normpath(os.path.join(os.path.dirname(code), '..', 'Code.exe'))
        if not os.path.isfile(exe):
            return False
        code = exe
    argomenti = [code, cartella] + ([file] if file else [])
    subprocess.Popen(argomenti, creationflags=NO_FINESTRA)
    return True


# =====================================================================
#  8. VERIFICA DA RIGA DI COMANDO
# =====================================================================
def _verifica():
    cat = carica_catalogo()
    print('Fonte:', cat['fonte'], cat.get('percorso'))
    print('Moduli:', len([k for k in cat['moduli'] if k != '0']), '| quiz:', len(cat['quiz']),
          '| orale:', len(cat['orale']), '| esercizi:', len(cat['esercizi']),
          '| giorni del piano:', len(cat['calendario']))
    for a in cat['avvisi']:
        print('AVVISO:', a)
    residui = 0
    testi = []
    for q in cat['quiz']:
        testi += [(q['id'], q['domanda']), (q['id'], q['commento'])] + [(q['id'], o) for o in q['opzioni']]
    testi += [(o['id'], o['risposta']) for o in cat['orale']]
    testi += [(e['id'], e['testo']) for e in cat['esercizi']]
    for id_, t in testi:
        t = re.sub(r'<pre.*?</pre>', '', t, flags=re.S)
        if re.search(r'\\(?!n)[a-zA-Z]{2,}|[\x00-\x08\x0e-\x1f]', t):
            residui += 1
            print('Residuo in', id_, ':', t[:100])
    senza = [e['id'] for e in cat['esercizi'] if not e['soluzione']['files']
             or not all(f['contenuto'] for f in e['soluzione']['files'])]
    print('Esercizi senza soluzione:', senza or 'nessuno')
    print('Testi con residui:', residui)
    return residui


if __name__ == '__main__':
    if '--copia' in sys.argv:
        destinazione = sys.argv[sys.argv.index('--copia') + 1]
        cat = carica_catalogo()
        if cat['fonte'] != 'dispensa':
            sys.exit('Dispensa non trovata: copia non creata.')
        for k in ('fonte', 'percorso'):
            cat.pop(k, None)
        with io.open(destinazione, 'w', encoding='utf-8') as f:
            json.dump(cat, f, ensure_ascii=False, separators=(',', ':'))
        print('Copia dei contenuti scritta in', destinazione, '(%d KB)' % (os.path.getsize(destinazione) // 1024))
    else:
        sys.exit(1 if _verifica() else 0)
