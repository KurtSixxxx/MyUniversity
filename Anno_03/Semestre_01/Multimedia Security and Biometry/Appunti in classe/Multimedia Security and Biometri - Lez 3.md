# Multimedia Security and Biometri - Lez 3

---

### Un po' di storia...

Per diminuire il margine d'errore, Galton introduce la nozione di **minuzia**, e ha definito un sistema di classificazione delle impronte digitali. Come ben sappiamo le impronte digitali sono uniche per ognuno di noi, non esisterà mai nessuno con le stesse impronte digitali di qualcun'altro.

<img title="" src="https://www.researchgate.net/publication/269298396/figure/fig5/AS:668364863193095@1536362009486/Fingerprints-marked-with-minutiae-points-A-Latent-fingerprint-with-core-B-Plain-slap.png" alt="Fingerprints marked with minutiae points: A. Latent fingerprint with... |  Download Scientific Diagram" data-align="center" width="528">

Possiamo utilizzare un sistema di sicurezza maggiore integrando i sistemi tradizionali. In maniera progressiva tra livello di sicurezza-soluzione possiamo usare:

1. Qualcosa che conosciamo (pin, password)

2. Qualcosa che conosciamo (pin, password) + Qualcosa che abbiamo

3. Qualcosa che conosciamo (pin, password) + Qualcosa che abbiamo + "Chi sei"

### Architettura di un sistema biometrico

Ci sono due fasi principali nell'architettura di un sistema biometrico.

- **Enrollment (Registrazione)**
  
  Durante la fase di registrazione, i dati biometrici vengono acquisiti dall'individuo e memorizzati in un database insieme a un identificatore che ne identifica
  la persona. Le persone si iscrivono, quindi i loro tratti biometrici verranno acquisiti e verranno definiti dei template per singolo utente, e dunque verrà definito un database con queste informazioni.

- **Recognition (Riconoscimento)**
  
  Questa è praticamente la fase attiva, ossia quando si prelevano informazioni dal database e vengono utilizzate al fine di riconoscimento e autenticazione.
  Durante la fase di riconoscimento, i dati biometrici vengono nuovamente acquisiti dall'individuo e confrontati con i dati memorizzati per determinare o verificare l'identità dell'utente.

*Verifica*: persona dichiara la sua identità, quindi fornendo una serie di dati identificativi in input, anche se i suoi dati biometrici non fanno parte del template si avrà comunque una risposta da parte del sistema. Il compito della verifica ha un livello di computazione molto breve e semplice in quanto deve solo controllare il matching dei dati e fornire una sola risposta. La prassi è analizzare -> fornire risposta. Quindi si fa una verifica 1:1, non serve analizzare tutti i dati biometrici in database.

*Identificazione*: l'utente non si dichiara, ma il sistema di identificazione è in grado di dare una risposta. Possiamo dire che è un sistema più complesso in quanto non dichiariamo alcun tipo di dato in input per il sistema e quindi deve prelevare -> analizzare -> fornire risposta. Quindi si fa una verifica 1:N, serve analizzare tutti i dati biometrici in database con quello in entrata.

### Moduli di un sistema biometrico

Un sistema biometrico è generalmente programmato per operare con 4 moduli.

- **Modulo sensore**: questo è il modulo dove, tramite sensori, vengono captati i dati biometrici e conservati.

- **Modulo di estrazione delle caratteristiche**: in questo modulo una serie di caratteristiche sono estratte dai dati acquisiti. In questa fase, durante la registrazione si produce un template che verrà conservato nel sistema.

- **Modulo di matching**: in questo modulo vengono accoppiati i dati passati in input al momento dell'identificazione con i template contenuti nel database. Alla fine della computazione si assegna il valore di matching al dato più simile trovato.

- **Modulo decisione**:
  
  <?> 

### Tipi di utenti

- **Utenti coperativi**: si parla di soggetti che hanno l'intento di farsi riconoscere da un sistema, magari al fine di autenticarsi.

- **Utenti non cooperativi**: si parla di soggetti che non vogliono essere riconosciuti e dunque questo "affatica" il sistema. Per questo è importante costruire un sistema che sia efficente ed in grado di riconoscere anche questi tipo di utenti

- **Contesti pubblici e privati**: 

... <?>

### Tipologie di setting

- **Controllato**: le impostazioni di acquisizione possono essere controllare, le distorsioni per lo più evitate (as esempio, per il viso, la posa, l'illuminazione e l'espressione), i modelli difettosi possono essere rifiutatu e l'acquisizione può essere ripetuta.

- **Non controllato/sottocontrollato**: le impostazioni di acquisizione non possono essere controllate, i template possono presentare diversi titpi di livelli di distorsione, i template difettosi possono essere rifiutati, ma l'acquisizione non può essere ripetuta.

### Tipi di identificazione

- **Open Set**: il sistema determina la probabilità che un soggetto appartiene alla galleria.

- **Possibile errore**: 

...

### Requisiti di un tratto biometrico

Perché acquisiamo alcuni tratti biometrici? Perchè questi hanno le caratteristiche di:

- **Universalità**: tratto che hanno tutte le persone, quindi non può essere un tratto di una sola persona o un gruppo di poche persone.

- **Unicità**: tratto che deve essere unico per ogni utente. Un semplice esempio ne sono le impronte digitali, nessuno ha le stesse fingerprints di altri individui.

- **Permanenza**: tratto che non deve cambiare nel tempo, o almeno che cambia lentamente nel tempo.

- **Acquisibilià**: deve essere possibile acquisire il tratto da un tipo di sensore.

- **Accettabilità**: i tratti che vengono acquisiti devono essere accettabili per l'individuo, il momento di acquisizione o del riconoscimento non deve essere ambiguo o imbarazzante per l'utente.

### Standard x9.84 - 2003

E' uno standard stipulato dall'ANSI (**American National Standards Institute**) - l'istituto americano che coordina gli standard nazionali statunitensi - che specifica i requisiti minimi di sicurezza per una gestione efficace dei dati biometrici.  E' progettato per fornire delle linee guida specifiche che riguardano l'uso sicuro di dati biometrici. Utile per proteggere gli utenti da dati sensibili o operazioni sensibili, come quelle bancarie.

### Tratti strong e soft

- **Strong**: iride, viso, impronta digitale. Cambiano difficilmente o mai, e la loro acquisizione è semplice e unica.

- **Soft**: colore dei capelli, forma del viso, camminata. Cambiano nel tempo e la loro acquisizione può cambiare anche in funzione della luminosità o dalla saturazione dei sensori. Quindi possono comportare un margine d'errore.

### Gaussian Mixture Model (GMM)

E' un modello statistico che rappresenta la distribuzione di probabilità di un set di dati come somma ponderata di più distribuzioni gaussiane (normali). E' un metodo di autenticazione tramite che utilizza la voce del soggetto.

### Signature

Riguarda la calligrafia o la firma di un soggetto. Vengono analizzate curve, tratti o linee della firma. Le misure possono essere trasformate in variabili (coordinate, pressione, grado di angoli, ...) e studiate al fine di verificarne l'autenticità.


