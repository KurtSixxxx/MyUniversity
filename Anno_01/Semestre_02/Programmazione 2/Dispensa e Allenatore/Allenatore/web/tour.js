/* =====================================================================
   Allenatore Prog2 — tour guidato del primo avvio
   ---------------------------------------------------------------------
   Bit accompagna lo studente tra le schede dell'app con un riquadro di
   dialogo «da videogioco a 8 bit»: il testo compare lettera per lettera
   e a ogni sillaba si sente il classico bip sintetizzato (onda quadra).
   • Il resto dell'app si oscura; restano accese solo le parti di cui
     Bit sta parlando (maschera SVG con i «buchi» che scivolano da una
     tappa all'altra).
   • Clic, Invio, Spazio o → : se il testo sta ancora comparendo lo
     completa, altrimenti passa alla tappa successiva. ← torna indietro.
   • Esc o «Salta il tour» lo chiudono. Si rivede da Impostazioni.
   • Alla fine (o se lo salti) si salva imp.tour_visto = true.
   Usa le funzioni globali di app.js (S, $, esc, vai, salvaImp, svgPet,
   nomePet, ...): va caricato DOPO app.js.
   ===================================================================== */

/* Le tappe. Nel testo: *grassetto*, [tasto]. {nome} e {bit} vengono sostituiti.
   vista = scheda da aprire; luci = elementi da illuminare (per ogni voce il primo elemento
   visibile; una voce può essere un elenco di alternative, provate in ordine); umore = espressione di Bit nel ritratto. */
const TAPPE_TOUR = [
  { umore: 'euforico', testo: 'Ciao{nome}! Sono *{bit}*, il tuo compagno di studio. Ti faccio fare un giro veloce dell\'Allenatore: un minuto, e poi sai dove mettere le mani.' },
  { vista: 'oggi', luci: ['#menu [data-vista="oggi"]', '#v-oggi .eroe'], umore: 'felice',
    testo: 'Questa è *Oggi*, la tua base. Qui vedi quanti giorni mancano all\'appello e il *piano del giorno*: cosa studiare e da dove partire. Quando non sai cosa fare, apri l\'app e premi il primo pulsante.' },
  { vista: 'oggi', luci: ['#v-oggi .bit-oggi'], umore: 'neutro',
    testo: 'Ogni giorno ti do tre *missioni*. Completarle vale XP, e gli XP mi fanno crescere. Se sparisci per qualche giorno... mi viene fame. Te lo dico e basta.' },
  { vista: 'quiz', luci: ['#menu [data-vista="quiz"]', ['#v-quiz .card.blocco', '#v-quiz .card', '#v-quiz']], umore: 'felice',
    testo: '*Quiz*: le domande a crocette della dispensa, modulo per modulo. C\'è l\'allenamento, il ripasso degli errori e la *simulazione d\'esame*: 30 domande in 60 minuti. Rispondi con [A] [B] [C] [D], vai avanti con [Invio].' },
  { vista: 'orale', luci: ['#menu [data-vista="orale"]', ['#v-orale .flashcard', '#v-orale']], umore: 'neutro',
    testo: '*Orale*: le domande del professore, come carte da ripasso. Rispondi ad alta voce, poi [Spazio] mostra la risposta modello e con [1] [2] [3] mi dici quanto la sapevi. Le carte deboli tornano più spesso.' },
  { vista: 'codice', luci: ['#menu [data-vista="codice"]', '#v-codice .elenco-es'], umore: 'felice', apri: true,
    testo: '*Codice*: tutti gli esercizi al PC e i laboratori a step, divisi per modulo. Quelli completati si spuntano, e li cerchi per nome.' },
  { vista: 'codice', luci: ['#v-codice .editor-card', '#v-codice .console'], umore: 'neutro', apri: true,
    testo: 'Scrivi qui, poi [Ctrl] + [Invio] compila con g++ ed esegue. Gli errori te li spiego in italiano, e *Confronto* mette il tuo output accanto a quello giusto. La soluzione c\'è... ma prima provaci davvero.' },
  { vista: 'bit', luci: ['#menu [data-vista="bit"]', '#v-bit .bit-scheda'], umore: 'euforico',
    testo: 'E questa è casa mia! Salendo di livello mi evolvo, e nell\'*Armadio* sblocchi vestiti e accessori con i traguardi. Sì, ci tengo al mio look.' },
  { luci: ['#pet-mini .pet-mini', '#musica-mini'], umore: 'felice',
    testo: 'Qui in basso mi trovi sempre, con livello e XP. Accanto c\'è la *musica*: colonna sonora originale, Spotify o YouTube. [Ctrl] + [M] la zittisce.' },
  { luci: ['#voce-impostazioni'], umore: 'neutro',
    testo: 'In *Impostazioni* cambi data dell\'appello, tema e colori, e sincronizzi i progressi con il *telefono*. Da lì puoi anche rivedere questo tour.' },
  { vista: 'oggi', umore: 'euforico',
    testo: 'Ultimo trucco: [Ctrl] + [1]...[5] salta tra le schede. Tieni la *dispensa* aperta accanto: lei ti spiega, io ti alleno. Pronto{nome}? Si comincia!' },
];

class Tour {
  constructor(fine) {
    this.fine = fine; this.i = -1; this.buchi = []; this.mete = []; this.timer = null; this.vivo = true;
    const el = this.el = document.createElement('div');
    el.className = 'tour';
    el.innerHTML = `
      <svg class="tour-velo" aria-hidden="true"><defs><mask id="tour-maschera">
        <rect x="0" y="0" width="100%" height="100%" fill="#fff"/><g class="tour-buchi"></g></mask></defs>
        <rect class="tour-scuro" x="0" y="0" width="100%" height="100%" mask="url(#tour-maschera)"/>
        <g class="tour-cornici"></g></svg>
      <div class="tour-dialogo" role="dialog" aria-modal="true" aria-label="Tour dell'app">
        <div class="tour-targa"></div>
        <div class="tour-ritratto"></div>
        <div class="tour-corpo">
          <div class="tour-testo" aria-live="polite"></div>
          <span class="tour-segue" aria-hidden="true">▼</span>
        </div>
        <div class="tour-piede">
          <button class="tour-salta" data-t="salta">Salta il tour <kbd>Esc</kbd></button>
          <span class="tour-punti"></span>
          <button class="tour-voce" data-t="voce" title="Voce di Bit"></button>
          <button class="btn secondario piccolo" data-t="indietro">◂ Indietro</button>
          <button class="btn primario piccolo" data-t="avanti">Avanti ▸</button>
        </div>
      </div>`;
    document.body.appendChild(el);
    document.body.classList.add('in-tour');
    this.dialogo = el.querySelector('.tour-dialogo'); this.testo = el.querySelector('.tour-testo');
    this.ritratto = el.querySelector('.tour-ritratto');
    this.gBuchi = el.querySelector('.tour-buchi'); this.gCornici = el.querySelector('.tour-cornici');
    el.querySelector('.tour-targa').textContent = nomePet().toUpperCase();
    el.querySelector('.tour-punti').innerHTML = TAPPE_TOUR.map(() => '<i></i>').join('');
    this.aggiornaVoce();

    el.addEventListener('click', ev => {
      const b = ev.target.closest('[data-t]');
      if (!b) return this.avanti();          // clic ovunque = come Invio
      ev.stopPropagation();
      ({ salta: () => this.chiudi(true), indietro: () => this.vai(this.i - 1), avanti: () => this.avanti(),
         voce: () => { salvaImp({ voce_bit: S.imp.voce_bit === false }); this.aggiornaVoce(); } })[b.dataset.t]?.();
    });
    this.tasto = ev => {
      if (ev.ctrlKey && ev.key.toLowerCase() === 'm') return;     // il muto resta disponibile
      const k = ev.key;
      if (k === 'Escape') this.chiudi(true);
      else if (k === 'Enter' || k === ' ' || k === 'ArrowRight') this.avanti();
      else if (k === 'ArrowLeft') this.vai(this.i - 1);
      else if (k === 'Tab') { /* lascia muovere il fuoco tra i pulsanti */ return; }
      ev.preventDefault(); ev.stopImmediatePropagation();
    };
    addEventListener('keydown', this.tasto, true);
    this.ridimensiona = () => this.misura();
    addEventListener('resize', this.ridimensiona);
    this.ciclo = this.ciclo.bind(this);
    requestAnimationFrame(this.ciclo);
    requestAnimationFrame(() => el.classList.add('vis'));
    this.vai(0);
  }

  aggiornaVoce() {
    const b = this.el.querySelector('.tour-voce'), on = S.imp.voce_bit !== false;
    b.textContent = on ? '♪' : '×♪'; b.classList.toggle('spenta', !on);
    b.title = on ? 'Voce di Bit attiva: clic per spegnerla' : 'Voce di Bit spenta: clic per accenderla';
  }

  /* ---------------- tappe */
  vai(n) {
    if (n < 0 || !this.vivo) return;
    if (n >= TAPPE_TOUR.length) return this.chiudi(false);
    this.i = n;
    const t = TAPPE_TOUR[n];
    if (t.vista && S.vista !== t.vista) vai(t.vista);
    if (t.apri && t.vista === 'codice' && !S.c.id && S.cat.esercizi.length) apriEsercizio(S.cat.esercizi[0].id);
    this.selettori = t.luci || [];
    // il primo elemento da illuminare deve essere visibile: se serve, la pagina scorre
    setTimeout(() => {
      const primo = this.trova().at(-1);
      if (primo) { const r = primo.getBoundingClientRect(); if (r.top < 0 || r.bottom > innerHeight) primo.scrollIntoView({ block: 'center' }); }
      this.misura();
    }, 60);
    this.misura();
    // ritratto, punti, pulsanti
    const pet = Gioco.pet(S.gioco || statoGioco(), nomePet());
    this.voceAcuta = pet.indice < 4;           // il Bit «senior» parla più grave
    this.ritratto.innerHTML = svgPet(pet.indice, t.umore || 'felice', 92);
    [...this.el.querySelectorAll('.tour-punti i')].forEach((p, k) => p.className = k < n ? 'fatto' : k === n ? 'ora' : '');
    this.el.querySelector('[data-t="indietro"]').disabled = n === 0;
    this.el.querySelector('[data-t="avanti"]').textContent = n === TAPPE_TOUR.length - 1 ? 'Iniziamo! ▸' : 'Avanti ▸';
    this.scrivi(t.testo);
  }
  avanti() { if (this.scrivendo) this.completa(); else this.vai(this.i + 1); }

  /* ---------------- testo che compare lettera per lettera */
  scrivi(sorgente) {
    clearTimeout(this.timer);
    const nome = (S.imp.nome || '').trim();
    const testo = sorgente.replace(/\{nome\}/g, nome ? ', ' + nome : '').replace(/\{bit\}/g, nomePet());
    // *grassetto* e [tasto] -> pezzi; ogni lettera è uno <span> invisibile che poi si accende
    // (il testo occupa subito il suo spazio: il riquadro non cambia altezza mentre Bit parla)
    this.testo.innerHTML = '';
    this.unita = [];
    const re = /\*([^*]+)\*|\[([^\]]+)\]|([^*[]+)/g;
    let m;
    while ((m = re.exec(testo))) {
      if (m[2] !== undefined) {               // un tasto compare tutto insieme
        const k = document.createElement('kbd'); k.textContent = m[2]; k.className = 'tl';
        this.testo.appendChild(k); this.unita.push({ el: k, ch: 'k' });
        continue;
      }
      const box = m[1] !== undefined ? document.createElement('b') : document.createDocumentFragment();
      for (const ch of m[1] ?? m[3]) {
        const s = document.createElement('span'); s.className = 'tl'; s.textContent = ch;
        box.appendChild(s); this.unita.push({ el: s, ch });
      }
      this.testo.appendChild(box);
    }
    this.k = 0; this.scrivendo = true; this.sillaba = 0;
    this.el.classList.remove('pronto');
    this.timer = setTimeout(() => this.lettera(), 180);
  }
  lettera() {
    if (!this.vivo) return;
    const u = this.unita[this.k++];
    if (!u) return this.completa();
    u.el.classList.add('on');
    let attesa = 24;
    if (/[.!?]/.test(u.ch) && this.unita[this.k]?.ch !== '.') attesa = 260;
    else if (/[,:;]/.test(u.ch)) attesa = 120;
    else if (/[\p{L}\p{N}]/u.test(u.ch) || u.ch === 'k') { if (this.sillaba++ % 2 === 0) this.bip(u.ch); }
    this.timer = setTimeout(() => this.lettera(), attesa);
  }
  completa() {
    clearTimeout(this.timer);
    this.unita.forEach(u => u.el.classList.add('on'));
    this.scrivendo = false;
    this.ritratto.classList.remove('bocca');
    this.el.classList.add('pronto');
    this.el.querySelector('[data-t="avanti"]').focus({ preventScroll: true });
  }

  /* ---------------- la voce: un bip di onda quadra per sillaba, come nei giochi a 8 bit */
  bip(ch) {
    // la bocca si apre e si chiude a ritmo
    this.ritratto.classList.add('bocca');
    clearTimeout(this.tBocca); this.tBocca = setTimeout(() => this.ritratto.classList.remove('bocca'), 55);
    const L = S.lettore;
    if (!L || L.muto || S.imp.voce_bit === false) return;
    const c = L.audio(); if (!c) return;
    if (c.state !== 'running') c.resume().catch(() => {});
    // altezza scelta dalla lettera (stessa lettera = stessa nota), su una scala pentatonica
    const scala = [0, 2, 4, 7, 9], codice = ch.toLowerCase().charCodeAt(0);
    const base = this.voceAcuta ? 523 : 262;
    const f = base * Math.pow(2, scala[codice % 5] / 12);
    const t = c.currentTime + .005, o = c.createOscillator(), g = c.createGain(), filtro = c.createBiquadFilter();
    o.type = 'square'; o.frequency.setValueAtTime(f, t); o.frequency.exponentialRampToValueAtTime(f * .94, t + .05);
    filtro.type = 'lowpass'; filtro.frequency.value = 2600;
    const vol = Math.max(.05, (L.volume ?? 60) / 100) * .09;
    g.gain.setValueAtTime(0, t); g.gain.linearRampToValueAtTime(vol, t + .004);
    g.gain.setValueAtTime(vol, t + .035); g.gain.linearRampToValueAtTime(0, t + .055);
    o.connect(filtro).connect(g).connect(c.destination);
    o.start(t); o.stop(t + .07);
  }

  /* ---------------- luci: i buchi nella maschera inseguono gli elementi */
  trova() {
    const visibile = sel => [...document.querySelectorAll(sel)].find(e => e.getClientRects().length && e.offsetWidth);
    return this.selettori.map(voce => [].concat(voce).reduce((trovato, sel) => trovato || visibile(sel), null)).filter(Boolean);
  }
  misura() {
    const m = 8;
    this.mete = this.trova().map(e => { const r = e.getBoundingClientRect();
      return { x: r.left - m, y: r.top - m, w: r.width + 2 * m, h: r.height + 2 * m }; });
    this.piazzaDialogo();
  }
  piazzaDialogo() {
    // il riquadro va in basso, a meno che copra quello che Bit sta indicando (allora va in alto)
    const h = (this.dialogo.offsetHeight || 220) + 56;
    const inBasso = this.mete.some(r => r.y + r.h > innerHeight - h), inAlto = this.mete.some(r => r.y < h);
    this.dialogo.classList.toggle('alto', inBasso && !inAlto);
    this.dialogo.classList.toggle('centro', !this.mete.length);
  }
  ciclo() {
    if (!this.vivo) return;
    if (this.selettori?.length) {
      // l'elemento può spostarsi (la vista si ridisegna, il codice si carica): si rimisura spesso
      if (performance.now() - (this._m || 0) > 150) { this._m = performance.now(); this.misura(); }
    }
    while (this.buchi.length < this.mete.length) {
      const r = this.mete[this.buchi.length];
      this.buchi.push({ x: r.x + r.w / 2, y: r.y + r.h / 2, w: 0, h: 0 });
    }
    if (this.buchi.length > this.mete.length) this.buchi = this.buchi.slice(0, this.mete.length);
    // avvicinamento che dipende dal tempo trascorso, non dal numero di fotogrammi
    const ora = performance.now(), passo = 1 - Math.exp(-Math.min(200, ora - (this._t || ora)) / 70);
    this._t = ora;
    this.buchi.forEach((b, k) => { const r = this.mete[k];
      for (const p of ['x', 'y', 'w', 'h']) b[p] += (r[p] - b[p]) * passo; });
    const html = (cls, extra) => this.buchi.map(b => `<rect class="${cls}" x="${b.x.toFixed(1)}" y="${b.y.toFixed(1)}" width="${Math.max(0, b.w).toFixed(1)}" height="${Math.max(0, b.h).toFixed(1)}" ${extra}/>`).join('');
    const rx = document.documentElement.dataset.tema === 'hacker' ? 0 : 12;
    this.gBuchi.innerHTML = html('', `rx="${rx}" fill="#000"`);
    this.gCornici.innerHTML = html('tour-cornice', `rx="${rx}"`);
    requestAnimationFrame(this.ciclo);
  }

  /* ---------------- fine */
  chiudi(saltato) {
    if (!this.vivo) return;
    this.vivo = false;
    clearTimeout(this.timer);
    removeEventListener('keydown', this.tasto, true);
    removeEventListener('resize', this.ridimensiona);
    this.el.classList.remove('vis'); this.el.classList.add('via');
    setTimeout(() => { this.el.remove(); document.body.classList.remove('in-tour'); S.bit?.aggiorna(); }, 280);
    this.fine?.(saltato);
  }
}

/* avvia il tour (dal primo avvio o da Impostazioni → Rivedi il tour) */
function avviaTour() {
  if (document.querySelector('.tour') || !S.cat) return;
  if (!$('#foglio').hidden) chiudiFoglio();
  if ($('#musica-dock').classList.contains('aperto')) S.lettore?.chiudi();
  S.tour = new Tour(saltato => {
    S.tour = null;
    salvaImp({ tour_visto: true });
    if (S.vista !== 'oggi') vai('oggi');
    if (saltato) avviso('Tour saltato: lo ritrovi in Impostazioni', 'ok');
    else { S.lettore?.effetto('missione'); setTimeout(() => S.bit?.reagisci('clic'), 600); }
  });
}
