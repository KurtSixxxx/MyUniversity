## Merged Files List
- 1. 1 Modulo Logica Proposizionale, Insiemi e relazion 32f1cf23380e806ca3bad2803bd73455.md (1.1 KB)
- 2. Insiemi 32f1cf23380e80ec89c9f31fc3ee404b.md (17.8 KB)
- 3. Insiemi chiusi e famiglie chiuse di insiemi 32f1cf23380e8000bb50d78d6a828a11.md (5.8 KB)
- 4. Logica Proposizionale 32f1cf23380e802db6cbcf20461eda6b.md (15.1 KB)
- 5. Relazioni 32a1cf23380e806e9569c773cb4389d1.md (27.6 KB)
- 6. Il paradosso di Russell spiegato agli stupidi 32a1cf23380e80e781d6d1d82c193d33.md (5 KB)
- 7. Esempi (Esercizi svolti con Google AI) (1) 32f1cf23380e805fb97cc36a9ec0b5fd.md (460 B)
- 8. Equivalenza Esercizi (1) 32f1cf23380e80f98850de637bd0e4af.md (2.2 KB)
- 9. Tavole di verità Esercizi (1) 32f1cf23380e8053a856c78dc76f4428.md (3.8 KB)


## 1. 1 Modulo Logica Proposizionale, Insiemi e relazion 32f1cf23380e806ca3bad2803bd73455.md

```md
# 1 Modulo: Logica Proposizionale, Insiemi e relazioni

## Indice:

1. Introduzione alla Logica Proposizionale e agli operatori di base.
2. Il concetto di insieme e le proprietà di base. Insiemi ed operazioni tra di essi. Dimostrazione diretta.
    - Famiglie di insiemi. Insieme prodotto. Paradossi.
3. Relazioni binarie e funzioni. Relazioni di Equivalenza. Relazioni d’ordine, Rappresentazione di insiemi finiti.
    - Il Problema del "Hitting Set"
4. Caso Studio: Famiglie di insiemi chiuse e la congettura Union-Closed

---

[Logica Proposizionale](1%20Modulo%20Logica%20Proposizionale,%20Insiemi%20e%20relazion/Logica%20Proposizionale%2032f1cf23380e802db6cbcf20461eda6b.md)

[Insiemi](1%20Modulo%20Logica%20Proposizionale,%20Insiemi%20e%20relazion/Insiemi%2032f1cf23380e80ec89c9f31fc3ee404b.md)

[Relazioni](1%20Modulo%20Logica%20Proposizionale,%20Insiemi%20e%20relazion/Relazioni%2032a1cf23380e806e9569c773cb4389d1.md)

[Insiemi chiusi e famiglie chiuse di insiemi](1%20Modulo%20Logica%20Proposizionale,%20Insiemi%20e%20relazion/Insiemi%20chiusi%20e%20famiglie%20chiuse%20di%20insiemi%2032f1cf23380e8000bb50d78d6a828a11.md)
```

## 2. Insiemi 32f1cf23380e80ec89c9f31fc3ee404b.md

```md
# Insiemi

# Insiemi

### Il concetto di insieme

Gli insiemi sono una collezione ben definita di oggetti. Un insieme è caratterizzato dal suo contenuto, ovvero dagli elementi che gli appartengono. Formalizziamo il concetto di appartenenza.

### Caratterizzazione di un insieme

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

**Appartenenza**
Se T è un insieme, l’espressione $x \in T$ si legge: “x appartiene all’insieme T” oppure “x è un elemento di T”.

</aside>

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

**Non Appartenenza**
Scriveremo invece $x \notin T$ per negare l’espressione precedente, cioè affermare che x non appartiene all’insieme T.

</aside>

### Assioma di estensionalità

Dal momento che un insieme è univocamente caratterizzato dal suo
contenuto, due insiemi che contengono gli stessi elementi, sono lo
stesso insieme. Abbiamo, quindi, una prima proprietà fondamentale
che viene anche denominata "Assioma di Estensionalità":

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

**Uguaglianza tra insiemi**
Due insiemi A e B sono uguali se hanno gli stessi elementi. In simboli

$A = B \iff (\forall x) (x \in A \iff x \in B)$

</aside>

### Descrizione di un insieme

Per descrivere un insieme sarà sufficiente elencarne gli elementi. Per convenzione vengono indicati tramite partentesi graffe. Ad esempio, un insieme $\{1,2,3\}$ indica l’insieme i cui elementi sono appunto i numeri 1, 2, 3.

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

**Singoletto**
La notazione $\{a\}$ indica l’insieme costituito solo da un elemento $a$, detto singoletto.

</aside>

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

Insieme Vuoto
Con il simbolo $\emptyset$ indicheremo un insieme speciale, detto insieme vuoto, che è l’insieme che non contiene alcun elemento.

</aside>

### Definizione di un insieme

Dalla definizione di uguaglianza, deduciamo immediatamente che gli insiemi $A = \{1,2,3\}$ e $B = \{2,3,1,2,3\}$ sono uguali perché contengono gli stessi elementi. Per lo stesso motivo sono uguali anche gli insiemi $A = \{1,2,3\}$ e $B = \{3,2,1\}$.
Quindi da questo capiamo che ogni insieme è caratterizzato dal fatto che i suoi elementi appaiono una sola volta, e non importa in quale ordine sono elencati.

Possiamo specificare un insieme e la proprietà che caratterizza i suoi elementi in questo modo:

Se P è una proprietà ben definita, possiamo allora definire l’insieme 

$$
\{x : \text{la proprietà P è vera per P}\} \equiv \{x:P(x)\}
$$

Questo vuol dire: ”Prendiamo tutti i valori di x per cui la frase P(x) è vera, e li mettiamo in un insieme.”

Cosa vuol dire che P è una proprietà ben definita? Vuol dire che
per ogni valore di x, P(x) può assumere sempre solo i 2 valori vero o falso

Esempi:

Se scrivo:

> $P(x)$: "x è maggiore di 5"
> 
- Allora:
    - $P(3)$ è **falsa** (perché 3 non è maggiore di 5)
    - $P(7)$ è **vera** (perché 7 è maggiore di 5)

Altro esempio:
Supponi che:

- $P(x)$ = "x è un numero pari"
- Allora l'insieme ${x : P(x)}$  significa:

*“L’insieme di tutti gli x **pari**”*

Quindi: $\{x \in \N : \text{x è pari}\} = \{0, 2, 4, 6, 8, ...\}$

Esempio di NON insieme:
Supponiamo P sia la proprietà di essere “alti”, allora $\{x : P(x)\}$ non è un insieme.

### Cardinalità

Ad ogni insieme si può associare la caratterizzazione della quantità degli elementi che gli appartengono.

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

**Cardinalità**
Dato un insieme A, il numero di elementi che lo costituisce è denominato cardinalità dell’insieme ed è denotata con  $|A|$. Se $|A|$  è un numero intero l’insieme si dice finito, altrimenti infinito.

</aside>

Esempio:

- La cardinalità dell’insieme vuoto è quindi zero, $|\emptyset| = 0$, mentre $|\{1,2,3\}| = 3$ e $|\{a\}| = 1$.
- La cardinalità dell’insieme costituito dai numeri pari è invece infinita, $|\{x : x \space \text{è un numero pari}\}|= +\infin$

### Relazione di Inclusione

Se abbiamo due insiemi $A$ e $B$ e tutti gli elementi di $A$ sono anche
elementi di $B$ allora diciamo che $A$ è incluso in $B$, ovvero che $A$ è un
sottoinsieme di $B$.

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

**Inclusione**
$A$ è un sottoinsieme di $B$, denotato con $A \sube B$ se:

$$
A \sube B \iff (\forall x) (x \in A \implies x \in B)
$$

</aside>

Si legge: A è contenuto in B se e solo se, per ogni x, se x appartiene ad A allora x appartiene anche a B.

Notiamo che la relazione $A \sube B$ è verificata nel caso in cui $A = B$.

Per esprimere il fatto che $A \sube B$ ma $A$ è diverso da $B$, cioè esistono elementi di $B$ che non sono elementi di A, scriviamo $A \sub B$ o equivalentemente $B \sub A$. In questo caso diciamo che $A$ è un sottoinsieme proprio di $B$, ovvero $A$ è propriamente contenuto in $B$.

Possiamo specificare un sottoinsieme di un dato insieme elencandone gli elementi, quando possibile, oppure utilizzare una proprietà ben definita. Più in dettaglio, supponiamo che $T$ sia un insieme e che $P(x)$ sia una proprietà che ha senso per gli elementi di $T$. Scriviamo allora $\{x : x \in T \space \text{e} \space P(x)\}$ per indicare il sottoinsieme di $T$ formato dagli elementi per cui $P(x)$ è vera.

Esempio:

Supponiamo $T$ sia l’insieme di tutti i numeri interi positivi da 1 a 100, ovvero

$$
T = \{1,2,3,4,...,98,99,100\}
$$

e supponiamo che la proprietà $P(x)$ sia quella di essere un multiplo di 10. Allora

$$
\{x : x \in T \space \text{e} \space P(x)\} = \\ \{10,20,30,40,50,60,70,80,90,100\}
$$

### Insiemi discreti

<aside>
<img src="https://www.notion.so/icons/warning_gray.svg" alt="https://www.notion.so/icons/warning_gray.svg" width="40px" />

**Insieme discreto**

Un insieme $A$ si dice discreto se è possibile ordinare i suoi elementi in maniera tale che tra un qualunque elemento ed il successivo nell’ordinamento dato, non vi sono altri elementi dell’insieme. Quindi, è un insieme composto da elementi "isolati".

</aside>

Ogni insieme finito è discreto. In particolare, anche l’insieme vuoto $\emptyset$ è discreto.

Ricordiamo che:

$$
\mathbb{N} = \left\{ 0,1,2,3,4,...\right\}\\\mathbb{Z} = \left\{ ..., -4, -3, -2, -1, 0, 1, 2, 3, 4,...\right\}\\ \mathbb{Q}= \left\{\frac{n}{m}: n,m \in \mathbb{Z}\right\}\\ \mathbb{R}= \left\{ x : x \text{\space razionale o irrazionale}\right\}\\ \mathbb{C}= \left\{ x : x \text{\space reale o immaginario}\right\}
$$

Quindi:

$\mathbb{N} \sub \mathbb{Z} \sub \mathbb{Q} \sub \mathbb{R} \sub \mathbb{C}$

Abbiamo:

| $\mathbb{N}$ | insieme dei **numeri naturali** | **discreto** |
| --- | --- | --- |
| $\mathbb{Z}$ | insieme degli **interi relativi** | **discreto** |
| $\mathbb{Q}$ | insieme dei **numeri razionali** | **né discreto né continuo** |
| $\mathbb{R}$ | insieme dei **numeri reali** | **continuo** |
| $\mathbb{C}$ | insieme dei **numeri complessi** | **continuo** |

### Operazioni tra insiemi

Introduciamo le operazioni fondamentali tra insiemi.

### Unione di due insiemi

L’unione di due insiemi $A$ e $B$ è l’insieme formato da quegli elementi che appartengono ad almeno uno dei due insiemi $A$ e $B$. La notazione per indicare l’unione tra A e B è $A \cup B$.

$$
A \cup B = \{x : x \in A \space \text{oppure} \space x \in B.\}
$$

**Esempio:**

Se $A = \{1,2,3\}$ e $B = \{3,4,5\}$ allora:

$$
A \cup B = \{1,2,3,4,5\}
$$

e notiamo che l’elemento $3$, presente in entrambi gli insiemi, è ovviamente presente nell’unione una sola volta, come da precedente definizione di insieme.

**Proprietà dell’unione di due insiemi:**

L’unione di due insiemi A e B è commutativa ed associativa, ovvero

- $A \cup B = B \cup A$  (**commutatività**)
- $A \cup (B \cup C) = (A \cup B) \cup C$ (**associatività**)

### Intersezione di due insiemi

L’intersezione di due insiemi $A$ e $B$ è l’insieme formato da quegli elementi che appartengono ad entrambi gli insiemi $A$ e $B$.

La notazione per indicare l’intersezione è $A \cap B$.

$$
A \cap B = \{x : x \in A \space \text{e} \space x \in B.\}
$$

**Esempio**:

Se $A = \{1,2,3\}$ e $B = \{3,4,5\}$ allora:

$$
A \cap B = \{3\}
$$

e notiamo che l’elemento $3$, è l’unico presente in entrambi gli insiemi.

Due insiemi $A$ e $B$ si dicono **disgiunti** se la loro intersezione è vuota
ovvero

$$
A \cap B = \emptyset
$$

L’intersezione di due insiemi A e B è commutativa ed associativa
ovvero:

- $A \cap B = B \cap A$ (**commutatività**)
- $A \cap (B \cap C) = (A \cap B) \cap C$ (**associatività**)

### Proprietà formali di unione ed intersezione

Abbiamo già detto che unione ed intersezione sono commutative ed
associative. Ecco altre proprietà importanti:

- $A \cap A = A$ e $A \cup A = A$ (**idempotenza**)
- Proprietà Distributiva
    - $A \cap (B \cap C) = (A \cap B) \cup (A \cap C)$ (l’intersezione si distribuisce sull’unione)
    - $A \cup (B \cap C) = (A \cup B)\cap(A \cup C)$ (L’unione si distribuisce sull’intersezione)
- Proprietà di Assorbimento
    - $A \cap (A \cup B) = A$ (l’intersezione tra un insieme con uno che lo contiene produce l’insieme dato)
    - $A \cup (A \cap B) = A$  (l’unione tra un insieme ed un suo sottoinsieme produce l’insieme dato)

### Cardinalità dell’unione

Se $A$ e $B$ sono insiemi finiti allora:

$$
|A \cup B| = |A| + |B| - |A \cap B|
$$

ovvero la cardinalità dell’unione dei due insiemi è la somma delle cardinalità dei due insiemi presi singolarmente meno la cardinalità dell’intersezione.
Se gli insiemi A e B sono disgiunti allora:
$|A \cup B| = |A| + |B|$

### Differenza di due insiemi

La differenza di due insiemi $A$ e $B$ denotata con $A \setminus  B$ è l’insieme
formato da quegli elementi del primo insieme $A$ che non appartengono al secondo insieme $B$. Quindi:

$$
A \setminus B = \{x : x \in A \space \text{e} \space x \notin B\}
$$

Esempio:

Se $A  = \{1,2,3\}$ e $B = \{3,4,5\}$ allora $A \setminus B = \{1,2\}$, l’elemento $3$, che è l’unico presente in entrambi gli insiemi, è sottratto da $A$.

### Diagrammi di Venn

I diagrammi di Venn sono una rappresentazione grafica della relazione di due o più insiemi, per esempio, i 3 insiemi A, B e C. E’ ottenuta rappresentando sul piano gli insiemi e osservando le regioni del piano.

![image.png](Insiemi/image.png)

 

1. $A \setminus (B \cup B)$
2. $(A \cap C) \setminus B$
3. $B \setminus (A \cup C)$
4. $(B \cap C) \setminus A$
5. $C \setminus (A \cup B)$
6. $(A \cap B) \setminus C$
7. $A \cap B \cap C$
8. e la regione dove ci sono tutti gli elementi che non appartengono a nessuno dei 3 insiemi

per un totale di **8 regioni**.

Quindi il diagramma di Venn di $n$ insiemi è formato da $2^n$ regioni, non tutte necessariamente non vuote.

### Complemento di un insieme

Se assumiamo che gli insiemi con cui lavoriamo siano tutti sottoinsiemi di un grande insieme chiamato *Universo* e indicato con $U$, allora dato che $A \sube U$ l’insieme $U \setminus A$ viene detto complemento di $A$.

Quindi il complemento di un insieme $A$ è l’insieme di tutti gli elementi che non appartengono ad $A$. E si indica con la seguente notazione:

$$
U \setminus A = A^C
$$

Esempio:

Se $A = \{1,2,3\}$ e $U = \{1,2,3,4,5,6,7,8,9,10\}$ allora $A^C = \{4,5,6,7,8,9,10\}$

### Proprietà del complemento

Elenchiamo 3 proprietà fondamentali del complemento.

1. $(A^C)^C = A$ (il complemento del complemento di un insieme è il complemento stesso)
2. $(A \cap B)^C = A^C \cup B^C$ (De Morgan: il complemento dell’intersezione è l’unione dei complementi)
3. $(A \cup B)^C = A^C \cap B^C$ (De Morgan: il complemento dell’unione è l’intersezione dei complementi)

Cardinalità del complemento.

Se $U$ è finito e $A \sube U$ allora $|A^C| = |U| - |A|$

### Differenza simmetrica di due insiemi

`Da completare…`

---

### Problema dell’Hitting Set

## Hitting Set

#### **1. Definizione Formale**

Dati:

- Un **insieme universo** $U = \{1, 2, 3, \dots, n\}$ (gli elementi che puoi scegliere).
- Una **collezione di sottoinsiemi** $S = \{S_1, S_2, \dots, S_m\}$ dove ogni $S_i$ contiene elementi di $U$.

Un **Hitting Set** è un sottoinsieme $H \subseteq U$ tale che $H$ ha almeno un elemento in comune con ogni sottoinsieme della collezione $S$.
In formule: $\forall S_i \in S, H \cap S_i \neq \emptyset$.

#### **2. Minimale vs. Minimo**

Esiste una distinzione cruciale tra questi due termini:

- **Hitting Set Minimale:** È un insieme che colpisce tutti i gruppi, ma se provi a togliere anche un solo elemento, smette di essere un hitting set. Non è necessariamente il più piccolo in assoluto, è solo "non ulteriormente riducibile".
- **Hitting Set Minimo:** È l'insieme con la **cardinalità più bassa possibile** (quello con meno elementi in assoluto) tra tutti i possibili hitting set. Trovare questo insieme è un problema **NP-difficile**, ovvero non esiste un algoritmo veloce (polinomiale) per risolverlo esattamente su larga scala.

#### **3. L'Algoritmo Greedy (Ingordo)**

Poiché trovare la soluzione perfetta (il minimo) è difficile, si usa spesso l'approccio **Greedy**, che è veloce e offre una buona approssimazione: [1]

1. Inizia con un insieme $H$ vuoto.
2. Finché ci sono sottoinsiemi in $S$ che non sono stati ancora "colpiti":
    - Conta quante volte ogni elemento di $U$ compare nei sottoinsiemi non ancora colpiti.
    - Scegli l'elemento che compare **più spesso**.
    - Aggiungi quell'elemento ad $H$.
    - Segna come "colpiti" tutti i sottoinsiemi che contengono quell'elemento.
3. Quando tutti i sottoinsiemi sono colpiti, restituisci $H$.

**Nota:** L'algoritmo greedy non garantisce sempre la soluzione minima, ma garantisce di non allontanarsi troppo da essa (il fattore di approssimazione è logaritmico rispetto alla dimensione degli insiemi).

#### **Esempio Pratico**

Immagina di avere tre gruppi di amici che vogliono ordinare una pizza:

- Gruppo A: {Margherita, Diavola}
- Gruppo B: {Diavola, Funghi}
- Gruppo C: {Margherita, Funghi, Vegetariana}

L'**Hitting Set Minimo** è {Diavola, Margherita} (o altre coppie), perché con solo 2 pizze accontenti tutti i gruppi. Un hitting set non minimale sarebbe {Diavola, Margherita, Funghi}: colpisce tutti, ma potresti togliere la Funghi e funzionerebbe ancora.

### 🔹 Cos’è un **Hitting Set (HS)?**

- Hai un insieme grande **U**
    
    (es: $U = \{a, b, c, d, e\}$)
    
- Hai una famiglia di sottoinsiemi **A**
    
    (es: $A = \{\{a, b, c\}, \{a, d, e\}, \{b, c, d\}, \{c, d, e\}\}$)
    

🔸 Un **Hitting Set** è un sottoinsieme **H ⊆ U** che ha **almeno un elemento in comune con ogni sottoinsieme di A**.

👉 Deve “toccare” tutti i gruppi.

---

### 🔍 Esempio

$U = \{a, b, c, d, e\}$

$A = \{\{a, b, c\}, \{a, d, e\}, \{b, c, d\}, \{c, d, e\}\}$

✔️ {a, b, c} è un HS → tocca tutti gli insiemi

✖️ {b, c} **non** è un HS → non tocca {a, d, e}

---

### 🔹 Cos’è un **HS minimale**?

- È un HS dove **non puoi togliere nessun elemento** senza perdere la proprietà.
    
    ✅ È “essenziale” in ogni suo elemento.
    

---

### 🔹 Cos’è un **HS minimo**?

- È l’HS **più piccolo possibile** (meno elementi)
    
    ✅ Nessun HS ha meno elementi di lui.
    

✳️ Un HS minimo è anche minimale, ma non sempre vale il contrario.

---

### 🚫 Perché è difficile trovare un HS minimo?

- Per trovare il minimo bisognerebbe **provare tutti i sottoinsiemi** di U
    
    → Troppo lento: ci sono **2^n** sottoinsiemi (esponenziale!)
    

---

### 💡 Caso facile: insiemi **disgiunti**

- Se gli insiemi di A **non hanno elementi in comune**, basta prendere **un elemento da ognuno**.

🧪 Esempio:

$A = \{\{a\}, \{b\}, \{c\}\} → \text{HS minimo} = \{a, b, c\}$

### 🔚 Riassunto veloce

| Concetto | Significato |
| --- | --- |
| **HS** | Tocca tutti gli insiemi (ha almeno un elemento in comune) |
| **Minimale** | Non puoi togliere nulla, o non è più HS |
| **Minimo** | Ha il minor numero possibile di elementi |
| **Difficile** | Il problema è NP-hard (nessun metodo veloce conosciuto) |
| **Facile se…** | Gli insiemi sono disgiunti → prendi un elemento per ciascuno |

### **1. Insieme delle Parti (Insieme Potenza)**

È l'insieme di **tutti i possibili sottoinsiemi** che puoi creare con gli elementi di un insieme $A$.

- **Cosa contiene:** L'insieme vuoto ($\emptyset$), i singoli elementi, tutte le combinazioni (coppie, terne, ecc.) e l'insieme $A$ stesso.
- **Caratteristica:** I sottoinsiemi si **sovrappongono** (un elemento può apparire in più gruppi contemporaneamente).
- **Esempio:** Se $A = \{1, 2\}$, l'Insieme delle Parti è: $\{\emptyset, \{1\}, \{2\}, \{1, 2\}\}$.

### **2. Partizione di un Insieme**

È una **suddivisione esatta** e ordinata di $A$ in "blocchi" separati (sottoinsiemi).

- **Le 3 Regole d'oro:**
    1. **Nessun vuoto:** Ogni sottoinsieme deve contenere almeno un elemento.
    2. **Nessun "doppione":** Ogni elemento appartiene a **uno e un solo** sottoinsieme (i gruppi sono disgiunti).
    3. **Nessun "escluso":** L'unione di tutti i sottoinsiemi deve restituire l'insieme $A$ completo.
- **Esempio:** Se $A = \{1, 2, 3, 4\}$, una partizione è: $\{\{1, 3\}, \{2, 4\}\}$ (divisione in dispari e pari).

---

**In sintesi:**

- L'**Insieme delle Parti** è il catalogo di **tutte le combinazioni** possibili.
- La **Partizione** è un modo di **fare ordine** dividendo l'insieme in pezzi che non si mischiano.

[Il paradosso di Russell spiegato agli stupidi](Insiemi/Il%20paradosso%20di%20Russell%20spiegato%20agli%20stupidi%2032a1cf23380e80e781d6d1d82c193d33.md)
```

## 3. Insiemi chiusi e famiglie chiuse di insiemi 32f1cf23380e8000bb50d78d6a828a11.md

```md
# Insiemi chiusi e famiglie chiuse di insiemi

## Insiemi chiusi e Famiglie di insiemi chiusi

#### 1. Insiemi chiusi rispetto a un’operazione

La prima parte parla di **insiemi chiusi** rispetto a un’’operazione.

Un insieme $( U )$ si dice **chiuso** rispetto a una certa operazione (es. somma, sottrazione, mcm) se, applicando l’operazione a elementi di ( $U )$, il risultato sta ancora in $( U )$.

Esempi:

- $( \mathbb{N} )$ è chiuso rispetto alla somma (due naturali danno un naturale).
- $( \mathbb{N} )$ **non** è chiuso rispetto alla sottrazione ($3-5 = -2$, che non è in $( \mathbb{N} )$).
- $( X = \{1,2,3\} )$ non è chiuso rispetto al mcm: $mcm(2,3)=6$, ma $6$ non è in $( X )$.
- Se prendiamo $( X = \{1,2,3,6\} )$, allora è chiuso rispetto al mcm.

Qui l’operazione è definita sugli **elementi** dell’insieme.

#### 2. Famiglie chiuse rispetto a unione e intersezione

Ora consideriamo **famiglie di insiemi**.

Una famiglia $( \mathcal{F} )$ (cioè un insieme i cui elementi sono insiemi) si dice **chiusa per unione** se, ogni volta che prendi due insiemi $( X, Y \in \mathcal{F})$, anche la loro unione $( X \cup Y )$ appartiene a $( \mathcal{F} )$.

Analogamente per l’intersezione.

**Esempio**:

$( \mathcal{F} = \{ \{1,2,3\}, \{1,2\}, \{1,3\} \} )$

- Unione: $(\{1,2\} \cup \{1,3\} = \{1,2,3\} \in \mathcal{F})$ ✅
$(\{1,2,3\} \cup \{1,2\} = \{1,2,3\} \in \mathcal{F})$ ✅
Quindi chiusa per unione.
- Intersezione: $(\{1,2\} \cap \{1,3\} = \{1\})$ ma $(\{1\} \notin \mathcal{F})$ → **non** chiusa per intersezione.

#### 3. Famiglia complemento

Dato un universo $( U )$, per ogni $( X \subseteq U )$ definiamo il complemento $( X^C = U \setminus X )$.

Se $( \mathcal{F} )$ è una famiglia di sottoinsiemi di $( U )$, possiamo considerare la famiglia dei complementi:
$[
\mathcal{F}^C = \{ X^C : X \in \mathcal{F} \}.
]$

C’è un **teorema**:

$( \mathcal{F} )$ è chiusa per unione **se e solo se** $( \mathcal{F}^C )$ è chiusa per intersezione (e viceversa).

La dimostrazione usa le leggi di De Morgan:

$$
[
X^C \cap Y^C = (X \cup Y)^C, \qquad X^C \cup Y^C = (X \cap Y)^C
]
$$

#### 4. Chiusura di una famiglia rispetto a un’operazione

Se una famiglia non è chiusa, possiamo aggiungere gli insiemi mancanti finché non lo diventa.

La **chiusura** di $( \mathcal{F} )$ rispetto all’unione (scritta $( \mathcal{F}_\cup )$) è la **più piccola** famiglia che contiene $( \mathcal{F} )$ ed è chiusa per unione.

In pratica, devi includere tutte le unioni di qualsiasi sottoinsieme di $( \mathcal{F} )$ (non solo coppie).

Per calcolarla con insiemi finiti, puoi usare un algoritmo iterativo:

1. Parti con $( \mathcal{F}_1 = \mathcal{F})$.
2. Ad ogni passo, prendi unione tra un insieme di $( \mathcal{F} )$ e uno già ottenuto, aggiungendo il risultato.
3. Ripeti finché non trovi nuovi insiemi.

**Esempio**:

$( \mathcal{F} = \{ \{1,2,3\}, \{1,2\}, \{1,3\}, \{2,4\} \} )$

La sua chiusura per unione deve contenere:

- unioni di coppie:
    - $(\{1,2\} \cup \{1,3\} = \{1,2,3\})$ già presente
    - $(\{1,2\} \cup \{2,4\} = \{1,2,4\})$ (nuovo)
    - $(\{1,3\} \cup \{2,4\} = \{1,2,3,4\})$ (nuovo)
    - ecc.
    Alla fine si ottiene:
    $(\{1,2,3\}, \{1,2\}, \{1,3\}, \{2,4\}, \{1,2,4\}, \{1,2,3,4\})$.
    Non si ottiene  $(\{1,3,4\})$ perché non è unione di insiemi di $( \mathcal{F} )$ (sarebbe $(\{1,3\} \cup \{2,4\}$) no, dà $(\{1,2,3,4\})$; oppure $(\{1,2,3\} \cup \{2,4\}) = (\{1,2,3,4\})$). Quindi $\{1,3,4\}$ non fa parte della chiusura.

#### 7. Chiusura rispetto Unione  e Intersezione: scrittura formale.

- **Chiusura per Unione**

$$
\mathcal{F}_{\cup} = \left\{ \bigcup_{X \in \mathcal{F}'} X : \mathcal{F}' \subseteq \mathcal{F}, \mathcal{F}' \neq \emptyset \right\}
$$

“*Prendo tutte le possibili unioni ($\cup$) ottenibili scegliendo dei pezzi ($\mathcal{F'}$) dalla mia famiglia originale ($\mathcal{F}$)*”

- Chiusura per Intersezione

$$
\mathcal{F}_{\cap} = \left\{ \bigcap_{X \in \mathcal{F}'} X : \mathcal{F}' \subseteq \mathcal{F}, \mathcal{F}' \neq \emptyset \right\}
$$

“*Prendo tutte le possibili intersezioni ($\cap$) ottenibili scegliendo dei pezzi ($\mathcal{F'}$) dalla mia famiglia originale ($\mathcal{F}$)*”

#### 7. Congettura *Union-Closed*

Questa è una congettura famosa (non ancora dimostrata in generale) che riguarda le famiglie chiuse per unione.

Dice: se $( \mathcal{A} )$ è una famiglia di sottoinsiemi di un insieme finito $( U )$, **non vuoti**, ed è chiusa per unione, allora esiste un elemento $( x \in U )$ che appartiene ad almeno la metà degli insiemi di $( \mathcal{A} )$.

Cioè, c’è un elemento “popolare” che compare in almeno $( |\mathcal{A}|/2 )$ insiemi.

Esempio: in una certa famiglia di 25 insiemi, l’elemento 6 compare in 16 insiemi (> metà).

**Dimostrazioni per casi particolari**:

- Se c’è un insieme di cardinalità 1, allora quell’elemento verifica la congettura (dimostrazione con funzione iniettiva).
- Se c’è un insieme di cardinalità 2, almeno uno dei due elementi verifica la congettura (dimostrazione per assurdo).

[Esempi (Esercizi svolti con Google AI) (1)](Insiemi%20chiusi%20e%20famiglie%20chiuse%20di%20insiemi/Esempi%20(Esercizi%20svolti%20con%20Google%20AI)%20(1)%2032f1cf23380e805fb97cc36a9ec0b5fd.md)

#### 8. Congettura *Intersection-Closed*

E’ semplicemente la **"versione a specchio" della congettura Union-Closed.**
Mentre la **UC** (Union-Closed) cerca un elemento "popolare" (che sta in **almeno** metà degli insiemi), la **IC** cerca un elemento "raro".

Definzione Formale:
Sia $U$ un insieme finito e $\mathcal{A}$ una famiglia di sottoinsiemi di $U$ (non tutti vuoti). Se $\mathcal{A}$ è chiusa rispetto all’intersezione, allora esiste un elemento $x \in U$ che appartiene a non più della metà degli elementi di $\mathcal{A}$.

In formule:

$$
|A_x| \le \frac{|\mathcal{A}|}{2}
$$
```

## 4. Logica Proposizionale 32f1cf23380e802db6cbcf20461eda6b.md

```md
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
```

## 5. Relazioni 32a1cf23380e806e9569c773cb4389d1.md

```md
# Relazioni

## Prodotto cartesiano

Immagina di avere due insiemi, **A** e **B**. Il **prodotto cartesiano** (indicato come $A \times B$) è **l'insieme di tutte le possibili coppie ordinate che puoi formare prendendo il primo elemento da A e il secondo da B**. 

In parole povere, è un modo per combinare ogni elemento del primo gruppo con ogni elemento del secondo.

**Un esempio pratico**
Se hai:

- **Insieme A** (gusti gelato): {Cioccolato, Crema}
- **Insieme B** (guarnizioni): {Panna, Granella}

Il prodotto $A \\times B$ sarà l'elenco di tutte le combinazioni possibili:

1. (Cioccolato, Panna)
2. (Cioccolato, Granella)
3. (Crema, Panna)
4. (Crema, Granella)

**Tre cose rapide da sapere:**

1. **L'ordine conta:** La coppia $(x, y)$ è diversa da $(y, x)$. Se inverti gli insiemi ($B \\times A$), le coppie si invertono.
2. **Quanti sono?** Se A ha 3 elementi e B ne ha 4, il prodotto cartesiano ne avrà $3 \\times 4 = 12$.
3. **Graficamente:** Si rappresenta spesso su un piano con due assi (come le coordinate X e Y che usi a scuola), da qui il nome "cartesiano”.

## Relazione Binaria

Sia U un insieme non vuoto.
Una relazione è semplicemente una regola che unisce un elemento del primo insieme A ad un elemento del secondo insieme B.
La relazione viene indicata con la regola R.

**Esempio pratico:**

- Insieme A, ci sono dei bambini: Marco, Giulia e Luca.
- Insieme B, ci sono dei gusti di gelato: Cioccolato e Fragola.
La nostra relazione risponde alla regola "Qual è il gusto preferito?".
- A Marco piace il Cioccolato.
- A Giulia piace la Fragola.
- A Luca piace il Cioccolato.
Ecco, questa è una relazione.

Si scrive:
$\text{(Marco, Cioccolato)}\in R$
$\text{(Giulia, Fragola)} \in R$
$\text{(Luca, Cioccolato)} \in R$
Si legge in modo semplicissimo: "la coppia Marco-Cioccolato fa parte della regola R".
L'insieme di tutte queste relazioni viene detto "Grafico della relazione"

Quindi $R \subseteq U \times U$.
Se R è la nostra relazione, l'insieme è denotato:
${(x,y) : (x,y) \in A \times B \text{ e } R(x,y)}$
Cioè il sottoinsieme di A \times B costituito da tutte le coppie per cui la relazione è verificata.

## Funzione

Una Funzione non è altro che una Relazione un po' più "severa", con delle regole più rigide.
$f$ definita in $A \times B$.

- A è il dominio (elementi di partenza)
- B è il codominio (elementi di arrivo)

La regola principale è che per ogni dominio vi sia uno e uno solo codominio. Non possono esserci più codomini.

Per dire che la nostra regola prende gli elementi dall'insieme A e li manda nell'insieme B, si usa una freccetta: $f:A→B$.
Si scrive così $f(x) = y$.
Si legge semplicemente: "*il valore della funzione per x è uguale a y*". Significa che se diamo x in pasto alla funzione, il risultato è y.

## Funzioni surgettive, iniettive e biiettive

### Funzioni Surgettive (o suriettive)

![Esempio-di-applicazione-suriettiva.png](Relazioni/Esempio-di-applicazione-suriettiva.png)

**Definizione**:
Una funzione $f : A \rightarrow B$ si dice **suriettiva** se ogni elemento $B$ è raggiunto da almeno un elemento di $A$.

**In formule**:  $\exists y \in B, \exists x \in A : f(x) = y$

**Condizione necessaria:**
$|A| \geq |B|$ (serve almeno un elemento di $A$ per ogni elemento di $B$).
Se $|A| \leq |B|$, non si possono coprire tutti gli elementi di $B$.

**Esempio**:

- $A = \{1,2,3,4\}, B = \{x,y,z\}$
- $f(1) = x, f(2) = y, f(3) = z, f(4) = x$
- Ogni elemento di $B (x,y,z)$ è stato raggiunto almeno una volta → **suriettiva**.

**Controesempio**:

- $f(1) = x, f(2) = x, f(3) = x, f(4) = x$
- $y$ e $z$ non sono stati raggiunti → **non suriettiva**.

### Funzioni Iniettive

![esempio-funzione-iniettiva.png](Relazioni/esempio-funzione-iniettiva.png)

**Definizione**:
Una funzione $f : A \rightarrow B$ si dice **iniettiva** se elementi diversi di $A$ vanno in elementi diversi di $B$.

**In formule**:  $x_1 \neq x_1 \Rightarrow f(x_1) \neq f(x_2)$

**Condizione necessaria (sulle cardinalità):**
Per avere una funzione iniettiva è necessario che $|A| \leq |B|$.
Se $|A| > |B|$ due elementi di $A$ finiranno sullo stesso elemento di $B$ → **non iniettiva**

**Esempio**:

- $A = \{1,2,3,4\}, B = \{a,b,c,d\}$
- $f(1) = a, f(2) = b, f(3) = c$
- Ogni elemento di $A$ ha una destinazione diversa → **iniettiva**.

**Controesempio**:

- $f(1) = a, f(2) = a, f(3) = b$ → non iniettiva perché $1$ e $2$ vanno entrambi su $a$.

### Funzioni Biiettive

**Definizione**:
Una funzione $f : A \rightarrow B$ si dice **biiettiva** se è **sia surgettiva che iniettiva**.
Equivale a dire che c’è una corrispondenza **uno a uno** tra gli elementi di $A$ e quelli di $B$.

**Condizione necessaria:**
$|A| = |B|$.
(È necessaria ma non sufficiente: anche con la stessa cardinalità, una funzione potrebbe non essere iniettiva o suriettiva.)

**Esempio**:

- $A = \{1,2,3\}, B = \{a,b,c\}$
- $f(1) = a, f(2) = b, f(3) = c$
- Iniettiva (tutti diversi) e suriettiva (ogni elemento di $B$ è raggiunto) → **biiettiva**.

**Controesempio (stessa cardinalità ma non biiettiva)**:

- $A = \{1,2,3\} , B = \{a,b,c\}$
- $f(1) = a, f(2) = a, f(3) = b$
- Non iniettiva (1 e 2 vanno su $a$) e non suriettiva ($c$ non è raggiunto).

## **Riassunto con le condizioni sulle cardinalità**

| **Tipo** | **Condizione necessaria sulle cardinalità** | **Spiegazione** |
| --- | --- | --- |
| **Suriettiva** | $(A \ge B)$ | Servono abbastanza elementi in $A$ per coprire tutti gli elementi di $B$. |
| **Iniettiva** | $( A \le B)$ | Serve spazio in $B$ per mettere ogni elemento di $A$ in un posto diverso. |
| **Biiettiva** | $(A = B)$ | Solo con lo stesso numero si può sperare di avere sia iniettività che suriettività. |

**Importante**: queste condizioni sono **necessarie** ma non **sufficienti**. Per esempio, con $|A| = |B|$ puoi costruire una funzione che non è né iniettiva né suriettiva (come nell’ultimo esempio). La funzione deve essere definita in modo opportuno.

## Cardinalità di un insieme: Teorema e Dimostrazione

### 1. Cardinalità di un insieme

La **cardinalità** di un insieme è, in parole povere, il **numero di elementi che appartengono a quell'insieme**.

- **Il concetto di "contare":** In matematica, contare significa stabilire una **corrispondenza biunivoca** (o biiezione) tra un insieme di oggetti e un insieme "campione" di numeri.
- **Insieme Finito:** Preso l'insieme campione $I_n = \{0, 1, 2, \dots, n - 1\}$ (che contiene i primi interi precedenti a $n$), un insieme $X$ si dice **finito** se è possibile metterlo in corrispondenza biunivoca con $I_n$.
- **Notazione:** Se l'insieme è finito e corrisponde a $I_n$, si dice che ha "numero cardinale $n$" e si scrive matematicamente come $c(X) = n$ oppure $|X| = n$.
- **Insieme Infinito:** Se non esiste nessun numero $n$ per cui si possa creare questa corrispondenza biunivoca, l'insieme $X$ si dice **infinito**.
- **Stessa cardinalità:** Due insiemi hanno lo stesso numero cardinale (cioè $c(X) = c(Y)$) se possono essere messi in corrispondenza biunivoca tra di loro.

### Operazioni con le cardinalità

Se abbiamo due insiemi finiti $X$ e $Y$, possiamo calcolare la cardinalità delle loro operazioni:

- **Unione (Insiemi disgiunti):** Se non hanno elementi in comune, la cardinalità dell'unione è la somma semplice: $c(X \cup Y) = c(X) + c(Y)$.
- **Unione (Caso generale):** Se hanno elementi in comune, bisogna sottrarre l'intersezione per non contare gli elementi due volte: $c(X \cup Y) = c(X) + c(Y) - c(X \cap Y)$.
- **Prodotto Cartesiano:** La cardinalità degli abbinamenti tra i due insiemi è il prodotto delle singole cardinalità: $c(X \times Y) = c(X) * c(Y)$.

### 2. Il Teorema delle Funzioni Iniettive

Questo teorema ci permette di confrontare la grandezza di due insiemi ($A$ e $B$) sapendo che tipo di funzione li collega.

> **Enunciato del Teorema:**
Se $A$ e $B$ sono due insiemi finiti ed esiste una **funzione iniettiva** $f : A \rightarrow B$, allora $|A| \leq |B|$.
> 

*Spiegazione semplice:* Se riesci ad associare ogni elemento di $A$ a un elemento distinto di $B$ senza mai "riciclare" gli arrivi (iniettività), significa necessariamente che in $B$ ci sono abbastanza "posti liberi" per tutti. Quindi gli elementi di $A$ non possono essere più numerosi di quelli di $B$.

### 3. La Dimostrazione del Teorema

Questa è la dimostrazione formale da esporre , suddivisa in passaggi logici:

1. **Analisi dell'Immagine:** Consideriamo l'immagine dell'applicazione, ovvero $f(A)$. Sappiamo per definizione che questo gruppo di elementi "colpiti" si trova dentro l'insieme di arrivo, quindi $f(A) \subseteq B$.
2. **Sfruttiamo l'Iniettività:** Il testo del teorema ci dice che la funzione $f$ è iniettiva. Questo significa che ogni elemento che si trova in $f(A)$ è l'immagine di **uno ed un solo elemento** di partenza nell'insieme $A$.
3. **Confronto delle cardinalità (A e f(A)):** Poiché a ogni elemento di $A$ corrisponde uno e un solo elemento in $f(A)$, possiamo affermare che in $f(A)$ ci sono esattamente tanti elementi quanti ce ne sono in $A$. In formula: $|A| = |f(A)|$.
4. **Conclusione:** Sappiamo che $f(A)$ è un sottoinsieme di $B$ ($f(A) \subseteq B$), per cui il numero dei suoi elementi sarà per forza minore o uguale al totale degli elementi di $B$ (ovvero $|f(A)| \leq |B|$). Sostituendo $|A|$ al posto di $|f(A)|$, arriviamo alla conclusione finale:
$|A| = |f(A)| \leq |B|$.

**C.V.D.** (Come Volevasi Dimostrare).

#### 📌 Riassunto rapido per il ripasso dell'ultimo minuto:

- $|X|$ **o** $c(X)$ = Quanti elementi ci sono in $X$.
- **Contare** = Fare una biiezione (unione uno-a-uno) con un insieme di numeri di riferimento.
- **Teorema:** Se c'è una funzione iniettiva da $A$ a $B \Rightarrow |A| \leq |B|$.
- **Dimostrazione in 3 step:**
    1. L'immagine $f(A)$ è dentro $B$.
    2. Essendo iniettiva, gli elementi in $A$ sono uguali agli elementi in $f(A)$.
    3. Dato che $f(A)$ è più piccolo o uguale a $B$, anche $A$ sarà più piccolo o uguale a $B$.

## Relazioni di equivalenza ($R$) e proprietà

Per capire le classi di equivalenza, dobbiamo prima guardare le tre proprietà che rendono una relazione "di equivalenza". Immagina la relazione come un legame tra due elementi $x$ e $y$.

Ecco le tre proprietà fondamentali: 

1. Riflessiva: Ogni elemento è in relazione con se stesso.
    1. *Esempio: Io sono alto quanto me stesso. (*$xRx$)
2. Simmetrica: Se x è in relazione con y, allora y è in relazione con x. Il legame va in entrambe le direzioni.
    1. *Esempio: Se io sono alto quanto te, tu sei alto quanto me.*  (Se $xRy$, allora $yRx$)
3. Transitiva: Se x è legato ad y, e y è legato a z, allora anche x è legato a z. E’ un effetto a catena.
    1. *Esempio: Se io sono alto quanto te, e tu sei alto quanto Marco, allora io sono alto quanto Marco.*  (Se $xRy$ e $yRz$, allora $xRz$)

Quando queste tre proprietà valgono contemporaneamente, puoi creare le **classi di equivalenza.**

### Relazioni d’ordine e di pre-ordine

In matematica, quando vuoi stabilire chi viene prima e chi dopo, usi le **Relazioni di Ordine**. La differenza sta tutta in una proprietà: la **Simmetria** viene sostituita dall'**Antisimmetria**.

1. Pre-ordine
    
    Una relazione è di pre-ordine se è:
    
    - **Riflessiva**: $x \leq x$ (Ogni elemento è “in riga” con se stesso.)
    - **Transitiva**: Se $x \leq y$ e $y \leq < z$, allora $x \leq z$.
    - Nota: Qui **non c’è antisimmetria**. Due elementi diversi potrebbero “stare prima” l’uno dell’altro senza essere uguali.
2. **Relazione di Ordine**
    
    E’ quella più comune. Per essere tale deve essere:
    
    - **Riflessiva**
    - **Transitiva**
    - **Antisimmetrica**: Se $x \leq y$ e $y \leq x$, allora $x = y$.

Spiegazione delle proprietà anti-simmetrica.

Anti simmetrica se:
xRy e yRx, allora x = y.
Esempio: 
R = minore o uguale (≤)
3 ≤ 5? Si
5 ≤ 3?  No
allora l'unica possibilità è che x = y

esempio
x = 4 e y = 4
4 ≤ 4 ?? si, in ambo i versi

- Preordine: relazione che è riflessiva e transitiva. Non si chiede antisimmetria. Quindi può succedere che due elementi diversi siano in relazione in entrambi i sensi.
    
    Esempio 1 (preordine, non antisimmetrico)
    Prendiamo l’insieme delle persone e la relazione “non è più alto di” (cioè “è alto al massimo quanto”).
    È riflessiva: ogni persona è alta al massimo quanto se stessa.
    È transitiva: se A non è più alto di B, e B non è più alto di C, allora A non è più alto di C.
    Non è antisimmetrica: se Marco e Lucia hanno la stessa altezza, allora Marco non è più alto di Lucia (sono uguali) e Lucia non è più alta di Marco.
    Quindi due persone diverse sono in relazione in entrambi i versi.
    Questo è un preordine.
    
- Ordine: relazione che è riflessiva, transitiva e antisimmetrica.
Quindi due elementi diversi non possono mai essere in relazione in entrambi i sensi.
    
    Esempio 2 (ordine, antisimmetrico)
    Prendiamo i numeri interi con la relazione ≤.
    È riflessiva, transitiva, ed è antisimmetrica: se x≤y e y≤x, allora x=y.
    Questo è un ordine.
    

### Insiemi ordinati e pre-ordinati

<aside>
💡

- Un insieme U su cui è definita un relazione di pre-ordine si dice pre-ordinato.
- Un insieme U su cui è definita un relazione d’ordine si dice ordinato.
</aside>

- **Insieme Pre-ordinato**: È un insieme dove hai stabilito una regola di **pre-ordine** (quella con le proprietà Riflessiva e Transitiva). È un insieme "abbozzato", dove puoi dire chi viene prima di chi, ma potresti avere elementi diversi che si scambiano il posto.
- **Insieme Ordinato**: È un insieme dove la regola è di **ordine** (quindi ha anche l'Antisimmetrica). Qui la gerarchia è solida: se $x$ precede $y$ e $y$ precede $x$, allora sono lo stesso elemento ($x = y$). Non ci sono ambiguità.
- **La distinzione tra $\leq$ e $\lt$:**
    
    **(Relazione larga $\le$)**: Include la possibilità che i due elementi siano uguali. "X viene prima o è uguale a Y".
    
    **(Relazione stretta $\lt$)**: Si ottiene prendendo la relazione larga e togliendo il caso in cui siano uguali. "X viene decisamente prima di Y"
    

In sintesi: La slide dice che un insieme "prende il nome" dalla relazione che lo governa. Se la relazione è un ordine, l'insieme diventa un Insieme Ordinato.

### Relazioni e Partizioni

La differenza tra Relazione di Equivalenza e Classe di Equivalenza.

- **La Relazione di Equivalenza (R)**
    
    E’ la regola o il “criterio” che si decide per confrontare gli elementi.
    
    - Esempio: “Avere lo stesso colore”
    - Per essere una relazione di equivalenza, questa regola deve essere: riflessiva, simmetrica e transitiva. Senza nessuna di queste caratteristiche puoi creare i gruppi.
- **La Classe di Equivalenza ([x])**
    
    E’ il risultato dell’applicazione di quella regola. Sono i “gruppi” (o le classi) dove metti dentro tutti gli elementi che si somigliano secondo la regola.
    
    - Esempio: “Il gruppo di tutti gli oggetti Rossi”.
    - La classe non “possiede” la proprietà riflessiva/simmetrica/transitiva; la classe **esiste grazie al fatto** che la relazione le possiede.

### 1. La Partizione

Una **partizione** di un insieme $U$ è una suddivisione in sottoinsiemi (chiamati **classi**) che rispetta tre condizioni:

1. **Non vuote:** Ogni classe deve contenere almeno un elemento.
2. **Disgiunte:** Le classi non hanno elementi in comune (un elemento sta in una sola classe).
3. **Esaustive:** L'unione di tutte le classi restituisce l'insieme $U$ originale.

### 2. Relazione di Equivalenza ($\mathcal{R}$)

Ogni **relazione di equivalenza** definita su un insieme $U$ genera sempre una partizione.
Gli elementi che soddisfano la relazione finiscono nella stessa "scatola", chiamata **Classe di Equivalenza**.

**Esempio Numerico:**
Insieme $U = \{1, 2, 3, 4, 5, 6\}$

Regola $\mathcal{R}$: *"Avere lo stesso resto nella divisione per 2"* (Pari o Dispari).

- **Classe A (Dispari):** $\{1, 3, 5\}$
- **Classe B (Pari):** $\{2, 4, 6\}$

### 3. Insieme Quoziente ($U/\mathcal{R}$)

L'**Insieme Quoziente** è l'insieme che ha come elementi le classi stesse (i gruppi), non i singoli numeri.

- **Simbolo:** $U/\mathcal{R}$ (si legge "U modulo $\mathcal{R}$").
- **Esempio:** $U/\mathcal{R} = \{ \{1, 3, 5\}, \{2, 4, 6\} \}$.

**In sintesi:**

- **Elementi di** $U$**:** I singoli numeri ($1, 2, 3...$).
- **Classi:** I raggruppamenti (Dispari, Pari).
- **Insieme Quoziente:** Il "contenitore" di tutti i raggruppamenti.

### Relazioni di Equivalenza e Applicazioni Surgettive

### 1. Dalla Partizione alla Relazione (Il lavoro del postino "al contrario")

Se trovi dei sacchi già pieni e divisi (**Partizione** $\mathcal{F}$), puoi risalire all'unica regola (**Relazione** $\mathcal{R}$) che è stata usata per riempirli.

- **Regola:** Due lettere $x, y$ sono in relazione ($x \approx y$) se e solo se si trovano nello stesso sacco.
- **Risultato:** $\mathcal{F} = U/\mathcal{R}$ (La divisione dei sacchi coincide con l'Insieme Quoziente).

### 2. L'Applicazione Canonica sul Quoziente (Il gesto di smistare)

Data una regola $\mathcal{R}$, definiamo il "gesto" del postino di mettere ogni lettera nel suo sacco:

$$
\pi: U \to U/\mathcal{R}
$$

- **Azione:** Prendi la lettera $x$ e lanciala nella sua classe di equivalenza $[x]$.
- **Definizione:** Questa funzione è chiamata **Applicazione Canonica**.

### 3. Perché è sempre Surgettiva?

L'applicazione è **surgettiva** perché, per definizione di partizione, non esistono classi vuote.

- **In pratica:** Se esiste un sacco postale nell'Insieme Quoziente, significa che c'è almeno una lettera indirizzata a quella città.
- **Conclusione:** Ogni "sacco" (classe) viene riempito da almeno un "elemento" (lettera) di $U$. Non rimangono sacchi vuoti a fine lavoro.

### Esempio Rapido

- **Insieme** $U$**:** 3 lettere per Napoli, 2 per Venezia.
- **Insieme Quoziente** $U/\mathcal{R}$**:** {Sacco Napoli, Sacco Venezia}.
- **Applicazione:** Tutte le 5 lettere vengono smistate.
- **Esito:** Tutti i sacchi sono pieni $\rightarrow$ L'applicazione è **Surgettiva**

---

### Classi di equivalenza e partizioni

Data una relazione di equivalenza, avremo una partizione del gruppo di oggetti in gruppi separati ed ordinati.

Prendiamo una **classe di equivalenza** ($[x]_2$): Immaginiamo di avere un insieme Z, $[x]_2$ sarà la parte di insieme che comprende i numeri pari; mentre $[x]_2+1$ sarà la parte di insieme che comprende i numeri dispari. Così avremo una partizione dell’insieme in due classi di equivalenza: pari e dispari.

**L’insieme quoziente ($U/R$)**. E’ semplicemente l’insieme di tutti questi gruppi (le classi di equivalenza) cioè il nostro insieme completo.

Per rispettare il concetto di “Partizione” queste classi devono rispettare **3 regole** ferree:

1. **Nessuna classe deve essere vuota.**
2. **Coprono tutto (U)**. Ogni elemento deve avere la sua classe di equivalenza, non deve rimanerne nemmeno uno isolato.
3. **Niente sovrapposizioni.** Nessun elemento può stare in più classi di equivalenza contemporaneamente.

**In sintesi:** Una relazione di equivalenza "affetta" il tuo insieme originale in pezzi distinti che, se rimessi insieme, lo ricostruiscono perfettamente.

## Massimi e Minimi | Minimale e Massimale

### Minimo e Massimo

Prendiamo un insieme U con la relazione d'ordine minore o uguale $\leq$.

- Il Massimo M di U è l'elemento tale che per ogni $x \in U$  e si ha $x \leq M$.
In pratica, M è "l'elemento più grande o uguale di tutti gli altri presenti in U".
Se esiste, è l'unico (per l'antisimmetria).
- Il Minimo di U è l'elemento tale che per ogni $x \in U$ e si ha $m \leq x$.In pratica, m è l'elemento più piccolo o uguale di tutti gli altri presenti in U.
Se esiste, è l'unico.

Esempi.

1. Prendiamo l'insieme dei numeri naturali $\mathbb{N} = \{0,1,2\}$ con il solito $\leq$:
    
    Minimo = 0 (è il più piccolo di tutti)
    
    Massimo = non esiste nei numeri naturali perché, essendo l'insieme infinito e privo di un "ultimo" elemento, per ogni numero scelto ne esisterà sempre uno successivo $(n+1)$ che lo supera.
    
2. Nell’insieme ${2,3,5}$ con $\leq$:
    
    Minimo = 2  Massimo = 5
    

### Minimale e Massimale

---

## Insiemi Ordinati (Massimo, Minimo, Massimali, Minimali

Sia $(S, \le)$ un insieme parzialmente ordinato.

### Definizioni Fondamentali

- **MASSIMO**: È unico. Ogni singolo elemento dell'insieme deve essere minore o uguale a lui ($\forall x \in S, x \le M$).
- **MINIMO**: È uno solo. Ogni singolo elemento dell'insieme deve essere maggiore o uguale a lui ($\forall x \in S, m \le x$).
- **MASSIMALE**: Ce ne possono essere molti, uno solo o nessuno. Un elemento è massimale se "non esiste nessuno più grande di lui" nell'insieme.
- **MINIMALE**: Ce ne possono essere molti, uno solo o nessuno. Un elemento è minimale se "non esiste nessuno più piccolo di lui" nell'insieme.

### Regole d'Oro per gli Esercizi

1. **Se hai più di un Massimale** $\implies$ Il Massimo **NON esiste mai**.
2. **Se hai più di un Minimale** $\implies$ Il Minimo **NON esiste mai**.
3. **Unicità**: Se il Massimo esiste, è l'unico massimale. Se il Minimo esiste, è l'unico minimale.

### Esempio 1: Relazione di Inclusione ($\subseteq$)

**Insieme**: $S = \{ \{a\}, \{b\}, \{c\}, \{a,b\}, \{a,c\}, \{b,c\} \}$

- **Minimali**: $\{a\}, \{b\}, \{c\}$ (Nessun elemento di $S$ è contenuto in loro).
- **Massimali**: $\{a,b\}, \{a,c\}, \{b,c\}$ (Non sono contenuti in nessun altro elemento di $S$).
- **Minimo**: **NON ESISTE** (Ci sono più minimali e sono inconfrontabili).
- **Massimo**: **NON ESISTE** (Ci sono più massimali e sono inconfrontabili).

### Esempio 2: Relazione di Divisibilità ($|$)

**Insieme**: $S = \{2, 4, 5, 8, 10, 20\}$
**Regola**: $x \le y \iff x \text{ divide } y$

**Analisi delle relazioni:**

- $2 \mid 4, 8, 10, 20$
- $4 \mid 8, 20$
- $5 \mid 10, 20$
- $10 \mid 20$
- $8$ e $20$ non dividono nessuno (oltre a se stessi).

**Minimali**: Quali numeri non hanno nessuno che li divide ? 2 e 5
**Massimali**: Quali numeri non dividono nessun altro? 8 e 20
**Minimo**: Esiste un numero solo che divide tutti gli altri? no
**Massimo**: Esiste un numero solo che è diviso da tutti gli altri? no

**Risultati:**

- **Minimali**: $\{2, 5\}$ (Sono i numeri che non hanno nessuno che li divide nell'insieme).
- **Massimali**: $\{8, 20\}$ (Sono i numeri che non dividono nessun altro nell'insieme).
- **Minimo**: **NON ESISTE** (Il $2$ non divide il $5$, quindi non divide "tutti" gli altri).
- **Massimo**: **NON ESISTE** (Il $20$ non è diviso dall'$8$, quindi non è diviso da "tutti" gli altri).

## Insiemi totalmente ordinati

Finora abbiamo parlato di **ordine parziale**: una relazione che è riflessiva, antisimmetrica e transitiva, ma non è detto che due elementi qualsiasi siano confrontabili.

Esempio: nell’insieme delle parti, $\{a\}$ e $\{b\}$ non sono confrontabili (nessuno dei due è sottoinsieme dell’altro).

Un **ordine totale** (o lineare) è un ordine in cui ogni coppia di elementi è confrontabile. Cioè, per ogni $x, y$, nell’insieme, si ha $x \leq y$ oppure $y \leq x$.

Esempi di insiemi che sono totalmente ordinati:

- Numeri naturali, interi, razionali, reali con $\leq$ sono insiemi totalmente ordinati.
- Parole in ordine alfabetico (dizionario) è un ordine totale
- Insieme delle parti con $\subseteq$ non totale.

Si chiama totale perché copre “tutte” le coppie, non ci sono coppie incomparabili.

**Esempio concreto**

Prendi l’insieme {2,4,8,16} con l’ordine “divide”.
È un ordine totale?
2 divide 4, 8, 16
4 divide 8, 16
8 divide 16

Ogni coppia è confrontabile (perché ogni numero è potenza di 2). Quindi sì, è totale.

Prendi invece {2,3,6} con “divide”.
2 e 3 non sono confrontabili (2 non divide 3, 3 non divide 2). Quindi non è totale.

## Strutture dati per insiemi di interi

Supponiamo di avere un insieme finito di numeri interi, per esempio $A = \{3,5,7,10\}$
Vogliamo scegliere un modo per rappresentarlo che ci permetta di fare operazioni in modo efficiente.

1. Rappresentazione binaria (vettore di bit)

Prendiamo un insieme universo $U$ che contiene tutti i numeri che ci possono interessare.
Di solito $U = I_m = \{0,1,2, \cdots, m-1\}$  per qualche $m$.

Costruiamo un array di bit (o di booleani) di lunghezza $m$, dove la posizione $i$ vale $1$ se $i \in A$, $0$ altrimenti.

Esempio:
$U = \{0,1,2,3,4,5,6,7,8,9\}$ (cioè m = 10)
$A = \{3,5,7\}$

Quindi avremo $U = \{0,0,0,1,0,1,0,1,0,0\},$ in corrispondenza di dove avevamo $3, 5$ e $7$

**Vantaggi**:

- Verificare se un numero appartiene all’insieme è **immediato**: guardo la posizione corrispondente e vedo se c’è 1 o 0. Tempo costante.
- Calcolare unione e intersezione è veloce: basta fare **OR** e **AND** bit a bit.

**Svantaggi**:

- Se l’universo U*U* è grande (per esempio m=1.000.000*m*=1.000.000) ma l’insieme A*A* ha pochi elementi, sprechiamo memoria (dobbiamo tenere un array di 1.000.000 di bit anche se l’insieme è piccolo).
1. Rappresentazione estesa (lista o array degli elementi)

Nella **rappresentazione estesa**, l’insieme viene semplicemente scritto come un elenco (di solito tra parentesi quadre, come un array) contenente solo gli elementi che ci appartengono.

- In matematica scriviamo A={3,5,7} con le parentesi graffe.
- Nella rappresentazione estesa (informatica) lo scriviamo come lista: `[3, 5, 7]`.

L’idea è che non usiamo una tabella di bit per tutti i numeri possibili, ma teniamo solo gli elementi presenti. Quindi sì, è proprio l’insieme scritto “per esteso”.

## Hitting Set

#### **1. Definizione Formale**

Dati:

- Un **insieme universo** $U = \{1, 2, 3, \dots, n\}$ (gli elementi che puoi scegliere).
- Una **collezione di sottoinsiemi** $S = \{S_1, S_2, \dots, S_m\}$ dove ogni $S_i$ contiene elementi di $U$.

Un **Hitting Set** è un sottoinsieme $H \subseteq U$ tale che $H$ ha almeno un elemento in comune con ogni sottoinsieme della collezione $S$.
In formule: $\forall S_i \in S, H \cap S_i \neq \emptyset$.

#### **2. Minimale vs. Minimo**

Esiste una distinzione cruciale tra questi due termini:

- **Hitting Set Minimale:** È un insieme che colpisce tutti i gruppi, ma se provi a togliere anche un solo elemento, smette di essere un hitting set. Non è necessariamente il più piccolo in assoluto, è solo "non ulteriormente riducibile".
- **Hitting Set Minimo:** È l'insieme con la **cardinalità più bassa possibile** (quello con meno elementi in assoluto) tra tutti i possibili hitting set. Trovare questo insieme è un problema **NP-difficile**, ovvero non esiste un algoritmo veloce (polinomiale) per risolverlo esattamente su larga scala.

#### **3. L'Algoritmo Greedy (Ingordo)**

Poiché trovare la soluzione perfetta (il minimo) è difficile, si usa spesso l'approccio **Greedy**, che è veloce e offre una buona approssimazione: [1]

1. Inizia con un insieme $H$ vuoto.
2. Finché ci sono sottoinsiemi in $S$ che non sono stati ancora "colpiti":
    - Conta quante volte ogni elemento di $U$ compare nei sottoinsiemi non ancora colpiti.
    - Scegli l'elemento che compare **più spesso**.
    - Aggiungi quell'elemento ad $H$.
    - Segna come "colpiti" tutti i sottoinsiemi che contengono quell'elemento.
3. Quando tutti i sottoinsiemi sono colpiti, restituisci $H$.

**Nota:** L'algoritmo greedy non garantisce sempre la soluzione minima, ma garantisce di non allontanarsi troppo da essa (il fattore di approssimazione è logaritmico rispetto alla dimensione degli insiemi).

#### **Esempio Pratico**

Immagina di avere tre gruppi di amici che vogliono ordinare una pizza:

- Gruppo A: {Margherita, Diavola}
- Gruppo B: {Diavola, Funghi}
- Gruppo C: {Margherita, Funghi, Vegetariana}

L'**Hitting Set Minimo** è {Diavola, Margherita} (o altre coppie), perché con solo 2 pizze accontenti tutti i gruppi. Un hitting set non minimale sarebbe {Diavola, Margherita, Funghi}: colpisce tutti, ma potresti togliere la Funghi e funzionerebbe ancora.
```

## 6. Il paradosso di Russell spiegato agli stupidi 32a1cf23380e80e781d6d1d82c193d33.md

```md
# Il paradosso di Russell spiegato agli stupidi

**Allora.**

Abbiamo un insieme **'S'**

Questo insieme **S** ha una regola: *"contiene tutti gli insiemi che non contengono se stessi"*.

**Chiariamo, inizialmente, cosa vuol dire "Insieme che contiene se stesso"**

- **Un insieme che non contiene se stesso**, è l'insieme Mela.
    
    L'insieme Mela contiene tutte le mele esistenti: mela rossa, mela gialla, mela verde, mela dolce, mela aspra, ecc..
    
    Ma l'insieme non è una mela, è solo un insieme, di cosa? Di mele. Quindi non può "auto-contenersi".
    
- **Un insieme che contiene se stesso**, è l'insieme "Insiemi".
    
    L'insieme Insiemi contiene tutti gli insiemi esistenti: l'insieme delle mele, l'insieme delle università, l'insieme delle bandiere, ecc...
    
    Questo insieme, dovrebbe contenersi, perché anche lui è un insieme, ma non può esistere. Perché: chi contiene questo insieme? Quindi è un insieme che si risucchia, come una scatola piena di scatole infinite: ma la scatola in sé dove sta? E' una specie di buco nero che si risucchia in continuazione. Quindi esiste e non esiste contemporaneamente.
    

---

**Torniamo alla nostra domanda: S appartiene ad S?**

Ricordiamoci la regola *"S contiene tutti gli insiemi che non contengono se stessi"*, tipo l'insieme Mela di prima.

Da qui arriviamo a 2 casi.

- **Caso 1: S appartiene ad S.**
    
    Vuol dire che S è un insieme che **contiene se stesso**. Allora S **non può** stare dentro S, perché la regola dice che S contiene solo insiemi che **non** contengono se stessi.
    
    Ed ecco la contraddizione del paradosso.
    
- **Caso 2: S NON appartiene ad S.**
    
    Vuol dire che S è un insieme che **non** contiene se stesso, e noi NON lo mettiamo dentro S.
    
    Ora se S non è dentro S ci rifacciamo la domanda rifacendoci alla regola: S contiene solo gli insiemi che non contengono se stessi. Ma allora S **dovrebbe** starci, perché non sta contenendo se stesso, e quindi rispetta la regola.
    
    Ed ecco la seconda contraddizione.
    

---

**Allora.**

Abbiamo visto che il paradosso nasce perché abbiamo fatto un insieme S con questa regola: *"contiene tutti gli insiemi che non contengono se stessi"*.

Il problema è che abbiamo preso **"tutti"** gli insiemi con una certa proprietà. È stato proprio quel **"tutti"** a creare il pasticcio, perché S finiva per parlare di se stesso e generava la contraddizione.

---

**Come si risolve?**

I matematici hanno detto: non possiamo permettere che un insieme venga definito prendendo **"tutti"** gli insiemi che hanno una certa proprietà. È troppo pericoloso, perché così si possono creare mostri come S che si auto-distruggono.

Allora hanno stabilito una regola nuova: **per costruire un insieme nuovo, dobbiamo sempre partire da un insieme che già esiste**. Così possiamo solo "filtrare" gli elementi di quell'insieme usando una proprietà.

**Facciamo un esempio.**

Se ho già un insieme **U** che conosco (per esempio, l'insieme di tutti gli studenti della mia scuola), allora posso costruire un insieme nuovo dicendo: *"l'insieme degli studenti di U che hanno i capelli biondi"*. Questo è sicuro, perché non sto prendendo "tutti" gli studenti del mondo, ma solo quelli che stanno dentro U.

---

**U e S sono due cose diverse**

- **U** è l'insieme di partenza, quello che già conosciamo e che esiste prima.
- **S** è l'insieme che costruiamo **dentro** U, filtrando i suoi elementi con una proprietà. Quindi S è un **sottoinsieme** di U.

**Applicando questa idea al paradosso**, invece di definire S come *"l'insieme di tutti gli insiemi che non contengono se stessi"*, lo definiamo così:

> **S = { A : A ⊆ U, e A ∉ A }**
> 

Cioè: **S** è l'insieme degli insiemi **A** che stanno dentro **U** e che **non contengono se stessi**.

**A** è un insieme qualsiasi che sta dentro **U**.

**S** è il gruppo di quegli **A** che hanno la proprietà *"non contenere se stessi"*.

**Quindi:**

- **U** è un insieme "grande" che abbiamo scelto all'inizio.
- **S** è un insieme più piccolo, fatto solo da **alcuni** sottoinsiemi di **U**.

**S non è uguale a U**. U contiene cose (insiemi), S è uno di quei sottoinsiemi.

---

**Perché non si ripete il paradosso?**

Perché **S non contiene "tutti" gli insiemi del mondo**, ma solo quelli che stanno dentro **U**.

Se provo a chiedere *"S appartiene a S?"*, non succede più niente di strano.

- Se **S non sta dentro U**, allora la domanda **"S ∈ S?"** non si pone nemmeno.
- Se invece **S sta dentro U**, allora si può rispondere senza contraddizione, perché S non è più un insieme mostruoso che contiene tutto.

---

**In altre parole, la soluzione è questa:**

Vietiamo di fare insiemi con **"tutti"** gli oggetti che hanno una proprietà. Permettiamo solo di fare insiemi **partendo da un insieme già esistente**.

- **U** è il *"contenitore sicuro"* che usiamo come punto di partenza.
- **S** è un **sottoinsieme** di U, non è U stesso.

Così evitiamo che S diventi un mostro che parla di tutti gli insiemi del mondo.

**Il paradosso di Russell non può più nascere.**
```

## 7. Esempi (Esercizi svolti con Google AI) (1) 32f1cf23380e805fb97cc36a9ec0b5fd.md

```md
# Esempi (Esercizi svolti con Google AI) (1)

![image.png](Esempi%20(Esercizi%20svolti%20con%20Google%20AI)%20(1)/image.png)

![image.png](Esempi%20(Esercizi%20svolti%20con%20Google%20AI)%20(1)/image%201.png)

![image.png](Esempi%20(Esercizi%20svolti%20con%20Google%20AI)%20(1)/image%202.png)

![image.png](Esempi%20(Esercizi%20svolti%20con%20Google%20AI)%20(1)/image%203.png)

![image.png](Esempi%20(Esercizi%20svolti%20con%20Google%20AI)%20(1)/image%204.png)
```

## 8. Equivalenza Esercizi (1) 32f1cf23380e80f98850de637bd0e4af.md

```md
# Equivalenza: Esercizi (1)

Verificare che se si considerano i valori numerici 1 per vero e 0 per falso, e assegnati tali valori numerici alle variabili proposizionali p e q abbiamo che:

1. $\neg p \equiv 1 - p$
2. $p \vee q \equiv max(p,q)$
3. $p \land q \equiv min(p,q)$
4. $p \implies q = max(1-p,q)$
5. $p \iff q = min(max(1-p,q),max(p,1-q))$

---

Ho impostato V = 1 e F = 0

1. $\neg p \equiv 1 - p$
se p = 1, allora $\neg p = 0 \rightarrow 0 \equiv 1 - 1 \rightarrow 0 \equiv 0$ ✅
se p = 0, allora $\neg p = 1 \rightarrow 1 \equiv 1- 0 \rightarrow 1 \equiv 1$ ✅
2. $p \vee q \equiv max(p,q)$
se p = 0 e q = 0, allora $\rightarrow 0 \vee 0 \equiv max(0,0) \rightarrow 0 \equiv 0$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \vee 1 \equiv max(0,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \vee 1 \equiv max(1,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \vee 0 \equiv max(1,0) \rightarrow 1 \equiv 1$ ✅
3. $p \land q \equiv min(p,q)$
se p = 0 e q = 0, allora $\rightarrow 0 \land 0 \equiv min(0,0) \rightarrow 0 \equiv 0$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \land 1 \equiv min(0,1) \rightarrow 0 \equiv 0$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \land 1 \equiv min(1,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \land 0 \equiv min(1,0) \rightarrow 0 \equiv 0$ ✅
4. $p \implies q = max(1-p,q)$
se p = 0 e q = 0, allora $\rightarrow 0 \implies 0 \equiv max(1-0,0) \rightarrow 1 \equiv 1$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \implies 1 \equiv max(1-0,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \implies 1 \equiv max(1-1,1) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \implies 0 \equiv max(1-1,0) \rightarrow 0 \equiv 0$ ✅
5. $p \iff q = min(max(1-p,q),max(p,1-q))$
se p = 0 e q = 0, allora $\rightarrow 0 \iff 0 \equiv min(max(1,0),max(0,1)) \rightarrow 1 \equiv 1$ ✅
se p = 0 e q = 1, allora $\rightarrow 0 \iff 1 \equiv min(max(1,1),max(0,0)) \rightarrow 0 \equiv 0$ ✅
se p = 1 e q = 1, allora $\rightarrow 1 \iff 1 \equiv min(max(0,1),max(1,0)) \rightarrow 1 \equiv 1$ ✅
se p = 1 e q = 0, allora $\rightarrow 1 \iff 0 \equiv min(max(0,0),max(1,1)) \rightarrow 0 \equiv 0$ ✅
```

## 9. Tavole di verità Esercizi (1) 32f1cf23380e8053a856c78dc76f4428.md

```md
# Tavole di verità: Esercizi (1)

Costruisci le Tavole di Verità delle seguenti formule:

- $p \land q \land (r \vee s)$
- $p \vee q \vee (r \land s)$
- $p \land (q \vee (s \land ( \neg p \vee \neg q)))$
- $((p \vee \neg q \vee r) \land s) \vee t$

---

1. $p \land q \land (r \vee s)$
    
    
    | $p$ | $q$ | $r$ | $s$ | $r \vee s$ | $q \land (r \vee s)$ | $p \land q \land (r \vee s)$ |
    | --- | --- | --- | --- | --- | --- | --- |
    | V | V | V | V | V | V | V |
    | V | V | V | F | V | V | V |
    | V | V | F | V | V | V | V |
    | V | V | F | F | F | F | F |
    | V | F | V | V | V | F | F |
    | V | F | V | F | V | V | V |
    | V | F | F | V | V | F | F |
    | V | F | F | F | F | F | F |
    | F | V | V | V | V | V | F |
    | F | V | V | F | V | V | F |
    | F | V | F | V | V | V | F |
    | F | V | F | F | F | F | F |
    | F | F | V | V | V | F | F |
    | F | F | V | F | V | F | F |
    | F | F | F | V | V | F | F |
    | F | F | F | F | F | F | F |
2. $p \vee q \vee (r \land s)$
    
    
    | $p$ | $q$ | $r$ | $s$ | $r \land s$ | $q \vee (r \land s)$ | $p \vee q \vee (r \land s)$ |
    | --- | --- | --- | --- | --- | --- | --- |
    | V | V | V | V | V | V | V |
    | V | V | V | F | F | V | V |
    | V | V | F | V | F | V | V |
    | V | V | F | F | F | V | V |
    | V | F | V | V | V | V | V |
    | V | F | V | F | F | F | V |
    | V | F | F | V | F | F | V |
    | V | F | F | F | F | F | V |
    | F | V | V | V | V | V | V |
    | F | V | V | F | F | V | V |
    | F | V | F | V | F | V | V |
    | F | V | F | F | F | V | V |
    | F | F | V | V | V | V | F |
    | F | F | V | F | F | F | F |
    | F | F | F | V | F | F | F |
    | F | F | F | F | F | F | F |
3. $p \land (q \vee (s \land ( \neg p \vee \neg q)))$
    
    
    | $p$ | $\neg p$ | $q$ | $\neg q$ | $s$ | $( \neg p \vee \neg q)$ | $(s \land ( \neg p \vee \neg q)$ | $q \vee (s \land ( \neg p \vee \neg q))$ | $p \land (q \vee (s \land ( \neg p \vee \neg q)))$ |
    | --- | --- | --- | --- | --- | --- | --- | --- | --- |
    | V | F | V | F | V | F | F | V | V |
    | V | F | V | F | F | F | F | V | V |
    | V | F | F | V | V | V | V | V | V |
    | V | F | F | V | F | V | F | F | F |
    | F | V | V | F | V | V | V | V | V |
    | F | V | V | F | F | V | F | V | V |
    | F | V | F | V | V | V | V | V | V |
    | F | V | F | V | F | V | F | F | F |
4. $((p \vee \neg q \vee r) \land s) \vee t$
    
    
    | $p$ | $\neg q$ | $r$ | $s$ | $t$ | $(p \vee \neg q \vee r)$ | $((p \vee \neg q \vee r) \land s)$ | $((p \vee \neg q \vee r) \land s) \vee t$ |
    | --- | --- | --- | --- | --- | --- | --- | --- |
    | V | V | V | V | V | V | V | V |
    | V | V | V | V | F | V | V | V |
    | V | V | V | F | V | V | F | V |
    | V | V | V | F | F | V | F | F |
    | V | V | F | V | V | F | F | V |
    | V | V | F | V | F | F | F | F |
    | V | V | F | F | V | F | F | V |
    | V | V | F | F | F | F | F | F |
    | V | V | V | V | V | V | V | V |
    | V | F | V | V | F | F | F | F |
    | V | F | V | F | V | F | F | V |
    | V | F | V | F | F | F | F | F |
    | V | F | F | V | V | F | F | V |
    | V | F | F | V | F | F | F | F |
    | V | F | F | F | V | F | F | V |
    | V | F | F | F | F | F | F | F |
    | F | F | V | V | V | F | F | V |
    | F | F | V | V | F | F | F | F |
    | F | V | V | F | V | F | F | V |
    | F | V | V | F | F | F | F | F |
    | F | V | F | V | V | F | F | V |
    | F | V | F | V | F | F | F | F |
    | F | V | F | F | V | F | F | V |
    | F | V | F | F | F | F | F | F |
    | F | V | V | V | V | F | F | V |
    | F | V | V | V | F | F | F | F |
    | F | F | V | F | V | F | F | V |
    | F | F | V | F | F | F | F | F |
    | F | F | F | V | V | F | F | V |
    | F | F | F | V | F | F | F | F |
    | F | F | F | F | V | F | F | V |
    | F | F | F | F | F | F | F | F |
```
