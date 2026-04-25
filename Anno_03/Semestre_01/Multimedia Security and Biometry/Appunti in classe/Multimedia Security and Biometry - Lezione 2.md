# Multimedia Security and Biometry - Lezione 2

---

### AI Act

Regolamento europeo sulla biometria e i dati biometrici

### Liveness Detection

Algoritmo basato sul riconoscimento di un volto reale rispetto ad uno simulato (ad esempio una fotografia) per evitare lo spoofing; in grado di riconoscere se il volto è umano o simulato.
Ad esempio il FaceID di Apple riconosce il volto tramite segnale ad infrarossi che scansiona tramite una "griglia" il volto reale. (Scansione 3D)

### Gesture Recognition

Biometria relativa al riconoscimento di gesti. Esempio: simulazione di emoji al fine di autenticare.

Casi utili di Gesture Recognition:

- Traduzione della lingua dei segni

- Gestione di un sistema tramite i segni

- Analisi del comportamento

- Identificazione di un soggetto tramite sequenza di gesti

### Pedestrian Attribute Recognition (PAR)

Metodo di riconoscimento attribuito ad una ricerca fotografica tramite descrzione - ad esempio - sul vestiario e i colori dei vestiti. Si effettua tramite 5 attributi legati al soggetto da riconoscere.

### Biometrics & Medical Imaging

Riconoscimento tramite dati medici. <?>

### Document Matching

Utilizzando al sistema di riconoscimento facciale, vogliamo dimostrare che il soggetto si faccia riconoscere mostrando anche il suo documento di riconoscimento, ad esempio la carta d'identità.

Bisogna tenere conto di alcuni ostacoli di questo riconoscimento: la carta è riflettente, il colore dell'immagine è diverso dal volto reale.

### Latent Fingerprint Enhancement

Riconoscimento di impronte digitali non scansionate volontariamente. Molto utilizzato sulle scene del crimine. Quindi le impronte sono parziali o danneggiate da sporcizia. Tramite questo metodo un algoritmo generativo è in grado di ricostruire l'immagine completa dell'impronta al fine di riconoscere l'individuo.

### Hand-Geometry Identificatio/Authentication

Riconoscimento della mano tramite la geometria di quest'ultima. Poiché unica per ogni individuo.

### LLM-based Identikit Generation

Fornendo un prompt ad un AI dove viene descritto un soggetto, ad esempio un soggetto ricercato per un eventuale crimine, viene generato un identikit.

Una volta ottenuto l'identikit si può generare tramite il modello generativo un immagine di un individuo.

Quindi questo implica l'uso di un API, l'interfaccia di un programma già esistente al fine di usarlo in un'altra app. In questo caso sarebbe utile usare l'API di OpenAI.

### MAAD-Face: A Massively Annotated Attribute Dataset for Face Image

Si utilizza un dataset di individui che hanno molto caratteristiche in comune.

### Entrace/Exit Wounds Recognition

Riconoscimento di un calibro, angolazione, ingresso/uscita, di un foro di proiettile.

### Machine Unlearning

La sfida si concentra sullo scenario in cui un predittore di età viene
costruito a partire da dati di immagini facciali e, dopo l'addestramento, un certo numero di immagini deve essere dimenticato per proteggere la privacy o i diritti
degli individui interessati.
Un algoritmo di disapprendimento prende come input un modello pre-addestrato e
uno o più campioni dal set di addestramento da disimparare (il "set
dimenticato"). Un algoritmo di disapprendimento ideale produce un modello che è
indistinguibile dal modello addestrato senza il set di dimenticato.

In sintesi, cancellare da un sistema di riconoscimento tutte le informazioni di un individuo.

### Deepfake

Tramite un volto, viene creato un contenuto multimediale che all'occhio di un umano sembra reale ma effettivamente non lo è. In sintesi viene "incollato" il volto di un individuo sul corpo di un'altra persona. Oppure generare video di individui noti che compiono azioni che realmente non hanno commesso.

### Adversarial Machine Learning

Insieme di tecniche per ingannare i servizi di machine learning.

___

## Biometrics and Pattern Recognition

### Biometic System - System for a (specific) kind of Pattern Recogniton

<?>

### Pattern Recognition in different kind of ways

Ci sono diverse classi dello stesso tipo, ad esempio diversi tipi dei cani.

- Classificazione 
  
  Quindi il sistema di riconoscimento deve conoscere dei parametri generali ed adattarli su delle caratteristiche che non ha mai visto, quindi per l'esempio sopra, adattarsi alle caratteristiche generali di un cane.

- Biometria
  
  <?>

### Cos'è la Biometria?

In generale, la misura e la statistica analitica di dati biologici.

Assunzione base: siamo unici, ognugno di noi ha dei tratti unici.

La biometria deve quindi determinare le feature uniche utili ad intetificare una persona.

...

### Access Type

Ci sono diversi tipi di accesso ad esempio. 

Accesso fisico: stanza, area.

Accesso logico: un login ad un sito web

### Perché i sistemi biometrici?

La biometria è basata sui tratti unici dell'individuo, che vengono in seguito tradotti in una "chiave" che ci permette di accedere. Diciamo di avere delle password che non dobbiamo ricordare perchè ce le abbiamo addosso. Una debolezza dei dati biometrici è che non possono essere cambiati, quindi dobbiamo fare in maniera che non vengano rubati o violati.




