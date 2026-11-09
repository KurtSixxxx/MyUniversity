#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""Costruisce la versione per telefono (Android e iPhone) con i contenuti della dispensa incorporati.

Uso (dalla cartella Allenatore):
  .ambiente\\Scripts\\python mobile\\crea_mobile.py                 -> mobile/allenatore-iphone.html (copia singola)
  .ambiente\\Scripts\\python mobile\\crea_mobile.py --pubblica      -> ../Pubblicazione/docs/ (sito per GitHub Pages)
  opzioni: --dispensa CARTELLA   (default: Dispensa accanto ad Allenatore; con --pubblica quella in Pubblicazione)
           --uscita CARTELLA     (dove scrivere il sito)

Il sito per GitHub Pages è una PWA: index.html (tutto incluso), manifest.webmanifest, sw.js (funziona
offline), icone. Si apre dal link e si installa: iPhone «Aggiungi alla schermata Home», Android «Installa app».
"""
import argparse
import datetime
import io
import json
import os
import sys

QUI = os.path.dirname(os.path.abspath(__file__))
ALLENATORE = os.path.dirname(QUI)
PROGETTO = os.path.dirname(ALLENATORE)
WEB = os.path.join(ALLENATORE, 'web')
sys.path.insert(0, ALLENATORE)

ar = argparse.ArgumentParser()
ar.add_argument('--pubblica', action='store_true')
ar.add_argument('--dispensa')
ar.add_argument('--uscita')
a = ar.parse_args()
dispensa = a.dispensa or (os.path.join(PROGETTO, 'Pubblicazione', 'Dispensa') if a.pubblica else '')
if dispensa:
    os.environ['ALLENATORE_DISPENSA'] = dispensa
import motore as M  # noqa: E402

cat = M.carica_catalogo(dispensa)
if cat.get('fonte') != 'dispensa':
    sys.exit('Dispensa non trovata.')
print('Dispensa:', cat['percorso'])
dati = {
    'generato': cat['generato'],
    'moduli': cat['moduli'],
    'calendario': cat['calendario'],
    'quiz': cat['quiz'],
    'orale': cat['orale'],
    'esercizi': [{k: e[k] for k in ('id', 'modulo', 'tipo', 'numero', 'titolo', 'difficolta', 'testo')}
                 | {'soluzione': {k: e['soluzione'][k] for k in ('commento', 'files', 'input', 'output')}}
                 for e in cat['esercizi']],
}


def leggi(p):
    return io.open(p, encoding='utf-8').read()


def sicuro_js(t):   # dentro <script>: niente chiusura del tag
    return t.replace('</', '<\\/')


modello = leggi(os.path.join(QUI, 'modello.html'))
for segnaposto in ('/*__DATI__*/', '/*__CONFIG__*/', '/*__GIOCO__*/', '/*__MUSICA__*/', '/*__GIOCO_CSS__*/', '<!--__PWA__-->'):
    assert modello.count(segnaposto) == 1, segnaposto
pagina = (modello
          .replace('/*__DATI__*/', json.dumps(dati, ensure_ascii=False, separators=(',', ':')).replace('</', '<\\/'))
          .replace('/*__CONFIG__*/', sicuro_js(leggi(os.path.join(WEB, 'config.js'))))
          .replace('/*__GIOCO__*/', sicuro_js(leggi(os.path.join(WEB, 'gioco.js'))))
          .replace('/*__MUSICA__*/', sicuro_js(leggi(os.path.join(WEB, 'musica.js'))))
          .replace('/*__GIOCO_CSS__*/', leggi(os.path.join(WEB, 'gioco.css'))))

if not a.pubblica:
    uscita = os.path.join(QUI, 'allenatore-iphone.html')
    io.open(uscita, 'w', encoding='utf-8', newline='\n').write(pagina.replace('<!--__PWA__-->', ''))
    print('Scritto %s (%d KB)' % (uscita, os.path.getsize(uscita) // 1024))
    sys.exit(0)

# ---------------------------------------------------------------- sito per GitHub Pages
dest = a.uscita or os.path.join(PROGETTO, 'Pubblicazione', 'docs')
os.makedirs(dest, exist_ok=True)
versione = datetime.datetime.now().strftime('%Y%m%d%H%M')
pwa = ('<link rel="manifest" href="manifest.webmanifest">\n'
       '<link rel="icon" type="image/png" sizes="192x192" href="icona-192.png">\n'
       '<link rel="apple-touch-icon" href="icona-180.png">\n'
       '<script>window.PWA = %r;</script>' % versione)
io.open(os.path.join(dest, 'index.html'), 'w', encoding='utf-8', newline='\n').write(pagina.replace('<!--__PWA__-->', pwa))

manifest = {
    'name': 'Allenatore Prog2', 'short_name': 'Prog2', 'lang': 'it',
    'description': "Quiz, orale e codice per l'esame di Programmazione 2, con il compagno Bit.",
    'start_url': './', 'scope': './', 'display': 'standalone', 'orientation': 'portrait',
    'background_color': '#000000', 'theme_color': '#000000',
    'icons': [{'src': 'icona-192.png', 'sizes': '192x192', 'type': 'image/png'},
              {'src': 'icona-512.png', 'sizes': '512x512', 'type': 'image/png'},
              {'src': 'icona-512.png', 'sizes': '512x512', 'type': 'image/png', 'purpose': 'maskable'}],
}
io.open(os.path.join(dest, 'manifest.webmanifest'), 'w', encoding='utf-8').write(json.dumps(manifest, ensure_ascii=False, indent=1))

sw = """/* Allenatore Prog2 — service worker: l'app funziona anche senza rete.
   La pagina e le icone restano in cache; Spotify e YouTube passano sempre dalla rete. */
const CACHE = 'prog2-%s';
const FILE = ['./', './index.html', './manifest.webmanifest', './icona-192.png', './icona-512.png', './icona-180.png'];
self.addEventListener('install', e => { e.waitUntil(caches.open(CACHE).then(c => c.addAll(FILE)).then(() => self.skipWaiting())); });
self.addEventListener('activate', e => { e.waitUntil(caches.keys().then(k => Promise.all(k.filter(n => n !== CACHE).map(n => caches.delete(n)))).then(() => self.clients.claim())); });
self.addEventListener('fetch', e => {
  const u = new URL(e.request.url);
  if (e.request.method !== 'GET' || u.origin !== location.origin) return;
  // prima la rete (per avere sempre l'ultima versione), poi la cache se si è offline
  e.respondWith(fetch(e.request).then(r => { const c = r.clone(); caches.open(CACHE).then(x => x.put(e.request, c)); return r; })
    .catch(() => caches.match(e.request).then(r => r || caches.match('./index.html'))));
});
""" % versione
io.open(os.path.join(dest, 'sw.js'), 'w', encoding='utf-8', newline='\n').write(sw)

# icone: terminale nero con le graffe al fosforo, a tutto quadrato (iOS e Android arrotondano da soli)
from PIL import Image, ImageDraw, ImageFilter, ImageFont  # noqa: E402


def icona(lato):
    L = 1024
    im = Image.new('RGB', (L, L), (0, 0, 0))
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
    testo = '{ }'
    alone = Image.new('RGB', (L, L), (0, 0, 0))
    d = ImageDraw.Draw(alone)
    box = d.textbbox((0, 0), testo, font=font)
    pos = ((L - (box[2] - box[0])) / 2 - box[0], (L - (box[3] - box[1])) / 2 - box[1] - 10)
    d.text(pos, testo, font=font, fill=(51, 255, 153))
    im = Image.blend(im, alone.filter(ImageFilter.GaussianBlur(40)), 0.9)
    im.paste(alone, (0, 0), alone.convert('L').point(lambda v: 255 if v > 40 else 0))
    d = ImageDraw.Draw(im)
    for y in range(0, L, 8):   # scanline
        d.line([(0, y + 6), (L, y + 6)], fill=(0, 0, 0), width=2)
    d.rectangle((70, 70, L - 70, L - 70), outline=(51, 255, 153), width=6)
    return im.resize((lato, lato), Image.LANCZOS)


for lato, nome in ((192, 'icona-192.png'), (512, 'icona-512.png'), (180, 'icona-180.png')):
    icona(lato).save(os.path.join(dest, nome))
io.open(os.path.join(dest, '.nojekyll'), 'w').write('')
print('Sito per telefono scritto in %s (%d KB): %d quiz, %d orale, %d esercizi' % (
    dest, os.path.getsize(os.path.join(dest, 'index.html')) // 1024, len(dati['quiz']), len(dati['orale']), len(dati['esercizi'])))
