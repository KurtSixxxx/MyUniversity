# Aritmetica Modulare: Lezioni Approfondite

Questo documento raccoglie e organizza le trascrizioni di tre lezioni sull'aritmetica modulare, con l'obiettivo di fornire una trattazione chiara e strutturata dell'argomento, inclusa la formalizzazione delle espressioni matematiche in formato LaTeX.

## Lezione 1: Introduzione all'Aritmetica Modulare e Proprietà delle Congruenze

### Introduzione al Problema delle Congruenze
L'aritmetica modulare introduce il concetto di **congruenza**, una relazione che estende l'idea di uguaglianza tra numeri interi. Spesso si incontrano problemi che richiedono di determinare il resto di una divisione o di risolvere sistemi di congruenze, come ad esempio $2x \equiv 5 \pmod 3$ o $3x \equiv 10 \pmod 2$. Un quesito comune è anche la determinazione del resto di divisioni complesse, come $2^{16} \div 9$.

La base di tutto è comprendere il significato di una scrittura come $9 \equiv 7 \pmod 2$. Questa relazione è vera se, dividendo entrambi i numeri per il modulo (in questo caso 2), si ottiene lo stesso resto. L'aritmetica modulare considera equivalenti due interi relativi che hanno lo stesso resto rispetto a un divisore comune.

### Numeri Coprimi
Due numeri interi relativi $a$ e $b$ sono detti **coprimi** (o relativamente primi) se il loro massimo comune divisore (MCD) è uguale a 1. Ad esempio, $+7$ e $+5$ sono coprimi, poiché $\text{MCD}(7, 5) = 1$. Invece, $9$ e $6$ non sono coprimi, dato che $\text{MCD}(9, 6) = 3 \neq 1$.

### Divisione tra Interi Relativi
La divisione tra due numeri interi relativi $n$ (dividendo) e $m$ (divisore, con $m \neq 0$) consiste nel determinare un unico numero intero relativo $q$ (quoziente) e un numero relativo $r$ (resto) tali che:

$$n = q \cdot m + r$$

con la condizione fondamentale che il resto $r$ deve essere maggiore o uguale a 0 e strettamente minore del valore assoluto di $m$: $0 \le r < |m|$.

**Esempi di Divisione:**

| Dividendo ($n$) | Divisore ($m$) | Quoziente ($q$) | Resto ($r$) | Verifica ($q \cdot m + r = n$) |
|---|---|---|---|---|
| $+15$ | $+7$ | $+2$ | $+1$ | $2 \cdot 7 + 1 = 15$ |
| $-15$ | $+7$ | $-3$ | $+6$ | $-3 \cdot 7 + 6 = -21 + 6 = -15$ |
| $+15$ | $-7$ | $-2$ | $+1$ | $-2 \cdot (-7) + 1 = 14 + 1 = 15$ |
| $-15$ | $-7$ | $+3$ | $+6$ | $3 \cdot (-7) + 6 = -21 + 6 = -15$ |

### Relazione di Congruenza Modulo $m$
Siano $a$ e $b$ due numeri interi relativi e $m$ un numero intero positivo. La scrittura:

$$a \equiv b \pmod m$$

si legge "$a$ è congruo a $b$ modulo $m$". Questa relazione è vera se, eseguendo la divisione di $a$ per $m$ e di $b$ per $m$, si ottiene lo stesso resto. Un modo più comodo per verificarlo è che la differenza $a - b$ sia un multiplo di $m$. Ovvero, deve esistere un numero intero relativo $k$ tale che:

$$a - b = k \cdot m$$

Se non esiste un tale $k$, allora $a$ non è congruo a $b$ modulo $m$.

**Esempi:**
*   $11 \equiv 7 \pmod 4$: Vera, perché $11 - 7 = 4$, e $4 = 1 \cdot 4$ (con $k=1$). Inoltre, $11 \div 4$ ha resto $3$, e $7 \div 4$ ha resto $3$.
*   $-15 \equiv 1 \pmod 8$: Vera, perché $-15 - 1 = -16$, e $-16 = -2 \cdot 8$ (con $k=-2$).
*   $5 \equiv 3 \pmod 5$: Falsa, perché $5 - 3 = 2$, e $2$ non è un multiplo di $5$ (non esiste un $k$ intero tale che $2 = k \cdot 5$).

### Relazione di Equivalenza
La relazione di congruenza modulo $m$ è una **relazione di equivalenza** nell'insieme degli interi $\mathbb{Z}$, poiché soddisfa le seguenti tre proprietà:

1.  **Proprietà Riflessiva:** $a \equiv a \pmod m$
    *   Dimostrazione: $a - a = 0$. Poiché $0 = k \cdot m$ (con $k=0$), $0$ è un multiplo di qualsiasi intero $m$. Quindi, $a \equiv a \pmod m$ è sempre vera.

2.  **Proprietà Simmetrica:** Se $a \equiv b \pmod m$, allora $b \equiv a \pmod m$.
    *   Dimostrazione: Se $a \equiv b \pmod m$, allora $a - b = k \cdot m$ per qualche intero $k$. Moltiplicando entrambi i membri per $-1$, otteniamo $-(a - b) = -(k \cdot m)$, ovvero $b - a = (-k) \cdot m$. Poiché $-k$ è anch'esso un intero, $b - a$ è un multiplo di $m$, quindi $b \equiv a \pmod m$.

3.  **Proprietà Transitiva:** Se $a \equiv b \pmod m$ e $b \equiv c \pmod m$, allora $a \equiv c \pmod m$.
    *   Dimostrazione: Se $a \equiv b \pmod m$, allora $a - b = k_1 \cdot m$. Se $b \equiv c \pmod m$, allora $b - c = k_2 \cdot m$. Sommando membro a membro le due equazioni, otteniamo $(a - b) + (b - c) = k_1 \cdot m + k_2 \cdot m$. Semplificando, $a - c = (k_1 + k_2) \cdot m$. Poiché $k_1 + k_2$ è un intero, $a - c$ è un multiplo di $m$, quindi $a \equiv c \pmod m$.

Essendo una relazione di equivalenza, la congruenza modulo $m$ partiziona l'insieme $\mathbb{Z}$ in **classi di equivalenza** (o classi di resto).

### Classi di Equivalenza (Congruenza Modulo $m$)

*   **Congruenza Modulo 1:** $a \equiv b \pmod 1$
    *   Significa che $a - b = k \cdot 1$. Qualsiasi differenza tra interi è un multiplo di 1. Inoltre, la divisione di qualsiasi intero per 1 ha sempre resto 0. Pertanto, esiste una sola classe di equivalenza, che è l'intero insieme $\mathbb{Z}$. La classe di resto è $[0]_1$.

*   **Congruenza Modulo 2:** $a \equiv b \pmod 2$
    *   Significa che $a - b = k \cdot 2$, ovvero la differenza tra $a$ e $b$ è un numero pari. Questo implica che $a$ e $b$ devono avere la stessa parità. L'insieme $\mathbb{Z}$ viene suddiviso in due classi di equivalenza:
        *   La classe dei numeri pari: $[0]_2$ (resto 0 quando divisi per 2).
        *   La classe dei numeri dispari: $[1]_2$ (resto 1 quando divisi per 2).
    *   Esempi: $2 \equiv 4 \pmod 2$ (entrambi hanno resto 0); $9 \equiv 5 \pmod 2$ (entrambi hanno resto 1).

In generale, per un modulo $m$, l'insieme $\mathbb{Z}$ viene suddiviso in $m$ classi di equivalenza (o classi di resto): $[0]_m, [1]_m, [2]_m, \dots, [m-1]_m$.

### Invarianza Rispetto a Somma e Prodotto

Se $a \equiv b \pmod m$ e $c \equiv d \pmod m$, allora valgono le seguenti proprietà:

1.  **Somma:** $a + c \equiv b + d \pmod m$
2.  **Prodotto:** $a \cdot c \equiv b \cdot d \pmod m$
3.  **Potenza:** $a^n \equiv b^n \pmod m$ per ogni intero positivo $n$.

Inoltre, si definisce $a \pmod m$ come il resto della divisione di $a$ per $m$. Ad esempio, $7 \pmod 2 = 1$.

Altre relazioni importanti (con il simbolo di uguaglianza, non congruenza):

*   $(a + b) \pmod m = ((a \pmod m) + (b \pmod m)) \pmod m$
*   $(a \cdot b) \pmod m = ((a \pmod m) \cdot (b \pmod m)) \pmod m$
*   $a^n \pmod m = ((a \pmod m)^n) \pmod m$

### Proprietà del Prodotto e Cancellazione

Se $a \equiv b \pmod m$, allora $a \cdot c \equiv b \cdot c \pmod m$. Tuttavia, la **cancellazione** di $c$ (ovvero, passare da $a \cdot c \equiv b \cdot c \pmod m$ a $a \equiv b \pmod m$) non è sempre lecita. È possibile cancellare $c$ se e solo se $\text{MCD}(c, m) = 1$ (cioè, $c$ e $m$ sono coprimi).

**Esempi di Cancellazione:**

*   **Cancellazione non consentita:** Consideriamo $6 \equiv 2 \pmod 4$. È vera, perché $6-2=4$, multiplo di 4. Possiamo scrivere $3 \cdot 2 \equiv 1 \cdot 2 \pmod 4$. Se cancellassimo il $2$, otterremmo $3 \equiv 1 \pmod 4$, che è falsa ($3-1=2$, non multiplo di 4). In questo caso, $\text{MCD}(2, 4) = 2 \neq 1$.

*   **Cancellazione consentita:** Consideriamo $15 \equiv 3 \pmod 4$. È vera, perché $15-3=12$, multiplo di 4. Possiamo scrivere $5 \cdot 3 \equiv 1 \cdot 3 \pmod 4$. Se cancellassimo il $3$, otterremmo $5 \equiv 1 \pmod 4$, che è vera ($5-1=4$, multiplo di 4). In questo caso, $\text{MCD}(3, 4) = 1$.

### Esercizi

1.  **Determinare il resto di $69 \div 7$ usando le congruenze.**
    *   Sappiamo che $69 = 9 \cdot 7 + 6$, quindi il resto è $6$.
    *   Applicando le proprietà: $69 \pmod 7 = (63 + 6) \pmod 7 = ((63 \pmod 7) + (6 \pmod 7)) \pmod 7 = (0 + 6) \pmod 7 = 6 \pmod 7 = 6$.

2.  **Determinare il resto di $66^{127} \div 5$.**
    *   Vogliamo calcolare $66^{127} \pmod 5$.
    *   Prima, riduciamo la base: $66 \pmod 5 = 1$ (poiché $66 = 13 \cdot 5 + 1$).
    *   Quindi, $66^{127} \equiv 1^{127} \pmod 5$.
    *   $1^{127} = 1$.
    *   Pertanto, $66^{127} \equiv 1 \pmod 5$. Il resto è $1$.

3.  **Determinare il resto di $19^{501} \div 20$.**
    *   Vogliamo calcolare $19^{501} \pmod 20$.
    *   Osserviamo che $19 \equiv -1 \pmod {20}$ (poiché $19 - (-1) = 20$, multiplo di 20).
    *   Quindi, $19^{501} \equiv (-1)^{501} \pmod {20}$.
    *   Poiché $501$ è dispari, $(-1)^{501} = -1$.
    *   Quindi, $19^{501} \equiv -1 \pmod {20}$.
    *   Per ottenere un resto positivo e nel range $0 \le r < 20$, aggiungiamo il modulo: $-1 + 20 = 19$.
    *   Pertanto, $19^{501} \equiv 19 \pmod {20}$. Il resto è $19$.

## Lezione 2: Funzione di Eulero e Teoremi di Eulero e Fermat

### Introduzione alla Funzione di Eulero (Totient di Eulero, $\phi(n)$)

La **funzione di Eulero** (o funzione totiente di Eulero), indicata con $\phi(n)$, per un numero intero positivo $n$, rappresenta il numero di interi positivi minori o uguali a $n$ che sono coprimi con $n$. In altre parole, $\phi(n)$ è il conteggio degli interi $x$ tali che $1 \le x \le n$ e $\text{MCD}(x, n) = 1$.

**Esempi di Calcolo di $\phi(n)$:**

| $n$ | Interi $x$ con $\text{MCD}(x, n) = 1$ e $1 \le x \le n$ | $\phi(n)$ |
|---|---|---|
| $1$ | $1$ | $1$ |
| $2$ | $1$ | $1$ |
| $3$ | $1, 2$ | $2$ |
| $4$ | $1, 3$ | $2$ |
| $5$ | $1, 2, 3, 4$ | $4$ |
| $6$ | $1, 5$ | $2$ |

### Casi Particolari per $\phi(n)$

1.  **Se $n$ è un numero primo ($P$):**
    *   Se $n$ è un numero primo, tutti gli interi positivi minori di $n$ sono coprimi con $n$. Quindi, $\phi(n) = n - 1$.
    *   Esempi: $\phi(37) = 37 - 1 = 36$; $\phi(41) = 41 - 1 = 40$.

2.  **Se $n$ è una potenza di un numero primo ($P^h$):**
    *   Se $n = P^h$ (con $P$ primo e $h \ge 1$), allora $\phi(n) = P^h - P^{h-1}$.
    *   Questa formula si ottiene sottraendo da $P^h$ tutti i multipli di $P$ minori o uguali a $P^h$, che sono $P^{h-1}$ in numero.
    *   Esempio: $\phi(8) = \phi(2^3) = 2^3 - 2^{3-1} = 8 - 2^2 = 8 - 4 = 4$. (Gli interi coprimi con 8 sono 1, 3, 5, 7).
    *   Esempio: $\phi(125) = \phi(5^3) = 5^3 - 5^{3-1} = 125 - 25 = 100$.

3.  **Se $n$ è il prodotto di due numeri primi distinti ($P_1 \cdot P_2$):**
    *   Se $n = P_1 \cdot P_2$ (con $P_1, P_2$ primi distinti), allora $\phi(n) = (P_1 - 1) \cdot (P_2 - 1)$.
    *   Esempio: $\phi(10) = \phi(2 \cdot 5) = (2 - 1) \cdot (5 - 1) = 1 \cdot 4 = 4$. (Gli interi coprimi con 10 sono 1, 3, 7, 9).

4.  **Se $n$ è il prodotto di due numeri coprimi ($A \cdot B$):**
    *   Se $n = A \cdot B$ e $\text{MCD}(A, B) = 1$, allora $\phi(n) = \phi(A) \cdot \phi(B)$. Questa è la proprietà di **moltiplicatività** della funzione di Eulero.
    *   Esempio: $\phi(40) = \phi(8 \cdot 5)$. Poiché $\text{MCD}(8, 5) = 1$, possiamo scrivere $\phi(40) = \phi(8) \cdot \phi(5)$.
        *   $\phi(8) = \phi(2^3) = 2^3 - 2^2 = 4$.
        *   $\phi(5) = 5 - 1 = 4$.
        *   Quindi, $\phi(40) = 4 \cdot 4 = 16$.

### Formula Generale per $\phi(n)$

Per un qualsiasi numero intero positivo $n$ con scomposizione in fattori primi $n = P_1^{h_1} \cdot P_2^{h_2} \cdot \dots \cdot P_k^{h_k}$, la funzione di Eulero è data da:

$$\phi(n) = (P_1^{h_1} - P_1^{h_1-1}) \cdot (P_2^{h_2} - P_2^{h_2-1}) \cdot \dots \cdot (P_k^{h_k} - P_k^{h_k-1})$$

Questa formula può anche essere scritta come:

$$\phi(n) = n \cdot \left(1 - \frac{1}{P_1}\right) \cdot \left(1 - \frac{1}{P_2}\right) \cdot \dots \cdot \left(1 - \frac{1}{P_k}\right)$$

**Esempio:** Calcolare $\phi(160)$.
*   Scomposizione in fattori primi di $160$: $160 = 16 \cdot 10 = 2^4 \cdot 2 \cdot 5 = 2^5 \cdot 5^1$.
*   Applicando la formula generale:
    *   $\phi(160) = (2^5 - 2^{5-1}) \cdot (5^1 - 5^{1-1})$
    *   $\phi(160) = (32 - 16) \cdot (5 - 1)$
    *   $\phi(160) = 16 \cdot 4 = 64$.

### Teorema di Eulero

Siano $a$ e $m$ due numeri interi positivi tali che $\text{MCD}(a, m) = 1$ (cioè, $a$ e $m$ sono coprimi). Allora si ha:

$$a^{\phi(m)} \equiv 1 \pmod m$$

**Esempio:** Calcolare $31^{\phi(40)} \pmod {40}$.
*   Verifichiamo le condizioni: $\text{MCD}(31, 40) = 1$. Le condizioni del teorema di Eulero sono soddisfatte.
*   Applicando il teorema, $31^{\phi(40)} \equiv 1 \pmod {40}$. Il resto è $1$.

### Piccolo Teorema di Fermat

Il Piccolo Teorema di Fermat è un caso particolare del Teorema di Eulero. Se $P$ è un numero primo e $a$ è un intero non divisibile per $P$ (cioè $\text{MCD}(a, P) = 1$), allora:

$$a^{P-1} \equiv 1 \pmod P$$

Questo deriva dal Teorema di Eulero sostituendo $m$ con un numero primo $P$, poiché $\phi(P) = P-1$.

**Esempio:** Calcolare $77^{30} \pmod {31}$.
*   Verifichiamo le condizioni: $31$ è un numero primo. $\text{MCD}(77, 31) = 1$ (poiché $77 = 2 \cdot 31 + 15$, il resto è 15, non 0, quindi non è divisibile).
*   L'esponente $30$ è uguale a $P-1 = 31-1$.
*   Applicando il Piccolo Teorema di Fermat, $77^{30} \equiv 1 \pmod {31}$. Il resto è $1$.

### Congruenza per la Riduzione dell'Esponente (Conseguenza del Teorema di Eulero)

Siano $a, m, n$ tre numeri interi positivi tali che $\text{MCD}(a, m) = 1$. Allora vale la seguente congruenza:

$$a^n \equiv a^{n \pmod{\phi(m)}} \pmod m$$

Questa proprietà è estremamente utile per ridurre esponenti molto grandi in calcoli modulari.

**Esempio:** Determinare il resto di $13^{49} \div 5$.
*   Vogliamo calcolare $13^{49} \pmod 5$.
*   Verifichiamo le condizioni: $\text{MCD}(13, 5) = 1$. Le condizioni sono soddisfatte.
*   Calcoliamo $\phi(m) = \phi(5)$. Poiché $5$ è un numero primo, $\phi(5) = 5 - 1 = 4$.
*   Ora riduciamo l'esponente $n = 49$ modulo $\phi(m) = 4$: $49 \pmod 4 = 1$ (poiché $49 = 12 \cdot 4 + 1$).
*   Applicando la congruenza, $13^{49} \equiv 13^1 \pmod 5$.
*   $13^1 = 13$.
*   Infine, calcoliamo $13 \pmod 5 = 3$ (poiché $13 = 2 \cdot 5 + 3$).
*   Pertanto, $13^{49} \equiv 3 \pmod 5$. Il resto è $3$.

## Lezione 3: Inverso Modulare

### Inverso nei Numeri Reali

Nel campo dei numeri reali (o razionali), per ogni numero $a \neq 0$, esiste un unico inverso (o reciproco) $x$ tale che $a \cdot x = 1$. Ad esempio, l'inverso di $3$ è $1/3$, e l'inverso di $-2/5$ è $-5/2$.

### Definizione di Inverso Modulare

Siano $n$ e $m$ due numeri interi positivi e non nulli. L'**inverso modulare** di $n$ modulo $m$, indicato con $x$, è un numero intero tale che:

$$n \cdot x \equiv 1 \pmod m$$

L'inverso modulare $x$ esiste se e solo se $n$ e $m$ sono coprimi, ovvero $\text{MCD}(n, m) = 1$.

**Normalizzazione:** L'inverso modulare non è unico, ma per convenzione si considera l'unico valore di $x$ compreso nell'intervallo $0 \le x < m$. Questo valore è chiamato l'inverso modulare normalizzato.

### Metodo per Determinare l'Inverso Modulare

Per trovare l'inverso $x$ di $n$ modulo $m$, possiamo riscrivere la congruenza come $n \cdot x - 1 = k \cdot m$ per qualche intero $k$. Da qui, possiamo esprimere $x$ come:

$$x = \frac{k \cdot m + 1}{n}$$

Si cerca un valore intero di $k$ tale che $k \cdot m + 1$ sia divisibile per $n$ e il risultante $x$ sia nell'intervallo $0 \le x < m$.

**Esempio:** Determinare l'inverso di $9$ modulo $5$.
*   Vogliamo trovare $x$ tale che $9x \equiv 1 \pmod 5$.
*   Verifichiamo l'esistenza: $\text{MCD}(9, 5) = 1$, quindi l'inverso esiste.
*   Usando la formula: $x = \frac{k \cdot 5 + 1}{9}$.
*   Proviamo valori di $k$ interi:
    *   $k=1 \Rightarrow x = (1 \cdot 5 + 1) / 9 = 6/9$ (non intero)
    *   $k=2 \Rightarrow x = (2 \cdot 5 + 1) / 9 = 11/9$ (non intero)
    *   $k=3 \Rightarrow x = (3 \cdot 5 + 1) / 9 = 16/9$ (non intero)
    *   $k=4 \Rightarrow x = (4 \cdot 5 + 1) / 9 = 21/9$ (non intero)
    *   $k=5 \Rightarrow x = (5 \cdot 5 + 1) / 9 = 26/9$ (non intero)
    *   $k=6 \Rightarrow x = (6 \cdot 5 + 1) / 9 = 31/9$ (non intero)
    *   $k=7 \Rightarrow x = (7 \cdot 5 + 1) / 9 = 36/9 = 4$. Questo è un intero!
*   L'inverso è $x=4$. Verifichiamo che $0 \le 4 < 5$. Sì.
*   Quindi, l'inverso di $9$ modulo $5$ è $4$. Infatti, $9 \cdot 4 = 36$, e $36 \equiv 1 \pmod 5$ (poiché $36 = 7 \cdot 5 + 1$).

**Metodo Alternativo (Multipli e Resti):**
Si possono elencare i multipli di $n$ e calcolare il loro resto modulo $m$ fino a trovare un resto di $1$.
*   Multipli di $9$: $0, 9, 18, 27, 36, 45, \dots$
*   Resti modulo $5$:
    *   $0 \pmod 5 = 0$
    *   $9 \pmod 5 = 4$
    *   $18 \pmod 5 = 3$
    *   $27 \pmod 5 = 2$
    *   $36 \pmod 5 = 1$. Trovato! $36 = 9 \cdot 4$, quindi $x=4$.

### Determinazione dell'Inverso Modulare Tramite il Teorema di Eulero

Se $\text{MCD}(n, m) = 1$, l'inverso modulare $x$ di $n$ modulo $m$ può essere determinato utilizzando il Teorema di Eulero. Sappiamo che $n^{\phi(m)} \equiv 1 \pmod m$. Possiamo riscrivere questa congruenza come:

$$n \cdot n^{\phi(m)-1} \equiv 1 \pmod m$$

Confrontando con la definizione $n \cdot x \equiv 1 \pmod m$, si deduce che l'inverso modulare $x$ è dato da:

$$x \equiv n^{\phi(m)-1} \pmod m$$

Questo risultato fornisce un metodo diretto per calcolare l'inverso modulare, specialmente quando $\phi(m)$ è facile da calcolare.

**Esempio:** Determinare l'inverso di $11$ modulo $5$.
*   Vogliamo trovare $x$ tale che $11x \equiv 1 \pmod 5$.
*   Verifichiamo l'esistenza: $\text{MCD}(11, 5) = 1$, quindi l'inverso esiste.
*   Calcoliamo $\phi(m) = \phi(5)$. Poiché $5$ è un numero primo, $\phi(5) = 5 - 1 = 4$.
*   Applichiamo la formula: $x \equiv 11^{\phi(5)-1} \pmod 5 \equiv 11^{4-1} \pmod 5 \equiv 11^3 \pmod 5$.
*   Ora dobbiamo calcolare $11^3 \pmod 5$. Possiamo ridurre la base prima di elevare a potenza:
    *   $11 \pmod 5 = 1$ (poiché $11 = 2 \cdot 5 + 1$).
    *   Quindi, $11^3 \equiv 1^3 \pmod 5$.
    *   $1^3 = 1$.
*   Pertanto, $x \equiv 1 \pmod 5$. L'inverso normalizzato è $1$.
*   Verifica: $11 \cdot 1 = 11$, e $11 \equiv 1 \pmod 5$.
