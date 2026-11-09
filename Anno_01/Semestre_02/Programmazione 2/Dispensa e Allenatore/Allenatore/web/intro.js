/* =====================================================================
   Allenatore Prog2 — intro «terminale» e colonna sonora
   ---------------------------------------------------------------------
   Musica: composizione originale sintetizzata dal vivo con Web Audio
   (nessun file audio). Re minore, 120 bpm: basso pulsante filtrato che
   sale, «riser» di rumore, colpo d'orchestra elettronica all'ACCESSO
   CONSENTITO (secondo 4), poi arpeggio con eco e pad che sfumano.
   Il momento del colpo è COLPO secondi dopo l'avvio: grafica e musica
   sono sincronizzate su quel numero.
   ===================================================================== */
const COLPO = 4.0;

class Colonna {
  constructor(volume = 0.55, contesto = null) {
    const AC = window.AudioContext || window.webkitAudioContext;
    this.ctx = contesto || (AC ? new AC() : null);
    if (!this.ctx) return;
    const c = this.ctx;
    this.master = c.createGain(); this.master.gain.value = volume;
    const comp = c.createDynamicsCompressor();
    comp.threshold.value = -14; comp.ratio.value = 4; comp.attack.value = .004; comp.release.value = .25;
    this.master.connect(comp).connect(c.destination);
    // riverbero: risposta all'impulso fatta di rumore che decade
    this.riv = c.createConvolver();
    const n = Math.floor(c.sampleRate * 3.2), imp = c.createBuffer(2, n, c.sampleRate);
    for (let ch = 0; ch < 2; ch++) {
      const d = imp.getChannelData(ch);
      for (let i = 0; i < n; i++) d[i] = (Math.random() * 2 - 1) * Math.pow(1 - i / n, 2.6);
    }
    this.riv.buffer = imp;
    this.rivGain = c.createGain(); this.rivGain.gain.value = .42;
    this.riv.connect(this.rivGain).connect(this.master);
    // eco a croma puntata per l'arpeggio
    this.eco = c.createDelay(1); this.eco.delayTime.value = .375;
    const fb = c.createGain(); fb.gain.value = .38;
    const ecoOut = c.createGain(); ecoOut.gain.value = .35;
    this.eco.connect(fb).connect(this.eco); this.eco.connect(ecoOut).connect(this.master); ecoOut.connect(this.riv);
    // rumore bianco riutilizzabile
    const r = c.createBuffer(1, c.sampleRate * 2, c.sampleRate), rd = r.getChannelData(0);
    for (let i = 0; i < rd.length; i++) rd[i] = Math.random() * 2 - 1;
    this.rumore = r;
  }
  get bloccata() { return !this.ctx || this.ctx.state !== 'running'; }
  async sblocca() { try { await this.ctx?.resume(); } catch (e) { /* niente audio */ } return !this.bloccata; }

  static hz(nota) {               // 'D2', 'A#3', 'Bb1'
    const m = /^([A-G])([#b]?)(-?\d)$/.exec(nota);
    const base = { C: -9, D: -7, E: -5, F: -4, G: -2, A: 0, B: 2 }[m[1]] + (m[2] === '#' ? 1 : m[2] === 'b' ? -1 : 0);
    return 440 * Math.pow(2, (base + (+m[3] - 4) * 12) / 12);
  }
  _uscita(destinazioni) { const g = this.ctx.createGain(); destinazioni.forEach(d => g.connect(d)); return g; }

  // una «voce» di sintetizzatore: oscillatori un po' scordati -> filtro -> inviluppo
  voce({ note, t, dur, tipo = 'sawtooth', scordo = 9, vol = .1, att = .01, ril = .3, f0 = 2000, f1 = null, q = 1, verso = [this.master], riv = .3 }) {
    const c = this.ctx, filt = c.createBiquadFilter(), env = c.createGain();
    filt.type = 'lowpass'; filt.Q.value = q;
    filt.frequency.setValueAtTime(f0, t);
    if (f1 != null) filt.frequency.exponentialRampToValueAtTime(f1, t + dur);
    env.gain.setValueAtTime(0, t);
    env.gain.linearRampToValueAtTime(vol, t + att);
    env.gain.setValueAtTime(vol, t + Math.max(att, dur - ril));
    env.gain.linearRampToValueAtTime(0, t + dur);
    filt.connect(env);
    verso.forEach(d => env.connect(d));
    if (riv) { const s = c.createGain(); s.gain.value = riv; env.connect(s).connect(this.riv); }
    for (const nota of note) {
      const f = typeof nota === 'number' ? nota : Colonna.hz(nota);
      for (const d of scordo ? [-scordo, 0, scordo] : [0]) {
        const o = c.createOscillator(); o.type = tipo; o.frequency.value = f; o.detune.value = d;
        o.connect(filt); o.start(t); o.stop(t + dur + .05);
      }
    }
    return filt;
  }

  suona() {
    if (!this.ctx) return;
    const c = this.ctx, T = c.currentTime + .06, sed = .125;   // sedicesimo a 120 bpm
    this.inizio = T;

    // 1. bordone grave che cresce
    this.voce({ note: ['D1'], t: T, dur: 11, tipo: 'sine', scordo: 0, vol: .32, att: 2.5, ril: 3, f0: 400, riv: 0 });
    this.voce({ note: ['D2'], t: T, dur: COLPO, tipo: 'sawtooth', scordo: 6, vol: .05, att: 2.5, ril: .2, f0: 140, f1: 600, riv: .2 });

    // 2. basso pulsante a sedicesimi con filtro che si apre (la «tensione»)
    const radici = t => t < COLPO ? 'D2' : t < COLPO + 2 ? 'D2' : t < COLPO + 4 ? 'Bb1' : 'C2';
    for (let i = 0; T + i * sed < T + COLPO + 6; i++) {
      const t = i * sed, acc = i % 4 === 0;
      const apertura = t < COLPO ? 160 + 1500 * Math.pow(t / COLPO, 2) : 900;
      this.voce({ note: [radici(t)], t: T + t, dur: sed * .92, scordo: 4, vol: (t < COLPO ? .05 + .07 * t / COLPO : .1) * (acc ? 1.25 : 1),
                  att: .004, ril: .08, f0: apertura * (acc ? 1.4 : 1), f1: 120, q: 7, riv: .08 });
    }

    // 3. riser di rumore che sale fino al colpo
    const rs = c.createBufferSource(); rs.buffer = this.rumore; rs.loop = true;
    const bp = c.createBiquadFilter(); bp.type = 'bandpass'; bp.Q.value = 2.5;
    bp.frequency.setValueAtTime(250, T + 1.4); bp.frequency.exponentialRampToValueAtTime(7000, T + COLPO);
    const rg = c.createGain(); rg.gain.setValueAtTime(0, T + 1.4); rg.gain.linearRampToValueAtTime(.16, T + COLPO - .05);
    rg.gain.linearRampToValueAtTime(0, T + COLPO + .02);
    rs.connect(bp).connect(rg).connect(this.master); rs.start(T + 1.4); rs.stop(T + COLPO + .1);

    // 4. IL COLPO: accordo enorme di Re minore + boato sub + scoppio di rumore
    const H = T + COLPO;
    this.voce({ note: ['D2', 'A2', 'D3', 'F3', 'A3', 'D4'], t: H, dur: 5.2, scordo: 12, vol: .085, att: .015, ril: 3.2,
                f0: 5200, f1: 380, q: 1.2, riv: .55 });
    this.voce({ note: ['D1', 'D2'], t: H, dur: 4.5, tipo: 'square', scordo: 5, vol: .05, att: .01, ril: 3, f0: 900, f1: 90, riv: .3 });
    const boom = c.createOscillator(), bg = c.createGain();
    boom.frequency.setValueAtTime(120, H); boom.frequency.exponentialRampToValueAtTime(32, H + .9);
    bg.gain.setValueAtTime(.9, H); bg.gain.exponentialRampToValueAtTime(.001, H + 1.6);
    boom.connect(bg).connect(this.master); boom.start(H); boom.stop(H + 1.7);
    const sc = c.createBufferSource(); sc.buffer = this.rumore;
    const sf = c.createBiquadFilter(); sf.type = 'lowpass'; sf.frequency.setValueAtTime(9000, H); sf.frequency.exponentialRampToValueAtTime(300, H + .6);
    const sg = c.createGain(); sg.gain.setValueAtTime(.35, H); sg.gain.exponentialRampToValueAtTime(.001, H + .7);
    sc.connect(sf).connect(sg); sg.connect(this.master); sg.connect(this.riv); sc.start(H); sc.stop(H + .8);

    // 5. pad che proseguono: Re minore -> Si bemolle -> Do (sospeso, «continua...»)
    this.voce({ note: ['Bb2', 'F3', 'Bb3', 'D4'], t: H + 2, dur: 3, scordo: 10, vol: .045, att: .9, ril: 1.2, f0: 1600, f1: 900, riv: .6 });
    this.voce({ note: ['C3', 'G3', 'C4', 'E4'], t: H + 4, dur: 3.6, scordo: 10, vol: .045, att: .9, ril: 2.6, f0: 1500, f1: 500, riv: .7 });

    // 6. arpeggio luminoso con eco, dopo il colpo
    const arp = [['D5', 'A4', 'F4', 'A4'], ['D5', 'Bb4', 'F4', 'Bb4'], ['E5', 'C5', 'G4', 'C5']];
    for (let i = 0; i < 48; i++) {
      const t = H + .5 + i * sed, giro = arp[Math.min(2, Math.floor((t - H) / 2))];
      const sfuma = Math.max(0, 1 - Math.max(0, i - 30) / 18);
      this.voce({ note: [giro[i % 4]], t, dur: sed * .8, tipo: 'square', scordo: 3, vol: .022 * sfuma * (i < 4 ? (i + 1) / 4 : 1),
                  att: .003, ril: .07, f0: 3800, f1: 1400, q: 2, verso: [this.master, this.eco], riv: .25 });
    }
  }

  sfuma(secondi = 1.2) {
    if (!this.ctx) return;
    const g = this.master.gain, t = this.ctx.currentTime;
    g.cancelScheduledValues(t); g.setValueAtTime(g.value, t); g.linearRampToValueAtTime(0, t + secondi);
    setTimeout(() => this.ctx.close().catch(() => {}), secondi * 1000 + 200);
  }
}

/* ---------------------------------------------------------------- grafica */
const BANNER = [
  '██████╗ ██████╗  ██████╗  ██████╗ ██████╗ ',
  '██╔══██╗██╔══██╗██╔═══██╗██╔════╝ ╚════██╗',
  '██████╔╝██████╔╝██║   ██║██║  ███╗ █████╔╝',
  '██╔═══╝ ██╔══██╗██║   ██║██║   ██║██╔═══╝ ',
  '██║     ██║  ██║╚██████╔╝╚██████╔╝███████╗',
  '╚═╝     ╚═╝  ╚═╝ ╚═════╝  ╚═════╝ ╚══════╝',
].join('\n');

const MOTTI = [
  'Ogni segmentation fault di oggi è un errore in meno all\'esame.',
  'Il compilatore non giudica: ti dice dove guardare. Ascoltalo.',
  'Un puntatore alla volta. Un nodo alla volta. Un giorno alla volta.',
  'Ogni bug trovato oggi è un bug che all\'esame non ti troverà.',
  'Chi disegna la memoria su carta non si perde tra i puntatori.',
  'Compila. Esegui. Correggi. Ripeti. Fino al 30.',
  'delete a ciò che ti frena, new a ciò che ti serve.',
  'Il laboratorio premia chi ha le mani allenate, non chi ha letto di più.',
  'La differenza tra «lo so» e «lo so scrivere» si chiama pratica. Inizia ora.',
  'Missione: superare Programmazione 2. Stato: in corso. Fallimento: non previsto.',
];

const GLIFI = '01{}<>[]();*&#=+-/\\|ABCDEF0123456789';
const HEX_SORGENTI = ['Nodo<T>* testa', 'delete[] arr;', 'virtual ~Base()', 'return *this;', 'template<class T>',
  'p->succ = q;', 'O(n log n)', 'BST::inserisci', 'dynamic_cast<D*>', 'operator<<'];
const esadecimale = s => [...s].map(c => c.charCodeAt(0).toString(16).padStart(2, '0')).join(' ');
const attendiIntro = ms => new Promise(r => setTimeout(r, ms));

function pioggia(canvas) {
  const g = canvas.getContext('2d');
  const cs = getComputedStyle(document.documentElement);
  const rgb = (cs.getPropertyValue('--fosforo-rgb') || '51, 255, 153').trim(), chiaro = 'rgba(255,255,255,.85)';
  let w, h, colonne, y, intens = .25, vivo = true;
  const dim = () => {
    w = canvas.width = canvas.offsetWidth; h = canvas.height = canvas.offsetHeight;
    colonne = Math.ceil(w / 16); y = Array.from({ length: colonne }, () => Math.random() * -h / 16);
  };
  dim(); addEventListener('resize', dim);
  const giro = () => {
    if (!vivo) return;
    g.fillStyle = 'rgba(0,0,0,.12)'; g.fillRect(0, 0, w, h);
    g.font = '14px Cascadia Mono, Consolas, monospace';
    for (let i = 0; i < colonne; i++) {
      if (Math.random() > intens && y[i] < 0) { y[i] += .2; continue; }
      const ch = GLIFI[Math.floor(Math.random() * GLIFI.length)];
      g.fillStyle = Math.random() < .06 ? chiaro : `rgba(${rgb},.75)`;
      g.fillText(ch, i * 16, y[i] * 16);
      y[i] = y[i] * 16 > h && Math.random() > .97 ? 0 : y[i] + 1;
    }
    requestAnimationFrame(giro);
  };
  requestAnimationFrame(giro);
  return { set intensita(v) { intens = v; }, ferma() { vivo = false; removeEventListener('resize', dim); } };
}

/**
 * Mostra l'intro sopra l'app. dati = {nome, giorni, quiz, orale, esercizi, gpp, versione, musica,
 *   professore, corso, sigla, livello, pet}
 * Restituisce una Promise che si risolve quando l'intro è finita (o saltata).
 */
function avviaIntro(dati) {
  return new Promise(async fine => {
    const el = document.createElement('div');
    el.className = 'intro';
    el.innerHTML = `<canvas></canvas><div class="intro-log"></div>
      <div class="intro-centro"><pre class="intro-banner"></pre><div class="intro-accesso">ACCESSO CONSENTITO</div>
        <div class="intro-motto"></div></div>
      <div class="intro-flash"></div><div class="intro-salta">[ ESC ] SALTA</div>`;
    document.body.appendChild(el);
    const $i = s => el.querySelector(s);
    const rain = pioggia($i('canvas'));
    let finito = false, musica = null;

    const chiudi = (veloce) => {
      if (finito) return; finito = true;
      removeEventListener('keydown', tasto, true); el.removeEventListener('click', clic);
      musica?.sfuma(veloce ? .6 : 2.6);
      el.classList.add('via');
      setTimeout(() => { rain.ferma(); el.remove(); }, 750);
      fine();
    };
    let attesa = null;   // se l'audio è bloccato: si aspetta un tasto per partire
    const tasto = ev => {
      ev.preventDefault(); ev.stopPropagation();
      if (attesa) { const a = attesa; attesa = null; return a(); }
      if (ev.key === 'Escape' || ev.key === 'Enter' || ev.key === ' ') chiudi(true);
    };
    const clic = () => { if (attesa) { const a = attesa; attesa = null; a(); } else chiudi(true); };
    addEventListener('keydown', tasto, true); el.addEventListener('click', clic);

    // ---- audio: parte subito se il browser lo permette, altrimenti al primo tasto
    if (dati.musica) {
      musica = new Colonna();
      if (musica.ctx && !(await musica.sblocca())) {
        $i('.intro-centro').insertAdjacentHTML('beforeend', '<div class="intro-invio">&gt; PREMI [INVIO] PER AUTENTICARTI<span class="cur">_</span></div>');
        await new Promise(r => { attesa = r; });
        $i('.intro-invio')?.remove();
        await musica.sblocca();
      }
      if (finito) return;
      musica.suona();
    }
    const t0 = performance.now();
    const a = ms => attendiIntro(Math.max(0, ms - (performance.now() - t0)));   // aspetta fino al ms ms dall'inizio

    // ---- 1. log di avvio
    const log = $i('.intro-log');
    const nome = (dati.nome || 'studente').toUpperCase();
    const righe = [
      ['dim', `PROG2-OS ${dati.versione || ''} // terminale d'addestramento // nodo ${(dati.sigla || 'UNICT').toUpperCase()}`],
      ['', ''],
      ['', '[ BOOT ] verifica memoria heap ...................... ', 'ok', '[ OK ]'],
      ['', `[ NET  ] collegamento cifrato al nodo ${(dati.sigla || 'UNICT').toUpperCase().slice(0, 8).padEnd(8, ' ')} ... `.padEnd(53, '.') + ' ', 'ok', '[ OK ]'],
      ['', '[ AUTH ] identificazione agente ..................... ', 'ok', nome],
      ...(dati.professore ? [['', '[ EXAM ] commissione ................................ ', 'att', ('PROF. ' + dati.professore).toUpperCase()]] : []),
      ...(dati.livello ? [['', `[ ${String(dati.pet || 'BIT').toUpperCase().slice(0, 4).padEnd(4, ' ')} ] compagno di studio .......................... `, 'ok', `LIVELLO ${dati.livello}`]] : []),
      ['hex'],
      ['', '[ LOAD ] quiz a crocette ............................ ', 'ok', String(dati.quiz)],
      ['', '[ LOAD ] interrogazioni orali ....................... ', 'ok', String(dati.orale)],
      ['', '[ LOAD ] esercizi al PC ............................. ', 'ok', String(dati.esercizi)],
      ['hex'],
      ['', '[ g++  ] compilatore ................................ ', dati.gpp ? 'ok' : 'att', dati.gpp ? 'ONLINE' : 'NON TROVATO'],
      ['barra'],
      ['', dati.giorni > 0 ? `[ WARN ] esame tra ${dati.giorni} giorni: priorità ` : '[ WARN ] priorità ', 'att', 'MASSIMA'],
    ];
    const passo = Math.min(230, 2700 / righe.length);
    for (let k = 0; k < righe.length && !finito; k++) {
      const [cls, testo, cls2, esito] = righe[k], riga = document.createElement('div');
      log.appendChild(riga);
      if (cls === 'hex') {
        const s = HEX_SORGENTI[Math.floor(Math.random() * HEX_SORGENTI.length)];
        riga.className = 'dim';
        riga.textContent = `0x${(0x7ffe0000 + Math.floor(Math.random() * 0xffff)).toString(16)}  ${esadecimale(s).padEnd(54)} ${s}`;
      } else if (cls === 'barra') {
        for (let p = 0; p <= 20 && !finito; p++) {
          riga.textContent = `[ DECR ] decrittazione dispensa  [${'#'.repeat(p)}${'.'.repeat(20 - p)}] ${String(p * 5).padStart(3)}%`;
          await attendiIntro(passo / 7);
        }
      } else {
        riga.className = cls;
        for (let i = 0; i <= testo.length && !finito; i += 4) { riga.textContent = testo.slice(0, i); await attendiIntro(passo / testo.length * 3); }
        riga.textContent = testo;
        if (esito) riga.insertAdjacentHTML('beforeend', `<span class="${cls2}">${esito.replace(/</g, '&lt;')}</span>`);
      }
      await attendiIntro(passo * .35);
    }
    if (finito) return;

    // ---- 2. il banner si «decritta»
    await a((COLPO - 1.1) * 1000);
    if (finito) return;
    rain.intensita = .9;
    log.style.transition = 'opacity .6s'; log.style.opacity = '.18';
    const ban = $i('.intro-banner'), dur = 1000, inizio = performance.now();
    await new Promise(r => {
      const giro = () => {
        if (finito) return r();
        const p = Math.min(1, (performance.now() - inizio) / dur);
        ban.textContent = [...BANNER].map(ch => ch === '\n' || ch === ' ' ? ch
          : Math.random() < p * p ? ch : GLIFI[Math.floor(Math.random() * GLIFI.length)]).join('');
        if (p < 1) setTimeout(giro, 33); else r();
      };
      giro();
    });
    if (finito) return;

    // ---- 3. ACCESSO CONSENTITO (in sincrono con il colpo della musica)
    await a(COLPO * 1000);
    if (finito) return;
    ban.textContent = BANNER;
    ban.classList.add('impatto');
    $i('.intro-flash').classList.add('vai');
    $i('.intro-accesso').classList.add('vis');
    rain.intensita = .35;

    // ---- 4. il conto alla rovescia e un motto
    await a(COLPO * 1000 + 800);
    const motto = $i('.intro-motto');
    const prima = dati.giorni > 0 ? `T-MINUS <b>${dati.giorni}</b> ${dati.giorni === 1 ? 'GIORNO' : 'GIORNI'} ALL'ESAME`
      : dati.giorni === 0 ? '<b>OGGI</b> È IL GIORNO DELL\'ESAME' : 'BENTORNATO, AGENTE';
    const frase = MOTTI[Math.floor(Math.random() * MOTTI.length)];
    motto.innerHTML = prima + '<br><span class="frase"></span><span class="cur">_</span>';
    const sp = motto.querySelector('.frase');
    for (let i = 0; i <= frase.length && !finito; i++) { sp.textContent = frase.slice(0, i); await attendiIntro(26); }

    await a(COLPO * 1000 + 4300);
    chiudi(false);
  });
}
