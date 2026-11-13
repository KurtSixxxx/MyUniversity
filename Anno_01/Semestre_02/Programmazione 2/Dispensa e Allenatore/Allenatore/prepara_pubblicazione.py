#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Prepara la cartella ../Pubblicazione, pronta da caricare su GitHub.

Uso (dalla cartella Allenatore):   .ambiente\\Scripts\\python prepara_pubblicazione.py [--exe]

  Pubblicazione/
    README.md, PUBBLICARE.md, .gitignore   (scritti a mano, non vengono toccati)
    Dispensa/        la dispensa pubblica (sorgenti LaTeX, codice, PDF): si modifica lì
    Allenatore/      i sorgenti dell'app, copiati da qui SENZA dati personali
    docs/            la versione per telefono (GitHub Pages serve questa cartella)
    rilascio/        con --exe: l'eseguibile da caricare nelle Release (escluso da git)

Non copia mai: progressi, impostazioni, codice scritto dallo studente, ambiente Python,
cartelle build/dist, la copia privata per iPhone.
"""
import os
import shutil
import subprocess
import sys

QUI = os.path.dirname(os.path.abspath(__file__))
PUB = os.path.join(os.path.dirname(QUI), 'Pubblicazione')
DEST = os.path.join(PUB, 'Allenatore')

DA_COPIARE = [
    'app.py', 'motore.py', 'crea_app.py', 'crea_app.bat', 'prepara_pubblicazione.py', 'collaudo.py',
    'web', 'mobile/modello.html', 'mobile/crea_mobile.py', 'risorse/icona.ico', 'risorse/icona.png',
]
ESCLUSI = {'tema-iniziale.js', '__pycache__'}


def copia(rel):
    src, dst = os.path.join(QUI, rel), os.path.join(DEST, rel)
    if os.path.isdir(src):
        shutil.copytree(src, dst, ignore=lambda d, nomi: [n for n in nomi if n in ESCLUSI], dirs_exist_ok=True)
    else:
        os.makedirs(os.path.dirname(dst), exist_ok=True)
        shutil.copy2(src, dst)


def main():
    if not os.path.isdir(os.path.join(PUB, 'Dispensa')):
        sys.exit('Manca Pubblicazione/Dispensa.')
    print('== Sorgenti dell\'app -> Pubblicazione/Allenatore')
    if os.path.isdir(DEST):
        shutil.rmtree(DEST)
    for rel in DA_COPIARE:
        copia(rel)
        print('   ' + rel)
    with open(os.path.join(DEST, 'requirements.txt'), 'w', encoding='utf-8') as f:
        f.write('pywebview>=5\npyinstaller\npillow\nsegno\n')

    print('\n== Versione per telefono -> Pubblicazione/docs')
    subprocess.run([sys.executable, os.path.join(QUI, 'mobile', 'crea_mobile.py'), '--pubblica',
                    '--uscita', os.path.join(PUB, 'docs')], check=True)

    if '--exe' in sys.argv:
        print('\n== Eseguibile -> Pubblicazione/rilascio')
        subprocess.run([sys.executable, os.path.join(QUI, 'crea_app.py'), '--pubblica'], check=True)

    # controllo finale: niente dati personali
    sospetti = []
    for radice, _, files in os.walk(PUB):
        if '.git' in radice or 'rilascio' in radice:
            continue
        for n in files:
            if n.endswith(('.json',)) and 'progressi' in n or n in ('impostazioni.json',):
                sospetti.append(os.path.join(radice, n))
    if sospetti:
        print('\nATTENZIONE, file da controllare:\n  ' + '\n  '.join(sospetti))
    print('\nFatto. Controlla Pubblicazione/ e segui PUBBLICARE.md.')


if __name__ == '__main__':
    main()
