# Digital Forensics lezione 11

Analizziamo la Digital Forensics nel contesto operativo previsto dalla circolare 1/2018 dalla Guardia di Finanza. Prende il nome di **Manuale operativo in materia di contrasto all'evasione e alle frodi fiscali**. E' una guida suddivisa in quattro volumi, che contiene indicazioni operative sulle attivitità di contrasto svolte dai Militari. In questo documento viene data particolare enfasi alla corretta modalità di acquisizione delle evidenze digitali, tramite tecniche e metodologie d'informatica forense.

Questa circolare è importante perché per la prima volta in un corpo di polizia viene introdotta la figura personale di esperto tecnico in Digital Forensics, infatti ci sono dei corsi specializzati all'intero del corpo della Guardia di Finanza per lavorare in questo campo, e si assume il ruolo di CFDA "Computer Forensics e Data Analysis".

Il secondo volume approfondisce in modo tecnicamente dettagliato la modalità con la quale deve avvenire la ricerca e l'estrazione di documenti informatici nel corso dell'accesso.

<da completare>

---

## Investigare su Immagini e Video

L'FBI dice che l'image (video) forensics è: *l'applicazione di scienza delle immagini e esperti di dominio per interpetare il contenuto di un immagine*.

Esperti di dominio: per analizzare immagini ci vuole un esperto del dominio tecnico, e deve essere anche esperto del contenuto. Quindi chi analizza l'immagine deve anche essere bravo e preparato a riconoscere cosa ha davanti.

La procedura di analizzazione di un immagine, in Digital Forensics, è quella di preservare l'immagine, documentare tutti i passi di elaborazione e assicurarci di poter riprodurre a partire dall'immagine principale il processo che abbiamo documentato.

I software che usiamo noi è Amped Five/Authenticate. Five è un acronimo, di "**Forensic Image and Video Enhancement**".

[Ripasso di Interazione & Multimedia]

- Immagine: griglia di pixel

- Pixel: numeri in una griglia

Un'immagine è una funzione 2D che rappresenta una misura opportuna di una o più caratteristiche (luminosità, colore, ecc) di una data scena.

##### Risoluzione Spaziale

Quindi un'immagine è una griglia, una matrice, di pixel che combinati costituiscono un contenuto multimediale. Ovviamente più pixel ci sono, più alta sarà la risoluzione dell'immagine.

A fini forensi la risoluzione non è assoluta ma dipende da ciò che vogliamo cercare.

##### Risoluzione Cromatica

E' legata ai colori, e nello specifico allo spazio colore RGB (Red Green Blue). Le componenti di questi 3 colori "uniti" tra di loro formano i colori reali dell'immagine.

I limiti della digital forensics non sono tanto i colori ma la risoluzione, che serve per i dettagli.

Lo strumento per eccellenza che ci permette di migliorare una foto (in termini di luminosità e di colore) è l'istogramma: L'istogramma di intensità è fondamentalmente la "carta d'identità" luminosa di un'immagine. Immaginalo come un grafico che ti dice, in un colpo d'occhio, com'è distribuita la luce: l'asse orizzontale va dal nero puro al bianco puro, e l'altezza delle barre ti dice quanti pixel ci sono per ogni tono. Se vedi tante barre a sinistra, l'immagine è scura; se sono tutte a destra, è chiara. Se sono schiacciate al centro, il contrasto è basso; se sono sparse su tutto il grafico, il contrasto è elevato.

##### Agire sul contrasto

Usare una look-up table, o LUT, per gestire il contrasto è un po' come decidere quali parti dell'immagine meritano più attenzione e quali meno.

In pratica, si prende una "curva" che riscrive la relazione tra i toni originali e quelli che vedremo alla fine. Se la curva "sale" molto rapidamente (nella zona scura), stiamo espandendo quei toni: un nero leggermente diverso dall'altro diventa molto diverso nell'immagine finale, aumentando il contrasto e tirando fuori dettagli dalle ombre.

Al contrario, dove la curva si appiattisce (nella zona chiara), stiamo comprimendo i toni: vari bianchi e grigi chiari vengono schiacciati in un range ristretto. Questo riduce il contrasto nelle luci, magari per evitare che il cielo appaia "bruciato" o eccessivamente luminoso. È un modo selettivo e potente per scolpire l'aspetto visivo di una foto.

In digital forensics si utilizza molto il Contrast Enhancement:
Nella **digital forensics**, il miglioramento del contrasto tramite l'istogramma ha un doppio ruolo, quasi da investigatore e da indiziato.

**Lato investigatore:** Gli analisti forensi usano queste tecniche per "aprire gli occhi" sulle prove. Se un'immagine di sorveglianza è troppo scura (l'istogramma è tutto a sinistra), usano l'equalizzazione o lo stretching del contrasto per distribuire meglio i toni di grigio e far emergere dettagli cruciali, come volti o targhe, che altrimenti resterebbero nascosti nelle ombre. 

**Lato indiziato:** Il trucco sta nel fatto che qualsiasi manipolazione dell'immagine, compreso un semplice aumento del contrasto, lascia delle "impronte digitali" precise sull'istogramma originale, creando *picchi* e *lacune* (piccoli buchi nei valori tonali). Gli esperti forensi sanno che le immagini originali tendono ad avere istogrammi fluidi e uniformi. Analizzando queste anomalie, possono **determinare se un'immagine è stata alterata** e, a volte, anche capire *come* è stata modificata, rivelando potenziali tentativi di contraffazione dell'evidenza visiva.

La stessa operazione può essere fatta con i colori, quindi equalizzando le 3 componenti di colore RGB. Questo processo viene chiamato Color Correction.

<fino a slide 32>
