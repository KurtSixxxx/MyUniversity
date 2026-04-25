# Automi a Stati Finiti Deterministici (ASFD)

*Dal PDF "Fondamenti di Informatica - Salvo Polizzi", da pag 19...*

## Definizione e Caratteristiche

Gli **automi ASFD** hanno la caratteristica di poter solo avanzare, o meglio, la testina può solo leggere e muovere solo verso destra: niente scrittura, niente ritorno su input già letti.
Per definizione un ASFD è una quintupla:

- **Σ** è l'alfabeto in input (finito)
- **Q** è l'insieme di stati finiti
- **δ** è la funzione di transizione, che in particolare sarebbe: $δ : Q × Σ → Q$ 
  Questa funzione si legge come: delta è una funzione che dato uno stato $q ∈ Q$ e un simbolo $a ∈ Σ$ restituisce un nuovo stato. Dunque il nuovo stato in cui andare.
- **q0** è lo stato iniziale, da cui inizia la computazione
- **F**, ossia l'insieme degli stati finali. Gli stati finali, ricordiamolo, sono gli stati in cui si arriva se una stringa è accettata, ma non quelli in cui finisce la computazione.
  *La **computazione** sarebbe il "calcolo" della stringa, ossia la verifica di appartenenza o meno al linguaggio della stringa presa in esame*

La funzione di transizione "δ" è detta totale perché tramite essa conosciamo tutte le coppie stato-simbolo; ad ogni coppia stato-simbolo corrisponde uno e un solo stato. Non esiste indecisione o dubbi.

## Rappresentazioni di un ASFD

### Tabella di Transizione

Dato un automa a stati finiti, si può costruire una **Tabella di Transizione**, che mostra le transizione da uno stato all'altro dell'automa durante la computazione di accettazione della stringa.
Ad esempio, dato l'automa $A = < Σ = {a, b}, Q = {q0, q1, q2}, δ, q0, F = {q1} >$
Intanto capiamo che:
L'alfabeto $Σ$ contiene i simboli $a$ e $b$.
Gli stati sono $q0$, $q1$, $q2$.
$δ$ è la funzione di transizione: dice come si passa da uno stato all'altro leggendo i simboli.
Lo stato iniziale è $q0$.
L'unico stato finale (accettante) è $q1$.

Possiamo costruire una tabella da questa quintupla contente i dati necessari, la quale sarebbe:

| **δ** | a   | b   |
| ----- | --- | --- |
| q0    | q0  | q1  |
| q1    | q2  | q2  |
| q2    | q2  | q2  |

### Diagramma di Stato

<img src="file:///C:/Users/giuli/Pictures/Screenshots/Screenshot%202025-05-20%20181737.png" title="" alt="Screenshot 2025-05-20 181737.png" width="620">

Un altro modo, oltre alla tabella, per rappresentare graficamente un automa è il **diagramma di stato**; ossia un grafo che ha:

- I **nodi**, che indicano lo stato; in particolare: lo stato iniziale q0 ha una freccia entrante nel nodo (per poter indicare che è lo stato da cui parte la computazione; e lo stato finale che viene rappresentato da un doppio cerchio
- Gli **archi**, (delle frecce, o dei cappi) che indicano la transizione. Per questo motivo sono etichettati con un simbolo che determina lo stato di transizione

## Computazione di un ASFD

Supponiamo di avere la seguente stringa $x$ nel nastro:

<img title="" src="file:///C:/Users/giuli/Pictures/Screenshots/Screenshot%202025-05-20%20182431.png" alt="Screenshot 2025-05-20 182431.png" data-align="center" width="190">

In base alla funzione di transizione abbiamo visto che durante la computazione si scorre la stringa, fino a che l'automa si accorgerà di aver trovato un carattere $B$, che indica la fine della stringa.
$B$ = *blank* = simbolo speciale sul nastro (spazio vuoto, fine stringa). Serve a dire: "qui finisce la parte utile della stringa".
Una volta trovato tale carattere la computazione termina. Per sapere se la stringa è accettata o meno si guarda lo stato:

- Se $q_n \in F$, ovvero lo stato appartiene all'insieme degli stati finali, dunque la stringa è **accettata**.

- Se $q_n \notin F$, ovvero lo stato **non** appartiene all'insieme degli stati finali, dunque la stringa **non è accettata**.

## Configurazioni degli Automi a Stati Finiti

Vediamo quli sono i tipi di configurazione nel quale si può trovare l'automa.

> Definizione: Dato un ASFD $A =< Σ, Q, δ, q0, F >$ una configurazione di
> A è una coppia $(q, x)$ con $q ∈ Q$ e $x ∈ Σ^*$

Ricordiamo innanzitutto che una **configurazione** rappresenta una "fotografia" dell'automa in un dato momento: mostra **in quale stato si trova**, **che simboli ci sono sul nastro** e **dove si trova la testina di lettura/scrittura**. Quindi una **configurazione** rappresenta **dove sei** nell'automa **mentre leggi una stringa**.

Una configurazione ha la forma:

$$
(q,x)
$$

- $q$ è lo stato attuale dell'automa

- $x$ è la parte di stringa ancora da leggere

Nella definizione scritta sopra, stiamo dicendo che dato un automa (con la sua quintupla), una configurazione è la coppia stato-simbolo. Ovviamente con lo stato appartente all'insieme degli stati finiti e il simbolo appartenente all'insieme delle stringhe.

> Da questo momento in poi useremo una convenzione sui linguaggi formali:
> 
> - Le lettere $(a, b, c)$ indicano i simboli dell'alfabeto.
> 
> - Le lettere $x, y, z$ indicano invece le stringhe.

Ad ogni modo,
poichè $x \in \Sigma^*$, una configurazione può anche essere la coppia $(q, \epsilon)$, dato che $\epsilon$ fa parte dell'insieme delle stringhe, in quanto stringa vuota. Per questo motivo, la coppia $(q, \epsilon)$ corrisponde nel nastro al carattere di *blank* $B$.
Vediamo alcuni tipi particolari di configurazioni:

Una configurazione $(q, x)$ con $q \in Q$, $x \in \Sigma^*$ è detta:

- **Iniziale** se $q = q_0$. Vuol dire che se nella coppia lo stato $q$ è uguale a $q_0$ significa che ci troviamo nello stato iniziale. Quinid abbiamo una configurazione iniziale.

- **Finale** se $x = \epsilon$. Vuol dire che se nella coppia la stringa $x$ è una stringa vuota $\epsilon$ ci troviamo con un carattere *blank*. Questo significa fine della computazione.

- **Accettante** se $q \in F$ e $x = \epsilon$. Vuol dire che se nella coppia lo stato fa parte dell'insieme degli stati finali $F$ e la stringa è una stringa vuota $\epsilon$ allora la configurazione indica che la stringa è stata accettata.
  
  E' importante ribadire che il fatto che $q$ appartenga ad $F$ non implica che la computazione termini, infatti la condizione per cui la computazione termini è che si trovi un carattere di $B$, ovvero ci troviamo in una configurazione finale $(q, ε)$.

## Configurazione Successiva e Relazioni fra Configurazioni

Affinché la computazione termini è fondamentale comprendere la relazione fra configurazione e il concetto di configurazione successiva. Proprio per capire quando inizia una computazione e quando ne termina un'altra.

> Definizione: Dato un ASFD $A = < \Sigma, Q, δ, q_0, F >$ e due configurazioni $(q,x)$ e $(q',y)$ avremo che la configurazione $(q',y)$ è successiva a $(q,x)$ e scriveremo $(q,x)  ⊢_A (q', y)$ se valgono le seguenti condizioni:
> 
> - $∃a \in \Sigma \space \text{tale che} \space x = ay$
> 
> - $δ(q,a) = q'$

**Cosa dice la definizone:**

Hai due configurazioni:

- una iniziale $(q,x)$

- una che viene subito dopo: $(q', y)$
  
  Allora diciamo che:
  
  $$
  (q,x) ⊢ (q',y)
  $$

Si legge: **"(q', y) è successiva a (q, x)"**  
(dove il simbolo ⊢ si legge: "produce", oppure "porta a")

Cosa significano i punti elencati:

1. $x = ay$
   Significa che la stringa $x$ **inizia con un simbolo** $a$, seguito dalla stringa $y$.  
   In altre parole: $x$ è fatta così: prima una lettera, poi il resto.

2. $δ(q,a) = q'$
   Se sei nello stato $q$ e leggi il simbolo $a$, la funzione di transizione ti dice che devi andare nello stato $q'$

### Tradotto in parole

Sei nello stato $q$ e davanti a te hai la stringa $x$.  
Se $x$ inizia con un simbolo $a$, e la funzione di transizione dice che leggendo $a$ da stato $q$ passi a $q'$,  
allora la nuova configurazione sarà $q'$, con la stringa rimanente $y$ da leggere.

### Pensa...

- Qual è il primo simbolo della stringa?  
- In che stato sei?  
- Dove ti porta la funzione di transizione?  
- Quale sarà la stringa rimanente?

### Esercizio di verifica

**Automa dato**  

- $Q = \{q_0, q1\}$ 
- $\Sigma = \{a, b\}$
- $\delta(q_0, a) = q_1$
- $\delta(q_1, b) = q_1$

**Configurazione iniziale**  
$(q_0,abb)$

**Domanda**  
Qual è la configurazione successiva?

**Soluzione**  
$(q_0,abb)\vdash(q_1,bb)$

> - La stringa $abb$ inizia con $a$ → resto $bb$  
> - $\delta(q_0,a) = q_1$  
> - Risultato: $(q_1, bb)$

## Chiusura Riflessiva e Transitiva della relazione ⊢

Ricordiamo che ⊢ si legge "porta a" o "produce".

Esempio: $(q_0,abb)\vdash(q_1,bb)$, vuol dire: "se sono nello stato $q_0$ e ho davanti la stringa $abb$, dopo **un passo** vado in $(q_1, bb)$".

$\vdash^*_A$ si chiama "chiusura riflessiva di $\vdash$"

Vuol dire:

- Posso andare da una configurazione $(q, x)$ a un'altra $(q', y)$ **in 0 o più passi**.

- Quindi:
  
  $(q,x)\vdash^*_A​(q′,y)$
  
  significa che:
  
  - **forse è la stessa configurazione** (0 passi)
  
  - oppure ci sono 1, 2, 3… $n$ passaggi

**Esempio:**  
Supponiamo che:

- $(q_0, abb) \vdash (q_1, bb)$

- $(q_1, bb) \vdash (q_1, b)$

- $(q_1, b) \vdash (q_1, \varepsilon)$

Allora possiamo scrivere:

$(q_0​,abb)\vdash^*_A(q_1​,ε)$

perché ho fatto **più passi**, ma usando ⊢*A li riassumo tutti insieme!

E anche:

$(q_0​,abb)\vdash^*_A​(q_0​,abb)$

perché $\vdash^*_A$ **include anche 0 passi** (cioè non mi muovo, sto fermo).

Mentre invece $\vdash^+_A​$ si chiama **<u>chiusura transitiva</u>** di $\vdash$

Vuol dire:

- Posso andare da una configurazione all'altra in **almeno 1 passo** (quindi 1 o più passi).

**Non** puoi scrivere:

$(q,x)\vdash^+_A​(q,x)$

perché **non c'è movimento** (non ho fatto nemmeno un passo).

Ma puoi scrivere:

$(q_0​,abb)\vdash^+_A​(q_1​,bb)$

oppure:

$(q_0​,abb)\vdash^+_A(q_1​,ε)$

(perché c'è almeno 1 passo fatto)

Ricapitolando:

| Simbolo      | Significato             | Passi           | Esempio valido ✅                 | Esempio non valido ❌       |
| ------------ | ----------------------- | --------------- | -------------------------------- | -------------------------- |
| $\vdash^*_A$ | Riflessiva e transitiva | $0$ o più passi | $(q, x) \vdash^*_A (q, x)$       | —                          |
| $\vdash^+_A$ | Solo transitiva         | $1$ o più passi | $(q_0, abb) \vdash^+_A (q_1, b)$ | $(q, x) \vdash^+_A (q, x)$ |

## Stringa Accettata e Linguaggio Riconosciuto

Capiamo cosa si intende per stringa accettata e linguaggio riconosciuto in un ASFD.

> Definizione: Dato un ASFD $A = < \Sigma, Q, δ, q_0, F > $ e $x \in \Sigma^*$, diciamo che $x$ è accettata da $A$ se e solo se $(q_0,x) \vdash^*_A$ con $q \in F$. Il linguaggio è riconosciuto dall'insieme:
> 
> $$
> L(A) = \{ x \in \Sigma^* | (q_0,x)\vdash^*_A (q, \epsilon) \space \text{con} \space q \in F \}
> $$

In parole povere ciò vuol dire:

Dato un automa ASFD con la stringa $x$ che appartiene all'insieme delle stringhe, diciamo che $x$ è accettata se si va da uno stato $(q_0,x)$ a uno stato $q$ (che appartiene all'insieme degli stati finali $F$) e con $\epsilon$ che è la stringa vuota (la quale inica la fine della computazione)

Dunque una stringa accettata da un ASFD che fa parte di un linguaggio $L$ fa parte dall'insieme:  $L(A) = \{ x \in \Sigma^* | (q_0,x)\vdash^*_A (q, \epsilon) \space \text{con} \space q \in F \}$

**Significato:**

Il linguaggio **accettato dall'automa A** è l'insieme di tutte le stringhe $x$ dell'alfabeto $\Sigma$ per cui:

- partendo dalla configurazione iniziale $(q_0, x)$

- si arriva in **uno stato finale** $q \in F$

- e **non resta nulla da leggere** (cioè la stringa diventa $\epsilon$)

Di conseguenza un **linguaggio riconosciuto** da un ASFD è l'insieme di **stringhe accettate dall'automa.**

**Esempio:** Utilizzando l'ASFD che ha tabella di transizione qui a sotto:

| $\delta$ | $a$   | $b$   |
|:--------:|:-----:|:-----:|
| $q_0$    | $q_0$ | $q_1$ |
| $q_1$    | $q_2$ | $q_2$ |
| $q_2$    | $q_2$ | $q_2$ |

Dimostriamo che:

$$
x = aab \in L(A)
$$

ovvero dobbiamo di mostrare che esiste un passaggio dalla configurazione $(q_0, aab)$ a una configurazione $(q_1, \epsilon)$ con un numero di passi $\ge \space 0$

<img title="" src="file:///C:/Users/giuli/Pictures/Screenshots/Screenshot%202025-05-21%20171632.png" alt="Screenshot 2025-05-21 171632.png" data-align="center">

dunque:

$$
(q_0,abb)\vdash_A (q_0,ab)\vdash_A(q_0,b)\vdash_A(q_1,\epsilon)
$$

quindi la stringa $x = aab \in L(A)$

Adesso dobbiamo porci una domanda: $\epsilon \in L(A)?$
A riguardo possiamo dire che:

$$
\epsilon \in L(A) \space \text{se e solo se} \space q_0 \in F
$$

#### **Dimostrazione:**

Quando un automa accetta la stringa vuota $\epsilon$?

Vogliamo dimostrare che:

> **`ε ∈ L(A)` se e solo se `q₀ ∈ F`**

Cioè: l'automa accetta la **stringa vuota** **se e solo se** lo **stato iniziale `q₀` è anche finale**.

#### Dimostrazione divisa in 2 parti

#### Parte 1 – Condizione Necessaria (⇒)

Supponiamo che **`ε ∈ L(A)`**.

- Allora esiste una derivazione:
  
  $$
  (q_0, \epsilon) \vdash^*_A (q, \epsilon)
  $$

- Per accettare la stringa vuota, devo **finire in uno stato finale**, cioè `q ∈ F`

- Ma non ho letto nulla (la stringa è vuota), quindi **non mi sono mai mosso** da `q₀`

- Quindi: `q = q₀` ⇒ **`q₀ ∈ F`**

Se `ε` è accettata, allora `q₀` deve essere uno stato finale.

#### Parte 2 – Condizione Sufficiente (⇐)

Supponiamo ora che **`q₀ ∈ F`**.

- Parto da `q₀` e la stringa da leggere è `ε`, quindi:
  
  $$
  (q_0, \epsilon) \vdash^*_A (q0, \epsilon)
  $$

- Non faccio nessun passo, ma mi trovo già in uno **stato finale**

- Quindi la stringa vuota è **accettata**

Se `q₀` è uno stato finale, allora `ε` è accettata.

#### Spiegazione del ragionamento sulle configurazioni

Quando scrivo una cosa come:

$$
(q_0, \epsilon) ⊢^*_A (q, \epsilon)
$$

Sto dicendo:

> "Parto dallo **stato iniziale** `q₀`, con la stringa `ε`, e dopo zero o più mosse arrivo in uno stato `q` con ancora `ε` da leggere."

Con `ε` però **non posso fare nessuna mossa**:

- non leggo simboli

- non mi sposto

- resto fermo in `q₀`

Quindi la derivazione vera è:

$$
(q_0, \epsilon) \vdash^*_A (q_0, \epsilon)
$$

Serve solo a dire: *“Sono già in una configurazione accettante senza fare nulla.”*

#### Riassunto del ragionamento logico

#### 1. Se `ε` è accettata:

- allora **esiste una derivazione** che parte da `q₀` e **finisce in uno stato finale**

- ma non si fa nessun passo ⇒ `q = q₀`

- quindi: `q₀ ∈ F`

#### 2. Se `q₀ ∈ F`:

- sono già in uno stato finale

- con la stringa vuota, non devo fare nulla

- quindi: `ε` è accettata

#### Conclusione intuitiva

L’automa accetta `ε` **se e solo se** lo **stato iniziale è uno stato finale**.  
Perché non si muove, e quindi deve **già** trovarsi in uno stato che accetta.

## Funzione di Transizione Estesa

Se $\delta : Q \times \Sigma \rightarrow Q$ è definita per le coppie stato-simbolo, la funzione di transizione estesa è definita per coppie **stato-stringa** e **restituisce lo stato a cui arriviamo dopo aver applicato $\delta$  ogni simbolo della stringa**. In particolare è definita come:

$$
\overline{\delta} : Q \times \Sigma^* \rightarrow Q
$$

Possiamo riprendere la precedente tabella di transizione per vedere come si applica la funzione di transizione estesa, calcolando $\overline{\delta}(q_0, aab):$

$$
\delta(q_0,a) = q_0 \rightarrow \delta(q_0,a) = q_0 \rightarrow \delta(q0,b) = q_1
$$

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-05-22-17-08-01-image.png" alt="" data-align="center">

> Definzione: La funzione di transizione estesa di ASFD $A = < \Sigma, Q, \delta, q_0, F >$ è la funzione $\overline{\delta}: Q \times \Sigma^* \rightarrow Q$.
> 
> Definita nel seguente modo:
> 
> - $\overline{\delta}(q, \epsilon) = q$, Se la stringa è vuota $(\epsilon)$, non cambi stato:
> 
> - Se la stringa è fatta da una parte $x$ (una stringa più corta) e un simbolo $a$ alla fine, prima vai dallo stato $q$ con $x$ (cioè calcoli $\overline{\delta}(q, x)$) e poi da lì leggi il simbolo $a$:
>   $\overline{\delta}(q, xa) = \delta(\overline{\delta}(q,x),a) \space \text{con} \space a \in \Sigma \space \text{e} \space x \in \Sigma^*$

**In poche parole:**

La funzione di transizione estesa serve per simulare un DFA su **intere stringhe**, passo passo, simbolo dopo simbolo.

**Quella formula dice**:

$$
\overline{\delta}(q, xa) = \delta(\overline{\delta}(q, x), a)
$$

* Qui, $q$ è lo stato da cui parti.  
* $xa$ è la stringa da leggere, fatta da una parte $x$ (una **stringa più corta**) e un simbolo $a$ alla fine.  
* $\overline{\delta}(q, x)$ significa: "da $q$, leggo tutta la stringa $x$" — quindi arrivo in uno stato nuovo.  
* Poi, da quello stato nuovo, leggo il simbolo $a$ (con la funzione $\delta$).

#### Un esempio con numeri e lettere

Prendi questa stringa: "ab"

* $x = a$ (stringa più corta)  
* $a = b$ (ultimo simbolo)

Calcolo $\overline{\delta}(q_0, ab)$:

1. Calcolo prima $\overline{\delta}(q_0, a)$ — cioè, da $q_0$, leggo "a".  
   Supponiamo $\overline{\delta}(q_0, a) = q_1$.  
2. Poi da $q_1$ leggo il simbolo $b$ con $\delta$:  
   $\delta(q_1, b) = q_2$.

Quindi

$$
\overline{\delta}(q_0, ab) = q_2
$$

---

# Automi a Stati Finiti Non Deterministici

Gli **automi deterministici** hanno la caratteristica che ogni configurazione ammette, per ogni coppia stato-simbolo, uno e un solo stato; ovvero, o abbiamo una configurazione successiva o altrimenti non l'abbiamo e la computazione termina. Come ad esempio nel caso di una configurazione del tipo $(q, \epsilon)$, in cui la computazione termina.

Parlando invece di automi non deterministici essi sono chiamati così poiché possono ammettere più configurazioni successive.

La differenza principale tra automi deterministici e automi non deterministici sta nella funzione di transizione, che viene chiamata $\delta_n$ e assume questa forma:

$$
\delta_n : Q \times \Sigma \rightarrow Pow(Q)
$$

Dove $Pow(Q)$ rappresenta l'insieme della parti di $Q$, ovvero l'insieme di stati, come ad esempio $Pow(Q) = \{q_0, q_1\}, \{q_1,q_2\}$ ecc...

Per l'insieme delle parti di Q si intende un insieme i cui elementi sono anch'essi sottoinsiemi dell'insieme Q.

> Definizione: Un Automa a Stati Finiti Non Deterministici (ASFND) A_N è una quintupla $A_n = < \Sigma, Q, \delta_n, q_0, F >$ dove:
> 
> - $\Sigma$ è l'alfabeto in input (finito)
> - $Q$ è l'insieme di stati finiti
> - $\delta_N$ è la funzione di transizione, che in particolare sarebbe: $\delta_n : Q \times \Sigma \rightarrow Pow(Q) $
>   Dove $Pow(Q)$ è l'insieme delle parti di $Q$
>   Questa funzione si legge come: delta è una funzione che dato uno stato $q ∈ Q$ e un simbolo $a ∈ Σ$ restituisce un nuovo stato. Dunque il nuovo stato in cui andare.
> - $q_0 \in Q$ è lo stato iniziale, da cui inizia la computazione
> - $F \subseteq Q$, ossia l'insieme degli stati finali. Gli stati finali, ricordiamolo, sono gli stati in cui si arriva se una stringa è accettata, ma non quelli in cui finisce la computazione.
>   La **computazione** sarebbe il "calcolo" della stringa, ossia la verifica di appartenenza o meno al linguaggio della stringa presa in esame

Gli ASFD e gli ASFND, a livello di capacitò di riconoscimento, sono perfettamente equivalenti, ovvero che con entrambi riusciamo a riconoscere gli stessi linguaggi. L'unica peculiarità, che è quella che conta, è che riescono a riconoscere certe classi di linguaggi, ovvero quelli dove è possibile avere diversce scelte di computazione piuttosto che una univoca.

**Esempio**: Dato l'alfabeto $ \Sigma = \{a,b\}$, vogliamo costruire un automa che riconosca le stringhe che abbiano b come penultimo carattere, considerando che $Q = \{q_0,q_1,q_2\}, F = \{q_2\}$.

Come prima cosa, costuriamo la tabella di transizione richiesta dall'esercizio.

| $\delta_n$ | $a$         | $b$         |
| ---------- | ----------- | ----------- |
| $q_0$      | $\{q_0\}$   | $\{q0,q1\}$ |
| $q_1$      | $\{q_2\}$   | $\{q_2\}$   |
| $q_2$      | $\emptyset$ | $\emptyset$ |

Tale funzione di transizone è quella di un ASFND, ci permette molto facilmente di riconoscere stringhe che abbiano b come penultimo carattere. Se avessimo dovuto creare in un automa deterministico con tali caratteristiche sarebbe stato parecchio più complesso.

Come abbiamo detto precedentemente, gl ASFD hanno la funzione di transizione totale, ossia che restituisce uno e un solo stato per ogni coppia stato-simbolo. Invece, per gli ASFND, la funzione **non è** sempre **totale**. Ovvero non è sempre definita per tutte le coppie di stato-simbolo. Questo però non implica che la computazione termini, perché stiamo parlando comunque di automi a stati finiti, che hanno la testina che si muove soltato verso destra con stringhe di lunghezza finita. Riprendendo l'esempio, e dunque la tabella, abbiamo che se mi trovo nel caso i cui $\delta(q_2,a)=\emptyset$, allora in quel caso la computazione termina.

### Computazione di un ASFND

Come detto in precedenza, la computazione di un ASFND è di tipo non deterministico. Ciò vuol dire che per ogni coppia stato-simbolo corrisponde un insieme di stati, e non uno solo. Per questo motivo si formerà un albero di computazione per tutte le possibili scelte per ogni caso. Se, almeno uno dei possibili alberi ha una computazione del tipo:

$$
(q_0,x)\vdash^*(q,\epsilon)\space\text{con}\space q \in F
$$

allora la **stringa** è **accettata**.

<img src="file:///C:/Users/giuli/Pictures/Screenshots/Screenshot%202025-05-23%20095015.png" title="" alt="Screenshot 2025-05-23 095015.png" data-align="center">

**Esempio**. Prendiamo in considerazione l'automa che ha il seguente diagramma di stati:

Data la stringa $x = bba$, vogliamo vedere se tale stringa è accettata dall'automa.

**Risoluzione**. Analizziamo tutti i possibili alberi di computazione:

![Screenshot 2025-05-23 095226.png](C:\Users\giuli\Pictures\Screenshots\Screenshot%202025-05-23%20095226.png)

Come possiamo notare, poichè tra tutte le possibili computazioni vi è una con-
figurazione $(q_3, \epsilon)$, con $q_3 \in F$, allora possiamo dire che **$x = bba$** è accettata
dall’automa.

### Configurazioni Successive e Linguaggi Riconosciuto da un ASFND

Negli ASFND le configurazioni successive possono essere più di una. Se avessimo due configurazioni successive del tipo:

$$
(q_0,bb)\vdash_{A_N} (q_0,b)
\\
(q_0,bb)\vdash_{A_N} (q_1,b)
$$

la notazione più compatta per le configurazioni successive è la seguente:

$$
(\{q_0\},bb)\vdash_{A_N} \space (\{q_0,q_1\},b)
$$

Ovvero partendo dall'insieme di stati $\{q_0\}$, le possibili configurazini successive sono raffigurate dall'insieme di stati $\{q_0,q_1\}$. Ovviamente possiamo avere anche una situazione di questo tipo:

$$
(\{q_0,q_1\},b)\vdash_{A_N}(\{q_0,q_1,q_2\},\epsilon)
$$

Quindi utilizzando la chisura riflessiva, possiamo dire che in un numero di passi maggiore o uguale a $0$:

> Definizone. Sia $A_N = < \Sigma, Q, \delta_n, q_0, F>  $ ASFND. Il linguaggio rionosciuto è così definito:
> 
> $L(A_N) = \{ x \in \Sigma^* | (\{q_0\}, x) \vdash^*_{A_N} (T, \epsilon),
> \\
> \text{con } T \in \text{Pow}(Q) \text{ e } T \cap F \neq \emptyset \}$
