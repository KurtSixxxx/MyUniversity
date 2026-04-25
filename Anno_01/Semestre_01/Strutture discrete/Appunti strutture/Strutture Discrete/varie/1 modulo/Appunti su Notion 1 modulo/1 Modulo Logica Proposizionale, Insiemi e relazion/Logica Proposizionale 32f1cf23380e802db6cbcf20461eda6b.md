# Logica Proposizionale

## Il significato di “Discreto”

Differenza tra discreto e continuo.
L’intero mondo della matematica è diviso in due ambiti: discreto e continuo.

- **Oggetti Discreti:**

I numeri naturali  $\mathbb{N}$ sono discreto. Ad esempio: 1, 2, 3, 4, 5…
Tra 1 e 2 non c’è alcun numero, c’è una transizione netta tra  1 e 2, da 2 a 3 e via dicendo. Vale a dire quindi “distinto non connesso”

Quindi:
In matematica, si dice "**Discreto**" un insieme i cui elementi sono ben distinti, come una linea tratteggiata. Ad esempio l'insieme dei numeri naturali  $\mathbb{N}$, che utilizziamo per contare, oppure potremmo pensare ad una rampa di scale: possiamo stare sul primo scalino, o sul secondo; perché non ci sono scalini intermedi tra questi.

- Oggetti continui

I numeri reali $\mathbb{R}$ sono continui, tra 0 e 1 ci sono numeri come 0, 0.001…, 0.000001…, 0.1000001… e molti altri. Vale a dire quindi “continuo e connesso”

Quindi:
In matematica, il contrario di Discreto si dice "**Continuo**", ciò vuol dire che tra gli elementi di un insieme non c'è nessuno "spazio", bensì si tratta di un insieme denso e unificato. Un esempio di insieme continuo può essere l'insieme dei numeri reali $\mathbb{R}$, che contiene tutti i numeri (frazioni, radici, periodici) quindi tra un numero ed un altro c'è sempre un unità che vi sta in mezzo. Per rendere le cose più semplici, possiamo pensare ad una rampa - piuttosto che ad una rampa di scale - detta anche "*scivola*", puoi stare in qualsiasi posizione, cosa che non puoi fare con le scale.

# La logica Proposizionale

**Cos’è la logica?** In genere, la logica è un **linguaggio** formale utilizzata per rappresentare informazioni e ragionare su di esse, cioè trarre conclusioni tramite esse. 
Ogni linguaggio è composto da due parti fondamentali, **Sintassi** e **Semantica**:

- La **sintassi** definisce le regole di scrittura, dunque come devono essere costruite le frasi (quali simboli usare, in che ordine, eccetera).
- La **semantica** definisce il significato delle frasi e la sua veridicità, ossia se sono vere o false.

Dunque sintassi ≠ significato.

Ci sono diversi tipi di logiche, ma per lo studio di questa materia a noi interessa solo la **Logica Proposizionale**, che inoltre è la più semplice.

Il suo compito è quello di **affermare** che una proposizione, dunque un fatto, sia **vero** o **falso**, ma non entrambi. 
E’ inerentemente connessa al **mondo binario 0/1**, e dato che i suoi valori possono essere solo Vero oppure Falso, il suo collegamento al mondo binario è il seguente:

| V | F |
| --- | --- |
| 1 | 0 |

In Logica Proposizionale, la costruzione sintattica avviene usando regole semplici ed operatori.

### Logica Proposizionale: Sintassi

Il vocabolario consiste di un insieme di variabili proposizionali $P$ di solito denotate con $p, q, r$…

Queste variabili possono assumere solo 2 valori: $1$ o $V$, $0$ o $F$.

Ogni variabile è di per sé una “formula” proposizionale, ma formule più complesse si possono costruire utilizzando più variabili “collegandole” tramite operatori, detti connettivi logici.

- $\neg$ negazione: si legge “non”
- $\vee$  disgiunzione: si legge “o”
- $\land$  congiunzione: si legge “e”
- $\implies$implicazione: si legge “ se … allora …” oppure “implica”
- $\iff$co-implicazione: si legge “se e solo se” oppure “co-implica”

### Esempi di formule proposizionali

Supponiamo di avere due variabili proposizionali $P$ e $Q$ - teniamo a mente che una variabile è di per sé una formula - allora:

- $\neg P$ è una formula.
- $P \vee Q$ è una formula.
- $P \land Q$ è una formula.
- $P \implies Q$ è una formula.
- $P \iff Q$ è una formula.

### Ordine di precedenza degli operatori logici

Nelle formule logiche, l’ordine degli operatori segue regole di precedenza, e in più, l’ordine può essere forzato tramite l’uso di operatori.

I connettivi hanno precedenza che si applica da sinistra verso destra, per questo al fine di evitare ambiguità è utile utilizzare le parentesi.

1. $\neg$ ha la precedenza maggiore.
Esempi:
    - `$\neg p \vee q$` (si legge “non p o q”). In questa formula la negazione si applica solo a $p$.
    - `$\neg(p \vee q)$` (si legge “non p o q”). In questa formula la negazione si applica alla disgiunzione $p \vee q$.
2. $\vee$ e $\land$ hanno precedenza secondaria.
Esempi:
    - `$p \vee q \land r$` (si legge “p o q e r”). In questa formula la congiunzione si applica prima: equivale a $p \vee (q \land r)$.
    - `$(p \vee q) \land r$` (si legge “p o q e poi tutto e r”). In questa formula le parentesi forzano a valutare prima la disgiunzione $p \vee q$.
3. $\implies$ e $\iff$ hanno precedenza minore.
Esempi:
    - `$p \land q \implies r$` (si legge “p e q implica r”). In questa formula la congiunzione $p \land q$ viene valutata prima dell’implicazione.
    - `$p \vee q \iff \neg r \land s$` (si legge “p o q se e solo se non r e s”). In questa formula prima si valuta $\neg r$, poi $\neg r \land s$, poi $p \vee q$, infine tutto viene legato con $\iff$.

### Interpretazione

Un interpretazione $I$ su $P$ è una funzione $I : P \rightarrow \{ 0,1 \}$ o $I : P \rightarrow \{ T,F \}$.

Date due formule $P_1$ e $P_2$ e data un interpretazione $I$ che assegna un valore di verità alle variabili proposizionali presenti nella formula, si calcola il valore di verità di tutta la formula $I(P_1)$ o $I(P_2)$ come segue:

- $I(\neg P_1)$ è vera se e solo se $I(P_1)$ è falsa.
- $I(P_1 \vee P_2)$ è vera se e solo se almeno una tra $I(P_1)$ e $I(P_2)$ è vera.
- $I(P_1 \land P_2)$ è vera se e solo se $I(P_1)$ e $I(P_2)$ sono entrambe vere.
- $I(P_1 \implies P_2)$ è vera se e solo se $I(P_1)$ è falsa oppure se $I(P_2)$ è vera.
- $I(P_1 \iff P_2)$ è vera se e solo se $I(P_1 \implies P_2)$ è vera e $I(P_2 \implies P_1)$ è anch’essa vera.

### Tavola della verità

Per avere più familiarità con i valori di veridicità dei connettivi logici possiamo usare le tavole della verità.

**Negazione**

| $p$ | $\neg p$ |
| --- | --- |
| V | F |
| F | V |

**Congiunzione**

(Vera solo se entrambe vere)

**Disgiunzione**

(Vera se almeno una delle due è vera)

| $p$ | $q$ | $p \land q$ |
| --- | --- | --- |
| F | F | F |
| F | V | F |
| V | F | F |
| V | V | V |

| $p$ | $q$ | $p \vee q$ |
| --- | --- | --- |
| F | F | F |
| F | V | V |
| V | F | V |
| V | V | V |

**Implicazione**

**Co-implicazione**

| $p$ | $q$ | $p \implies q$ |
| --- | --- | --- |
| V | V | V |
| V | F | F |
| F | V | V |
| F | F | V |

| $p$ | $q$ | $p \iff q$ |
| --- | --- | --- |
| F | F | V |
| F | V | F |
| V | F | F |
| V | V | V |

### **Soddisfacibilità**

Una formula è detta **soddisfacibile** se nella sua tavola della verità esiste almeno un risultato vero.

Una formula è detta **insoddisfacibile** se nella sua tavola della verità non esiste alcun caso in cui sia vera.

Una formula si dice tautologia se è sempre vera. Indipendentemente dai valori di verità assegnati alle variabili, la formula rimane sempre vera.

Esempi:

- $p \land (q \vee \neg p)$ è soddisfacibile.
- $p \land (q \vee \neg p) \land (\neg q \land \neg p)$ è insoddisfacibile**.**
- $p \implies (\neg p \implies q)$ è una tautologia.

Lo dimostriamo utilizzando le tavole della verità.

**Esempio Soddisfacibile**

| p | q | $(q \vee \neg p)$ | $p \land (q \vee \neg p)$ |
| --- | --- | --- | --- |
| F | F | V | F |
| F | V | V | F |
| V | F | F | F |
| V | V | V | V |

**Esempio Insoddisfacibile**

| p | q | $q \vee \neg p$ | $\neg q \vee \neg p$ | $p \land (q \vee \neg p) \land (\neg q \land \neg p)$ |
| --- | --- | --- | --- | --- |
| F | F | V | V | F |
| F | V | V | V | F |
| V | F | F | V | F |
| V | V | V | F | F |

**Esempio Tautologia**

| $p$ | $q$ | $\neg p \implies q$ | $p \implies (\neg p \implies q$) |
| --- | --- | --- | --- |
| F | F | F | V |
| F | V | V | V |
| V | F | V | V |
| V | V | V | V |

### Principi fondamentali della logica

In logica proposizionale ci sono 2 principi fondamentali.
Per ogni proposizione $p$ si ha:

- ***Principio del terzo escluso***
$p \vee \neg p$ è una tautologia, ossia sempre vera.

Una proposizione è o vera o falsa, senza vie di mezzo.
Quindi "p oppure non p" è sempre vera (tautologia).
Esempio: "O piove, oppure non piove". Non esiste una terza possibilità.

- ***Principio di non contraddizione***
$p \land \neg p$ è insoddisfacibile, ossia sempre falsa.

Una proposizione non può essere vera e falsa allo stesso tempo.
Quindi "p e non p" è sempre falsa (insoddisfacibile).
Esempio: "Sta piovendo **e** non sta piovendo" è logicamente impossibile.

Questi due principi servono a **garantire coerenza** nella logica classica. Se una frase li viola, allora non può essere considerata **logicamente valida**.

### Equivalenza logica e proprietà

Due formule aventi le stesse variabili proposizionali, $P$ e $Q$, si dicono equi-soddisfacibili, e lo denotiamo con $P \equiv Q$. Se comunque assegniamo un valore alle variabili, P risulta vera se e solo se Q risulta vera.

Abbiamo allora le seguenti proprietà dei connettivi logici.

1. **Commutatività**
    - $p \vee q \equiv q \vee p$ (commutatività della disgiunzione)
    Se hai due interruttori, $P$ e $Q$, la luce si accenderà se almeno uno dei due interruttori è acceso, indipendentemente dall’ordine.
    - $p \land q \equiv q \land p$ (commutatività della congiunzione)
    Se hai due interruttori, $P$ e $Q$, la luce si accenderà solo se entrambi sono accesi, indipendentemente dall’ordine.
2. **Associatività**
    - $p \vee (q \vee r) \equiv (p \vee q) \vee r$ (associatività della disgiunzione)
    Se hai tre interruttori, $P$, $Q$ e $R$, la luce si accenderà solo se tutti e tre sono accesi, indipendentemente da come raggruppi gli interruttori.
    - $p \land (q\land r) \equiv (p \land q) \land r$ (associatività della congiunzione)
    Se hai tre interruttori, $P$, $Q$ e $R$, la luce si accenderà se almeno uno è acceso, indipendentemente da come raggruppi gli interruttori.

[Tavole di verità: Esercizi (1)](Logica%20Proposizionale/Tavole%20di%20verit%C3%A0%20Esercizi%20(1)%2032f1cf23380e8053a856c78dc76f4428.md)

[Equivalenza: Esercizi (1)](Logica%20Proposizionale/Equivalenza%20Esercizi%20(1)%2032f1cf23380e80f98850de637bd0e4af.md)

### Conseguenza Logica

Immagina di avere un insieme di affermazioni, che contiene:

- Affermazioni che consideri vere; ossia le tue **premesse**. Che indicheremo con $\mathcal{P}$
- Un’altra affermazione che consideri vera, ossia la tua **conclusione**. Che indicheremo con $P$

La Conseguenza Logica, denotata con $\mathcal P \models P$, ci dice che la conclusione P deriva logicamente dalla premessa P, se vale questa condizione fondamentale:

> In tutti i casi possibili (chiamati "interpretazioni" $I$ nel linguaggio logico) in cui le **tutte le tue premesse** nell’insieme $\mathcal P$ **sono vere**, allora anche la tua **conclusione $P$ deve essere necessariamente vera**.
> 

In altre parole, **non può mai succedere che tutte le premesse siano vere e la conclusione sia falsa.**

Come detto precedentemente, una **interpretazione $I$** è un'assegnazione di valori di verità (Vero/Falso, o 1/0) alle variabili proposizionali.
Una formula è "soddisfatta" da un'interpretazione se risulta vera con quell'assegnazione di valori.
Mente un insieme di formule è soddisfatto se **tutte** le formule al suo interno sono vere con quell'interpretazione.

Le **tavole di verità** sono lo strumento fondamentale per analizzare sistematicamente tutte le possibili interpretazioni delle variabili proposizionali coinvolte nelle formule. Ogni riga di una tavola di verità corrisponde a una diversa **interpretazione.**

Ecco come si usano le tavole di verità per verificare una conseguenza logica **$\mathcal P \models P$:**

Esempio di Conclusione Logica

| $p$ | $q$ | $p \implies q$ | $q$ |  |
| --- | --- | --- | --- | --- |
| F | F | V | F | $p$ falsa |
| F | V | V | V | $p$ falsa |
| V | F | F | F | $p \implies q$ falsa |
| V | V | V | V | ✅ **[Tautologia]** |

Cerchiamo le righe dove sia $p$ che $p \implies q$ sono vere. Guardando le colonne delle premesse, questo avviene **solo nell'ultima riga** ($p=V$, $q=V$), dove entrambe le premesse sono "$V$".

Nell'ultima riga, dove le premesse sono vere, guardiamo il valore della conclusione $q$. È "$V$".

Poiché l'unica riga in cui tutte le premesse ($p$ e $p \implies q$) sono vere è una riga in cui anche la conclusione ($q$) è vera, la giustificazione $\{p, p \implies q\} \models q$ è dimostrata.

### Forme Normali

Nelle applicazioni informatiche in cui si usano formule del calcolo proposizionale
si trasformano spesso le formule in forme standardizzate, ovvero in una delle
due seguenti forme normali:

- **Forma Normale Congiuntiva (CNF)**:
Una formula $p$ è in Forma Normale Congiuntiva (CNF) se è scritta come congiunzione di disgiunzioni. Per esempio
$(p \vee q)\land(\neg p \vee \neg r \vee s)$
Nell’esempio sopra, abbiamo 2 gruppi di disgiunzioni $\vee$ legati da una congiunzione $\land$.
- **Forma Normale Disgiuntiva (DNF)**:
Una formula $p$ è in Forma Normale Disgiuntiva. Per esempio
$(p \land q)\vee(\neg p \land \neg r \land s)$
Nell’esempio sopra, abbiamo 2 gruppi di congiunzioni $\land$ legati da una disgiunzione $\vee$.

Una qualunque formula $P$ si può trasformare in una delle due forme normali
attraverso un semplice procedimento algoritmico.

**Algoritmo di Trasformazione in Forma Normale:**

1. Elimina le doppie implicazioni $p \iff q$ dalla formula sostituendole con $(p \implies q) \land (q \implies p)$.
Dopo questa fase, la formula conterrà solo i connettivi $\neg, \vee, \land, \implies$
2. Elimina le implicazioni $p \implies q$ dalla formula sostituendole con $\neg p \vee q$.
Dopo questa fase, la formula conterrà solo i connettivi $\neg, \vee, \land$.
3. Ora dobbiamo spostare le negazioni “verso l’interno”. L’obiettivo è fare in modo che il connettivo di negazione $\neg$ appaia **solo direttamente davanti alle variabili proposizionali.** Per farlo usiamo le **Leggi di De Morgan,** e usiamo anche la **regola di eliminazione delle doppie negazioni**.
    
    Le Leggi di De Morgan:
    
    - $\neg(P \vee Q)$ diventa $\neg P \land \neg Q$
    - $\neg(P \land Q)$ diventa $\neg P \vee \neg Q$
    - $\neg(\neg P)$ diventa $P$
    
    Applica ripetutamente queste regole dall'esterno della formula verso l'interno, fino a quando ogni $\neg$ nega solo una singola variabile proposizionale.
    Per esempio
    $\neg(\neg p \vee \neg r \vee s)$ diventa $(p \land r \land \neg s)$.
    Vediamo come la negazione "esterna" viene spostata sui letterali interni (e la doppia negazione $\neg(\neg p)$ viene eliminata in $p$).
    
    Dopo questa fase, la formula sarà composta da letterali collegati solo da $\vee$ e $\land$.
    

Dal terzo passaggio in poi dobbiamo decidere quale strada prendere, ossia se trasformare la formula in CNF o DNF.

**Per ottenere la Forma Normale Congiuntiva (CNF) (Fase 4-a):**

- **Obiettivo**: Arrivare a una forma $(\text{proposizione  }\vee ... \vee \text{proposizione  }) \land (\text{proposizione  }\vee ... \vee \text{proposizione  }) \land …$
- **Come**: Devi distribuire la congiunzione ($\land$) sulla disgiunzione ($\vee$).
 Utilizza la regola di distributività $P \land (Q \vee R) \equiv (P \land Q) \vee (P \land R)$

… completare …