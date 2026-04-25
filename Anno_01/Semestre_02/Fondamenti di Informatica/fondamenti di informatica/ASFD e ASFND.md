# ASFD & ASFND

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

Un **ASFND** (Automa a Stati Finiti Non Deterministico) può, a differenza di quello deterministico, **fare più scelte** in base allo stesso stato e simbolo.

Esempio base:
Se siamo nello stato $q_0$ e leggiamo la stringa $bb$, potremmo avere due possibilità:

$$
(q_0, bb) \vdash (q_0, b) \quad \text{→ resto in $q_0$}
\\
(q_0, bb) \vdash (q_1, b) \quad \text{→ vado in $q_1$}
$$

Cioè leggendo $b$, posso **restare** in $q_0$ oppure andare in $q_1$.

Per semplificare, scriviamo tutto scriviamo in notazione più compatta per le configurazioni successive:

$$
(\{q_0\},bb)\vdash_{A_N} \space (\{q_0,q_1\},b)
$$

Se parto dallo stato $q_0$ e leggo $b$, posso trovarmi in uno dei due stati: $q_0$ o $q_1$. Quindi considero entrambi.

Ora immagina di partire già da più stati, ad esempio $\{q_0, q_1\}$ e leggere $b$. Potrei finire anche in altri stati, tipo $q_2$.

$$
(\{q_0,q_1\},b)\vdash_{A_N}(\{q_0,q_1,q_2\},\epsilon)
$$

Significa che, leggendo $b$, posso andare in uno qualunque di questi tre stati e avere la stringa vuota $(\epsilon)$ da leggere

Quindi utilizzando la chiusura riflessiva, possiamo dire che in un numero di passi maggiore o uguale a $0$.
Quando diciamo che **una stringa è accettata** da un ASFND, intendiamo:

“Partendo dallo stato iniziale $q_0$, leggo tutta la stringa $x$, e alla fine mi trovo in **almeno uno** stato finale”.

> Definizione. Sia $A_N = < \Sigma, Q, \delta_n, q_0, F>  $ ASFND. Il linguaggio riconosciuto è così definito:
> 
> $L(A_N) = \{ x \in \Sigma^* | (\{q_0\}, x) \vdash^*_{A_N} (T, \epsilon),
> \\
> \text{con } T \in \text{Pow}(Q) \text{ e } T \cap F \neq \emptyset \}$

Tradotto:

$x \in \Sigma^* \text{→ x}$ è una stringa qualsiasi.

$(\{q_0\}, x) \vdash^* (T, \epsilon)$ → partendo da $q_0$ e leggendo $x$, arrivo in un insieme di stati $T$ e non mi resta più nulla da leggere ($\epsilon$).

$T \cap F \neq \emptyset$ → almeno uno di questi stati è finale.

Quindi in zero o più passi dobbiamo arrivare alla configurazione $(T, \epsilon)$, dove T appartiene all'insieme delle parti di Q, ossia è un insieme di stati. E propri

**In parole povere:**

**Una stringa è accettata** se:

- Leggo tutta la stringa

- Parto da $q_0$

- Posso finire in **uno qualunque** degli stati finali (non importa quanti passaggi faccio)

### Funzione di Transizione Estesa di un ASFND

La funzione di transizione "normale" ($\delta_n$) ti dice:

"Se sono nello stato $q$ e leggo il simbolo $a$, dove posso andare?"

Ma cosa succede invece se invece di leggere un solo simbolo, devo leggere una stringa intera?

Per esempio: invece di "a" devo leggere "aba"?
Serve qualcosa che ti dica:

"Se sono in q e leggo tutta la stringa aba, in quali stati potrei trovarmi alla fine?"

Ecco che quindi ci serve la funzione di transizone estesa, scritta così:

$$
\overline{\delta}_N(q, stringa)
$$

La definizione di transizione estesa di un ASFND è leggermente diversa rispetto a quella vista per gli ASFD, ma in realtà rispecchia esattamente quanto visto nella definzione precedente di fuznione di transizione estesa per gli ASFD.

> Definizione. Sia $A_N = < \Sigma, Q, \delta_n, q_0, F >$ un ASFND. La funzione di transizione estesa
> 
> $$
> \overline{\delta}_N : Q \times \Sigma^* \rightarrow Pow(Q)
> $$

è così definita:

- **Caso base (stringa vuota $\epsilon$)**
  "Se non leggo nulla ($\epsilon$), resto fermo dove sono."
  Formalmente:
  $\overline{\delta}_N(q,\epsilon) = \{q\} \\ \text{con }\forall q \in Q$
  Se sono in $q_0$ e non leggo nulla:
  $\overline{\delta}_N(q_0, \epsilon) = \{q_0\}$

- **Caso generale**
  $x$ è una **stringa** di simboli (es. "$abba$", "$\epsilon$")

- $a$ è un **singolo simbolo** dell'alfabeto (es. "$a$", "$b$")

La definizione:

$\bar{\delta}_{N}(q, x a)=\bigcup_{p \in \bar{\delta}_{N}(q, x)} \delta_{N}(p, a) \quad \forall q \in Q, a \in \Sigma, x \in \Sigma^{*}$

vuol dire:

1. **Leggo tutta la stringa $x$** partendo da $q$ → ottengo un **insieme di stati** (perché l'automa è non deterministico).

2. **Da ogni stato** in quell'insieme, vedo **dove posso andare** leggendo il simbolo $a$.

3. **Unisco tutti gli stati** in cui posso arrivare → questo è il risultato di $\overline{\delta}_{N}(q, xa)$.

Questa funzione serve a capire in quali **stati finali potresti finire** leggendo tutta la stringa, anche se ci sono più percorsi possibili.

Esempio:

Immagina un automa dove:

$\delta_N(q_0, a) = {q_1, q_2}$

$\delta_N(q_1, b) = {q_3}$

$\delta_N(q_2, b) = {q_4}$

La funzione di transizione estesa ci restituisce un insieme di stai poiché è definita per coppie (stato, stringa), allora la definiamo come l'unione delle funzioni di transizioni per tutti gli stati appartenenti alla funzione di transizione estesa applicata sulla stringa $x$. Utilizzando la funzione di transizione estesa possiamo dare la definizione di linguaggio riconosciuto conoscendo la relaizone che vi è tra configurazioni successive e funzione di transizione estesa:

> Definizione. Sia $A_N = < \Sigma, Q, \delta_n, q_0, F >$ un ASFND. Il linguaggio riconosciuto da un ASFND é
> 
> $$
> L(A_N) = \{x \in \Sigma^* | \space \overline{\delta}_N(q_0, x) = T \text{ con } T \in Pow(Q), T \cap F \neq \emptyset\}
> $$

### !!!Funzione di Transizione Estesa di un ASFND!!!

##### Cosa fa la transizione “normale” in un ASFND

La funzione di transizione

$$
\delta_N : Q \times \Sigma \to \mathrm{Pow}(Q)
$$

ti dice **dove puoi andare** se sei in uno stato $q$ e leggi **un solo simbolo** $a$.

- **Input**: $(q,a)$
- **Output**: un insieme di stati $\delta_N(q,a)$ (perché è **non deterministico**).

##### Perché serve la transizione estesa

Se invece devi leggere **una stringa intera** (per esempio “aba”):

> “Se parto dallo stato $q$ e leggo tutta la stringa “aba”, in quali stati potrei finire?”

Serve quindi $\overline\delta_N$:

$$
\overline\delta_N(q,\text{stringa}) : Q \times \Sigma^* \;\to\; \mathrm{Pow}(Q)
$$

##### Definizione di $\overline\delta_N$

**Caso base: stringa vuota $\epsilon$**

> “Se non leggo nulla, resto fermo dove sono.”

$$
\overline\delta_N(q,\epsilon) = \{\,q\,\}
$$

**Esempio**:
$\overline\delta_N(q_0,\epsilon)=\{q_0\}$

**Caso generale: stringa = $x\,a$**

* $x$ è **qualunque stringa** (es. “abba”)
* $a$ è **un solo simbolo** (es. “a” o “b”)

$$
\overline\delta_N(q,\,x a)
=\bigcup_{p\in \overline\delta_N(q,x)} \delta_N(p,a)
$$

**Cosa significa, in parole**:

1. Parti da $q$, leggi tutta la **parte iniziale** $x$ → ottieni un **insieme di stati** $S=\overline\delta_N(q,x)$.
2. Per **ognuno** di questi stati $p\in S$, vedi dove puoi andare con **un solo simbolo** $a$: prendi $\delta_N(p,a)$.
3. **Unisci** tutti gli insiemi $\delta_N(p,a)$ → il risultato è $\overline\delta_N(q,xa)$.

##### Esempio concreto

Immagina un automa con queste regole:

* $\delta_N(q_0,a)=\{q_1,q_2\}$
* $\delta_N(q_1,b)=\{q_3\}$
* $\delta_N(q_2,b)=\{q_4\}$

Voglio sapere dove arrivo leggendo la stringa “ab” da $q_0$:

1. Leggo prima “a”:
   $\overline\delta_N(q_0,a)=\{q_1,q_2\}$

2. Poi leggo “b” da ciascuno:
   
   * da $q_1$: $\delta_N(q_1,b)=\{q_3\}$
   * da $q_2$: $\delta_N(q_2,b)=\{q_4\}$

3. Unisco:
   $\overline\delta_N(q_0,ab)=\{q_3,q_4\}$

##### Linguaggio riconosciuto

Una stringa $x$ è **accettata** se, partendo da $q_0$, leggendo $x$ posso **arrivare in almeno uno stato finale**:

$$
x\in L(A_N)\quad\Longleftrightarrow\quad
\overline\delta_N(q_0,x)\;\cap\;F\;\neq\;\emptyset.
$$

**In parole**:

> “Leggo tutta la stringa $x$. Se alla fine mi trovo in uno stato che fa parte di $F$, allora accetto $x$.”

### Relazione tra ASFD e ASFND

Immagina di avere due tipi di robot che leggono stringhe di caratteri:

- Uno (ASFD) è **super rigido**, può trovarsi **in un solo stato alla volta**.
- L’altro (ASFND) è **più flessibile**, può stare **in più stati contemporaneamente**.

**Obiettivo**
Dimostrare che **entrambi possono riconoscere gli stessi linguaggi**, cioè che nonostante funzionino in modo diverso, possono arrivare agli stessi risultati.

**Intuizione Base**
Pensala così:

- L’ASFND è come una persona indecisa: quando deve fare una scelta, prende **tutte le strade possibili in parallelo**.
- L’ASFD invece sceglie **una sola strada**, ma può **simulare tutte quelle dell’ASFND**… basta che tenga traccia di **tutti gli stati** in cui l’ASFND potrebbe trovarsi.

#### 1. Parte (⇒): Da ASFND a ASFD

Domanda: Come può un automa deterministico (ASFD) comportarsi come uno non deterministico (ASFND)?

**Trucco: ogni stato dell’ASFD rappresenta un insieme di stati dell’ASFND.**

**Costruzione passo-passo**
Hai un ASFND:
$A_N = < \Sigma, Q, \delta_n, q_o, F>$

Costruisci un ASFD:
$A' = <\Sigma, Q', \delta', q_0', F'>$

Spiegazione dei simboli:

| Simbolo          | Significato                                                                                                      |
|:----------------:|:---------------------------------------------------------------------------------------------------------------- |
| $Q$              | Stati dell’ASFND                                                                                                 |
| $Pow(Q)$         | Tutti i sottoinsiemi di $Q$ (insieme delle parti) → questi diventano gli stati dell’ASFD                         |
| $q_0' = \{q_0\}$ | Lo stato iniziale dell’ASFD è l’insieme che contiene solo $q_0$ dell’ASFND                                       |
| $\delta'$        | Funzione di transizione dell’ASFD → prende un insieme di stati e un simbolo, e ti dice il nuovo insieme di stati |
| $F$              | Insiemi che contengono almeno uno stato finale dell’ASFND                                                        |

**Come funziona la transizione?**
Supponi che l’ASFND si trovi in più stati contemporaneamente:
$T = {q_1, q_3, q_5}$
L’ASFD prende $T$ come stato unico. Ora, dato un simbolo $a$, fai così:

1. Guarda ogni stato di T.
2. Applica $\delta_n(q,a)$ per ognuno.
3. Prendi l’unione di tutti i risultati.

Formula:
$\delta'(T, a) = ⋃_{q \in T} \delta_n(q, a)$
Così l’ASFD simula tutte le possibilità dell’ASFND.

**Osservazione sulla dimensione degli stati**
Se l’ASFND ha $n$ stati, l’ASFD ne avrà fino a $2^n$, perché deve considerare ogni possibile combinazione di stati.

#### 2. Parte (⇐): Da ASFD a ASFND

Questa è **molto più semplice**.
L’idea è: un ASFD è già un caso particolare di ASFND, solo che la sua funzione di transizione restituisce sempre un solo stato.

**Costruzione**
Hai un ASFD:
$A = <\Sigma, Q, \delta, q_0, F>$

Costruisci l’ASFND:
$A_N = <\Sigma, Q, \delta_n, q_0, F>$

Definisci $\delta_n$ così:
$\delta_n(q,a) = \{\delta(q,a)\}$
È lo stesso automa, ma scritto in modo "non deterministico", anche se funziona esattamente come prima.

#### Conclusione

- Ogni ASFND può essere convertito in un ASFD (anche se con più stati).
- Ogni ASFD è già un tipo di ASFND.

Quindi, hanno la stessa potenza, cioè riconoscono gli stessi linguaggi.
