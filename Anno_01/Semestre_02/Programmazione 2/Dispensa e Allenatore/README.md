# Programmazione 2 — Dispensa e Allenatore

Kit completo per preparare l'esame di **Programmazione 2** (C++, OOP e strutture dati dinamiche) dell'Università di Catania: una dispensa di circa 300 pagine e un'app per allenarsi su PC e telefono.

| | |
|---|---|
| **Dispensa** | 14 moduli, dalle classi ai grafi. Ogni modulo ha teoria con analogie, disegni della memoria, codice commentato, trappole d'esame, ~10 quiz a crocette, un laboratorio a step in stile esame, domande d'orale con risposta modello e 10 esercizi al PC. In appendice: piano di studio, simulazione d'esame completa, formulario, glossario, strategie per le tre prove. |
| **Soluzioni** | Volume separato con le soluzioni compilate ed eseguite di tutti gli esercizi. |
| **Allenatore (Windows)** | Quiz con simulazione d'esame (30 domande in 60 minuti), orale a flashcard, editor C++ che compila con `g++ -Wall -Wextra` e confronta l'output con la soluzione. Legge i contenuti direttamente dalla dispensa. |
| **Allenatore (telefono)** | Android e iPhone, si installa dal browser e funziona offline: quiz, orale, «Prevedi l'output», esercizi con soluzione. |
| **Bit** | Il compagno di studio: XP, livelli, missioni giornaliere, serie di giorni, 25 traguardi. Bit cresce con te (da uovo a Gigabyte). |
| **Musica** | Colonna sonora originale generata dal vivo, oppure la tua playlist Spotify o YouTube. |

Nel codice di laboratorio **non** si usa la STL: liste, pile, code, alberi e grafi sono scritti da zero con `new`/`delete`, come richiesto all'esame.

## Scaricare

- **Dispensa**: [`Dispensa/dispensa-light.pdf`](Dispensa/dispensa-light.pdf) (da stampare) o [`Dispensa/dispensa-dark.pdf`](Dispensa/dispensa-dark.pdf) (da schermo); soluzioni in [`Dispensa/soluzioni-light.pdf`](Dispensa/soluzioni-light.pdf) / [`soluzioni-dark.pdf`](Dispensa/soluzioni-dark.pdf).
- **App per Windows**: `Allenatore Prog2.exe` nelle [Releases](https://github.com/KurtSixxxx/MyUniversity/releases) del repository. Mettilo accanto alla cartella `Dispensa`.
- **App per telefono**: https://kurtsixxxx.github.io/MyUniversity/ — aprila dal telefono e aggiungila alla schermata Home.

Istruzioni complete (installazione, compilatore `g++`, telefono, sincronizzazione, problemi frequenti) nel capitolo **«Prima di iniziare»** della dispensa.

### In breve

1. Scarica dispensa ed eseguibile; installa `g++` con [MSYS2](https://www.msys2.org) (`pacman -S mingw-w64-ucrt-x86_64-gcc`, poi aggiungi `C:\msys64\ucrt64\bin` al `Path`).
2. Avvia l'Allenatore: al primo avvio scegli nome, data dell'appello, docente, colore e il nome del tuo compagno.
3. Ogni giorno: teoria sulla dispensa → quiz e codice nell'app → orale ad alta voce. Nei tempi morti, il telefono.
4. Telefono — **iPhone**: Safari → Condividi → *Aggiungi alla schermata Home*. **Android**: Chrome → ⋮ → *Installa app*.
5. PC e telefono si sincronizzano con un codice `P2:` da copiare e incollare (Impostazioni → Telefono). Nessun account, nessun server.

## Struttura del repository

```
Dispensa/      sorgenti LaTeX, PDF e codice/ (mNN/: pattern, lab, es01..es10, input, output)
Allenatore/    sorgenti dell'app (Python + pywebview, interfaccia HTML/CSS/JS in web/)
docs/          versione per telefono (pagina unica, PWA), pubblicata con GitHub Pages
```

## Contribuire

Errori nella dispensa, domande ambigue, esercizi che non compilano: apri una *issue* o una *pull request*.

- **Dispensa**: modifica i `.tex` in `Dispensa/`; i programmi in `Dispensa/codice/` vanno compilati ed eseguiti con `bash verifica_codice.sh mNN` (l'output nella dispensa è sempre quello reale). PDF: `compila.bat` o `bash build.sh` (serve MiKTeX o TeX Live).
- **App**: `cd Allenatore`, `python -m venv .ambiente`, `.ambiente\Scripts\pip install -r requirements.txt`, poi `.ambiente\Scripts\python app.py`. Eseguibile: `crea_app.bat --pubblica`. Versione per telefono: `.ambiente\Scripts\python mobile\crea_mobile.py --pubblica`. Tutto insieme: `prepara_pubblicazione.py`.
- Quiz, domande d'orale ed esercizi dell'app sono letti dalla dispensa: per aggiungerne uno basta scriverlo nel modulo, con gli ambienti `quiz`, `orale`, `esercizio`.

## Licenza

Come tutto il repository: Creative Commons BY-NC-SA 4.0.

## Avvertenze

Materiale di studio scritto da studenti, non ufficiale: in caso di dubbio valgono le slide e le indicazioni del docente. Le regole d'esame riportate (quiz a sbarramento, laboratorio, orale) vanno sempre verificate sulla pagina del corso.

## Crediti

Dispensa e Allenatore Prog2 sono un progetto di **Giulio Casella**, realizzato con l'aiuto di Claude (Anthropic).
