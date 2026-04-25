# Strutture Discrete

## Parte 1: Logica Proposizionale, Insiemi e relazioni

### 1: Logica Proposizionale

Le **logiche** sono **linguaggi formali** per rappresentare informazioni da cui trarre conclusioni. Una logica è **composta** da **due parti** fondamentali:

- **Sintassi**: definisce l'**ordine** e il **modo di utilizzo** delle formule del linguaggio

- **Semantica**: definisce il **significato** delle formule, ossia se sono vere o sono false.

La logica proposizionale si occupa di infromazioni e della loro veridicità. Una proposizione può essere vera oppure falsam, ma non entrambe. E la sua costruzione sintattica avviene tramite semplici operatori.

##### Sintassi

Il vocabolario della logica proposizonale comprende:

- **Proposizioni**: sono le variabili con cui lavoriamo, solitamente denotate con p, q, r.

- **Valore di veridicità**: possono assumere solo 2 valori, spesso sono
  
  - **0/1**
  
  - **T/F**
  
  - **V/F**

- **Connettivi logici**: i connettivi vengono utilizzati nelle formule per connettere appunto le proposizioni e fornire alla formula un significato.
  
  - $\neg$ **negazione**: si legge "non"
  
  - $\lor$ **disgiunzione**: si legge "o"
  
  - $\land$ **congiunzione**: si legge "e"
  
  - $\implies$ **implicazione**: si legge "se ... allora ..." oppure "implica"
  
  - $\Leftrightarrow$ **coimplicazione**: si legge "se e solo se" oppure "implica e co-implica"

##### Formule Proposizionali

Teniamo a mente, che **una variabile è di per se una formula**. Ma quando lavoriamo con le formule troviamo:

- $\neg P$ è una formula

- $P \lor Q$ è una formula

- $P \land Q$ è una formula

- $P \implies Q$ è una formula

- $P \Leftrightarrow Q$ è una formula

Nelle formule, l'ordine delle operatiori segue **regole di precedenza**, e, naturalmente, può essere forzato usando le parentesi.

L'ordine è:

1. $\neg$ negazione

2. $\land$ congiunzione e $\lor$ disgiunzione

Ecco degli esempi:

- $\neg p \lor q$: in questa formula la negazione si applica solo a $p$

- $\neg(p \lor q)$ in questa formula la negazione si applica alla disgiunzione $p \lor q$

##### Semantica: interpretazione

Una interpretazione $I$ su $\mathbb{P}$ è una funzione $I : P \rightarrow \{0,1\}$ o equivalentemente $I : P \rightarrow \{V,F\}$

##### Tavole della verità

- **Negazione**

| $p$ | $\neg p$ |
|:---:|:--------:|
| V   | F        |
| F   | V        |

- **Congiunzione**

| $p$ | $q$ | $p \land q$ |
|:---:|:---:|:-----------:|
| V   | V   | V           |
| V   | F   | F           |
| F   | V   | F           |
| F   | F   | F           |

- **Disgiunzione**

| $p$ | $q$ | $p \lor q$ |
|:---:|:---:|:----------:|
| V   | V   | V          |
| V   | F   | V          |
| F   | V   | V          |
| F   | F   | F          |

- **Implicazione**

| $p$ | $q$ | $p \implies q$ |
|:---:|:---:|:--------------:|
| V   | V   | V              |
| V   | F   | F              |
| F   | V   | V              |
| F   | F   | V              |

- **Coimplicazione**

| $p$ | $q$ | $p \Leftrightarrow q$ |
|:---:|:---:|:---------------------:|
| V   | V   | V                     |
| V   | F   | F                     |
| F   | V   | F                     |
| F   | F   | V                     |

##### Soddisfacibilità

- Una formula è **soddisfacibile** se esiste almeno una interpretazione per cui è vera.

- Una formula è **insoddisfacibile** se non esiste nessuna interpretazione per cui è vera.

- Una formula è una **tautologia** se per ogni interpretazione è vera.

##### Principi fondamentali della logica

Nella logica proposizionale ci sono 2 principi fondamentali.

- Principio del **Terzo Escluso**: *Una proposizione o è vera oppure è falsa, non c'è una terza possibilità.*
  
  La formula $p \lor \neg p$ è una tautologia, il che significa che è sempre vera.

- Principio di **Non Contraddizione**: *Una proposizione non può essere contemporaneamente vera e falsa.*
  
  La formula $p \land \neg p$ è insoddisfacibile, il che significa che è sempre falsa. 

##### Equivalenza logica e proprietà

Due formule che hanno le stesse variabili proposizionali si dicono equivalenti.
Se abbiamo una formula P ed una formula Q, ed entrambe contengono le stesse variabili proposizionali, allora si dice $P \equiv Q$. E se assegniamo un valore alle variabili, $P$ risulta vera se e solo $Q$ risulta anch'essa vera.

Abbiamo allora le seguenti proprietà dei connettivi logici:

- $p \lor q \equiv q \lor p$ (commutatività della disgiunzione)

- $p \land q \equiv q \land p$ (commutatività della congiunzione)

- $p \lor (q \lor r) \equiv (p \lor q) \lor r$ (associatività della disgiunzione) 

- $p \land (q \land r) \equiv (p \land q) \land r$ (associatività della congiunzione)

- $\neg (\neg p) \equiv p$ (doppia negazione)

- $p \implies q \equiv \neg q \implies\neg p$ (contrapposizione)

- $p \Leftrightarrow q \equiv (p \implies q) \lor (q \implies p)$ (Eliminazione doppia implicazione)

Leggi di De Morgan

- $\neg (p \lor q) \equiv \neg p \land \neg q$

- $\neg (p \land q) \equiv \neg p \lor \neg q$

Distributività

- $p \land (q \lor r) \equiv (p \land q) \lor (p \land r)$ distributività della congiunzione sulla disgiunzione

- $p \lor (q \land r) \equiv (p \lor q) \land (p \lor r)$ distributività della disgiunzione sulla congiunzione

###### Giustificazione o Conseguenza Logica

Sia $\mathcal{P}$ un insieme di proprosizioni (formule) e P una proposizione. Possiamo dire che $P$ è una conseguenza logica di $\mathcal{P}$, e lo denotiamo con:

$$
\mathcal{P} \models P
$$

stiamo dicendo, che ogni interpretazione $I$ che soddisfa tutte le formule $\mathcal{P}$ soddisfa anche $P$.

Una conclusione $Q$ è una conseguenza logica di $\mathcal{P}$ se tutte le premesse di $\mathcal{P}$ sono vere. Come se io sono un detective e i miei indizi in $\mathcal{P}$ sono tutti veri, naturalmente anche la conclusione $Q$ sarà vera.

La proposizione $Q$ (conclusione) può essere vera anche quando l'insieme delle premesse $\mathcal{P}$ è falso o insoddisfatto, semplicemente perché $Q$ è vera per conto suo o in base ad altre condizioni. La conseguenza logica garantisce solo la dipendenza in avanti: **se** le premesse sono vere, **allora** la conclusione deve esserlo.

##### Forme normali: CNF & DNF

Esistono due forme standardizzate in cui spesso si trasformano le formule, ossia le cosiddette forme normali.

- Forma Normale Congiuntiva (CNF)
  
  Una formula p è in CNF se è scritta come congiunzione di disgiunzioni. Per esempio: $(p \lor q) \land (\neg p \lor \neg r \lor s)$

- Forma Normale Disgiuntiva (DNF)
  
  Una formula p è i DNF se è scritta come disgunzione di congiunzioni. Per esempio: $(p \land q) \lor (\neg p \land \neg r \land s)$

Una qualunque formula p può essere trasformata in una delle due forme normali, basta seguire un semplice procedimento algoritmico.

- **Fase 1.**
  Elimina le doppie implicazioni $p \Leftrightarrow q$ dalla formula sostituendole con $(p \implies q) \land (q \implies p)$

- **Fase 2.**
  Elimina le implicazioni $p \implies q$ dalla formula sostituendole con $\neg p \lor q$.

- **Fase 3.**
  Sposta le negazioni $\neg$ a ridosso delle variabili proposizionali, utilizzando le regole di De Morgan, ed eliminando le doppie negazioni.
  Per esempio
  $\neg(\neg p \lor \neg r \lor s)$ diventa $(p \land r \land \neg s)$

- **Fase 4-a.**
  Per costruire una CNF distribuire la congiunzione sulla disgiunzione ed eliminare le tautologie. Per esempio $(p \land q) \lor (\neg p \land \neg r \land s)$ è una formula in DNF che vogliamo trasformare in CNF. Abbiamo
  
  $(p \lor (\neg p \land \neg r \land s)) \land (q \lor (\neg p \land \neg r \land s)) \equiv$
  
  $(p \lor \neg p) \land (p \lor \neg r) \land (p \lor s) \land (q \lor \neg p) \land (q \lor \neg r) \land (q \lor s) \equiv$
  
  $(p \lor \neg r) \land (p \lor s) \land (q \lor \neg p) \land (q \lor \neg r) \land (q \lor s)$

- **Fase 4-b.**
  Per costruire una DNF distribuire la disguinzione sulla congiunzione ed eliminare disgiunti insoddisfacibili e ripetizioni. Per esempio $(p \lor q) \land (\neg p \lor \neg r)$ è una formula in CNF che vogliamo trasformare in DNF. Abbiamo
  $(p \land \neg p) \lor (p \land \neg r) \lor (q \land \neg p) \lor (q \land \neg r) \equiv
  $
  $(p \land \neg r) \lor (q \land \neg p) \lor (q \land \neg r)$

### 2: Insiemi

##### Caratterizzazione di un insieme

Un insieme è una collezione ben definita di elementi. 

> **Appartenenza**
> 
> $x \in T$ si legge: "x appartiene all'insieme T" oppure "x è un elemento di T."

> **Non Appartenenza**
> 
> $x \notin T$ si legge "x non appartiene all'insieme T"

##### Definizione di un insieme

Gli elementi di un insieme si elencano inserendoli tra parentesi graffe, ad esempio: $A = \{1,2,3\}.$

> **Singoletto**
> 
> $\{a\}$ inidica l'insieme costituito da un solo elemento e si chiama singoletto.

> **Insieme vuoto**
> 
> $\emptyset$ indica l'insieme che non contiene nessun elemento.

##### Assioma di Estensionalità

Ogni insieme è caratterizzato dal fatto che i suoi elementi appaiono una sola volta e non importa in quale ordine essi sono elencati.

Questo vuol dire che: 

- $A = \{1,2,3\}$ e $B = \{2,3,1,2,3\}$ sono uguali, la ripetizione non ha importanza.

- $A = \{1,2,3\}$ e **$B = \{3,2,1\}$** sono uguali, l'ordine non ha importanza.

Ciò vuol dire che $A$ e $B$ sono lo stesso insieme.

Con questo introduciamo il concetti di:

> **Assioma di Estensionalità**
> 
> *Due insiemi A e B sono uguali se hanno gli stessi elementi.*
> 
> $A = B \Leftrightarrow (\forall x) (x \in A \Leftrightarrow x \in B)$

Inoltre, possiamo specificare un insieme indicando una proprietà che caratterizza gli elementi i suoi elementi. Se $P$ è una proprietà ben definita, possiamo allora definire l'insieme $\{x : \text{la proprietà P è vera per x}\} \equiv \{x : P(x)\}$.

Cosa vuol dire che $P$ è una proprietà ben definita? Vuol dire che per ogni valore di $x$, $P(x)$ può assumere sempre solo i 2 valori: vero o falso 

Esempi di insieme e non insieme definiti da proprietà:

- **Esemio di insieme**: Supponiamo P sia la proprietà di avere gl occhiali, allora $\{x : P(x)\}$ è un insieme.

- **Esempio di NON insieme**: Supponiamo P sia la proprietà di essere alti, allora ${x : P(x)}$ non è un insieme.

##### Cardinalità

Dato un insieme A, il numero di elementi che lo costituisce viene denominato cardinalità e viene denotato con $|A|$. Se $|A|$ è un numero intero allora l'insieme si dice finito, altrimenti infinito.

Esempi di cardinalità:

- Cardinalita dell'insieme vuoto: $| \emptyset | = 0$

- Cardinalita di un singoletto: $|\{a\}| = 1$

- Cardinalità di un insieme: $|\{1,2,3\}| = 3$

##### Relazione di Inclusione

$$
A \subseteq B \Leftrightarrow (\forall x)(x \in A \Rightarrow x \in B)
$$

###### - Uguaglianza tra insiemi

Due insiemi si dicono **uguali** quando contengono **esattamente gli stessi elementi**, anche se scritti in ordine diverso.  
In questo caso si ha che **ognuno è sia sottoinsieme che sovrainsieme dell’altro**:

> $A = B \Leftrightarrow A \subseteq B \space \space \space e  \space \space B \subseteq  A$

###### - Sottoinsieme $\subseteq$

Un insieme $A$ è **sottoinsieme** di $B$ (si scrive $A \subseteq B$) se **tutti gli elementi di $A$ sono anche in $B$**.  
In pratica, A è “contenuto” dentro B.

###### - Sottoinsieme proprio $\subset$

$A$ è **sottoinsieme proprio** di $B$ $(A \subset B$) se:

- tutti gli elementi di $A$ sono in $B$,

- ma $B$ contiene **almeno un elemento in più**.

Esempio:  
$A = \{1, 2\}, B = \{1, 2, 3\} \rightarrow A \subset B$

###### - Sottoinsieme improprio $\subseteq$

Il **sottoinsieme improprio** è il caso in cui **due insiemi sono uguali**.  
In altre parole:

> $A$ è sottoinsieme improprio di $B$ quando $A = B$.

Quindi, **ogni insieme è sottoinsieme improprio di sé stesso**, e se $A = B$, allora:

- $A$ è sottoinsieme di $B$,

- $B$ è sottoinsieme di $A$,

- ma **nessuno dei due è sottoinsieme proprio dell’altro**.

###### **- Insiemi disgiunti**

Due insiemi si dicono **disgiunti** quando **non hanno nessun elemento in comune**.  
Formalmente:

> $A \cup B = \emptyset$

Esempio:  
$A = \{1, 2, 3\}, B = \{4, 5, 6\} \rightarrow$ disgiunti, perché non condividono elementi.

##### Insiemi discreti e continui

> Un insiemesi dice discreto se è possibile ordinare i suoi elementi in maniera tale che tra un elemento ed un altro non vi siano altri elementi dell'insieme. Quindi è composto da elementi "isolati".

Possiamo immaginare un insieme discreto come una scala: i gradini sono ben distinti tra loro. Proprio come l'insieme dei numeri reali $\mathbb{N}$.
Infatti ogni insieme finito è discreto. Anche l'insieme vuoto $\emptyset$ è vuoto.

Un **insieme continuo** è l'opposto, una linea disegnata senza staccare la penna dal foglio è continua, o come una scivola (che quindi non ha gradini ed è continua), così come i numeri reali $\mathbb{R}$ quindi tutti i numeri con la virgola, come anche $\pi$, in mezzo ce ne sono infiniti altri.

##### Operazioni tra insiemi

###### Unione di due insiemi

> Se $A = \{1,2,3\}$ e $B = \{3,4,5\}$ allora
> 
> $A \cup B = \{1,2,3,4,5\}$
> 
> quindi: $A \cup B = \{x : x \in A \space \text{oppure} \space x \in B\}$

L'unione gode di due proprietà:

- **Commutatività**: $A \cup B = B \cup A$

- **Associatività**: $A \cup (B \cup C) = (A \cup B) \cup C$

**Cardinalità dell'unione**: $|A \cup B| = |A| + |B| - |A \cap B|$
Ovvero la somma delle due cardinalità meno la cardinalità dell'intersezione.

Se i due insiemi sono disgiunti invece:
$|A \cup B| = |A| + |B|$

###### Intersezione di due insiemi

> Se $A = \{1,2,3\}$ e $B = \{3,4,5\}$ allora
> 
> $A \cap B = \{3\}$
> 
> quindi: $A \cap B = \{x : x \in A \space \text{e} \space x \in B\}$

Introduciamo il concetto di insiemi disgiunti: "Due insiemi si dicono disgiunti quando non hanno alcun elemento in comune."

Quindi due insiemi $A$ e $B$ si dicono disgiunti se la loro intersezione è vuota, ovvero: $A \cap B = \emptyset$

L'intersezione gode di due proprietà:

- Commutatività: $A \cap B = B \cap A$ 

- Associatività: $A \cap (B \cap C) = (A \cap B) \cap C$

###### Proprietà formali di unione ed intersezione

- $A \cup A = A$ e $A \cap A = A$ (**idempotenza**)

- **Proprietà distributiva**:
  
  - $A \cap (B \cup C) = (A \cap B) \cup (A \cap C)$
  
  - $A \cup (B \cap C) = (A \cup B) \cap (A \cup C)$

- Proprietà di Assorbimento 
  
  - $A \cup (A \cap B) = A$ (l'intersezione tra un insieme con uno che lo contiene produce l'inseime dato)
  
  - $A \cap (A \cup B) = A$ (l'unione tra un insieme ed un suo sottoinsieme produce l'insieme dato)

##### Differenza di due insiemi

$A \backslash B$ è l'insieme formato da quegli elementi del primo insieme $A$ che non appartengono al secondo insieme $B$. Quindi

$$
A \backslash B = \{x: x \in A \space \text{e} \space x \notin B\}
$$

Se $A = \{1,2,3\}$ e $B = \{3,4,5\}$ allora $A \backslash B = \{1,2\}$. L'elemento 3 è l'unico elemento che i due insiemi hanno in comune, quindi viene sottratto da $A$.

**Cardinalità della differenza**:

$|A \backslash B| = |A| - |A \cup B|$

##### Diagrammi di Venn

I diagrammi di Venn sono una rappresentazione gradica della relazione di due o più insiemi. Il diagramma di Venn di $n$ insiemi è formato da $2^n$ regioni.

##### Complemento di un insieme

Assumiamo di trattare tutti gli insiemi come sottoinsiemi di un insieme "universo" $U$, dato $A \subseteq U$, l'insieme $U \backslash A$ viene detto **complemento di $A$**. Il complemento di un insieme di $A$ è l'insieme di tutti gli elementi che non appartengono ad $A$.

La notazione per indicare un insieme complemento è $A^C$.

Se $A = \{1,2,3\}$ e $U = \{1,2,3, ..., 10\}$ allora $A^C = \{4,5, ..., 10\}$

###### Proprietà del complemento

1. $(A^C)^C  = A$ (il complemento del complemento di un insieme è il complemento stesso)

2. $(A \cap B)^C = A^C \cup B^C$ (De Morgan: il complemento dell'intersezione è l'unione dei complementi)

3. $(A \cup B)^C = A^C \cap B^C$ (De Morgan: il complemento dell'unione è l'intersezione dei complementi)

###### Cardialità del complemento

$|A^C| = |U| - |A|$

##### Differenza simmetrica di due insiemi

La differenza simettrica è l'unione delle differenze di due insiemi.

> $A \Delta B = (A \backslash B) \cup (B \backslash A)$

Quindi è l'insieme formato da quegli elementi del primo o del secondo insieme che non appartengono ad entrambi.

Se $A = \{1,2,3\}$ e $B = \{3,4,5\}$ allora $A \Delta B = \{1,2,4,5\}$.
Quindi, l'elemento $3$, che è l'unico presente in entrambi gli insiemi è sottratto dall'unione $A \cup B$. 
[Possiamo dire che è il contrario dell'intersezione].

###### Proprietà della differenza simmetrica

- $A \Delta B = B \Delta A$ (commutatività)

- $A \Delta (B \Delta C) = (A \Delta B) \Delta C$ (associatività)

Vale la seguente uguaglianza: $A \Delta B = (A \backslash B) \cup (B \backslash A) = (A \cup B) \backslash (A \cap B)$

###### Cardinalità della differenza simmetrica

$|A \Delta B| = |A|+|B| - 2|A \cap B|$
