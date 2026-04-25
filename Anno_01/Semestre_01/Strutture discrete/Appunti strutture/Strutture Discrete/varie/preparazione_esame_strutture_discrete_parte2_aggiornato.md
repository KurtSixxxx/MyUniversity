# Preparazione Esame Strutture Discrete - Seconda Parte

Benvenuto! Questo documento è stato creato per fornirti un supporto completo e mirato per la preparazione della Seconda Parte del tuo esame di Strutture Discrete. Ho analizzato attentamente le slide del tuo professore e i quesiti degli appelli passati per offrirti un materiale didattico chiaro, sintetico e pratico.

Il contenuto è strutturato per argomenti, con sezioni dedicate alla teoria, agli schemi risolutivi per gli esercizi e all'analisi dei quesiti d'esame. L'obiettivo è rendere ogni concetto accessibile, fornendo definizioni precise, esempi concreti e trucchi per affrontare i problemi più comuni.

---

## Appunti Teorici: Parte II - Fondamenti di Teoria dei Numeri e Metodologie di Dimostrazione

Questa sezione è dedicata ai concetti fondamentali della Teoria dei Numeri e alle metodologie di dimostrazione, essenziali per la comprensione delle Strutture Discrete. Spiegheremo ogni concetto in modo semplice, definendo termini, simboli e notazioni, e useremo esempi concreti per illustrare le idee astratte.

### 1. Numeri Interi

I *numeri interi* sono l'insieme dei numeri naturali (0, 1, 2, ...) e dei loro opposti negativi (-1, -2, -3, ...). Sono denotati dal simbolo $\mathbb{Z}$.

#### 1.1 Operazioni sui Numeri Interi
Le operazioni fondamentali sui numeri interi sono addizione, sottrazione e moltiplicazione. Queste operazioni godono delle proprietà associative, commutative e distributive, analogamente a quanto avviene per i numeri reali.

#### 1.2 Principio di Induzione
Il **Principio di Induzione Matematica** è una potente tecnica di dimostrazione utilizzata per provare che una certa proprietà $P(n)$ è vera per tutti i numeri naturali $n \ge n_0$, dove $n_0$ è un intero fisso (spesso 0 o 1).

Per dimostrare una proprietà $P(n)$ per tutti i numeri naturali $n \ge n_0$ tramite induzione, si devono seguire due passi:

1.  **Passo Base (o Caso Base)**: Dimostrare che la proprietà $P(n_0)$ è vera per il valore iniziale $n_0$.
2.  **Passo Induttivo**: Assumere che la proprietà $P(k)$ sia vera per un generico intero $k \ge n_0$ (questa è l'*ipotesi induttiva*) e dimostrare che, sotto questa ipotesi, la proprietà $P(k+1)$ è vera.

Se entrambi i passi sono dimostrati, allora la proprietà $P(n)$ è vera per tutti i numeri naturali $n \ge n_0$.

*Esempio: Dimostrare che la somma dei primi $n$ numeri naturali è $n(n+1)/2$.*

Sia $P(n)$ la proprietà $1 + 2 + \dots + n = n(n+1)/2$.

1.  **Passo Base**: Per $n=1$, $P(1)$ è $1 = 1(1+1)/2 = 1(2)/2 = 1$. La proprietà è vera per $n=1$.
2.  **Passo Induttivo**: Assumiamo che $P(k)$ sia vera per un $k \ge 1$, cioè $1 + 2 + \dots + k = k(k+1)/2$. Dobbiamo dimostrare che $P(k+1)$ è vera, cioè $1 + 2 + \dots + k + (k+1) = (k+1)(k+2)/2$.
    Partiamo dal lato sinistro dell'equazione per $P(k+1)$:
    $1 + 2 + \dots + k + (k+1) = (1 + 2 + \dots + k) + (k+1)$
    Per l'ipotesi induttiva, possiamo sostituire la somma dei primi $k$ termini:
    $= k(k+1)/2 + (k+1)$
    Mettiamo in evidenza $(k+1)$:
    $= (k+1) [k/2 + 1]$
    $= (k+1) [(k+2)/2]$
    $= (k+1)(k+2)/2$
    Questo è esattamente il lato destro dell'equazione per $P(k+1)$. Quindi, il passo induttivo è dimostrato.

Per il Principio di Induzione, la proprietà $P(n)$ è vera per tutti i numeri naturali $n \ge 1$.

#### 1.3 Divisione tra Interi e Divisibilità

Per due interi $a$ e $b$, con $b \ne 0$, la *divisione euclidea* (o divisione con resto) afferma che esistono e sono unici due interi $q$ (quoziente) e $r$ (resto) tali che:

$a = bq + r$, con $0 \le r < |b|$.

Un intero $a$ è **divisibile** per un intero $b$ (o $b$ divide $a$, o $b$ è un divisore di $a$) se il resto $r$ della divisione di $a$ per $b$ è 0. In questo caso, scriviamo $b | a$.

#### 1.4 Massimo Comun Divisore (MCD) ed Algoritmo di Euclide

Il **Massimo Comun Divisore (MCD)** di due interi $a$ e $b$, non entrambi nulli, è il più grande intero positivo che divide sia $a$ che $b$. È denotato come $\text{MCD}(a, b)$.

L'**Algoritmo di Euclide** è un metodo efficiente per calcolare il MCD di due numeri interi. Si basa sul principio che $\text{MCD}(a, b) = \text{MCD}(b, r)$, dove $r$ è il resto della divisione di $a$ per $b$. Il processo si ripete fino a quando il resto diventa 0; il MCD è l'ultimo resto non nullo.

*Esempio: Calcolare $\text{MCD}(252, 198)$.*

1.  $252 = 1 \cdot 198 + 54$
2.  $198 = 3 \cdot 54 + 36$
3.  $54 = 1 \cdot 36 + 18$
4.  $36 = 2 \cdot 18 + 0$

L'ultimo resto non nullo è 18. Quindi, $\text{MCD}(252, 198) = 18$.

#### 1.5 Numeri Primi e Coprimi

Un intero $p > 1$ è un **numero primo** se i suoi unici divisori positivi sono 1 e $p$ stesso. Esempi: 2, 3, 5, 7, 11, ...

Due interi $a$ e $b$ sono **coprimi** (o relativamente primi) se il loro Massimo Comun Divisore è 1, cioè $\text{MCD}(a, b) = 1$.

### 2. Aritmetica Modulare

L'**Aritmetica Modulare** è un sistema di aritmetica per interi, dove i numeri si "avvolgono" dopo aver raggiunto un certo valore, chiamato *modulo*. È spesso chiamata "aritmetica dell'orologio" perché funziona in modo simile a un orologio, dove le ore si ripetono dopo 12.

#### 2.1 Congruenze

Due interi $a$ e $b$ sono **congruenti modulo $n$** (dove $n$ è un intero positivo, il modulo) se la loro differenza $a-b$ è un multiplo di $n$. In altre parole, $a$ e $b$ hanno lo stesso resto quando divisi per $n$. Questo si scrive come:

$a \equiv b \pmod{n}$

*Esempio: $17 \equiv 5 \pmod{12}$ perché $17 - 5 = 12$, che è un multiplo di 12. Entrambi 17 e 5 danno resto 5 quando divisi per 12.*

#### 2.2 Proprietà delle Congruenze

Le congruenze godono di diverse proprietà utili:

*   **Riflessività**: $a \equiv a \pmod{n}$
*   **Simmetria**: Se $a \equiv b \pmod{n}$, allora $b \equiv a \pmod{n}$
*   **Transitività**: Se $a \equiv b \pmod{n}$ e $b \equiv c \pmod{n}$, allora $a \equiv c \pmod{n}$

Queste tre proprietà indicano che la congruenza modulo $n$ è una *relazione di equivalenza*.

Inoltre, le congruenze sono compatibili con le operazioni di somma e prodotto:

*   **Somma**: Se $a \equiv b \pmod{n}$ e $c \equiv d \pmod{n}$, allora $a+c \equiv b+d \pmod{n}$
*   **Prodotto**: Se $a \equiv b \pmod{n}$ e $c \equiv d \pmod{n}$, allora $ac \equiv bd \pmod{n}$

Queste proprietà sono fondamentali per semplificare i calcoli in aritmetica modulare, specialmente con grandi numeri.

*Esempio: Calcolare $15^{15} \pmod{13}$.*

Sappiamo che $15 \equiv 2 \pmod{13}$.
Quindi, $15^{15} \equiv 2^{15} \pmod{13}$.
Ora calcoliamo le potenze di 2 modulo 13:
$2^1 \equiv 2 \pmod{13}$
$2^2 \equiv 4 \pmod{13}$
$2^3 \equiv 8 \pmod{13}$
$2^4 \equiv 16 \equiv 3 \pmod{13}$
$2^5 \equiv 2 \cdot 3 = 6 \pmod{13}$
$2^6 \equiv 2 · 6 = 12 \equiv -1 \pmod{13}$

Ora possiamo usare $2^6 \equiv -1 \pmod{13}$ per semplificare $2^{15}$:
$2^{15} = 2^{12} \cdot 2^3 = (2^6)^2 \cdot 2^3 \equiv (-1)^2 \cdot 8 \pmod{13}$
$2^{15} \equiv 1 \cdot 8 \pmod{13}$
$2^{15} \equiv 8 \pmod{13}$

Quindi, $15^{15} \equiv 8 \pmod{13}$.

#### 2.3 Inverso Modulare

Un intero $x$ è l'**inverso modulare** di $a$ modulo $n$ se $ax \equiv 1 \pmod{n}$. L'inverso modulare esiste se e solo se $a$ e $n$ sono coprimi, cioè $\text{MCD}(a, n) = 1$.

Per trovare l'inverso modulare, si può usare l'Algoritmo di Euclide Esteso. Questo algoritmo permette di trovare interi $x$ e $y$ tali che $ax + ny = \text{MCD}(a, n)$. Se $\text{MCD}(a, n) = 1$, allora $ax + ny = 1$. Prendendo questa equazione modulo $n$, otteniamo $ax \equiv 1 \pmod{n}$, e $x$ è l'inverso modulare.

*Esempio: Trovare l'inverso modulare di 5 modulo 13.*

Usiamo l'Algoritmo di Euclide per trovare $\text{MCD}(5, 13)$:
$13 = 2 \cdot 5 + 3$
$5 = 1 \cdot 3 + 2$
$3 = 1 \cdot 2 + 1$
$2 = 2 \cdot 1 + 0$
$\text{MCD}(5, 13) = 1$, quindi l'inverso esiste.

Ora, risaliamo le equazioni per esprimere 1 come combinazione lineare di 5 e 13:
$1 = 3 - 1 \cdot 2$
$1 = 3 - 1 \cdot (5 - 1 \cdot 3) = 3 - 5 + 3 = 2 \cdot 3 - 5$
$1 = 2 \cdot (13 - 2 \cdot 5) - 5 = 2 \cdot 13 - 4 \cdot 5 - 5 = 2 \cdot 13 - 5 \cdot 5$

Quindi $1 = 2 \cdot 13 - 5 \cdot 5$. Questo significa che $-5 \cdot 5 \equiv 1 \pmod{13}$.
$-5 \equiv 8 \pmod{13}$. Quindi l'inverso di 5 modulo 13 è 8.
Verifica: $5 \cdot 8 = 40$. $40 = 3 \cdot 13 + 1$. Corretto!

#### 2.4 Funzione φ di Eulero (Totiente di Eulero)

La **funzione φ di Eulero** (o funzione totiente) $\phi(n)$ conta il numero di interi positivi minori o uguali a $n$ che sono coprimi con $n$. In altre parole, $\phi(n) = |\{k \in \mathbb{Z} \mid 1 \le k \le n, \text{MCD}(k, n) = 1\}|$.

*Esempio: $\phi(10)$. I numeri coprimi con 10 tra 1 e 10 sono 1, 3, 7, 9. Quindi $\phi(10) = 4$.*

**Formula Generale per $\phi(n)$**:

Se la fattorizzazione in primi di $n$ è $n = p_1^{k_1} p_2^{k_2} \dots p_r^{k_r}$, allora:

$\phi(n) = n \left(1 - \frac{1}{p_1}\right) \left(1 - \frac{1}{p_2}\right) \dots \left(1 - \frac{1}{p_r}\right)$

*Esempio: $\phi(12)$. La fattorizzazione di 12 è $2^2 \cdot 3^1$.*
$\phi(12) = 12 \left(1 - \frac{1}{2}\right) \left(1 - \frac{1}{3}\right) = 12 \left(\frac{1}{2}\right) \left(\frac{2}{3}\right) = 12 \cdot \frac{1}{3} = 4$.
I numeri coprimi con 12 tra 1 e 12 sono 1, 5, 7, 11. Quindi $\phi(12) = 4$.

#### 2.5 Teorema di Eulero

Il **Teorema di Eulero** afferma che se $a$ e $n$ sono interi positivi coprimi (cioè $\text{MCD}(a, n) = 1$), allora:

$a^{\phi(n)} \equiv 1 \pmod{n}$

Questo teorema è una generalizzazione del Piccolo Teorema di Fermat (che è un caso speciale quando $n$ è un numero primo).

*Esempio: Calcolare $7^{100} \pmod{10}$.*

Sappiamo che $\text{MCD}(7, 10) = 1$. Calcoliamo $\phi(10) = 4$.
Per il Teorema di Eulero, $7^{\phi(10)} \equiv 7^4 \equiv 1 \pmod{10}$.
Ora possiamo usare questa informazione per calcolare $7^{100}$:
$7^{100} = (7^4)^{25} \equiv 1^{25} \pmod{10}$
$7^{100} \equiv 1 \pmod{10}$.

#### 2.6 Applicazioni dell'Aritmetica Modulare

L'aritmetica modulare ha numerose applicazioni in informatica e crittografia. Un esempio semplice è la **prova del 9**, un metodo per verificare la correttezza di calcoli aritmetici basato sulla congruenza modulo 9. Oltre a questo, troviamo applicazioni nei **Codici ISBN**, nelle **Carte di Credito** e nei **Cifrari monoalfabetici a trasposizione**.

##### 2.6.1 Codici ISBN

Il **Codice ISBN (International Standard Book Number)** è un identificatore numerico commerciale di libri. Fino al 2006 era un codice a 10 cifre, dal 2007 è a 13 cifre. L'ultima cifra è una cifra di controllo che serve a verificare la correttezza del codice, basandosi sull'aritmetica modulare.

Per l'ISBN-10, la cifra di controllo $x_{10}$ è calcolata in modo che la somma ponderata delle cifre sia congruente a 0 modulo 11:

$\sum_{i=1}^{9} i \cdot x_i + 10 \cdot x_{10} \equiv 0 \pmod{11}$

Dove $x_i$ sono le prime 9 cifre e $x_{10}$ è la cifra di controllo (che può essere 10, rappresentata con 'X').

##### 2.6.2 Carte di Credito

Anche i numeri delle **Carte di Credito** utilizzano algoritmi basati sull'aritmetica modulare (come l'algoritmo di Luhn) per la verifica della validità. Questo aiuta a prevenire errori di trascrizione e a rilevare numeri di carta falsi. L'algoritmo di Luhn non è un metodo crittografico, ma un semplice checksum.

##### 2.6.3 Cifrari Monoalfabetici a Trasposizione

I **cifrari monoalfabetici a trasposizione** sono metodi crittografici classici in cui le lettere del messaggio originale vengono sostituite con altre lettere o simboli secondo una chiave fissa. L'aritmetica modulare è fondamentale per implementare questi cifrari, ad esempio per mappare le lettere dell'alfabeto a numeri e poi eseguire operazioni aritmetiche modulo la dimensione dell'alfabeto (es. modulo 26 per l'alfabeto inglese).

In crittografia, algoritmi come RSA si basano pesantemente sui principi dell'aritmetica modulare e della teoria dei numeri per garantire la sicurezza delle comunicazioni.

#### 2.7 Teoria dei Numeri e Problemi Aperti

La teoria dei numeri è ricca di problemi affascinanti che, nonostante la loro apparente semplicità, rimangono irrisolti da secoli. Questi problemi stimolano la ricerca matematica e hanno portato a scoperte significative.

##### 2.7.1 Numeri Primi di Mersenne e Numeri Perfetti

Un **numero primo di Mersenne** è un numero primo della forma $2^p - 1$, dove $p$ è a sua volta un numero primo. Non si sa se esistano infiniti numeri primi di Mersenne.

Un **numero perfetto** è un intero positivo che è uguale alla somma dei suoi divisori positivi propri (esclusi se stesso). Ad esempio, 6 è un numero perfetto perché $1+2+3=6$. Euclide dimostrò che se $2^p - 1$ è un primo di Mersenne, allora $2^{p-1}(2^p - 1)$ è un numero perfetto pari. Eulero dimostrò che tutti i numeri perfetti pari sono di questa forma. Non si sa se esistano numeri perfetti dispari.

##### 2.7.2 Numeri Primi Gemelli

I **numeri primi gemelli** sono coppie di numeri primi che differiscono di 2 (es. (3, 5), (5, 7), (11, 13)). La **congettura dei primi gemelli** afferma che esistono infiniti numeri primi gemelli. Anche questo è un problema aperto.

##### 2.7.3 La Congettura di Goldbach

La **congettura di Goldbach** afferma che ogni numero pari maggiore di 2 può essere espresso come la somma di due numeri primi. Ad esempio, $4 = 2+2$, $6 = 3+3$, $8 = 3+5$, $10 = 3+7 = 5+5$. Questa congettura è stata verificata per numeri enormi, ma non è stata ancora dimostrata per tutti i numeri pari.

#### 2.8 Caso Studio: Il Problema 3x + 1 (Congettura di Collatz)

La **Congettura di Collatz** (o problema 3x + 1) è un problema matematico molto semplice da enunciare ma estremamente difficile da risolvere. Si definisce una sequenza come segue:

*   Se $n$ è pari, il prossimo numero è $n/2$.
*   Se $n$ è dispari, il prossimo numero è $3n+1$.

La congettura afferma che, partendo da qualsiasi intero positivo, la sequenza alla fine raggiungerà sempre il numero 1. Ad esempio, partendo da 6: $6 \to 3 \to 10 \to 5 \to 16 \to 8 \to 4 \to 2 \to 1$. Nonostante sia stata verificata per un numero enorme di valori iniziali, non è stata ancora dimostrata per tutti i numeri.

### 3. Calcolo Combinatorio e Probabilità Discrete

Questa sezione esplora i metodi per contare il numero di possibili arrangiamenti o combinazioni di oggetti e introduce i concetti fondamentali della probabilità in contesti discreti.

#### 3.1 Calcolo Combinatorio

Il **Calcolo Combinatorio** si occupa di contare il numero di modi in cui gli elementi di un insieme possono essere raggruppati o ordinati, seguendo determinate regole. Le principali tecniche includono permutazioni, disposizioni e combinazioni.

##### 3.1.1 Permutazioni

Una **permutazione** è un riordinamento degli elementi di un insieme. Se abbiamo $n$ oggetti distinti, il numero di modi in cui possono essere ordinati è $n!$ (n fattoriale).

$n! = n \times (n-1) \times \dots \times 2 \times 1$

*Esempio: In quanti modi diversi si possono sedere 3 persone su 3 sedie?*
$3! = 3 \times 2 \times 1 = 6$ modi.

##### 3.1.2 Disposizioni Semplici

Le **disposizioni semplici** contano il numero di modi in cui si possono scegliere $k$ oggetti da un insieme di $n$ oggetti distinti, *tenendo conto dell'ordine*. La formula è:

$P(n, k) = \frac{n!}{(n-k)!}$

*Esempio: Quanti numeri di 3 cifre diverse si possono formare con le cifre 1, 2, 3, 4, 5?*
$n=5, k=3$. $P(5, 3) = \frac{5!}{(5-3)!} = \frac{5!}{2!} = 5 \times 4 \times 3 = 60$ numeri.

##### 3.1.3 Combinazioni Semplici

Le **combinazioni semplici** contano il numero di modi in cui si possono scegliere $k$ oggetti da un insieme di $n$ oggetti distinti, *senza tenere conto dell'ordine*. La formula è:

$\binom{n}{k} = \frac{n!}{k!(n-k)!}$

*Esempio: In quanti modi si possono scegliere 2 studenti da un gruppo di 5?*
$\binom{5}{2} = \frac{5!}{2!(5-2)!} = \frac{5!}{2!3!} = \frac{5 \times 4}{2 \times 1} = 10$ modi.

#### 3.2 Principio dei Cassetti (Pigeonhole Principle)

Il **Principio dei Cassetti** (o Principio di Dirichlet) afferma che se si hanno $n$ oggetti da sistemare in $m$ cassetti, e $n > m$, allora almeno un cassetto deve contenere più di un oggetto.

Nella sua forma generalizzata, se $n$ oggetti sono distribuiti in $m$ cassetti, allora almeno un cassetto contiene almeno $\lceil n/m \rceil$ oggetti (dove $\lceil x \rceil$ indica il più piccolo intero maggiore o uguale a $x$).

*Esempio: In un gruppo di 13 persone, almeno due sono nate nello stesso mese. (Oggetti = 13 persone, Cassetti = 12 mesi. $13 > 12$, quindi almeno un mese ha più di una persona nata in esso).*

#### 3.3 Probabilità Discreta

La **probabilità discreta** si occupa di eventi in spazi campionari finiti o numerabili. La probabilità di un evento $E$ è data da:

$P(E) = \frac{\text{Numero di casi favorevoli}}{\text{Numero totale di casi possibili}}$

##### 3.3.1 Variabili Casuali e Valore Atteso

Una **variabile casuale discreta** $X$ è una funzione che associa un valore numerico a ciascun risultato di un esperimento casuale. Il **valore atteso** (o media) di una variabile casuale discreta $X$ è la somma dei prodotti di ciascun possibile valore per la sua probabilità:

$E[X] = \sum_{x} x \cdot P(X=x)$

Una proprietà fondamentale è la **linearità del valore atteso**: $E[X+Y] = E[X] + E[Y]$, anche se $X$ e $Y$ non sono indipendenti.

*Esempio: Il valore atteso del lancio di un dado equo è $E[X] = 1 \cdot (1/6) + 2 \cdot (1/6) + \dots + 6 \cdot (1/6) = 3.5$.*

### 4. Teoria dei Grafi

La **Teoria dei Grafi** studia le proprietà dei grafi, strutture matematiche utilizzate per modellare relazioni tra oggetti. Un grafo $G = (V, E)$ è composto da un insieme di *vertici* $V$ e un insieme di *archi* $E$ che connettono coppie di vertici.

#### 4.1 Planarità e Omeomorfismo (Teorema di Kuratowski)

Un grafo è **planare** se può essere disegnato su un piano senza che i suoi archi si intersechino (se non nei vertici). Il **Teorema di Kuratowski** fornisce una condizione necessaria e sufficiente per la planarità:

Un grafo è planare se e solo se non contiene un sottografo che è omeomorfo a $K_5$ (il grafo completo con 5 vertici) o a $K_{3,3}$ (il grafo bipartito completo con 3 vertici in ciascun insieme della partizione).

Due grafi sono **omeomorfi** se uno può essere ottenuto dall'altro inserendo o rimuovendo vertici di grado 2 (cioè, vertici che connettono esattamente due archi).

#### 4.2 Grafi Euleriani e Hamiltoniani

*   Un **circuito euleriano** è un cammino che attraversa ogni arco del grafo esattamente una volta e ritorna al vertice di partenza. Un grafo connesso ha un circuito euleriano se e solo se tutti i suoi vertici hanno grado pari.
*   Un **cammino euleriano** è un cammino che attraversa ogni arco del grafo esattamente una volta. Un grafo connesso ha un cammino euleriano se e solo se ha esattamente due vertici di grado dispari (il cammino inizia e finisce in questi vertici).

*   Un **ciclo hamiltoniano** è un ciclo che visita ogni vertice del grafo esattamente una volta (tranne il vertice di partenza/arrivo). Non esiste una condizione necessaria e sufficiente semplice come per i grafi euleriani. Teoremi come quello di Dirac e Ore forniscono condizioni sufficienti.
*   Un **cammino hamiltoniano** è un cammino che visita ogni vertice del grafo esattamente una volta.

#### 4.3 Proprietà degli Alberi

Un **albero** è un grafo connesso e aciclico (non contiene cicli). Le proprietà fondamentali degli alberi includono:

*   Un albero con $v$ vertici ha esattamente $v-1$ archi.
*   Esiste un unico cammino tra ogni coppia di vertici.
*   L'aggiunta di un arco tra due vertici non adiacenti in un albero crea esattamente un ciclo.

Un **albero libero** è un albero non radicato. Un **albero radicato** è un albero in cui un vertice è designato come radice, e tutti gli altri vertici sono organizzati in livelli rispetto alla radice.

#### 4.4 Grafi Planari Massimali

Un grafo planare è **massimale** se non è possibile aggiungere alcun arco tra due vertici non adiacenti senza violare la planarità. Per un grafo planare massimale connesso con $v \ge 3$ vertici:

*   Numero di archi $e = 3v - 6$.
*   Numero di facce $f = 2v - 4$.

---

## Schemi Risolutivi per Esercizi di Strutture Discrete (Seconda Parte)

Questa sezione fornisce schemi risolutivi passo-passo per le tipologie di problemi più comuni che si incontrano negli esami di Strutture Discrete, con esempi concreti e consigli per evitare errori comuni.

### 1. Aritmetica Modulare

#### 1.1 Calcolo di Potenze Modulo $n$ (Es. $a^b \pmod{n}$)

**Obiettivo**: Calcolare il resto di una potenza molto grande quando divisa per un numero $n$.

**Schema Risolutivo**:

1.  **Semplificare la base**: Se $a \ge n$, sostituire $a$ con $a \pmod{n}$. Questo riduce la base a un numero più piccolo, rendendo i calcoli più gestibili. Quindi, $a^b \pmod{n} \equiv (a \pmod{n})^b \pmod{n}$.
2.  **Trovare un ciclo (se possibile)**: Calcolare le prime potenze della base semplificata modulo $n$ ($a^1 \pmod{n}$, $a^2 \pmod{n}$, $a^3 \pmod{n}$, ...) fino a quando non si trova un valore che si ripete o si raggiunge 1. Questo rivela la lunghezza del ciclo delle potenze.
3.  **Applicare il Teorema di Eulero (se applicabile)**: Se $\text{MCD}(a, n) = 1$, è possibile usare il Teorema di Eulero: $a^{\phi(n)} \equiv 1 \pmod{n}$. Questo è estremamente utile per ridurre l'esponente $b$.
    *   Calcolare $\phi(n)$.
    *   Sostituire l'esponente $b$ con $b \pmod{\phi(n)}$. Se $b \pmod{\phi(n)} = 0$, allora l'esponente effettivo è $\phi(n)$ (a meno che $b=0$, in tal caso $a^0=1$).
    *   Calcolare $a^{(b \pmod{\phi(n)})} \pmod{n}$.
4.  **Calcolo iterativo (se il Teorema di Eulero non è applicabile o per piccoli esponenti)**: Se non si può usare il Teorema di Eulero (es. $\text{MCD}(a, n) \ne 1$) o se l'esponente è piccolo, si può calcolare la potenza in modo iterativo, riducendo il risultato modulo $n$ ad ogni passo per evitare numeri troppo grandi.
    *   $a^b = a \cdot a \cdot \dots \cdot a$ ($b$ volte).
    *   $(a \cdot a) \pmod{n} \cdot a \pmod{n} \dots$

**Esempio**: Calcolare $15^{15} \pmod{13}$.

1.  **Semplificare la base**: $15 \equiv 2 \pmod{13}$. Quindi, $15^{15} \pmod{13} \equiv 2^{15} \pmod{13}$.
2.  **Applicare il Teorema di Eulero**: $\text{MCD}(2, 13) = 1$, quindi possiamo usare il Teorema di Eulero.
    *   Calcoliamo $\phi(13)$. Poiché 13 è un numero primo, $\phi(13) = 13 - 1 = 12$.
    *   Sostituiamo l'esponente $15$ con $15 \pmod{12} = 3$. (Nota: se il resto fosse 0, useremmo $\phi(n)$ come esponente).
    *   Quindi, $2^{15} \pmod{13} \equiv 2^3 \pmod{13}$.
3.  **Calcolo finale**: $2^3 = 8$. Quindi, $15^{15} \pmod{13} \equiv 8 \pmod{13}$.

**Errori Comuni da Evitare**:
*   Dimenticare di semplificare la base modulo $n$ all'inizio.
*   Applicare il Teorema di Eulero quando $\text{MCD}(a, n) \ne 1$.
*   Errore nel calcolo di $\phi(n)$.
*   Se $b \pmod{\phi(n)} = 0$, usare $\phi(n)$ come esponente, non 0 (a meno che l'esponente originale $b$ fosse 0).

#### 1.2 Verifica Codici ISBN (ISBN-10)

**Obiettivo**: Verificare la validità di un codice ISBN-10 utilizzando l'aritmetica modulare.

**Schema Risolutivo**:

1.  **Identificare le cifre**: Un codice ISBN-10 è composto da 10 cifre $x_1 x_2 \dots x_9 x_{10}$. L'ultima cifra $x_{10}$ è la cifra di controllo. Se $x_{10}$ è 'X', il suo valore numerico è 10.
2.  **Calcolare la somma ponderata**: Calcolare la somma ponderata delle cifre secondo la formula:
    $\sum_{i=1}^{9} i \cdot x_i + 10 \cdot x_{10}$
3.  **Verificare la congruenza**: Il codice è valido se la somma ponderata è congruente a 0 modulo 11, cioè:
    $\sum_{i=1}^{9} i \cdot x_i + 10 \cdot x_{10} \equiv 0 \pmod{11}$

**Esempio**: Verificare la validità dell'ISBN-10: 0-306-40615-2.

1.  **Cifre**: $x_1=0, x_2=3, x_3=0, x_4=6, x_5=4, x_6=0, x_7=6, x_8=1, x_9=5, x_{10}=2$.
2.  **Somma ponderata**:
    $1\cdot0 + 2\cdot3 + 3\cdot0 + 4\cdot6 + 5\cdot4 + 6\cdot0 + 7\cdot6 + 8\cdot1 + 9\cdot5 + 10\cdot2$
    $= 0 + 6 + 0 + 24 + 20 + 0 + 42 + 8 + 45 + 20 = 165$
3.  **Verifica congruenza**: $165 \pmod{11}$.
    $165 = 11 \cdot 15 + 0$. Quindi $165 \equiv 0 \pmod{11}$.
    Il codice ISBN è valido.

**Errori Comuni da Evitare**:
*   Errori nel calcolo della somma ponderata.
*   Dimenticare che 'X' vale 10 per la cifra di controllo.

#### 1.3 Ricerca dell'Inverso Modulare (Es. $ax \equiv 1 \pmod{n}$)

**Obiettivo**: Trovare un intero $x$ tale che $ax \equiv 1 \pmod{n}$.

**Schema Risolutivo**:

1.  **Verificare l'esistenza**: L'inverso modulare $x$ esiste se e solo se $\text{MCD}(a, n) = 1$. Se non sono coprimi, l'inverso non esiste.
2.  **Algoritmo di Euclide Esteso**: Utilizzare l'Algoritmo di Euclide Esteso per esprimere $\text{MCD}(a, n)$ come combinazione lineare di $a$ e $n$. Se $\text{MCD}(a, n) = 1$, si otterrà un'equazione del tipo $ax + ny = 1$.
    *   Eseguire l'Algoritmo di Euclide per trovare il MCD.
    *   Riscrivere le equazioni dell'Algoritmo di Euclide all'indietro per esprimere 1 come combinazione lineare di $a$ e $n$.
3.  **Identificare l'inverso**: Il coefficiente di $a$ nell'equazione $ax + ny = 1$ sarà l'inverso modulare. Se è negativo, aggiungere $n$ fino a renderlo positivo e minore di $n$.

**Esempio**: Trovare l'inverso modulare di 5 modulo 13.

1.  **Verificare l'esistenza**: $\text{MCD}(5, 13) = 1$, quindi l'inverso esiste.
2.  **Algoritmo di Euclide Esteso**:
    *   $13 = 2 \cdot 5 + 3$
    *   $5 = 1 \cdot 3 + 2$
    *   $3 = 1 \cdot 2 + 1$
    *   $2 = 2 \cdot 1 + 0$
    Riscriviamo all'indietro:
    *   $1 = 3 - 1 \cdot 2$
    *   $1 = 3 - 1 \cdot (5 - 1 \cdot 3) = 3 - 5 + 3 = 2 \cdot 3 - 5$
    *   $1 = 2 \cdot (13 - 2 \cdot 5) - 5 = 2 \cdot 13 - 4 \cdot 5 - 5 = 2 \cdot 13 - 5 \cdot 5$
    Quindi, abbiamo $1 = (-5) \cdot 5 + (2) \cdot 13$.
3.  **Identificare l'inverso**: Il coefficiente di 5 è -5. Poiché $-5 \equiv 8 \pmod{13}$, l'inverso modulare di 5 modulo 13 è 8.

**Errori Comuni da Evitare**:
*   Non verificare se il MCD è 1 prima di iniziare. Se non lo è, l'inverso non esiste.
*   Errori nei calcoli dell'Algoritmo di Euclide Esteso.
*   Non convertire l'inverso in un valore positivo e minore di $n$ se necessario.

#### 1.4 Cifrari Monoalfabetici a Trasposizione

**Obiettivo**: Cifrare o decifrare un messaggio usando un cifrario monoalfabetico a trasposizione (es. cifrario di Cesare).

**Schema Risolutivo (Cifrario di Cesare)**:

1.  **Mappare le lettere a numeri**: Assegnare un numero a ciascuna lettera dell'alfabeto (es. A=0, B=1, ..., Z=25).
2.  **Identificare la chiave**: La chiave $k$ è il numero di posizioni di cui ogni lettera viene spostata.
3.  **Cifratura**: Per ogni lettera $x$ del messaggio in chiaro, la lettera cifrata $y$ è data da:
    $y \equiv (x + k) \pmod{26}$
4.  **Decifratura**: Per ogni lettera cifrata $y$, la lettera in chiaro $x$ è data da:
    $x \equiv (y - k) \pmod{26}$
5.  **Mappare i numeri a lettere**: Convertire i numeri risultanti nuovamente in lettere.

**Esempio (Cifrario di Cesare con chiave $k=3$)**: Cifrare il messaggio "CIAO".

1.  **Mappatura**: C=2, I=8, A=0, O=14.
2.  **Chiave**: $k=3$.
3.  **Cifratura**:
    *   C: $(2 + 3) \pmod{26} = 5 \implies F$
    *   I: $(8 + 3) \pmod{26} = 11 \implies L$
    *   A: $(0 + 3) \pmod{26} = 3 \implies D$
    *   O: $(14 + 3) \pmod{26} = 17 \implies R$
4.  **Messaggio Cifrato**: FLDR.

**Errori Comuni da Evitare**:
*   Errori nella mappatura lettere-numeri o viceversa.
*   Dimenticare l'operazione modulo 26 (o la dimensione dell'alfabeto usato).
*   Confondere cifratura e decifratura.

### 2. Principio di Induzione

#### 2.1 Dimostrazioni per Induzione

**Obiettivo**: Dimostrare che una proprietà $P(n)$ è vera per tutti i numeri naturali $n \ge n_0$.

**Schema Risolutivo**:

1.  **Definire la Proprietà $P(n)$**: Enunciare chiaramente la proprietà che si vuole dimostrare in funzione di $n$.
2.  **Passo Base**: Dimostrare che $P(n_0)$ è vera. Sostituire $n_0$ nella proprietà e verificare che l'uguaglianza o l'affermazione sia valida. Questo è spesso il passo più semplice, ma cruciale.
3.  **Passo Induttivo**:
    *   **Ipotesi Induttiva**: Assumere che $P(k)$ sia vera per un generico intero $k \ge n_0$. Scrivere esplicitamente questa assunzione.
    *   **Tesi Induttiva**: Dimostrare che $P(k+1)$ è vera, utilizzando l'ipotesi induttiva. Questo è il cuore della dimostrazione. Spesso si parte da un lato dell'uguaglianza (o disuguaglianza) per $P(k+1)$ e, tramite manipolazioni algebriche e l'applicazione dell'ipotesi induttiva, si arriva all'altro lato.
4.  **Conclusione**: Affermare che, per il Principio di Induzione, la proprietà $P(n)$ è vera per tutti i $n \ge n_0$.

**Esempio**: Dimostrare che la somma dei primi $n$ numeri naturali è $n(n+1)/2$.

1.  **Proprietà $P(n)$**: $1 + 2 + \dots + n = n(n+1)/2$.
2.  **Passo Base**: Per $n=1$, $P(1)$ è $1 = 1(1+1)/2 = 1$. Vero.
3.  **Passo Induttivo**:
    *   **Ipotesi Induttiva**: Assumiamo che $P(k)$ sia vera per un $k \ge 1$, cioè $1 + 2 + \dots + k = k(k+1)/2$.
    *   **Tesi Induttiva**: Dobbiamo dimostrare che $P(k+1)$ è vera, cioè $1 + 2 + \dots + k + (k+1) = (k+1)(k+2)/2$.
        Partiamo dal lato sinistro di $P(k+1)$:
        $(1 + 2 + \dots + k) + (k+1)$
        Per l'ipotesi induttiva, sostituiamo la somma dei primi $k$ termini:
        $= k(k+1)/2 + (k+1)$
        Mettiamo in evidenza $(k+1)$:
        $= (k+1) [k/2 + 1]$
        $= (k+1) [(k+2)/2]$
        $= (k+1)(k+2)/2$
        Questo è il lato destro di $P(k+1)$. Quindi, $P(k+1)$ è vera.
4.  **Conclusione**: Per il Principio di Induzione, la proprietà è vera per tutti i numeri naturali $n \ge 1$.

**Errori Comuni da Evitare**:
*   Non dimostrare il passo base o dimostrarlo in modo errato.
*   Non usare l'ipotesi induttiva nel passo induttivo. Il passo induttivo deve mostrare una connessione logica tra $P(k)$ e $P(k+1)$.
*   Assumere che $P(k+1)$ sia vera e cercare di dimostrare $P(k)$ (errore di ragionamento circolare).
*   Errori algebrici durante le manipolazioni nel passo induttivo.

### 3. Calcolo Combinatorio e Probabilità

#### 3.1 Problemi di Conteggio (Permutazioni, Disposizioni, Combinazioni)

**Obiettivo**: Determinare il numero di modi in cui un insieme di oggetti può essere arrangiato o selezionato, in base a specifiche condizioni.

**Schema Risolutivo**:

1.  **Identificare il tipo di problema**: Chiedersi:
    *   **L'ordine conta?** Se sì, si tratta di permutazioni o disposizioni. Se no, si tratta di combinazioni.
    *   **Le ripetizioni sono ammesse?** Se sì, si usano formule con ripetizione. Se no, si usano formule semplici.
2.  **Determinare $n$ e $k$**: Identificare il numero totale di oggetti disponibili ($n$) e il numero di oggetti da scegliere o arrangiare ($k$).
3.  **Applicare la formula corretta**:
    *   **Permutazioni (ordine conta, no ripetizioni, tutti gli oggetti)**: $n!$
    *   **Disposizioni Semplici (ordine conta, no ripetizioni, $k$ oggetti da $n$)**: $P(n, k) = \frac{n!}{(n-k)!}$
    *   **Combinazioni Semplici (ordine non conta, no ripetizioni, $k$ oggetti da $n$)**: $\binom{n}{k} = \frac{n!}{k!(n-k)!}$
    *   **Combinazioni con Ripetizione (ordine non conta, ripetizioni ammesse, $k$ oggetti da $n$)**: $\binom{n+k-1}{k}$

**Esempio**: In quanti modi si possono scegliere 3 palline da un sacchetto contenente palline rosse, blu e verdi, se le palline dello stesso colore sono indistinguibili e possiamo scegliere più volte lo stesso colore?

1.  **Tipo di problema**: L'ordine non conta (le palline sono indistinguibili per colore), e le ripetizioni sono ammesse (possiamo scegliere più volte lo stesso colore). Si tratta di combinazioni con ripetizione.
2.  **$n$ e $k$**: $n=3$ (colori disponibili: rosso, blu, verde), $k=3$ (palline da scegliere).
3.  **Formula**: $\binom{n+k-1}{k} = \binom{3+3-1}{3} = \binom{5}{3}$.
4.  **Calcolo**: $\binom{5}{3} = \frac{5!}{3!(5-3)!} = \frac{5!}{2!3!} = \frac{5 \times 4}{2 \times 1} = 10$ modi.

**Errori Comuni da Evitare**:
*   Confondere permutazioni, disposizioni e combinazioni. La chiave è capire se l'ordine è rilevante e se le ripetizioni sono permesse.
*   Errori nel calcolo dei fattoriali o dei coefficienti binomiali.

#### 3.2 Principio dei Cassetti (Pigeonhole Principle)

**Obiettivo**: Dimostrare l'esistenza di almeno un elemento con una certa proprietà quando gli elementi sono distribuiti in categorie.

**Schema Risolutivo**:

1.  **Identificare Oggetti e Cassetti**: Il primo passo è capire cosa rappresentano gli oggetti e cosa i cassetti nel contesto del problema. Gli *oggetti* sono gli elementi che vengono distribuiti, e i *cassetti* sono le categorie in cui vengono distribuiti.
2.  **Applicare il Principio**: Se il numero di oggetti ($n$) è maggiore del numero di cassetti ($m$), allora almeno un cassetto deve contenere più di un oggetto. Nella versione generalizzata, almeno un cassetto conterrà $\lceil n/m \rceil$ oggetti.
3.  **Formulare la Conclusione**: Tradurre il risultato matematico in una risposta chiara e concisa che risolva il quesito originale.

**Trucchi e Consigli**:
*   Sii creativo nell'identificare oggetti e cassetti. A volte non sono immediatamente ovvi.
*   Ricorda la funzione soffitto $\lceil x \rceil$ per la versione generalizzata del principio.

**Errori Comuni da Evitare**:
*   Confondere oggetti e cassetti.
*   Errori nel calcolo della funzione soffitto.

#### 3.3 Probabilità Discreta: Valore Atteso

**Obiettivo**: Calcolare il valore atteso di una variabile casuale discreta.

**Schema Risolutiva**:

1.  **Identificare la Variabile Casuale**: Definire la variabile casuale $X$.
2.  **Determinare i Possibili Valori e le Loro Probabilità**: Elencare i valori $x$ che $X$ può assumere e le probabilità $P(X=x)$.
3.  **Applicare la Formula del Valore Atteso**: $E[X] = \sum_{x} x \cdot P(X=x)$.
4.  **Proprietà di Linearità**: Se $X = X_1 + X_2 + \dots + X_k$, allora $E[X] = E[X_1] + E[X_2] + \dots + E[X_k]$.

**Esempio (Valore Atteso)**: Per ogni studente si lanciano 6 dadi e gli si dà come voto la somma dei valori usciti. Quale voto ci si aspetta di ricevere?

1.  **Variabile Casuale**: Sia $X$ la somma dei risultati di 6 dadi. Sia $X_i$ il risultato del lancio del $i$-esimo dado.
2.  **Valore Atteso di un Singolo Dado**: Per un dado equo, $E[X_i] = (1+2+3+4+5+6)/6 = 3.5$.
3.  **Linearità del Valore Atteso**: $E[X] = E[X_1 + \dots + X_6] = E[X_1] + \dots + E[X_6] = 6 \times 3.5 = 21$.

**Errori Comuni da Evitare**:
*   Errori nel calcolo delle probabilità dei singoli eventi.
*   Dimenticare di applicare la proprietà di linearità quando possibile.

### 4. Teoria dei Grafi

#### 4.1 Planarità e Omeomorfismo (Teorema di Kuratowski)

**Obiettivo**: Dimostrare la non planarità di un grafo identificando un sottografo omeomorfo a $K_5$ o $K_{3,3}$.

**Schema Risolutivo**:

1.  **Comprendere il Teorema di Kuratowski**: Un grafo è non planare se e solo se contiene un sottografo che è omeomorfo a $K_5$ (il grafo completo con 5 vertici) o a $K_{3,3}$ (il grafo bipartito completo con 3 vertici in ciascun insieme della partizione).
2.  **Ricerca di $K_5$ o $K_{3,3}$**: Questo è il passo più difficile e richiede intuizione e pratica.
    *   **Per $K_5$**: Cercare 5 vertici in cui ogni coppia è connessa da un cammino (non necessariamente un arco diretto, ma un cammino che non passa per altri vertici già selezionati per $K_5$).
    *   **Per $K_{3,3}$**: Cercare due insiemi disgiunti di 3 vertici ciascuno ($V_1 = \{v_1, v_2, v_3\}$ e $V_2 = \{u_1, u_2, u_3\}$) tali che ogni vertice in $V_1$ è connesso a ogni vertice in $V_2$ tramite un cammino (senza passare per altri vertici di $V_1$ o $V_2$).
3.  **Rimuovere Vertici di Grado 2**: Per semplificare la ricerca di omeomorfismi, si possono rimuovere i vertici di grado 2 e sostituire l'arco $(u,w)$ e $(w,v)$ con un unico arco $(u,v)$. Questo non cambia la planarità del grafo.

**Trucchi e Consigli**:
*   Inizia cercando di semplificare il grafo eliminando vertici di grado 2 o archi multipli/cappio se presenti.
*   Disegna il grafo in modo chiaro per aiutarti a visualizzare le connessioni.
*   Per $K_{3,3}$, cerca vertici che sembrano formare due gruppi distinti con connessioni incrociate.
*   Per $K_5$, cerca un sottografo completo con 5 vertici.

**Errori Comuni da Evitare**:
*   Non identificare correttamente i vertici e gli archi che formano il sottografo omeomorfo.
*   Confondere $K_5$ con $K_{3,3}$.

#### 4.2 Verifica dell'Esistenza di Cicli/Cammini Euleriani o Hamiltoniani

**Obiettivo**: Determinare se un grafo possiede un circuito/cammino euleriano o hamiltoniano.

**Schema Risolutivo per Euleriani**:

1.  **Verificare la connessione**: Il grafo deve essere connesso.
2.  **Controllare i gradi dei vertici**:
    *   **Circuito Euleriano**: Esiste se e solo se *tutti* i vertici hanno grado pari.
    *   **Cammino Euleriano**: Esiste se e solo se ci sono *esattamente due* vertici con grado dispari (il cammino inizierà da uno e finirà nell'altro) o *nessun* vertice con grado dispari (nel qual caso è un circuito).

**Esempio (Euleriano)**: Un grafo con vertici A, B, C, D e archi (A,B), (B,C), (C,D), (D,A), (A,C).

1.  **Connessione**: Il grafo è connesso.
2.  **Gradi**: $\delta(A)=3$, $\delta(B)=2$, $\delta(C)=3$, $\delta(D)=2$.
3.  **Conclusione**: Ci sono esattamente due vertici con grado dispari (A e C). Quindi, esiste un cammino euleriano (es. B-A-C-D-A-C), ma non un circuito euleriano.

**Schema Risolutiva per Hamiltoniani**:

1.  **Verificare la connessione**: Il grafo deve essere connesso.
2.  **Criteri di esistenza (non sufficienti, ma utili per escludere)**:
    *   **Teorema di Dirac**: Se un grafo semplice con $n \ge 3$ vertici ha $\delta(v) \ge n/2$ per ogni vertice $v$, allora ha un ciclo hamiltoniano.
    *   **Teorema di Ore**: Se un grafo semplice con $n \ge 3$ vertici ha $\delta(u) + \delta(v) \ge n$ per ogni coppia di vertici non adiacenti $u, v$, allora ha un ciclo hamiltoniano.
    *   Se un grafo ha un vertice di grado 1, non può avere un ciclo hamiltoniano.
    *   Se la rimozione di $k$ vertici disconnette il grafo in più di $k$ componenti connesse, allora non ha un ciclo hamiltoniano.
3.  **Ricerca esaustiva o euristica (se i criteri non bastano)**: Per grafi piccoli, si può tentare di trovare un ciclo/cammino hamiltoniano per ispezione o enumerazione. Per grafi più grandi, il problema è NP-completo e richiede algoritmi più complessi o euristici.

**Esempio (Hamiltoniano)**: Un grafo completo $K_n$ con $n \ge 3$ ha sempre un ciclo hamiltoniano.

1.  **Connessione**: $K_n$ è connesso.
2.  **Criterio di Dirac**: Per $K_n$, ogni vertice ha grado $n-1$. Poiché $n-1 \ge n/2$ per $n \ge 2$, il Teorema di Dirac si applica per $n \ge 3$. Quindi, $K_n$ ha un ciclo hamiltoniano.

**Errori Comuni da Evitare**:
*   Confondere i criteri per Euleriani e Hamiltoniani.
*   Applicare i teoremi di Dirac o Ore come condizioni necessarie (sono solo sufficienti).
*   Non considerare la connessione del grafo.

#### 4.3 Proprietà degli Alberi

**Obiettivo**: Applicare le proprietà fondamentali degli alberi per risolvere problemi.

**Schema Risolutivo**:

1.  **Verificare la definizione di albero**: Un grafo è un albero se è connesso e aciclico.
2.  **Applicare le proprietà**: Se un grafo è un albero con $v$ vertici, allora ha $v-1$ archi.
3.  **Identificare foglie e vertici interni**: Le foglie hanno grado 1. I vertici interni hanno grado maggiore di 1.

**Esempio**: Un grafo connesso ha 10 vertici e 9 archi. È un albero?

1.  **Verificare la definizione**: Il grafo è connesso. Ha $v=10$ vertici e $e=9$ archi. Poiché $e = v-1$, il grafo è aciclico. (Un grafo connesso con $v$ vertici e $v-1$ archi è sempre un albero).
2.  **Conclusione**: Sì, è un albero.

**Errori Comuni da Evitare**:
*   Dimenticare la condizione di connessione o aciclicità.
*   Non applicare correttamente la relazione $e = v-1$.

---

## Analisi Chirurgica degli Esami Passati: Seconda Parte di Strutture Discrete

Questa sezione analizza i quesiti della Seconda Parte degli appelli passati, classificandoli per tipologia e indicando la strategia migliore per affrontarli e risolverli correttamente. Faremo riferimento agli appunti teorici e agli schemi risolutivi precedentemente forniti.

### 1. Tipologie di Quesiti e Strategie Risolutive

#### 1.1 Aritmetica Modulare: Calcolo di Potenze Modulo $n$

**Tipologia di Quesito**: Calcolare $a^b \pmod{n}$ per valori grandi di $b$ e $n$.

**Esempi dagli Esami**:
*   `Calcolare 15^15 mod 13.` (Esame 24 Febbraio 2026 - TEST A, Quesito 3)
*   `Calcolare 17^13 mod 15.` (Esame 24 Febbraio 2026 - TEST B, Quesito 3)
*   `Verificare che 11^13 mod 17 = 17^13 mod 11` (Esame 10 Dicembre 2021, Quesito 3)

**Strategia Risolutiva**:

1.  **Semplificazione della Base**: Il primo passo è sempre ridurre la base $a$ modulo $n$. Se $a \ge n$, sostituire $a$ con $a \pmod{n}$. Questo rende il numero più piccolo e più facile da gestire. Ad esempio, per $15^{15} \pmod{13}$, si ha $15 \equiv 2 \pmod{13}$, quindi il problema diventa $2^{15} \pmod{13}$.
2.  **Applicazione del Teorema di Eulero**: Questo è il metodo più efficiente quando $\text{MCD}(base, modulo) = 1$.
    *   Calcolare la funzione totiente di Eulero $\phi(n)$. Se $n$ è primo, $\phi(n) = n-1$. Se $n = p_1^{k_1} \dots p_r^{k_r}$, usare la formula $\phi(n) = n \prod (1 - 1/p_i)$.
    *   L'esponente $b$ può essere ridotto modulo $\phi(n)$. Quindi, $a^b \equiv a^{(b \pmod{\phi(n)})} \pmod{n}$. Attenzione: se $b \pmod{\phi(n)} = 0$, l'esponente effettivo da usare è $\phi(n)$ (a meno che $b=0$, nel qual caso $a^0=1$).
    *   Eseguire il calcolo con l'esponente ridotto.
3.  **Calcolo Iterativo (per esponenti piccoli o quando Eulero non si applica)**: Se il Teorema di Eulero non è applicabile (cioè $\text{MCD}(base, modulo) \ne 1$) o se l'esponente ridotto è ancora gestibile, si possono calcolare le potenze in modo iterativo, riducendo il risultato modulo $n$ ad ogni passaggio per evitare numeri troppo grandi. Ad esempio, $a^k \pmod{n} = (a^{k-1} \pmod{n} \cdot a) \pmod{n}$.

**Trucchi e Consigli**:
*   Ricorda che $x \equiv -1 \pmod{n}$ è molto utile, perché $(-1)^k$ è facile da calcolare.
*   Se $n$ è un numero primo, puoi usare il Piccolo Teorema di Fermat: $a^{n-1} \equiv 1 \pmod{n}$ per $a$ non multiplo di $n$.

**Errori Comuni da Evitare**:
*   Dimenticare di verificare la condizione $\text{MCD}(a, n) = 1$ prima di applicare il Teorema di Eulero.
*   Errori nel calcolo di $\phi(n)$.
*   Usare $0$ come esponente ridotto quando $b \pmod{\phi(n)} = 0$; in questo caso, l'esponente è $\phi(n)$.

#### 1.2 Principio di Induzione

**Tipologia di Quesito**: Dimostrare una proprietà $P(n)$ per tutti i numeri naturali $n \ge n_0$.

**Esempi dagli Esami**:
*   `Definire e dimostrare il Principio di Induzione.` (Esame 24 Febbraio 2026 - TEST A, Quesito 4)
*   `Dimostrare per induzione che dato un insieme finito A la cardinalità del suo insieme potenza pow(A) è uguale a 2^|A|.` (Esame 24 Febbraio 2026 - TEST B, Quesito 4)
*   `Dimostrare per induzione su n che la somma dei primi n numeri dispari è uguale a n^2.` (Esame 12 Aprile 2022 - Versione A, Quesito 3)

**Strategia Risolutiva**:

1.  **Identificare $P(n)$ e $n_0$**: Definire chiaramente la proprietà $P(n)$ da dimostrare e il valore iniziale $n_0$ per cui la proprietà deve valere.
2.  **Passo Base**: Dimostrare che $P(n_0)$ è vera. Questo è un controllo diretto, sostituendo $n_0$ nella proprietà e verificando l'uguaglianza o l'affermazione.
3.  **Passo Induttivo**: Questo è il cuore della dimostrazione.
    *   **Ipotesi Induttiva**: Assumere che $P(k)$ sia vera per un generico $k \ge n_0$. Scrivere esplicitamente questa assunzione.
    *   **Tesi Induttiva**: Dimostrare che $P(k+1)$ è vera, utilizzando l'ipotesi induttiva. Spesso si manipola un lato dell'espressione per $P(k+1)$ fino a quando non si può applicare l'ipotesi induttiva per trasformarlo nell'altro lato.
4.  **Conclusione**: Affermare che, per il Principio di Induzione, la proprietà $P(n)$ è vera per tutti i $n \ge n_0$.

**Trucchi e Consigli**:
*   Il passo base è fondamentale: se è sbagliato, tutta la dimostrazione crolla.
*   Nel passo induttivo, cerca sempre di collegare il lato sinistro di $P(k+1)$ all'ipotesi induttiva $P(k)$.
*   Presta attenzione ai dettagli algebrici; un piccolo errore può invalidare l'intera dimostrazione.

#### 1.3 Principio dei Cassetti (Pigeonhole Principle)

**Tipologia di Quesito**: Applicare il Principio dei Cassetti per dimostrare l'esistenza di una certa condizione.

**Esempi dagli Esami**:
*   `Dei 141 studenti prenotati per l’esame di oggi, supponendo che siano tutti siciliani, quanti possiamo dire con certezza che provengono dalla stessa provincia?` (Esame 24 Febbraio 2026 - TEST A, Quesito 5)
*   `Dei 141 studenti prenotati per l’esame di Strutture Discrete, quanti studenti, sappiamo con certezza, otterranno lo stesso voto?` (Esame 24 Febbraio 2026 - TEST B, Quesito 6)

**Strategia Risolutiva**:

1.  **Identificare Oggetti e Cassetti**: Il primo passo è capire cosa rappresentano gli oggetti e cosa i cassetti nel contesto del problema. Gli *oggetti* sono gli elementi che vengono distribuiti, e i *cassetti* sono le categorie in cui vengono distribuiti.
2.  **Applicare il Principio**: Se il numero di oggetti ($n$) è maggiore del numero di cassetti ($m$), allora almeno un cassetto deve contenere più di un oggetto. Nella versione generalizzata, almeno un cassetto conterrà $\lceil n/m \rceil$ oggetti.
3.  **Formulare la Conclusione**: Tradurre il risultato matematico in una risposta chiara e concisa che risolva il quesito originale.

**Trucchi e Consigli**:
*   Sii creativo nell'identificare oggetti e cassetti. A volte non sono immediatamente ovvi.
*   Ricorda la funzione soffitto $\lceil x \rceil$ per la versione generalizzata del principio.

**Errori Comuni da Evitare**:
*   Confondere oggetti e cassetti.
*   Errori nel calcolo della funzione soffitto.

#### 1.4 Probabilità Discreta: Valore Atteso

**Tipologia di Quesito**: Calcolare il valore atteso di una variabile casuale discreta.

**Esempi dagli Esami**:
*   `Invece di correggere 141 esami, il professore decide di procedere in questo modo: per ogni studente lancia 6 dadi e gli dà, come voto, la somma dei valori usciti. Dato questo criterio, quale voto vi aspettate di ricevere ?` (Esame 24 Febbraio 2026 - TEST A, Quesito 6)

**Strategia Risolutiva**:

1.  **Identificare la Variabile Casuale**: Definire la variabile casuale $X$ di cui si vuole calcolare il valore atteso.
2.  **Determinare i Possibili Valori e le Loro Probabilità**: Elencare tutti i possibili valori che la variabile casuale può assumere e le probabilità associate a ciascun valore, $P(X=x)$.
3.  **Applicare la Formula del Valore Atteso**: $E[X] = \sum_{x} x \cdot P(X=x)$.
4.  **Proprietà di Linearità del Valore Atteso**: Se la variabile casuale è la somma di più variabili casuali (es. somma dei risultati di più dadi), si può usare la proprietà di linearità: $E[X_1 + X_2 + \dots + X_k] = E[X_1] + E[X_2] + \dots + E[X_k]$. Questo semplifica notevolmente i calcoli.

**Trucchi e Consigli**:
*   Per problemi con dadi, monete o estrazioni semplici, le probabilità sono spesso uniformi o facilmente calcolabili.
*   La linearità del valore atteso è una proprietà molto potente che funziona anche se le variabili casuali non sono indipendenti.

**Errori Comuni da Evitare**:
*   Errori nel calcolo delle probabilità dei singoli eventi.
*   Dimenticare di applicare la proprietà di linearità quando possibile, rendendo i calcoli più complessi del necessario.

#### 1.5 Applicazioni dell'Aritmetica Modulare (Codici ISBN, Carte di Credito, Cifrari)

**Tipologia di Quesito**: Verificare la validità di codici (es. ISBN) o comprendere i principi di base dei cifrari monoalfabetici. Questi quesiti possono richiedere l'applicazione diretta dell'aritmetica modulare o la comprensione dei concetti sottostanti.

**Esempi dagli Esami**: Negli esami forniti non sono presenti quesiti diretti su Codici ISBN, Carte di Credito o Cifrari monoalfabetici. Tuttavia, data la loro menzione nelle slide, è probabile che possano essere oggetto di domande teoriche o di semplici esercizi applicativi.

**Strategia Risolutiva**:

1.  **Codici ISBN**: Per l'ISBN-10, ricordare la formula della somma ponderata modulo 11. Per l'ISBN-13, la logica è simile ma con un modulo diverso (10) e pesi alternati (1 e 3).
2.  **Carte di Credito**: Comprendere che si basano su algoritmi di checksum (come l'algoritmo di Luhn) per la verifica, non per la crittografia.
3.  **Cifrari Monoalfabetici**: Capire come funzionano le operazioni di cifratura e decifratura usando l'aritmetica modulare (es. cifrario di Cesare: $y \equiv (x+k) \pmod{26}$ per cifrare, $x \equiv (y-k) \pmod{26}$ per decifrare).

**Trucchi e Consigli**:
*   Memorizzare le formule di verifica per i codici (ISBN) e le operazioni di cifratura/decifratura.
*   Esercitarsi con piccoli esempi per familiarizzare con i calcoli.

**Errori Comuni da Evitare**:
*   Errori di calcolo modulare.
*   Confondere i principi di verifica con quelli di crittografia.

#### 1.6 Teoria dei Numeri e Problemi Aperti (Mersenne, Perfetti, Gemelli, Goldbach, Collatz)

**Tipologia di Quesito**: Domande di definizione, comprensione concettuale o brevi discussioni su questi problemi aperti della teoria dei numeri.

**Esempi dagli Esami**: Negli esami forniti non sono presenti quesiti diretti su questi argomenti. Tuttavia, la loro presenza nel programma suggerisce che potrebbero essere oggetto di domande teoriche.

**Strategia Risolutiva**:

1.  **Definizioni**: Conoscere le definizioni precise di numeri primi di Mersenne, numeri perfetti, numeri primi gemelli, congettura di Goldbach e congettura di Collatz.
2.  **Stato del Problema**: Essere consapevoli che si tratta di problemi aperti (non ancora dimostrati o risolti).
3.  **Esempi**: Essere in grado di fornire un piccolo esempio per ciascun concetto (es. 6 è un numero perfetto).

**Trucchi e Consigli**:
*   Non è richiesta la dimostrazione di queste congetture, ma la loro comprensione e definizione.

**Errori Comuni da Evitare**:
*   Confondere le definizioni tra i vari tipi di numeri o congetture.

#### 1.7 Teoria dei Grafi: Planarità e Omeomorfismo

**Tipologia di Quesito**: Dimostrare la non planarità di un grafo identificando un sottografo omeomorfo a $K_5$ o $K_{3,3}$.

**Esempi dagli Esami**:
*   `Dato il grafo in figura, dimostrare che il grafo non è planare identificando un suo sottogrofo omeomorfo a K3,3 .` (Esame 10 Dicembre 2021, Quesito 7)
*   `Dato il grafo in figura, aggiungete un numero minimo di archi sufficiente per renderlo non planare.` (Esame 24 Febbraio 2026 - TEST B, Quesito 8)

**Strategia Risolutiva**:

1.  **Comprendere il Teorema di Kuratowski**: Un grafo è non planare se e solo se contiene un sottografo omeomorfo a $K_5$ o $K_{3,3}$.
2.  **Ricerca di $K_5$ o $K_{3,3}$**: Questo è il passo più difficile e richiede intuizione e pratica.
    *   **Per $K_5$**: Cercare 5 vertici in cui ogni coppia è connessa da un cammino (non necessariamente un arco diretto, ma un cammino che non passa per altri vertici già selezionati per $K_5$).
    *   **Per $K_{3,3}$**: Cercare due insiemi disgiunti di 3 vertici ciascuno ($V_1 = \{v_1, v_2, v_3\}$ e $V_2 = \{u_1, u_2, u_3\}$) tali che ogni vertice in $V_1$ è connesso a ogni vertice in $V_2$ tramite un cammino (senza passare per altri vertici di $V_1$ o $V_2$).
3.  **Rimuovere Vertici di Grado 2**: Per semplificare la ricerca di omeomorfismi, si possono rimuovere i vertici di grado 2 e sostituire l'arco $(u,w)$ e $(w,v)$ con un unico arco $(u,v)$. Questo non cambia la planarità del grafo.

**Trucchi e Consigli**:
*   Inizia cercando di semplificare il grafo eliminando vertici di grado 2 o archi multipli/cappio se presenti.
*   Disegna il grafo in modo chiaro per aiutarti a visualizzare le connessioni.
*   Per $K_{3,3}$, cerca vertici che sembrano formare due gruppi distinti con connessioni incrociate.
*   Per $K_5$, cerca un sottografo completo con 5 vertici.

**Errori Comuni da Evitare**:
*   Non identificare correttamente i vertici e gli archi che formano il sottografo omeomorfo.
*   Confondere $K_5$ con $K_{3,3}$.

#### 1.8 Calcolo Combinatorio: Funzioni Iniettive e Conteggio

**Tipologia di Quesito**: Calcolare il numero di funzioni iniettive tra due insiemi o risolvere problemi di conteggio che richiedono l'uso di disposizioni.

**Esempi dagli Esami**:
*   `Se A è un insieme di 4 elementi e B è un insieme di 10 elementi, quante sono le funzioni iniettive da A a B?` (Esame 12 Aprile 2022 - Versione A, Quesito 5)

**Strategia Risolutiva**:

1.  **Comprendere la Definizione di Funzione Iniettiva**: Una funzione $f: A \to B$ è iniettiva se elementi distinti di $A$ sono mappati a elementi distinti di $B$. Questo significa che ogni elemento di $A$ deve scegliere un elemento di $B$ diverso da quelli già scelti dagli altri elementi di $A$.
2.  **Tradurre in Termini Combinatori**: Il problema di contare le funzioni iniettive da un insieme $A$ con $|A|=k$ elementi a un insieme $B$ con $|B|=n$ elementi è equivalente a scegliere $k$ elementi distinti da $n$ e ordinarli. Questo è esattamente il concetto di **disposizioni semplici** di $n$ oggetti presi $k$ alla volta.
3.  **Applicare la Formula**: Il numero di funzioni iniettive è $P(n, k) = \frac{n!}{(n-k)!}$.

**Trucchi e Consigli**:
*   Assicurati che $|A| \le |B|$, altrimenti non possono esistere funzioni iniettive.
*   Ricorda che l'ordine conta in questo tipo di problemi (quale elemento di $A$ va a quale elemento di $B$).

**Errori Comuni da Evitare**:
*   Confondere le disposizioni con le combinazioni (dove l'ordine non conta).
*   Errori nel calcolo dei fattoriali.

#### 1.9 Probabilità Discreta: Problemi d'Urna e Coprimi

**Tipologia di Quesito**: Calcolare probabilità in contesti di estrazione da urne o con condizioni sui numeri (es. coprimi).

**Esempi dagli Esami**:
*   `In un’urna ci sono 9 palline colorate: 2 rosse, 3 verdi e 4 bianche. Se estraiamo 3 palline senza reinserimento, qual è la probabilità di poter formare la bandiera italiana, ovvero di estrarre 1 pallina per ognuno dei 3 colori?` (Esame 10 Dicembre 2021, Quesito 5)
*   `In un’urna ci sono 9 palline numerate da 1 a 9. Estraendo 2 palline, senza reintroduzione, qual è la probabilità di estrarre 2 numeri coprimi tra di loro?` (Esame 12 Aprile 2022 - Versione A, Quesito 6)

**Strategia Risolutiva**:

1.  **Identificare lo Spazio Campionario**: Calcolare il numero totale di risultati possibili. Questo spesso coinvolge combinazioni o disposizioni.
    *   Per estrazioni senza reinserimento e senza ordine, usare le combinazioni semplici $\binom{N}{K}$.
    *   Per estrazioni senza reinserimento e con ordine, usare le disposizioni semplici $P(N, K)$.
2.  **Identificare gli Eventi Favorevoli**: Calcolare il numero di risultati che soddisfano la condizione richiesta.
    *   Per il problema della bandiera italiana: scegliere 1 rossa da 2, 1 verde da 3, 1 bianca da 4. Moltiplicare i risultati.
    *   Per il problema dei numeri coprimi: elencare tutte le coppie di numeri coprimi tra 1 e 9, o usare la funzione $\phi$ di Eulero per contare i coprimi con ogni numero.
3.  **Calcolare la Probabilità**: Dividere il numero di eventi favorevoli per il numero totale di risultati possibili.

**Trucchi e Consigli**:
*   Presta molta attenzione se l'ordine conta o meno e se c'è reinserimento o meno. Questo determina la formula combinatoria da usare.
*   Per i numeri coprimi, la funzione $\phi(n)$ è molto utile per contare i numeri coprimi con $n$.

**Errori Comuni da Evitare**:
*   Errori nel calcolo dello spazio campionario o degli eventi favorevoli.
*   Confondere le formule di combinatoria.

#### 1.10 Teoria dei Grafi: Grafi Euleriani e Hamiltoniani

**Tipologia di Quesito**: Determinare se un grafo possiede un ciclo/cammino euleriano o hamiltoniano.

**Esempi dagli Esami**:
*   `Il grafo in figura possiede un ciclo euleriano o un cammino euleriano? Possiede un cammino hamiltoniano?` (Esame 10 Dicembre 2021, Quesito 8)

**Strategia Risolutiva**:

1.  **Per Cicli/Cammini Euleriani**:
    *   **Connessione**: Il grafo deve essere connesso.
    *   **Gradi dei Vertici**: Un grafo connesso ha un circuito euleriano se e solo se tutti i vertici hanno grado pari. Ha un cammino euleriano se e solo se ha esattamente due vertici di grado dispari (il cammino inizia e finisce in questi vertici).
2.  **Per Cicli/Cammini Hamiltoniani**:
    *   **Criteri di Esistenza (sufficienti, non necessari)**: Utilizzare teoremi come quello di Dirac ($\delta(v) \ge n/2$) o Ore ($\delta(u) + \delta(v) \ge n$) per *dimostrare l'esistenza*. Se questi non sono soddisfatti, non significa che non esista un ciclo hamiltoniano, ma solo che questi teoremi non lo garantiscono.
    *   **Criteri di Non Esistenza**: Se la rimozione di $k$ vertici disconnette il grafo in più di $k$ componenti connesse, non esiste un ciclo hamiltoniano. Se c'è un vertice di grado 1, non può esserci un ciclo hamiltoniano.
    *   **Ispezione/Ricerca**: Per grafi piccoli, si può tentare di trovare un ciclo/cammino hamiltoniano per ispezione visiva o enumerazione.

**Trucchi e Consigli**:
*   Disegna il grafo e calcola i gradi di tutti i vertici per i problemi euleriani.
*   Per i problemi hamiltoniani, cerca di eliminare vertici o archi che renderebbero impossibile un ciclo/cammino.

**Errori Comuni da Evitare**:
*   Confondere i criteri per Euleriani e Hamiltoniani.
*   Applicare i teoremi di Dirac o Ore come condizioni necessarie (sono solo sufficienti).

#### 1.11 Teoria dei Grafi: Proprietà degli Alberi

**Tipologia di Quesito**: Applicare le proprietà fondamentali degli alberi per risolvere problemi o dimostrare affermazioni.

**Esempi dagli Esami**:
*   `Dato un grafo connesso e aciclico, dimostrare che il numero dei sui archi è uguale al numero dei vertici meno 1.` (Esame 24 Febbraio 2026 - TEST B, Quesito 7)
*   `Dare la definizione di Albero Libero e di Albero Libero Radicato.` (Esame 12 Aprile 2022 - Versione A, Quesito 7)

**Strategia Risolutiva**:

1.  **Definizione di Albero**: Un albero è un grafo connesso e aciclico.
2.  **Proprietà Fondamentale**: Se un albero ha $v$ vertici, allora ha esattamente $v-1$ archi. Questa è una proprietà chiave da usare nelle dimostrazioni.
3.  **Definizioni**: Conoscere le definizioni di albero libero, albero radicato, radice, foglie, vertici interni, altezza, ecc.

**Trucchi e Consigli**:
*   Per dimostrazioni, spesso si può usare l'induzione sul numero di vertici.
*   Ricorda che la rimozione di un arco da un albero lo disconnette in due componenti connesse.

**Errori Comuni da Evitare**:
*   Dimenticare una delle due condizioni (connesso o aciclico) nella definizione di albero.
*   Errori nell'applicazione della relazione $e = v-1$.

#### 1.12 Teoria dei Grafi: Grafi Planari Massimali

**Tipologia di Quesito**: Calcolare il numero di archi o facce in un grafo planare massimale.

**Esempi dagli Esami**:
*   `Dato il grafo planare in figura, quanti archi dobbiamo aggiungere per renderlo massimale? E quante sono le facce sul piano in tal caso?` (Esame 12 Aprile 2022 - Versione A, Quesito 8)

**Strategia Risolutiva**:

1.  **Definizione di Grafo Planare Massimale**: Un grafo planare è massimale se non è possibile aggiungere altri archi senza perdere la planarità.
2.  **Formule per Grafi Planari Massimali**: Per un grafo planare massimale con $v$ vertici e $v \ge 3$:
    *   Numero di archi: $e = 3v - 6$.
    *   Numero di facce: $f = 2v - 4$.
3.  **Calcolo**: Usare le formule per determinare il numero di archi o facce richieste.

**Trucchi e Consigli**:
*   Queste formule sono valide solo per grafi planari massimali e connessi con $v \ge 3$.

**Errori Comuni da Evitare**:
*   Applicare le formule a grafi non planari o non massimali.
*   Errori di calcolo.

