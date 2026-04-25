# Il paradosso di Russell spiegato agli stupidi

**Allora.**

Abbiamo un insieme **'S'**

Questo insieme **S** ha una regola: *"contiene tutti gli insiemi che non contengono se stessi"*.

**Chiariamo, inizialmente, cosa vuol dire "Insieme che contiene se stesso"**

- **Un insieme che non contiene se stesso**, è l'insieme Mela.
    
    L'insieme Mela contiene tutte le mele esistenti: mela rossa, mela gialla, mela verde, mela dolce, mela aspra, ecc..
    
    Ma l'insieme non è una mela, è solo un insieme, di cosa? Di mele. Quindi non può "auto-contenersi".
    
- **Un insieme che contiene se stesso**, è l'insieme "Insiemi".
    
    L'insieme Insiemi contiene tutti gli insiemi esistenti: l'insieme delle mele, l'insieme delle università, l'insieme delle bandiere, ecc...
    
    Questo insieme, dovrebbe contenersi, perché anche lui è un insieme, ma non può esistere. Perché: chi contiene questo insieme? Quindi è un insieme che si risucchia, come una scatola piena di scatole infinite: ma la scatola in sé dove sta? E' una specie di buco nero che si risucchia in continuazione. Quindi esiste e non esiste contemporaneamente.
    

---

**Torniamo alla nostra domanda: S appartiene ad S?**

Ricordiamoci la regola *"S contiene tutti gli insiemi che non contengono se stessi"*, tipo l'insieme Mela di prima.

Da qui arriviamo a 2 casi.

- **Caso 1: S appartiene ad S.**
    
    Vuol dire che S è un insieme che **contiene se stesso**. Allora S **non può** stare dentro S, perché la regola dice che S contiene solo insiemi che **non** contengono se stessi.
    
    Ed ecco la contraddizione del paradosso.
    
- **Caso 2: S NON appartiene ad S.**
    
    Vuol dire che S è un insieme che **non** contiene se stesso, e noi NON lo mettiamo dentro S.
    
    Ora se S non è dentro S ci rifacciamo la domanda rifacendoci alla regola: S contiene solo gli insiemi che non contengono se stessi. Ma allora S **dovrebbe** starci, perché non sta contenendo se stesso, e quindi rispetta la regola.
    
    Ed ecco la seconda contraddizione.
    

---

**Allora.**

Abbiamo visto che il paradosso nasce perché abbiamo fatto un insieme S con questa regola: *"contiene tutti gli insiemi che non contengono se stessi"*.

Il problema è che abbiamo preso **"tutti"** gli insiemi con una certa proprietà. È stato proprio quel **"tutti"** a creare il pasticcio, perché S finiva per parlare di se stesso e generava la contraddizione.

---

**Come si risolve?**

I matematici hanno detto: non possiamo permettere che un insieme venga definito prendendo **"tutti"** gli insiemi che hanno una certa proprietà. È troppo pericoloso, perché così si possono creare mostri come S che si auto-distruggono.

Allora hanno stabilito una regola nuova: **per costruire un insieme nuovo, dobbiamo sempre partire da un insieme che già esiste**. Così possiamo solo "filtrare" gli elementi di quell'insieme usando una proprietà.

**Facciamo un esempio.**

Se ho già un insieme **U** che conosco (per esempio, l'insieme di tutti gli studenti della mia scuola), allora posso costruire un insieme nuovo dicendo: *"l'insieme degli studenti di U che hanno i capelli biondi"*. Questo è sicuro, perché non sto prendendo "tutti" gli studenti del mondo, ma solo quelli che stanno dentro U.

---

**U e S sono due cose diverse**

- **U** è l'insieme di partenza, quello che già conosciamo e che esiste prima.
- **S** è l'insieme che costruiamo **dentro** U, filtrando i suoi elementi con una proprietà. Quindi S è un **sottoinsieme** di U.

**Applicando questa idea al paradosso**, invece di definire S come *"l'insieme di tutti gli insiemi che non contengono se stessi"*, lo definiamo così:

> **S = { A : A ⊆ U, e A ∉ A }**
> 

Cioè: **S** è l'insieme degli insiemi **A** che stanno dentro **U** e che **non contengono se stessi**.

**A** è un insieme qualsiasi che sta dentro **U**.

**S** è il gruppo di quegli **A** che hanno la proprietà *"non contenere se stessi"*.

**Quindi:**

- **U** è un insieme "grande" che abbiamo scelto all'inizio.
- **S** è un insieme più piccolo, fatto solo da **alcuni** sottoinsiemi di **U**.

**S non è uguale a U**. U contiene cose (insiemi), S è uno di quei sottoinsiemi.

---

**Perché non si ripete il paradosso?**

Perché **S non contiene "tutti" gli insiemi del mondo**, ma solo quelli che stanno dentro **U**.

Se provo a chiedere *"S appartiene a S?"*, non succede più niente di strano.

- Se **S non sta dentro U**, allora la domanda **"S ∈ S?"** non si pone nemmeno.
- Se invece **S sta dentro U**, allora si può rispondere senza contraddizione, perché S non è più un insieme mostruoso che contiene tutto.

---

**In altre parole, la soluzione è questa:**

Vietiamo di fare insiemi con **"tutti"** gli oggetti che hanno una proprietà. Permettiamo solo di fare insiemi **partendo da un insieme già esistente**.

- **U** è il *"contenitore sicuro"* che usiamo come punto di partenza.
- **S** è un **sottoinsieme** di U, non è U stesso.

Così evitiamo che S diventi un mostro che parla di tutti gli insiemi del mondo.

**Il paradosso di Russell non può più nascere.**