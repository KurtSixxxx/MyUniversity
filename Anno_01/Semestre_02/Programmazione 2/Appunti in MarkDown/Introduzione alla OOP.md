# Introduzione alla OOP

Il mondo in cui viviamo è gestito da tanti sistemi complessi, e per farli lavorare tutti insieme c'è molto lavoro da fare per parli interagire. Per gestire la complessità esiste l'**astrazione**.

Un esempio di astrazione: Pensate a una mappa di una città. Non vi mostra ogni singolo tombino o ogni albero, giusto? No, vi mostra solo quello che vi serve per orientarvi, le strade, i monumenti.

Ecco, questo è il cuore dell'astrazione. Quindi questa definizione è perfetta. L'astrazione è l'arte di filtrare la realtà e buttare via tutti i dettagli inutili per concentrarsi, solo e soltanto, su quello che è essenziale per risolvere il nostro problema. È come mettere a fuoco, per vedere chiaramente solo quello che conta.

> L'**astrazione** è un procedimento che consente di semplificare la realtà che vogliamo modellare. La semplificazione avviene concentrando l'attenzione solo sugli elementi importanti del sistema complesso che stiamo considerando.

L'astrazione è un concetto fondamentale nella programmazione ad oggetti. Infatti gli oggetti in un linguaggio OOP forniscono la funzionalità di astrarre, cioè di nascondere i dettagli implementativi interni. Quando si creano dei programmi mediante un linguaggio orientato ad oggetti, la capacità di astarre, cioè la capacità di semplificare delle entità complesse **oggetti caratterizzati dalle caratteristiche e dalle funzionalità essenziali** è importante.

Come sappiamo, linguaggi di programmazione permettono di scrivere un programma in forma comprensibile all'elaboratore. Per fare ciò, ogni linguaggio è caratterizzato da una **sintassi**, cioè un insieme di costrutti e di regole. Questi costrutti rappresentano una **astrazione delle possibili operazioni che il processore può eseguire**.

Nel caso del C++, ossia un linguaggio ad alto livello, si utilizzano parole chiave in inglese. Il programma viene poi processato da un **interprete** o **compilatore** che si occupano di tradurlo in linguaggio macchina.

### Programmazione procedurale vs OOP

Quando si parla di **programmazione procedurale** si parla appunto di procedure, di una sequenza di istruzioni una dopo l'altra che seguono un andamento lineare. Si crea dunque un modello indicando le procedure da eseguire in maniera sequenziale per arrivare alla soluzione.
Quando invece parliamo di **programmazione OOP** si passa ad un tipo di ragionamento differente. Ossia quello di oggetti intesi come entità che hanno un loro stato e possono eseguire certe operazioni in relazione tra essi.

In questo caso l'algortimo perde importanza a vantaggio del concetto di **sistema**.

> Un **algoritmo** è un insieme di istruzioni che a partire dai dati di input permettono di ottenere risultati di output. Inoltre, deve essere riproducibile, deve avere una durata finita e non deve essere ambiguo. Il modo di programmare pone attenzione sulla sequenza di esecuzione.

> Un **sistema** è una parte del mondo che si sceglie di considerare come un intero, composto da **componenti**. Ogni componente è caratterizzato da **proprietà**, e da **azioni** che creano interazioni tra le proprietà e le altre componenti.

#### Programmazione procedurale

I programmi sono fatti da fuzioni, che spesso rappresentano codice riutilizzabile, ma che spesso fanno riferimento a headers e/o variabili globali che devono essere importate insieme al codice delle funzioni.
I linguaggi procedurali non si prestano bene alla modellazione di concetti ad alti livelli di astrazione, utili per rappresentare entità complesse che interagiscono in un sistema reale. Questi linguaggi quindi separano le strutture dati e gli algoritmi

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-27-17-16-21-image.png" alt="" data-align="center" width="169">

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-27-17-17-20-image.png" alt="" data-align="center" width="498">

#### Programmazione ad oggetti (OOP)

Esempio: interfaccia grafica (GUI) di un PC

Componenti:
Finestre (proprietà: dimensione, posizione)
Bottoni (proprietà: colore, testo)

Correlazioni:
Premendo un bottone si può aprire una finestra (e quindi definire la sua posizione e la sua dimensione)

La metodologia OO è un modo di pensare al problema in termini di sistema. Durante la fase di analisi si crea un **modello del sistema**, individuando gli **elementi** di cui è formato e i **comportamenti** che devono avere.

#### Concetto di Oggetto e Classe

Un oggetto può essere definito elencano sia le sue caratteristiche, sia il modo in cui interagisce con l'ambiente esterno, cioè i suoi comportamenti.

- Le **caratteristiche** rappresento gli elementi che caratterizzano l'oggetto, utili per descrivere le sue proprietà e definirne lo stato.

- I **comportamenti** rappresentato le funzionalità che l'oggetto mette a disposizione: chi intende utilizzare l'oggetto deve attivare i comportamenti dell'oggetto stesso.

Una classe incapsula sia le caratteristiche (**attributi**) sia i comportamenti (**metodi**) degli oggetti che rappresenta.

Inoltre forisce una interfaccia pubblica per poter utilizzare (interagire con) gli oggetti definiti dalla classe.

In altre parole, la OOP combina strutture dati e algoritmi in entità software "impacchettate" dalla definizione di una classe.

**Classe $\neq$ Oggetto**, detto terra terra:
Una **classe** è una **descrizione**: definisce quali dati (attributi) e quali operazioni (metodi) avrà un certo tipo di entità.  
Esiste solo nel codice, non rappresenta qualcosa di concreto.

Un **oggetto** è una **istanza della classe**: è qualcosa di reale che viene creato in memoria quando il programma è in esecuzione.  
Ha valori specifici per gli attributi definiti dalla classe.

**Esempio (Automobile)**

- `Automobile` è la **classe**: descrive cosa ha e cosa può fare un’auto (colore, porte, cavalli, accelera, frena…).

- `panda` è un **oggetto** della classe `Automobile`: rappresenta una specifica auto concreta (per esempio una Fiat Panda rossa con 70 cavalli).

In breve:

- **Classe** → modello / progetto

- **Oggetto** → istanza concreta creata dal modello

Da una stessa classe possono nascere **più oggetti diversi**, tutti con la stessa struttura ma con valori differenti.

Analizziamo l'oggetto "automobile"

- Caratteristiche/Attributi: velocità, colore, numero di porte, livello del carburante, posizione della marcia

- Comportamenti/Metodi: accellera, fermati, giraa (a destra o sinistra), cambia marcia, rifornisciti.

Chi intende utilizzare questo oggetto agisce attivando i suoi comportamenti, questi posono concretizzarsi con delle azioni o con il **cambiamento dello stato** dell'oggetto cioè delle sue caratteristiche.

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-27-18-59-25-image.png" title="" alt="" data-align="center">

Mediante il metodo "`fermati()`" posso modificare lo stato dell'oggetto auto_1.

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-27-19-00-06-image.png" title="" alt="" data-align="center">

Mediante il metodo "`accelera()`" posso modificare lo stato dell'oggetto auto_1.

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-27-19-01-05-image.png" title="" alt="" data-align="center">

Un oggetto quindi è formato da attributi e metodi.

Un programma ad oggetti è caratterizzato dalla presenza di tanti oggetti che comunicano ed interagiscono tra loro (modello di sistema).

L'interazione tra oggetti avviene con un meccaniscmo chiamato **scambio di messaggi**. Un oggetto, inviando un messaggio ad un altro oggetto, può richiedere l'esecuzione di un metodo.

Un messaggio è costituito da tre parti:

- Un destinatario $\rightarrow$ l'oggetto verso il quale il messaggio è indirizzato.

- Un selettore $\rightarrow$ identifica il metodo che si vuole attivare

- Un elenco di argomenti $\rightarrow$ l'insieme dei parametri che vengono passati all'oggetto quand si richiede l'attivazione del metodo 

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-12-27-19-21-56-image.png" title="" alt="" data-align="center">

### Caratteristiche della OOP

Adesso che sappiamo cosa è la programmazione OO e cos'è un oggetto, vediamo ora le caratteristiche fondamentali della OOP che la rendono così importante:

- Incapsulamento

- Interfaccia di un oggetto

- Classe

- Ereditarietà

- Polimorifsmo

- Collegamento dinamico

Il termine **incapsulamento** indica la proprietà degli oggetti di incorporare al loro interno sia gli attributi che i metodi, cioè le caratteristiche ed i comportamenti dell'oggetto.
