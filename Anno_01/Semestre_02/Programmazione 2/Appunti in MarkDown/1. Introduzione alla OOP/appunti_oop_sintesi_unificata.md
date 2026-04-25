# Programmazione Orientata agli Oggetti (OOP)

## Perché esiste la OOP

Il mondo reale è complesso: è composto da tanti sistemi che interagiscono tra loro. Il software moderno deve riflettere questa complessità senza diventare ingestibile.

La **programmazione orientata agli oggetti (OOP)** nasce per mettere ordine nel caos, attraverso un concetto chiave: **l’astrazione**.

### Astrazione

Astrarre significa **semplificare la realtà**, mantenendo solo ciò che è essenziale per il problema da risolvere.

Un esempio classico è la **mappa di una città**: non mostra ogni tombino o albero, ma solo strade e punti di riferimento utili.

> L’astrazione è il procedimento che consente di filtrare la realtà, eliminando i dettagli inutili e concentrandosi sugli elementi importanti del sistema.

Nella OOP, l’astrazione è realizzata tramite gli **oggetti**, che nascondono i dettagli interni e mostrano solo ciò che serve per usarli.

---

## Programmazione procedurale vs OOP

### Programmazione procedurale

- Il programma è una **sequenza di istruzioni**
- Dati e funzioni sono separati
- Le funzioni spesso dipendono da variabili globali
- Difficile modellare sistemi complessi

<img title="" src="file:///C:/Users/giuli/OneDrive/Immagini/Screenshots/Screenshot%202025-12-27%20171614.png" alt="Screenshot 2025-12-27 171614.png" data-align="center" width="175">

È come seguire una **ricetta**: passi ordinati uno dopo l’altro.

### Programmazione orientata agli oggetti

- Il programma è visto come un **sistema**
- Composto da **oggetti** che interagiscono
- Ogni oggetto ha un proprio stato e dei comportamenti

È come costruire con i **Lego**: tanti mattoncini indipendenti che sanno come funzionare e collaborano.

In OOP l’algoritmo perde centralità a favore del **modello del sistema**.

<img title="" src="file:///C:/Users/giuli/OneDrive/Immagini/Screenshots/Screenshot%202025-12-27%20171719.png" alt="Screenshot 2025-12-27 171719.png" data-align="center" width="549">

---

## Oggetti e Classi

### Oggetto

Un **oggetto** è un’entità software che combina:

- **Attributi** → caratteristiche (dati)
- **Metodi** → comportamenti (azioni)

L’insieme dei valori degli attributi in un dato momento rappresenta lo **stato dell’oggetto**.

Un oggetto non è solo dati e non è solo funzioni: è l’unione coerente di entrambi.

### Classe

Una **classe** è la **descrizione** di un oggetto:

- Definisce quali attributi esistono
- Definisce quali metodi sono disponibili
- Fornisce un’interfaccia pubblica per usare l’oggetto

La classe esiste solo nel codice.

### Classe ≠ Oggetto

- **Classe** → modello / progetto
- **Oggetto** → istanza concreta creata in memoria

Da una stessa classe possono essere creati **molti oggetti diversi**, con la stessa struttura ma con valori differenti.

Per rappresentare graficamente le classi di un progetto software basato sulla OOP si usa il diagramma delle classi.

![](C:\Users\giuli\AppData\Roaming\marktext\images\2025-12-28-04-06-59-image.png)

---

## Esempio: Automobile

### Classe `Automobile`

**Attributi**:

- velocità
- colore
- numero di porte
- livello carburante
- marcia

**Metodi**:

- accelera()
- frena()
- fermati()
- gira()
- cambiaMarcia()
- rifornisci()

La classe descrive **che cos’è un’auto in generale**.

### Oggetto `panda`

`panda` è un **oggetto** della classe `Automobile`.

Rappresenta un’auto concreta, per esempio:

- Fiat Panda
- colore rosso
- 70 cavalli

Quando si invoca un metodo, lo **stato dell’oggetto cambia**.

Esempio concettuale:

- Stato iniziale: velocità = 60
- Chiamata: `panda.fermati()`
- Stato finale: velocità = 0

Da una stessa classe possono nascere **più oggetti diversi**, tutti con la stessa struttura ma con valori differenti.

Chi intende utilizzare questo oggetto agisce attivando i suoi comportamenti, questi possono concretizzarsi con delle azioni o con il **cambiamento dello stato** dell'oggetto cioè delle sue caratteristiche.

<img src="file:///C:/Users/giuli/OneDrive/Immagini/Screenshots/Screenshot%202025-12-27%20185923.png" title="" alt="Screenshot 2025-12-27 185923.png" data-align="center">

Mediante il metodo "`fermati()`" posso modificare lo stato dell'oggetto auto_1.

<img title="" src="file:///C:/Users/giuli/OneDrive/Immagini/Screenshots/Screenshot%202025-12-27%20190004.png" alt="Screenshot 2025-12-27 190004.png" data-align="center" width="516">

Mediante il metodo "`accelera()`" posso modificare lo stato dell'oggetto auto_1.

<img title="" src="file:///C:/Users/giuli/OneDrive/Immagini/Screenshots/Screenshot%202025-12-27%20190058.png" alt="Screenshot 2025-12-27 190058.png" data-align="center" width="527">

---

## Scambio di messaggi

Gli oggetti comunicano tramite **messaggi**, cioè chiamate ai metodi.

Un messaggio è composto da:

- **Destinatario** → oggetto che riceve il messaggio
- **Selettore** → identifica il metodo che si vuole attivare
- **Argomenti** → parametri passati al metodo quando vi si richiede l'attivazion

<img title="" src="file:///C:/Users/giuli/OneDrive/Immagini/Screenshots/Screenshot%202025-12-27%20192155.png" alt="Screenshot 2025-12-27 192155.png" data-align="center" width="475">

Questo meccanismo permette agli oggetti di collaborare all’interno del sistema.

---

## I pilastri della OOP

### Incapsulamento

L’incapsulamento consiste nel **racchiudere attributi e metodi nello stesso oggetto**, proteggendo i dati interni.

Dall’esterno si utilizza solo l’**interfaccia pubblica**, senza conoscere i dettagli di implementazione.

Vantaggi:

- Protezione dei dati
- Riduzione degli errori
- Codice più manutenibile

### Ereditarietà

Permette di creare nuove classi partendo da classi esistenti. Quindi si può pensare di estendere la classe già esistente per adattarla alle nostre necessità.

Esempio:

- MezzoDiTrasporto
  - Automobile
  - Motocicletta
  - Autobus

La classe che è stata ereditata prende il nome di **sottoclasse**, mentre la generatrice si chiama **sopraclasse**. 

Queste relazioni individuano una gerarchia che si può descrivere usando un grafo di gerarchia.

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-28-04-09-24-image.png" title="" alt="" data-align="center">

La nuova classe si differenzia dalla sopraclasse in due modi.

- Per estensione: aggiungendo nuovi attributi e metodi

- Per ridefinizione: modificando i metodi ereditati, specificando una implementazione diversa di un metodo.

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-28-04-10-54-image.png" alt="" data-align="center" width="499">

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-28-04-12-11-image.png" title="" alt="" data-align="center">

- **Associazione**
  L'associazione è definita come una relazione d'uso. Si verifica quando una classe "utilizza" un'altra classe. Nello specifico, una classe A utilizza una classe B se un oggetto di classe A è in grado di inviare messaggi ad un oggetto di classe B, oppure se può creare, ricevere o resituire oggetti di tale classe.
  
  <img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-28-17-43-37-image.png" title="" alt="" data-align="center">

- **Aggregazione**
  L'aggregazione è una relazione di contenimento ed è considerata una forma di associazione più forte. In questo caso esiste un rapporto di tipo "intero-parte": una classe ne aggrega un'altra se l'oggetto contenuto (la parte) è un attributo dell'oggetto contenente (l'intero).
  Esempio: La classe Azienda aggrega la classe Persona, poiché l'azienda rappresenta l'intero composto da persone che ne costituiscono le parti.

- **Composizione**
  La composizione è la forma di aggregazione più forte. La sua caratteristica principale è il vincolo di appartenenza esclusiva: una "parte" può appartenere a **un solo "intero"** in un determinato istante di tempo.
  Esempio di differenza con l'aggregazione: Uno pneumatico può far parte di una sola automobile alla volta (composizione), mentre una persona può lavorare contemporaneamente per più aziende (aggregazione).

**Metafora per comprendere la differenza di forza:** Immagina l'**associazione** come una conversazione tra due passanti: comunicano ma restano indipendenti. L'**aggregazione** è come una squadra di calcio: i giocatori (parti) formano la squadra (intero), ma possono anche far parte di altre squadre in tempi diversi o esistere fuori da essa. La **composizione** è come il cuore in un corpo umano: è una parte vitale che appartiene esclusivamente a quell'intero e non può essere condivisa con altri corpi simultaneamente.

### Polimorfismo

Poli = molte, Morfo = forme

Significa che **lo stesso metodo può comportarsi in modo diverso** a seconda dell’oggetto che lo implementa.

Esempio:

- `accelera()` su un’auto con pedale
- `accelera()` su una moto con manopola

Stesso messaggio, comportamento diverso.

Questo rende il codice flessibile ed estendibile.

Durante l'esecuzione del programma, un'istanza della classe "veicoli a motore" può rappresentare sia un "automobile" che una "moto". Quando viene richiesta l'attivazione del metodo "accellera" è importante garantire che, tra tutte le implementazioni, venga scelta quella corretta.
Il **collegamento dinamico** è lo strumento utilizzato per la realizzazione del polimorfismo. E' dinamico perché l'associazione tra l'oggetto e il metodo corretto da eseguire è effettuata a **run-time**, cioè durante l'esecuzione del programma.

---

## La OOP come modo di pensare

La OOP non è solo una tecnica, ma un **approccio mentale**.

Di fronte a un problema:

1. Individuare gli **oggetti** (i protagonisti)
2. Definire le **classi** (attributi e metodi)
3. Progettare le **interazioni** tra oggetti

Imparare la OOP significa imparare a vedere il mondo come un **insieme di oggetti che collaborano**.
