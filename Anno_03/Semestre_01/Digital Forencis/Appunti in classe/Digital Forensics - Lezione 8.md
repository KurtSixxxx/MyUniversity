# Digital Forensics - Lezione 8

---

<Accenno sulla proiezione prospettica, dalla precedente lezione>

Nella proiezione prospettica i pixel vengono "ridisegnati" mediante una opportuna trasfromazione geometrica.

Bisogna dimostrare nella relazione teorica di non aver invertito nulla, dunque spiegare i dettagli dal processo in modo che l'altra parte possa ripeterli.

Si può:

- Scrivere il codice e fornirlo, ma non è detto che sia chiaro.

- Algoritmi standard, noti in letteratura. Si forniscono i parametri dell'algoritmo.

- Usare i tool specializzati in questo tipo di operazioni. (ad esempio Amped Five. Questi programmi forniscono un report alla fine del lavoro, che si può fornire alle parti)

- L'utilizzo di software open source non è sempre consigliato, per via dell'affidabilità dietro lo sviluppo del software stesso.

### Super Resolution

Il super resolution è un algoritmo che permette di aumentare la qualità di un'immagine su cui abbiamo effettuato uno zoom.

Quando si effettua lo zoom si "rovina" la qualità dell'immagine porzionata che abbiamo zoommato - c'è una ricostruzione di pixel molto più grandi - e dunque tramite l'algoritmo si attenuano i "grandi pixel" in modo da fornire un'immagine più di qualità.

Nel campo dell'informatica forense è molto utilizzato per il riconoscimento di immagini zoommate e sfocate.

L'algoritmo è costruito su una base di machine learning, a cui passo centinaia di migliaia di immagini di alta risoluzione. La macchina a questo punto, tramite statistica e banca dati dovuta a immagini precedenti, riesce a ricostruire l'immagine con quello che è più realistico.

### Source Interpol

L’effetto swirl è una tecnica di offuscamento visivo che distorce i pixel di un volto ruotandoli attorno a un centro, rendendo l’identità irriconoscibile.
L’effetto swirl viene applicato per nascondere i tratti somatici di una persona, ruotando i pixel in modo concentrico attorno a un punto centrale. Questo crea un vortice visivo che altera la posizione dei dettagli facciali, come occhi, naso e bocca. È una tecnica più distruttiva rispetto alla sfocatura, perché non si limita a rendere indistinti i contorni, ma li sposta fisicamente, rendendo difficile la ricostruzione diretta.
Gli informatici forensi intervengono cercando di invertire o aggirare l’effetto, usando modelli predittivi e confronti con immagini originali.

Gli informatici forensi affrontano l’effetto swirl con approcci diversi. Se l’intensità della distorsione è nota o stimabile, si può tentare un’inversione dell’effetto, ruotando i pixel in senso opposto. Tuttavia, questa operazione è complessa e raramente restituisce un volto perfettamente riconoscibile. Più spesso, si ricorre a tecniche di riconoscimento facciale basate su intelligenza artificiale, che confrontano l’immagine distorta con database di volti noti, cercando corrispondenze nei pattern residui. In alternativa, si analizzano elementi secondari dell’immagine, come lo sfondo, la postura o gli oggetti visibili, per raccogliere indizi utili all’identificazione.

### Fotogrammeria

La fotogrammetria, nel contesto della digital forensics, è una tecnica che consente di estrarre caratteristiche fisiche da contenuti multimediali, come video o fotografie. Tra queste caratteristiche, una delle più comuni è la stima dell’altezza di un soggetto ripreso. Questo processo si basa sull’analisi delle proporzioni visive, dei punti di riferimento presenti nell’immagine (come oggetti noti o strutture architettoniche), e sull’angolo di ripresa.

Poiché le immagini possono essere soggette a distorsioni prospettiche, variazioni di scala o qualità non uniforme, è fondamentale gestire l’incertezza nella misurazione. Per questo motivo, quando si stima l’altezza di una persona, il risultato viene espresso come un intervallo, preceduto da un simbolo "+/-", che indica il margine di errore associato alla stima. Ad esempio, un soggetto potrebbe risultare alto "170 cm +/- 5 cm", segnalando che l’altezza reale potrebbe variare entro quel range.

Un altro caso è la **ricostruzione 3D**. 
La ricostruzione 3D è una tecnica avanzata utilizzata nella digital forensics per rappresentare in modo realistico e tridimensionale la scena di un crimine, un incidente o un evento investigativo. Questa tecnologia consente di trasformare dati raccolti da fotografie, video, rilievi laser o scanner in modelli digitali navigabili, offrendo una visione immersiva e dettagliata. Bisogna anche essere fedeli alla fisica, per dimostrare i fatti realmente e scentificamente.
Nel contesto giudiziario, la ricostruzione 3D ha un impatto significativo: permette a giudici, avvocati, giurati e testimoni di visualizzare concretamente la dinamica dei fatti, superando le limitazioni delle descrizioni verbali o delle immagini bidimensionali. Si possono simulare movimenti, angoli di visuale, distanze, tempi di reazione e posizioni relative dei soggetti coinvolti, rendendo più chiara la comprensione degli eventi.

### Implicazioni in ambito "forense"

<>

### Nuove tecnologie

Si può costruire un ambiente 3D, tramite alcuni reticoli, per analizzare meglio e quando vogliamo la scena del crimine. Senza inquinare quest'ultima.

<>

---

### Ecco un'espansione dei tuoi appunti in formato Markdown, pronta per il copia-e-incolla e redatta con un tono discorsivo.

---

# La Struttura della Consulenza Tecnica in Digital Forensics

La consulenza tecnica, in ambito forense, è un ponte tra due mondi: quello tecnico-informatico e quello giuridico. Il nostro obiettivo primario, come consulenti, è rispondere in modo scientifico e oggettivo al **quesito tecnico** posto dal giudice. È fondamentale ricordare la distinzione tra *fatto* e *diritto*. Noi siamo i *periti* (Peritus), gli esperti del fatto tecnico: descriviamo cosa è accaduto a livello digitale, ad esempio chi ha creato un file, quando è stato cancellato o da quale indirizzo IP è partita un'email. Il giudice (Iudex), invece, valuta questi fatti e applica la legge per decidere sulla responsabilità legale. Non dobbiamo mai cadere nella tentazione di esprimere opinioni sulla colpevolezza o sull'interpretazione delle norme.

Una relazione tecnica ben scritta segue una struttura logica che guida il giudice (o l'avvocato, o il PM) attraverso un percorso complesso.

##### 1. Inquadramento del Contesto e del Mandato

Ogni consulenza tecnica deve iniziare definendo con precisione il suo contesto. Questa parte iniziale, gli **estremi del procedimento**, serve a identificare formalmente chi ci ha conferito l'incarico (la Procura, il Tribunale), qual è il numero del procedimento e chi sono le parti coinvolte (es. indagato, persona offesa, attore, convenuto). Definiamo anche il nostro ruolo, ad esempio Consulente Tecnico d'Ufficio (CTU) o di Parte (CTP).

Subito dopo, si passa al cuore del nostro mandato: il **testo del quesito**. Questo non è un riassunto, ma la trascrizione *letterale* della domanda, o delle domande, che il giudice ci ha posto. Il quesito definisce i confini invalicabili della nostra indagine; non possiamo indagare su aspetti non richiesti (il divieto di *ultra petita*). Se durante l'analisi emergono nuovi fatti rilevanti ma fuori dal mandato, abbiamo il dovere di segnalarli, ma non di analizzarli di nostra iniziativa senza un'estensione formale dell'incarico.

##### 2. Preparare il Terreno: Premesse e Dati

Prima di tuffarci nell'analisi, dobbiamo "preparare il terreno" per chi legge, che spesso non è un tecnico. Le **premesse tecniche** servono a questo: spieghiamo in termini semplici i concetti chiave che useremo (come 'hash', 'timestamp', 'spazio non allocato' o 'metadati') e citiamo gli standard internazionali che seguiamo, come le norme ISO o le best practice del NIST. In questa fase siamo anche trasparenti riguardo a eventuali limitazioni oggettive dell'analisi, ad esempio se un dispositivo ci è stato consegnato già danneggiato o se parte dei dati era irrimediabilmente sovrascritta.

A questo punto, descriviamo i **dati di lavoro**. È cruciale tracciare la **provenienza** dei reperti (smartphone, hard disk, server, ecc.) e garantire la loro integrità. Qui entra in gioco la **catena di conservazione** (Chain of Custody), che documenta chi ha maneggiato il reperto dal momento del sequestro fino alla nostra analisi.

L'operazione più critica è l'**acquisizione forense**: non lavoriamo mai sull'originale, ma su una sua copia identica, acquisita tramite metodi *bit-stream* (o *bit-by-bit*). Per dimostrare scientificamente che la nostra copia è perfetta, usiamo la funzione di **hash** (come SHA-256). Calcoliamo l'hash dell'originale e quello della copia: i due codici alfanumerici devono coincidere. Questo garantisce che la nostra analisi è fedele, difendibile e che il reperto originale non è stato minimamente alterato.

##### 3. L'Analisi: Metodologia e Risultati

Una volta acquisiti i dati in modo sicuro, spieghiamo la nostra **metodologia di lavoro**. Per essere scientifica, l'analisi deve essere trasparente, verificabile e, idealmente, ripetibile da altri esperti. In questa sezione descriviamo l'ambiente di analisi (la nostra workstation forense, i software usati come Autopsy, EnCase, UFED, ecc.) e le fasi logiche che abbiamo seguito.

Non è un semplice elenco di clic, ma una descrizione ragionata: ad esempio, potremmo spiegare di aver prima indicizzato tutti i dati, poi eseguito ricerche per parole chiave rilevanti per il quesito, successivamente analizzato lo spazio non allocato per recuperare file cancellati (*data carving*), e infine ricostruito una timeline degli eventi correlando i vari artefatti digitali.

Dopo aver spiegato *come* abbiamo lavorato, presentiamo i **risultati**, ovvero *cosa* abbiamo trovato. Questa è spesso la parte più corposa della relazione, dove esponiamo le prove digitali (log, file, email, messaggi, metadati) che abbiamo scoperto, correlandole tra loro per ricostruire la dinamica dei fatti tecnici.

##### 4. Le Conclusioni: La Risposta al Quesito

Infine, arriviamo alle **conclusioni**. Questa sezione non è altro che la **risposta diretta al quesito** iniziale. Riproponiamo la domanda del giudice e forniamo una risposta chiara, concisa e basata esclusivamente sui risultati tecnici emersi nell'analisi. È il momento di tirare le somme, sempre ricordando di rimanere nel nostro ambito: non diremo mai "Tizio è colpevole di accesso abusivo", ma piuttosto "Alle ore 10:30 del 5/10, l'account 'Tizio' si è connesso da un indirizzo IP esterno all'azienda e ha copiato il file 'budget.xls' su un drive USB".

Tutta la documentazione di supporto, come i log grezzi degli strumenti, l'elenco completo dei file rilevanti con i loro hash o le fotografie dei reperti, viene solitamente inserita negli **allegati** per non appesantire la lettura della relazione, pur garantendo la massima verificabilità del nostro operato.

<concludere appunti>
