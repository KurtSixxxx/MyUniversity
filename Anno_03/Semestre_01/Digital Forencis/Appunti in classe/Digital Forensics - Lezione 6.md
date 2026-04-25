# Digital Forensics Lezione 6

---

### Amped 5

Amped 5 è un software utilizzato nel campo dell'informatica forense. E' utilizzato per l'analisi e il miglioramento di immagini e video in ambito forense, riconosciuto per la sua affidabilità e l’efficienza delle sue procedure.

Analizzando un file multimediale possiamo compiere diverse azioni:

- Rimuovere rumore o sfocatura per riconoscere targhe

- Aumentare o diminuire luminosità per riconoscere individui sulla scena

Sostanzialmente tramite alcuni strumenti o filtri possiamo svolgere indagini forensi al fine di scrivere un report.

Quest'ultimo ha il compito di fornire una descrizione dettagliata di tutti i tools utilizzati, delle certificazioni e delle versioni di strumenti utilizzati per svolgere l'indagine.

Amped Authenticate, un altro software di casa Amped, ci permette di estrarre informazioni come metadati, da ogni tipo di file. Questa pratica può essere svolta anche tramite codice (C / Python).

### Dispositivi di Memorizzazione

La memorizzazione nei dispositivi digitali avviene su due...< ? >

La gestione dei file all'interno di un dispositivo di memorizzazione avviene diversamente in base al tipo di disco su cui scaricati, quindi dai file system.
Quindi i diversi file system utilizzano lo spazio sui dispositivi di memorizzazione in maniera dissimile l'uno dall'altro, per questo, servono tecniche di analisi diverse per esaminare i dati memorizzati da essi.
Nei diversi file system, alle inerenti locazioni di memoria, non per forza i dati sono memorizzati in posizioni continue, ma sono frammentati in blocchi che sono associati tra loro tramite informazioni di indirizzamento.

Per questa ragione, è compito del tecnico forense - ancor prima di inziare l'analisi e operare sul dispositivo - informarsi sul dispositivo (conoscere le caratteristiche e i file system) in maniera di poter operare bene sul dispositivo senza cercare di rovinare i file (Per questo è sempre meglio lavorare su copie delle prove a disposizione).

### Nuove tecnologie a supporto delle investigazioni digitali

##### Analisi di scansioni 3D

- **Structure Sensor**: E' un dispositivo che funzioa tramite luce strutturata, e che funziona solo su iPad.
  Il sensore Structure contiene un proiettore a infrarossi (IR), che emette una griglia o un insieme di punti luminosi invisibili all'occhio umano sull'oggetto o sull'ambiente da scansionare. Contemporaneamente, una telecamera a infrarossi (distinta da quella dell'iPad) rileva il modo in cui il pattern proiettato si deforma e si riflette sulla superficie dell'oggetto. Le curve, le sporgenze e le rientranze dell'oggetto causano una distorsione del pattern. Utilizzando una tecnica chiamata triangolazione, il software calcola la posizione esatta di ogni punto sulla superficie analizzando la differenza di angolazione tra il proiettore e la telecamera IR. Per ogni punto, il sensore può determinare la sua distanza, creando una "mappa di profondità" che rappresenta la geometria tridimensionale dell'oggetto.
  
  Il sensore Structure fornisce solo informazioni sulla profondità (la geometria in 3D), ma non sul colore. Per ovviare a questo, il sistema utilizza la fotocamera a colori dell'iPad per catturare la texture e i colori dell'oggetto. Il software esegue una **fusione dei sensori**, combinando in tempo reale la mappa di profondità proveniente dal sensore Structure con i dati di colore della fotocamera dell'iPad, creando un modello 3D completo e a colori.Questi sensori hanno dei laser che ricostruiscono le mesh e l'RGB dell'oggetto scansionato. Sono strumenti che permettono, tramite scansioni, di salvare una scansione 3D di un oggetto, persona o luogo. Nei casi delle indagini forensi queste scansioni sono utili per estrarre misurazioni.

- **3D Flow Zephyr**: 3D Flow Zephyr è un software di fotogrammetria che, nel contesto delle indagini forensi, serve a ricostruire scene del crimine e prove in 3D in modo automatico, preciso e documentabile. La sua utilità si basa sulla capacità di creare un "gemello digitale" della scena a partire da una serie di fotografie, offrendo agli investigatori strumenti avanzati di analisi e visualizzazione.  La fotogrammetria offre un metodo non invasivo e non distruttivo per documentare permanentemente la scena del crimine e le prove. Il modello 3D risultante fornisce una visione completa e accurata, superando i limiti delle fotografie tradizionali.

- **Blender**: Le ricostruzioni e animazioni 3D forensi con Blender servono a **ricreare virtualmente la dinamica di un evento a scopo investigativo e probatorio**. In sintesi: Si usa Blender per **modellare una scena virtuale** basata su dati reali come foto, video e scansioni. Poi si **animano gli eventi** (es. traiettorie di proiettili, movimenti di veicoli) per mostrare la sequenza dei fatti in modo chiaro. Queste visualizzazioni aiutano investigatori e tribunali a **comprendere la dinamica degli eventi** e a presentare le prove in modo più efficace.

##### Analisi delle manoscritture

- **GraphJ**: Per decenni, l'analisi delle manoscritture per scopi forensi si è affidata all'occhio esperto del grafologo. Questo processo, pur professionale, aveva dei limiti in termini di oggettività e ripetibilità. Con **GraphJ**, il **RIS (Reparto Investigazioni Scientifiche dei Carabinieri)** ha introdotto una soluzione innovativa che non sostituisce l'esperto, ma lo potenzia con strumenti digitali. Invece di una valutazione puramente visiva, GraphJ digitalizza il manoscritto e lo analizza con precisione millimetrica. 
  
  Il software è in grado di: 
  
  - Identificare in automatico righe e parole.
  - Calcolare parametri dimensionali precisi, come altezza e larghezza dei caratteri.
  - Cercare rapidamente occorrenze di specifici elementi grafici.
  - Generare un rapporto dettagliato che documenta ogni misurazione e passaggio dell'analisi. 
  - Confrontare grafe in diversi scritti per riconoscere l'individuo che ha scritto.
  
  In questo modo, GraphJ fornisce all'esperto dati numerici e oggettivi a supporto del suo giudizio. Il risultato è un'indagine più rapida, tracciabile e scientificamente inattaccabile in sede giudiziaria.

##### Balistica forense della armi da fuoco

- **Metaverse**: il concetto di "Metaverso" applicato alla balistica forense si riferisce principalmente all'utilizzo della realtà virtuale (VR) e di ricostruzioni tridimensionali avanzate per l'analisi e la visualizzazione delle scene del crimine. Grazie a tecniche come la scansione laser 3D e la fotogrammetria, le forze dell'ordine possono catturare la scena del crimine in ogni minimo dettaglio, creando un'esatta replica virtuale navigabile. 
  
  - **Navigazione a 360°:** Gli investigatori, indossando un visore VR, possono "entrare" nella scena virtuale per esaminare l'ambiente da ogni angolazione, come se fossero fisicamente presenti.
  - **Analisi dei dettagli:** La visualizzazione immersiva rende più facile notare indizi cruciali che potrebbero sfuggire con metodi tradizionali, superando i limiti delle fotografie bidimensionali.
  - **Analisi balistica:** In casi che coinvolgono armi da fuoco, il Metaverso consente di visualizzare e analizzare le traiettorie dei proiettili, i punti di impatto e la posizione del tiratore in modo molto più intuitivo e realistico.
  
  La balistica forense si occupa di conoscere le caratteristiche di un bossolo: calibro, angolazione del momento dello sparo, ecc...
  La scansione della balistica, senza l'utilizzo di tool, impiega alle forze dell'ordine un'intera giornata o più.
  Per un'indagine balistica, lo strumento necessario è un microscopio comparatore. La sua funzione principale è confrontare contemporaneamente due reperti, come proiettili e bossoli, per stabilire se provengono dalla stessa arma. Le impronte lasciate sul proiettile e sul bossolo dall'arma da fuoco (percussore, espulsore, microstrie) agiscono come una sorta di "impronta digitale" balistica.
  
  **Immagini 3D**: si passa dalla semplice foto a una scansione tridimensionale ad alta definizione delle micro-striature su bossoli e proiettili. Questo permette di analizzare le superfici in modo più dettagliato e oggettivo.
  
  **Database balistici**: i dati di ogni arma usata in un crimine vengono archiviati in enormi banche dati digitali, come il sistema NIBIN. I computer possono quindi scansionare automaticamente questi database per cercare correlazioni, collegando armi e crimini in tutto il mondo.
  
  **Intelligenza artificiale**: algoritmi di machine learning analizzano i dati balistici per identificare somiglianze in modo automatico e più efficiente. Questo non sostituisce l'investigatore, ma lo aiuta a scartare rapidamente le ipotesi meno probabili, velocizzando l'indagine.
  
  **Realtà virtuale**: permette agli investigatori di esaminare in un ambiente virtuale la scena del crimine e la traiettoria dei proiettili, offrendo una visione d'insieme più completa e precisa. 
  
  In sintesi, l'informatica non ha eliminato l'esperienza dell'investigatore, ma l'ha potenziata, fornendogli strumenti che accelerano l'analisi, aumentano l'oggettività e permettono di collegare crimini a livello globale.
  
  Quando un'arma da fuoco spara, in ogni componente di essa rimangono delle tracce che fanno capire che l'arma ha sparato. La stessa cosa accade ovviamente con i proiettili.
  Noi informatici possiamo effettuare scansioni 3D sui bossoli e analizzare ogni informazione che riusciamo a prelevare da quest'ultime.
  
  [Vedi progetti del prof guarnera su Unity]
