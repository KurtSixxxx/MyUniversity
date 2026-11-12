/* Allenatore Prog2 — service worker: l'app funziona anche senza rete.
   La pagina e le icone restano in cache; Spotify e YouTube passano sempre dalla rete. */
const CACHE = 'prog2-202611121540';
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
