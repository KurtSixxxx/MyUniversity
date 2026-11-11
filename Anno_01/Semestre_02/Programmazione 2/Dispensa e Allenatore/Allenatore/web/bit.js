/* =====================================================================
   Allenatore Prog2 — Bit, il compagno di studio
   ---------------------------------------------------------------------
   Stadi ed evoluzioni, i 6 umori, il disegno in pixel art (SVG 24×24),
   l'Armadio dei cosmetici (sbloccati dai traguardi) e il «Compagno»:
   Bit in scena, ancorato in punti fissi dell'interfaccia, che reagisce
   e parla con un fumetto a 8 bit.
   Condiviso tra PC e telefono. Va caricato DOPO gioco.js: si aggiunge
   a window.Gioco (Gioco.pet, Gioco.svgPet, Gioco.Compagno, ...).
   ===================================================================== */
(function () {
  'use strict';
  const G = window.Gioco, { rgbDa, hslDa, hash, oggiISO } = G._util;
  const scegli = l => l[Math.floor(Math.random() * l.length)];

  /* ------------------------------------------------------------ stadi */
  const STADI = [
    { da: 1, nome: 'Uovo', descr: 'Un uovo di silicio. Qualcosa si muove là dentro.' },
    { da: 3, nome: 'Bit', descr: 'Appena nato: sa solo 0 e 1, ma impara in fretta.' },
    { da: 8, nome: 'Byte', descr: 'Otto bit di entusiasmo. Ha scoperto i puntatori.' },
    { da: 14, nome: 'Kilobyte', descr: 'Cresce a vista d\'occhio. Sogna liste concatenate.' },
    { da: 20, nome: 'Megabyte', descr: 'Robusto e sveglio: bilancia alberi a occhi chiusi.' },
    { da: 26, nome: 'Gigabyte', descr: 'Forma finale. Ha visto ogni segfault e li ha perdonati.' },
  ];
  const indiceStadio = L => STADI.reduce((k, s, j) => L >= s.da ? j : k, 0);

  /* ------------------------------------------------------------ i 6 umori */
  /* Umori «di fondo» (calcolati dai progressi):
       neutro    studio normale
       felice    tutte e tre le missioni di oggi completate
       euforico  simulazione d'esame superata oggi (sul momento anche: combo di 5 giuste)
       affamato  2 o 3 giorni senza studiare
       dorme     4 o più giorni senza studiare
     Umore «di evento» (solo sul momento): triste = errore al quiz o compilazione fallita. */
  const UMORI = { neutro: 'neutro', felice: 'felice', euforico: 'euforico', triste: 'triste', affamato: 'affamato', dorme: 'a riposo',
    // espressioni delle reazioni (non sono umori)
    sbadiglio: 'annoiato', mangia: 'a pranzo di XP', errore: 'in crash', tranquillo: 'neutro' };
  function umoreBase(st) {
    if (st.giorniFermo != null && st.giorniFermo >= 4) return 'dorme';
    if (st.giorniFermo != null && st.giorniFermo >= 2) return 'affamato';
    if (st.simOggi) return 'euforico';
    if ((st.missioni || []).length && st.missioni.every(m => m.fatto)) return 'felice';
    return 'neutro';
  }
  const MOTIVI = {
    neutro: 'Studio normale. Completa le tre missioni di oggi per renderlo felice.',
    felice: 'Hai completato tutte e tre le missioni di oggi.',
    euforico: 'Hai superato una simulazione d\'esame oggi.',
    triste: 'Ha appena visto un errore: una risposta giusta lo rimette in sesto.',
    affamato: 'Non studi da {g} giorni: ha fame di XP.',
    dorme: 'Non studi da {g} giorni: si è addormentato. Una missione lo sveglia.',
  };
  const FRASI = {
    neutro: ['Pronto quando lo sei tu. Una missione per cominciare?', 'Una domanda alla volta, un nodo alla volta.', 'Ho preparato tre missioni per oggi.'],
    felice: ['Tre missioni su tre! Oggi mi hai sfamato per bene.', 'Missioni completate: mi crescono i byte dalla gioia.', 'Giornata piena. Domani si ricomincia, ma intanto festeggio.'],
    euforico: ['Simulazione superata! Sono a 64 bit di felicità.', 'Promossi alla prova generale! L\'esame vero ci fa un baffo.', 'Che giornata! Il mio heap è pieno di XP.'],
    triste: ['Mi è rimasto un errore sullo stomaco... riproviamo?', 'Un segfault fa male, ma insegna.'],
    affamato: ['Ho fame di XP... facciamo qualche quiz?', 'Sono giorni che non mangio una risposta giusta.', 'Brontolio di stomaco: segmentation fault in arrivo.'],
    dorme: ['Zzz... (svegliami con una missione)', 'Zzz... delete[] noia; ...zzz', 'Zzz... sogno un BST bilanciato...'],
  };
  const CONSIGLI = [
    'Ogni new vuole il suo delete. Ogni new[] il suo delete[].',
    'Una classe base con metodi virtuali vuole il distruttore virtuale.',
    'Regola dei tre: distruttore, costruttore di copia, operator=.',
    'Nel laboratorio compila spesso: un errore alla volta.',
    'Prima di scrivere una lista, disegnala su carta.',
    'Ricorsione: caso base prima di tutto.',
    'Nel BST, cancellare un nodo con due figli = successore in-order.',
    'Il quiz si supera con 18 su 30: punta a 22 per stare tranquillo.',
    'All\'orale: definizione, esempio, disegno. In quest\'ordine.',
    'operator<< restituisce ostream& per poter concatenare.',
    'Un reference va inizializzato subito e non cambia più bersaglio.',
    'BFS usa una coda, DFS usa la ricorsione (cioè uno stack).',
  ];

  function pet(stato, nome = 'Bit') {
    const i = indiceStadio(stato.livello), umore = umoreBase(stato);
    const giorno = hash(oggiISO() + umore);
    const frase = Math.random() < .4 && umore !== 'dorme' ? scegli(CONSIGLI) : FRASI[umore][giorno % FRASI[umore].length];
    const prossimo = STADI[i + 1];
    return {
      nome: (nome || 'Bit').trim() || 'Bit', stadio: STADI[i].nome, descr: STADI[i].descr, indice: i,
      umore, frase, motivo: MOTIVI[umore].replace('{g}', stato.giorniFermo ?? 0),
      prossimo: prossimo ? { nome: prossimo.nome, livello: prossimo.da } : null,
      sazieta: Math.min(1, stato.xpOggi / Math.max(1, stato.obiettivo)),
    };
  }

  /* ------------------------------------------------------------ disegno in pixel art (SVG 24×24) */
  /* Ogni stadio è disegnato per metà (12 colonne) e specchiato; 'extra' aggiunge pixel asimmetrici.
     Lettere: O contorno, B corpo, L luce, D ombra, A accessorio (colore complementare),
     S secondo accessorio, G oro, K visiera scura, W bianco. Il viso è disegnato a parte. */
  const SPRITE = [
    { // 0 Uovo
      righe: ['', '', '', '..........OO', '........OOLL', '.......OLLBB', '......OLLBBB', '......OLBBBB', '.....OLBBBBB', '.....OBBBBBB',
        '.....OBBBBBB', '....OBBBBBBB', '....OBBBBBBB', '....OBBBBBBB', '....OBBBBBBB', '....OBBBBBBB', '.....OBBBBBB', '.....ODBBBBB',
        '......ODDBBB', '.......OODDD', '.........OOO'],
      extra: [[11, 7, 'A'], [12, 7, 'A'], [11, 8, 'A'], [7, 11, 'A'], [8, 11, 'A'], [8, 12, 'A'], [15, 10, 'A'], [16, 10, 'A'], [16, 11, 'A'],
        [12, 14, 'A'], [13, 14, 'A'], [13, 15, 'A'], [17, 13, 'D'], [17, 14, 'D'], [16, 15, 'D'], [17, 15, 'D'], [16, 16, 'D'], [15, 17, 'D']],
      occhi: [[9, 12], [13, 12]], bocca: null, guance: null, pancia: [18, 15], testa: [16, 3] },
    { // 1 Bit
      righe: ['', '', '', '', '', '', '', '........OOOO', '......OOLLBB', '.....OLLBBBB', '....OLBBBBBB', '....OBBBBBBB', '...OBBBBBBBB',
        '...OBBBBBBBB', '...OBBBBBBBB', '...OBBBBBBBB', '...ODBBBBBBB', '....ODBBBBBB', '....ODDBBBBB', '.....OODDDDD', '......OOOOOO',
        '......ODO...', '......OOO...'],
      extra: [[11, 6, 'O'], [12, 5, 'A'], [13, 5, 'A'], [13, 4, 'A'], [14, 4, 'A'], [12, 6, 'O']],
      occhi: [[8, 12], [14, 12]], bocca: [11, 15], guance: [[6, 14], [16, 14]], pancia: [19, 16], testa: [17, 5] },
    { // 2 Byte
      righe: ['', '', '...........G', '...........G', '...........O', '...........O', '....OOOOOOOO', '...OLLLBBBBB', '...OLBBBBBBB',
        '...OBBBBBBBB', '..AOBBBBBBBB', '..AOBBBBBBBB', '...OBBBBBBBB', '...OBBBBBBBB', '...ODBBBBBBB', '...ODDDDDDDD', '....OOOOOOOO',
        '......OBBBBB', '.....OBBBBAA', '.....OBBBBAA', '.....ODBBBBB', '......OOOOOO', '.......ODO..', '.......OOO..'],
      extra: [],
      occhi: [[8, 10], [14, 10]], bocca: [11, 13], guance: [[6, 12], [16, 12]], pancia: [19, 19], testa: [16, 2] },
    { // 3 Kilobyte
      righe: ['', '', '', '.......OOOOO', '.....OOLLBBB', '....OLLBBBBB', '...OLBBBBBBB', '.AAOBBBBBBBB', 'AAAOBBBBBBBB', '.AAOBBBBBBBB',
        '..OBBBBBBBBB', '..OBBBBBBBBB', '..OBBBBBBBBB', '..OBBBBBBBBB', '..OGGGGGGGGG', '..ODBBBBBBBB', '..ODBBBBBBBB', '...ODBBBBBBB',
        '...ODDBBBBBB', '....OODDDDDD', '......OOOOOO', '.....OBBO...', '.....OOOO...'],
      extra: [[11, 14, 'A'], [12, 14, 'A']],
      occhi: [[7, 9], [15, 9]], bocca: [11, 12], guance: [[5, 11], [17, 11]], pancia: [21, 16], testa: [17, 2] },
    { // 4 Megabyte
      righe: ['', '', '........OOOO', '......OOLLBB', '.....OLLBBBB', '....OLBBBBBB', '....OBBBBBBB', '....ODDDDDDD', '....OKKKKKKK',
        '....OKKKKKKK', '....ODDDDDDD', '....OBBBBBBB', 'OAAAAOBBBBBB', 'OAAAAOBBBBBB', '.OOOOOBBBBGG', '.....OBBBBGG', '.....OBBBBBB',
        '.....ODBBBBB', '.....ODDBBBB', '.....OODDDDD', '......OOOOOO', '......OAAO..', '......OOOO..'],
      extra: [],
      occhi: [[8, 8], [14, 8]], bocca: [11, 11], guance: null, visiera: true, pancia: [20, 17], testa: [17, 1] },
    { // 5 Gigabyte
      righe: ['', '......G...G.', '......GG.GGG', '......GGGGGG', '......GAGGGA', '.....OOOOOOO', '....OLLBBBBB', '...OLBBBBBBB',
        '...OBBBBBBBB', '..OBBBBBBBBB', '..OBBBBBBBBB', '..OBBBBBBBBB', '..OBBBBBBBBB', 'SSOBBBBBBBBB', 'SSODBBBBBBBB', 'SSODBBBBBBBB',
        'SSSODBBBBBBB', 'SSSODDBBBBBB', 'SSSSODDDDDDD', 'SSSSSOOOOOOO', '.SSSS.OBBO..', '......OOOO..'],
      extra: [],
      occhi: [[8, 9], [14, 9]], bocca: [11, 12], guance: [[6, 11], [16, 11]], pancia: [21, 15], testa: [18, 0] },
  ];
  const mescola = (a, b, t) => a.map((c, i) => Math.round(c + (b[i] - c) * t));
  const hex = rgb => '#' + rgb.map(c => c.toString(16).padStart(2, '0')).join('');
  function hslHex(h, s, l) {
    s /= 100; l /= 100;
    const f = n => { const k = (n + h / 30) % 12, a = s * Math.min(l, 1 - l); return Math.round(255 * (l - a * Math.max(-1, Math.min(k - 3, 9 - k, 1)))); };
    return hex([f(0), f(8), f(4)]);
  }
  function colori(accento) {
    const rgb = rgbDa(accento), [h, s] = hslDa(rgb), grigio = s < 15;
    return {
      B: hex(rgb), L: hex(mescola(rgb, [255, 255, 255], .45)), D: hex(mescola(rgb, [0, 0, 0], .35)), O: hex(mescola(rgb, [0, 0, 0], .82)),
      A: grigio ? '#ff4fd8' : hslHex((h + 180) % 360, 88, 63), S: grigio ? '#5b3cc4' : hslHex((h + 205) % 360, 62, 40),
      G: '#ffd447', K: '#0b1020', W: '#ffffff', R: '#ff7aa8', P: hex(mescola(rgb, [0, 0, 0], .9)),
    };
  }

  /* palette dell'Armadio: 'app' segue il colore scelto nelle impostazioni */
  const PALETTE = [
    { id: 'app', nome: 'Colore dell\'app', descr: 'Segue il colore del terminale scelto nelle impostazioni.' },
    { id: 'fosforo', nome: 'Fosforo verde', descr: 'Il verde dei terminali anni \'80.', base: '#33ff99' },
    { id: 'ambra', nome: 'Ambra vintage', descr: 'Monitor a fosfori ambra, profumo di DOS.', base: '#ffb000', req: 'serie3' },
    { id: 'ciano', nome: 'Ciano hacker', descr: 'Freddo come una shell alle tre di notte.', base: '#00e5ff', req: 'hello' },
    { id: 'magenta', nome: 'Cyberpunk magenta', descr: 'Neon, pioggia e codice che scorre.', base: '#ff2bd6', extra: { A: '#00f0ff', S: '#ffe600', R: '#00f0ff' }, req: 'promosso' },
    { id: 'gameboy', nome: 'GameBoy monocromo', descr: 'Quattro tonalità di verde e niente di più.', req: 'cento',
      fisso: { B: '#8bac0f', L: '#9bbc0f', D: '#306230', O: '#0f380f', A: '#306230', S: '#0f380f', G: '#9bbc0f', K: '#0f380f', W: '#9bbc0f', R: '#306230', P: '#0f380f' } },
    { id: 'oro', nome: 'Oro leggendario', descr: 'Riservato a chi ha raggiunto il livello 20.', req: 'liv20',
      fisso: { B: '#ffc93c', L: '#fff1a8', D: '#c98a00', O: '#3d2600', A: '#ff4d6d', S: '#8a1c3c', G: '#ffffff', K: '#1a1206', W: '#ffffff', R: '#ff8a5c', P: '#3d2600' } },
  ];
  function coloriPalette(id, accento) {
    const p = PALETTE.find(x => x.id === id);
    if (!p || id === 'app') return colori(accento || '#33ff99');
    if (p.fisso) return { ...p.fisso };
    return { ...colori(p.base), ...(p.extra || {}) };
  }

  const ALONE = { euforico: '#ffd447', felice: 'B', neutro: 'B', tranquillo: 'B', affamato: '#ff9f1a', dorme: '#6c8cff',
    errore: '#ff3b5c', triste: '#5b8cff', sbadiglio: 'B', mangia: '#ffd447' };

  /* geometria utile agli accessori: cima della testa (prima riga del contorno larga almeno 4) e larghezza di una riga */
  function geometria(px, sp) {
    let cima = 0;
    for (let y = 0; y < 24; y++) { let n = 0; for (let x = 0; x < 24; x++) if (px.get(x + ',' + y) === 'O') n++; if (n >= 4) { cima = y; break; } }
    const riga = y => { let a = 99, b = -1; for (let x = 0; x < 24; x++) if (px.has(x + ',' + y)) { a = Math.min(a, x); b = Math.max(b, x); } return [a, b]; };
    const [, ey] = sp.occhi[0];
    const collo = sp.bocca ? sp.bocca[1] + 3 : ey + 5;
    return { cima, riga, collo };
  }

  /* accessori dell'Armadio, disegnati sopra il viso */
  function accessorio(id, sp, g, C, rect) {
    const [[lx, ly], [rx, ry]] = sp.occhi, cx = 12;
    switch (id) {
      case 'thug':   // occhiali Thug Life: barra nera, lenti a gradini, riflessi bianchi
        return rect(lx - 2, ly - 1, rx - lx + 6, 1, C.K) + rect(lx - 1, ly, 4, 2, C.K) + rect(rx - 1, ly, 4, 2, C.K)
          + rect(lx, ly + 2, 2, 1, C.K) + rect(rx, ly + 2, 2, 1, C.K) + rect(lx + 3, ly, rx - lx - 4, 1, C.K)
          + rect(lx - 1, ly, 1, 1, C.W) + rect(lx, ly + 1, 1, 1, C.W) + rect(rx - 1, ly, 1, 1, C.W) + rect(rx, ly + 1, 1, 1, C.W);
      case 'monocolo':   // anello d'oro sull'occhio destro, catenella che pende
        return rect(rx - 1, ry - 1, 4, 1, C.G) + rect(rx - 1, ry + 2, 4, 1, C.G) + rect(rx - 1, ry, 1, 2, C.G) + rect(rx + 2, ry, 1, 2, C.G)
          + rect(rx + 2, ry + 3, 1, 1, C.G) + rect(rx + 3, ry + 4, 1, 2, C.G) + rect(rx + 2, ry + 6, 1, 1, C.G);
      case 'laurea': {   // tocco da laurea con nappa dorata
        const t = g.cima;
        return rect(cx - 4, t - 2, 8, 2, '#2c3352') + rect(cx - 7, t - 4, 14, 2, '#2c3352') + rect(cx - 6, t - 4, 12, 1, '#6370a8') + rect(cx - 7, t - 3, 14, 1, '#1d2238')
          + rect(cx - 1, t - 5, 2, 1, C.G) + rect(cx + 5, t - 3, 1, 3, C.G) + rect(cx + 4, t, 3, 1, C.G);
      }
      case 'cuffie': {   // archetto sopra la testa e padiglioni ai lati, all'altezza degli occhi
        const [a, b] = g.riga(ly), t = g.cima;
        const n = '#4a5272', l = '#7c86ad';
        return rect(a - 2, ly - 1, 3, 5, n) + rect(a - 1, ly, 1, 3, C.A) + rect(b, ly - 1, 3, 5, n) + rect(b + 1, ly, 1, 3, C.A)
          + rect(a - 1, t - 2, b - a + 3, 1, n) + rect(a, t - 2, b - a + 1, 1, l) + rect(a - 2, t - 1, 1, ly - t, n) + rect(b + 2, t - 1, 1, ly - t, n);
      }
      case 'sciarpa': {   // sciarpa blu C++ a righe bianche, con un capo che pende
        const y = g.collo, [a, b] = g.riga(y);
        let s = rect(a, y, b - a + 1, 2, '#00599c');
        for (let x = a + 2; x <= b - 1; x += 3) s += rect(x, y, 1, 2, '#ffffff');
        return s + rect(b - 4, y + 2, 3, 4, '#00599c') + rect(b - 4, y + 4, 3, 1, '#ffffff') + rect(b - 4, y + 6, 1, 1, '#00599c') + rect(b - 2, y + 6, 1, 1, '#00599c');
      }
      case 'baffetto': {   // baffi a manubrio, alla Oscar
        const [mx, my] = sp.bocca || [cx - 1, ly + 3];
        return rect(mx - 2, my - 1, 6, 1, C.K) + rect(mx - 3, my - 2, 1, 1, C.K) + rect(mx + 4, my - 2, 1, 1, C.K) + rect(mx, my - 2, 2, 1, C.K);
      }
    }
    return '';
  }

  /* svgPet(indice, umore, opz) -> stringa SVG animata dal CSS di bit.css
     opz: { colore, palette, lato, classe, accessori: {occhi, testa, collo, viso}, faccia, sguardo: 'su'|'giu'|'sx'|'dx',
            occhiali (reazione hype), mani: 'occhi'|'applauso' } */
  function svgPet(indice, umore, opz = {}) {
    if (umore === 'tranquillo') umore = 'neutro';
    const sp = SPRITE[Math.max(0, Math.min(SPRITE.length - 1, indice))];
    const C = coloriPalette(opz.palette, opz.colore);
    const acc = opz.accessori || {};
    const px = new Map();
    sp.righe.forEach((r, y) => { if (!r) return; const piena = r.padEnd(12, '.') + [...r.padEnd(12, '.')].reverse().join('');
      [...piena].forEach((c, x) => { if (c !== '.') px.set(x + ',' + y, c); }); });
    for (const [x, y, c] of sp.extra) px.set(x + ',' + y, c);
    const g = geometria(px, sp);
    // con un cappello o le cuffie, antenne e corone sopra la testa spariscono
    if (acc.testa) for (const k of [...px.keys()]) if (+k.split(',')[1] < g.cima) px.delete(k);
    const rect = (x, y, w, h, c) => `<rect x="${x}" y="${y}" width="${w}" height="${h}" fill="${C[c] || c}"/>`;
    let corpo = '';
    for (let y = 0; y < 24; y++) for (let x = 0; x < 24; x++) {
      const c = px.get(x + ',' + y); if (!c) continue;
      let w = 1; while (px.get((x + w) + ',' + y) === c) w++;
      corpo += rect(x, y, w, 1, c); x += w - 1;
    }
    // --- viso: l'espressione scelta nell'armadio vale negli umori tranquilli (neutro e felice)
    const faccia = (umore === 'neutro' || umore === 'felice') && opz.faccia && opz.faccia !== 'normale' ? opz.faccia : null;
    const scuro = sp.visiera ? C.A : C.P;
    const chiusi = umore === 'dorme' || umore === 'sbadiglio';
    const arco = umore === 'felice' || umore === 'euforico' || umore === 'mangia' || faccia === 'gioia';
    const [dx, dy] = { su: [0, -1], giu: [0, 1], sx: [-1, 0], dx: [1, 0] }[opz.sguardo] || [0, 0];
    let occhi = '', aperti = false;
    sp.occhi.forEach(([x, y], i) => {
      const sx = i === 0 ? x - 1 : x;   // gli occhi larghi 3 si allargano verso l'esterno
      if (umore === 'errore') occhi += rect(sx, y - 1, 1, 1, '#ff3b5c') + rect(sx + 2, y - 1, 1, 1, '#ff3b5c') + rect(sx + 1, y, 1, 1, '#ff3b5c')
        + rect(sx, y + 1, 1, 1, '#ff3b5c') + rect(sx + 2, y + 1, 1, 1, '#ff3b5c');
      else if (chiusi) occhi += rect(sx, y + 1, 3, 1, scuro);
      else if (faccia === 'stelle') occhi += rect(sx + 1, y - 1, 1, 3, C.G) + rect(sx, y, 3, 1, C.G);
      else if (faccia === 'sornione') occhi += rect(sx, y, 3, 1, scuro) + rect(sx + 2, y + 1, 1, 1, scuro) + rect(sx + 1 + (i ? 1 : 0), y + 1, 1, 1, scuro);
      else if (faccia === 'giudice') occhi += rect(sx, y - 1, 3, 1, scuro) + rect(sx + (i ? 2 : 0), y - 2, 1, 1, scuro) + rect(sx + 1, y + 1, 1, 1, scuro);
      else if (arco) occhi += rect(sx, y + 1, 1, 1, scuro) + rect(sx + 1, y, 1, 1, scuro) + rect(sx + 2, y + 1, 1, 1, scuro);
      else if (umore === 'triste') occhi += rect(x, y + 1, 2, 1, scuro) + rect(x + (i ? 1 : 0), y, 1, 1, scuro) + rect(x + (i ? -1 : 2), y - 1, 1, 1, scuro)
        + (i === 0 ? rect(x, y + 2, 1, 2, '#6cc8ff') : '');
      else { aperti = true; occhi += rect(x + dx, y + dy, 2, 2, scuro) + rect(x + dx, y + dy, 1, 1, C.W); }
    });
    let bocca = '';
    if (sp.bocca) {
      const [x, y] = sp.bocca;
      if (umore === 'euforico') bocca = rect(x - 1, y, 4, 1, C.P) + rect(x, y + 1, 2, 1, C.R);
      else if (umore === 'felice' && !faccia) bocca = rect(x - 1, y, 1, 1, C.P) + rect(x, y + 1, 2, 1, C.P) + rect(x + 2, y, 1, 1, C.P);
      else if (umore === 'affamato') bocca = rect(x, y, 2, 2, C.P);
      else if (umore === 'dorme') bocca = rect(x - 1, y, 1, 1, C.P) + rect(x, y + 1, 1, 1, C.P) + rect(x + 1, y, 1, 1, C.P) + rect(x + 2, y + 1, 1, 1, C.P);
      else if (umore === 'errore') bocca = rect(x - 1, y + 1, 1, 1, C.P) + rect(x, y, 1, 1, C.P) + rect(x + 1, y + 1, 1, 1, C.P) + rect(x + 2, y, 1, 1, C.P);
      else if (umore === 'triste') bocca = rect(x - 1, y + 1, 1, 1, C.P) + rect(x, y, 2, 1, C.P) + rect(x + 2, y + 1, 1, 1, C.P);
      else if (umore === 'sbadiglio') bocca = rect(x - 1, y - 1, 4, 4, C.P) + rect(x, y + 1, 2, 1, C.R);
      else if (umore === 'mangia') bocca = rect(x - 1, y - 1, 4, 3, C.P) + rect(x, y, 2, 1, C.R);
      else if (faccia === 'stelle') bocca = rect(x - 1, y, 4, 1, C.P) + rect(x, y + 1, 2, 1, C.R);
      else bocca = rect(x, y, 2, 1, C.P);
    }
    const guance = sp.guance && (umore === 'felice' || umore === 'euforico' || umore === 'neutro' || umore === 'mangia')
      ? sp.guance.map(([x, y]) => rect(x, y, 2, 1, C.R)).join('') : '';
    // --- accessori dell'armadio (viso, collo, occhi, testa) e oggetti delle reazioni
    let vestiti = '';
    for (const slot of ['collo', 'viso', 'occhi', 'testa']) if (acc[slot] && !(slot === 'occhi' && (opz.occhiali || opz.mani === 'occhi')))
      vestiti += `<g class="pet-acc acc-${acc[slot]}">${accessorio(acc[slot], sp, g, C, rect)}</g>`;
    let reazione = '';
    if (opz.occhiali) reazione += `<g class="pet-occhiali">${accessorio('thug', sp, g, C, rect)}</g>`;
    if (opz.mani === 'occhi') reazione += `<g class="pet-mani-occhi">${sp.occhi.map(([x, y]) =>
      rect(x - 2, y - 2, 5, 5, C.O) + rect(x - 1, y - 1, 3, 3, C.L) + rect(x - 1, y - 2, 1, 1, C.L) + rect(x + 1, y - 2, 1, 1, C.L)).join('')}</g>`;
    if (opz.mani === 'applauso') {
      const y = Math.min(20, sp.pancia[1]);
      reazione += [['sx', 0], ['dx', 21]].map(([l, x]) => `<g class="pet-mano ${l}">${rect(x, y - 1, 3, 4, C.O)}${rect(x + (l === 'sx' ? 0 : 1), y, 2, 2, C.L)}</g>`).join('');
    }
    // --- decorazioni animate degli umori
    let extra = '';
    const [tx, ty] = sp.testa;
    if (umore === 'dorme') extra = [0, 1, 2].map(i => `<text class="pet-zzz" style="animation-delay:${i}s" x="${tx}" y="${ty + 4}" fill="${C.L}">z</text>`).join('');
    if (umore === 'affamato') { const [bx, by] = sp.pancia, o = '#ff9f1a';
      extra = `<g class="pet-grr">${rect(bx, by, 1, 1, o)}${rect(bx + 1, by - 1, 1, 1, o)}${rect(bx + 2, by, 1, 1, o)}${rect(bx, by + 2, 1, 1, o)}${rect(bx + 1, by + 1, 1, 1, o)}${rect(bx + 2, by + 2, 1, 1, o)}</g>`; }
    if (umore === 'euforico') extra = [[1, 4], [21, 6], [3, 18], [20, 19]].map(([x, y], i) =>
      `<g class="pet-scintilla" style="animation-delay:${i * .35}s">${rect(x, y - 1, 1, 3, C.G)}${rect(x - 1, y, 3, 1, C.G)}</g>`).join('');
    const alone = ALONE[umore] === 'B' || !ALONE[umore] ? C.B : ALONE[umore];
    const lato = opz.lato || 96;
    return `<svg class="pet-svg stadio-${indice} umore-${umore} ${opz.classe || ''}" viewBox="-3 -4 30 30" width="${lato}" height="${lato}"
      shape-rendering="crispEdges" style="--alone:${alone}" role="img" aria-label="${STADI[indice]?.nome || 'Bit'}, ${UMORI[umore] || umore}">
      <g class="pet-tutto"><g class="pet-corpo">${corpo}<g class="pet-guance">${guance}</g><g class="pet-bocca">${bocca}</g>
      <g class="pet-occhi ${aperti ? 'aperti' : ''}">${occhi}</g>${vestiti}${reazione}</g></g>${extra}</svg>`;
  }
  /* posizione della bocca in percentuale del riquadro (per le particelle di XP che vengono mangiate) */
  function puntoBocca(indice) {
    const sp = SPRITE[Math.max(0, Math.min(SPRITE.length - 1, indice))];
    const [x, y] = sp.bocca || [sp.occhi[0][0] + 3, sp.occhi[0][1] + 3];
    return [(x + 1 + 3) / 30, (y + .5 + 4) / 30];
  }

  /* ------------------------------------------------------------ Armadio: cosmetici sbloccati dai traguardi */
  const ACCESSORI = [
    { id: 'thug', slot: 'occhi', nome: 'Occhiali Thug Life', descr: 'Deal with it.', req: 'serie7' },
    { id: 'monocolo', slot: 'occhi', nome: 'Monocolo Senior Dev', descr: 'Per giudicare il codice altrui con eleganza.',
      cond: c => c.perfetti >= 50, testo: '50 domande del quiz giuste senza mai sbagliarle', prog: c => [Math.min(c.perfetti, 50), 50] },
    { id: 'laurea', slot: 'testa', nome: 'Cappello da laurea', descr: 'Il tocco a 8 bit di chi ha fatto 30 e lode.', req: 'lode' },
    { id: 'cuffie', slot: 'testa', nome: 'Cuffie lo-fi', descr: 'Beat rilassati per studiare.',
      cond: c => c.brani >= 3, testo: 'Ascolta 3 brani diversi nel lettore musicale', prog: c => [Math.min(c.brani, 3), 3] },
    { id: 'sciarpa', slot: 'collo', nome: 'Sciarpa C++', descr: 'Blu come il logo, calda come un for infinito.', req: 'lab' },
    { id: 'baffetto', slot: 'viso', nome: 'Baffetto alla Oscar', descr: 'Per commentare con teatralità.', req: 'oratore' },
  ];
  const FACCE = [
    { id: 'normale', nome: 'Normale', ascii: 'o_o', descr: 'Lo sguardo di sempre.' },
    { id: 'gioia', nome: 'Gioia', ascii: '^_^', descr: 'Sorride anche a un warning.', req: 'primo' },
    { id: 'sornione', nome: 'Sornione', ascii: '¬_¬', descr: 'Ha capito il trucco della domanda.', req: 'spazzino' },
    { id: 'giudice', nome: 'Giudice', ascii: 'ಠ_ಠ', descr: 'Disapprova i delete dimenticati.', req: 'perfetto' },
    { id: 'stelle', nome: 'Stelle', ascii: '*_*', descr: 'Occhi a stella per il codice elegante.', req: 'tris' },
  ];
  const SCELTE_VUOTE = { palette: 'app', faccia: 'normale', occhi: null, testa: null, collo: null, viso: null };
  function contesto(st, prog, imp) {
    let perfetti = 0;
    for (const s of Object.values(prog?.quiz || {})) if ((s.g || 0) >= 1 && !(s.s || 0)) perfetti++;
    return { st, perfetti, brani: (imp?.brani_ascoltati || []).length };
  }
  function valuta(voce, c) {
    if (voce.cond) return { ok: !!voce.cond(c), req: voce.testo, prog: voce.prog?.(c) || null };
    if (!voce.req) return { ok: true, req: '', prog: null };
    const t = (c.st?.traguardi || []).find(x => x.id === voce.req);
    return { ok: !!t?.ok, req: t ? `Traguardo «${t.nome}»: ${t.descr.replace(/\.$/, '')}` : 'Traguardo', prog: t?.prog || null };
  }
  /* catalogo completo con lo stato di ogni voce */
  function armadio(st, prog, imp) {
    const c = contesto(st, prog, imp);
    const voci = (lista, tipo) => lista.map(v => ({ ...v, tipo, ...valuta(v, c) }));
    const tutto = { palette: voci(PALETTE, 'palette'), accessori: voci(ACCESSORI, 'accessori'), facce: voci(FACCE, 'facce') };
    tutto.scelte = scelteValide(imp?.armadio, tutto);
    tutto.sbloccati = [...tutto.palette, ...tutto.accessori, ...tutto.facce].filter(v => v.ok && (v.req || v.cond)).map(v => v.id);
    tutto.totale = [...tutto.palette, ...tutto.accessori, ...tutto.facce].filter(v => v.req || v.cond).length;
    return tutto;
  }
  /* le scelte salvate, tenendo solo ciò che è davvero sbloccato */
  function scelteValide(salvate, tutto) {
    const s = { ...SCELTE_VUOTE, ...(salvate || {}) }, ok = (l, id) => l.some(v => v.id === id && v.ok);
    if (!ok(tutto.palette, s.palette)) s.palette = 'app';
    if (!ok(tutto.facce, s.faccia)) s.faccia = 'normale';
    for (const slot of ['occhi', 'testa', 'collo', 'viso']) if (s[slot] && !tutto.accessori.some(v => v.id === s[slot] && v.slot === slot && v.ok)) s[slot] = null;
    return s;
  }
  /* opzioni per svgPet con quello che Bit indossa (da unire a { colore }) */
  function vestito(st, prog, imp) {
    const s = armadio(st, prog, imp).scelte;
    return { palette: s.palette, faccia: s.faccia, accessori: { occhi: s.occhi, testa: s.testa, collo: s.collo, viso: s.viso } };
  }

  /* ------------------------------------------------------------ la finestra dell'Armadio */
  const ICONE = {   // icone 8×8 in pixel art
    orologio: ['..####..', '.#....#.', '#...#..#', '#...#..#', '#...###.', '#......#', '.#....#.', '..####..'],
    stomaco: ['........', '.##..##.', '#..##..#', '#......#', '.#.##.#.', '..#..#..', '...##...', '........'],
    lucchetto: ['..####..', '.#....#.', '.#....#.', '########', '###..###', '###..###', '########', '########'],
    stampella: ['...##...', '..#..#..', '.....#..', '....#...', '...#....', '.######.', '#......#', '########'],
  };
  function iconaPixel(nome, lato = 16, classe = 'cmp-icona') {
    const r = ICONE[nome]; if (!r) return '';
    let s = '';
    r.forEach((riga, y) => [...riga].forEach((c, x) => { if (c === '#') s += `<rect x="${x}" y="${y}" width="1" height="1"/>`; }));
    return `<svg class="${classe}" viewBox="0 0 8 8" width="${lato}" height="${lato}" shape-rendering="crispEdges" fill="currentColor" aria-hidden="true">${s}</svg>`;
  }
  const escHTML = s => String(s ?? '').replace(/[&<>"]/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));

  /* apriArmadio({ stato, prog, imp, nome, colore, salva(scelte), chiuso() }) */
  function apriArmadio(o) {
    document.querySelector('.armadio-velo')?.remove();
    const st = o.stato, indice = indiceStadio(st.livello);
    let scheda = 'palette', scelte = armadio(st, o.prog, o.imp).scelte;
    const velo = document.createElement('div');
    velo.className = 'armadio-velo';
    velo.setAttribute('role', 'dialog'); velo.setAttribute('aria-modal', 'true'); velo.setAttribute('aria-label', `Armadio di ${o.nome}`);
    document.body.appendChild(velo);
    const svg = (sc, lato, umore = 'neutro', classe = '') => svgPet(indice, umore, { colore: o.colore, palette: sc.palette, faccia: sc.faccia,
      accessori: { occhi: sc.occhi, testa: sc.testa, collo: sc.collo, viso: sc.viso }, lato, classe });
    const indossa = (sc, v) => {
      const n = { ...sc };
      if (v.tipo === 'palette') n.palette = v.id;
      else if (v.tipo === 'facce') n.faccia = v.id;
      else n[v.slot] = sc[v.slot] === v.id ? null : v.id;
      return n;
    };
    const indossato = (sc, v) => v.tipo === 'palette' ? sc.palette === v.id : v.tipo === 'facce' ? sc.faccia === v.id : sc[v.slot] === v.id;
    const disegna = () => {
      const t = armadio(st, o.prog, { ...o.imp, armadio: scelte });
      const voci = t[scheda];
      const addosso = [PALETTE.find(p => p.id === scelte.palette)?.nome, FACCE.find(f => f.id === scelte.faccia)?.ascii,
        ...['testa', 'occhi', 'viso', 'collo'].map(s => ACCESSORI.find(a => a.id === scelte[s])?.nome)].filter(Boolean);
      velo.innerHTML = `<div class="armadio">
        <header class="arm-testa">
          <div><div class="arm-sopra">${iconaPixel('stampella', 14, 'arm-ic')} Armadio</div><h2>L'armadio di ${escHTML(o.nome)}</h2></div>
          <span class="arm-conta">${t.sbloccati.length}/${t.totale} sbloccati</span>
          <button class="arm-chiudi" data-arm="chiudi" aria-label="Chiudi">×</button>
        </header>
        <div class="arm-corpo">
          <div class="arm-anteprima">
            <div class="arm-palco">${svg(scelte, 168)}</div>
            <div class="arm-addosso">${addosso.map(x => `<span>${escHTML(x)}</span>`).join('')}</div>
            <button class="arm-btn" data-arm="spoglia">Togli tutto</button>
          </div>
          <div class="arm-scaffali">
            <div class="arm-schede" role="tablist">${[['palette', 'Palette'], ['accessori', 'Accessori'], ['facce', 'Espressioni']].map(([k, n]) =>
              `<button role="tab" aria-selected="${k === scheda}" class="${k === scheda ? 'attiva' : ''}" data-arm="scheda" data-k="${k}">${n}</button>`).join('')}</div>
            ${scheda === 'facce' ? '<p class="arm-nota">L\'espressione si vede quando Bit è neutro o felice: nelle reazioni prevale la sua faccia del momento.</p>' : ''}
            <div class="arm-griglia">${voci.map(v => {
              const su = indossato(scelte, v);
              const prova = indossa({ ...SCELTE_VUOTE, palette: scelte.palette }, v);   // anteprima: solo questa voce
              return `<button class="arm-voce ${v.ok ? 'ok' : 'chiuso'} ${su ? 'su' : ''}" data-arm="voce" data-id="${v.id}" aria-pressed="${su}"
                ${v.ok ? '' : `aria-disabled="true"`} title="${escHTML(v.ok ? v.descr : v.req)}">
                <span class="arm-mini">${svg(prova, 64)}${v.ok ? '' : iconaPixel('lucchetto', 18, 'arm-lucchetto')}</span>
                <b>${escHTML(v.nome)}${v.ascii ? ` <code>${escHTML(v.ascii)}</code>` : ''}</b>
                <small>${v.ok ? (su ? (v.tipo === 'accessori' ? 'Indossato · tocca per togliere' : 'In uso') : escHTML(v.descr)) : escHTML(v.req)}</small>
                ${!v.ok && v.prog ? `<i class="arm-barra"><i style="width:${Math.round(100 * v.prog[0] / Math.max(1, v.prog[1]))}%"></i></i>` : ''}
              </button>`;
            }).join('')}</div>
          </div>
        </div>
      </div>`;
    };
    const chiudi = () => { velo.remove(); removeEventListener('keydown', tasto, true); o.chiuso?.(); };
    const tasto = ev => { if (ev.key === 'Escape') { ev.preventDefault(); ev.stopPropagation(); chiudi(); } };
    addEventListener('keydown', tasto, true);
    velo.addEventListener('click', ev => {
      if (ev.target === velo) return chiudi();
      const b = ev.target.closest('[data-arm]'); if (!b) return;
      const a = b.dataset.arm;
      if (a === 'chiudi') return chiudi();
      if (a === 'scheda') { scheda = b.dataset.k; return disegna(); }
      if (a === 'spoglia') { scelte = { ...SCELTE_VUOTE }; o.salva(scelte); return disegna(); }
      if (a === 'voce') {
        const v = armadio(st, o.prog, o.imp)[scheda].find(x => x.id === b.dataset.id);
        if (!v) return;
        if (!v.ok) { b.classList.remove('nego'); void b.offsetWidth; b.classList.add('nego'); return; }
        scelte = indossa(scelte, v); o.salva(scelte); disegna();
        velo.querySelector('.arm-palco .pet-svg')?.classList.add('salta');
      }
    });
    disegna();
    velo.querySelector('.arm-chiudi')?.focus();
  }

  /* ------------------------------------------------------------ battute */
  /* Due caratteri: «giovane» (Uovo, Bit, Byte, Kilobyte) e «senior» (Megabyte, Gigabyte).
     {n} = risposte giuste di fila, {m} = titolo del modulo. Frasi neutre: niente maschile/femminile. */
  const BATTUTE = {
    giovane: {
      giusta: ['Giusta! Gnam, che buon XP.', 'Sì! Mi è venuto il saltino.', 'Esatto! Mi crescono i bit.', 'Corretta! Un byte di felicità.',
        'Bel colpo! Un\'altra così e mi evolvo.', 'Vai così! Il mio heap si riempie.', 'return true; Che gioia!', 'Giusta! Questa me la segno.'],
      sbagliata: ['Ahia! Segmentation fault nel mio cuore.', 'Oh no... errore di logica rilevato!', 'Bzzt! Risposta corrotta. Leggi il commento e riproviamo.',
        'Ouch! Mi si è glitchato un pixel.', 'Ops! La spiegazione qui sotto è dove si impara davvero.', 'Errore! Ma tornerà presto: la prossima volta è nostra.'],
      combo: ['COMBO x{n}! Sono in modalità turbo!', '{n} di fila! Mi servono gli occhiali da sole.', 'x{n}! Stai compilando senza warning!', 'Inarrestabile: {n} giuste in fila!'],
      esitazione: ['Mmmh... *sbadiglio* tutto bene lì?', 'Tic tac... all\'esame hai due minuti a domanda.', 'Il mio stomaco brontola... una risposta?',
        'Non la sai? Scarta prima le opzioni impossibili.', 'Pensaci pure, io intanto conto: 0, 1, 10, 11...'],
      domanda: ['Leggi tutte e quattro le opzioni prima di scegliere!', 'Occhio ai «non» nel testo della domanda!', 'Ok, questa la guardiamo insieme.',
        'Se c\'è del codice, seguilo riga per riga.', 'Nuova domanda, nuovi XP in arrivo!', 'Prima pensa alla risposta, poi cercala tra le opzioni.',
        'Hmm, interessante... tu che dici?', 'Concentrazione: modalità debug attiva.'],
      compilaOk: ['Compila e gira! Zero warning: che profumo di codice pulito.', 'g++ non ha detto niente: è il complimento più grande!', 'Eseguito! Festeggio con un byte extra.'],
      compilaAvvisi: ['Compila, ma g++ ha dei warning: leggili, spesso sono bug veri.', 'Funziona... ma quei warning mi fanno il solletico.'],
      compilaErrore: ['Non guardo! Non compila...', 'Aiuto, errori rossi ovunque! Parti dal primo.', 'g++ si è arrabbiato. Correggi il primo errore e riprova.', 'Mi copro gli occhi: dimmi quando compila.'],
      crash: ['BOOM! Il programma è crollato. Puntatori sospetti?', 'Fumo! Qualcosa è esploso durante l\'esecuzione.', 'Crash! Controlla new, delete e gli indici degli array.'],
      diffOk: ['Output identico alla soluzione! Sono senza parole.', 'Perfetto, riga per riga! Questo è da laboratorio vero.'],
      diffNo: ['Uh... l\'output non coincide. Guarda le righe con il meno.', 'Quasi! Qualche riga diversa: confrontale con calma.'],
      oraleAlta: ['Clap clap! Spiegazione da 30.', 'Che esposizione! Il prof prenderebbe appunti.', 'Applausi a 8 bit! Chiara e precisa.'],
      oraleBassa: ['Nessun problema: un ripasso di «{m}» e la prossima volta va.', 'Si impara così: rileggi la teoria di «{m}» e riprova ad alta voce.',
        'Domanda segnata: tornerà presto. Intanto un occhio a «{m}».'],
      orale: ['Rispondi ad alta voce, io ascolto!', 'Definizione, esempio, disegno. Vai!', 'Prova a spiegarlo come a un amico.', 'Fai finta che io sia il prof. Sono tutto orecchi... cioè, tutto pixel.'],
      risposta: ['Allora? Confronta con la risposta modello.', 'Valutati con onestà: serve a te, non a me.', 'Hai detto le parole chiave?'],
      prevediOk: ['Hai letto il codice come un compilatore!', 'Output previsto! Hai la vista a raggi X.'],
      prevediNo: ['Mancato! Rileggi il programma riga per riga, come fa la CPU.', 'Non era quello: segui le variabili con carta e penna.'],
      simulazioneOk: ['PROMOSSI! Sopra il 18: l\'esame vero ci fa un baffo!', 'Simulazione superata! Sono euforico a 64 bit!'],
      simulazioneNo: ['Non ancora, ma ci siamo vicini. Ripassa le sbagliate e riprova.', 'Sotto soglia stavolta. Ogni simulazione ti avvicina al 18.'],
      missioni: ['Tre missioni su tre! Oggi sono felice e sazio.', 'Missioni completate! Pancia piena, cuore pieno.'],
      fame: ['Ho fame di XP... un quiz veloce?', 'Il mio stomaco fa grrr. Tre domande e sono sazio!', 'Ehi, ci sei? Ho un buco nello stack.', 'Tempo morto? Bastano 5 minuti di orale.'],
      dorme: ['Zzz... toccami per svegliarmi...', 'Zzz... sogno liste concatenate...'],
      sveglia: ['Eccoti! Ripartiamo?', 'Sveglio! Dove eravamo rimasti?'],
      entra: {
        quiz: ['Pronto? Leggi bene ogni domanda, io commento!', 'Quiz! Il mio piatto preferito.'],
        codice: ['Laboratorio! Io guardo l\'output di g++ da qui.', 'Scrivi, compila, e io tifo per te.'],
        orale: ['Interrogazione! Io faccio il prof.', 'Pronto ad ascoltarti.'],
      },
      clic: {
        tutti: ['Mi hai toccato! +0 XP, ma +100 affetto.', 'Hop! Il quiz si supera con 18 su 30.', 'Ogni new vuole il suo delete!'],
        quiz: ['Leggi tutte e quattro le opzioni prima di scegliere!', 'Occhio ai «non» nelle domande!'],
        codice: ['Compila spesso: un errore alla volta.', 'Disegna la lista su carta prima di scriverla.'],
        orale: ['Ad alta voce! Definizione, esempio, disegno.', 'Prova a spiegarlo come a un amico.'],
        oggi: ['Cosa facciamo oggi? Io voto quiz!', 'Le missioni di oggi mi fanno venire fame.'],
      },
    },
    senior: {
      giusta: ['Corretto. Me lo aspettavo, ovviamente.', 'Giusto. Elegante come un distruttore virtuale.', 'Sì. Annoto nel mio registro: competenza.',
        'Esatto. Si vede chi ha studiato la dispensa.'],
      rapida: ['Troppo facile. Quasi mi offendo a festeggiare.', 'Questa la sapeva anche l\'Uovo.', 'Domanda da Hello World. Passiamo oltre.', 'Banale. Ma giusta. Ma banale.'],
      sbagliata: ['NO. Questo è un dangling pointer della mente.', 'Errore. Sento un memory leak di concetti.', 'Inaccettabile. Hai dimenticato un delete e ora il mio cuore perde memoria.',
        'Doppia delete sulla mia pazienza. Rileggi il commento.', 'Hai appena dereferenziato nullptr. Davanti a me.', 'Comportamento indefinito. Il mio incubo preferito.'],
      combo: ['{n} di fila. Gli occhiali da sole non sono per il sole: sono per te.', 'COMBO x{n}. Talento in O(1).', '{n} perfette. Prendo appunti per il prof.'],
      esitazione: ['Sto invecchiando. Ho visto passare tre garbage collector.', '*sbadiglio teatrale* Il tempo, come la memoria, non è infinito.',
        'Nel frattempo ho ricompilato il kernel. Due volte.', 'All\'esame non avrai tutto questo tempo. Lo dico con affetto. Poco.'],
      domanda: ['Vediamo se questa è all\'altezza.', 'Leggi due volte. Le trappole stanno nei dettagli.', 'Una domanda degna di me, finalmente?',
        'Osservo. In silenzio. Giudicando.', 'Il testo nasconde un tranello. Lo sento nei bit.', 'Prossima vittima: questa domanda.'],
      compilaOk: ['Zero warning. Questo codice ha classe. E distruttore.', 'Compila al primo colpo. Mi commuovo.', 'Che eleganza. Nemmeno -Wextra ha trovato da ridire.'],
      compilaAvvisi: ['Compila, sì. Ma quei warning sono grida d\'aiuto.', 'Un warning ignorato oggi è un segfault domani.'],
      compilaErrore: ['Non posso guardare. Chiudo gli occhi finché non compila.', 'Errore di compilazione. Si corregge il PRIMO. Sempre il primo.', 'g++ ha parlato, e non era un complimento.'],
      crash: ['Segfault. Un puntatore pendente ha colpito ancora. Chi ha liberato quella memoria?!',
        'Crash. Scena del crimine: un delete dimenticato o un indice oltre la fine.', 'Fumo dai registri! Qualcuno ha scritto oltre la fine dell\'array.'],
      diffOk: ['Output identico. Riga per riga. Il laboratorio non ti merita.', 'Perfetto. Incornicio questo output.'],
      diffNo: ['L\'output diverge. Come certe scelte sui puntatori.', 'Righe diverse. Confronta, con umiltà.'],
      oraleAlta: ['Esposizione impeccabile. Applaudo, e io non applaudo mai.', 'Precisione chirurgica. Il prof annuirebbe in silenzio.', 'Da 30 e lode. Lo metto agli atti.'],
      oraleBassa: ['Non disperiamo. Riapri «{m}»: la teoria non morde. Io sì.', 'Il modulo «{m}» ti chiama. Rispondigli prima dell\'esame.'],
      orale: ['Prego, la ascolto. Sono la commissione.', 'Definizione, esempio, disegno. Recitalo come Shakespeare.', 'Parli pure. Ho tutta la RAM del mondo.'],
      risposta: ['Ora confronti. Con onestà intellettuale, mi raccomando.', 'Le parole chiave c\'erano tutte? Non mentire al Gigabyte.'],
      prevediOk: ['Hai eseguito il codice a mente. Rispetto.', 'Output previsto. Sei tu il compilatore, adesso.'],
      prevediNo: ['Previsione errata. La CPU non improvvisa: segui ogni riga.', 'No. Traccia le variabili come un detective, non come un poeta.'],
      simulazioneOk: ['Superata. Applausi, coriandoli, e un filo di commozione.', 'Diciotto e oltre. La commissione approva. Io anche.'],
      simulazioneNo: ['Sotto soglia. Una tragedia in tre atti, ma il quarto lo scrivi tu.', 'Non basta. Ripassa le sbagliate: sono loro le vere maestre.'],
      missioni: ['Tre missioni su tre. La disciplina è elegante.', 'Missioni completate. Concedo un sorriso.'],
      fame: ['Un Gigabyte a digiuno è uno spettacolo triste.', 'Inattività rilevata. Il mio heap reclama XP.', 'Sto per lanciare un\'eccezione: std::fame.'],
      dorme: ['Zzz... sogno codice senza memory leak...', 'Zzz... delete[] noia;'],
      sveglia: ['Oh, ci sei. Fingerò di non aver dormito.', 'Ripristino dal sonno completato.'],
      entra: {
        quiz: ['Quiz. Vediamo di non deludermi.', 'Si va in scena. Io commento, tu rispondi.'],
        codice: ['Laboratorio. Osservo l\'output di g++ con lo sguardo di un critico.', 'Scriva pure. Io giudico da qui.'],
        orale: ['La commissione è riunita. Cioè io.', 'Prego, si accomodi. L\'interrogazione ha inizio.'],
      },
      clic: {
        tutti: ['Non disturbare il genio mentre medita.', 'Sì? Una domanda sui puntatori, spero.', 'Regola dei tre. Sempre. Non farmelo ripetere.'],
        quiz: ['Leggi il testo due volte. Le trappole stanno nei dettagli.'],
        codice: ['Ogni new senza delete è una piccola tragedia greca.', 'Distruttore virtuale nella classe base. Non dimenticarlo. Mai.'],
        orale: ['All\'orale: definizione, esempio, disegno. Recitalo come Shakespeare.'],
        oggi: ['Il piano di oggi ti attende. Io pure.'],
      },
    },
  };
  /* reazione -> animazione, espressione, oggetti, particelle, icona del fumetto, durata (ms), umore che resta dopo */
  const REAZIONI = {
    giusta: { anim: 'eat-xp', umore: 'mangia', part: 'xp-in', durata: 1500, dopo: 'ok' },
    rapida: { anim: 'eat-xp', umore: 'mangia', part: 'xp-in', durata: 1300, dopo: 'ok' },
    sbagliata: { anim: 'glitch-error', umore: 'triste', durata: 1600, suono: 'errore', dopo: 'triste' },
    combo: { anim: 'victory-hype', umore: 'euforico', occhiali: true, part: 'coriandoli', durata: 2800, suono: 'combo', dopo: 'euforico' },
    esitazione: { anim: 'sbadiglio', umore: 'sbadiglio', durata: 2600 },
    compilaOk: { anim: 'salto', umore: 'felice', part: 'xp', durata: 1800, dopo: 'ok' },
    compilaAvvisi: { anim: 'annuisce', umore: 'neutro', durata: 1600 },
    compilaErrore: { anim: 'trema', umore: 'triste', mani: 'occhi', durata: 2200, suono: 'errore', dopo: 'triste' },
    crash: { anim: 'glitch-error', umore: 'errore', part: 'fumo', durata: 2400, suono: 'errore', dopo: 'triste' },
    diffOk: { anim: 'victory-hype', umore: 'euforico', occhiali: true, part: 'coriandoli', durata: 2800, suono: 'combo', dopo: 'euforico' },
    diffNo: { anim: 'trema', umore: 'triste', mani: 'occhi', durata: 2000, dopo: 'triste' },
    oraleAlta: { anim: 'salto', umore: 'euforico', mani: 'applauso', part: 'scintille', durata: 2200, dopo: 'ok' },
    oraleBassa: { anim: 'annuisce', umore: 'neutro', durata: 1800 },
    prevediOk: { anim: 'eat-xp', umore: 'mangia', part: 'xp-in', durata: 1400, dopo: 'ok' },
    prevediNo: { anim: 'glitch-error', umore: 'triste', durata: 1500, dopo: 'triste' },
    simulazioneOk: { anim: 'victory-hype', umore: 'euforico', occhiali: true, part: 'coriandoli', durata: 3400, suono: 'combo', dopo: 'euforico' },
    simulazioneNo: { anim: 'annuisce', umore: 'triste', durata: 2000, dopo: 'triste' },
    missioni: { anim: 'salto', umore: 'felice', part: 'scintille', durata: 2000 },
    fame: { anim: 'brontola', umore: 'affamato', icona: 'stomaco', durata: 2800 },
    dorme: { anim: '', umore: 'dorme', durata: 0 },
    sveglia: { anim: 'salto', umore: 'felice', durata: 1200 },
    clic: { anim: 'salto', umore: 'felice', durata: 900 },
  };

  /* ------------------------------------------------------------ Bit in scena */
  /* new Compagno({ stato, vestito, contesto, attivo, visibile, lato, classe, suono, osserva })
       stato()    -> Gioco.pet(...)      vestito() -> { colore, palette, faccia, accessori }
       contesto() -> 'quiz' | 'codice' | 'orale' | 'oggi' | 'bit'
     Bit NON si trascina: si ancora da solo al primo elemento .bit-posto visibile
     (data-posto = nome, data-layout = riga | riga-inv | colonna, data-lato = px, data-sguardo = su | giu | sx | dx).
     Se non ce n'è, sta nella postazione base in basso a destra. */
  class Compagno {
    constructor(o) {
      this.o = o; this.serie = 0; this.dorme = false; this.affamato = false; this.temp = null; this.evento = null;
      this.ultima = Date.now(); this.qChiave = null; this.qInizio = 0; this.posto = null; this.chiavePosto = null; this.entrato = 0;
      const el = this.el = document.createElement('div');
      el.className = 'compagno base ' + (o.classe || '');
      el.innerHTML = `<div class="cmp-fumetto" hidden><span class="cmp-icona-box"></span><span class="cmp-testo"></span></div>
        <button class="cmp-pet" type="button"><span class="cmp-aura"></span><span class="cmp-corpo"><span class="cmp-voce"></span></span><span class="cmp-effetti" aria-hidden="true"></span></button>`;
      document.body.appendChild(el);
      this.fumetto = el.querySelector('.cmp-fumetto'); this.testo = el.querySelector('.cmp-testo');
      this.voce = el.querySelector('.cmp-voce'); this.effetti = el.querySelector('.cmp-effetti');
      el.querySelector('.cmp-pet').addEventListener('click', () => this.reagisci('clic'));
      this.fumetto.onclick = () => { if (!this.ancorato) this.zitto(); };
      const sveglio = () => this.attivita();
      for (const t of ['pointerdown', 'keydown', 'wheel', 'touchstart']) document.addEventListener(t, sveglio, { capture: true, passive: true });
      let mm = 0;
      document.addEventListener('mousemove', () => { const t = Date.now(); if (t - mm > 1500) { mm = t; this.attivita(); } }, { passive: true });
      setInterval(() => this.controllaInattivita(), 5000);
      // le viste si ridisegnano spesso: a ogni cambio del DOM Bit ritrova il suo posto
      new MutationObserver(() => this.programma()).observe(o.osserva || document.body, { childList: true, subtree: true });
      this.aggiorna();
    }
    get pet() { return this.o.stato(); }
    get carattere() { return this.pet.indice >= 4 ? 'senior' : 'giovane'; }
    get ancorato() { return !!this.posto; }
    attivo() { return !this.o.attivo || this.o.attivo(); }
    programma() { if (this._raf) return; this._raf = requestAnimationFrame(() => { this._raf = 0; this.aggiorna(); }); }

    /* trova il posto, decide se mostrarsi, ridisegna */
    aggiorna() {
      const vis = this.attivo() && (!this.o.visibile || this.o.visibile());
      document.body.classList.toggle('senza-bit', !this.attivo());
      if (!vis) { this.el.hidden = true; return; }
      this.el.hidden = false;
      const posto = [...document.querySelectorAll('.bit-posto')].find(p => p.getClientRects().length) || null;
      if (posto) { if (this.el.parentNode !== posto) posto.appendChild(this.el); }
      else if (this.el.parentNode !== document.body) document.body.appendChild(this.el);
      this.posto = posto;
      this.el.classList.toggle('ancorato', !!posto); this.el.classList.toggle('base', !posto);
      const chiave = posto ? posto.dataset.posto : 'base';
      if (chiave !== this.chiavePosto) {
        this.chiavePosto = chiave; this.entrato = Date.now();
        if (!posto) this.zitto();
        else { const l = BATTUTE[this.carattere].entra[chiave]; if (l && Date.now() - (this.ultimaFrase || 0) > 1200) this.dice(scegli(l)); }
      }
      this.disegna();
    }
    disegna() {
      const p = this.pet, t = this.temp || {};
      const evento = this.evento && this.evento.fino > Date.now() ? this.evento.umore : null;
      const umore = this.dorme ? 'dorme' : t.umore || evento || (this.affamato ? 'affamato' : p.umore);
      const lato = +(this.posto?.dataset.lato) || this.o.lato || 76;
      const legge = !!this.posto?.dataset.sguardo && !this.temp && !this.dorme && (this.chiavePosto !== 'quiz' || this.qChiave != null);
      this.el.classList.toggle('legge', legge);
      const html = svgPet(p.indice, umore, { ...(this.o.vestito?.() || {}), lato, occhiali: t.occhiali, mani: t.mani, sguardo: legge ? this.posto.dataset.sguardo : null });
      if (html !== this.html) { this.html = html; this.voce.innerHTML = html; }   // niente ridisegni inutili: ripartirebbero le animazioni
      this.el.querySelector('.cmp-pet').setAttribute('aria-label', `${p.nome}, ${UMORI[umore] || umore}: toccalo per una frase`);
      this.el.classList.toggle('riposo', umore === 'dorme');
      this.el.dataset.umore = umore;
    }
    cambiaVista() { this.domanda(null); this.aggiorna(); }
    azzeraSerie() { this.serie = 0; if (this.evento?.umore === 'euforico') this.evento = null; }

    /* il quiz mostra una domanda nuova: Bit la commenta e parte il conto per l'esitazione (null = nessuna domanda aperta) */
    domanda(chiave, ms = 15000) {
      if (chiave === this.qChiave) return;
      clearTimeout(this.tEsita);
      this.qChiave = chiave; this.qInizio = Date.now();
      if (chiave == null) return this.disegna();
      this.tEsita = setTimeout(() => { if (this.qChiave === chiave) this.reagisci('esitazione'); }, ms);
      this.aggiorna();
      if (this.ancorato && Date.now() - this.entrato > 900 && Date.now() - (this.ultimaFrase || 0) > 1200) this.parla('domanda');
    }
    /* dice una frase del suo repertorio, senza reazione */
    parla(chiave, dati = {}) {
      if (!this.attivo() || this.el.hidden || Date.now() - (this.ultimaFrase || 0) < 900) return;   // non coprire una frase appena detta
      const l = BATTUTE[this.carattere][chiave] || BATTUTE.giovane[chiave];
      if (l) this.dice(scegli(l).replace('{m}', dati.m || 'questo modulo'));
    }

    reagisci(tipo, dati = {}) {
      if (!this.attivo()) return;
      if (tipo === 'giusta' || tipo === 'prevediOk') {
        this.serie++;
        if (tipo === 'giusta' && this.serie >= 5 && this.serie % 5 === 0) { tipo = 'combo'; dati.n = this.serie; }
        else if (tipo === 'giusta' && this.carattere === 'senior' && Date.now() - this.qInizio < 5000) tipo = 'rapida';
      } else if (tipo === 'sbagliata' || tipo === 'prevediNo') this.serie = 0;
      if (['giusta', 'sbagliata', 'rapida', 'combo'].includes(tipo)) { clearTimeout(this.tEsita); this.qChiave = null; }
      if (tipo !== 'dorme' && tipo !== 'fame') { this.dorme = false; this.affamato = false; }
      const r = REAZIONI[tipo] || REAZIONI.clic;
      // l'umore che resta dopo la reazione: triste dopo un errore, euforico dopo una vittoria (finché dura la serie)
      if (r.dopo === 'triste') this.evento = { umore: 'triste', fino: Date.now() + 45000 };
      else if (r.dopo === 'euforico') this.evento = { umore: 'euforico', fino: Date.now() + 90000 };
      else if (r.dopo === 'ok' && this.evento?.umore === 'triste') this.evento = null;
      const banca = BATTUTE[this.carattere], frasi = tipo === 'clic'
        ? [...banca.clic.tutti, ...(banca.clic[this.o.contesto?.()] || []), ...CONSIGLI]
        : banca[tipo] || BATTUTE.giovane[tipo] || banca.giusta;
      const frase = scegli(frasi).replace('{n}', dati.n ?? this.serie).replace('{m}', dati.m || 'questo modulo');
      clearTimeout(this.tFine);
      this.temp = tipo === 'dorme' ? null : { umore: r.umore, occhiali: r.occhiali, mani: r.mani };
      if (tipo === 'dorme') this.dorme = true;
      if (tipo === 'fame') this.affamato = true;
      this.aggiorna();
      if (this.el.hidden) return;
      this.anima(r.anim, r.durata);
      if (r.part) this.particelle(r.part);
      if (r.suono) this.o.suono?.(r.suono);
      this.dice(frase, r.icona || (tipo === 'esitazione' ? scegli(['orologio', 'stomaco']) : ''));
      if (r.durata) this.tFine = setTimeout(() => { this.temp = null; this.disegna(); }, r.durata);
    }

    anima(nome, durata) {
      const c = this.el;
      c.removeAttribute('data-anim'); void c.offsetWidth;
      if (!nome) return;
      c.dataset.anim = nome;
      clearTimeout(this.tAnim);
      this.tAnim = setTimeout(() => c.removeAttribute('data-anim'), Math.max(800, durata));
    }

    particelle(tipo) {
      const n = { fumo: 9, scintille: 10, coriandoli: 22, 'xp-in': 10 }[tipo] || 12;
      const [bx, by] = puntoBocca(this.pet.indice);
      const colori = ['#ffd447', '#ff4fd8', '#00e5ff', '#33ff99', '#ff7a45', '#ffffff'];
      for (let i = 0; i < n; i++) {
        const p = document.createElement('i');
        p.className = 'cmp-p ' + tipo;
        let ang = (i / n) * Math.PI * 2 + Math.random() * .5, dist = 34 + Math.random() * 26;
        if (tipo === 'fumo') { ang = -Math.PI / 2 + (Math.random() - .5) * 1.1; dist = 40 + Math.random() * 26; }
        if (tipo === 'coriandoli') { ang = -Math.PI / 2 + (Math.random() - .5) * 2.4; dist = 50 + Math.random() * 50;
          p.style.background = scegli(colori); p.style.setProperty('--cade', 40 + Math.random() * 60 + 'px'); p.style.setProperty('--giro', (Math.random() * 720 - 360) + 'deg'); }
        if (tipo === 'xp-in') { p.style.left = bx * 100 + '%'; p.style.top = by * 100 + '%'; dist = 46 + Math.random() * 30; }
        p.style.setProperty('--dx', Math.cos(ang) * dist + 'px');
        p.style.setProperty('--dy', Math.sin(ang) * dist - (tipo === 'fumo' ? 10 : 0) + 'px');
        p.style.animationDelay = (tipo === 'fumo' ? i * 90 : tipo === 'xp-in' ? i * 45 : Math.random() * 120) + 'ms';
        if ((tipo === 'xp' || tipo === 'xp-in') && i % 4 === 0) { p.textContent = '+XP'; p.classList.add('scritta'); }
        this.effetti.appendChild(p);
        setTimeout(() => p.remove(), 2000 + i * 90);
      }
    }

    /* fumetto con effetto macchina da scrivere; Bit molleggia e muove la bocca mentre «parla».
       Ancorato il fumetto resta (commenta in continuazione); nella postazione base sparisce dopo qualche secondo. */
    dice(frase, icona) {
      clearInterval(this.tScrivi); clearTimeout(this.tZitto);
      this.ultimaFrase = Date.now(); this.fraseIntera = frase;
      const f = this.fumetto, el = this.el;
      f.querySelector('.cmp-icona-box').innerHTML = icona ? iconaPixel(icona) : '';
      f.hidden = false; f.classList.remove('via'); f.classList.add('scrive'); el.classList.add('parla');
      this.testo.textContent = '';
      let i = 0;
      this.tScrivi = setInterval(() => {
        i += frase[i] === ' ' ? 2 : 1;
        this.testo.textContent = frase.slice(0, i);
        el.classList.toggle('bocca', i < frase.length && (i >> 1) % 2 === 0);
        if (i >= frase.length) { clearInterval(this.tScrivi); f.classList.remove('scrive'); el.classList.remove('parla', 'bocca'); }
      }, 30);
      if (!this.ancorato) this.tZitto = setTimeout(() => this.zitto(), Math.max(3600, frase.length * 30 + 2600));
    }
    zitto() {
      clearInterval(this.tScrivi); clearTimeout(this.tZitto);
      this.el.classList.remove('parla', 'bocca');
      const f = this.fumetto; if (f.hidden) return;
      f.classList.add('via');
      setTimeout(() => { if (f.classList.contains('via')) { f.hidden = true; f.classList.remove('via'); } }, 220);
    }

    /* tempi morti: dopo 2 minuti fermi ha fame, dopo 6 si addormenta; il primo gesto lo sveglia */
    attivita() {
      this.ultima = Date.now();
      if (this.dorme && this.attivo()) { this.dorme = false; this.affamato = false; this.reagisci('sveglia'); }
      else if (this.affamato) { this.affamato = false; this.disegna(); }
    }
    controllaInattivita() {
      if (!this.attivo() || document.hidden) return;
      const fermo = Date.now() - this.ultima;
      if (!this.dorme && fermo > 360000) this.reagisci('dorme');
      else if (!this.dorme && !this.affamato && fermo > 120000) this.reagisci('fame');
    }
  }

  Object.assign(G, {
    STADI, UMORI, CONSIGLI, BATTUTE, pet, umoreBase, svgPet, puntoBocca, Compagno,
    PALETTE, ACCESSORI, FACCE, armadio, vestito, apriArmadio, iconaPixel,
  });
})();
