#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Costruisce "Allenatore Prog2.exe" (un solo file, con icona e informazioni di versione).

Uso (dalla cartella Allenatore):   crea_app.bat
oppure                              .ambiente\\Scripts\\python crea_app.py [--senza-collegamenti] [--debug]
Versione da distribuire:            .ambiente\\Scripts\\python crea_app.py --pubblica
   (contenuti dalla dispensa di Pubblicazione/, eseguibile in Pubblicazione/rilascio/, niente collegamenti)

Sul Mac (python3 crea_app.py [--pubblica]) costruisce invece "Allenatore Prog2.app"
e lo impacchetta in un .dmg (Apple Silicon o Intel, come il Mac su cui gira):
vedi main_mac(). Da Windows non si può: lo fa il workflow mac-prog2.yml su GitHub.

Passi:
  1. disegna l'icona (risorse/icona.ico)
  2. crea la copia dei contenuti della dispensa (build/contenuti.json), inclusa nell'eseguibile
  3. compila con PyInstaller
  4. copia l'eseguibile accanto alla cartella Dispensa
  5. crea i collegamenti sul Desktop e nel menu Start
"""
import io
import os
import shutil
import subprocess
import sys

QUI = os.path.dirname(os.path.abspath(__file__))
PROGETTO = os.path.dirname(QUI)
sys.path.insert(0, QUI)
import motore as M  # noqa: E402

NOME = M.APP_NOME
RISORSE = os.path.join(QUI, 'risorse')
BUILD = os.path.join(QUI, 'build')
DIST = os.path.join(QUI, 'dist')


def passo(t):
    print('\n== ' + t)


def cartella_pubblica(*parti):
    """Pubblicazione/... sul PC dello studente; nel repository la dispensa pubblica sta accanto ad Allenatore/."""
    if os.path.isdir(os.path.join(PROGETTO, 'Pubblicazione')):
        return os.path.join(PROGETTO, 'Pubblicazione', *parti)
    return os.path.join(PROGETTO, *parti)


def crea_contenuti(pubblica):
    """Copia dei contenuti della dispensa (build/contenuti.json), inclusa nell'app."""
    import json
    cat = M.carica_catalogo(cartella_pubblica('Dispensa') if pubblica else '')
    print('   da ' + str(cat.get('percorso')))
    if cat['fonte'] != 'dispensa':
        sys.exit('Dispensa non trovata: impossibile creare la copia dei contenuti.')
    for k in ('fonte', 'percorso'):
        cat.pop(k, None)
    contenuti = os.path.join(BUILD, 'contenuti.json')
    with io.open(contenuti, 'w', encoding='utf-8') as f:
        json.dump(cat, f, ensure_ascii=False, separators=(',', ':'))
    print('   %d quiz, %d domande d\'orale, %d esercizi (%d KB)' % (
        len(cat['quiz']), len(cat['orale']), len(cat['esercizi']), os.path.getsize(contenuti) // 1024))
    return contenuti


# ---------------------------------------------------------------- 1. icona
def crea_icona():
    """Icona in stile «Terminale»: riquadro nero con bordo e graffe al fosforo, alone e scanline."""
    from PIL import Image, ImageDraw, ImageFilter, ImageFont
    L, VERDE = 1024, (51, 255, 153)
    margine, raggio = 64, 200
    maschera = Image.new('L', (L, L), 0)
    ImageDraw.Draw(maschera).rounded_rectangle((margine, margine, L - margine, L - margine), raggio, fill=255)
    font = None
    for nome in ('CascadiaMono.ttf', 'CascadiaCode.ttf', 'consolab.ttf', 'cour.ttf'):
        p = os.path.join(os.environ.get('WINDIR', r'C:\Windows'), 'Fonts', nome)
        if os.path.exists(p):
            font = ImageFont.truetype(p, 400)
            try:
                font.set_variation_by_name('Bold')
            except Exception:
                pass
            break
    segno = Image.new('RGB', (L, L), (0, 0, 0))
    d = ImageDraw.Draw(segno)
    box = d.textbbox((0, 0), '{ }', font=font)
    d.text(((L - (box[2] - box[0])) / 2 - box[0], (L - (box[3] - box[1])) / 2 - box[1] - 10), '{ }', font=font, fill=VERDE)
    fondo = Image.new('RGB', (L, L), (2, 8, 5))
    fondo = Image.blend(fondo, segno.filter(ImageFilter.GaussianBlur(42)), .85)
    fondo.paste(segno, (0, 0), segno.convert('L').point(lambda v: 255 if v > 40 else 0))
    d = ImageDraw.Draw(fondo)
    for y in range(0, L, 9):
        d.line([(0, y + 7), (L, y + 7)], fill=(0, 0, 0), width=2)
    bordo = Image.new('L', (L, L), 0)
    ImageDraw.Draw(bordo).rounded_rectangle((margine, margine, L - margine, L - margine), raggio, outline=255, width=14)
    fondo.paste(Image.new('RGB', (L, L), VERDE), (0, 0), bordo)
    icona = Image.new('RGBA', (L, L), (0, 0, 0, 0))
    icona.paste(fondo, (0, 0), maschera)
    os.makedirs(RISORSE, exist_ok=True)
    icona.save(os.path.join(RISORSE, 'icona.png'))
    icona.save(os.path.join(RISORSE, 'icona.ico'),
               sizes=[(16, 16), (20, 20), (24, 24), (32, 32), (40, 40), (48, 48), (64, 64), (128, 128), (256, 256)])


def crea_qr():
    """QR della versione per telefono, dal link scritto in web/config.js (se c'è)."""
    import re as _re
    testo = io.open(os.path.join(QUI, 'web', 'config.js'), encoding='utf-8').read()
    m = _re.search(r"linkTelefono:\s*'([^']*)'", testo)
    dest = os.path.join(QUI, 'web', 'qr-telefono.svg')
    if not m or not m.group(1).strip():
        if os.path.exists(dest):
            os.remove(dest)
        return None
    import segno
    segno.make(m.group(1).strip(), error='m').save(dest, scale=6, border=2, dark='#000000', light='#ffffff')
    return m.group(1).strip()


# ---------------------------------------------------------------- 2. informazioni di versione
def file_versione():
    v = tuple(int(x) for x in (M.APP_VERSIONE + '.0.0.0').split('.')[:4])
    testo = f'''VSVersionInfo(
  ffi=FixedFileInfo(filevers={v}, prodvers={v}, mask=0x3f, flags=0x0, OS=0x40004, fileType=0x1, subtype=0x0, date=(0, 0)),
  kids=[
    StringFileInfo([StringTable('041004B0', [
      StringStruct('CompanyName', '{NOME}'),
      StringStruct('FileDescription', '{NOME}'),
      StringStruct('FileVersion', '{M.APP_VERSIONE}'),
      StringStruct('InternalName', 'AllenatoreProg2'),
      StringStruct('LegalCopyright', '2026 Giulio Casella'),
      StringStruct('OriginalFilename', '{NOME}.exe'),
      StringStruct('ProductName', '{NOME}'),
      StringStruct('ProductVersion', '{M.APP_VERSIONE}')])]),
    VarFileInfo([VarStruct('Translation', [0x0410, 1200])])
  ]
)
'''
    p = os.path.join(BUILD, 'versione.txt')
    io.open(p, 'w', encoding='utf-8').write(testo)
    return p


# ---------------------------------------------------------------- 5. collegamenti
def collegamento(destinazione_lnk, exe):
    ps = ('$s=(New-Object -ComObject WScript.Shell).CreateShortcut(\'{lnk}\');'
          '$s.TargetPath=\'{exe}\';$s.WorkingDirectory=\'{cart}\';$s.IconLocation=\'{exe},0\';'
          '$s.Description=\'Allenatore per l esame di Programmazione 2\';$s.Save()').format(
        lnk=destinazione_lnk.replace("'", "''"), exe=exe.replace("'", "''"),
        cart=os.path.dirname(exe).replace("'", "''"))
    subprocess.run(['powershell', '-NoProfile', '-Command', ps], check=True)


# ---------------------------------------------------------------- Mac
PRIMO_AVVIO_MAC = """ALLENATORE PROG2 PER MAC
========================

1. Trascina «Allenatore Prog2» nella cartella Applicazioni.

2. La prima volta macOS potrebbe dire che l'app «non può essere aperta» o che
   lo sviluppatore non è verificato (l'app non è firmata da Apple: è un progetto
   gratuito di uno studente). Per aprirla lo stesso:
     • prova ad aprirla una volta, chiudi l'avviso;
     • Impostazioni di Sistema → Privacy e sicurezza → in fondo «Apri comunque».
   In alternativa, nel Terminale:
     xattr -dr com.apple.quarantine "/Applications/Allenatore Prog2.app"

3. Per compilare gli esercizi serve il compilatore di Apple. Nel Terminale:
     xcode-select --install
   e conferma l'installazione (pochi minuti, una volta sola).

I tuoi progressi sono in ~/Library/Application Support/Allenatore Prog2.
Le scorciatoie con Ctrl funzionano anche con ⌘ (es. ⌘↵ esegue il codice).
"""


def main_mac(pubblica):
    import platform
    import plistlib
    import tempfile
    from PIL import Image
    arch = 'AppleSilicon' if platform.machine() == 'arm64' else 'Intel'

    passo('1. Icona e QR del telefono')
    png = os.path.join(RISORSE, 'icona.png')
    if not os.path.isfile(png):     # di solito c'è già (disegnata su Windows, con il font giusto)
        crea_icona()
    icns = os.path.join(BUILD, 'icona.icns')
    Image.open(png).convert('RGBA').save(icns)
    print('   ' + icns)
    print('   QR: ' + (crea_qr() or 'nessun link del telefono in web/config.js'))

    passo('2. Copia dei contenuti della dispensa')
    contenuti = crea_contenuti(pubblica)

    passo('3. Compilazione con PyInstaller (%s)' % arch)
    sep = os.pathsep
    subprocess.run([sys.executable, '-m', 'PyInstaller', '--noconfirm', '--clean', '--windowed', '--onedir',
                    '--name', NOME, '--icon', icns, '--osx-bundle-identifier', 'it.allenatoreprog2.app',
                    '--add-data', os.path.join(QUI, 'web') + sep + 'web',
                    '--add-data', contenuti + sep + '.',
                    '--distpath', DIST, '--workpath', os.path.join(BUILD, 'pyinstaller'), '--specpath', BUILD,
                    os.path.join(QUI, 'app.py')], check=True)
    app = os.path.join(DIST, NOME + '.app')

    passo('4. Informazioni del pacchetto e firma ad hoc')
    info = os.path.join(app, 'Contents', 'Info.plist')
    with open(info, 'rb') as f:
        p = plistlib.load(f)
    p.update({'CFBundleDisplayName': NOME, 'CFBundleShortVersionString': M.APP_VERSIONE,
              'CFBundleVersion': M.APP_VERSIONE, 'NSHumanReadableCopyright': '2026 Giulio Casella · CC BY-NC-SA 4.0',
              'LSApplicationCategoryType': 'public.app-category.education', 'NSHighResolutionCapable': True,
              'LSMinimumSystemVersion': '11.0',
              # l'interfaccia è servita da http://127.0.0.1 (server locale di pywebview)
              'NSAppTransportSecurity': {'NSAllowsLocalNetworking': True}})
    with open(info, 'wb') as f:
        plistlib.dump(p, f)
    # dopo aver toccato Info.plist la firma va rifatta, altrimenti macOS dice che l'app è «danneggiata»
    subprocess.run(['codesign', '--force', '--deep', '--sign', '-', app], check=True)
    subprocess.run(['codesign', '--verify', '--deep', '--strict', app], check=True)
    print('   ' + app)

    passo('5. Immagine disco (.dmg)')
    cartella = cartella_pubblica('rilascio') if pubblica else PROGETTO
    os.makedirs(cartella, exist_ok=True)
    dmg = os.path.join(cartella, 'Allenatore.Prog2-mac-%s.dmg' % arch)
    with tempfile.TemporaryDirectory() as tmp:
        subprocess.run(['ditto', app, os.path.join(tmp, NOME + '.app')], check=True)
        os.symlink('/Applications', os.path.join(tmp, 'Applicazioni'))
        with io.open(os.path.join(tmp, 'Leggimi - primo avvio.txt'), 'w', encoding='utf-8') as f:
            f.write(PRIMO_AVVIO_MAC)
        if os.path.exists(dmg):
            os.remove(dmg)
        subprocess.run(['hdiutil', 'create', '-volname', NOME, '-srcfolder', tmp, '-ov', '-format', 'UDZO', dmg], check=True)
    print('   ' + dmg + '  (%d MB)' % (os.path.getsize(dmg) // (1024 * 1024)))
    print('\nFatto.')


def main():
    os.makedirs(BUILD, exist_ok=True)
    pubblica = '--pubblica' in sys.argv
    if sys.platform == 'darwin':
        return main_mac(pubblica)
    passo('1. Icona e QR del telefono')
    crea_icona()
    print('   risorse/icona.ico')
    print('   QR: ' + (crea_qr() or 'nessun link del telefono in web/config.js'))

    passo('2. Copia dei contenuti della dispensa')
    contenuti = crea_contenuti(pubblica)

    passo('3. Compilazione con PyInstaller')
    sep = os.pathsep
    debug = '--debug' in sys.argv   # versione con console, per leggere gli errori
    nome_exe = NOME + (' debug' if debug else '')
    comando = [sys.executable, '-m', 'PyInstaller', '--noconfirm', '--clean', '--onefile',
               '--console' if debug else '--windowed',
               '--name', nome_exe, '--icon', os.path.join(RISORSE, 'icona.ico'),
               '--version-file', file_versione(),
               '--add-data', os.path.join(QUI, 'web') + sep + 'web',
               '--add-data', contenuti + sep + '.',
               '--add-data', os.path.join(RISORSE, 'icona.ico') + sep + '.',
               '--distpath', DIST, '--workpath', os.path.join(BUILD, 'pyinstaller'), '--specpath', BUILD,
               os.path.join(QUI, 'app.py')]
    subprocess.run(comando, check=True)
    exe_creato = os.path.join(DIST, nome_exe + '.exe')
    if debug:
        print('\nVersione di debug: ' + exe_creato)
        return

    if pubblica:
        passo('4. Copia in Pubblicazione/rilascio (da caricare nelle Release di GitHub)')
        cartella = cartella_pubblica('rilascio')
        os.makedirs(cartella, exist_ok=True)
        exe = os.path.join(cartella, NOME + '.exe')
        shutil.copy2(exe_creato, exe)
        print('   ' + exe + '  (%d MB)' % (os.path.getsize(exe) // (1024 * 1024)))
        print('\nFatto.')
        return

    passo('4. Copia accanto alla dispensa')
    exe = os.path.join(PROGETTO, NOME + '.exe')
    shutil.copy2(exe_creato, exe)
    print('   ' + exe + '  (%d MB)' % (os.path.getsize(exe) // (1024 * 1024)))

    if '--senza-collegamenti' not in sys.argv:
        passo('5. Collegamenti')
        desktop = os.path.join(os.path.expanduser('~'), 'Desktop')
        try:
            import ctypes
            buf = ctypes.create_unicode_buffer(260)
            ctypes.windll.shell32.SHGetFolderPathW(None, 0x0010, None, 0, buf)  # CSIDL_DESKTOPDIRECTORY
            desktop = buf.value or desktop
        except Exception:
            pass
        start = os.path.join(os.environ['APPDATA'], 'Microsoft', 'Windows', 'Start Menu', 'Programs')
        for cartella in (desktop, start):
            lnk = os.path.join(cartella, NOME + '.lnk')
            collegamento(lnk, exe)
            print('   ' + lnk)
    print('\nFatto.')


if __name__ == '__main__':
    main()
