'use strict';
/* =====================================================================
   Allenatore Prog2 — interfaccia
   I contenuti arrivano da Python (window.pywebview.api), che li legge
   dalla dispensa. Qui c'è solo presentazione e logica di allenamento.
   ===================================================================== */

const $ = (s, r = document) => r.querySelector(s);
const $$ = (s, r = document) => [...r.querySelectorAll(s)];
const esc = s => String(s ?? '').replace(/[&<>"]/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));
const api = () => window.pywebview.api;
const pausa = ms => new Promise(r => setTimeout(r, ms));

/* ---------------------------------------------------------------- icone */
const ICONE = {
  oggi: '<circle cx="12" cy="12" r="4"/><path d="M12 2v2M12 20v2M4.93 4.93l1.41 1.41M17.66 17.66l1.41 1.41M2 12h2M20 12h2M6.34 17.66l-1.41 1.41M19.07 4.93l-1.41 1.41"/>',
  quiz: '<path d="m3 17 2 2 4-4"/><path d="m3 7 2 2 4-4"/><path d="M13 6h8"/><path d="M13 12h8"/><path d="M13 18h8"/>',
  orale: '<path d="M12 2a3 3 0 0 0-3 3v7a3 3 0 0 0 6 0V5a3 3 0 0 0-3-3Z"/><path d="M19 10v2a7 7 0 0 1-14 0v-2"/><path d="M12 19v3"/>',
  codice: '<path d="m16 18 6-6-6-6"/><path d="m8 6-6 6 6 6"/>',
  impostazioni: '<path d="M20 7h-9"/><path d="M14 17H5"/><circle cx="17" cy="17" r="3"/><circle cx="7" cy="7" r="3"/>',
  play: '<path d="M7 4.5v15a1 1 0 0 0 1.5.86l12-7.5a1 1 0 0 0 0-1.72l-12-7.5A1 1 0 0 0 7 4.5Z" fill="currentColor" stroke="none"/>',
  check: '<path d="M20 6 9 17l-5-5"/>',
  x: '<path d="M18 6 6 18"/><path d="m6 6 12 12"/>',
  orologio: '<circle cx="12" cy="12" r="9"/><path d="M12 7v5l3 2"/>',
  occhio: '<path d="M2 12s3.5-7 10-7 10 7 10 7-3.5 7-10 7S2 12 2 12Z"/><circle cx="12" cy="12" r="3"/>',
  sinistra: '<path d="m12 19-7-7 7-7"/><path d="M19 12H5"/>',
  destra: '<path d="M5 12h14"/><path d="m12 5 7 7-7 7"/>',
  cerca: '<circle cx="11" cy="11" r="7"/><path d="m20 20-3.5-3.5"/>',
  cartella: '<path d="M20 20a2 2 0 0 0 2-2V8a2 2 0 0 0-2-2h-7.9a2 2 0 0 1-1.69-.9L9.6 3.9A2 2 0 0 0 7.93 3H4a2 2 0 0 0-2 2v13a2 2 0 0 0 2 2Z"/>',
  ricomincia: '<path d="M3 12a9 9 0 1 0 9-9 9.75 9.75 0 0 0-6.74 2.74L3 8"/><path d="M3 3v5h5"/>',
  confronta: '<circle cx="18" cy="18" r="3"/><circle cx="6" cy="6" r="3"/><path d="M13 6h3a2 2 0 0 1 2 2v7"/><path d="M11 18H8a2 2 0 0 1-2-2V9"/>',
  libro: '<path d="M2 4h6a4 4 0 0 1 4 4v13a3 3 0 0 0-3-3H2z"/><path d="M22 4h-6a4 4 0 0 0-4 4v13a3 3 0 0 1 3-3h7z"/>',
  fulmine: '<path d="M13 2 4 14h8l-1 8 9-12h-8l1-8z"/>',
  bersaglio: '<circle cx="12" cy="12" r="9"/><circle cx="12" cy="12" r="5"/><circle cx="12" cy="12" r="1"/>',
  terminale: '<path d="m5 17 5-5-5-5"/><path d="M12 19h7"/>',
  giu: '<path d="m6 9 6 6 6-6"/>',
  avanti: '<path d="m9 18 6-6-6-6"/>',
  altro: '<circle cx="5" cy="12" r="1.2" fill="currentColor"/><circle cx="12" cy="12" r="1.2" fill="currentColor"/><circle cx="19" cy="12" r="1.2" fill="currentColor"/>',
  attenzione: '<path d="m21.7 18-8-14a2 2 0 0 0-3.4 0l-8 14A2 2 0 0 0 4 21h16a2 2 0 0 0 1.7-3Z"/><path d="M12 9v4"/><path d="M12 17h.01"/>',
  ripeti: '<path d="M17 2l4 4-4 4"/><path d="M3 11v-1a4 4 0 0 1 4-4h14"/><path d="M7 22l-4-4 4-4"/><path d="M21 13v1a4 4 0 0 1-4 4H3"/>',
  tastiera: '<rect x="2" y="5" width="20" height="14" rx="2.5"/><path d="M6 9h.01M10 9h.01M14 9h.01M18 9h.01M6 13h.01M18 13h.01M9 15.5h6"/>',
  stella: '<path d="m12 3 2.6 5.6 6.1.7-4.5 4.2 1.2 6L12 16.6 6.6 19.5l1.2-6-4.5-4.2 6.1-.7z"/>',
  pannello: '<rect x="3" y="4" width="18" height="16" rx="2.5"/><path d="M9 4v16"/>',
  salva: '<path d="M5 3h11l5 5v11a2 2 0 0 1-2 2H5a2 2 0 0 1-2-2V5a2 2 0 0 1 2-2Z"/><path d="M7 3v5h8"/><path d="M7 21v-7h10v7"/>',
  bit: '<rect x="4" y="7" width="16" height="12" rx="2"/><path d="M12 3v4"/><circle cx="12" cy="3" r="1"/><path d="M9 12h.01M15 12h.01"/><path d="M9.5 15.5h5"/><path d="M2 12v3M22 12v3"/>',
  musica: '<path d="M9 18V5l12-2v13"/><circle cx="6" cy="18" r="3"/><circle cx="18" cy="16" r="3"/>',
  telefono: '<rect x="6" y="2" width="12" height="20" rx="2.5"/><path d="M11 18h2"/>',
};
const ic = (n, cls = '') => `<svg class="ic ${cls}" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1.8" stroke-linecap="round" stroke-linejoin="round" aria-hidden="true">${ICONE[n] || ''}</svg>`;

/* ---------------------------------------------------------------- stato */
const S = {
  cat: null, prog: null, imp: null, gpp: null, versione: '', cartellaDati: '',
  vista: null, moduli: [], quizPer: {}, esPer: {},
  q: { fase: 'scelta', modo: 'allenamento', moduli: null, num: 10 },
  o: { filtro: 'tutti', corrente: null, mostrata: false, timer: null },
  c: { id: null, filtro: 'tutti', cerca: '', aperti: new Set(), sporco: false, ultimo: null,
       scheda: 'output', crono: { inizio: null, acc: 0, id: null }, tracciaAperta: false, costruito: false, inCorso: false },
};
const VISTE = [['oggi', 'Oggi'], ['quiz', 'Quiz'], ['orale', 'Orale'], ['codice', 'Codice'], ['bit', 'Bit']];
const nomePet = () => (S.imp?.nome_pet || '').trim() || 'Bit';
const CORTI = { 0: 'Simulazione', 1: 'OOP', 2: 'C++ base', 3: 'Puntatori', 4: 'Classi', 5: 'Template', 6: 'Complessità',
  7: 'Ordinamento', 8: 'Ricorsione', 9: 'Ereditarietà', 10: 'Operatori', 11: 'Liste', 12: 'Pile e code', 13: 'Alberi', 14: 'Grafi' };
const ETICHETTE_TIPO = { es: '', lab: 'Laboratorio a step', pattern: 'Pattern a memoria', esame: 'Simulazione d\'esame' };

/* ---------------------------------------------------------------- avvio */
window.addEventListener('pywebviewready', avvia);

async function avvia() {
  let d;
  try { d = await api().avvio(); }
  catch (e) { return erroreAvvio('Errore di avvio: ' + e); }
  $('#voce-impostazioni').innerHTML = `${ic('impostazioni')}<span>Impostazioni</span>`;
  $('#riduci-barra').innerHTML = ic('pannello');
  if (!caricaDati(d)) return;
  // v2.2: il tema «Terminale» diventa quello predefinito (una volta sola; poi decide lo studente)
  if (!S.imp.tema_terminale_proposto) salvaImp({ tema: 'hacker', tema_terminale_proposto: true });
  disegnaMenu();
  applicaPannelli();
  applicaTema();
  matchMedia('(prefers-color-scheme: dark)').addEventListener('change', applicaTema);
  S.lettore = new Musica.Lettore({
    imp: () => S.imp, salva: p => salvaImp(p), dock: $('#musica-dock'), mini: () => [$('#musica-mini')],
    accediSpotify: () => accediSpotify(), avviso: t => avviso(t),
  });
  S.gioco = Gioco.calcola(S.prog, S.cat, { obiettivo: S.imp.obiettivo_xp });
  S.traguardiVisti = new Set(S.imp.traguardi_visti || S.gioco.traguardi.filter(t => t.ok).map(t => t.id));
  S.bit = new Gioco.Compagno({
    stato: () => Gioco.pet(S.gioco || statoGioco(), nomePet()), colore: () => S.imp.accento || Gioco.COLORI[0][0],
    contesto: () => S.vista, attivo: () => S.imp.compagno !== false && !!S.imp.configurato, visibile: () => S.vista !== 'bit',
    lato: () => S.imp.barra_stretta ? 54 : 80, pos: S.imp.compagno_pos, ancora: casaBit, salvaPos: p => salvaImp({ compagno_pos: p }), suono: t => S.lettore?.effetto(t),
  });
  aggiornaMini();
  setInterval(() => { aggiornaMini(); disegnaPetMini(); }, 60000);
  $('#app').hidden = false;
  const intro = S.imp.intro !== false && S.imp.configurato ? mostraIntro() : Promise.resolve();   // l'intro copre l'app mentre questa si disegna sotto
  $('#avvio').classList.add('via');
  setTimeout(() => $('#avvio')?.remove(), 500);
  vai(S.imp.vista && S.imp.vista !== 'codice' ? S.imp.vista : 'oggi');
  if (S.cat.avvisi?.length) console.warn(S.cat.avvisi);
  intro.then(() => {
    if (!S.imp.configurato) return benvenuto();
    if (S.imp.musica_auto !== false && S.lettore.sorgente === 'colonna') S.lettore.play();
  });
}

function disegnaMenu() {
  $('#menu').innerHTML = VISTE.map(([v, t]) => { if (v === 'bit') t = nomePet();
    return `<button class="voce-menu ${v === S.vista ? 'attiva' : ''}" data-azione="vai" data-vista="${v}" data-titolo="${esc(t)}">${ic(v)}<span>${esc(t)}</span></button>`; }).join('');
  $('#marchio-sotto').textContent = (S.imp.professore || '').trim() ? 'prof. ' + S.imp.professore.trim() : 'Allenatore d\'esame';
}

function mostraIntro() {
  if (typeof avviaIntro !== 'function' || $('.intro')) return Promise.resolve();
  return avviaIntro({
    nome: S.imp.nome, giorni: giorniAllEsame() ?? -1, quiz: S.cat.quiz.length, orale: S.cat.orale.length,
    esercizi: S.cat.esercizi.length, gpp: !!S.gpp, versione: 'v' + S.versione, musica: S.imp.musica !== false,
    professore: (S.imp.professore || '').trim(), sigla: (S.imp.sigla || '').trim() || 'UNICT',
    livello: S.gioco?.livello, pet: nomePet(),
  });
}

function caricaDati(d) {
  S.imp = d.impostazioni; S.gpp = d.gpp; S.versione = d.versione; S.cartellaDati = d.cartella_dati;
  S.prog = d.progressi || {};
  for (const k of ['quiz', 'orale', 'esercizi']) S.prog[k] = S.prog[k] || {};
  S.prog.simulazioni = S.prog.simulazioni || [];
  if (d.errore || !d.catalogo) { erroreAvvio(d.errore || 'Contenuti non trovati.', true); return false; }
  S.cat = d.catalogo;
  S.quizPer = Object.fromEntries(S.cat.quiz.map(q => [q.id, q]));
  S.esPer = Object.fromEntries(S.cat.esercizi.map(e => [e.id, e]));
  S.moduli = Object.keys(S.cat.moduli).map(Number).sort((a, b) => a - b);
  if (!S.q.moduli) S.q.moduli = new Set(S.moduli.filter(m => S.cat.quiz.some(q => q.modulo === m)));
  return true;
}

function erroreAvvio(msg, conScelta) {
  $('#avvio')?.remove();
  document.body.insertAdjacentHTML('beforeend', `
    <div class="errore-avvio"><div class="card">
      ${ic('attenzione', 'grande arancio')}
      <h2>Non trovo i contenuti</h2>
      <p>${esc(msg)}</p>
      ${conScelta ? '<button class="btn primario" data-azione="scegli-dispensa">Scegli la cartella della dispensa…</button>' : ''}
    </div></div>`);
}

/* ---------------------------------------------------------------- utilità */
let _tSalva;
function salvaProgressi() { clearTimeout(_tSalva); _tSalva = setTimeout(() => api().salva_progressi(S.prog), 250); aggiornaGioco(); }
function salvaImp(parz) { Object.assign(S.imp, parz); api().salva_impostazioni(parz); }
const oggiISO = () => { const d = new Date(); return `${d.getFullYear()}-${String(d.getMonth() + 1).padStart(2, '0')}-${String(d.getDate()).padStart(2, '0')}`; };
const maiuscola = t => t.charAt(0).toUpperCase() + t.slice(1);
const nomeModulo = m => +m === 0 ? 'Simulazione d\'esame' : `Modulo ${m}`;
const titoloModulo = m => S.cat.moduli[String(m)] || '';
const percento = (a, b) => b ? Math.round(100 * a / b) : 0;
const plur = (n, s, p) => `${n} ${n === 1 ? s : p}`;
const mmss = s => { s = Math.max(0, Math.round(s)); const h = Math.floor(s / 3600), m = Math.floor(s % 3600 / 60), x = s % 60;
  return h ? `${h}:${String(m).padStart(2, '0')}:${String(x).padStart(2, '0')}` : `${String(m).padStart(2, '0')}:${String(x).padStart(2, '0')}`; };
function mescola(a) { a = a.slice(); for (let i = a.length - 1; i > 0; i--) { const j = Math.floor(Math.random() * (i + 1)); [a[i], a[j]] = [a[j], a[i]]; } return a; }
function campionePesato(lista, pesi, k) {
  return lista.map((x, i) => [Math.pow(Math.random(), 1 / Math.max(pesi[i], 1e-6)), x])
    .sort((a, b) => b[0] - a[0]).slice(0, k).map(p => p[1]);
}

function avviso(testo, tipo = '') {
  const el = document.createElement('div');
  el.className = 'avviso ' + tipo;
  el.innerHTML = (tipo === 'ok' ? ic('check') : tipo === 'errore' ? ic('attenzione') : '') + `<span>${esc(testo)}</span>`;
  $('#avvisi').appendChild(el);
  setTimeout(() => el.classList.add('via'), 2400);
  setTimeout(() => el.remove(), 2800);
}

/* ---------------------------------------------------------------- telefono: codice dei progressi */
const linkTelefono = () => (window.CONFIG?.linkTelefono || '').trim();
/* la regola di unione (per ogni voce vince la più recente) è in gioco.js, uguale sul telefono */
const unisciProgressi = (a, b) => Gioco.unisci(a, b);
/* il profilo viaggia con i progressi, così il telefono si personalizza da solo */
const CAMPI_PROFILO = ['nome', 'data_esame', 'professore', 'corso', 'sigla', 'accento', 'nome_pet', 'obiettivo_xp'];
function codiceProgressi() {
  const profilo = Object.fromEntries(CAMPI_PROFILO.filter(k => S.imp[k] !== undefined && S.imp[k] !== '').map(k => [k, S.imp[k]]));
  const prog = { ...S.prog, data_esame: S.imp.data_esame };
  return 'P2:' + btoa(unescape(encodeURIComponent(JSON.stringify({ v: 1, prog, profilo }))));
}
function leggiCodiceProgressi(c) {
  c = (c || '').trim().replace(/\s+/g, '');
  if (!c.startsWith('P2:')) throw new Error('Il codice deve iniziare con P2:');
  let o;
  try { o = JSON.parse(decodeURIComponent(escape(atob(c.slice(3))))); } catch (e) { throw new Error('Codice incompleto: ricopialo per intero'); }
  if (!o || !o.prog) throw new Error('Codice non valido');
  return { prog: o.prog, profilo: o.profilo || {} };
}

/* ---------------------------------------------------------------- tema */
function temaScuro() {
  const t = S.imp?.tema || 'auto';
  return t === 'scuro' || t === 'hacker' || (t === 'auto' && matchMedia('(prefers-color-scheme: dark)').matches);
}
function applicaTema() {
  const scuro = temaScuro(), terminale = S.imp?.tema === 'hacker';
  document.documentElement.dataset.tema = terminale ? 'hacker' : scuro ? 'scuro' : 'chiaro';
  Gioco.applicaAccento(S.imp?.accento || Gioco.COLORI[0][0], terminale);
  S.bit?.aggiorna();
  try { api().barra_titolo(scuro, scuro ? '#000000' : '#F5F5F7'); } catch (e) { /* non su Windows */ }
}

/* ---------------------------------------------------------------- navigazione */
const RENDER = { oggi: renderOggi, quiz: renderQuiz, orale: renderOrale, codice: renderCodice, bit: renderBit };
function vai(v) {
  if (S.vista === 'codice' && v !== 'codice') salvaCodice();
  if (S.vista === 'orale' && v !== 'orale') fermaTimerOrale();
  S.vista = v;
  $$('#menu .voce-menu').forEach(b => b.classList.toggle('attiva', b.dataset.vista === v));
  $$('.vista').forEach(s => { s.hidden = s.id !== 'v-' + v; });
  const sez = $('#v-' + v);
  sez.classList.remove('entra'); void sez.offsetWidth; sez.classList.add('entra');
  RENDER[v]();
  if (v !== 'codice') $('#contenuto').scrollTop = 0;
  salvaImp({ vista: v });
  S.bit?.cambiaVista();
}

/* --- pannelli comprimibili: barra principale (Ctrl+B) ed elenco esercizi (Ctrl+E) --- */
function applicaPannelli() {
  const stretta = !!S.imp.barra_stretta, senzaElenco = !!S.imp.elenco_nascosto;
  $('#app').classList.toggle('stretta', stretta);
  $$('#menu .voce-menu').forEach(b => b.title = stretta ? b.dataset.titolo : '');
  $('#voce-impostazioni').title = stretta ? 'Impostazioni' : '';
  $('#riduci-barra').title = stretta ? 'Allarga il pannello (Ctrl+B)' : 'Riduci il pannello (Ctrl+B)';
  $('.codice')?.classList.toggle('senza-elenco', senzaElenco);
  const b = $('#mostra-elenco');
  if (b) b.title = senzaElenco ? 'Mostra l\'elenco degli esercizi (Ctrl+E)' : 'Nascondi l\'elenco degli esercizi (Ctrl+E)';
}
function cambiaPannello(chiave) { salvaImp({ [chiave]: !S.imp[chiave] }); applicaPannelli(); setTimeout(() => S.bit?.aggiorna(), 260); }
/* Bit abita nello spazio vuoto della barra laterale, sopra la scheda del livello: così non copre mai i pulsanti */
function casaBit() {
  const b = $('.barra'), p = $('.barra-piede'), m = $('#menu'); if (!b || !p || !m) return null;
  const rb = b.getBoundingClientRect(), rp = p.getBoundingClientRect(), rm = m.getBoundingClientRect(), lato = S.imp.barra_stretta ? 54 : 80;
  const y = rp.top - lato - 16;
  if (y < rm.bottom + 24) return null;   // finestra troppo bassa: angolo in basso a destra
  return { x: rb.left + rb.width / 2 - lato / 2, y };
}

function aggiornaMini() {
  const g = giorniAllEsame();
  $('#conto-mini').innerHTML = g > 0 ? `<b>${g}</b> ${g === 1 ? 'giorno' : 'giorni'} all'esame`
    : g === 0 ? '<b>Oggi</b> è il giorno dell\'esame' : '<button class="link" data-azione="impostazioni">Imposta la data dell\'appello</button>';
  disegnaPetMini();
}

/* ---------------------------------------------------------------- statistiche */
function statModulo(m) {
  const pq = S.prog.quiz, po = S.prog.orale, pe = S.prog.esercizi;
  const qs = S.cat.quiz.filter(q => q.modulo === m);
  const provati = qs.filter(q => pq[q.id]);
  const giusti = provati.filter(q => pq[q.id].ultima);
  const os = S.cat.orale.filter(o => o.modulo === m);
  const sapute = os.filter(o => (po[o.id]?.box || 0) >= 3);
  const es = S.cat.esercizi.filter(e => e.modulo === m && e.tipo === 'es');
  const fatti = es.filter(e => pe[e.id]?.fatto);
  const lab = S.cat.esercizi.filter(e => e.modulo === m && (e.tipo === 'lab' || e.tipo === 'esame'));
  return { quiz: qs.length, provati: provati.length, giusti: giusti.length, orale: os.length, sapute: sapute.length,
    es: es.length, fatti: fatti.length, lab: lab.length, labFatti: lab.filter(e => pe[e.id]?.fatto).length };
}
function statGlobali() {
  const t = { quiz: 0, provati: 0, giusti: 0, orale: 0, sapute: 0, es: 0, fatti: 0, lab: 0, labFatti: 0 };
  for (const m of S.moduli) { const s = statModulo(m); for (const k in t) t[k] += s[k]; }
  return t;
}
/* giorni che mancano all'appello; null se la data non è impostata */
function giorniAllEsame() {
  if (!/^\d{4}-\d{2}-\d{2}$/.test(S.imp?.data_esame || '')) return null;
  const d = new Date(S.imp.data_esame + 'T00:00:00');
  const o = new Date(); o.setHours(0, 0, 0, 0);
  return Math.round((d - o) / 86400000);
}
function pianoDiOggi() {
  const cal = S.cat.calendario || [], n = cal.length, g = giorniAllEsame();
  const giorno = n + 1 - g;
  if (!n || g === null || g <= 0) return null;
  if (giorno < 1) return { prima: true, tra: 1 - giorno, n };
  const v = cal[Math.min(giorno, n) - 1];
  const moduli = [...(v.argomento.match(/M(\d+)/g) || [])].map(x => +x.slice(1));
  return { giorno: Math.min(giorno, n), n, ...v, moduli };
}

/* =====================================================================
   OGGI
   ===================================================================== */
function saluto() { const h = new Date().getHours(); return h < 13 ? 'Buongiorno' : h < 18 ? 'Buon pomeriggio' : 'Buonasera'; }

function consigli() {
  const pq = S.prog.quiz, pe = S.prog.esercizi, po = S.prog.orale, out = [];
  const sbagliate = S.cat.quiz.filter(q => pq[q.id]?.ultima === false).length;
  if (sbagliate) out.push({ icona: 'ripeti', colore: 'rosso', titolo: `Correggi ${plur(sbagliate, 'risposta sbagliata', 'risposte sbagliate')}`,
    testo: 'Le domande sbagliate sono quelle che ti fanno perdere punti. Rifalle finché non le sai.', azione: 'quiz-errori', bottone: 'Inizia' });
  const deboli = S.moduli.filter(m => m > 0).map(m => [m, statModulo(m)])
    .filter(([, s]) => s.provati >= 3 && s.giusti / s.provati < 0.7)
    .sort((a, b) => a[1].giusti / a[1].provati - b[1].giusti / b[1].provati);
  for (const [m, s] of deboli.slice(0, 1)) out.push({ icona: 'bersaglio', colore: 'arancio', titolo: `Ripassa il Modulo ${m}`,
    testo: `${titoloModulo(m)}: ${percento(s.giusti, s.provati)}% di risposte giuste. Rileggi la teoria, poi rifai i quiz.`,
    azione: 'quiz-modulo', m, bottone: 'Quiz del modulo' });
  const lab = S.cat.esercizi.find(e => (e.tipo === 'lab' || e.tipo === 'esame') && !pe[e.id]?.fatto && e.modulo > 0
    && (pianoDiOggi()?.moduli || []).includes(e.modulo))
    || S.cat.esercizi.find(e => e.tipo === 'lab' && !pe[e.id]?.fatto);
  if (lab) out.push({ icona: 'terminale', colore: 'verde', titolo: `Laboratorio del Modulo ${lab.modulo}`,
    testo: 'Il laboratorio è la prova più selettiva. Uno step alla volta, compilando sempre.', azione: 'codice-apri', id: lab.id, bottone: 'Apri' });
  const daFare = S.cat.orale.filter(o => (po[o.id]?.box || 0) < 3).length;
  if (daFare) out.push({ icona: 'orale', colore: 'viola', titolo: 'Allenati all\'orale',
    testo: `${daFare} domande su ${S.cat.orale.length} non sono ancora sicure. Rispondi ad alta voce.`, azione: 'vai', vista: 'orale', bottone: 'Inizia' });
  const ultima = S.prog.simulazioni.at(-1);
  if (!ultima || ultima.data !== oggiISO()) out.push({ icona: 'orologio', colore: 'accento', titolo: 'Simulazione del quiz',
    testo: ultima ? `L'ultima volta: ${ultima.giuste}/${ultima.totale}. Trenta domande, sessanta minuti.` : 'Trenta domande in sessanta minuti, come all\'esame. Soglia: 18.',
    azione: 'quiz-esame', bottone: 'Inizia' });
  const mai = S.moduli.filter(m => m > 0 && statModulo(m).provati === 0);
  if (mai.length && out.length < 4) out.push({ icona: 'stella', colore: 'accento', titolo: `Prova i quiz del Modulo ${mai[0]}`,
    testo: `${titoloModulo(mai[0])}: non hai ancora risposto a nessuna domanda.`, azione: 'quiz-modulo', m: mai[0], bottone: 'Inizia' });
  return out.slice(0, 4);
}

function anelli(valori, dim = 184, spessore = 14, spazio = 5) {
  const c = dim / 2;
  let s = `<svg class="anelli" viewBox="0 0 ${dim} ${dim}" width="${dim}" height="${dim}">`;
  valori.forEach((v, i) => {
    const r = c - spessore / 2 - i * (spessore + spazio), C = 2 * Math.PI * r, p = Math.max(0, Math.min(1, v.p));
    s += `<circle cx="${c}" cy="${c}" r="${r}" fill="none" style="stroke:var(--${v.colore})" stroke-opacity=".16" stroke-width="${spessore}"/>`;
    s += `<circle class="arco" cx="${c}" cy="${c}" r="${r}" fill="none" style="stroke:var(--${v.colore})" stroke-width="${spessore}" stroke-linecap="round"
      stroke-dasharray="${C}" stroke-dashoffset="${C}" data-fine="${C * (1 - p)}" transform="rotate(-90 ${c} ${c})"/>`;
  });
  return s + '</svg>';
}
function animaAnelli(r) { requestAnimationFrame(() => requestAnimationFrame(() => $$('.arco', r).forEach(a => a.setAttribute('stroke-dashoffset', a.dataset.fine)))); }

function renderOggi() {
  const el = $('#v-oggi');
  const g = giorniAllEsame(), p = pianoDiOggi(), t = statGlobali();
  const dataEsame = g === null ? null : new Date(S.imp.data_esame + 'T00:00:00');
  const oggi = new Date().toLocaleDateString('it-IT', { weekday: 'long', day: 'numeric', month: 'long' });
  const nome = (S.imp.nome || '').trim();
  const corso = [(S.imp.corso || '').trim() || 'Programmazione 2', (S.imp.professore || '').trim() && 'prof. ' + S.imp.professore.trim()].filter(Boolean).join(' · ');
  let piano;
  if (!p) piano = `<div class="sopratitolo">Piano di studio</div><h3>${g === null ? 'Quando è il tuo appello?' : g <= 0 ? 'In bocca al lupo.' : 'Nessun piano'}</h3>
      <p class="secondario">${g === null ? 'Imposta la data dell\'appello: il piano di studio e il conto alla rovescia partono da lì.' : g <= 0 ? 'Oggi niente di nuovo: checklist, colazione, arriva presto.' : 'Il calendario non è stato trovato nella dispensa.'}</p>
      ${g === null ? '<div class="azioni"><button class="btn primario" data-azione="impostazioni">Imposta la data</button></div>' : ''}`;
  else if (p.prima) piano = `<div class="sopratitolo">Piano di studio</div><h3>Il piano di ${p.n} giorni parte tra ${plur(p.tra, 'giorno', 'giorni')}</h3>
      <p class="secondario">Intanto studia i moduli in ordine: teoria, quiz, esercizi.</p>
      <div class="azioni"><button class="btn primario" data-azione="vai" data-vista="quiz">Allenati con i quiz</button></div>`;
  else piano = `<div class="sopratitolo">Oggi · giorno ${p.giorno} di ${p.n}</div>
      <h3>${esc(p.argomento)}</h3>
      <p class="secondario">${esc(p.obiettivo.charAt(0).toUpperCase() + p.obiettivo.slice(1))}.</p>
      <div class="azioni">
        ${p.moduli.length ? `<button class="btn primario" data-azione="quiz-piano">${ic('quiz')}Quiz di oggi</button>
        <button class="btn secondario" data-azione="codice-modulo" data-m="${p.moduli[0]}">${ic('codice')}Esercizi di oggi</button>`
        : `<button class="btn primario" data-azione="codice-modulo" data-m="0">${ic('terminale')}Apri le tracce</button>`}
      </div>`;

  const valori = [
    { nome: 'Quiz', colore: 'accento', a: t.giusti, b: t.quiz, nota: 'risposte giuste' },
    { nome: 'Orale', colore: 'viola', a: t.sapute, b: t.orale, nota: 'domande sicure' },
    { nome: 'Esercizi', colore: 'verde', a: t.fatti, b: t.es, nota: 'esercizi completati' },
    { nome: 'Laboratori', colore: 'arancio', a: t.labFatti, b: t.lab, nota: 'laboratori svolti' },
  ];
  const sim = S.prog.simulazioni.slice(-5).reverse();
  el.innerHTML = `
    <header class="testata">
      <div class="sopratitolo">${esc(oggi)} · ${esc(corso)}</div>
      <h1>${saluto()}${nome ? ', ' + esc(nome) : ''}.</h1>
    </header>
    <div class="card eroe">
      <div class="eroe-numero">
        <div class="numero">${g > 0 ? g : g === 0 ? '0' : '—'}</div>
        <div class="numero-sotto">${g === 1 ? 'giorno' : 'giorni'} all'esame</div>
        <div class="numero-data">${dataEsame ? esc(maiuscola(dataEsame.toLocaleDateString('it-IT', { weekday: 'long', day: 'numeric', month: 'long', year: 'numeric' }))) : 'Data dell\'appello non impostata'}</div>
      </div>
      <div class="eroe-piano">${piano}</div>
    </div>
    ${cartaBitOggi()}
    <div class="griglia-2">
      <div class="card anelli-card">
        <div class="card-titolo">Il tuo allenamento</div>
        <div class="anelli-corpo">
          ${anelli(valori.map(v => ({ p: v.b ? v.a / v.b : 0, colore: v.colore })), 200, 15)}
          <div class="legenda">
            ${valori.map(v => `<div class="legenda-voce"><i style="background:var(--${v.colore})"></i>
              <div><div class="legenda-nome">${v.nome}</div><div class="legenda-valore"><b>${v.a}</b><span>/${v.b}</span> <em>${percento(v.a, v.b)}%</em></div>
              <div class="legenda-nota">${v.nota}</div></div></div>`).join('')}
          </div>
        </div>
        ${sim.length ? `<div class="sim-storico"><div class="sopratitolo">Simulazioni del quiz</div>
          <div class="sim-righe">${sim.map(s => `<span class="sim ${s.superato ? 'ok' : 'no'}" title="${esc(s.data)}">${s.giuste}<small>/${s.totale}</small></span>`).join('')}</div></div>` : ''}
      </div>
      <div class="card consigli-card">
        <div class="card-titolo">Consigliati per te</div>
        <div class="consigli">
          ${consigli().map(c => `<div class="consiglio">
            <div class="consiglio-icona ${c.colore}">${ic(c.icona)}</div>
            <div class="consiglio-testo"><div class="consiglio-titolo">${esc(c.titolo)}</div><div class="secondario">${esc(c.testo)}</div></div>
            <button class="btn secondario piccolo" data-azione="${c.azione}" ${c.m !== undefined ? `data-m="${c.m}"` : ''} ${c.id ? `data-id="${c.id}"` : ''} ${c.vista ? `data-vista="${c.vista}"` : ''}>${esc(c.bottone)}</button>
          </div>`).join('') || '<p class="secondario">Tutto in ordine. Continua così.</p>'}
        </div>
      </div>
    </div>
    <div class="titolo-sezione"><h2>Moduli</h2><span class="secondario">Quiz giusti, domande d'orale sicure ed esercizi fatti per ogni modulo.</span></div>
    <div class="griglia-moduli">
      ${S.moduli.filter(m => m > 0).map(m => cartaModulo(m)).join('')}
    </div>`;
  animaAnelli(el);
}

function cartaModulo(m) {
  const s = statModulo(m);
  const barra = (nome, a, b, colore) => `<div class="mini"><div class="mini-riga"><span>${nome}</span><span>${a}/${b}</span></div>
    <div class="barretta"><i style="width:${percento(a, b)}%;background:var(--${colore})"></i></div></div>`;
  return `<div class="card modulo">
    <div class="sopratitolo">Modulo ${m}</div>
    <div class="modulo-titolo">${esc(titoloModulo(m))}</div>
    ${barra('Quiz', s.giusti, s.quiz, 'accento')}${barra('Orale', s.sapute, s.orale, 'viola')}${barra('Esercizi', s.fatti, s.es, 'verde')}
    <div class="modulo-azioni">
      <button class="link" data-azione="quiz-modulo" data-m="${m}">Quiz</button>
      <button class="link" data-azione="orale-modulo" data-m="${m}">Orale</button>
      <button class="link" data-azione="codice-modulo" data-m="${m}">Codice</button>
    </div>
  </div>`;
}

/* =====================================================================
   QUIZ
   ===================================================================== */
const MODI = {
  allenamento: ['Allenamento', 'Correzione immediata con il commento della dispensa. Le domande sbagliate o mai viste escono più spesso.'],
  errori: ['Da correggere', 'Solo le domande a cui l\'ultima volta hai risposto male.'],
  nuove: ['Mai viste', 'Solo le domande che non hai ancora affrontato.'],
  esame: ['Esame', 'Come la prova vera: 30 domande, 60 minuti, correzione solo alla consegna. Soglia: 18 risposte giuste.'],
};

function quizPool() {
  const pq = S.prog.quiz;
  let pool = S.cat.quiz.filter(q => S.q.moduli.has(q.modulo));
  if (S.q.modo === 'errori') pool = pool.filter(q => pq[q.id]?.ultima === false);
  if (S.q.modo === 'nuove') pool = pool.filter(q => !pq[q.id]);
  return pool;
}

function renderQuiz() {
  const el = $('#v-quiz');
  el.classList.toggle('vista-quiz-sessione', S.q.fase === 'sessione');
  if (S.q.fase !== 'sessione') S.bit?.domanda(null);
  if (S.q.fase === 'sessione') return renderQuizSessione(el);
  if (S.q.fase === 'esito') return renderQuizEsito(el);
  const pool = quizPool(), esame = S.q.modo === 'esame';
  const n = esame ? Math.min(30, pool.length) : Math.min(S.q.num, pool.length);
  const sim = S.prog.simulazioni.slice(-8).reverse();
  el.innerHTML = `
    <header class="testata">
      <div class="sopratitolo">Prova scritta</div>
      <h1>Quiz a crocette</h1>
      <p class="sottotitolo">All'esame: trenta domande in un'ora su tutto il programma. Si passa con diciotto.</p>
    </header>
    <div class="card blocco">
      <div class="etichetta-campo">Modalità</div>
      <div class="segmentato largo">${Object.entries(MODI).map(([k, [t]]) =>
        `<button class="${k === S.q.modo ? 'attivo' : ''}" data-azione="quiz-modo" data-modo="${k}">${t}</button>`).join('')}</div>
      <p class="secondario descr-modo">${MODI[S.q.modo][1]}</p>
    </div>
    <div class="card blocco">
      <div class="riga-campo"><div class="etichetta-campo">Argomenti</div>
        <div><button class="link" data-azione="quiz-tutti">Tutti</button><span class="sep">·</span><button class="link" data-azione="quiz-nessuno">Nessuno</button></div></div>
      <div class="chips">${S.moduli.filter(m => S.cat.quiz.some(q => q.modulo === m)).map(m =>
        `<button class="chip ${S.q.moduli.has(m) ? 'on' : ''}" data-azione="quiz-chip" data-m="${m}">
          ${m ? `<b>M${m}</b> ${CORTI[m] || ''}` : `${ic('orologio')} Simulazione d'esame`}</button>`).join('')}</div>
    </div>
    <div class="avvio-quiz">
      <div class="avvio-info">
        ${esame ? `<div class="grande-info"><b>${n}</b> domande · <b>${Math.round(60 * n / 30)}</b> minuti</div>`
        : `<div class="stepper"><button data-azione="quiz-num" data-d="-5" aria-label="meno">−</button><span><b>${n}</b> domande</span><button data-azione="quiz-num" data-d="5" aria-label="più">+</button></div>`}
        <span class="secondario">${plur(pool.length, 'domanda disponibile', 'domande disponibili')}</span>
      </div>
      <button class="btn primario grande" data-azione="quiz-inizia" ${pool.length ? '' : 'disabled'}>Inizia ${ic('destra')}</button>
    </div>
    ${sim.length ? `<div class="card blocco"><div class="etichetta-campo">Le tue simulazioni</div>
      <div class="storico">${sim.map(s => `<div class="storico-riga"><span>${esc(new Date(s.data + 'T00:00:00').toLocaleDateString('it-IT', { day: 'numeric', month: 'long' }))}</span>
        <div class="barretta lunga"><i style="width:${percento(s.giuste, s.totale)}%;background:var(--${s.superato ? 'verde' : 'rosso'})"></i></div>
        <b>${s.giuste}/${s.totale}</b><span class="pill ${s.superato ? 'ok' : 'no'}">${s.superato ? 'Superato' : 'Sotto soglia'}</span></div>`).join('')}</div></div>` : ''}`;
}

function quizInizia() {
  const pool = quizPool();
  if (!pool.length) return avviso('Nessuna domanda con questi filtri.');
  const pq = S.prog.quiz;
  let lista;
  if (S.q.modo === 'esame') lista = mescola(pool).slice(0, 30);
  else {
    const pesi = pool.map(q => { const s = pq[q.id]; return !s ? 3 : s.ultima === false ? 5 : 1 / (1 + (s.g || 0)); });
    lista = campionePesato(pool, pesi, Math.min(S.q.num, pool.length));
  }
  Object.assign(S.q, { fase: 'sessione', lista, i: 0, risposte: {}, esame: S.q.modo === 'esame', finito: false, inizio: Date.now() });
  S.bit?.azzeraSerie();
  clearInterval(S.q.timer);
  if (S.q.esame) {
    S.q.scadenza = Date.now() + 60 * 60000 * lista.length / 30;
    S.q.timer = setInterval(tickQuiz, 1000);
  }
  renderQuiz();
}

function tickQuiz() {
  const resto = (S.q.scadenza - Date.now()) / 1000;
  const t = $('#quiz-timer');
  if (t) { t.textContent = mmss(resto); t.classList.toggle('urgente', resto < 300); }
  if (resto <= 0) { clearInterval(S.q.timer); avviso('Tempo scaduto: consegna automatica.'); quizConsegna(true); }
}

function renderQuizSessione(el) {
  const Q = S.q, q = Q.lista[Q.i], n = Q.lista.length, scelta = Q.risposte[Q.i];
  const rivela = scelta !== undefined && (!Q.esame || Q.finito);
  const date = Object.keys(Q.risposte).length;
  const dove = q.modulo === 0 ? `Simulazione d'esame${q.rif ? ' · argomento del Modulo ' + q.rif : ''}` : `${nomeModulo(q.modulo)} · ${titoloModulo(q.modulo)}`;
  const opz = q.opzioni.map((o, k) => {
    let cls = '';
    if (rivela) cls = k === q.giusta ? 'giusta' : k === scelta ? 'sbagliata' : 'attenuata';
    else if (k === scelta) cls = 'scelta';
    const segno = rivela && k === q.giusta ? ic('check') : rivela && k === scelta ? ic('x') : 'ABCD'[k];
    return `<button class="opzione ${cls}" data-azione="quiz-scegli" data-k="${k}"><span class="lettera">${segno}</span><span class="opz-testo">${o}</span></button>`;
  }).join('');
  let riscontro = '';
  if (rivela) {
    const ok = scelta === q.giusta;
    riscontro = `<div class="riscontro ${ok ? 'ok' : 'no'}">
      <div class="riscontro-titolo">${ok ? ic('check') + 'Esatto.' : ic('x') + `Non esatto. La risposta corretta è la ${'ABCD'[q.giusta]}.`}</div>
      ${q.commento ? `<div class="testo-ricco">${q.commento}</div>` : ''}</div>`;
  }
  const ultima = Q.i === n - 1;
  el.innerHTML = `
    <div class="sessione">
      <div class="sessione-barra">
        <button class="btn fantasma piccolo" data-azione="quiz-esci">${ic('sinistra')}${Q.finito ? 'Risultati' : 'Esci'}</button>
        <div class="progresso"><i style="width:${percento(Q.esame && !Q.finito ? date : Q.i + 1, n)}%"></i></div>
        <span class="conteggio">${Q.i + 1} di ${n}</span>
        ${Q.esame && !Q.finito ? `<span class="pill timer" id="quiz-timer">${mmss((Q.scadenza - Date.now()) / 1000)}</span>` : ''}
      </div>
      <div class="sessione-corpo">
        <div class="sopratitolo accento">${esc(dove)}</div>
        <div class="domanda testo-ricco">${q.domanda}</div>
        <div class="opzioni ${rivela ? 'rivelate' : ''}">${opz}</div>
        ${riscontro}
        ${Q.esame ? `<div class="navigatore">${Q.lista.map((x, k) => {
          let c = k === Q.i ? 'qui' : '';
          if (Q.finito) c += Q.risposte[k] === x.giusta ? ' ok' : ' no';
          else if (Q.risposte[k] !== undefined) c += ' data';
          return `<button class="punto ${c}" data-azione="quiz-vai" data-k="${k}" title="Domanda ${k + 1}">${k + 1}</button>`;
        }).join('')}</div>` : ''}
      </div>
      <div class="sessione-piede">
        <span class="tasti">${ic('tastiera')} <kbd>A</kbd>–<kbd>D</kbd> per rispondere · <kbd>↵</kbd> per continuare</span>
        <div class="spazio"></div>
        ${Q.esame || Q.finito ? `<button class="btn secondario" data-azione="quiz-prec" ${Q.i ? '' : 'disabled'}>${ic('sinistra')}Precedente</button>` : ''}
        ${Q.esame && !Q.finito ? `<button class="btn secondario" data-azione="quiz-consegna">Consegna</button>` : ''}
        <button class="btn primario" data-azione="quiz-succ" ${(!Q.esame && !Q.finito && scelta === undefined) ? 'disabled' : ''}>
          ${ultima ? (Q.esame || Q.finito ? (Q.finito ? 'Risultati' : 'Consegna') : 'Fine') : 'Successiva'}${ic('destra')}</button>
      </div>
    </div>`;
  evidenziaBlocchi(el);
  // Bit conta i secondi solo in allenamento: nella simulazione d'esame resta in silenzio, come in aula
  S.bit?.domanda(!Q.esame && !rivela ? q.id + '#' + Q.i : null);
}

function registraQuiz(q, ok) {
  const s = S.prog.quiz[q.id] || (S.prog.quiz[q.id] = { g: 0, s: 0 });
  s[ok ? 'g' : 's'] = (s[ok ? 'g' : 's'] || 0) + 1;
  s.ultima = ok; s.data = oggiISO();
  Gioco.registra(S.prog, 'q'); if (ok) Gioco.registra(S.prog, 'g');
}

function quizScegli(k) {
  const Q = S.q;
  if (Q.fase !== 'sessione' || Q.finito) return;
  const q = Q.lista[Q.i];
  if (k >= q.opzioni.length) return;
  if (!Q.esame) {
    if (Q.risposte[Q.i] !== undefined) return;
    Q.risposte[Q.i] = k;
    registraQuiz(q, k === q.giusta);
    S.bit?.reagisci(k === q.giusta ? 'giusta' : 'sbagliata');
    salvaProgressi();
  } else Q.risposte[Q.i] = k;
  renderQuiz();
}
function quizSucc() {
  const Q = S.q;
  if (Q.fase !== 'sessione') return;
  if (!Q.esame && !Q.finito && Q.risposte[Q.i] === undefined) return;
  if (Q.i < Q.lista.length - 1) { Q.i++; renderQuiz(); }
  else if (Q.finito) { Q.fase = 'esito'; renderQuiz(); }
  else if (Q.esame) quizConsegna();
  else { Q.finito = true; Q.fase = 'esito'; renderQuiz(); }
}
function quizPrec() { const Q = S.q; if (Q.fase === 'sessione' && (Q.esame || Q.finito) && Q.i > 0) { Q.i--; renderQuiz(); } }

async function quizConsegna(forza) {
  const Q = S.q;
  if (!Q.esame || Q.finito) return;
  const mancano = Q.lista.length - Object.keys(Q.risposte).length;
  if (!forza && !await chiedi({ titolo: 'Consegnare il quiz?',
    testo: mancano ? `Ci sono ${plur(mancano, 'domanda', 'domande')} senza risposta. Se gli errori non tolgono punti, conviene rispondere a tutte.` : 'Dopo la consegna vedrai il risultato e le risposte corrette.',
    ok: 'Consegna', annulla: 'Continua' })) return;
  clearInterval(Q.timer);
  Q.finito = true;
  let giuste = 0;
  Q.lista.forEach((q, i) => { const r = Q.risposte[i]; const ok = r === q.giusta; giuste += ok; if (r !== undefined) registraQuiz(q, ok); });
  const tot = Q.lista.length, soglia = Math.ceil(tot * 0.6);
  Q.esito = { giuste, tot, soglia, superato: giuste >= soglia, durata: (Date.now() - Q.inizio) / 1000 };
  S.prog.simulazioni.push({ data: oggiISO(), giuste, totale: tot, superato: giuste >= soglia });
  if (tot >= 30) Gioco.registra(S.prog, 's');
  salvaProgressi();
  Q.fase = 'esito';
  renderQuiz();
}

function renderQuizEsito(el) {
  const Q = S.q, tot = Q.lista.length;
  const giuste = Q.lista.filter((q, i) => Q.risposte[i] === q.giusta).length;
  const esame = Q.esame, soglia = Math.ceil(tot * 0.6), superato = giuste >= soglia;
  const titolo = esame ? (superato ? 'Superato.' : 'Non ancora.') : (giuste / tot >= 0.8 ? 'Ottimo lavoro.' : giuste / tot >= 0.6 ? 'Buon allenamento.' : 'Continua ad allenarti.');
  const sbagliate = Q.lista.map((q, i) => [q, i]).filter(([q, i]) => Q.risposte[i] !== q.giusta);
  const durata = (Date.now() - Q.inizio) / 1000;
  el.innerHTML = `
    <div class="esito">
      <div class="esito-anello">
        ${anelli([{ p: giuste / tot, colore: esame ? (superato ? 'verde' : 'rosso') : 'accento' }], 220, 18)}
        <div class="esito-numero"><b>${giuste}</b><span>su ${tot}</span></div>
      </div>
      <h1>${titolo}</h1>
      <p class="sottotitolo centro">${esame ? `Soglia: ${soglia} risposte giuste su ${tot}. ${superato ? 'Punta a restare sempre qualche risposta sopra.' : 'Ripassa i moduli delle domande sbagliate e riprova.'}`
        : `${percento(giuste, tot)}% di risposte giuste. Le domande sbagliate torneranno più spesso.`}</p>
      <div class="esito-dati"><span>${ic('orologio')} ${mmss(Q.esito?.durata ?? durata)}</span><span>${ic('check')} ${giuste} giuste</span><span>${ic('x')} ${tot - giuste} da rivedere</span></div>
      <div class="azioni centro">
        <button class="btn secondario grande" data-azione="quiz-rivedi" data-k="${sbagliate.length ? sbagliate[0][1] : 0}">${ic('occhio')}Rivedi le risposte</button>
        <button class="btn primario grande" data-azione="quiz-nuovo">Nuovo quiz${ic('destra')}</button>
      </div>
      ${sbagliate.length ? `<div class="card elenco-sbagliate">
        <div class="etichetta-campo">Da rivedere</div>
        ${sbagliate.map(([q, i]) => `<button class="riga-sbagliata" data-azione="quiz-rivedi" data-k="${i}">
          <span class="num">${i + 1}</span>
          <span class="rs-testo"><span class="rs-domanda">${q.domanda.replace(/<[^>]+>/g, ' ').slice(0, 140)}</span>
          <span class="secondario">${esc(q.modulo ? nomeModulo(q.modulo) + ' · ' + titoloModulo(q.modulo) : 'Simulazione d\'esame')} · risposta ${Q.risposte[i] !== undefined ? 'ABCD'[Q.risposte[i]] : 'non data'}, corretta ${'ABCD'[q.giusta]}</span></span>
          ${ic('avanti')}</button>`).join('')}
      </div>` : ''}
    </div>`;
  animaAnelli(el);
}

/* =====================================================================
   ORALE
   ===================================================================== */
function oralePool() { return S.o.filtro === 'tutti' ? S.cat.orale : S.cat.orale.filter(o => o.modulo === +S.o.filtro); }
function oraleProssima() {
  const pool = oralePool(), po = S.prog.orale;
  if (!pool.length) return;
  const pesi = pool.map(o => (o.id === S.o.corrente?.id && pool.length > 1) ? 1e-4 : Math.pow(5 - (po[o.id]?.box || 0), 2));
  S.o.corrente = campionePesato(pool, pesi, 1)[0];
  S.o.mostrata = false;
  fermaTimerOrale();
  renderOrale();
}
function renderOrale() {
  const el = $('#v-orale');
  if (!S.o.corrente || (S.o.filtro !== 'tutti' && S.o.corrente.modulo !== +S.o.filtro)) { S.o.corrente = null; return oraleProssima(); }
  const o = S.o.corrente, po = S.prog.orale, box = po[o.id]?.box || 0;
  const sicure = S.cat.orale.filter(x => (po[x.id]?.box || 0) >= 3).length;
  const moduli = S.moduli.filter(m => S.cat.orale.some(x => x.modulo === m));
  el.innerHTML = `
    <header class="testata riga">
      <div><div class="sopratitolo">Prova orale</div><h1>Orale</h1></div>
      <div class="testata-destra">
        <div class="selettore">${ic('giu')}<select data-cambia="orale-filtro">
          <option value="tutti">Tutti i moduli</option>
          ${moduli.map(m => `<option value="${m}" ${String(m) === String(S.o.filtro) ? 'selected' : ''}>Modulo ${m} · ${esc(titoloModulo(m))}</option>`).join('')}
        </select></div>
        <span class="pill">${sicure} di ${S.cat.orale.length} sicure</span>
      </div>
    </header>
    <div class="card flashcard">
      <div class="flash-testa">
        <span class="sopratitolo accento">${esc(nomeModulo(o.modulo))} · ${esc(titoloModulo(o.modulo))}</span>
        <span class="livello" title="Livello ${box} di 4">${[1, 2, 3, 4].map(i => `<i class="${i <= box ? 'on' : ''}"></i>`).join('')}</span>
      </div>
      <h2 class="flash-domanda">${o.domanda}</h2>
      <p class="secondario metodo">Rispondi <b>ad alta voce</b>, prima di guardare: una frase di definizione, un esempio o un disegno, perché serve.</p>
      <div class="flash-azioni" ${S.o.mostrata ? 'hidden' : ''}>
        <button class="btn secondario timer-orale" data-azione="orale-timer" id="orale-timer">
          <svg viewBox="0 0 36 36" class="mini-anello"><circle cx="18" cy="18" r="15" class="binario"/><circle cx="18" cy="18" r="15" class="avanz" id="orale-arco"/></svg>
          <span id="orale-timer-testo">Cronometro 90 s</span></button>
        <button class="btn primario" data-azione="orale-mostra">${ic('occhio')}Mostra la risposta <kbd>Spazio</kbd></button>
      </div>
      <div class="flash-risposta testo-ricco" ${S.o.mostrata ? '' : 'hidden'}>${o.risposta}</div>
      <div class="flash-valuta" ${S.o.mostrata ? '' : 'hidden'}>
        <span class="secondario">Com'è andata?</span>
        <button class="btn valuta rosso" data-azione="orale-valuta" data-v="0">Non la sapevo <kbd>1</kbd></button>
        <button class="btn valuta arancio" data-azione="orale-valuta" data-v="1">In parte <kbd>2</kbd></button>
        <button class="btn valuta verde" data-azione="orale-valuta" data-v="2">La sapevo <kbd>3</kbd></button>
      </div>
    </div>
    <div class="orale-piede"><button class="btn fantasma" data-azione="orale-salta">Salta questa domanda ${ic('destra')}</button></div>`;
  evidenziaBlocchi(el);
}
function oraleMostra() {
  if (S.o.mostrata) return;
  S.o.mostrata = true; fermaTimerOrale();
  const el = $('#v-orale');
  $('.flash-azioni', el).hidden = true;
  $('.flash-risposta', el).hidden = false;
  $('.flash-valuta', el).hidden = false;
  $('.flash-risposta', el).classList.add('appare');
}
function oraleValuta(v) {
  const o = S.o.corrente, po = S.prog.orale;
  const s = po[o.id] || (po[o.id] = { box: 0, n: 0 });
  s.box = v === 0 ? 0 : v === 1 ? Math.min(s.box || 0, 2) : Math.min(4, (s.box || 0) + 1);
  s.n = (s.n || 0) + 1; s.data = oggiISO();
  Gioco.registra(S.prog, 'o');
  S.bit?.reagisci(v === 2 ? 'oraleAlta' : 'oraleBassa', { m: titoloModulo(o.modulo) });
  salvaProgressi();
  oraleProssima();
}
function oraleTimer() {
  if (S.o.timer) return fermaTimerOrale();
  const fine = Date.now() + 90000, arco = $('#orale-arco'), C = 2 * Math.PI * 15;
  arco.style.strokeDasharray = C;
  const tick = () => {
    const r = (fine - Date.now()) / 1000;
    const t = $('#orale-timer-testo'); if (!t) return fermaTimerOrale();
    if (r <= 0) { t.textContent = 'Tempo! Ora guarda la risposta'; fermaTimerOrale(true); return; }
    t.textContent = `${Math.ceil(r)} s`;
    arco.style.strokeDashoffset = C * (1 - r / 90);
  };
  tick(); S.o.timer = setInterval(tick, 250);
}
function fermaTimerOrale(tieniTesto) {
  clearInterval(S.o.timer); S.o.timer = null;
  if (!tieniTesto) { const t = $('#orale-timer-testo'); if (t) t.textContent = 'Cronometro 90 s'; const a = $('#orale-arco'); if (a) a.style.strokeDashoffset = 0; }
}

/* =====================================================================
   EVIDENZIATORE C++ (stile Xcode)
   ===================================================================== */
const KW = new Set(('alignas alignof and asm auto bool break case catch char class const constexpr const_cast continue decltype default delete do double ' +
  'dynamic_cast else enum explicit export extern false float for friend goto if inline int long mutable namespace new noexcept not nullptr operator or ' +
  'private protected public register reinterpret_cast return short signed sizeof static static_assert static_cast struct switch template this throw true ' +
  'try typedef typeid typename union unsigned using virtual void volatile while override final').split(' '));
const STD = new Set(('std string size_t ostream istream cout cin cerr endl exception runtime_error out_of_range underflow_error overflow_error ' +
  'invalid_argument logic_error bad_cast stringstream istringstream ostringstream ifstream ofstream fstream getline srand rand time swap max min').split(' '));
const RE_CPP = /(\/\/[^\n]*|\/\*[\s\S]*?(?:\*\/|$))|("(?:\\.|[^"\\\n])*"?|'(?:\\.|[^'\\\n])*'?)|(^[ \t]*#[^\n]*)|(\b\d[\w.']*)|([A-Za-z_]\w*)/gm;
function cpp(src) {
  let out = '', ultimo = 0, m;
  RE_CPP.lastIndex = 0;
  while ((m = RE_CPP.exec(src))) {
    if (!m[0]) { RE_CPP.lastIndex++; continue; }
    out += esc(src.slice(ultimo, m.index));
    const t = m[0];
    let c = '';
    if (m[1]) c = 'c-com';
    else if (m[2]) c = 'c-str';
    else if (m[3]) c = 'c-pre';
    else if (m[4]) c = 'c-num';
    else if (KW.has(t)) c = 'c-kw';
    else if (STD.has(t)) c = 'c-std';
    else if (/^[A-Z]/.test(t)) c = 'c-tipo';
    else if (/^\s*\(/.test(src.slice(RE_CPP.lastIndex, RE_CPP.lastIndex + 3))) c = 'c-fn';
    if (c === 'c-pre') {
      const r = esc(t).replace(/(&lt;[^&]*&gt;|"[^"]*")/, '<span class="c-str">$1</span>');
      out += `<span class="c-pre">${r}</span>`;
    } else out += c ? `<span class="${c}">${esc(t)}</span>` : esc(t);
    ultimo = RE_CPP.lastIndex;
  }
  return out + esc(src.slice(ultimo));
}
function evidenziaBlocchi(r) { $$('pre.cpp:not(.fatto)', r).forEach(p => { p.innerHTML = cpp(p.textContent); p.classList.add('fatto'); }); }

/* =====================================================================
   EDITOR (textarea + strato evidenziato)
   ===================================================================== */
class Editor {
  constructor(el, { onCambio, onEsegui, onSalva }) {
    this.el = el; this.onCambio = onCambio; this.onEsegui = onEsegui; this.onSalva = onSalva;
    el.innerHTML = `<div class="ed-numeri"><div class="ed-numeri-int"></div></div>
      <div class="ed-area"><div class="ed-strato"><div class="ed-riga-attiva"></div><div class="ed-errori"></div></div>
      <pre class="ed-hl" aria-hidden="true"><code></code></pre>
      <textarea class="ed-testo" spellcheck="false" autocapitalize="off" autocomplete="off" autocorrect="off" wrap="off"></textarea></div>`;
    this.ta = $('textarea', el); this.hl = $('code', el); this.pre = $('pre', el);
    this.num = $('.ed-numeri-int', el); this.strato = $('.ed-strato', el); this.attiva = $('.ed-riga-attiva', el);
    this.erroriEl = $('.ed-errori', el); this.errori = new Map(); this.nRighe = 0;
    this.LH = 22; this.PT = 16;
    this.ta.addEventListener('input', () => { this.disegna(); this.onCambio?.(); });
    this.ta.addEventListener('scroll', () => this.scorri());
    this.ta.addEventListener('keydown', e => this.tasto(e));
    for (const ev of ['click', 'keyup', 'focus']) this.ta.addEventListener(ev, () => this.rigaAttiva());
    this.ta.addEventListener('blur', () => this.attiva.classList.remove('vis'));
  }
  get valore() { return this.ta.value; }
  set valore(v) { this.ta.value = v; this.ta.setSelectionRange(0, 0); this.errori.clear(); this.disegna(); this.ta.scrollTop = 0; this.ta.scrollLeft = 0; this.scorri(); }
  disegna() {
    const v = this.ta.value;
    this.hl.innerHTML = cpp(v) + '\n ';
    const n = v.split('\n').length;
    if (n !== this.nRighe || this._numSporco) {
      this.nRighe = n; this._numSporco = false;
      let s = '';
      for (let i = 1; i <= n; i++) s += `<div class="${this.errori.has(i) ? 'err ' + this.errori.get(i) : ''}">${i}</div>`;
      this.num.innerHTML = s;
    }
    this.rigaAttiva(); this.scorri();
  }
  scorri() {
    const t = this.ta.scrollTop, l = this.ta.scrollLeft;
    this.pre.scrollTop = t; this.pre.scrollLeft = l;
    this.num.style.transform = `translateY(${-t}px)`;
    this.strato.style.transform = `translateY(${-t}px)`;
  }
  rigaAttiva() {
    if (document.activeElement !== this.ta) return;
    const riga = this.ta.value.slice(0, this.ta.selectionStart).split('\n').length;
    this.attiva.style.top = (this.PT + (riga - 1) * this.LH) + 'px';
    this.attiva.classList.add('vis');
  }
  segnaErrori(diag) {
    this.errori.clear();
    for (const d of diag || []) if (!this.errori.has(d.riga) || d.tipo === 'errore') this.errori.set(d.riga, d.tipo === 'errore' ? 'errore' : 'avviso');
    this.erroriEl.innerHTML = [...this.errori].map(([r, t]) => `<div class="ed-err ${t}" style="top:${this.PT + (r - 1) * this.LH}px"></div>`).join('');
    this._numSporco = true; this.disegna();
  }
  vaiARiga(r) {
    const righe = this.ta.value.split('\n');
    r = Math.max(1, Math.min(r, righe.length));
    let pos = 0; for (let i = 0; i < r - 1; i++) pos += righe[i].length + 1;
    this.ta.focus();
    this.ta.setSelectionRange(pos + (righe[r - 1].match(/^\s*/)[0].length), pos + righe[r - 1].length);
    this.ta.scrollTop = Math.max(0, (r - 1) * this.LH - this.ta.clientHeight / 2);
    this.rigaAttiva();
  }
  inserisci(t) { document.execCommand('insertText', false, t); }
  righeSelezionate() {
    const v = this.ta.value, a = this.ta.selectionStart, b = this.ta.selectionEnd;
    const ini = v.lastIndexOf('\n', a - 1) + 1;
    let fin = v.indexOf('\n', b - (b > a && v[b - 1] === '\n' ? 1 : 0)); if (fin < 0) fin = v.length;
    return { ini, fin, testo: v.slice(ini, fin) };
  }
  sostituisciRighe(fn) {
    const { ini, fin, testo } = this.righeSelezionate();
    const nuovo = testo.split('\n').map(fn).join('\n');
    this.ta.setSelectionRange(ini, fin); this.inserisci(nuovo);
    this.ta.setSelectionRange(ini, ini + nuovo.length);
  }
  tasto(e) {
    const ta = this.ta, ctrl = e.ctrlKey || e.metaKey;
    if ((ctrl && e.key === 'Enter') || e.key === 'F5') { e.preventDefault(); return this.onEsegui?.(); }
    if (ctrl && e.key.toLowerCase() === 's') { e.preventDefault(); return this.onSalva?.(); }
    if (ctrl && (e.key === '/' || e.code === 'Slash' || e.key === '7' && e.shiftKey)) {
      e.preventDefault();
      const { testo } = this.righeSelezionate();
      const righe = testo.split('\n').filter(r => r.trim());
      const tutte = righe.length && righe.every(r => /^\s*\/\//.test(r));
      const rient = Math.min(...righe.map(r => r.match(/^\s*/)[0].length), 99);
      return this.sostituisciRighe(r => !r.trim() ? r : tutte ? r.replace(/^(\s*)\/\/ ?/, '$1') : r.slice(0, rient) + '// ' + r.slice(rient));
    }
    if (e.key === 'Tab') {
      e.preventDefault();
      if (e.shiftKey) return this.sostituisciRighe(r => r.replace(/^ {1,4}|^\t/, ''));
      if (ta.selectionStart !== ta.selectionEnd && ta.value.slice(ta.selectionStart, ta.selectionEnd).includes('\n'))
        return this.sostituisciRighe(r => '    ' + r);
      return this.inserisci('    ');
    }
    if (e.key === 'Enter' && !ctrl && !e.shiftKey && !e.altKey) {
      e.preventDefault();
      const v = ta.value, s = ta.selectionStart;
      const ini = v.lastIndexOf('\n', s - 1) + 1;
      let rient = v.slice(ini, s).match(/^[ \t]*/)[0];
      const prima = v.slice(ini, s).trimEnd();
      if (prima.endsWith('{')) {
        if (v[ta.selectionEnd] === '}') {
          this.inserisci('\n' + rient + '    \n' + rient);
          const p = s + 1 + rient.length + 4; ta.setSelectionRange(p, p); this.rigaAttiva(); return;
        }
        rient += '    ';
      }
      return this.inserisci('\n' + rient);
    }
    if (e.key === '}' && ta.selectionStart === ta.selectionEnd) {
      const v = ta.value, s = ta.selectionStart, ini = v.lastIndexOf('\n', s - 1) + 1;
      if (/^ {4,}$/.test(v.slice(ini, s))) { e.preventDefault(); ta.setSelectionRange(s - 4, s); this.inserisci('}'); }
    }
  }
}

/* =====================================================================
   CODICE
   ===================================================================== */
const MODELLO = t => `// ${t}\n#include <iostream>\nusing namespace std;\n\nint main() {\n    \n    return 0;\n}\n`;
const statoEs = id => { const s = S.prog.esercizi[id] || {}; return s.fatto ? 'fatto' : s.iniziato ? 'iniziato' : 'nuovo'; };
const ORDINE_TIPO = { esame: 0, lab: 1, pattern: 2, es: 3 };

function renderCodice() {
  const el = $('#v-codice');
  if (!S.c.costruito) {
    el.innerHTML = `
      <div class="codice">
        <aside class="elenco-es">
          <div class="elenco-testa">
            <div class="elenco-titolo"><h2>Codice</h2>
              <button class="btn icona piccolo secondario" data-azione="elenco-riduci" title="Nascondi l'elenco degli esercizi (Ctrl+E)">${ic('pannello')}</button></div>
            <label class="cerca">${ic('cerca')}<input id="es-cerca" placeholder="Cerca un esercizio" autocomplete="off"></label>
            <div class="segmentato piccolo pieno" id="es-filtro">
              <button data-azione="es-filtro" data-f="tutti" class="attivo">Tutti</button>
              <button data-azione="es-filtro" data-f="dafare">Da fare</button>
              <button data-azione="es-filtro" data-f="fatti">Fatti</button>
            </div>
          </div>
          <div class="lista-es" id="lista-es"></div>
        </aside>
        <div class="lavoro" id="lavoro"></div>
      </div>`;
    $('#es-cerca').addEventListener('input', e => { S.c.cerca = e.target.value.trim().toLowerCase(); disegnaLista(); });
    S.c.costruito = true;
    applicaPannelli();
    if (!S.c.id && S.imp.ultimo_esercizio && S.esPer[S.imp.ultimo_esercizio]) S.c.aperti.add(S.esPer[S.imp.ultimo_esercizio].modulo);
    disegnaLista();
    if (!S.c.id && S.imp.ultimo_esercizio && S.esPer[S.imp.ultimo_esercizio]) apriEsercizio(S.imp.ultimo_esercizio);
    else if (!S.c.id) disegnaVuoto();
  } else disegnaLista();
}

function disegnaVuoto() {
  $('#lavoro').innerHTML = `<div class="vuoto">
    <div class="vuoto-icona">${ic('codice')}</div>
    <h2>Scegli un esercizio</h2>
    <p class="secondario">Ogni modulo ha il pattern da riscrivere a memoria, il laboratorio a step e dieci esercizi.
    Scrivi, premi <kbd>Ctrl</kbd> <kbd>↵</kbd> per compilare con g++ come in laboratorio, poi confronta il tuo output con quello della soluzione.</p>
    <div class="azioni centro"><button class="btn primario" data-azione="codice-apri" data-id="esame-lab">${ic('orologio')}Simulazione d'esame</button>
    ${(() => { const l = S.cat.esercizi.find(e => e.tipo === 'lab' && !S.prog.esercizi[e.id]?.fatto); return l ? `<button class="btn secondario" data-azione="codice-apri" data-id="${l.id}">Prossimo laboratorio</button>` : ''; })()}</div>
    ${S.gpp ? '' : `<div class="banner">${ic('attenzione')} Non trovo il compilatore g++: installa MSYS2/MinGW e riavvia l'app.</div>`}
  </div>`;
}

function disegnaLista() {
  const pe = S.prog.esercizi, f = S.c.filtro, cerca = S.c.cerca;
  const gruppi = S.moduli.map(m => {
    let es = S.cat.esercizi.filter(e => e.modulo === m)
      .sort((a, b) => ORDINE_TIPO[a.tipo] - ORDINE_TIPO[b.tipo] || (a.numero || 0) - (b.numero || 0));
    const tot = es.length, fatti = es.filter(e => pe[e.id]?.fatto).length;
    if (f === 'dafare') es = es.filter(e => !pe[e.id]?.fatto);
    if (f === 'fatti') es = es.filter(e => pe[e.id]?.fatto);
    if (cerca) es = es.filter(e => (e.titolo + ' ' + titoloModulo(m) + ' modulo ' + m).toLowerCase().includes(cerca));
    return { m, es, tot, fatti };
  }).filter(g => g.es.length);
  $('#lista-es').innerHTML = gruppi.map(({ m, es, tot, fatti }) => {
    const aperto = S.c.aperti.has(m) || !!cerca;
    return `<div class="gruppo ${aperto ? 'aperto' : ''}">
      <button class="gruppo-testa" data-azione="es-gruppo" data-m="${m}">
        ${ic('avanti', 'freccia')}<span class="gruppo-nome">${m ? `<b>M${m}</b> ${esc(titoloModulo(m))}` : `<b>${ic('orologio')}</b> Simulazione d'esame`}</span>
        <span class="gruppo-conta">${fatti}/${tot}</span></button>
      <div class="gruppo-voci">${es.map(e => {
        const st = statoEs(e.id);
        const titolo = e.tipo === 'es' ? `${e.numero}. ${e.titolo}` : e.titolo;
        return `<button class="voce-es ${e.id === S.c.id ? 'sel' : ''}" data-azione="codice-apri" data-id="${e.id}">
          <span class="stato ${st}">${st === 'fatto' ? ic('check') : ''}</span>
          <span class="voce-titolo">${esc(titolo)}</span>
          <span class="tag ${esc(e.difficolta)}">${esc(e.difficolta)}</span></button>`;
      }).join('')}</div></div>`;
  }).join('') || '<p class="secondario vuoto-lista">Nessun esercizio trovato.</p>';
}

async function apriEsercizio(id) {
  const e = S.esPer[id];
  if (!e) return;
  if (S.c.id === id) return;
  await salvaCodice();
  S.c.id = id; S.c.ultimo = null; S.c.scheda = 'output'; S.c.sporco = false; S.c.confronto = null;
  S.c.aperti.add(e.modulo);
  azzeraCrono();
  salvaImp({ ultimo_esercizio: id });
  disegnaLista();
  $('.voce-es.sel')?.scrollIntoView({ block: 'nearest' });
  const intestazione = e.tipo === 'es' ? `${nomeModulo(e.modulo)} · Esercizio ${e.numero}` : `${nomeModulo(e.modulo)} · ${ETICHETTE_TIPO[e.tipo]}`;
  const fatto = !!S.prog.esercizi[id]?.fatto;
  $('#lavoro').innerHTML = `
    <header class="lavoro-testa">
      <button class="btn icona piccolo secondario mostra-elenco" data-azione="elenco-riduci" id="mostra-elenco">${ic('pannello')}</button>
      <div class="lavoro-titoli">
        <div class="sopratitolo">${esc(intestazione)}</div>
        <h2>${esc(e.titolo)} <span class="tag ${esc(e.difficolta)}">${esc(e.difficolta)}</span></h2>
      </div>
      <div class="lavoro-azioni">
        <button class="pill crono" data-azione="crono" id="crono" title="Cronometro">${ic('orologio')}<span id="crono-testo">00:00</span></button>
        <button class="btn secondario piccolo" data-azione="soluzione">${ic('libro')}Soluzione</button>
        <button class="btn piccolo ${fatto ? 'fatto' : 'secondario'}" data-azione="es-fatto" id="bottone-fatto">${ic('check')}${fatto ? 'Completato' : 'Segna come fatto'}</button>
        <button class="btn icona piccolo secondario" data-azione="ricomincia" title="Ricomincia da zero">${ic('ricomincia')}</button>
      </div>
    </header>
    <div class="traccia ${S.c.tracciaAperta ? 'aperta' : ''}" id="traccia">
      <div class="traccia-corpo testo-ricco">${e.testo}</div>
      <button class="traccia-interruttore" data-azione="traccia">${ic('giu')}<span>${S.c.tracciaAperta ? 'Riduci' : 'Mostra tutta la traccia'}</span></button>
    </div>
    <div class="editor-card">
      <div class="editor-barra">
        <span class="file">${ic('codice')}${esc(id)}.cpp<i class="pallino" id="pallino" hidden></i></span>
        <span class="spazio"></span>
        <button class="btn secondario piccolo" data-azione="vscode-apri" title="Apri questo esercizio in VS Code, con la consegna scritta in commento">${ic('terminale')}Apri in VS Code</button>
        <button class="btn secondario piccolo" data-azione="vscode-importa" title="Copia qui il codice che hai scritto in VS Code (Ctrl+I)">${ic('salva')}Importa da VS Code</button>
        <span class="tasti"><kbd>Ctrl</kbd><kbd>↵</kbd></span>
        <button class="btn primario piccolo" data-azione="esegui" id="bottone-esegui">${ic('play')}Esegui</button>
      </div>
      <div class="editor" id="editor"></div>
    </div>
    <div class="maniglia" id="maniglia" title="Trascina per ridimensionare"><i></i></div>
    <div class="console" id="console">
      <div class="console-barra">
        <div class="segmentato piccolo" id="console-schede">
          <button data-azione="scheda" data-s="output">Output</button>
          <button data-azione="scheda" data-s="input">Input</button>
          <button data-azione="scheda" data-s="confronto">Confronto</button>
        </div>
        <span class="spazio"></span>
        <span id="console-stato"></span>
      </div>
      <div class="console-corpo" id="console-corpo"></div>
    </div>`;
  evidenziaBlocchi($('#lavoro'));
  sistemaTraccia();
  S.c.editor = new Editor($('#editor'), {
    onCambio: () => { S.c.sporco = true; $('#pallino').hidden = false; clearTimeout(S.c.tAuto); S.c.tAuto = setTimeout(() => salvaCodice(), 900); },
    onEsegui: () => esegui(), onSalva: () => salvaCodice(true),
  });
  const salvato = await api().leggi_codice(id);
  if (S.c.id !== id) return;
  S.c.editor.valore = salvato ?? MODELLO(e.titolo);
  S.c.input = e.soluzione.input || '';
  attivaManiglia();
  disegnaConsole();
  setTimeout(() => S.c.editor?.ta.focus(), 50);
}

function sistemaTraccia() {
  const t = $('#traccia'), c = $('.traccia-corpo', t);
  const lunga = c.scrollHeight > 170;
  t.classList.toggle('corta', !lunga);
}

async function salvaCodice(conAvviso) {
  if (!S.c.id || !S.c.editor) return;
  clearTimeout(S.c.tAuto);
  const e = S.esPer[S.c.id], codice = S.c.editor.valore;
  if (!S.c.sporco && !conAvviso) return;
  if (codice.trim() === MODELLO(e.titolo).trim() && !conAvviso) return;
  await api().salva_codice(S.c.id, codice);
  S.c.sporco = false;
  const p = $('#pallino'); if (p) p.hidden = true;
  const st = S.prog.esercizi[S.c.id] || (S.prog.esercizi[S.c.id] = {});
  if (!st.iniziato) { st.iniziato = true; salvaProgressi(); disegnaLista(); }
  if (conAvviso) avviso('Salvato', 'ok');
}

async function esegui() {
  if (!S.c.id || S.c.inCorso) return;
  const e = S.esPer[S.c.id];
  S.c.inCorso = true;
  const b = $('#bottone-esegui');
  b.disabled = true; b.innerHTML = `<span class="rotella"></span>Compilazione…`;
  $('#console-stato').innerHTML = '';
  S.c.scheda = 'output';
  $('#console-corpo').innerHTML = `<div class="console-attesa"><span class="rotella grande"></span><span>Compilo con g++ -Wall -Wextra…</span></div>`;
  segnaSchede();
  const codice = S.c.editor.valore;
  S.c.sporco = true;
  let r;
  try { r = await api().esegui(S.c.id, codice, S.c.input || '', (e.tipo === 'lab' || e.tipo === 'esame') ? 20 : 10); }
  catch (err) { r = { compilato: false, diagnostica: [], messaggi: String(err) }; }
  S.c.inCorso = false; S.c.sporco = false; $('#pallino') && ($('#pallino').hidden = true);
  const st = S.prog.esercizi[S.c.id] || (S.prog.esercizi[S.c.id] = {});
  if (!st.iniziato) { st.iniziato = true; salvaProgressi(); disegnaLista(); }
  if (S.esPer[S.c.id] !== e) return;
  b.disabled = false; b.innerHTML = `${ic('play')}Esegui`;
  S.c.ultimo = r; S.c.confronto = null;
  S.c.editor.segnaErrori(r.diagnostica);
  disegnaConsole();
  if (!r.senza_compilatore) S.bit?.reagisci(!r.compilato ? 'compilaErrore' : (r.nota || r.uscita !== 0) ? 'crash'
    : (r.diagnostica || []).some(d => d.tipo === 'avviso') ? 'compilaAvvisi' : 'compilaOk');
}

function segnaSchede() { $$('#console-schede button').forEach(b => b.classList.toggle('attivo', b.dataset.s === S.c.scheda)); }

function disegnaConsole() {
  segnaSchede();
  const corpo = $('#console-corpo'), stato = $('#console-stato'), r = S.c.ultimo, e = S.esPer[S.c.id];
  if (!corpo) return;
  if (S.c.scheda === 'input') {
    corpo.innerHTML = `<div class="console-input"><div class="secondario piccola">Quello che scriveresti da tastiera mentre il programma gira. ${e.soluzione.input ? 'È già pronto l\'input di prova della dispensa.' : ''}</div>
      <textarea id="campo-input" spellcheck="false" placeholder="Nessun input">${esc(S.c.input || '')}</textarea></div>`;
    $('#campo-input').addEventListener('input', ev => { S.c.input = ev.target.value; });
    return;
  }
  if (S.c.scheda === 'confronto') return disegnaConfronto();
  if (!r) {
    stato.innerHTML = '';
    corpo.innerHTML = `<div class="console-attesa">${ic('terminale')}<span>Premi <b>Esegui</b> o <kbd>Ctrl</kbd><kbd>↵</kbd> per compilare con g++ ed eseguire.</span></div>`;
    return;
  }
  const errori = (r.diagnostica || []).filter(d => d.tipo === 'errore'), avvisi = (r.diagnostica || []).filter(d => d.tipo === 'avviso');
  const diagRiga = d => `<button class="diag ${d.tipo}" data-azione="vai-riga" data-r="${d.riga}"><span class="diag-riga">Riga ${d.riga}</span><span class="diag-testo">${esc(d.testo)}</span>${ic('avanti')}</button>`;
  if (!r.compilato) {
    stato.innerHTML = `<span class="pill no">${ic('x')}${r.senza_compilatore ? 'Compilatore assente' : 'Non compila'}</span>`;
    corpo.innerHTML = `
      ${errori.length ? `<div class="suggerimento">Correggi il <b>primo</b> errore e ricompila: spesso gli altri spariscono da soli.</div>
        <div class="diag-lista">${errori.slice(0, 12).map(diagRiga).join('')}</div>` : ''}
      <details ${errori.length ? '' : 'open'}><summary>Messaggio completo del compilatore</summary><pre class="uscita">${esc(r.messaggi)}</pre></details>`;
    return;
  }
  const okUscita = r.uscita === 0 && !r.nota;
  stato.innerHTML = `<span class="pill ${okUscita ? 'ok' : 'no'}">${okUscita ? ic('check') : ic('attenzione')}${okUscita ? 'Eseguito' : 'Problema in esecuzione'}</span>
    <span class="secondario piccola">compilato in ${String(r.tempo_compilazione).replace('.', ',')} s${r.tempo_esecuzione !== undefined ? ` · eseguito in ${String(r.tempo_esecuzione).replace('.', ',')} s` : ''}</span>
    ${e.soluzione.output ? `<button class="btn secondario piccolo" data-azione="scheda" data-s="confronto">${ic('confronta')}Confronta</button>` : ''}`;
  corpo.innerHTML = `
    ${r.nota ? `<div class="banner errore">${ic('attenzione')}<span>${esc(r.nota)}</span></div>` : ''}
    ${avvisi.length ? `<details class="avvisi-comp"><summary>${plur(avvisi.length, 'avviso', 'avvisi')} del compilatore (warning): leggili, spesso indicano un errore vero</summary>
      <div class="diag-lista">${avvisi.slice(0, 12).map(diagRiga).join('')}</div></details>` : ''}
    <pre class="uscita">${r.stdout ? esc(r.stdout) : '<span class="secondario">(il programma non ha stampato nulla)</span>'}</pre>
    ${r.stderr ? `<div class="etichetta-campo">Messaggi su cerr</div><pre class="uscita rosso">${esc(r.stderr)}</pre>` : ''}`;
}

async function disegnaConfronto() {
  const corpo = $('#console-corpo'), e = S.esPer[S.c.id], r = S.c.ultimo;
  if (!e.soluzione.output) { corpo.innerHTML = `<div class="console-attesa">${ic('confronta')}<span>Per questo esercizio non c'è un output di riferimento: controlla tu che il programma faccia quello che chiede la traccia.</span></div>`; return; }
  if (!r || !r.compilato) { corpo.innerHTML = `<div class="console-attesa">${ic('confronta')}<span>Prima esegui il programma, poi confronto il tuo output con quello della soluzione.</span></div>`; return; }
  if (!S.c.confronto) {
    S.c.confronto = await api().confronta(e.soluzione.output, r.stdout || '');
    S.bit?.reagisci(S.c.confronto.uguale ? 'diffOk' : 'diffNo');
  }
  const c = S.c.confronto;
  if (S.c.scheda !== 'confronto') return;
  if (c.uguale) {
    corpo.innerHTML = `<div class="confronto-ok">${ic('check')}<div><b>Identico all'output della soluzione.</b><div class="secondario">Se l'hai scritto da solo, segna l'esercizio come fatto.</div></div>
      ${S.prog.esercizi[S.c.id]?.fatto ? '' : `<button class="btn primario piccolo" data-azione="es-fatto">Segna come fatto</button>`}</div>`;
    return;
  }
  corpo.innerHTML = `<div class="legenda-diff"><span class="leg meno">− atteso, non stampato</span><span class="leg piu">+ stampato, non atteso</span></div><div class="suggerimento">Non sempre è un errore: frasi o spazi diversi vanno bene se la traccia non li impone. Con <code>rand()</code> o <code>typeid</code> l'output può cambiare.</div>
    <div class="diff">${c.righe.map(x => `<div class="d ${x.tipo}"><span class="d-segno">${x.tipo === 'meno' ? '−' : x.tipo === 'piu' ? '+' : ''}</span><span>${esc(x.testo) || ' '}</span></div>`).join('')}</div>`;
}

function attivaManiglia() {
  const m = $('#maniglia'), lav = $('#lavoro');
  const h = S.imp.altezza_console || 240;
  lav.style.setProperty('--h-console', h + 'px');
  m.onmousedown = ev => {
    ev.preventDefault();
    const r = lav.getBoundingClientRect();
    document.body.classList.add('trascina');
    const muovi = e => { const nh = Math.max(120, Math.min(r.bottom - e.clientY - 20, r.height * 0.65)); lav.style.setProperty('--h-console', nh + 'px'); S.c._h = nh; };
    const su = () => { document.removeEventListener('mousemove', muovi); document.removeEventListener('mouseup', su); document.body.classList.remove('trascina'); if (S.c._h) salvaImp({ altezza_console: Math.round(S.c._h) }); };
    document.addEventListener('mousemove', muovi); document.addEventListener('mouseup', su);
  };
}

function azzeraCrono() { clearInterval(S.c.crono.id); S.c.crono = { inizio: null, acc: 0, id: null }; }
function crono() {
  const c = S.c.crono, b = $('#crono');
  if (c.inizio) { c.acc += (Date.now() - c.inizio) / 1000; c.inizio = null; clearInterval(c.id); b.classList.remove('attivo'); return; }
  c.inizio = Date.now(); b.classList.add('attivo');
  const tick = () => { const t = $('#crono-testo'); if (t) t.textContent = mmss(c.acc + (Date.now() - c.inizio) / 1000); };
  tick(); c.id = setInterval(tick, 500);
}
const secondiCrono = () => S.c.crono.acc + (S.c.crono.inizio ? (Date.now() - S.c.crono.inizio) / 1000 : 0);

function esFatto() {
  const st = S.prog.esercizi[S.c.id] || (S.prog.esercizi[S.c.id] = {});
  st.fatto = !st.fatto;
  if (st.fatto) {
    st.data = oggiISO(); const s = secondiCrono(); if (s > 30) st.minuti = Math.round(s / 60); avviso('Completato. Ottimo lavoro.', 'ok');
    if (!st.contato) { st.contato = true; Gioco.registra(S.prog, 'e'); }   // una volta sola, anche se lo si toglie e rimette
  }
  salvaProgressi();
  const b = $('#bottone-fatto');
  if (b) { b.className = `btn piccolo ${st.fatto ? 'fatto' : 'secondario'}`; b.innerHTML = `${ic('check')}${st.fatto ? 'Completato' : 'Segna come fatto'}`; }
  disegnaLista();
  if (S.c.scheda === 'confronto') disegnaConfronto();
}

async function ricomincia() {
  if (!await chiedi({ titolo: 'Ricominciare da zero?', testo: 'Il tuo codice per questo esercizio verrà sostituito dal modello vuoto.', ok: 'Ricomincia', annulla: 'Annulla', pericolo: true })) return;
  const e = S.esPer[S.c.id];
  S.c.editor.valore = MODELLO(e.titolo);
  S.c.sporco = true; await salvaCodice();
  S.c.ultimo = null; disegnaConsole();
}

/* --- VS Code: la consegna in un file .cpp, il codice torna qui con «Importa» --- */
const SCHELETRO = '#include<iostream>usingnamespacestd;intmain(){return0;}';
async function vscodeApri() {
  if (!S.c.id) return;
  const r = await api().apri_vscode(S.c.id);
  if (r?.errore) return avviso(r.errore, 'errore');
  avviso('Aperto in VS Code: quando hai finito torna qui e premi «Importa da VS Code»', 'ok');
}
async function vscodeImporta() {
  if (!S.c.id || !S.c.editor) return;
  const id = S.c.id, r = await api().importa_vscode(id);
  if (S.c.id !== id) return;
  if (r?.errore) return avviso(r.errore + ' Premi prima «Apri in VS Code».', 'errore');
  if (r.codice.replace(/\s+/g, '') === SCHELETRO) return avviso('Il file in VS Code è ancora vuoto: hai salvato (Ctrl+S)?', 'errore');
  const attuale = S.c.editor.valore, e = S.esPer[id];
  if (attuale.trim() === r.codice.trim()) return avviso('Il codice è già uguale a quello di VS Code', 'ok');
  if (attuale.trim() && attuale.trim() !== MODELLO(e.titolo).trim() && !await chiedi({ titolo: 'Sostituire il codice?',
    testo: 'Il codice scritto qui verrà sostituito da quello del file di VS Code.', ok: 'Importa', annulla: 'Annulla' })) return;
  S.c.editor.valore = r.codice;
  S.c.sporco = true; await salvaCodice();
  S.c.ultimo = null; disegnaConsole();
  avviso('Codice importato da VS Code: premi Esegui', 'ok');
}
async function disegnaVscodeImp() {
  const el = $('#imp-vscode'); if (!el) return;
  const st = await api().stato_vscode();
  el.innerHTML = `<div class="secondario">Un file <code>.cpp</code> per ogni esercizio, con la consegna in commento in testa. In VS Code <kbd>Ctrl</kbd><kbd>Shift</kbd><kbd>B</kbd> compila ed esegue; poi qui premi «Importa da VS Code» nell'esercizio. I file che esistono già non vengono mai sovrascritti.</div>
    <div class="secondario" style="margin-top:8px">Cartella: <code>${esc(st.cartella)}</code>${st.esiste ? '' : ' (non ancora creata)'}${st.vscode ? '' : '<br>VS Code non trovato: la cartella si può creare lo stesso.'}</div>
    <div class="azioni"><button class="btn primario piccolo" data-azione="vscode-crea">${ic('terminale')}${st.esiste ? 'Aggiorna e apri in VS Code' : 'Crea la cartella e apri VS Code'}</button>
    <button class="btn secondario piccolo" data-azione="vscode-scegli">${ic('cartella')}Cambia cartella…</button></div>`;
}

async function mostraSoluzione() {
  const e = S.esPer[S.c.id], st = S.prog.esercizi[S.c.id] || (S.prog.esercizi[S.c.id] = {});
  if (!st.visto && !await chiedi({ titolo: 'Vuoi vedere la soluzione?',
    testo: 'Bloccarsi e sbloccarsi da soli è l\'allenamento più utile per il laboratorio. Se hai provato davvero, guardala pure.',
    ok: 'Mostra la soluzione', annulla: 'Continuo a provare' })) return;
  st.visto = true; salvaProgressi();
  const sol = e.soluzione;
  const schede = sol.files.map(f => ({ nome: f.nome, testo: f.contenuto, codice: true }));
  if (sol.input) schede.push({ nome: 'Input di prova', testo: sol.input });
  if (sol.output) schede.push({ nome: 'Output atteso', testo: sol.output });
  for (const x of sol.altre_uscite || []) schede.push({ nome: x.nome, testo: x.contenuto });
  const vista = i => {
    const s = schede[i];
    const righe = s.testo.replace(/\n$/, '').split('\n');
    return `<div class="visore"><div class="visore-num">${righe.map((_, k) => k + 1).join('<br>')}</div>
      <pre class="visore-codice">${s.codice ? cpp(s.testo.replace(/\n$/, '')) : esc(s.testo.replace(/\n$/, ''))}</pre></div>`;
  };
  apriFoglio(`
    <div class="foglio-testa"><div><div class="sopratitolo">Soluzione</div><h2>${esc(e.titolo)}</h2></div>
      <button class="btn icona secondario" data-azione="chiudi-foglio" title="Chiudi">${ic('x')}</button></div>
    ${sol.commento ? `<div class="testo-ricco soluzione-commento">${sol.commento}</div>` : ''}
    <div class="segmentato piccolo" id="sol-schede">${schede.map((s, i) => `<button class="${i ? '' : 'attivo'}" data-i="${i}">${esc(s.nome)}</button>`).join('')}</div>
    <div class="sol-corpo" id="sol-corpo">${vista(0)}</div>`, 'largo');
  $('#sol-schede').onclick = ev => {
    const b = ev.target.closest('button'); if (!b) return;
    $$('#sol-schede button').forEach(x => x.classList.toggle('attivo', x === b));
    $('#sol-corpo').innerHTML = vista(+b.dataset.i);
  };
}

/* =====================================================================
   GIOCO: XP, livelli, missioni, traguardi e il compagno Bit
   (i calcoli sono in gioco.js, condiviso con il telefono)
   ===================================================================== */
function statoGioco() { return Gioco.calcola(S.prog, S.cat, { obiettivo: S.imp.obiettivo_xp || 300 }); }

/* dopo ogni salvataggio: XP guadagnati, livello nuovo, traguardi e missioni appena completati */
function aggiornaGioco() {
  const prima = S.gioco, dopo = statoGioco();
  S.gioco = dopo;
  if (prima) {
    const guadagno = dopo.xp - prima.xp;
    if (guadagno > 0) { xpVolante(guadagno); S.lettore?.effetto('xp'); setTimeout(saltaPet, 30); }
    const misPrima = prima.missioni.filter(m => m.fatto).length, misDopo = dopo.missioni.filter(m => m.fatto).length;
    if (misDopo > misPrima) { avviso(misDopo === 3 ? 'Tutte le missioni di oggi completate! +100 XP' : 'Missione completata: +40 XP', 'ok'); S.lettore?.effetto('missione'); }
    const nuovi = dopo.traguardi.filter(t => t.ok && !S.traguardiVisti.has(t.id));
    if (nuovi.length) {
      nuovi.forEach(t => S.traguardiVisti.add(t.id));
      salvaImp({ traguardi_visti: [...S.traguardiVisti] });
      setTimeout(() => { avviso('Traguardo sbloccato: ' + nuovi.map(t => t.nome).join(', '), 'ok'); S.lettore?.effetto('traguardo'); }, 700);
    }
    if (dopo.livello > prima.livello) setTimeout(() => livelloNuovo(dopo, prima), 900);
  }
  disegnaPetMini();
  if (S.vista === 'bit') renderBit();
  S.bit?.aggiorna();
}

function xpVolante(n) {
  const el = document.createElement('div');
  el.className = 'xp-volante'; el.textContent = `+${n} XP`;
  const r = ($('.btn.primario:not([disabled])', $('#v-' + S.vista)) || $('#pet-mini')).getBoundingClientRect();
  el.style.left = Math.max(10, r.left + r.width / 2 - 30) + 'px'; el.style.top = Math.max(10, r.top - 12) + 'px';
  document.body.appendChild(el);
  setTimeout(() => el.remove(), 1500);
}

function livelloNuovo(st, prima) {
  const pet = Gioco.pet(st, nomePet()), cambio = Gioco.pet(prima, nomePet()).indice !== pet.indice;
  const el = document.createElement('div');
  el.className = 'livello-nuovo';
  el.innerHTML = `<div class="ln-box">
    <div class="ln-sopra">LIVELLO RAGGIUNTO</div>
    <div class="ln-num">${st.livello}</div>
    <div class="ln-titolo">${esc(st.titolo)}</div>
    ${cambio ? `<div class="evoluzione">${svgPet(Gioco.pet(prima, nomePet()).indice, 'felice', 150, 'vecchio')}${svgPet(pet.indice, 'euforico', 150, 'nuovo')}<div class="lampo"></div></div>`
      : `<div class="evoluzione">${svgPet(pet.indice, 'euforico', 150)}</div>`}
    <div class="ln-nota">${cambio ? `${esc(pet.nome)} si è evoluto: ora è un <b>${esc(pet.stadio)}</b>. ${esc(pet.descr)}` : `${esc(pet.nome)} è fiero di te. Prossimo livello a ${st.prossimo} XP.`}</div>
    <div class="ln-chiudi">[ CLIC PER CONTINUARE ]</div></div>`;
  document.body.appendChild(el);
  S.lettore?.effetto('livello');
  const via = () => { el.remove(); removeEventListener('keydown', tasto, true); };
  const tasto = ev => { ev.preventDefault(); ev.stopPropagation(); via(); };
  el.onclick = via; addEventListener('keydown', tasto, true);
}

/* Bit in pixel art (gioco.js): il colore del corpo è il colore d'accento scelto */
const svgPet = (indice, umore, lato, classe = '') => Gioco.svgPet(indice, umore, { colore: S.imp?.accento || Gioco.COLORI[0][0], lato, classe });
/* salto di gioia quando arrivano XP */
function saltaPet() {
  $$('.pet-svg').forEach(el => { el.classList.remove('salta'); void el.getBoundingClientRect(); el.classList.add('salta'); setTimeout(() => el.classList.remove('salta'), 800); });
}
function disegnaPetMini() {
  const el = $('#pet-mini'); if (!el || !S.gioco) return;
  const st = S.gioco, pet = Gioco.pet(st, nomePet());
  el.innerHTML = `<button class="pet-mini" data-azione="vai" data-vista="bit" title="${esc(pet.nome)}: ${esc(Gioco.UMORI[pet.umore])}">
    ${svgPet(pet.indice, pet.umore, 44)}
    <span class="pm-testo"><span class="pm-livello">LV ${st.livello}</span> <span class="secondario">${st.xp - st.base}/${st.prossimo - st.base} XP</span>
      <div class="xp-barra sottile" style="margin:4px 0 3px"><i style="width:${percento(st.xp - st.base, st.prossimo - st.base)}%"></i></div>
      <div class="pm-sotto">${st.serie ? `serie ${st.serie} ${st.serie === 1 ? 'giorno' : 'giorni'}` : 'nessuna serie attiva'} · oggi ${st.xpOggi} XP</div></span></button>`;
}
function missioniHTML(st) {
  return `<div class="missioni">${st.missioni.map(m => `<div class="missione ${m.fatto ? 'fatta' : ''}">
    <span class="ms-casella">${m.fatto ? '[x]' : '[ ]'}</span><span class="ms-testo">${esc(m.t)}</span><span class="ms-conta">${m.valore}/${m.n}</span></div>`).join('')}</div>`;
}

function cartaBitOggi() {
  const st = S.gioco || statoGioco(), pet = Gioco.pet(st, nomePet());
  return `<div class="card bit-oggi">
    <button class="bit-oggi-pet" data-azione="vai" data-vista="bit" title="Apri la scheda di ${esc(pet.nome)}">
      ${svgPet(pet.indice, pet.umore, 118)}</button>
    <div class="bit-oggi-dati">
      <div class="sopratitolo">${esc(pet.nome)} · ${esc(pet.stadio)} · ${esc(Gioco.UMORI[pet.umore])}</div>
      <div class="bit-oggi-livello"><b>Livello ${st.livello}</b> <span class="secondario">${esc(st.titolo)}</span></div>
      <div class="xp-barra"><i style="width:${percento(st.xp - st.base, st.prossimo - st.base)}%"></i></div>
      <div class="secondario piccola" style="margin-top:6px">${st.xp} XP · mancano ${st.prossimo - st.xp} XP al livello ${st.livello + 1} · serie: ${st.serie} ${st.serie === 1 ? 'giorno' : 'giorni'}</div>
    </div>
    <div class="bit-oggi-missioni"><div class="card-titolo">Missioni di oggi</div>${missioniHTML(st)}</div>
  </div>`;
}

function renderBit() {
  const el = $('#v-bit');
  const st = S.gioco = S.gioco || statoGioco(), pet = Gioco.pet(st, nomePet());
  const ok = st.traguardi.filter(t => t.ok).length;
  const d = st.dettaglio;
  const voci = [['Quiz', d.quiz], ['Orale', d.orale], ['Esercizi', d.esercizi], ['Simulazioni', d.simulazioni], ['Prevedi l\'output', d.prevedi], ['Missioni', d.missioni]];
  el.innerHTML = `
    <header class="testata riga">
      <div><div class="sopratitolo">Il tuo compagno di studio</div><h1>${esc(pet.nome)}</h1></div>
      <div class="testata-destra"><button class="btn secondario piccolo" data-azione="rinomina-pet">Rinomina</button></div>
    </header>
    <div class="griglia-2">
      <div class="card bit-scheda">
        <div class="bit-palco">${svgPet(pet.indice, pet.umore, 220)}</div>
        <div class="pet-nuvola">${esc(pet.frase)}</div>
        <div class="bit-righe">
          <div><span class="secondario">Stadio</span><b>${esc(pet.stadio)}</b></div>
          <div><span class="secondario">Umore</span><b>${esc(Gioco.UMORI[pet.umore])}</b></div>
          <div><span class="secondario">Evoluzione</span><b>${pet.prossimo ? `${esc(pet.prossimo.nome)} al livello ${pet.prossimo.livello}` : 'forma finale'}</b></div>
        </div>
        <div class="etichetta-campo" style="margin-top:14px">Sazietà di oggi · ${st.xpOggi}/${st.obiettivo} XP</div>
        <div class="xp-barra cibo"><i style="width:${percento(Math.min(st.xpOggi, st.obiettivo), st.obiettivo)}%"></i></div>
        <p class="secondario piccola">${esc(pet.descr)} Si nutre degli XP che guadagni: se non studi per due giorni ha fame, dopo quattro si addormenta.</p>
      </div>
      <div class="card">
        <div class="card-titolo">Livello ${st.livello} · ${esc(st.titolo)}</div>
        <div class="bit-xp"><b>${st.xp}</b> XP <span class="secondario">· prossimo livello a ${st.prossimo}</span></div>
        <div class="xp-barra"><i style="width:${percento(st.xp - st.base, st.prossimo - st.base)}%"></i></div>
        <div class="bit-numeri">
          <div><b>${st.serie}</b><span>serie attuale</span></div>
          <div><b>${st.serieMax}</b><span>serie record</span></div>
          <div><b>${st.giorniStudio}</b><span>giorni di studio</span></div>
          <div><b>${ok}/${st.traguardi.length}</b><span>traguardi</span></div>
        </div>
        <div class="card-titolo" style="margin-top:18px">Missioni di oggi</div>
        ${missioniHTML(st)}
        <p class="secondario piccola" style="margin-top:10px">Ogni missione vale 40 XP, tutte e tre insieme altri 60. Cambiano a mezzanotte e sono le stesse sul telefono.</p>
        <div class="card-titolo" style="margin-top:18px">Da dove vengono i tuoi XP</div>
        <div class="bit-fonti">${voci.map(([n, v]) => `<div><span>${n}</span><i style="width:${percento(v, Math.max(1, ...voci.map(x => x[1])))}%"></i><b>${v}</b></div>`).join('')}</div>
      </div>
    </div>
    <div class="titolo-sezione"><h2>Traguardi</h2><span class="secondario">${ok} sbloccati su ${st.traguardi.length}.</span></div>
    <div class="traguardi">${st.traguardi.map(t => `<div class="traguardo ${t.ok ? 'ok' : ''}" title="${esc(t.descr)}">
      <div class="tg-icona">${esc(t.icona)}</div><div class="tg-nome">${esc(t.nome)}</div><div class="tg-descr">${esc(t.descr)}</div>
      ${t.prog && !t.ok ? `<div class="xp-barra sottile"><i style="width:${percento(t.prog[0], t.prog[1])}%"></i></div>` : ''}</div>`).join('')}</div>
    <div class="titolo-sezione"><h2>Come si guadagnano gli XP</h2></div>
    <div class="card"><div class="tabella-xp">
      <div><span>Risposta giusta al quiz</span><b>+10</b></div><div><span>Risposta sbagliata (ci hai provato)</span><b>+2</b></div>
      <div><span>Domanda d'orale ripassata</span><b>+3 / +15 per livello</b></div><div><span>Esercizio al PC completato</span><b>+60</b></div>
      <div><span>Pattern riscritto a memoria</span><b>+50</b></div><div><span>Laboratorio a step completato</span><b>+200</b></div>
      <div><span>Laboratorio della simulazione d'esame</span><b>+400</b></div><div><span>Simulazione del quiz</span><b>+5 a risposta, +150 se superata</b></div>
      <div><span>Output indovinato (telefono)</span><b>+25</b></div><div><span>Missione del giorno</span><b>+40</b></div>
    </div><p class="secondario piccola">Ogni domanda dà XP solo per i primi cinque tentativi: ripetere all'infinito la stessa domanda non serve, studiare cose nuove sì.</p></div>`;
}

/* ---------------------------------------------------------------- primo avvio */
function benvenuto() {
  const oggi = new Date(); oggi.setDate(oggi.getDate() + 30);
  apriFoglio(`
    <div class="foglio-testa"><div><div class="sopratitolo">Primo avvio</div><h2>Benvenuto nell'Allenatore</h2></div></div>
    <p class="secondario">Quiz, orale e laboratorio di Programmazione 2 in un'unica app, insieme alla dispensa. Bastano poche informazioni per personalizzarla (le cambi quando vuoi in Impostazioni).</p>
    <div class="impostazioni">
      <div class="imp-riga"><div><div class="imp-nome">Come ti chiami?</div><div class="secondario">Per il saluto e per l'intro.</div></div>
        <input class="campo" id="bv-nome" value="${esc(S.imp.nome || '')}" placeholder="Il tuo nome"></div>
      <div class="imp-riga"><div><div class="imp-nome">Data dell'appello</div><div class="secondario">Conto alla rovescia e piano di studio.</div></div>
        <input type="date" class="campo" id="bv-data" value="${esc(S.imp.data_esame || '')}"></div>
      <div class="imp-riga"><div><div class="imp-nome">Docente</div><div class="secondario">Facoltativo: compare nell'intestazione.</div></div>
        <input class="campo" id="bv-prof" value="${esc(S.imp.professore || '')}" placeholder="Cognome del docente"></div>
      <div class="imp-riga"><div><div class="imp-nome">Colore</div><div class="secondario">Il colore del terminale.</div></div>
        <div class="colori" id="bv-colori">${coloriHTML()}</div></div>
      <div class="imp-riga"><div><div class="imp-nome">Il tuo compagno</div><div class="secondario">Cresce con i tuoi XP. Dagli un nome.</div></div>
        <input class="campo" id="bv-pet" value="${esc(S.imp.nome_pet || '')}" placeholder="Bit"></div>
    </div>
    <div class="azioni" style="justify-content:flex-end"><button class="btn primario" id="bv-ok">Iniziamo ${ic('destra')}</button></div>`, 'medio');
  attivaColori('#bv-colori');
  $('#bv-ok').onclick = () => {
    salvaImp({ nome: $('#bv-nome').value.trim(), data_esame: $('#bv-data').value, professore: $('#bv-prof').value.trim(),
      nome_pet: $('#bv-pet').value.trim(), configurato: true });
    chiudiFoglio(); disegnaMenu(); aggiornaMini(); vai(S.vista);
    if (S.imp.musica_auto !== false && S.lettore.sorgente === 'colonna') S.lettore.play();
  };
  setTimeout(() => $('#bv-nome')?.focus(), 60);
}

function coloriHTML() {
  const att = (S.imp.accento || Gioco.COLORI[0][0]).toLowerCase();
  const preset = Gioco.COLORI.some(([c]) => c === att);
  return Gioco.COLORI.map(([c, n]) => `<button class="colore ${c === att ? 'attivo' : ''}" data-c="${c}" title="${n}" style="--c:${c}"></button>`).join('')
    + `<label class="colore libero ${preset ? '' : 'attivo'}" title="Scegli un colore" style="--c:${preset ? '#888' : att}"><input type="color" value="${preset ? '#33ff99' : att}"></label>`;
}
function attivaColori(sel) {
  const box = $(sel);
  const scegli = c => { salvaImp({ accento: c }); applicaTema(); box.innerHTML = coloriHTML(); collega(); };
  const collega = () => {
    $$('.colore[data-c]', box).forEach(b => b.onclick = () => scegli(b.dataset.c));
    const inp = $('input[type=color]', box);
    inp.oninput = ev => { Gioco.applicaAccento(ev.target.value, S.imp.tema === 'hacker'); };
    inp.onchange = ev => scegli(ev.target.value.toLowerCase());
  };
  collega();
}

async function accediSpotify() {
  avviso('Accedi nella finestra di Spotify, poi chiudila', 'ok');
  try { await api().accedi_spotify(); } catch (e) { avviso('Non riesco ad aprire la finestra di Spotify', 'errore'); }
}
/* chiamata da Python quando la finestra di accesso a Spotify si chiude */
window.dopoLoginSpotify = () => { S.lettore?.ricaricaSpotify(); avviso('Lettore Spotify aggiornato', 'ok'); };

/* =====================================================================
   FOGLI (finestre modali), CONFERME, IMPOSTAZIONI
   ===================================================================== */
function apriFoglio(html, classe = '') {
  const f = $('#foglio');
  f.innerHTML = `<div class="foglio ${classe}" role="dialog" aria-modal="true">${html}</div>`;
  f.hidden = false;
  f.onclick = ev => { if (ev.target === f) chiudiFoglio(); };
  evidenziaBlocchi(f);
}
function chiudiFoglio() {
  const f = $('#foglio');
  if (f.hidden) return;
  f.classList.add('chiude');
  setTimeout(() => { f.hidden = true; f.classList.remove('chiude'); f.innerHTML = ''; S._risolvi?.(false); S._risolvi = null; }, 160);
}
function chiedi({ titolo, testo, ok = 'OK', annulla = 'Annulla', pericolo = false }) {
  return new Promise(risolvi => {
    S._risolvi?.(false);
    apriFoglio(`<div class="conferma"><h3>${esc(titolo)}</h3><p class="secondario">${esc(testo)}</p>
      <div class="azioni"><button class="btn secondario" data-r="0">${esc(annulla)}</button>
      <button class="btn ${pericolo ? 'pericolo' : 'primario'}" data-r="1">${esc(ok)}</button></div></div>`, 'piccolo');
    S._risolvi = risolvi;
    $$('#foglio [data-r]').forEach(b => b.onclick = () => { const v = b.dataset.r === '1'; S._risolvi = null; risolvi(v); chiudiFoglio(); });
    setTimeout(() => $('#foglio [data-r="1"]')?.focus(), 30);
  });
}

function apriImpostazioni() {
  const fonte = S.cat.fonte === 'dispensa'
    ? `Letti dalla dispensa:<br><code>${esc(S.cat.percorso)}</code>`
    : `Copia inclusa nell'app (aggiornata al ${esc((S.cat.generato || '').replace('T', ' alle '))}).`;
  apriFoglio(`
    <div class="foglio-testa"><div><h2>Impostazioni</h2></div>
      <button class="btn icona secondario" data-azione="chiudi-foglio" title="Chiudi">${ic('x')}</button></div>
    <div class="impostazioni">
      <div class="imp-gruppo">Profilo</div>
      <div class="imp-riga"><div><div class="imp-nome">Il tuo nome</div><div class="secondario">Per il saluto e per l'intro.</div></div>
        <input class="campo" data-imp="nome" value="${esc(S.imp.nome || '')}" placeholder="Facoltativo"></div>
      <div class="imp-riga"><div><div class="imp-nome">Data dell'appello</div><div class="secondario">Conto alla rovescia e piano di studio.</div></div>
        <input type="date" class="campo" id="imp-data" value="${esc(S.imp.data_esame || '')}"></div>
      <div class="imp-riga"><div><div class="imp-nome">Docente</div><div class="secondario">Compare sotto il logo e nella schermata Oggi.</div></div>
        <input class="campo" data-imp="professore" value="${esc(S.imp.professore || '')}" placeholder="Cognome del docente"></div>
      <div class="imp-riga"><div><div class="imp-nome">Corso</div><div class="secondario">Se il tuo corso ha un altro nome o un canale (es. A-L).</div></div>
        <input class="campo" data-imp="corso" value="${esc(S.imp.corso || '')}" placeholder="Programmazione 2"></div>
      <div class="imp-riga"><div><div class="imp-nome">Ateneo</div><div class="secondario">Sigla mostrata nell'intro.</div></div>
        <input class="campo" data-imp="sigla" value="${esc(S.imp.sigla || '')}" placeholder="UNICT"></div>

      <div class="imp-gruppo">Aspetto</div>
      <div class="imp-riga"><div><div class="imp-nome">Tema</div><div class="secondario">Terminale è lo stile dell'app e del telefono. Automatico segue Windows.</div></div>
        <div class="segmentato" id="imp-tema">${[['hacker', 'Terminale'], ['auto', 'Automatico'], ['chiaro', 'Chiaro'], ['scuro', 'Scuro']].map(([k, t]) =>
          `<button data-t="${k}" class="${(S.imp.tema || 'auto') === k ? 'attivo' : ''}">${t}</button>`).join('')}</div></div>
      <div class="imp-riga"><div><div class="imp-nome">Colore</div><div class="secondario">Il colore del fosforo. L'ultimo cerchio apre la tavolozza.</div></div>
        <div class="colori" id="imp-colori">${coloriHTML()}</div></div>

      <div class="imp-gruppo">${esc(nomePet())} e obiettivi</div>
      <div class="imp-riga"><div><div class="imp-nome">Nome del compagno</div><div class="secondario">Il personaggio che cresce con i tuoi XP.</div></div>
        <input class="campo" data-imp="nome_pet" value="${esc(S.imp.nome_pet || '')}" placeholder="Bit"></div>
      <div class="imp-riga"><div><div class="imp-nome">${esc(nomePet())} in scena</div><div class="secondario">Resta in un angolo, reagisce a quiz, codice e orale e ti parla. Trascinalo dove dà meno fastidio; un clic lo fa saltare.</div></div>
        <div class="azioni" style="margin:0"><button class="btn secondario piccolo" data-azione="bit-a-posto">Rimetti nell'angolo</button>${siNo('compagno')}</div></div>
      <div class="imp-riga"><div><div class="imp-nome">Obiettivo giornaliero</div><div class="secondario">Gli XP che sfamano ${esc(nomePet())} ogni giorno.</div></div>
        <div class="segmentato" id="imp-obiettivo">${[150, 300, 500, 800].map(k =>
          `<button data-v="${k}" class="${(S.imp.obiettivo_xp || 300) === k ? 'attivo' : ''}">${k} XP</button>`).join('')}</div></div>

      <div class="imp-gruppo">Musica e suoni</div>
      <div class="imp-riga"><div><div class="imp-nome">Lettore musicale</div><div class="secondario">Colonna sonora originale, Spotify o YouTube. Muto: Ctrl+M.</div></div>
        <button class="btn secondario piccolo" data-azione="musica-apri">${ic('musica')}Apri il lettore</button></div>
      <div class="imp-riga"><div><div class="imp-nome">Musica all'avvio</div><div class="secondario">Fa partire la colonna sonora quando apri l'app.</div></div>
        ${siNo('musica_auto')}</div>
      <div class="imp-riga"><div><div class="imp-nome">Effetti sonori</div><div class="secondario">Un suono breve per XP, missioni e livelli.</div></div>
        ${siNo('effetti')}</div>
      <div class="imp-riga"><div><div class="imp-nome">Intro all'avvio</div><div class="secondario">Animazione di accesso al terminale. Esc, Invio o un clic la saltano.</div></div>
        <div class="azioni" style="margin:0"><button class="btn secondario piccolo" data-azione="rivedi-intro">${ic('play')}Guarda</button>${siNo('intro')}</div></div>
      <div class="imp-riga"><div><div class="imp-nome">Musica dell'intro</div><div class="secondario">Sigla sintetizzata, circa 10 secondi.</div></div>
        ${siNo('musica')}</div>

      <div class="imp-gruppo">Sistema</div>
      <div class="imp-riga colonna"><div class="imp-nome">Contenuti</div><div class="secondario">${fonte}</div>
        <div class="azioni"><button class="btn secondario piccolo" data-azione="scegli-dispensa">${ic('cartella')}Scegli la cartella della dispensa…</button>
        <button class="btn secondario piccolo" data-azione="ricarica">${ic('ricomincia')}Ricarica i contenuti</button></div></div>
      <div class="imp-riga colonna"><div class="imp-nome">Compilatore</div>
        <div class="secondario">${S.gpp ? `g++ trovato in <code>${esc(S.gpp)}</code>` : 'g++ non trovato: installa MSYS2/MinGW e aggiungilo al PATH.'}</div></div>
      <div class="imp-riga colonna"><div class="imp-nome">Esercizi in VS Code</div><div id="imp-vscode"></div></div>
      <div class="imp-gruppo">Telefono</div>
      <div class="imp-riga colonna"><div class="imp-nome">Allenatore sul telefono (Android e iPhone)</div>
        ${linkTelefono() ? `<div class="iphone">
          <img src="qr-telefono.svg" alt="Codice QR della versione per telefono" class="qr" onerror="this.remove()">
          <div class="iphone-testo">
            <div class="secondario">Inquadra il codice con la fotocamera del telefono: quiz, orale e «Prevedi l'output» anche senza PC, pure offline.<br>
            <b>iPhone</b>: in Safari tocca Condividi → Aggiungi alla schermata Home.<br>
            <b>Android</b>: in Chrome tocca ⋮ → Installa app (o Aggiungi a schermata Home).</div>
            <button class="link" data-azione="apri-telefono">${esc(linkTelefono())}</button>
          </div>
        </div>` : '<div class="secondario">La versione per telefono non è ancora stata pubblicata per questa copia dell\'app.</div>'}
        <div class="secondario" style="margin-top:12px">Per scambiare i progressi: copia il codice qui e incollalo sul telefono (Bit → Impostazioni), oppure incolla qui il codice copiato dal telefono. Le due cronologie vengono unite: per ogni domanda vale il tentativo più recente. Il codice porta con sé anche nome, appello, docente e colore.</div>
        <div class="azioni"><button class="btn primario piccolo" data-azione="copia-codice">${ic('confronta')}Copia il codice per il telefono</button></div>
        <textarea class="campo area" id="imp-codice" placeholder="Incolla qui il codice copiato dal telefono (inizia con P2:)" spellcheck="false"></textarea>
        <div class="azioni" style="margin-top:8px"><button class="btn secondario piccolo" data-azione="importa-codice">Unisci i progressi del telefono</button></div></div>
      <div class="imp-riga colonna"><div class="imp-nome">I tuoi dati</div>
        <div class="secondario">Progressi e codice sono salvati in <code>${esc(S.cartellaDati)}</code>.</div>
        <div class="azioni"><button class="btn secondario piccolo" data-azione="apri-dati">${ic('cartella')}Apri la cartella</button>
        <button class="btn pericolo-testo piccolo" data-azione="azzera">Azzera i progressi</button></div></div>
      <div class="imp-piede secondario">Allenatore Prog2 · versione ${esc(S.versione)} · ${S.cat.quiz.length} quiz, ${S.cat.orale.length} domande d'orale, ${S.cat.esercizi.length} esercizi
        <br>Un progetto di Giulio Casella
        ${window.CONFIG?.linkProgetto ? `<br><button class="link" data-azione="apri-progetto">Pagina del progetto e aggiornamenti</button>` : ''}</div>
    </div>`, 'medio');
  disegnaVscodeImp();
  attivaColori('#imp-colori');
  $$('#foglio [data-sino]').forEach(seg => seg.onclick = ev => {
    const b = ev.target.closest('button'); if (!b) return;
    salvaImp({ [seg.dataset.sino]: b.dataset.v === 'true' });
    $$('button', seg).forEach(x => x.classList.toggle('attivo', x === b));
    if (seg.dataset.sino === 'compagno') S.bit?.aggiorna();
  });
  $('#imp-obiettivo').onclick = ev => { const b = ev.target.closest('button'); if (!b) return; salvaImp({ obiettivo_xp: +b.dataset.v });
    $$('#imp-obiettivo button').forEach(x => x.classList.toggle('attivo', x === b)); S.gioco = statoGioco(); disegnaPetMini(); };
  $('#imp-tema').onclick = ev => { const b = ev.target.closest('button'); if (!b) return; salvaImp({ tema: b.dataset.t });
    $$('#imp-tema button').forEach(x => x.classList.toggle('attivo', x === b)); applicaTema(); };
  $('#imp-data').onchange = ev => { salvaImp({ data_esame: ev.target.value }); aggiornaMini(); if (S.vista === 'oggi') renderOggi(); };
  $$('#foglio [data-imp]').forEach(inp => inp.oninput = ev => {
    clearTimeout(S._tImp);
    S._tImp = setTimeout(() => { salvaImp({ [inp.dataset.imp]: ev.target.value.trim() }); disegnaMenu(); disegnaPetMini(); if (S.vista === 'oggi' || S.vista === 'bit') RENDER[S.vista](); }, 400);
  });
}
function siNo(chiave) {
  const v = S.imp[chiave] !== false;
  return `<div class="segmentato" data-sino="${chiave}">${[[true, 'Sì'], [false, 'No']].map(([k, t]) =>
    `<button data-v="${k}" class="${v === k ? 'attivo' : ''}">${t}</button>`).join('')}</div>`;
}

async function dopoRicarica(d) {
  if (!d) return;
  if (d.errore && !d.catalogo) return avviso(d.errore, 'errore');
  const id = S.c.id;
  $('.errore-avvio')?.remove();
  if (!caricaDati(d)) return;
  S.gioco = statoGioco(); disegnaPetMini();
  S.c = { ...S.c, costruito: false, id: null, editor: null };
  S.q.fase = 'scelta';
  chiudiFoglio();
  if ($('#app').hidden) { $('#app').hidden = false; applicaTema(); aggiornaMini(); }
  if (S.vista === 'codice' && id && S.esPer[id]) { renderCodice(); apriEsercizio(id); } else vai(S.vista || 'oggi');
  avviso('Contenuti aggiornati', 'ok');
}

/* =====================================================================
   AZIONI (clic) E TASTIERA
   ===================================================================== */
const AZIONI = {
  'vai': d => vai(d.vista),
  'impostazioni': () => apriImpostazioni(),
  'chiudi-foglio': () => chiudiFoglio(),
  'quiz-modo': d => { S.q.modo = d.modo; renderQuiz(); },
  'quiz-chip': d => { const m = +d.m; S.q.moduli.has(m) ? S.q.moduli.delete(m) : S.q.moduli.add(m); renderQuiz(); },
  'quiz-tutti': () => { S.q.moduli = new Set(S.moduli.filter(m => S.cat.quiz.some(q => q.modulo === m))); renderQuiz(); },
  'quiz-nessuno': () => { S.q.moduli = new Set(); renderQuiz(); },
  'quiz-num': d => { S.q.num = Math.max(5, Math.min(60, S.q.num + +d.d)); renderQuiz(); },
  'quiz-inizia': () => quizInizia(),
  'quiz-scegli': d => quizScegli(+d.k),
  'quiz-succ': () => quizSucc(),
  'quiz-prec': () => quizPrec(),
  'quiz-vai': d => { S.q.i = +d.k; renderQuiz(); },
  'quiz-consegna': () => quizConsegna(),
  'quiz-esci': async () => {
    if (S.q.finito) { S.q.fase = 'esito'; return renderQuiz(); }
    if (S.q.esame && !await chiedi({ titolo: 'Uscire dalla simulazione?', testo: 'Le risposte date finora andranno perse.', ok: 'Esci', annulla: 'Continua', pericolo: true })) return;
    clearInterval(S.q.timer); S.q.fase = 'scelta'; S.q.finito = true; renderQuiz();
  },
  'quiz-rivedi': d => { S.q.fase = 'sessione'; S.q.finito = true; S.q.i = +d.k; renderQuiz(); },
  'quiz-nuovo': () => { S.q.fase = 'scelta'; renderQuiz(); },
  'quiz-modulo': d => { S.q.moduli = new Set([+d.m]); S.q.modo = 'allenamento'; S.q.fase = 'scelta'; vai('quiz'); quizInizia(); },
  'quiz-piano': () => { const p = pianoDiOggi(); S.q.moduli = new Set(p.moduli); S.q.modo = 'allenamento'; S.q.fase = 'scelta'; vai('quiz'); quizInizia(); },
  'quiz-errori': () => { S.q.moduli = new Set(S.moduli); S.q.modo = 'errori'; S.q.num = Math.max(S.q.num, 10); S.q.fase = 'scelta'; vai('quiz'); quizInizia(); },
  'quiz-esame': () => { S.q.moduli = new Set(S.moduli); S.q.modo = 'esame'; S.q.fase = 'scelta'; vai('quiz'); quizInizia(); },
  'orale-modulo': d => { S.o.filtro = String(d.m); S.o.corrente = null; vai('orale'); },
  'orale-mostra': () => oraleMostra(),
  'orale-valuta': d => oraleValuta(+d.v),
  'orale-salta': () => oraleProssima(),
  'orale-timer': () => oraleTimer(),
  'codice-modulo': d => {
    const m = +d.m; S.c.aperti.add(m); vai('codice');
    const e = S.cat.esercizi.filter(x => x.modulo === m).sort((a, b) => ORDINE_TIPO[a.tipo] - ORDINE_TIPO[b.tipo] || (a.numero || 0) - (b.numero || 0))
      .find(x => !S.prog.esercizi[x.id]?.fatto && x.tipo !== 'pattern') || S.cat.esercizi.find(x => x.modulo === m);
    if (e) apriEsercizio(e.id);
  },
  'codice-apri': d => { if (S.vista !== 'codice') vai('codice'); apriEsercizio(d.id); },
  'es-gruppo': d => { const m = +d.m; S.c.aperti.has(m) ? S.c.aperti.delete(m) : S.c.aperti.add(m); disegnaLista(); },
  'es-filtro': (d, b) => { S.c.filtro = d.f; $$('#es-filtro button').forEach(x => x.classList.toggle('attivo', x === b)); disegnaLista(); },
  'esegui': () => esegui(),
  'bit-a-posto': () => { S.bit?.rimettiAPosto(); salvaImp({ compagno_pos: null }); },
  'scheda': d => { S.c.scheda = d.s; disegnaConsole(); },
  'vai-riga': d => S.c.editor?.vaiARiga(+d.r),
  'traccia': () => { S.c.tracciaAperta = !S.c.tracciaAperta; $('#traccia').classList.toggle('aperta', S.c.tracciaAperta);
    $('.traccia-interruttore span').textContent = S.c.tracciaAperta ? 'Riduci' : 'Mostra tutta la traccia'; },
  'crono': () => crono(),
  'es-fatto': () => esFatto(),
  'ricomincia': () => ricomincia(),
  'soluzione': () => mostraSoluzione(),
  'scegli-dispensa': async () => { const d = await api().scegli_dispensa(); if (d?.errore && !d.catalogo) return avviso(d.errore, 'errore'); dopoRicarica(d); },
  'ricarica': async () => dopoRicarica(await api().ricarica()),
  'apri-dati': () => api().apri_cartella_dati(),
  'rivedi-intro': () => { chiudiFoglio(); setTimeout(mostraIntro, 250); },
  'barra-riduci': () => cambiaPannello('barra_stretta'),
  'elenco-riduci': () => cambiaPannello('elenco_nascosto'),
  'vscode-apri': () => vscodeApri(),
  'vscode-importa': () => vscodeImporta(),
  'vscode-crea': async () => {
    const r = await api().crea_vscode(true);
    if (r?.errore) return avviso(r.errore, 'errore');
    avviso(`${r.nuovi} esercizi nuovi, ${r.esistenti} già presenti (non toccati)` + (r.senza_vscode ? ' · VS Code non trovato' : ''), r.senza_vscode ? 'errore' : 'ok');
    disegnaVscodeImp();
  },
  'vscode-scegli': async () => { if (await api().scegli_cartella_vscode()) disegnaVscodeImp(); },
  'apri-telefono': () => api().apri_link(linkTelefono()),
  'apri-progetto': () => api().apri_link(window.CONFIG?.linkProgetto || ''),
  'musica-apri': () => { chiudiFoglio(); S.lettore.apri(); },
  'rinomina-pet': () => {
    apriFoglio(`<div class="conferma"><h3>Come si chiama il tuo compagno?</h3>
      <input class="campo" id="nuovo-nome-pet" value="${esc(S.imp.nome_pet || '')}" placeholder="Bit" maxlength="16" style="width:100%;margin:12px 0">
      <div class="azioni"><button class="btn secondario" data-azione="chiudi-foglio">Annulla</button><button class="btn primario" id="ok-nome-pet">Salva</button></div></div>`, 'piccolo');
    const ok = () => { salvaImp({ nome_pet: $('#nuovo-nome-pet').value.trim() }); chiudiFoglio(); disegnaMenu(); disegnaPetMini(); renderBit(); };
    $('#ok-nome-pet').onclick = ok;
    $('#nuovo-nome-pet').onkeydown = ev => { if (ev.key === 'Enter') { ev.preventDefault(); ok(); } };
    setTimeout(() => $('#nuovo-nome-pet')?.select(), 30);
  },
  'copia-codice': async () => {
    const ok = await api().copia_appunti(codiceProgressi());
    avviso(ok ? 'Codice copiato: incollalo sul telefono' : 'Copia non riuscita', ok ? 'ok' : 'errore');
  },
  'importa-codice': () => {
    try {
      const { prog: remoto, profilo } = leggiCodiceProgressi($('#imp-codice').value);
      delete remoto.data_esame;
      S.prog = unisciProgressi(S.prog, remoto);
      // il profilo del telefono riempie solo i campi ancora vuoti sul PC
      const vuoti = Object.fromEntries(Object.entries(profilo).filter(([k, v]) => CAMPI_PROFILO.includes(k) && v && !S.imp[k]));
      if (Object.keys(vuoti).length) { salvaImp(vuoti); applicaTema(); disegnaMenu(); aggiornaMini(); }
      salvaProgressi();
      $('#imp-codice').value = '';
      avviso('Progressi del telefono uniti', 'ok');
      if (S.vista === 'codice') disegnaLista(); else if (S.vista !== 'quiz') RENDER[S.vista]();
    } catch (e) { avviso(e.message || 'Codice non valido', 'errore'); }
  },
  'azzera': async () => {
    if (!await chiedi({ titolo: 'Azzerare tutti i progressi?', testo: 'Quiz, orale, esercizi e simulazioni ripartono da zero. Il tuo codice resta salvato.', ok: 'Azzera', annulla: 'Annulla', pericolo: true })) return;
    S.prog = await api().azzera_progressi(); S.gioco = statoGioco(); disegnaPetMini(); avviso('Progressi azzerati'); vai(S.vista);
  },
};

document.addEventListener('click', ev => {
  const t = ev.target.closest('[data-azione]');
  if (!t || t.disabled) return;
  const f = AZIONI[t.dataset.azione];
  if (f) { ev.preventDefault(); f(t.dataset, t, ev); }
});
document.addEventListener('change', ev => {
  const t = ev.target.closest('[data-cambia]');
  if (t?.dataset.cambia === 'orale-filtro') { S.o.filtro = t.value; S.o.corrente = null; renderOrale(); }
});

document.addEventListener('keydown', ev => {
  if (ev.defaultPrevented) return;
  if (ev.key === 'Escape' && $('#musica-dock').classList.contains('aperto') && $('#foglio').hidden) { ev.preventDefault(); return S.lettore.chiudi(); }
  if (!$('#foglio').hidden) {
    if (ev.key === 'Escape') { ev.preventDefault(); chiudiFoglio(); }
    return;
  }
  const inCampo = /^(INPUT|TEXTAREA|SELECT)$/.test(document.activeElement?.tagName);
  if (ev.ctrlKey && ev.key >= '1' && ev.key <= String(VISTE.length)) { ev.preventDefault(); return vai(VISTE[+ev.key - 1][0]); }
  if (ev.ctrlKey && !ev.shiftKey && ev.key.toLowerCase() === 'm') { ev.preventDefault(); S.lettore?.alternaMuto(); return avviso(S.lettore?.muto ? 'Audio disattivato' : 'Audio attivo'); }
  if (ev.ctrlKey && ev.key === ',') { ev.preventDefault(); return apriImpostazioni(); }
  if (ev.ctrlKey && !ev.shiftKey && ev.key.toLowerCase() === 'b') { ev.preventDefault(); return cambiaPannello('barra_stretta'); }
  if (ev.ctrlKey && !ev.shiftKey && ev.key.toLowerCase() === 'e' && S.vista === 'codice') { ev.preventDefault(); return cambiaPannello('elenco_nascosto'); }
  if (S.vista === 'codice') {
    if ((ev.ctrlKey && ev.key === 'Enter') || ev.key === 'F5') { ev.preventDefault(); return esegui(); }
    if (ev.ctrlKey && ev.key.toLowerCase() === 'k') { ev.preventDefault(); return $('#es-cerca')?.focus(); }
    if (ev.ctrlKey && ev.key.toLowerCase() === 's') { ev.preventDefault(); return salvaCodice(true); }
    if (ev.ctrlKey && ev.key.toLowerCase() === 'i') { ev.preventDefault(); return vscodeImporta(); }
    return;
  }
  if (inCampo) return;
  if (S.vista === 'quiz' && S.q.fase === 'sessione') {
    const k = { a: 0, b: 1, c: 2, d: 3, 1: 0, 2: 1, 3: 2, 4: 3 }[ev.key.toLowerCase()];
    if (k !== undefined) { ev.preventDefault(); return quizScegli(k); }
    if (ev.key === 'Enter' || ev.key === 'ArrowRight') { ev.preventDefault(); return quizSucc(); }
    if (ev.key === 'ArrowLeft') { ev.preventDefault(); return quizPrec(); }
  }
  if (S.vista === 'orale') {
    if (ev.key === ' ' && !S.o.mostrata) { ev.preventDefault(); return oraleMostra(); }
    if (S.o.mostrata && ['1', '2', '3'].includes(ev.key)) { ev.preventDefault(); return oraleValuta(+ev.key - 1); }
    if (ev.key === 'ArrowRight') { ev.preventDefault(); return oraleProssima(); }
  }
});
