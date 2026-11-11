/* =====================================================================
   Allenatore Prog2 — gioco: XP, livelli, serie di giorni, missioni,
   traguardi, il compagno «Bit» e il colore d'accento.
   ---------------------------------------------------------------------
   Condiviso tra l'app per PC e la versione per telefono.
   Tutti i punti sono CALCOLATI dai progressi (quiz, orale, esercizi...),
   mai salvati a parte: così PC e telefono, dopo la sincronizzazione,
   mostrano sempre gli stessi numeri.
   L'unica cosa nuova nei progressi è prog.attivita = { 'AAAA-MM-GG':
   { q: risposte, g: giuste, o: orale, e: esercizi, p: output, s: simulazioni } }
   ===================================================================== */
(function () {
  'use strict';

  const oggiISO = (d = new Date()) => `${d.getFullYear()}-${String(d.getMonth() + 1).padStart(2, '0')}-${String(d.getDate()).padStart(2, '0')}`;
  const giornoPrima = iso => { const d = new Date(iso + 'T12:00:00'); d.setDate(d.getDate() - 1); return oggiISO(d); };
  const hash = s => { let h = 2166136261; for (const c of s) { h ^= c.charCodeAt(0); h = Math.imul(h, 16777619); } return h >>> 0; };

  /* ------------------------------------------------------------ valori */
  const XP_ES = { es: 60, pattern: 50, lab: 200, esame: 400 };
  const XP_MISSIONE = 40, XP_TRIS = 60;

  /* livello L richiede 50·L·(L−1) XP: 0, 100, 300, 600, 1000, 1500, ... */
  const sogliaLivello = L => 50 * L * (L - 1);
  function livelloDa(xp) { let L = 1; while (xp >= sogliaLivello(L + 1)) L++; return L; }

  const TITOLI = [
    [1, 'Hello World'], [3, 'Apprendista del puntatore'], [5, 'Cacciatore di segfault'],
    [8, 'Domatore dell\'heap'], [11, 'Cavaliere dei template'], [14, 'Architetto delle classi'],
    [17, 'Maestro della ricorsione'], [20, 'Custode degli alberi'], [23, 'Esploratore di grafi'],
    [26, 'Leggenda di Prog2'],
  ];
  const titolo = L => TITOLI.filter(t => L >= t[0]).at(-1)[1];

  /* ------------------------------------------------------------ attività del giorno */
  function registra(prog, tipo, n = 1) {
    const g = oggiISO();
    prog.attivita = prog.attivita || {};
    const a = prog.attivita[g] || (prog.attivita[g] = {});
    a[tipo] = (a[tipo] || 0) + n;
  }

  /* ------------------------------------------------------------ missioni del giorno */
  /* Tre missioni al giorno, uguali su PC e telefono (dipendono solo dalla data). */
  function missioni(data) {
    const h = hash('missioni' + data);
    const quiz = [
      { k: 'q', n: 10, t: 'Rispondi a 10 domande del quiz' },
      { k: 'q', n: 20, t: 'Rispondi a 20 domande del quiz' },
      { k: 'g', n: 12, t: 'Dai 12 risposte giuste al quiz' },
      { k: 's', n: 1, t: 'Fai una simulazione del quiz (30 domande)' },
    ][h % 4];
    const orale = [
      { k: 'o', n: 5, t: 'Ripassa 5 domande d\'orale ad alta voce' },
      { k: 'o', n: 8, t: 'Ripassa 8 domande d\'orale ad alta voce' },
    ][(h >>> 3) % 2];
    const codice = { k: 'ep', n: 1, t: 'Completa un esercizio al PC (o indovina 3 output sul telefono)' };
    return [quiz, orale, codice];
  }
  function valoreMissione(a, m) {
    if (m.k === 'ep') return Math.max(a.e || 0, Math.floor((a.p || 0) / 3));
    return a[m.k] || 0;
  }
  function esitoMissioni(a, data) {
    return missioni(data).map(m => ({ ...m, fatto: valoreMissione(a || {}, m) >= m.n, valore: Math.min(m.n, valoreMissione(a || {}, m)) }));
  }

  /* ------------------------------------------------------------ calcolo completo */
  function calcola(prog, cat, opz = {}) {
    prog = prog || {};
    const pq = prog.quiz || {}, po = prog.orale || {}, pe = prog.esercizi || {}, pp = prog.prevedi || {};
    const sims = prog.simulazioni || [], att = prog.attivita || {};
    const esPer = {}; for (const e of (cat?.esercizi || [])) esPer[e.id] = e;

    let xpQuiz = 0, giuste = 0, corretti = 0;
    for (const s of Object.values(pq)) {
      xpQuiz += Math.min(s.g || 0, 5) * 10 + Math.min(s.s || 0, 5) * 2;
      giuste += s.g || 0;
      if ((s.s || 0) > 0 && s.ultima) corretti++;
    }
    let xpOrale = 0;
    for (const s of Object.values(po)) xpOrale += (s.box || 0) * 15 + Math.min(s.n || 0, 10) * 3;
    let xpEs = 0;
    for (const [id, s] of Object.entries(pe)) {
      const tipo = esPer[id]?.tipo || 'es';
      xpEs += s.fatto ? XP_ES[tipo] || 60 : s.iniziato ? 10 : 0;
    }
    let xpPrev = 0, indovinati = 0;
    for (const s of Object.values(pp)) { xpPrev += s.ok ? 25 : Math.min(s.n || 0, 3) * 5; if (s.ok) indovinati++; }
    let xpSim = 0;
    for (const s of sims) xpSim += (s.giuste || 0) * 5 + (s.superato ? 150 : 0);

    // missioni: si ricalcolano per ogni giorno registrato
    let xpMis = 0, giorniTris = 0;
    for (const [data, a] of Object.entries(att)) {
      const es = esitoMissioni(a, data), fatte = es.filter(m => m.fatto).length;
      xpMis += fatte * XP_MISSIONE + (fatte === 3 ? XP_TRIS : 0);
      if (fatte === 3) giorniTris++;
    }
    const xp = xpQuiz + xpOrale + xpEs + xpPrev + xpSim + xpMis;
    const L = livelloDa(xp);

    // giorni di studio: quelli registrati + le date dei progressi (anche dei dati vecchi)
    const giorni = new Set(Object.keys(att).filter(d => Object.values(att[d] || {}).some(v => v > 0)));
    for (const gruppo of [pq, po, pe, pp]) for (const s of Object.values(gruppo)) if (s && s.data) giorni.add(s.data);
    for (const s of sims) if (s.data) giorni.add(s.data);
    const oggi = oggiISO();
    let serie = 0, d = giorni.has(oggi) ? oggi : giornoPrima(oggi);
    while (giorni.has(d)) { serie++; d = giornoPrima(d); }
    let serieMax = 0, corr = 0, prec = null;
    for (const x of [...giorni].sort()) { corr = prec && giornoPrima(x) === prec ? corr + 1 : 1; serieMax = Math.max(serieMax, corr); prec = x; }
    const ultimo = [...giorni].sort().at(-1) || null;
    const giorniFermo = ultimo ? Math.round((new Date(oggi + 'T12:00:00') - new Date(ultimo + 'T12:00:00')) / 86400000) : null;

    // XP di oggi (stima dalle attività del giorno, missioni comprese)
    const a = att[oggi] || {};
    const misOggi = esitoMissioni(a, oggi), fatteOggi = misOggi.filter(m => m.fatto).length;
    const xpOggi = (a.g || 0) * 10 + Math.max(0, (a.q || 0) - (a.g || 0)) * 2 + (a.o || 0) * 15 + (a.e || 0) * 60
      + (a.p || 0) * 15 + (a.s || 0) * 150 + fatteOggi * XP_MISSIONE + (fatteOggi === 3 ? XP_TRIS : 0);

    const stato = {
      xp, livello: L, titolo: titolo(L), base: sogliaLivello(L), prossimo: sogliaLivello(L + 1),
      dettaglio: { quiz: xpQuiz, orale: xpOrale, esercizi: xpEs, prevedi: xpPrev, simulazioni: xpSim, missioni: xpMis },
      serie, serieMax: Math.max(serieMax, serie), giorniStudio: giorni.size, giorniFermo, xpOggi,
      obiettivo: opz.obiettivo || 300, missioni: misOggi, giorniTris,
      giuste, corretti, indovinati,
    };
    stato.traguardi = traguardi(prog, cat, stato);
    return stato;
  }

  /* ------------------------------------------------------------ traguardi */
  function traguardi(prog, cat, st) {
    const pq = prog.quiz || {}, po = prog.orale || {}, pe = prog.esercizi || {};
    const sims = prog.simulazioni || [];
    const quiz = cat?.quiz || [], orale = cat?.orale || [], es = cat?.esercizi || [];
    const labs = es.filter(e => e.tipo === 'lab'), fattiEs = es.filter(e => e.tipo === 'es' && pe[e.id]?.fatto).length;
    const sicure = orale.filter(o => (po[o.id]?.box || 0) >= 3).length;
    const moduliQuiz = [...new Set(quiz.filter(q => q.modulo > 0).map(q => q.modulo))];
    const moduloPerfetto = moduliQuiz.some(m => { const qs = quiz.filter(q => q.modulo === m); return qs.length && qs.every(q => pq[q.id]?.ultima); });
    const migliore = sims.reduce((m, s) => Math.max(m, s.totale >= 30 ? s.giuste : 0), 0);
    const T = (id, icona, nome, descr, ok, prog = null) => ({ id, icona, nome, descr, ok: !!ok, prog });
    return [
      T('primo', '>_', 'Primo sangue', 'La prima risposta giusta al quiz.', st.giuste >= 1),
      T('cento', '100', 'Centurione', '100 risposte giuste al quiz.', st.giuste >= 100, [Math.min(st.giuste, 100), 100]),
      T('cinquecento', '500', 'Macchina da quiz', '500 risposte giuste al quiz.', st.giuste >= 500, [Math.min(st.giuste, 500), 500]),
      T('spazzino', 'GC', 'Garbage collector', 'Correggi 20 domande che avevi sbagliato.', st.corretti >= 20, [Math.min(st.corretti, 20), 20]),
      T('enciclopedia', '[*]', 'Enciclopedia', 'Rispondi almeno una volta a tutte le domande.', quiz.length && quiz.every(q => pq[q.id]), [quiz.filter(q => pq[q.id]).length, quiz.length]),
      T('perfetto', '100%', 'Modulo perfetto', 'Tutte le domande di un modulo giuste all\'ultimo tentativo.', moduloPerfetto),
      T('promosso', '18+', 'Promosso', 'Supera una simulazione del quiz.', sims.some(s => s.superato)),
      T('chirurgo', '27+', 'Precisione chirurgica', 'Almeno 27/30 in una simulazione.', migliore >= 27),
      T('lode', '30L', 'Trenta e lode', '30 su 30 in una simulazione.', migliore >= 30),
      T('hello', '{ }', 'Hello, World!', 'Il primo esercizio al PC completato.', fattiEs >= 1),
      T('dieci', 'x10', 'Mani calde', '10 esercizi al PC completati.', fattiEs >= 10, [Math.min(fattiEs, 10), 10]),
      T('cinquanta', 'x50', 'Mani d\'acciaio', '50 esercizi al PC completati.', fattiEs >= 50, [Math.min(fattiEs, 50), 50]),
      T('lab', 'LAB', 'Camice bianco', 'Il primo laboratorio a step completato.', labs.some(e => pe[e.id]?.fatto)),
      T('tuttilab', 'ALL', 'Full stack', 'Tutti i laboratori a step completati.', labs.length && labs.every(e => pe[e.id]?.fatto), [labs.filter(e => pe[e.id]?.fatto).length, labs.length]),
      T('esame', 'EXE', 'Prova generale', 'Il laboratorio della simulazione d\'esame completato.', pe['esame-lab']?.fatto),
      T('oratore', 'ORL', 'Oratore', '10 domande d\'orale sicure.', sicure >= 10, [Math.min(sicure, 10), 10]),
      T('professore', 'PRF', 'Cattedra', 'Tutte le domande d\'orale sicure.', orale.length && sicure >= orale.length, [sicure, orale.length]),
      T('oracolo', '???', 'Oracolo', 'Indovina l\'output di 10 programmi (telefono).', st.indovinati >= 10, [Math.min(st.indovinati, 10), 10]),
      T('tris', '3/3', 'Missione compiuta', 'Completa tutte e tre le missioni di un giorno.', st.giorniTris >= 1),
      T('serie3', 'S03', 'Costanza', '3 giorni di studio di fila.', st.serieMax >= 3, [Math.min(st.serieMax, 3), 3]),
      T('serie7', 'S07', 'Una settimana', '7 giorni di studio di fila.', st.serieMax >= 7, [Math.min(st.serieMax, 7), 7]),
      T('serie14', 'S14', 'Abitudine', '14 giorni di studio di fila.', st.serieMax >= 14, [Math.min(st.serieMax, 14), 14]),
      T('serie30', 'S30', 'Inarrestabile', '30 giorni di studio di fila.', st.serieMax >= 30, [Math.min(st.serieMax, 30), 30]),
      T('liv10', 'L10', 'Livello 10', 'Raggiungi il livello 10.', st.livello >= 10, [Math.min(st.livello, 10), 10]),
      T('liv20', 'L20', 'Livello 20', 'Raggiungi il livello 20.', st.livello >= 20, [Math.min(st.livello, 20), 20]),
    ];
  }

  /* ------------------------------------------------------------ Bit, il compagno */
  const STADI = [
    { da: 1, nome: 'Uovo', descr: 'Un uovo di silicio. Qualcosa si muove là dentro.' },
    { da: 3, nome: 'Bit', descr: 'Appena nato: sa solo 0 e 1, ma impara in fretta.' },
    { da: 7, nome: 'Byte', descr: 'Otto bit di entusiasmo. Ha scoperto i puntatori.' },
    { da: 13, nome: 'Kilobyte', descr: 'Cresce a vista d\'occhio. Sogna liste concatenate.' },
    { da: 20, nome: 'Megabyte', descr: 'Robusto e sveglio: bilancia alberi a occhi chiusi.' },
    { da: 26, nome: 'Gigabyte', descr: 'Forma finale. Ha visto ogni segfault e li ha perdonati.' },
  ];
  /* {E} = occhi (3 caratteri), {M} = bocca (1 carattere) */
  const ARTE = [
    ['     .-""-.     ', '    /  .   \\    ', '   |  .  ,  |   ', '   |   ,  . |   ', '    \\  .   /    ', "     '-..-'     "],
    ['                ', '     .-----.    ', '    (  {E}  )   ', '     \\  {M}  /    ', "      '---'     ", '      "   "     '],
    ['       |        ', '    .--+--.     ', '   |  {E}  |    ', '   |   {M}   |    ', '   [|-----|]    ', '     |   |      '],
    ['     \\   /      ', '   .-------.    ', '  /   {E}   \\   ', ' |     {M}     |  ', '  \\  -----  /   ', "   '--| |--'    "],
    ['    \\ \\ / /     ', '  .=========.   ', ' ||   {E}   ||  ', ' ||    {M}    ||  ', ' ||  [===]  ||  ', "  '==|   |=='   "],
    ['   _/\\_/\\_/\\_   ', '  |  * * *  |   ', ' .===========.  ', '||    {E}    || ', '||     {M}     || ', "'==[=======]==' "],
  ];
  const OCCHI = { felice: '^ ^', tranquillo: 'o o', affamato: 'o o', triste: '; ;', dorme: '- -', euforico: '* *', chiusi: '- -' };
  const BOCCA = { felice: 'v', tranquillo: '_', affamato: 'o', triste: 'n', dorme: '~', euforico: 'D' };

  const FRASI = {
    euforico: ['Obiettivo di oggi superato! Sono a 64 bit di felicità.', 'Che giornata! Il mio heap è pieno di XP.', 'Se continui così all\'esame compiliamo al primo colpo.'],
    felice: ['Bel lavoro oggi. Ancora un po\' e raggiungiamo l\'obiettivo.', 'Mi piace quando studi: mi crescono i byte.', 'Una domanda alla volta, un nodo alla volta.'],
    tranquillo: ['Ieri hai studiato, oggi ripartiamo?', 'Una missione veloce prima di cena?', 'Ho preparato tre missioni per oggi.'],
    affamato: ['Ho fame di XP... facciamo qualche quiz?', 'Sono due giorni che non mangio una risposta giusta.', 'Brontolio di stomaco: segmentation fault in arrivo.'],
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
    const i = STADI.reduce((k, s, j) => stato.livello >= s.da ? j : k, 0);
    let umore;
    if (stato.giorniFermo === null) umore = 'tranquillo';
    else if (stato.giorniFermo >= 4) umore = 'dorme';
    else if (stato.giorniFermo >= 2) umore = 'affamato';
    else if (stato.giorniFermo === 1) umore = 'tranquillo';
    else umore = stato.xpOggi >= stato.obiettivo ? 'euforico' : 'felice';
    const giorno = hash(oggiISO() + umore);
    const frase = Math.random() < .45 && umore !== 'dorme' ? CONSIGLI[Math.floor(Math.random() * CONSIGLI.length)]
      : FRASI[umore][giorno % FRASI[umore].length];
    const prossimo = STADI[i + 1];
    return {
      nome: (nome || 'Bit').trim() || 'Bit', stadio: STADI[i].nome, descr: STADI[i].descr, indice: i,
      umore, frase, prossimo: prossimo ? { nome: prossimo.nome, livello: prossimo.da } : null,
      sazieta: Math.min(1, stato.xpOggi / Math.max(1, stato.obiettivo)),
    };
  }
  function disegnaPet(indice, umore, occhiChiusi = false) {
    const e = occhiChiusi ? OCCHI.chiusi : OCCHI[umore] || OCCHI.tranquillo;
    const m = BOCCA[umore] || '_';
    return ARTE[indice].map(r => r.replace('{E}', e).replace('{M}', m)).join('\n');
  }
  const UMORI = { euforico: 'euforico', felice: 'contento', tranquillo: 'tranquillo', affamato: 'affamato', dorme: 'addormentato',
    errore: 'in panico', sbadiglio: 'annoiato' };

  /* ------------------------------------------------------------ unione dei progressi (PC <-> telefono) */
  /* per ogni voce vince la più recente; a parità si uniscono le informazioni */
  function unisci(a, b) {
    a = a || {}; b = b || {};
    const out = { ...a, ...b, simulazioni: [] };
    for (const k of ['quiz', 'orale', 'esercizi', 'prevedi']) {
      const x = a[k] || {}, y = b[k] || {}; out[k] = {};
      for (const id of new Set([...Object.keys(x), ...Object.keys(y)])) {
        const u = x[id], v = y[id];
        if (!u || !v) { out[k][id] = { ...(u || v) }; continue; }
        const du = u.data || '', dv = v.data || '';
        if (du !== dv) { out[k][id] = { ...(dv > du ? v : u) }; continue; }
        const r = { ...u, ...v };
        for (const c of ['g', 's', 'n', 'box']) if (c in u || c in v) r[c] = Math.max(u[c] || 0, v[c] || 0);
        for (const c of ['fatto', 'visto', 'iniziato']) if (c in u || c in v) r[c] = !!(u[c] || v[c]);
        out[k][id] = r;
      }
    }
    const viste = new Set();
    for (const s of [...(a.simulazioni || []), ...(b.simulazioni || [])]) {
      const ch = [s.data, s.giuste, s.totale].join('|');
      if (!viste.has(ch)) { viste.add(ch); out.simulazioni.push(s); }
    }
    out.simulazioni.sort((p, q) => (p.data || '') < (q.data || '') ? -1 : 1);
    // attività: per ogni giorno e tipo il valore più alto (non si sommano: sarebbero contate due volte)
    out.attivita = {};
    for (const src of [a.attivita || {}, b.attivita || {}]) {
      for (const [d, v] of Object.entries(src)) {
        const t = out.attivita[d] || (out.attivita[d] = {});
        for (const [k, n] of Object.entries(v || {})) t[k] = Math.max(t[k] || 0, n || 0);
      }
    }
    return out;
  }

  /* ------------------------------------------------------------ colore d'accento */
  const COLORI = [
    ['#33ff99', 'Fosforo'], ['#00e5ff', 'Ciano'], ['#ffb000', 'Ambra'], ['#ff4fd8', 'Magenta'],
    ['#ff4d6d', 'Rosso'], ['#b388ff', 'Viola'], ['#4d9fff', 'Blu'], ['#e6e6e6', 'Bianco'],
  ];
  function rgbDa(hex) {
    const h = String(hex || '').replace('#', '');
    const v = h.length === 3 ? h.split('').map(c => c + c).join('') : h.padEnd(6, '0').slice(0, 6);
    return [0, 2, 4].map(i => parseInt(v.slice(i, i + 2), 16) || 0);
  }
  function hslDa([r, g, b]) {
    r /= 255; g /= 255; b /= 255;
    const max = Math.max(r, g, b), min = Math.min(r, g, b), l = (max + min) / 2;
    if (max === min) return [0, 0, l * 100];
    const d = max - min, s = l > .5 ? d / (2 - max - min) : d / (max + min);
    let h = max === r ? (g - b) / d + (g < b ? 6 : 0) : max === g ? (b - r) / d + 2 : (r - g) / d + 4;
    return [h * 60, s * 100, l * 100];
  }
  const hsl = (h, s, l) => `hsl(${h.toFixed(1)} ${s.toFixed(1)}% ${l.toFixed(1)}%)`;
  /* variabili CSS del tema «Terminale» costruite da un solo colore */
  function paletta(hex) {
    const rgb = rgbDa(hex), [h, s0] = hslDa(rgb), s = Math.min(100, s0), k = s / 100;
    const rgbs = rgb.join(', ');
    const chiaro = rgb.map(c => Math.round(c + (255 - c) * .42));
    return {
      '--fosforo': hex, '--fosforo-rgb': rgbs, '--fosforo-chiaro': `rgb(${chiaro.join(', ')})`,
      '--accento': hex, '--accento-2': `rgb(${chiaro.join(', ')})`, '--accento-tenue': `rgba(${rgbs}, .14)`,
      '--testo': hsl(h, 100 * k, 89), '--testo-2': hsl(h, 39 * k, 55), '--testo-3': hsl(h, 39 * k, 30),
      '--superficie': hsl(h, 70 * k, 1.4), '--superficie-2': hsl(h, 70 * k, .8),
      '--linea': `rgba(${rgbs}, .16)`, '--linea-forte': `rgba(${rgbs}, .34)`,
      '--riempi': `rgba(${rgbs}, .045)`, '--riempi-2': `rgba(${rgbs}, .085)`,
      '--seg': `rgba(${rgbs}, .05)`, '--seg-attivo': `rgba(${rgbs}, .2)`, '--bordo-card': `rgba(${rgbs}, .2)`,
      '--riga-attiva': `rgba(${rgbs}, .06)`, '--selezione': `rgba(${rgbs}, .3)`, '--c-com': hsl(h, 41 * k, 38),
      '--bagliore': `0 0 8px rgba(${rgbs}, .45)`,
      '--ombra-alta': `0 0 0 1px rgba(${rgbs}, .3), 0 0 40px rgba(${rgbs}, .12)`,
    };
  }
  /* terminale = true: tutta la paletta; altrimenti solo l'accento (temi chiaro/scuro) */
  function applicaAccento(hex, terminale, radice = document.documentElement) {
    const p = paletta(hex || COLORI[0][0]);
    const tutte = Object.keys(paletta('#33ff99'));
    for (const k of tutte) radice.style.removeProperty(k);
    const usa = terminale ? Object.keys(p) : ['--accento-tenue', '--fosforo', '--fosforo-rgb'];
    for (const k of usa) radice.style.setProperty(k, p[k]);
    if (!terminale) {   // nei temi chiaro/scuro l'accento vale come colore dei pulsanti
      radice.style.setProperty('--accento', hex);
      radice.style.setProperty('--accento-2', hex);
    }
  }

  /* ------------------------------------------------------------ Bit in pixel art (SVG 24×24) */
  /* Ogni stadio è disegnato per metà (12 colonne) e specchiato; 'extra' aggiunge pixel asimmetrici.
     Lettere: O contorno, B corpo, L luce, D ombra, A accessorio (colore complementare),
     S secondo accessorio, G oro, K visiera scura, W bianco. Il viso è disegnato a parte (umore). */
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
  const ALONE = { euforico: '#ffd447', felice: 'B', tranquillo: 'B', affamato: '#ff9f1a', dorme: '#6c8cff', errore: '#ff3b5c', sbadiglio: 'B' };

  /* svgPet(indice, umore, { colore, lato, classe }) -> stringa SVG animata con il CSS di gioco.css */
  function svgPet(indice, umore, opz = {}) {
    const sp = SPRITE[Math.max(0, Math.min(SPRITE.length - 1, indice))], C = colori(opz.colore || '#33ff99');
    const px = new Map();
    sp.righe.forEach((r, y) => { if (!r) return; const piena = r.padEnd(12, '.') + [...r.padEnd(12, '.')].reverse().join('');
      [...piena].forEach((c, x) => { if (c !== '.') px.set(x + ',' + y, c); }); });
    for (const [x, y, c] of sp.extra) px.set(x + ',' + y, c);
    // rettangoli: pixel uguali e adiacenti sulla stessa riga diventano un solo rect
    const rect = (x, y, w, h, c) => `<rect x="${x}" y="${y}" width="${w}" height="${h}" fill="${C[c] || c}"/>`;
    let corpo = '';
    for (let y = 0; y < 24; y++) for (let x = 0; x < 24; x++) {
      const c = px.get(x + ',' + y); if (!c) continue;
      let w = 1; while (px.get((x + w) + ',' + y) === c) w++;
      corpo += rect(x, y, w, 1, c); x += w - 1;
    }
    // viso secondo l'umore
    const scuro = sp.visiera ? C.A : C.P, luce = sp.visiera ? C.W : C.W;
    let occhi = '', chiusi = umore === 'dorme' || umore === 'sbadiglio', felici = umore === 'felice' || umore === 'euforico';
    sp.occhi.forEach(([x, y], i) => {
      const sx = i === 0 ? x - 1 : x;   // l'arco «^» è largo 3: si allarga verso l'esterno
      if (umore === 'errore') occhi += rect(sx, y - 1, 1, 1, '#ff3b5c') + rect(sx + 2, y - 1, 1, 1, '#ff3b5c') + rect(sx + 1, y, 1, 1, '#ff3b5c')
        + rect(sx, y + 1, 1, 1, '#ff3b5c') + rect(sx + 2, y + 1, 1, 1, '#ff3b5c');
      else if (chiusi) occhi += rect(sx, y + 1, 3, 1, scuro);
      else if (felici) occhi += rect(sx, y + 1, 1, 1, scuro) + rect(sx + 1, y, 1, 1, scuro) + rect(sx + 2, y + 1, 1, 1, scuro);
      else occhi += rect(x, y, 2, 2, scuro) + rect(x, y, 1, 1, luce);
    });
    let bocca = '';
    if (sp.bocca) {
      const [x, y] = sp.bocca;
      if (umore === 'euforico') bocca = rect(x - 1, y, 4, 1, C.P) + rect(x, y + 1, 2, 1, C.R);
      else if (umore === 'felice') bocca = rect(x - 1, y, 1, 1, C.P) + rect(x, y + 1, 2, 1, C.P) + rect(x + 2, y, 1, 1, C.P);
      else if (umore === 'affamato') bocca = rect(x, y, 2, 2, C.P);
      else if (umore === 'dorme') bocca = rect(x - 1, y, 1, 1, C.P) + rect(x, y + 1, 1, 1, C.P) + rect(x + 1, y, 1, 1, C.P) + rect(x + 2, y + 1, 1, 1, C.P);
      else if (umore === 'errore') bocca = rect(x - 1, y + 1, 1, 1, C.P) + rect(x, y, 1, 1, C.P) + rect(x + 1, y + 1, 1, 1, C.P) + rect(x + 2, y, 1, 1, C.P);
      else if (umore === 'sbadiglio') bocca = rect(x - 1, y - 1, 4, 4, C.P) + rect(x, y + 1, 2, 1, C.R);
      else bocca = rect(x, y, 2, 1, C.P);
    }
    const guance = sp.guance && (felici || umore === 'tranquillo')
      ? sp.guance.map(([x, y]) => rect(x, y, 2, 1, C.R)).join('') : '';
    // accessori delle reazioni: occhiali da sole (hype), mani sugli occhi (errore), mani che applaudono (orale)
    let accessori = '';
    if (opz.occhiali) {
      const [[lx, ly], [rx]] = sp.occhi;
      accessori += `<g class="pet-occhiali">${rect(lx - 2, ly - 1, 5, 3, C.K)}${rect(rx - 1, ly - 1, 5, 3, C.K)}${rect(lx + 3, ly - 1, rx - lx - 4, 1, C.K)}`
        + `${rect(lx - 1, ly - 1, 2, 1, C.W)}${rect(rx, ly - 1, 2, 1, C.W)}</g>`;
    }
    if (opz.mani === 'occhi') accessori += `<g class="pet-mani-occhi">${sp.occhi.map(([x, y]) =>
      rect(x - 2, y - 2, 5, 5, C.O) + rect(x - 1, y - 1, 3, 3, C.L) + rect(x - 1, y - 2, 1, 1, C.L) + rect(x + 1, y - 2, 1, 1, C.L)).join('')}</g>`;
    if (opz.mani === 'applauso') {
      const y = Math.min(20, sp.pancia[1]);
      accessori += [['sx', 0], ['dx', 21]].map(([l, x]) => `<g class="pet-mano ${l}">${rect(x, y - 1, 3, 4, C.O)}${rect(x + (l === 'sx' ? 0 : 1), y, 2, 2, C.L)}</g>`).join('');
    }
    // decorazioni animate
    let extra = '';
    const [tx, ty] = sp.testa;
    if (umore === 'dorme') extra = [0, 1, 2].map(i => `<text class="pet-zzz" style="animation-delay:${i}s" x="${tx}" y="${ty + 4}" fill="${C.L}">z</text>`).join('');
    if (umore === 'affamato') { const [bx, by] = sp.pancia;
      extra = `<g class="pet-grr" fill="#ff9f1a">${rect(bx, by, 1, 1, '#ff9f1a')}${rect(bx + 1, by - 1, 1, 1, '#ff9f1a')}${rect(bx + 2, by, 1, 1, '#ff9f1a')}${rect(bx, by + 2, 1, 1, '#ff9f1a')}${rect(bx + 1, by + 1, 1, 1, '#ff9f1a')}${rect(bx + 2, by + 2, 1, 1, '#ff9f1a')}</g>`; }
    if (umore === 'euforico') extra = [[1, 4], [21, 6], [3, 18], [20, 19]].map(([x, y], i) =>
      `<g class="pet-scintilla" style="animation-delay:${i * .35}s">${rect(x, y - 1, 1, 3, C.G)}${rect(x - 1, y, 3, 1, C.G)}</g>`).join('');
    const alone = ALONE[umore] === 'B' ? C.B : ALONE[umore];
    const lato = opz.lato || 96;
    return `<svg class="pet-svg stadio-${indice} umore-${umore} ${opz.classe || ''}" viewBox="-3 -4 30 30" width="${lato}" height="${lato}"
      shape-rendering="crispEdges" style="--alone:${alone}" role="img" aria-label="${STADI[indice]?.nome || 'Bit'}, ${UMORI[umore] || umore}">
      <g class="pet-tutto"><g class="pet-corpo">${corpo}<g class="pet-guance">${guance}</g><g class="pet-bocca">${bocca}</g>
      <g class="pet-occhi ${!chiusi && !felici && umore !== 'errore' ? 'aperti' : ''}">${occhi}</g>${accessori}</g></g>${extra}</svg>`;
  }

  /* ------------------------------------------------------------ Bit vivo: reazioni, fumetto, inattività */
  /* Due caratteri: «giovane» (Uovo, Bit, Byte, Kilobyte) e «senior» (Megabyte, Gigabyte).
     {n} = numero di risposte giuste di fila, {m} = titolo del modulo. Frasi neutre: niente maschile/femminile. */
  const BATTUTE = {
    giovane: {
      giusta: ['Giusta! Gnam, che buon XP.', 'Sì! Mi è venuto il saltino.', 'Esatto! Mi crescono i bit.', 'Corretta! Un byte di felicità.',
        'Bel colpo! Un\'altra così e mi evolvo.', 'Vai così! Il mio heap si riempie.', 'return true; Che gioia!', 'Giusta! Questa me la segno.'],
      sbagliata: ['Ahia! Segmentation fault nel mio cuore.', 'Oh no... errore di logica rilevato!', 'Bzzt! Risposta corrotta. Leggi il commento e riproviamo.',
        'Ouch! Mi si è glitchato un pixel.', 'Ops! La spiegazione qui sotto è dove si impara davvero.', 'Errore! Ma tornerà presto: la prossima volta è nostra.'],
      combo: ['COMBO x{n}! Sono in modalità turbo!', '{n} di fila! Mi servono gli occhiali da sole.', 'x{n}! Stai compilando senza warning!', 'Inarrestabile: {n} giuste in fila!'],
      esitazione: ['Mmmh... *sbadiglio* tutto bene lì?', 'Tic tac... all\'esame hai due minuti a domanda.', 'Il mio stomaco brontola... una risposta?',
        'Non la sai? Scarta prima le opzioni impossibili.', 'Pensaci pure, io intanto conto: 0, 1, 10, 11...'],
      compilaOk: ['Compila e gira! Zero warning: che profumo di codice pulito.', 'g++ non ha detto niente: è il complimento più grande!', 'Eseguito! Festeggio con un byte extra.'],
      compilaAvvisi: ['Compila, ma g++ ha dei warning: leggili, spesso sono bug veri.', 'Funziona... ma quei warning mi fanno il solletico.'],
      compilaErrore: ['Non guardo! Non compila...', 'Aiuto, errori rossi ovunque! Parti dal primo.', 'g++ si è arrabbiato. Correggi il primo errore e riprova.', 'Mi copro gli occhi: dimmi quando compila.'],
      crash: ['BOOM! Il programma è crollato. Puntatori sospetti?', 'Fumo! Qualcosa è esploso durante l\'esecuzione.', 'Crash! Controlla new, delete e gli indici degli array.'],
      diffOk: ['Output identico alla soluzione! Sono senza parole.', 'Perfetto, riga per riga! Questo è da laboratorio vero.'],
      diffNo: ['Uh... l\'output non coincide. Guarda le righe con il meno.', 'Quasi! Qualche riga diversa: confrontale con calma.'],
      oraleAlta: ['Clap clap! Spiegazione da 30.', 'Che esposizione! Il prof prenderebbe appunti.', 'Applausi a 8 bit! Chiara e precisa.'],
      oraleBassa: ['Nessun problema: un ripasso di «{m}» e la prossima volta va.', 'Si impara così: rileggi la teoria di «{m}» e riprova ad alta voce.',
        'Domanda segnata: tornerà presto. Intanto un occhio a «{m}».'],
      prevediOk: ['Hai letto il codice come un compilatore!', 'Output previsto! Hai la vista a raggi X.'],
      prevediNo: ['Mancato! Rileggi il programma riga per riga, come fa la CPU.', 'Non era quello: segui le variabili con carta e penna.'],
      fame: ['Ho fame di XP... un quiz veloce?', 'Il mio stomaco fa grrr. Tre domande e sono sazio!', 'Ehi, ci sei? Ho un buco nello stack.', 'Tempo morto? Bastano 5 minuti di orale.'],
      dorme: ['Zzz... toccami per svegliarmi...', 'Zzz... sogno liste concatenate...'],
      sveglia: ['Eccoti! Ripartiamo?', 'Sveglio! Dove eravamo rimasti?'],
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
      compilaOk: ['Zero warning. Questo codice ha classe. E distruttore.', 'Compila al primo colpo. Mi commuovo.', 'Che eleganza. Nemmeno -Wextra ha trovato da ridire.'],
      compilaAvvisi: ['Compila, sì. Ma quei warning sono grida d\'aiuto.', 'Un warning ignorato oggi è un segfault domani.'],
      compilaErrore: ['Non posso guardare. Chiudo gli occhi finché non compila.', 'Errore di compilazione. Si corregge il PRIMO. Sempre il primo.', 'g++ ha parlato, e non era un complimento.'],
      crash: ['Segfault. Un puntatore pendente ha colpito ancora. Chi ha liberato quella memoria?!',
        'Crash. Scena del crimine: un delete dimenticato o un indice oltre la fine.', 'Fumo dai registri! Qualcuno ha scritto oltre la fine dell\'array.'],
      diffOk: ['Output identico. Riga per riga. Il laboratorio non ti merita.', 'Perfetto. Incornicio questo output.'],
      diffNo: ['L\'output diverge. Come certe scelte sui puntatori.', 'Righe diverse. Confronta, con umiltà.'],
      oraleAlta: ['Esposizione impeccabile. Applaudo, e io non applaudo mai.', 'Precisione chirurgica. Il prof annuirebbe in silenzio.', 'Da 30 e lode. Lo metto agli atti.'],
      oraleBassa: ['Non disperiamo. Riapri «{m}»: la teoria non morde. Io sì.', 'Il modulo «{m}» ti chiama. Rispondigli prima dell\'esame.'],
      prevediOk: ['Hai eseguito il codice a mente. Rispetto.', 'Output previsto. Sei tu il compilatore, adesso.'],
      prevediNo: ['Previsione errata. La CPU non improvvisa: segui ogni riga.', 'No. Traccia le variabili come un detective, non come un poeta.'],
      fame: ['Un Gigabyte a digiuno è uno spettacolo triste.', 'Inattività rilevata. Il mio heap reclama XP.', 'Sto per lanciare un\'eccezione: std::fame.'],
      dorme: ['Zzz... sogno codice senza memory leak...', 'Zzz... delete[] noia;'],
      sveglia: ['Oh, ci sei. Fingerò di non aver dormito.', 'Ripristino dal sonno completato.'],
      clic: {
        tutti: ['Non disturbare il genio mentre medita.', 'Sì? Una domanda sui puntatori, spero.', 'Regola dei tre. Sempre. Non farmelo ripetere.'],
        quiz: ['Leggi il testo due volte. Le trappole stanno nei dettagli.'],
        codice: ['Ogni new senza delete è una piccola tragedia greca.', 'Distruttore virtuale nella classe base. Non dimenticarlo. Mai.'],
        orale: ['All\'orale: definizione, esempio, disegno. Recitalo come Shakespeare.'],
        oggi: ['Il piano di oggi ti attende. Io pure.'],
        bit: ['Ammira pure. Ogni pixel è guadagnato.'],
      },
    },
  };
  /* reazione -> animazione, espressione, accessori, particelle, icona del fumetto, durata (ms) */
  const REAZIONI = {
    giusta: { anim: 'felice', umore: 'felice', part: 'xp', durata: 1400 },
    rapida: { anim: 'felice', umore: 'tranquillo', durata: 1400 },
    sbagliata: { anim: 'glitch', umore: 'errore', durata: 1500, suono: 'errore' },
    combo: { anim: 'hype', umore: 'euforico', occhiali: true, part: 'scintille', durata: 2600, suono: 'combo' },
    esitazione: { anim: 'sbadiglio', umore: 'sbadiglio', icona: 'orologio', durata: 2600 },
    compilaOk: { anim: 'felice', umore: 'euforico', part: 'xp', durata: 1800 },
    compilaAvvisi: { anim: 'consola', umore: 'tranquillo', durata: 1600 },
    compilaErrore: { anim: 'trema', umore: 'errore', mani: 'occhi', durata: 2200, suono: 'errore' },
    crash: { anim: 'trema', umore: 'errore', part: 'fumo', durata: 2400, suono: 'errore' },
    diffOk: { anim: 'hype', umore: 'euforico', occhiali: true, part: 'scintille', durata: 2600, suono: 'combo' },
    diffNo: { anim: 'trema', umore: 'errore', mani: 'occhi', durata: 2000 },
    oraleAlta: { anim: 'felice', umore: 'euforico', mani: 'applauso', part: 'scintille', durata: 2200 },
    oraleBassa: { anim: 'consola', umore: 'tranquillo', durata: 1800 },
    prevediOk: { anim: 'felice', umore: 'felice', part: 'xp', durata: 1400 },
    prevediNo: { anim: 'glitch', umore: 'errore', durata: 1500 },
    fame: { anim: 'brontola', umore: 'affamato', icona: 'stomaco', durata: 2800 },
    dorme: { anim: '', umore: 'dorme', durata: 0 },
    sveglia: { anim: 'felice', umore: 'felice', durata: 1200 },
    clic: { anim: 'salta', umore: 'felice', durata: 900 },
  };
  const ICONE_FUMETTO = {   // icone 8×8 in pixel art
    orologio: ['..####..', '.#....#.', '#...#..#', '#...#..#', '#...###.', '#......#', '.#....#.', '..####..'],
    stomaco: ['........', '.##..##.', '#..##..#', '#......#', '.#.##.#.', '..#..#..', '...##...', '........'],
  };
  function iconaPixel(nome) {
    const r = ICONE_FUMETTO[nome]; if (!r) return '';
    let s = '';
    r.forEach((riga, y) => [...riga].forEach((c, x) => { if (c === '#') s += `<rect x="${x}" y="${y}" width="1" height="1"/>`; }));
    return `<svg class="cmp-icona" viewBox="0 0 8 8" width="16" height="16" shape-rendering="crispEdges" fill="currentColor" aria-hidden="true">${s}</svg>`;
  }
  const scegli = l => l[Math.floor(Math.random() * l.length)];

  /* new Compagno({ stato, colore, contesto, attivo, visibile, lato, classe, pos, salvaPos, suono })
     stato() -> Gioco.pet(...) ; contesto() -> 'quiz' | 'codice' | 'orale' | 'oggi' | 'bit' */
  class Compagno {
    constructor(o) {
      this.o = o; this.serie = 0; this.dorme = false; this.affamato = false; this.temp = null;
      this.ultima = Date.now(); this.qChiave = null; this.qInizio = 0;
      const el = this.el = document.createElement('div');
      el.className = 'compagno ' + (o.classe || '');
      el.innerHTML = `<div class="cmp-fumetto" hidden><span class="cmp-icona-box"></span><span class="cmp-testo"></span></div>
        <div class="cmp-effetti" aria-hidden="true"></div>
        <button class="cmp-pet" type="button"><span class="cmp-aura"></span><span class="cmp-corpo"></span></button>`;
      document.body.appendChild(el);
      this.fumetto = el.querySelector('.cmp-fumetto'); this.testo = el.querySelector('.cmp-testo');
      this.corpo = el.querySelector('.cmp-corpo'); this.effetti = el.querySelector('.cmp-effetti');
      this.fumetto.onclick = () => this.zitto();
      if (o.pos) { this.utente = true; this.posiziona(o.pos.x, o.pos.y); }
      this.trascinabile();
      const sveglio = () => this.attivita();
      for (const t of ['pointerdown', 'keydown', 'wheel', 'touchstart']) document.addEventListener(t, sveglio, { capture: true, passive: true });
      let mm = 0;
      document.addEventListener('mousemove', () => { const t = Date.now(); if (t - mm > 1500) { mm = t; this.attivita(); } }, { passive: true });
      setInterval(() => this.controllaInattivita(), 5000);
      addEventListener('resize', () => { if (this.utente && this.pos) this.posiziona(this.pos.x, this.pos.y); else this.casa(); });
      this.aggiorna();
    }
    get pet() { return this.o.stato(); }
    get lato() { return typeof this.o.lato === 'function' ? this.o.lato() : this.o.lato || 76; }
    get carattere() { return this.pet.indice >= 4 ? 'senior' : 'giovane'; }
    attivo() { return !this.o.attivo || this.o.attivo(); }

    /* ridisegna (stadio, colore, espressione del momento) e decide se mostrarsi */
    aggiorna() {
      const vis = this.attivo() && (!this.o.visibile || this.o.visibile());
      this.el.hidden = !vis;
      document.body.classList.toggle('compagno-attivo', vis);
      if (!vis) return;
      const p = this.pet, t = this.temp || {};
      const umore = this.dorme ? 'dorme' : t.umore || (this.affamato ? 'affamato' : p.umore);
      const html = svgPet(p.indice, umore, { colore: this.o.colore(), lato: this.lato, occhiali: t.occhiali, mani: t.mani });
      if (html !== this.html) { this.html = html; this.corpo.innerHTML = html; }   // niente ridisegni inutili: ripartirebbero le animazioni
      this.el.querySelector('.cmp-pet').setAttribute('aria-label', `${p.nome}, ${UMORI[umore] || umore}: toccalo per una frase`);
      this.el.classList.toggle('riposo', this.dorme);
      if (!this.utente) this.casa();
    }
    /* posizione di casa (decisa dall'app, es. nella barra laterale); null = angolo in basso a destra del CSS */
    casa() {
      if (this.utente || this.el.hidden) return;
      const p = this.o.ancora?.();
      if (p) this.posiziona(p.x, p.y);
      else { this.pos = null; Object.assign(this.el.style, { left: '', top: '', right: '', bottom: '' }); this.el.classList.remove('fumetto-sotto', 'fumetto-destra'); }
    }
    cambiaVista() { this.domanda(null); this.aggiorna(); }
    azzeraSerie() { this.serie = 0; }

    /* il quiz mostra una domanda nuova: parte il conto per l'esitazione (null = nessuna domanda aperta) */
    domanda(chiave, ms = 15000) {
      if (chiave === this.qChiave) return;
      clearTimeout(this.tEsita);
      this.qChiave = chiave; this.qInizio = Date.now();
      if (chiave != null) this.tEsita = setTimeout(() => { if (this.qChiave === chiave) this.reagisci('esitazione'); }, ms);
    }

    reagisci(tipo, dati = {}) {
      if (!this.attivo()) return;
      if (tipo === 'giusta' || tipo === 'prevediOk') {
        this.serie++;
        if (tipo === 'giusta' && this.serie >= 5 && this.serie % 5 === 0) { tipo = 'combo'; dati.n = this.serie; }
        else if (tipo === 'giusta' && this.carattere === 'senior' && Date.now() - this.qInizio < 5000) tipo = 'rapida';
      } else if (tipo === 'sbagliata' || tipo === 'prevediNo') this.serie = 0;
      if (tipo === 'giusta' || tipo === 'sbagliata' || tipo === 'rapida' || tipo === 'combo') { clearTimeout(this.tEsita); this.qChiave = null; }
      if (tipo !== 'dorme' && tipo !== 'fame') { this.dorme = false; this.affamato = false; }
      const r = REAZIONI[tipo] || REAZIONI.clic;
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
      this.dice(frase, r.icona);
      if (r.durata) this.tFine = setTimeout(() => { this.temp = null; this.aggiorna(); }, r.durata);
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
      const n = tipo === 'fumo' ? 9 : tipo === 'scintille' ? 10 : 12;
      for (let i = 0; i < n; i++) {
        const p = document.createElement('i');
        p.className = 'cmp-p ' + tipo;
        const ang = tipo === 'fumo' ? -Math.PI / 2 + (Math.random() - .5) * 1.1 : (i / n) * Math.PI * 2 + Math.random() * .5;
        const dist = (tipo === 'fumo' ? 40 : 34) + Math.random() * 26;
        p.style.setProperty('--dx', Math.cos(ang) * dist + 'px');
        p.style.setProperty('--dy', Math.sin(ang) * dist - (tipo === 'fumo' ? 10 : 0) + 'px');
        p.style.animationDelay = (tipo === 'fumo' ? i * 90 : Math.random() * 120) + 'ms';
        if (tipo === 'xp' && i % 4 === 0) { p.textContent = '+XP'; p.classList.add('scritta'); }
        this.effetti.appendChild(p);
        setTimeout(() => p.remove(), 1800 + i * 90);
      }
    }

    /* fumetto con effetto macchina da scrivere; sparisce da solo dopo qualche secondo */
    dice(frase, icona) {
      clearInterval(this.tScrivi); clearTimeout(this.tZitto);
      const f = this.fumetto;
      f.querySelector('.cmp-icona-box').innerHTML = icona ? iconaPixel(icona) : '';
      f.hidden = false; f.classList.remove('via'); f.classList.add('scrive');
      this.testo.textContent = ''; this.fraseIntera = frase;
      let i = 0;
      this.tScrivi = setInterval(() => {
        i += frase[i] === ' ' ? 2 : 1;
        this.testo.textContent = frase.slice(0, i);
        if (i >= frase.length) { clearInterval(this.tScrivi); f.classList.remove('scrive'); }
      }, 28);
      this.tZitto = setTimeout(() => this.zitto(), Math.max(3600, frase.length * 28 + 2600));
    }
    zitto() {
      clearInterval(this.tScrivi); clearTimeout(this.tZitto);
      const f = this.fumetto; if (f.hidden) return;
      f.classList.add('via');
      setTimeout(() => { if (f.classList.contains('via')) { f.hidden = true; f.classList.remove('via'); } }, 220);
    }

    /* tempi morti: dopo 2 minuti fermi ha fame, dopo 6 si addormenta; il primo gesto lo sveglia */
    attivita() {
      this.ultima = Date.now();
      if (this.dorme && this.attivo()) { this.dorme = false; this.affamato = false; this.reagisci('sveglia'); }
      else if (this.affamato) { this.affamato = false; this.aggiorna(); }
    }
    controllaInattivita() {
      if (!this.attivo() || document.hidden) return;
      const fermo = Date.now() - this.ultima;
      if (!this.dorme && fermo > 360000) this.reagisci('dorme');
      else if (!this.dorme && !this.affamato && fermo > 120000) this.reagisci('fame');
    }

    /* trascina Bit dove dà meno fastidio; un tocco senza trascinare = salto e frase */
    trascinabile() {
      const b = this.el.querySelector('.cmp-pet');
      let inizio = null, mosso = false;
      b.addEventListener('pointerdown', ev => {
        if (ev.button !== 0) return;
        const r = this.el.getBoundingClientRect();
        inizio = { x: ev.clientX, y: ev.clientY, l: r.left, t: r.top }; mosso = false;
        b.setPointerCapture(ev.pointerId);
      });
      b.addEventListener('pointermove', ev => {
        if (!inizio) return;
        const dx = ev.clientX - inizio.x, dy = ev.clientY - inizio.y;
        if (!mosso && Math.hypot(dx, dy) < 6) return;
        mosso = true; this.el.classList.add('trascinato');
        this.posiziona(inizio.l + dx, inizio.t + dy);
      });
      const fine = () => {
        if (!inizio) return;
        inizio = null; this.el.classList.remove('trascinato');
        if (mosso) { this.utente = true; this.o.salvaPos?.(this.pos); } else this.reagisci('clic');
      };
      b.addEventListener('pointerup', fine);
      b.addEventListener('pointercancel', () => { inizio = null; this.el.classList.remove('trascinato'); });
      b.addEventListener('keydown', ev => { if (ev.key === 'Enter' || ev.key === ' ') { ev.preventDefault(); this.reagisci('clic'); } });
    }
    posiziona(x, y) {
      const w = this.el.offsetWidth || 80, h = this.el.offsetHeight || 80;
      x = Math.max(4, Math.min(innerWidth - w - 4, x)); y = Math.max(4, Math.min(innerHeight - h - 4, y));
      this.pos = { x: Math.round(x), y: Math.round(y) };
      Object.assign(this.el.style, { left: this.pos.x + 'px', top: this.pos.y + 'px', right: 'auto', bottom: 'auto' });
      this.el.classList.toggle('fumetto-sotto', y < 150);
      this.el.classList.toggle('fumetto-destra', x + w / 2 < innerWidth / 2);
    }
    rimettiAPosto() { this.utente = false; this.casa(); }
  }

  window.Gioco = {
    svgPet, Compagno, BATTUTE,
    oggiISO, registra, calcola, missioni, esitoMissioni, pet, disegnaPet, UMORI, STADI,
    sogliaLivello, livelloDa, unisci, COLORI, paletta, applicaAccento, XP_ES,
  };
})();
