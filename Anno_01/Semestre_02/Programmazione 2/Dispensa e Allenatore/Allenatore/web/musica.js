/* =====================================================================
   Allenatore Prog2 — musica
   ---------------------------------------------------------------------
   Tre sorgenti, una alla volta:
   • Colonna sonora originale: brani generati dal vivo con Web Audio
     (nessun file audio, nessun diritto d'autore di terzi). Tre brani:
     «Concentrazione» (lo-fi), «Codice notturno» (synthwave), «Deep focus»
     (ambient). Gli accordi sono fissi, i dettagli (melodia, batteria)
     cambiano a ogni giro, così non stanca.
   • Spotify: lettore ufficiale incorporato (iFrame API). Con l'accesso
     a Spotify fatto nel lettore si sentono i brani interi.
   • YouTube: lettore ufficiale (IFrame API) ridotto a una miniatura:
     si ascolta la playlist in sottofondo mentre si studia.
   Condiviso tra app per PC e versione per telefono.
   ===================================================================== */
(function () {
  'use strict';

  /* ================================================================ motore della colonna sonora */
  const hz = n => { const m = /^([A-G])([#b]?)(-?\d)$/.exec(n); const b = { C: -9, D: -7, E: -5, F: -4, G: -2, A: 0, B: 2 }[m[1]] + (m[2] === '#' ? 1 : m[2] === 'b' ? -1 : 0); return 440 * Math.pow(2, (b + (+m[3] - 4) * 12) / 12); };
  const caso = a => a[Math.floor(Math.random() * a.length)];

  const BRANI = [
    { nome: 'Concentrazione', genere: 'lo-fi', bpm: 76, swing: .58, battute: 1,
      accordi: [['D3', 'F3', 'A3', 'C4', 'E4'], ['Bb2', 'D3', 'F3', 'A3'], ['F2', 'A2', 'C3', 'E3', 'G3'], ['C3', 'E3', 'G3', 'A3']],
      bassi: ['D2', 'Bb1', 'F1', 'A1'], scala: ['D4', 'F4', 'G4', 'A4', 'C5', 'D5', 'F5'] },
    { nome: 'Codice notturno', genere: 'synthwave', bpm: 104, swing: .5, battute: 1,
      accordi: [['D3', 'F3', 'A3', 'D4'], ['Bb2', 'D3', 'F3', 'Bb3'], ['F2', 'A2', 'C3', 'F3'], ['C3', 'E3', 'G3', 'C4']],
      bassi: ['D2', 'Bb1', 'F1', 'C2'], scala: ['D5', 'E5', 'F5', 'A5', 'C6'] },
    { nome: 'Deep focus', genere: 'ambient', bpm: 60, swing: .5, battute: 2,
      accordi: [['D3', 'A3', 'E4', 'F4'], ['Bb2', 'F3', 'A3', 'D4'], ['G2', 'D3', 'F3', 'A3', 'Bb3'], ['A2', 'E3', 'G3', 'D4']],
      bassi: ['D2', 'Bb1', 'G1', 'A1'], scala: ['A5', 'C6', 'D6', 'E6', 'F6', 'A6'] },
  ];

  class MotoreColonna {
    constructor(ctx, uscita) {
      this.ctx = ctx; const c = ctx;
      this.bus = c.createGain(); this.bus.gain.value = .8; this.bus.connect(uscita);
      this.riv = c.createConvolver();
      const n = Math.floor(c.sampleRate * 2.8), imp = c.createBuffer(2, n, c.sampleRate);
      for (let ch = 0; ch < 2; ch++) { const d = imp.getChannelData(ch); for (let i = 0; i < n; i++) d[i] = (Math.random() * 2 - 1) * Math.pow(1 - i / n, 2.8); }
      this.riv.buffer = imp;
      const rg = c.createGain(); rg.gain.value = .35; this.riv.connect(rg).connect(this.bus);
      this.eco = c.createDelay(1.5);
      const fb = c.createGain(); fb.gain.value = .33; const eo = c.createGain(); eo.gain.value = .3;
      this.eco.connect(fb).connect(this.eco); this.eco.connect(eo).connect(this.bus); eo.connect(this.riv);
      const r = c.createBuffer(1, c.sampleRate * 2, c.sampleRate), rd = r.getChannelData(0);
      for (let i = 0; i < rd.length; i++) rd[i] = Math.random() * 2 - 1;
      this.rumore = r;
      this.timer = null; this.brano = null;
    }
    voce({ note, t, dur, tipo = 'sawtooth', scordo = 6, vol = .1, att = .01, ril = .3, f0 = 2000, f1 = null, q = .8, riv = .25, eco = 0 }) {
      const c = this.ctx, filt = c.createBiquadFilter(), env = c.createGain();
      filt.type = 'lowpass'; filt.Q.value = q; filt.frequency.setValueAtTime(f0, t);
      if (f1 != null) filt.frequency.exponentialRampToValueAtTime(f1, t + dur);
      env.gain.setValueAtTime(0, t); env.gain.linearRampToValueAtTime(vol, t + att);
      env.gain.setValueAtTime(vol, t + Math.max(att, dur - ril)); env.gain.linearRampToValueAtTime(0, t + dur);
      filt.connect(env); env.connect(this.bus);
      if (riv) { const s = c.createGain(); s.gain.value = riv; env.connect(s).connect(this.riv); }
      if (eco) { const s = c.createGain(); s.gain.value = eco; env.connect(s).connect(this.eco); }
      for (const nota of note) {
        const f = typeof nota === 'number' ? nota : hz(nota);
        for (const d of scordo ? [-scordo, scordo] : [0]) {
          const o = c.createOscillator(); o.type = tipo; o.frequency.value = f; o.detune.value = d;
          o.connect(filt); o.start(t); o.stop(t + dur + .05);
        }
      }
    }
    colpo(t, { f = 1800, q = 1, dur = .15, vol = .2, tipo = 'bandpass', riv = .1 }) {
      const c = this.ctx, s = c.createBufferSource(); s.buffer = this.rumore;
      s.playbackRate.value = .8 + Math.random() * .4;
      const fl = c.createBiquadFilter(); fl.type = tipo; fl.frequency.value = f; fl.Q.value = q;
      const g = c.createGain(); g.gain.setValueAtTime(vol, t); g.gain.exponentialRampToValueAtTime(.001, t + dur);
      s.connect(fl).connect(g).connect(this.bus);
      if (riv) { const r = c.createGain(); r.gain.value = riv; g.connect(r).connect(this.riv); }
      s.start(t, Math.random()); s.stop(t + dur + .02);
    }
    cassa(t, vol = .55) {
      const c = this.ctx, o = c.createOscillator(), g = c.createGain();
      o.frequency.setValueAtTime(130, t); o.frequency.exponentialRampToValueAtTime(42, t + .18);
      g.gain.setValueAtTime(vol, t); g.gain.exponentialRampToValueAtTime(.001, t + .35);
      o.connect(g).connect(this.bus); o.start(t); o.stop(t + .4);
    }
    fruscio(on) {   // il crepitio del vinile del brano lo-fi
      if (this._vinile) { try { this._vinile.stop(); } catch (e) { /* già fermo */ } this._vinile = null; }
      if (!on) return;
      const c = this.ctx, s = c.createBufferSource(); s.buffer = this.rumore; s.loop = true; s.playbackRate.value = .5;
      const f = c.createBiquadFilter(); f.type = 'highpass'; f.frequency.value = 3500;
      const g = c.createGain(); g.gain.value = .012;
      s.connect(f).connect(g).connect(this.bus); s.start(); this._vinile = s;
    }
    avvia(i) {
      this.ferma();
      this.brano = BRANI[i] || BRANI[0]; this.indice = i;
      this.passo = 0; this.prossimo = this.ctx.currentTime + .08;
      this.fruscio(this.brano.genere === 'lo-fi');
      this.timer = setInterval(() => this.programma(), 25);
    }
    ferma() { clearInterval(this.timer); this.timer = null; this.fruscio(false); }
    programma() {
      const B = this.brano, sed = 60 / B.bpm / 4;
      while (this.prossimo < this.ctx.currentTime + .15) {
        const p = this.passo, inBattuta = p % 16, battuta = Math.floor(p / 16);
        const k = Math.floor(battuta / B.battute) % B.accordi.length;
        const swing = inBattuta % 2 ? (B.swing - .5) * 2 * sed : 0;
        this.suonaPasso(B, k, inBattuta, battuta, this.prossimo + swing, sed);
        this.prossimo += sed; this.passo++;
      }
    }
    suonaPasso(B, k, s, battuta, t, sed) {
      const acc = B.accordi[k], basso = B.bassi[k], inizioAcc = s === 0 && battuta % B.battute === 0;
      const durAcc = 16 * sed * B.battute;
      if (B.genere === 'lo-fi') {
        if (s === 0) this.voce({ note: acc, t, dur: sed * 9, tipo: 'triangle', scordo: 4, vol: .035, att: .02, ril: 1, f0: 1600, f1: 700, riv: .35 });
        if (s === 10 && Math.random() < .7) this.voce({ note: acc.slice(1), t, dur: sed * 6, tipo: 'triangle', scordo: 4, vol: .026, att: .02, ril: .8, f0: 1400, riv: .35 });
        if (s === 0 || s === 7 || s === 10) this.voce({ note: [basso], t, dur: sed * (s === 0 ? 6 : 3), tipo: 'sine', scordo: 0, vol: .2, att: .01, ril: .3, f0: 500, riv: 0 });
        if (s === 0 || s === 7 || (s === 10 && Math.random() < .5)) this.cassa(t, .38);
        if (s === 4 || s === 12) this.colpo(t, { f: 1700, q: .7, dur: .18, vol: .09, riv: .2 });
        if (s % 2 === 0) this.colpo(t, { f: 8000, q: 1.5, dur: .04, vol: .02 + Math.random() * .025, tipo: 'highpass', riv: 0 });
        if (Math.random() < .16 && s % 2 === 0) this.voce({ note: [caso(B.scala)], t, dur: sed * 3, tipo: 'sine', scordo: 0, vol: .045, att: .01, ril: .5, f0: 3000, riv: .3, eco: .5 });
      } else if (B.genere === 'synthwave') {
        if (s === 0) this.voce({ note: acc, t, dur: sed * 16, tipo: 'sawtooth', scordo: 9, vol: .022, att: .25, ril: .6, f0: 1300, f1: 2200, riv: .5 });
        if (s % 2 === 0) this.voce({ note: [s % 4 === 0 ? basso : basso.replace(/\d/, d => +d + 1)], t, dur: sed * 1.8, tipo: 'sawtooth', scordo: 3, vol: .07, att: .005, ril: .1, f0: 700, f1: 160, q: 4, riv: 0 });
        const nota = acc[[0, 1, 2, 3, 2, 1][s % 6] % acc.length].replace(/\d/, d => +d + 2);
        this.voce({ note: [nota], t, dur: sed * .8, tipo: 'square', scordo: 2, vol: .018, att: .003, ril: .08, f0: 3200, f1: 1200, riv: .2, eco: .6 });
        if (s % 4 === 0) this.cassa(t, .5);
        if (s === 4 || s === 12) this.colpo(t, { f: 1500, q: .6, dur: .3, vol: .12, riv: .55 });
        if (s % 4 === 2) this.colpo(t, { f: 9000, q: 1, dur: .05, vol: .03, tipo: 'highpass', riv: 0 });
        if (s === 14 && battuta % 4 === 3) this.voce({ note: [caso(B.scala)], t, dur: sed * 6, tipo: 'square', scordo: 5, vol: .025, att: .05, ril: .8, f0: 2500, riv: .5, eco: .5 });
      } else {   // ambient
        if (inizioAcc) {
          this.voce({ note: acc, t, dur: durAcc + 1.5, tipo: 'sawtooth', scordo: 10, vol: .02, att: 2.2, ril: 2.6, f0: 900, f1: 600, riv: .8 });
          this.voce({ note: [basso], t, dur: durAcc + .5, tipo: 'sine', scordo: 0, vol: .12, att: 1.5, ril: 1.5, f0: 400, riv: .2 });
        }
        if (s % 3 === 0 && Math.random() < .28) this.voce({ note: [caso(B.scala)], t, dur: 2.4, tipo: 'sine', scordo: 0, vol: .04, att: .005, ril: 2.2, f0: 5000, riv: .7, eco: .5 });
        if (s === 8 && Math.random() < .4) this.colpo(t, { f: 600, q: .4, dur: 2.5, vol: .02, tipo: 'lowpass', riv: .6 });
      }
    }
  }

  /* ================================================================ link -> identificativi */
  function uriSpotify(link) {
    link = String(link || '').trim();
    if (/^spotify:(playlist|album|track|artist|show|episode):\w+$/.test(link)) return link;
    const m = /open\.spotify\.com\/(?:intl-[a-z-]+\/)?(?:embed\/)?(playlist|album|track|artist|show|episode)\/([A-Za-z0-9]+)/.exec(link);
    return m ? `spotify:${m[1]}:${m[2]}` : null;
  }
  function idYouTube(link) {
    link = String(link || '').trim();
    const lista = /[?&]list=([A-Za-z0-9_-]+)/.exec(link);
    const video = /(?:youtu\.be\/|[?&]v=|\/embed\/|\/shorts\/)([A-Za-z0-9_-]{11})/.exec(link);
    if (!lista && !video) return null;
    return { lista: lista ? lista[1] : null, video: video ? video[1] : null };
  }
  const carica = {};
  function script(src) {
    return carica[src] || (carica[src] = new Promise((ok, no) => {
      const s = document.createElement('script'); s.src = src; s.async = true; s.onerror = () => { delete carica[src]; no(new Error('rete')); };
      document.head.appendChild(s); setTimeout(() => ok(), 0);
    }));
  }

  /* ================================================================ il lettore */
  const SORGENTI = [['colonna', 'Colonna sonora'], ['spotify', 'Spotify'], ['youtube', 'YouTube'], ['nessuna', 'Silenzio']];
  const ESC = s => String(s ?? '').replace(/[&<>"]/g, c => ({ '&': '&amp;', '<': '&lt;', '>': '&gt;', '"': '&quot;' }[c]));

  class Lettore {
    /* opz: { imp: () => impostazioni, salva: parz => void, dock: elemento, mini: [elementi],
              accediSpotify: () => void (solo PC), avviso: testo => void } */
    constructor(opz) {
      this.o = opz; this.ctx = null; this.motore = null; this.suona = false;
      this.spotify = null; this.spotifyPausa = true; this.yt = null; this.ytPronto = false;
      this.costruisciDock();
      this.aggiorna();
    }
    get imp() { return this.o.imp(); }
    get sorgente() { return this.imp.musica_sorgente || 'colonna'; }
    get muto() { return !!this.imp.musica_muto; }
    get volume() { return this.imp.musica_volume ?? 60; }
    salva(p) { this.o.salva(p); }

    /* ---------------- audio di base (colonna + effetti) */
    audio() {
      if (this.ctx) return this.ctx;
      const AC = window.AudioContext || window.webkitAudioContext;
      if (!AC) return null;
      this.ctx = new AC();
      this.master = this.ctx.createGain();
      const comp = this.ctx.createDynamicsCompressor(); comp.threshold.value = -16; comp.ratio.value = 3;
      this.analisi = this.ctx.createAnalyser(); this.analisi.fftSize = 64;
      this.master.connect(comp).connect(this.analisi).connect(this.ctx.destination);
      this.livelloColonna = this.ctx.createGain(); this.livelloColonna.connect(this.master);
      this.motore = new MotoreColonna(this.ctx, this.livelloColonna);
      this.applicaVolume();
      return this.ctx;
    }
    applicaVolume() {
      if (this.master) this.master.gain.setTargetAtTime(this.muto ? 0 : this.volume / 100 * .9, this.ctx.currentTime, .05);
      if (this.yt && this.ytPronto) { try { this.yt.setVolume(this.volume); this.muto ? this.yt.mute() : this.yt.unMute(); } catch (e) { /* non pronto */ } }
    }
    /* suoni brevi del gioco: XP, livello, traguardo (rispettano il muto) */
    effetto(tipo) {
      if (this.muto || this.imp.effetti === false) return;
      const c = this.audio(); if (!c) return;
      if (c.state !== 'running') c.resume().catch(() => {});
      const t = c.currentTime + .02, g = c.createGain(); g.connect(c.destination);
      const vol = Math.max(.05, this.volume / 100) * .22;
      const note = { xp: ['A5', 'E6'], livello: ['D5', 'F5', 'A5', 'D6', 'F6', 'A6'], traguardo: ['A5', 'C6', 'E6', 'A6'], missione: ['E5', 'A5', 'C#6'] }[tipo] || ['A5'];
      const passo = tipo === 'xp' ? .06 : .09;
      note.forEach((n, i) => {
        const o = c.createOscillator(), e = c.createGain(); o.type = tipo === 'xp' ? 'triangle' : 'square';
        o.frequency.value = hz(n); e.gain.setValueAtTime(0, t + i * passo);
        e.gain.linearRampToValueAtTime(vol * (tipo === 'xp' ? .8 : .5), t + i * passo + .01);
        e.gain.exponentialRampToValueAtTime(.001, t + i * passo + (i === note.length - 1 ? .7 : .25));
        o.connect(e).connect(g); o.start(t + i * passo); o.stop(t + i * passo + .8);
      });
    }

    /* ---------------- comandi */
    async play() {
      const s = this.sorgente;
      if (s === 'nessuna') return;
      this.suona = true;
      if (s === 'colonna') {
        const c = this.audio(); if (!c) return;
        try { await c.resume(); } catch (e) { /* bloccato finché non si tocca la pagina */ }
        if (!this.motore.timer || this.motore.indice !== (this.imp.musica_traccia || 0)) this.motore.avvia(this.imp.musica_traccia || 0);
      } else if (s === 'spotify') {
        await this.preparaSpotify();
        try {
          if (!this.spotify) return;
          if (!this.spotifyAvviato) { this.spotify.play(); this.spotifyAvviato = true; } else this.spotify.resume();
        } catch (e) { /* ignorato */ }
      } else if (s === 'youtube') {
        await this.preparaYouTube();
        try { this.yt?.playVideo(); } catch (e) { /* ignorato */ }
      }
      this.aggiorna();
    }
    pausa() {
      this.suona = false;
      this.motore?.ferma();
      try { this.spotify && !this.spotifyPausa && this.spotify.pause(); } catch (e) { /* ignorato */ }
      try { this.yt && this.ytPronto && this.yt.pauseVideo(); } catch (e) { /* ignorato */ }
      this.aggiorna();
    }
    alterna() { (this.suona ? this.pausa() : this.play()); }
    alternaMuto() {
      this.salva({ musica_muto: !this.muto });
      this.applicaVolume();
      if (this.sorgente === 'spotify' && this.spotify) {   // Spotify non ha il volume: muto = pausa
        try {
          if (this.muto) { this.pausaPerMuto = !this.spotifyPausa; this.spotify.pause(); }
          else if (this.pausaPerMuto) { this.pausaPerMuto = false; this.spotify.resume(); }
        } catch (e) { /* ignorato */ }
      }
      this.aggiorna();
    }
    successivo() {
      if (this.sorgente === 'colonna') { this.salva({ musica_traccia: ((this.imp.musica_traccia || 0) + 1) % BRANI.length }); if (this.suona) this.motore.avvia(this.imp.musica_traccia); this.aggiorna(); }
      else if (this.sorgente === 'youtube') { try { this.yt?.nextVideo(); } catch (e) { /* ignorato */ } }
    }
    precedente() {
      if (this.sorgente === 'colonna') { this.salva({ musica_traccia: ((this.imp.musica_traccia || 0) + BRANI.length - 1) % BRANI.length }); if (this.suona) this.motore.avvia(this.imp.musica_traccia); this.aggiorna(); }
      else if (this.sorgente === 'youtube') { try { this.yt?.previousVideo(); } catch (e) { /* ignorato */ } }
    }
    cambiaSorgente(s) {
      const suonava = this.suona;
      this.pausa();
      this.salva({ musica_sorgente: s });
      this.disegnaCorpo();
      if (s === 'spotify') this.preparaSpotify();
      if (s === 'youtube') this.preparaYouTube();
      if (suonava && s === 'colonna') this.play();
      this.aggiorna();
    }

    /* ---------------- Spotify */
    linkSpotify() { return this.imp.spotify_link || window.CONFIG?.spotifyPlaylist || ''; }
    async preparaSpotify(forza) {
      const uri = uriSpotify(this.linkSpotify());
      const box = this.dock.querySelector('.md-spotify');
      if (!uri) { box.querySelector('.md-embed').innerHTML = '<div class="md-vuoto">Incolla qui sopra il link di una playlist di Spotify.</div>'; return; }
      if (this.spotify && !forza) { if (this.spotifyUri !== uri) { this.spotify.loadUri(uri); this.spotifyUri = uri; this.spotifyAvviato = false; } return; }
      try {
        const api = await new Promise((ok, no) => {
          if (window.__spotifyApi) return ok(window.__spotifyApi);
          window.onSpotifyIframeApiReady = a => { window.__spotifyApi = a; ok(a); };
          script('https://open.spotify.com/embed/iframe-api/v1').catch(no);
          setTimeout(() => no(new Error('tempo')), 15000);
        });
        if (this.spotify) { try { this.spotify.destroy(); } catch (e) { /* ignorato */ } }
        const posto = document.createElement('div');
        box.querySelector('.md-embed').replaceChildren(posto);
        await new Promise(ok => api.createController(posto, { uri, width: '100%', height: 152, theme: 'dark' }, ctrl => {
          this.spotify = ctrl; this.spotifyUri = uri; this.spotifyAvviato = false;
          ctrl.addListener('playback_update', e => { this.spotifyPausa = !!e.data?.isPaused; if (this.sorgente === 'spotify') { this.suona = !this.spotifyPausa; this.aggiorna(); } });
          ok();
        }));
      } catch (e) {
        box.querySelector('.md-embed').innerHTML = '<div class="md-vuoto">Spotify non risponde: serve la connessione a Internet.</div>';
      }
    }

    /* ---------------- YouTube */
    linkYouTube() { return this.imp.youtube_link || window.CONFIG?.youtubePlaylist || ''; }
    async preparaYouTube(forza) {
      const id = idYouTube(this.linkYouTube());
      const box = this.dock.querySelector('.md-youtube .md-embed');
      if (!id) { box.innerHTML = '<div class="md-vuoto">Incolla qui sopra il link di una playlist (o di un video) di YouTube.</div>'; return; }
      const chiave = (id.lista || '') + '|' + (id.video || '');
      if (this.yt && this.ytChiave === chiave && !forza) return;
      try {
        await new Promise((ok, no) => {
          if (window.YT && window.YT.Player) return ok();
          const prima = window.onYouTubeIframeAPIReady;
          window.onYouTubeIframeAPIReady = () => { prima?.(); ok(); };
          script('https://www.youtube.com/iframe_api').catch(no);
          setTimeout(() => no(new Error('tempo')), 15000);
        });
        if (this.yt) { try { this.yt.destroy(); } catch (e) { /* ignorato */ } }
        this.ytPronto = false; this.ytChiave = chiave;
        const posto = document.createElement('div');
        box.replaceChildren(posto);
        const vars = { playsinline: 1, rel: 0, modestbranding: 1, controls: 1, origin: location.origin, widget_referrer: location.href };
        if (id.lista) { vars.listType = 'playlist'; vars.list = id.lista; } else { vars.loop = 1; vars.playlist = id.video; }
        this.yt = new YT.Player(posto, {
          width: 192, height: 108, videoId: id.lista ? undefined : id.video, playerVars: vars,
          events: {
            onReady: () => { this.ytPronto = true; this.applicaVolume(); if (this.suona && this.sorgente === 'youtube') this.yt.playVideo(); },
            onStateChange: e => { if (this.sorgente !== 'youtube') return; if (e.data === 1) this.suona = true; if (e.data === 2) this.suona = false; this.aggiorna(); },
            onError: e => { this.o.avviso?.(e.data === 150 || e.data === 101 || e.data >= 152 ? 'Questo video non si può riprodurre fuori da YouTube: salto al successivo' : 'YouTube: video non disponibile'); try { this.yt.nextVideo(); } catch (x) { /* ignorato */ } },
          },
        });
      } catch (e) {
        box.innerHTML = '<div class="md-vuoto">YouTube non risponde: serve la connessione a Internet.</div>';
      }
    }

    /* ---------------- interfaccia */
    costruisciDock() {
      const d = this.dock = this.o.dock;
      d.classList.add('musica-dock');
      d.innerHTML = `
        <div class="md-testa"><span class="md-titolo">MUSICA</span><span class="md-spazio"></span>
          <button class="md-chiudi" data-md="chiudi" title="Chiudi (la musica continua)">×</button></div>
        <div class="md-sorgenti">${SORGENTI.map(([k, t]) => `<button data-md="sorgente" data-s="${k}">${t}</button>`).join('')}</div>
        <div class="md-corpo">
          <div class="md-pannello md-colonna"></div>
          <div class="md-pannello md-spotify">
            <div class="md-riga"><input class="md-campo" data-md-campo="spotify" placeholder="Link di una playlist Spotify" spellcheck="false">
              <button class="md-btn" data-md="usa-spotify">Usa</button></div>
            <div class="md-embed"></div>
            <div class="md-nota">Per i brani interi accedi a Spotify ${this.o.accediSpotify ? 'con il pulsante qui sotto' : 'dal lettore (Accedi)'}: senza accesso Spotify fa sentire 30 secondi per brano.
              ${this.o.accediSpotify ? '<br><button class="md-btn" data-md="accedi-spotify">Accedi a Spotify</button>' : ''}
              <button class="md-link" data-md="predefinita-spotify">Torna alla playlist predefinita</button></div>
          </div>
          <div class="md-pannello md-youtube">
            <div class="md-riga"><input class="md-campo" data-md-campo="youtube" placeholder="Link di una playlist YouTube" spellcheck="false">
              <button class="md-btn" data-md="usa-youtube">Usa</button></div>
            <div class="md-yt-riga"><div class="md-embed"></div>
              <div class="md-nota">La playlist suona in sottofondo anche con questo pannello chiuso.
                <button class="md-link" data-md="predefinita-youtube">Torna alla playlist predefinita</button></div></div>
          </div>
          <div class="md-pannello md-nessuna"><div class="md-vuoto">Silenzio. A volte è la colonna sonora migliore.</div></div>
        </div>
        <div class="md-controlli">
          <button class="md-tasto" data-md="prec" title="Precedente">|&lt;</button>
          <button class="md-tasto grande" data-md="play" title="Riproduci / pausa"></button>
          <button class="md-tasto" data-md="succ" title="Successivo">&gt;|</button>
          <button class="md-tasto" data-md="muto" title="Muto"></button>
          <input type="range" min="0" max="100" class="md-volume" data-md-vol title="Volume">
        </div>`;
      d.addEventListener('click', ev => {
        const b = ev.target.closest('[data-md]'); if (!b) return;
        const a = b.dataset.md;
        if (a === 'chiudi') this.chiudi();
        else if (a === 'sorgente') this.cambiaSorgente(b.dataset.s);
        else if (a === 'play') this.alterna();
        else if (a === 'muto') this.alternaMuto();
        else if (a === 'succ') this.successivo();
        else if (a === 'prec') this.precedente();
        else if (a === 'brano') { this.salva({ musica_traccia: +b.dataset.i }); this.play(); this.disegnaCorpo(); }
        else if (a === 'usa-spotify') this.usaLink('spotify');
        else if (a === 'usa-youtube') this.usaLink('youtube');
        else if (a === 'predefinita-spotify') { this.salva({ spotify_link: '' }); this.disegnaCorpo(); this.preparaSpotify(); }
        else if (a === 'predefinita-youtube') { this.salva({ youtube_link: '' }); this.disegnaCorpo(); this.preparaYouTube(true); }
        else if (a === 'accedi-spotify') this.o.accediSpotify?.();
      });
      d.querySelector('[data-md-vol]').addEventListener('input', ev => {
        this.salva({ musica_volume: +ev.target.value, musica_muto: false }); this.applicaVolume(); this.aggiorna();
      });
      d.addEventListener('keydown', ev => { if (ev.key === 'Enter' && ev.target.dataset.mdCampo) this.usaLink(ev.target.dataset.mdCampo); ev.stopPropagation(); });
      this.disegnaCorpo();
      setInterval(() => this.disegnaOnde(), 140);
    }
    usaLink(tipo) {
      const v = this.dock.querySelector(`[data-md-campo="${tipo}"]`).value.trim();
      const ok = tipo === 'spotify' ? uriSpotify(v) : idYouTube(v);
      if (!ok) return this.o.avviso?.(tipo === 'spotify' ? 'Link di Spotify non riconosciuto (Condividi → Copia link)' : 'Link di YouTube non riconosciuto');
      this.salva({ [tipo + '_link']: v });
      if (this.sorgente !== tipo) this.cambiaSorgente(tipo);
      tipo === 'spotify' ? this.preparaSpotify() : this.preparaYouTube(true);
      this.o.avviso?.('Playlist impostata: premi play');
    }
    disegnaCorpo() {
      const s = this.sorgente, d = this.dock;
      d.dataset.sorgente = s;
      d.querySelectorAll('.md-sorgenti button').forEach(b => b.classList.toggle('attivo', b.dataset.s === s));
      const tr = this.imp.musica_traccia || 0;
      d.querySelector('.md-colonna').innerHTML = `<div class="md-brani">${BRANI.map((b, i) =>
        `<button class="md-brano ${i === tr ? 'attivo' : ''}" data-md="brano" data-i="${i}"><span class="md-num">0${i + 1}</span><span><b>${ESC(b.nome)}</b><small>${b.genere} · ${b.bpm} bpm</small></span></button>`).join('')}</div>
        <div class="md-nota">Colonna sonora originale dell'Allenatore, composta e suonata dal vivo dal tuo computer.</div>`;
      const sp = d.querySelector('[data-md-campo="spotify"]'), yt = d.querySelector('[data-md-campo="youtube"]');
      if (document.activeElement !== sp) sp.value = this.imp.spotify_link || '';
      if (document.activeElement !== yt) yt.value = this.imp.youtube_link || '';
      sp.placeholder = window.CONFIG?.spotifyPlaylist ? 'Predefinita del progetto · incolla un altro link' : 'Link di una playlist Spotify';
      yt.placeholder = window.CONFIG?.youtubePlaylist ? 'Predefinita del progetto · incolla un altro link' : 'Link di una playlist YouTube';
    }
    descrizione() {
      const s = this.sorgente;
      if (s === 'colonna') return BRANI[this.imp.musica_traccia || 0].nome;
      if (s === 'spotify') return 'Spotify';
      if (s === 'youtube') { try { return this.ytPronto && this.yt.getVideoData()?.title || 'YouTube'; } catch (e) { return 'YouTube'; } }
      return 'Musica spenta';
    }
    disegnaOnde() {
      const onde = [...document.querySelectorAll('.md-onde')];
      if (!onde.length) return;
      let barre;
      if (this.suona && !this.muto && this.sorgente === 'colonna' && this.analisi) {
        const dati = new Uint8Array(this.analisi.frequencyBinCount); this.analisi.getByteFrequencyData(dati);
        barre = [1, 2, 3, 4, 6, 8, 11, 14].map(i => dati[i] / 255);
      } else if (this.suona && !this.muto) barre = Array.from({ length: 8 }, (_, i) => .25 + .6 * Math.abs(Math.sin(Date.now() / 300 + i * 1.3)) * Math.random());
      else barre = Array(8).fill(0);
      const car = ' ▁▂▃▄▅▆▇█';
      const t = barre.map(v => car[Math.min(8, Math.round(v * 8))]).join('');
      onde.forEach(o => { o.textContent = t; });
    }
    aggiorna() {
      const d = this.dock;
      d.querySelector('[data-md="play"]').textContent = this.suona ? '||' : '>';
      d.querySelector('[data-md="muto"]').textContent = this.muto ? 'MUTO' : 'VOL';
      d.querySelector('[data-md="muto"]').classList.toggle('attivo', this.muto);
      d.querySelector('[data-md-vol]').value = this.volume;
      d.classList.toggle('suona', this.suona);
      for (const m of this.o.mini?.() || []) {
        m.innerHTML = `<button class="mm-play" data-mm="play" title="Riproduci / pausa">${this.suona ? '||' : '&gt;'}</button>
          <button class="mm-testo" data-mm="apri" title="Apri il lettore musicale"><span class="md-onde"></span><span class="mm-nome">${ESC(this.descrizione())}</span></button>
          <button class="mm-muto ${this.muto ? 'attivo' : ''}" data-mm="muto" title="${this.muto ? 'Riattiva l\'audio' : 'Muto'} (Ctrl+M)">${this.muto ? 'M' : '♪'}</button>`;
        m.onclick = ev => { const b = ev.target.closest('[data-mm]'); if (!b) return; const a = b.dataset.mm;
          a === 'play' ? this.alterna() : a === 'muto' ? this.alternaMuto() : this.apri(); };
      }
    }
    apri() { this.dock.classList.add('aperto'); this.disegnaCorpo(); if (this.sorgente === 'spotify') this.preparaSpotify(); if (this.sorgente === 'youtube') this.preparaYouTube(); }
    chiudi() { this.dock.classList.remove('aperto'); }
    alternaDock() { this.dock.classList.contains('aperto') ? this.chiudi() : this.apri(); }
    /* da chiamare dopo l'accesso a Spotify (PC): ricarica il lettore con i cookie nuovi */
    ricaricaSpotify() { this.spotify = null; this.preparaSpotify(true); }
  }

  window.Musica = { Lettore, BRANI, uriSpotify, idYouTube };
})();
