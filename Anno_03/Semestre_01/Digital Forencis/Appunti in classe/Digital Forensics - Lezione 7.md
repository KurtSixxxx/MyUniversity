# Digital Forensics - Lezione 7

### Cos'è l'hash?

<?>

### SHA (Secure Hash Algorithm)

Lo SHA è una famiglia di cinque diverse funzioni cittografiche di hash sviluppate dalla National Security Agency. Sono: SHA-1, SHA-224, SHA-256, SHA-384 e SHA-512. Le ultime 4 varianti sono indicate genericaemte come SHA-2.

Lo SHA produce un *message digest*, o "impronta del messaggio", di lunghezza fissa partendo da un messaggio di lunghezza variabile. La sicurezza di u Algoritmo di *hash* risiede nel fatto che la funzione non sia invertibile (non sia cioè possibile risalire al messaggio originale conoscendo solo questo dato) e che non deve essere mai possibile creare *intenzionalmente* due messaggi diversi con lo stesso *digest*.

Il primo SHA produce un digest di soli 160bit, mentre gli altri producono un digest pari al numero indicato nella loro sigla. Il più diffuso della famiglia SHA è lo SHA-1

### Integrità $\neq$ Autenticità

In ambito di informatica forense, la distinzione tra autenticità e integrità è cruciale, sebbene i due concetti siano spesso correlati. 

- **Autenticità**: Si riferisce alla garanzia che l'immagine o il dato digitale sia una rappresentazione fedele dell'evento originale. In altre parole, attesta l'identità del creatore o del sottoscrittore (come nel caso della firma digitale) e il legame con la sua fonte originaria.

- **Integrità**: Garanzia che il dato non sia stato alterato o manomesso dal momento della sua acquisizione o sottoscrizione fino alla sua disposizione finale. L'integrità viene spesso verificata tramite funzioni di hash, che producono un'impronta digitale univoca del file; se il valore hash cambia, significa che il file è stato modificato. 
  
  Vediamo come diverse operazioni influiscano su questi due aspetti:
  
  1. **Compressione/Salvataggio JPEG**: L'operazione non altera la rappresentazione originale dell'immagine (mantiene l'autenticità), ma modifica i dati del file, compromettendone l'integrità.
  
  2. **Caricamento e Scaricamento da Social Network o Online**: Similmente alla compressione, il processo non compromette l'autenticità dell'immagine originale, ma la modifica a causa del processo di compressione della piattaforma, annullando l'integrità dei dati.
  
  3. **Operazioni di elaborazione dell'immagine**: Modificano l'immagine stessa, compromettendo sia l'autenticità che l'integrità.
  
  4. **Recapture di un'immagine falsa**: L'immagine è di per sé una rappresentazione di un falso, quindi non è autentica. Tuttavia, se l'immagine non viene alterata dal momento dell'acquisizione, può mantenere la sua integrità forense come prova digitale di un falso.
  
  5. **Messa in scena (Staging)**: L'immagine rappresenta una scena costruita e non un evento reale, quindi non è autentica. L'integrità, però, è mantenuta se l'immagine non subisce modifiche successive.

### Dispositivi di memorizzazione

Quest'ultima avviene a diversi livelli:

- livello **logico**: Il livello logico riguarda la prospettiva dell'utente e del sistema operativo. 
  
  - **Gestione dei dati:** Si riferisce alla struttura e all'organizzazione dei dati, come la gestione di file, directory e partizioni, che sono come vengono visti dall'utente.
  - **Strumenti:** Include i file system (come NTFS, FAT32 o ext4) e altre strutture che il sistema operativo usa per allocare, recuperare e gestire i dati.
  - **Analisi forense:** Nell'informatica forense, un'acquisizione logica crea un'immagine dei file e delle cartelle visibili all'utente. Questa analisi può rivelare prove relative a file cancellati ma ancora recuperabili, o a strutture di file danneggiate.

- livello **fisico**: Il livello fisico riguarda la rappresentazione effettiva dei dati sul supporto di memorizzazione, indipendentemente dalla loro organizzazione logica. 
  
  - **Posizione fisica:** I dati sono memorizzati come una sequenza di bit (0 e 1) in settori e blocchi, in posizioni specifiche sul supporto fisico (ad esempio, particelle magnetiche su un HDD o celle di memoria su un SSD).
  - **Hardware:** L'interazione con il livello fisico richiede una conoscenza approfondita di come l'hardware (controller, dischi, ecc.) gestisce la lettura e la scrittura dei dati.
  - **Analisi forense:** Un'acquisizione fisica (o bitstream) crea una copia bit per bit dell'intero supporto di archiviazione, inclusi i dati allocati, quelli non allocati (spazio libero), le aree di dati nascoste e le strutture di sistema. Questo tipo di acquisizione è essenziale per recuperare dati cancellati o frammentati e per indagare su attività che non lasciano tracce a livello logico

La modalità con cui un dispositivo gestisce i dati a livello logico ha implicazioni diette su qualunque analisi forense.

### Slack Space

<img title="" src="https://media.licdn.com/dms/image/v2/D5622AQH9j9pilIBOWg/feedshare-shrink_2048_1536/feedshare-shrink_2048_1536/0/1690249730179?e=2147483647&v=beta&t=Ojr3W1W4zIGfieLfuiyyxQT27a1zawEVgSFqYXCZYAU" alt="digitalforensics #digitalevidence #clusters #cybersecurity #harddisk |  Ravichandran A" data-align="center" width="505">

Lo [slack space]([#digitalforensics #digitalevidence #clusters #cybersecurity #harddisk | Ravichandran A](https://www.linkedin.com/posts/ravi-chandran-a-_digitalforensics-digitalevidence-clusters-activity-7089421207564914690-9u7u)) (spazio residuo) è la parte inutilizzata di un'unità di allocazione del disco (un **cluster** o un **blocco**) che rimane dopo che un file è stato memorizzato.

In breve, quando un file viene salvato, il sistema operativo gli assegna uno o più cluster. Se la dimensione del file non occupa completamente l'ultimo cluster, lo spazio rimanente in quel cluster è il *slack space*. Questo spazio non viene cancellato, ma può contenere frammenti di dati di file precedentemente cancellati o altre informazioni casuali.

**Rilevanza nell'informatica forense**:
Nell'informatica forense, il *slack space* è una fonte preziosa di potenziali prove. Un'analisi approfondita di queste aree può portare alla luce:

- **Frammenti di dati:** Parti di file che l'utente ha cancellato ma che non sono state sovrascritte.
- **Informazioni nascoste:** Dati che un utente malintenzionato potrebbe aver cercato di occultare.

Pertanto, l'esame del *slack space* è una fase critica durante l'acquisizione e l'analisi forense di un dispositivo di memorizzazione, poiché può rivelare informazioni che non sono visibili a livello logico.

<meccanismo di Take Out>

### Image/Video Forensics (in pratica)

- Restaruo o miglioramento di un file multimediale

- Interpretazione e aanalisi dei contenuti
  
  - Ricostruzione dinamica (incidenti automobilistici, etc...)
  
  - Problemi antropometrici

- Identificazione della fonte

- Integrità/autenticità

Queste ultime due, in particolare, fanno parte di quello che viene detto "Multimedia Forensics"

<cctv>

<effetto truman>

---

### Come condurre un'investigazione?

Come già detto il passo ,più importante è quello di preservare il dato originale senza modificarlo o danneggiarlo, al fine di rendere l'indagine ripetibile.

Si può schematizzare tutto in 5 fasi, ripercorribile in tutti i versi.

1. Fase di **preservazione** del sistema
   
   Trovandoci nella scena dove dobbiamo effettuare l'indagine, bisogna prelevare i dati senza modificarli. Anche durante la ricerca delle evidenze è importante.
   Live Anaysis = Si analizza sul sistema in funzione!(SBAGLIATO). Ad esempio quando spegniamo il computer perdiamo alcuni dati, e se inseriamo un pendrive qualcosa nel sitema di altera. L'esperto deve essere quindi delicato ed evitare di inquinare il più possibile le prove. Quindi il modo migliore per operare è la "**dead analysis**", dove il sistema viene riprodotto in laboratorio in modo da non alterare la versione originale.
   Lo scopo di preservare il sistema è prevenire la sovrascrittura delle evidenze, ...<?>

1. Fase di **ricerca** delle evidenze
   
   I **punti chiave** sono: capire dove e cosa cercare. Non si cercano solo prove a favore dell'ipotesi ma anche, e soprattutto, evidenze che la contraddicano.
   La **procedura generale** consiste in due passi: caratterizzare l'oggetto che stiamo cercando e cercare l'oggetto in una opportuna raccolta dati. Ad esempio potremmo cercare le *abitudini di navigazione web* (cache del browser, cronologia, segnalibri).

2. Fase di **ricostruzione** degli eventi
   
   A questo punto bisogna fare due cose fondamentali: determinare quali eventi sono accaduti e quali non sono accaduti.
   Supponiiamo di trovare file illegali, o file legali che però non dovrebbero essere dove sono. ... <integrare dalle slide>

### Tipi di analisi e attendibilità dei dati


