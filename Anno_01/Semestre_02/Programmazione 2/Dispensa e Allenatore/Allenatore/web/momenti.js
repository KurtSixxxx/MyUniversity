/* =====================================================================
   Allenatore Prog2 — momenti speciali
   ---------------------------------------------------------------------
   • Modalità panico: negli ultimi 3 giorni prima dell'appello la scheda
     «Oggi» mostra un piano di ripasso d'emergenza (costruito dai tuoi
     punti deboli), con le spunte salvate nelle impostazioni.
   • Giorno dell'esame: all'apertura, un riquadro al centro (si chiude
     con la ×) con un esercizio di respirazione e poche frasi calme.
   • Stella su GitHub: un fumetto piccolo in un angolo in cui Bit chiede
     una stella al progetto. Sparisce per sempre dopo «Fatto» o «Non
     chiedere più»; mai nel giorno dell'esame.
   • Crediti: il blocco per le impostazioni.
   Usa le funzioni globali di app.js (S, esc, ic, api, salvaImp, ...):
   va caricato DOPO app.js.
   ===================================================================== */

/* ---------------------------------------------------------------- modalità panico */
function moduliDeboli(n = 3) {
  // prima i moduli mai provati, poi quelli con la percentuale di giuste più bassa
  return S.moduli.filter(m => m > 0).map(m => {
    const s = statModulo(m);
    return { m, p: s.provati ? s.giusti / s.provati : -1, s };
  }).sort((a, b) => a.p - b.p).slice(0, n);
}

function pianoPanico(g) {
  const deboli = moduliDeboli(3), ms = deboli.map(d => d.m);
  const nomi = deboli.map(d => 'M' + d.m).join(', ');
  const sbagliate = S.cat.quiz.filter(q => S.prog.quiz[q.id]?.ultima === false).length;
  const oraleDaFare = S.cat.orale.filter(o => (S.prog.orale[o.id]?.box || 0) < 3).length;
  return [
    { g: 3, titolo: 'Tappa i buchi', sotto: 'Solo i punti deboli: niente argomenti nuovi.', voci: [
      { k: 'a', testo: `Quiz sui tre moduli più deboli (${nomi})`, azione: 'quiz-moduli', dati: { ms: ms.join(',') }, bottone: 'Inizia' },
      { k: 'b', testo: `Orale: le domande non ancora sicure del Modulo ${deboli[0]?.m ?? 1}`, azione: 'orale-modulo', dati: { m: deboli[0]?.m ?? 1 }, bottone: 'Orale' },
      { k: 'c', testo: 'Un laboratorio d\'esame a step, senza guardare la soluzione', azione: 'codice-modulo', dati: { m: 0 }, bottone: 'Tracce' },
      { k: 'd', testo: 'Rileggi il formulario e il glossario (appendice della dispensa)' },
    ] },
    { g: 2, titolo: 'Prova generale', sotto: 'Come il giorno vero: tempo, silenzio, niente aiuti.', voci: [
      { k: 'a', testo: 'Simulazione del quiz: 30 domande in 60 minuti', azione: 'quiz-esame', bottone: 'Simula' },
      { k: 'b', testo: sbagliate ? `Correggi le ${sbagliate} risposte sbagliate` : 'Rifai le domande sbagliate nella simulazione', azione: 'quiz-errori', bottone: 'Correggi' },
      { k: 'c', testo: 'Simulazione del laboratorio con il cronometro (2 ore)', azione: 'codice-modulo', dati: { m: 0 }, bottone: 'Tracce' },
      { k: 'd', testo: `Ripeti ad alta voce 10 domande d'orale (${oraleDaFare} ancora da fissare)`, azione: 'vai', dati: { vista: 'orale' }, bottone: 'Orale' },
    ] },
    { g: 1, titolo: 'Consolida, non imparare', sotto: 'Giornata leggera. La memoria si fissa dormendo.', voci: [
      { k: 'a', testo: 'Solo le domande sbagliate, una passata veloce', azione: 'quiz-errori', bottone: 'Inizia' },
      { k: 'b', testo: 'Riscrivi a memoria i pattern: lista, pila/coda, BST', azione: 'codice-modulo', dati: { m: 11 }, bottone: 'Pattern' },
      { k: 'c', testo: 'Orale: 15 minuti sulle domande che sai meno', azione: 'vai', dati: { vista: 'orale' }, bottone: 'Orale' },
      { k: 'd', testo: 'Prepara documento, penna e sveglia. Stasera stacca e dormi 8 ore' },
    ] },
  ];
}

function cartaPanico(g) {
  if (g === null || g < 1 || g > 3) return '';
  const fatti = (S.imp.panico || {})[S.imp.data_esame] || {};
  const giorni = pianoPanico(g);
  const tot = giorni.reduce((n, d) => n + d.voci.length, 0), ok = Object.values(fatti).filter(Boolean).length;
  const attr = o => Object.entries(o || {}).map(([k, v]) => `data-${k}="${esc(v)}"`).join(' ');
  return `<div class="card panico">
    <div class="panico-testa">
      <span class="panico-sirena"></span>
      <div><div class="sopratitolo">Modalità panico · T-${g}</div>
        <h2>Piano di ripasso d'emergenza</h2>
        <div class="secondario">Tre giorni, una cosa alla volta. Fai le voci del giorno evidenziato: se finisci prima, riposa. ${ok}/${tot} fatte.</div></div>
    </div>
    <div class="panico-giorni">
      ${giorni.map(d => `<div class="panico-giorno ${d.g === g ? 'oggi' : d.g > g ? 'passato' : ''}">
        <div class="panico-giorno-testa"><b>T-${d.g}</b> ${esc(d.titolo)}${d.g === g ? '<span class="pill ok">oggi</span>' : ''}</div>
        <div class="secondario piccola">${esc(d.sotto)}</div>
        ${d.voci.map(v => { const id = d.g + v.k, f = !!fatti[id]; return `<div class="panico-voce ${f ? 'fatta' : ''}">
          <button class="panico-spunta" data-azione="panico-spunta" data-k="${id}" title="${f ? 'Segna da fare' : 'Segna come fatta'}">${f ? '✓' : ''}</button>
          <span>${esc(v.testo)}</span>
          ${v.azione && d.g === g ? `<button class="btn secondario piccolo" data-azione="${v.azione}" ${attr(v.dati)}>${esc(v.bottone)}</button>` : ''}
        </div>`; }).join('')}
      </div>`).join('')}
    </div>
    <div class="panico-regole secondario piccola"><b>Regole d'emergenza:</b> niente argomenti nuovi · blocchi da 50 minuti + 10 di pausa · acqua e luce · la notte prima si dorme.</div>
  </div>`;
}

function spuntaPanico(k) {
  const tutte = { ...(S.imp.panico || {}) }, chiave = S.imp.data_esame;
  // si tengono solo le spunte dell'appello attuale
  const fatti = { ...(tutte[chiave] || {}) };
  fatti[k] = !fatti[k];
  salvaImp({ panico: { [chiave]: fatti } });
  if (fatti[k]) S.lettore?.effetto('missione');
  if (S.vista === 'oggi') renderOggi();
}

/* ---------------------------------------------------------------- giorno dell'esame */
const FRASI_CALMA = [
  'Hai fatto il lavoro. Adesso conta la calma, non un\'ora in più di studio.',
  'L\'ansia è energia: ti tiene sveglio. Non è un segnale che andrà male.',
  'Leggi tutta la traccia prima di scrivere. Poi uno step alla volta.',
  'Se una domanda ti blocca, passa alla successiva e torna dopo.',
  'Compila spesso: un errore alla volta è facile da trovare.',
  'Il professore vuole vedere come ragioni, non la perfezione.',
];

function giornoEsame() {
  if (giorniAllEsame() !== 0 || document.querySelector('.calma-velo')) return;
  const velo = document.createElement('div');
  velo.className = 'calma-velo';
  const nome = (S.imp.nome || '').trim();
  velo.innerHTML = `<div class="calma" role="dialog" aria-modal="true" aria-label="Il giorno dell'esame">
    <button class="calma-chiudi" title="Chiudi">${ic('x')}</button>
    <div class="calma-bit">${svgPet(S.gioco ? Gioco.pet(S.gioco, nomePet()).indice : 0, 'felice', 84)}</div>
    <div class="sopratitolo">Oggi è il giorno${nome ? ', ' + esc(nome) : ''}</div>
    <h2>Respira con me.</h2>
    <div class="respiro"><div class="respiro-cerchio"></div><div class="respiro-testo">Inspira</div></div>
    <p class="calma-frase"></p>
    <ul class="calma-lista">
      <li>Documento e libretto, penna, acqua</li>
      <li>Arriva un quarto d'ora prima</li>
      <li>Quiz: prima quelle sicure, poi le altre</li>
      <li>Laboratorio: compila spesso, uno step alla volta</li>
    </ul>
    <button class="btn primario calma-ok">Ci sono</button>
  </div>`;
  document.body.appendChild(velo);
  // respirazione «a scatola»: 4 s dentro, 4 s trattieni, 4 s fuori, 4 s pausa
  const fasi = [['Inspira', 1.25], ['Trattieni', 1.25], ['Espira', .8], ['Pausa', .8]];
  const cerchio = velo.querySelector('.respiro-cerchio'), testo = velo.querySelector('.respiro-testo');
  const frase = velo.querySelector('.calma-frase');
  let i = 0, giri = 0;
  const passo = () => {
    const [t, s] = fasi[i % 4];
    testo.textContent = t; cerchio.style.transform = `scale(${s})`;
    if (i % 4 === 0) frase.textContent = FRASI_CALMA[giri++ % FRASI_CALMA.length];
    i++;
  };
  passo();
  const timer = setInterval(passo, 4000);
  const chiudi = () => { clearInterval(timer); velo.classList.add('via'); setTimeout(() => velo.remove(), 250); document.removeEventListener('keydown', esc_); };
  const esc_ = ev => { if (ev.key === 'Escape') chiudi(); };
  document.addEventListener('keydown', esc_);
  velo.querySelector('.calma-chiudi').onclick = chiudi;
  velo.querySelector('.calma-ok').onclick = () => { chiudi(); avviso('In bocca al lupo. Ce la fai.', 'ok'); };
  velo.onclick = ev => { if (ev.target === velo) chiudi(); };
}

/* ---------------------------------------------------------------- stella su GitHub */
function linkRepo() {
  const l = window.CONFIG?.linkProgetto || '';
  const m = /^https:\/\/github\.com\/[^/]+\/[^/]+/.exec(l);
  return m ? m[0] : '';
}
function chiediStella() {
  const repo = linkRepo();
  if (!repo || S.imp.stella_fatta || S.imp.stella_mai || giorniAllEsame() === 0 || !S.imp.configurato) return;
  if (document.querySelector('.stella')) return;
  const el = document.createElement('div');
  el.className = 'stella';
  el.innerHTML = `<button class="stella-x" title="Chiudi">${ic('x')}</button>
    <div class="stella-bit">${svgPet(S.gioco ? Gioco.pet(S.gioco, nomePet()).indice : 0, 'felice', 46)}</div>
    <div class="stella-testo"><b>${esc(nomePet())}</b>: ti sto aiutando? Lasciaci una ★ su GitHub: fa scoprire l'Allenatore ad altri studenti.
      <div class="stella-azioni"><button class="btn primario piccolo" data-s="si">★ Lascia una stella</button>
      <button class="link" data-s="mai">Non chiedere più</button></div></div>`;
  document.body.appendChild(el);
  requestAnimationFrame(() => el.classList.add('vis'));
  const via = () => { el.classList.remove('vis'); setTimeout(() => el.remove(), 300); };
  el.onclick = ev => {
    const b = ev.target.closest('button'); if (!b) return;
    if (b.dataset.s === 'si') { api().apri_link(repo); salvaImp({ stella_fatta: true }); S.bit?.reagisci?.('giusta'); avviso('Grazie! ★', 'ok'); }
    else if (b.dataset.s === 'mai') salvaImp({ stella_mai: true });
    via();
  };
  setTimeout(() => el.isConnected && via(), 25000);   // non disturba: se ne va da solo
}

/* ---------------------------------------------------------------- crediti */
function creditiHTML() {
  const repo = linkRepo();
  return `<div class="imp-gruppo">Crediti</div>
    <div class="imp-riga colonna crediti">
      <div class="imp-nome">Allenatore Prog2 · a cura di Giulio Casella</div>
      <div class="secondario">Dispensa, esercizi, app e versione per telefono pensati per chi prepara l'esame di Programmazione 2.
        Distribuito con licenza <b>CC BY-NC-SA 4.0</b>: puoi condividerlo e modificarlo citando l'autore, non a scopo di lucro.</div>
      <ul class="crediti-lista secondario">
        <li><b>Contenuti</b>: dispensa scritta seguendo il programma del corso, le slide e le prove d'esame</li>
        <li><b>Bit</b>: compagno in pixel art originale</li>
        <li><b>Colonna sonora</b>: brani originali generati dal vivo con Web Audio</li>
        <li><b>Tecnologia</b>: Python, pywebview e Microsoft WebView2, compilatore g++ (MinGW-w64), PyInstaller</li>
        <li><b>Musica in streaming</b>: lettori ufficiali di Spotify e YouTube (marchi dei rispettivi proprietari)</li>
        <li>Sviluppato con l'aiuto di Claude (Anthropic)</li>
      </ul>
      ${repo ? `<div class="azioni"><button class="btn secondario piccolo" data-azione="apri-repo">★ Il progetto su GitHub</button></div>` : ''}
    </div>`;
}
