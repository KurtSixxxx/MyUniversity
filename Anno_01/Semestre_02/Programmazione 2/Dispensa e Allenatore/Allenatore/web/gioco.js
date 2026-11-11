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
      simOggi: sims.some(s => s.data === oggi && s.superato),
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

  window.Gioco = {
    oggiISO, registra, calcola, missioni, esitoMissioni,
    sogliaLivello, livelloDa, unisci, COLORI, paletta, applicaAccento, XP_ES,
    _util: { rgbDa, hslDa, hash, oggiISO },   // per bit.js
  };
})();
