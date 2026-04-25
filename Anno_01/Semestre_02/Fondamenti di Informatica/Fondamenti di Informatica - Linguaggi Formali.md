# Fondamenti di Informatica: Linguaggi Formali

## Riconoscimento di Linguaggi

Come rappresentare un linguaggio? Ci sono essenzialmente **2 metodi**:

- ***Metodi Riconoscitivi***: Prendono in input una stringa e mi dicono se la stringa appartiene al linguaggio.

- ***Metodi Generativi***: Attraverso un insieme finito di regole generano le stringhe del linguaggio.

## Metodi Riconoscitivi

### Accettazione e Riconoscimento di Linguaggi

Il concetto fondamentale è che tali metodi si basano su **riconoscitori**, o anche detti **automi**.
Un riconoscitore è dotato di:

- Uno o più nastri, che sono dispostivi di memoria, formati da celle che possono contenere simboli appartenenti ad un alfabeto $\Sigma$. Una stringa non è altro che la sequenza di simboli contenuti in celle consecutive, tale che non ci sia una cella vuota indicata con $\mathcal B$. Il nastro è **infinito in entrambe le direzioni** in modo tale da poter scrivere quante stringhe di lunghezza finita vogliamo.

- I caratteri vengono **letti/scritti** tramite **testine **che possono muoversi lungo i nastri e posizionarsi sulle diverse celle.

![](C:\Users\giuli\AppData\Roaming\marktext\images\2025-06-06-09-25-17-image.png)

- La struttura dell’automa prevede inoltre un dispositivo, chiamato **controllo**
  che ad ogni istante assume uno **stato** che rappresenta l’informazione associata
  al funzionamento dell’automa in quell’istante. Lo stato iniziale viene denominato $q_0$ e vi è un insiemedi stati finiti $Q$ che contiene tutti gli stati dell’automa, e un insieme di stati finali $F \sube Q$ che è l’insieme di stati che ci permette di dire se una stringa appartiene al linguaggio o meno.
  
  Su cosa si basa principalmente il funzionamento dell'automa? Principalmente sui concetti di **configurazione** e funzione di **transizione**:
  
  - La **configurazione** rappresenta il comportamento che l’automa assume in un
    determinato momento, ovvero una fotografia della "situazione momentanea"
    dell’automa. Tale configurazione si costituisce di una **tripla**:
    
    1. Contenuto dei nastri
    
    2. Posizione della testina
    
    3. Stato del controllo
    
    Lo stato cambia in base alla configurazione. Il primo momento della configurazione dell'automa è chiamato **configurazione iniziale**. Poi c'è la cosiddetta **configurazione di accettazione** che ci permette di dire se la stringa in input è accettata o meno.
  
  - La **funzione di transizione** è un programma che ci dice come funziona l’automa e, in particolare, è una **relazione tra configurazioni** che mi dice come passare da una configurazione alla configurazione successiva e, per questo, si dice che tale funzione detta il **movimento**, o **passo computazionale** dell’automa che essenzialmente può fare le seguenti azioni:
    
    1. Cambiare la testina
    
    2. Cambiare lo stato
    
    3. Scrivere un carattere

La funzione di transizione è una funzione che prende in **input** un simbolo e uno stato, e restituisce in **output** un simbolo uno stato e un movimento.

$$
f:(\text{simbolo, stato}) \rightarrow (\text{simbolo, stato, movimento})
$$

### Automi a Stati Finiti Deterministici (ASFD)

#### Definizione e Caratteristiche

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

#### Rappresentazioni di un ASFD

##### Tabella di Transizione

Dato un automa a stati finiti, si può costruire una **Tabella di Transizione**, che mostra le transizione da uno stato all'altro dell'automa durante la computazione di accettazione della stringa.

Ad esempio, dato l'automa $A = < Σ = {a, b}, Q = {q0, q1, q2}, δ, q0, F = {q1} >$

Intanto capiamo che:

- L'alfabeto $Σ$ contiene i simboli $a$ e $b$.

- Gli stati sono $q0$, $q1$, $q2$.

- $δ$ è la funzione di transizione: dice come si passa da uno stato all'altro leggendo i simboli.

- Lo stato iniziale è $q0$.

- L'unico stato finale (accettante) è $q1$.

Possiamo costruire una tabella da questa quintupla contente i dati necessari, la quale sarebbe:

| **δ** | $a$   | $b$   |
| ----- | ----- | ----- |
| $q_0$ | $q_0$ | $q_1$ |
| $q_1$ | $q_2$ | $q_2$ |
| $q_2$ | $q_2$ | q_2   |

#### Diagramma di Stato

<img src="file:///C:/Users/giuli/Pictures/Screenshots/Screenshot%202025-05-20%20181737.png" title="" alt="Screenshot 2025-05-20 181737.png" width="620">

Un altro modo, oltre alla tabella, per rappresentare graficamente un automa è il **diagramma di stato**; ossia un grafo che ha:

- I **nodi**, che indicano lo stato; in particolare: lo stato iniziale $q_0$ ha una freccia entrante nel nodo per poter indicare che è lo stato da cui parte la computazione; e lo stato finale che viene rappresentato da un doppio cerchio

- Gli **archi**, (delle frecce, o dei cappi) che indicano la transizione. Per questo motivo sono etichettati con un simbolo che determina lo stato di transizione

##### Computazione di un ASFD

Supponiamo di avere la seguente stringa $x$ nel nastro:

<img title="" src="file:///C:/Users/giuli/Pictures/Screenshots/Screenshot%202025-05-20%20182431.png" alt="Screenshot 2025-05-20 182431.png" data-align="center" width="190">

In base alla funzione di transizione abbiamo visto che durante la computazione si scorre la stringa, fino a che l'automa si accorgerà di aver trovato un carattere $B$, che indica la fine della stringa.

$B$ = *blank* = simbolo speciale sul nastro (spazio vuoto, fine stringa). Serve a dire: "qui finisce la parte utile della stringa".

Una volta trovato tale carattere la computazione termina. Per sapere se la stringa è accettata o meno si guarda lo stato:

- Se $q_n \in F$, ovvero lo stato appartiene all'insieme degli stati finali, dunque la stringa è **accettata**.

- Se $q_n \notin F$, ovvero lo stato **non** appartiene all'insieme degli stati finali, dunque la stringa **non è accettata**.

#### Configurazioni degli Automi a Stati Finiti

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

##### Configurazione Successiva e Relazioni fra Configurazioni

Affinché la computazione termini è fondamentale comprendere la relazione fra configurazione e il concetto di configurazione successiva. Proprio per capire quando inizia una computazione e quando ne termina un'altra.

> Definizione: Dato un ASFD $A = < \Sigma, Q, δ, q_0, F >$ e due configurazioni $(q,x)$ e $(q',y)$ avremo che la configurazione $(q',y)$ è successiva a $(q,x)$ e scriveremo $(q,x)  ⊢_A (q', y)$ se valgono le seguenti condizioni:
> 
> - $∃a \in \Sigma \space \text{tale che} \space x = ay$
> 
> - $δ(q,a) = q'$

**Cosa dice la definizione**:

Hai due configurazioni:

- una iniziale $(q,x)$

- una che viene subito dopo: $(q', y)$

  Allora diciamo che:

  $(q,x) ⊢ (q',y)$

Si legge: **"(q', y) è successiva a (q, x)"**  

(dove il simbolo ⊢ si legge: "produce", oppure "porta a")

Cosa significano i punti elencati:

1. $x = ay$

   Significa che la stringa $x$ **inizia con un simbolo** $a$, seguito dalla stringa $y$.  

   In altre parole: $x$ è fatta così: prima una lettera, poi il resto.

2. $δ(q,a) = q'$

Se sei nello stato $q$ e leggi il simbolo $a$, la funzione di transizione ti dice che devi andare nello stato $q'$

**Tradotto in parole**:

Sei nello stato $q$ e davanti a te hai la stringa $x$.  
Se $x$ inizia con un simbolo $a$, e la funzione di transizione dice che leggendo $a$ da stato $q$ passi a $q'$, allora la nuova configurazione sarà $q'$, con la stringa rimanente $y$ da leggere.

**Pensa...**

- Qual è il primo simbolo della stringa?  

- In che stato sei?  

- Dove ti porta la funzione di transizione?  

- Quale sarà la stringa rimanente?

Esercizio di verifica:

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
>   
>   - $\delta(q_0,a) = q_1$  
>     
>     - Risultato: $(q_1, bb)$ù

##### Chiusura Riflessiva e Transitiva della relazione ⊢

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

#### Stringa Accettata e Linguaggio Riconosciuto

Capiamo cosa si intende per stringa accettata e linguaggio riconosciuto in un ASFD.

> Definizione: Dato un ASFD $A = < \Sigma, Q, δ, q_0, F > $ e $x \in \Sigma^*$, diciamo che $x$ è accettata da $A$ se e solo se $(q_0,x) \vdash^*_A$ con $q \in F$. Il linguaggio è riconosciuto dall'insieme:
> $L(A) = \{ x \in \Sigma^* | (q_0,x)\vdash^*_A (q, \epsilon) \space \text{con} \space q \in F \}$

In parole povere ciò vuol dire:

Dato un automa ASFD con la stringa $x$ che appartiene all'insieme delle stringhe, diciamo che $x$ è accettata se si va da uno stato $(q_0,x)$ a uno stato $q$ (che appartiene all'insieme degli stati finali $F$) e con $\epsilon$ che è la stringa vuota (la quale inica la fine della computazione)

Dunque una stringa accettata da un ASFD che fa parte di un linguaggio $L$ fa parte dall'insieme:  $L(A) = \{ x \in \Sigma^* | (q_0,x)\vdash^*_A (q, \epsilon) \space \text{con} \space q \in F \}$

**Significato:**

Il linguaggio **accettato dall'automa A** è l'insieme di tutte le stringhe $x$ dell'alfabeto $\Sigma$ per cui:

- partendo dalla configurazione iniziale $(q_0, x)$

- si arriva in **uno stato finale** $q \in F$

- e **non resta nulla da leggere** (cioè la stringa diventa $\epsilon$)

Di conseguenza un **linguaggio riconosciuto** da un ASFD è l'insieme di **stringhe accettate dall'automa.**

**Esempio:** Utilizzando l'ASFD che ha tabella di transizione qui a sotto:

| $\delta$ | $a$   | $b$   |
| -------- | ----- | ----- |
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

**Dimostrazione**:

Quando un automa accetta la stringa vuota $\epsilon$?

Vogliamo dimostrare che:

> **`ε ∈ L(A)` se e solo se `q₀ ∈ F`**

Cioè: l'automa accetta la **stringa vuota** **se e solo se** lo **stato iniziale `q₀` è anche finale**.

Dimostrazione divisa in 2 parti:

1. Supponiamo che **`ε ∈ L(A)`**.
   
   - Allora esiste una derivazione:
   
    $(q_0, \epsilon) \vdash^*_A (q, \epsilon)$
   
   - Per accettare la stringa vuota, devo **finire in uno stato finale**, cioè `q ∈ F`
   
   - Ma non ho letto nulla (la stringa è vuota), quindi **non mi sono mai mosso** da `q₀`
   
   - Quindi: `q = q₀` ⇒ **`q₀ ∈ F`**
   
   Se `ε` è accettata, allora `q₀` deve essere uno stato finale.

2. Supponiamo ora che **`q₀ ∈ F`**.
   
   - Parto da `q₀` e la stringa da leggere è `ε`, quindi:
   
     $(q_0, \epsilon) \vdash^*_A (q0, \epsilon)$
   
   - Non faccio nessun passo, ma mi trovo già in uno **stato finale**
   
   - Quindi la stringa vuota è **accettata**
   
   Se `q₀` è uno stato finale, allora `ε` è accettata.

**Spiegazione del ragionamento sulle configurazioni:**

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

**Riassunto del ragionamento logico**:

1. Se `ε` è accettata:
   
   - allora **esiste una derivazione** che parte da `q₀` e **finisce in uno stato finale**
   
   - ma non si fa nessun passo ⇒ `q = q₀`
   
   - quindi: `q₀ ∈ F`

2. Se `q₀ ∈ F`:
   
   - sono già in uno stato finale
   
   - con la stringa vuota, non devo fare nulla
   
   - quindi: `ε` è accettata

**Conclusione intuitiva**:
L’automa accetta `ε` **se e solo se** lo **stato iniziale è uno stato finale**.  

Perché non si muove, e quindi deve **già** trovarsi in uno stato che accetta.

#### Funzione di Transizione Estesa

Se $\delta : Q \times \Sigma \rightarrow Q$ è definita per le coppie stato-simbolo, la funzione di transizione estesa è definita per coppie **stato-stringa** e **restituisce lo stato a cui arriviamo dopo aver applicato $\delta$  ogni simbolo della stringa**. In particolare è definita come:

$$
\overline{\delta} : Q \times \Sigma^* \rightarrow Q

$$

Possiamo riprendere la precedente tabella di transizione per vedere come si applica la funzione di transizione estesa, calcolando $\overline{\delta}(q_0, aab):$

$$
\delta(q_0,a) = q_0 \rightarrow \delta(q_0,a) = q_0 \rightarrow \delta(q0,b) = q_1

$$

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-05-22-17-08-01-image.png" alt="" data-align="center">

> Definzione: La funzione di transizione estesa di ASFD $A = < \Sigma, Q, \delta, q_0, F >$ è la funzione $\overline{\delta}: Q \times \Sigma^* \rightarrow Q$.
> Definita nel seguente modo:
> 
> - $\overline{\delta}(q, \epsilon) = q$, Se la stringa è vuota $(\epsilon)$, non cambi stato.
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

**Un esempio con numeri e lettere:**

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

### Automi a Stati Finiti Non Deterministici (ASFND)

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
> 
> - $Q$ è l'insieme di stati finiti
> 
> - $\delta_N$ è la funzione di transizione, che in particolare sarebbe: $\delta_n : Q \times \Sigma \rightarrow Pow(Q) $
>   Dove $Pow(Q)$ è l'insieme delle parti di $Q$
>   Questa funzione si legge come: delta è una funzione che dato uno stato $q ∈ Q$ e un simbolo $a ∈ Σ$ restituisce un nuovo stato. Dunque il nuovo stato in cui andare.
> 
> - $q_0 \in Q$ è lo stato iniziale, da cui inizia la computazione
> 
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

> Definizione. Sia $A_N = < \Sigma, Q, \delta_n, q_0, F>  $ ASFND. Il linguaggio riconosciuto è così definito:
> $L(A_N) = \{ x \in \Sigma^* | (\{q_0\}, x) \vdash^*_{A_N} (T, \epsilon),$
> 
> $\\
> \text{con } T \in \text{Pow}(Q) \text{ e } T \cap F \neq \emptyset \}$

Tradotto:

$x \in \Sigma^* \text{→ x}$ è una stringa qualsiasi.

$(\{q_0\}, x) \vdash^* (T, \epsilon)$ → partendo da $q_0$ e leggendo $x$, arrivo in un insieme di stati $T$ e non mi resta più nulla da leggere ($\epsilon$).

$T \cap F \neq \emptyset$ → almeno uno di questi stati è finale.

**In parole povere:**

**Una stringa è accettata** se:

- Leggo tutta la stringa

- Parto da $q_0$

- Posso finire in **uno qualunque** degli stati finali (non importa quanti passaggi faccio)

#### Funzione di Transizione Estesa di un ASFND

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
> $\overline{\delta}_N : Q \times \Sigma^* \rightarrow Pow(Q)$

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

> Definizione. Sia $A_N = < \Sigma, Q, \delta_n, q_0, F >$ un ASFND. Il linguaggio riconosciuto da un ASFND è $L(A_N) = \{x \in \Sigma^* | \space \overline{\delta}_N(q_0, x) = T \text{ con } T \in Pow(Q), T \cap F \neq \emptyset\}$

##### Funzione di Transizione Estesa di un ASFND

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
   
   - da $q_1$: $\delta_N(q_1,b)=\{q_3\}$
   
   - da $q_2$: $\delta_N(q_2,b)=\{q_4\}$

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

###### 1. Parte (⇒): Da ASFND a ASFD

Domanda: Come può un automa deterministico (ASFD) comportarsi come uno non deterministico (ASFND)?

**Trucco: ogni stato dell’ASFD rappresenta un insieme di stati dell’ASFND.**

**Costruzione passo-passo**

Hai un ASFND:

$A_N = < \Sigma, Q, \delta_n, q_o, F>$

Costruisci un ASFD:

$A' = <\Sigma, Q', \delta', q_0', F'>$

Spiegazione dei simboli:

| Simbolo          | Significato                                                                                                      |
| ---------------- |:---------------------------------------------------------------------------------------------------------------- |
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

###### 2. Parte (⇐): Da ASFD a ASFND

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

---

### Pumping Lemma per Linguaggi Regolari

Il Pumping Lemma è uno strumento che viene utilizzato per dimostrare che un liguaggio non è regolare. Ma non può essere usato per dire che un linguaggio è regolare.

Ricordiamo cos'è un linguaggio regolare:

I linguaggi regolari L, sono i linguaggi che possono essere rappresentati usando un automa a stati finiti, e dato che come sappiamo, un automa a stati finiti ha un numero finito e limitato di stati, a causa di questo limite ci sono dei linguaggi che non possono essere rappresentati, e dunque non regolari.

Quindi come facciamo a dimostrare che un linguaggio non è regolare? Con il Pumping Lemma.

Se il linguaggio è dunque regolare allora ha una certa proprietà che possiamo chiamare "proprietà di pompaggio" (Pumping, ossia pompaggio).

Un "lemma" è un piccolo teorema, un risultato che ci aitua a dimostrare cose più grandi.

Vediamo cosa fa il Pumping Lemma e come può essere utilizzato per dimostrare che un linguaggio non è regolare.

> Se A è un linguaggio regolare, allora A ha una lunghezza di pompaggio "P" tale che qualsiasi stringa S, di cui la lunghezza è maggiore o uguale a P ($|S| \geq 0$), può essere divisa in 3 parti uguali $S=xyz$ ed in modo che le seguenti condizioni siano vere:
> 
> 1. $xy^iz \in A \text{ per tutte le i }\geq 0$.
> 
> 2. $|y|>0$
> 
> 3. $|xy|\leq P$

Quindi: Se A è un linguaggio regolare, allora A deve avere ua lungezza di pompaggio P tale che qualsiasi stringa S (che estrai dal linguaggio A) in cui la lunghezza è maggiore o uguale a P, può essere divisa in 3 parti, che sono x y e z. Dunque la stringa si divide in 3 parti (x, y e z) ma bisogna far in modo che queste 3 parti rispettino le seguenti condizioni.

$xy^iz \in A \text{ per tutte le i }\geq 0$.

Abbiamo diviso la stringa in x, y e z; e diciamo che la parte x e z li manteniamo così come sono. Mentre invece la parte centrale y (una sequenza di un qualsiasi tipo di simbolo) la eleviamo un certo numero qualsiasi di volte (purchè sia maggiore o uguale a 0). E la stringa che ottieni dopo aver aumentato la parte y un numero qualsiasi di volte deve anche appartenere al linguaggio A. ($xy^iz \in A$)

Vediamo come dimostrare che un linguaggio non è Regolare tramite il Pumping Lemma.

La dimostrazione che faremo sarà fatta usando la contradizzione/"per assurdo"

Seguiamo i seguenti passaggi:

- Diciamo che A sia regolare

- Allora ha una Lunghezza di Pompaggio (detta P)

- Tutte le stringhe maggiori o uguali di P possono essere "pompate" ($|S| \geq P$)

- Ora troviamo una stringa S nel linguaggio A che ha una lunghezza maggiore o uguale a P ($|S| \geq P$)

- Dividiamo S in x, y, z

- Dimostriamo che $xy^iz \notin A$ per qualche i

- Ora consideriamo tutti i modi in cui la stringa S può essere divisa in x y e z

- E dimostri che nessuno di questi "metodi di spezzettamento" può rispettare tutte e 3 le condizioni allo stesso momento

- Allora se non può fare quest'ultima cosa, S non può essere pompata e il linguaggio NON E' regolare.

  Un linguaggio regolare dovrebbe essere in grado di poter soffisfare tutte e 3 le condizioni conemporaneamente.

Esempio 1: Usiamo il Pumping Lemma per dimostrare che un linguaggio $A = \{a^n b^n | n \geq 0\}$ non è regolare.

Innanzi tutto capiamo perchè questo linguaggio NON E' regolare.

Perché è nella forma $a^n b^n$, il che vuol dire che possiamo avere un numero qualsiasi di $a$ seguito dallo stesso numero di $b$. Quindi perché non è regolare? Perché per ottenere questo linguaggio dobbiamo tenere conto

... DA COMPLETARE

---

### Espressioni Regolari

Le Espressioni Regolari sono un metodo algebrico e formale per rappresentare un linguaggio. Sono uno strumento "finito" in grado di rappresentare linguaggi anche infiniti.

Sono delle scritture che usano i simboli di un alfabeto e i simboli delle operazioni.

> **Definizione.**
> Dati:
> 
> - un alfabeto $\Sigma$
> 
> - un insieme di simboli $\{+, *, (,) \cdot, \emptyset \}$
>   
>   Si definisce espressione regolare su $\Sigma$ una stringa $r \in (\{+, *, (,), \cdot, \emptyset \} \cup \Sigma)^+$ tale che valga una delle seguenti condizioni:
>   
>   1. $r = \emptyset$
>   
>   2. $r = a$ con $a \in \Sigma$
>   
>   3. $r = (s+t)$ oppure,
>      $r = (s \cdot t)$ oppure
>        $r = (s^*)$ con $s,t$ espressioni regolari su $\Sigma$.
>      
>      > Ricordiamo che con la scrittura$ ( \{+, *, (,), \cdot, \emptyset\} \cup \Sigma)^+$ stiamo facendo riferimento alla chiusura positiva. Da cui quindi è esclusa $\epsilon$, ovvero la stringa vuota.

Forniamo una spiegazione semplice e chiara per le 3 condizioni:

##### Le 3 condizioni:

- $r = \emptyset$: L'espressione $\emptyset$ rappresenta il linguaggio vuoto ($\Lambda$).

- $r = a$: Dove $a$ è un simbolo qualsiasi dell'alfabeto $\Sigma$. Questa espressione rappresenta il linguaggio che contiene solo il simbolo a (ad esempio $\{a\}$).

- $r = (s+t)$: Se $s$ e $t$ sono espressioni regolari, allora $(s+t)$ è un'espressione regolare. Essa rappresenta l'unione dei linguaggi rappresentati da $s$ e $t$ ($\mathcal L(s) \cup \mathcal L(t)$)

- $r = (s \cdot t)$: Se s e t sono espressioni regolari, allora $(s \cdot t)$ è un'espressione regolare. Essa rapprsenta la concatenazione dei linguaggi rappresentati da $s$ e $t$ ($\mathcal L(s) \cdot \mathcal L(t)$)

- $r = (s^*)$: Se s è un'espressione regolare, allora $(s^*)$ è un'espressione regolare. Essa rappresenta la chiusura di Kleene/Riflessiva del linguaggio rappresentato da $s$ ($\mathcal L(s)^*$), ovvero il linguaggio che include la stringa ($\epsilon$) e tutte le possibili concatenazioni di zero o più stringhe del linguaggio di $s$.

**Esempio**: Vediamo degli esempi di espressioni regolari e non, dato un alfabeto $\Sigma = \{a,b\}$:

- **$(a + \cdot b \cdot b)$**: questa espressione **non è sintatticamente corretta**, perché l'operatore di concatenazione `·` non può essere usato da solo senza operandi validi.  

  Infatti `·b·b` non è una stringa ben formata secondo le regole.  

  Una possibile "correzione" sarebbe scrivere $\epsilon \cdot (b \cdot b)$, ma **attenzione**: la stringa vuota $\epsilon$ non è presente **nell’insieme dei simboli ammessi per costruire espressioni regolari** secondo la definizione data in questi appunti, che considera solo ${+, *, (,), \cdot, \emptyset} \cup \Sigma$.

  > 📌 Quindi, **non è che l’espressione non è regolare perché contiene $\epsilon$**, ma **perché l’uso di $\cdot b \cdot b$ è sintatticamente errato** secondo le regole formali. Inoltre, $\epsilon$ **non è incluso tra i simboli ammessi nella definizione**, quindi ogni espressione che lo usa **non è valida** per motivi **sintattici**, **non semantici**.

- $((a^* \cdot b)^* + (a \cdot b))$: In questo caso invece abbiamo la somma di due espressioni, ossia $(a^* \cdot b)^*$ e $(a \cdot b)$: sappiamo che $(r)^*$ è espressione regolare, e quindi $(a^* \cdot b)^*$ è espressione regolare, infatti si tratta di un prodotto di due termini che soddisfano la condizione per essere espressione regolare. Ovviamente anche $(a \cdot b)$ è espressione regolare, quindi $((a^* \cdot b)^* + (a \cdot b))$ è espressione regolare.

#### Linguaggio rappresentato da un Espressione Regolare

Una volta definite le espressioni regolari, possiamo dare la definizione formale di **linguaggio rappresentato da espressione regolare**:

> **Definizione**.
> 
> Sia r espressione regolare su $\Sigma$. Il linguaggio rappresentato da $r$ si indica con $\mathcal L(r)$ ed è così definito.
> 
> 1. Se $r = \emptyset$, allora $\mathcal L(r) = \Lambda$
> 
> 2. Se $r = a \in \Sigma$, allora $\mathcal L(r) = \{a\}$
> 
> 3. Se $r = (s+t)$, allora $\mathcal L(r) = \mathcal L(s) \cup \mathcal L(t)$
> 
> 4. Se $r = (s \cdot t)$, allora $\mathcal L(r) = \mathcal L(s) \cdot \mathcal L(t)
> 
> 5. Se $r = s^*$, allora $\mathcal L(r) = (\mathcal L(s))^*$

 Esempio. Vediamo quindi applicando la definizione alcuni esempi di linguaggi rappresentati dalle espressioni regolari:

- $r = (a^* \cdot b)$. Applichiamo la definizione

$$
\mathcal L (a^* \cdot b)= \\

\mathcal L(a^*) \cdot \mathcal L(b)=\\

(\mathcal L(a))^* \cdot \mathcal L(b)=\\

(\{a\}^* \cdot \{b\} = \{a^nb|n\geq 0\})

$$

- $r = (\emptyset)^*$. Applichiamo la definizione

$$
\mathcal L((\emptyset)^*) = (\mathcal L(\emptyset))^*  = \Lambda^* = \{\epsilon\}

$$

> **Nota:** La chiusura di Kleene del linguaggio vuoto è sempre $\Lambda^* = {\epsilon}$.  

> Infatti, l’unica concatenazione possibile di zero stringhe è la stringa vuota.

#### Espressioni equivalenti

Ogni **espressione regolare** r rappresenta **un solo linguaggio** L(r).  

Questo significa che da un’espressione regolare sai sempre quale insieme di stringhe descrive.

Però, **più espressioni regolari diverse** possono descrivere **lo stesso linguaggio**.  

Ad esempio:

- $r1​=(a+b)^∗$

- $r2​=(b+a)^∗$  

  Sono espressioni diverse ma descrivono lo stesso insieme di stringhe: tutte le combinazioni di $a$ e $b$, anche vuote.

Quindi:

- Linguaggio = insieme di parole

- Espressione regolare = “formula” per descrivere quel linguaggio

- Più formule diverse possono descrivere lo stesso insieme di parole

Per questo diciamo che le espressioni sono **equivalenti** se rappresentano lo stesso linguaggio

> **Definizione.**
> Due espressioni regolari si dicono equivalenti se rappresentano lo stesso linguaggio.

**Esempio**. Vediamo per esempio le seguenti espressioni regolari:

$r = ((a +b) \cdot b)$ e $s = ((a \cdot b) + (b \cdot b))$

Analizziamo dunque i linguaggi rappresentati dalle 2 espressioni:

$$
\mathcal L(((a+b)\cdot b)) = \{a,b\} \cdot \{b\} = \{ab,bb\}

\\

\mathcal L(((a \cdot b) + (b \cdot b))) = \{ab\} \cup \{bb\} = \{ab,bb\}

$$

> Ricordiamo:
> 
> - **Concatenazione ($\cdot$)**: prendi ogni parola del primo linguaggio e la unisci **stringa per stringa** con ogni parola del secondo linguaggio. 
>   Esempio:  
>     $\{a,b\}\cdot\{b\}=\{ab,bb\}$
>     Ossia fai a per b, e b per b.
> - **Somma (+)**: fai l’**unione** dei due insiemi di parole, cioè prendi tutte le parole di entrambi.  
>   Esempio:  
>   $\{ab\}+\{bb\}=\{ab,bb\}$

#### Convenzioni sulle Espressioni Regolari

Per facilitare la scrittura delle espressioni regolari, si utilizzano delle convenzioni sia

sulle operazioni, che sulle parentesi:

- **Per quanto riguarda le operazioni**:

  Ci sono delle regole di precedenza, ossia

  **Chiusura riflessiva $^*$ > Concatenazione $\cdot$ > Somma**

- **Per quanto riguarda le parentesi**:

$  (a+b) \rightarrow a + b \\$

$  (a \cdot b) \rightarrow a \cdot b \\$

$  a \cdot b \rightarrow ab$

#### Relazione fra Automi ed Espressioni Regolari

C'è una fortissima correlazione tra automi ed espressioni regolari.

> Teorema.
> Sia $L \sube \Sigma^*$ un'espressione formale che lo rappresenta, cioè $L = \mathcal L(r)$

Se riusciamo a costruire per un linguaggio la rispettiva espressione regolare che lo rappresenta, allora esisterà sicuramente l'automa che lo riconosce. Vediamo alcuni esempi:

- Il linguaggio $L = \{a^n b^n | n \geq 0\}$ non è regolare, infatti non esiste alcuna espressione regolare che lo rappresenta.

- Il linguaggio $L = \{a^n b^m | m \geq 1\}$ è regolare, infatti esiste l'espressione regolare che lo rappresenta, ovvero $r = aa^*bb^*$
  
  **Esempio della Rete Stradale**![](C:\Users\giuli\AppData\Roaming\marktext\images\2025-06-06-14-55-38-image.png)

Il nostro intento è quello di trovare tutti i possibili cammini dal nodo A al nodo B. Possiamo considerare questa rete come un automa che ha stato inziale in A e stato finale in B.
Dobbiamo scrivere l'espressione regolare che rappresenta le possibili etichette dal nodo A al nodo B.
Dunque possiamo affermare che tutte le stringghe che vengono conosciute dall'automa sono le giuste etichette e possiamo affermare che esisterà sicuramente l'espressione regolare che rappresenta il linguaggio.
Al centro notiamo che abbiamo un ciclo $(ebd)^*$. L'espressione regolare che possiamo scrivere è la seguente:

$$
r = (ad + f) \cdot (ebd)^* \cdot (ec + g)
$$

Inoltre possiamo affermare che partendo da $A$, i due possibili cammini per arrivare al nodo dove comincia il ciclo ($(ebd)^*$) sono $ad + f$. Una volta che termina il ciclo ($(ebd)^*$) i possibili cammini per arrivare a $B$ sono $ec$ oppure $g$.

---

### Cardinalità dei Linguaggi

Uno dei problemi più importanti è querllo di riconoscere se una stringa appartiene ad un linguaggio.
Adesso valuteremo un problema di cardinalità degli insiemi, e riusciremo a notare che non esiste un algoritmo di riconoscimento per tutti i linguaggi.

#### Ordinamento Lessicografico

In parole semplici, possiamo dire che l'ordinamento lessicografico di $\Sigma^*$ è un ordinamento sulla liunghezza delle stringhe al quale applichiamo l'ordine alfabetico. Il motivo per cui non ordiniamo le stringhe in ordine alfbetico è che si potrebbe incorrere al seguente problema: consideriamo $\Sigma = \{a,b\}$; se applicassimo l'ordinamento alfabetico avremmo il seguente ordine:

$$
a
\\
aa
\\
aaa
\\
aaaa
\\.
\\.
\\.
\\ 
b
\\
ba
$$

Come ossiamo notare si pone il problema di avere dei simboli che non sono ordinati in maniera corretta (esempio: $b,ba$), e , per ovviare a tale problema utilizziamo un ordinamento lessicografico.

> Definizione.
> Dato un alfabeto $\Sigma = \{a_1, a_2, ..., a_n\}$, si definisce ordinamento lessicografico delle stringhe di $\Sigma^*$  l’ordinamento $<$ ottenuto stabilendo un ordinamento fra i caratteri di $\Sigma$ (ad esempio $a_1 < a_2 < ... < a_n$) e definendo l'ordinamento di due stringhe $x, y \in \Sigma^*$ in modo tale che x < y se e solo una delle due condizioni è verificata:
> 
> - $|x| < |y|$ 
> 
> - $|x| = |y|$, ed esiste $z \in \Sigma^*$ tale che $x = za_iu$ e $y = za_jv$ con $u, v \in \Sigma^*$ e $i < j$

Spieghiamo la **seconda condizione più semplicemente**:

Hai due stringhe $x$ e $y$ che hanno **la stessa lunghezza**. Allora per decidere se $x < y$ (cioè se $x$ viene prima di $y$ nell’ordinamento lessicografico), si fa così:

Cerchiamo la prima posizione dove $x$ e $y$ **diventano diverse**.
Supponiamo che fino a quella posizione $k$ sono uguali (cioè c’è una parte $z$ uguale in entrambe le stringhe).
Alla posizione $k+1$, $x$ ha il carattere $a_i$ e $y$ ha il carattere $a_j$.
Se $a_i < a_j$ (cioè il carattere di $x$ è "più piccolo" di quello di $y$ secondo l’ordine stabilito fra i caratteri), allora $x < y$.

In pratica:
**Quando le due stringhe sono lunghe uguali, guarda la prima lettera dove differiscono, e ordinale in base a quella lettera.**

**Esempio:**

$\Sigma = \{a, b, c\}$ con $a < b < c$

Stringhe:

* $x = "aba"$
* $y = "abb"$

Sono lunghe uguali (3 lettere).
Confrontiamo lettera per lettera:

* Prima lettera: $a = a$ (uguali)
* Seconda lettera: $b = b$ (uguali)
* Terza lettera: $a$ in $x$, $b$ in $y$.

Poiché $a < b$, allora $x < y$.

Quindi tornando al nostro alfabeto $\Sigma = \{a,b\}$ avremo un ordinamento lessicografico di questo tipo:

$$
strumento\epsilon
\\
a
\\
b
\\
aa
\\
ab
\\
ba
\\
bb
\\
.\\.\\.
$$

---

## Metodi Generativi

Abbiamo visto i metodi riconoscitivi di un linguaggio, adesso tratteremo i **metodi generativ**i ovvero quei metodi che mi permettono di **generare tutte le stringhe di un linguaggio**.

### Le Grammatiche (G)

Lo strumento grazie al quale riusciamo a generare tutte le stringhe di un linguaggio sono le **grammatiche**. Sono formate da un'*insieme di regole* che mi permettono di generare appunto le stringhe di un determinato linguaggio le regole sono *coppie ordinate di stringhe* di questo tipo:

$$
(S,0A1) \space (0A,00A1) \space (A, \epsilon)
$$

dove:

- i simboli $\{0, 1\}$ sono chiamati **simboli terminali** $V_T$, e sono quei simboli che ci danno l’alfabeto sul quale genero le stringhe di un linguaggio;

- i simboli $\{S, A\}$ sono chiamati **simboli non terminali** $V_N$ e servono per ottenere le stringhe del linguaggio;

- Per ottenere le stringhe di un linguaggio applico le **regole di sostituzione** $P$;
  
  Considerando quindi le regole scritte in precedenza, un esempio di sostituzione può
  essere il seguente:
  
  $$
  S \rightarrow 0A1 \rightarrow 00A11 \rightarrow 00\epsilon 11 = 0011

  $$

Diamo una definizione formale di grammatica:

> Definzione.
> Una grammatica formale G è una quadrupla $G = < V_T, V_N, P, S>$ dove:
> 
> - $V_T$ è l'insieme finito e non vuoto di **simboli terminali**
> 
> - $V_N$ è l'insieme fiinito e non vuoto di **simboli non terminali**
> 
> - $S \in V_N$ è il **simbolo iniziale** della grammatica
> 
> - P è l'insieme finito di regole di produzione ed è una relazione binaria, ovvero una coppia ordinata di stringhe, definita come:
>   $((V_T \cup V_N)^* \cdot V_N \cdot (V_T \cup V_N)^*) \times (V_T \cup V_N)^*$
>   
>   dove la coppia $(\alpha, \beta) \sube P$ si può rappresentare come $\alpha \implies \beta$, e si legge "$\alpha$ produce $\beta$"

**Spiegazione semplice e chiara delle Regole di produzione (P):**

Le regole di produzione sono come delle istruzioni per creare stringhe.

* Ogni regola dice:
  **“Se trovi questa certa sequenza di simboli ($\alpha$), la puoi sostituire con un’altra sequenza ($\beta$)”.**

**Cosa significa che P è una relazione binaria?**

* Una relazione binaria è un insieme di coppie.
* Qui ogni coppia è formata da due stringhe: $\alpha$ e $\beta$.
* Scriviamo questa coppia come $\alpha \implies \beta$ e si legge:
  **“$\alpha$ produce $\beta$”** oppure
  **“da $\alpha$ posso arrivare a $\beta$”**

**Cosa sono $\alpha$ e $\beta$?**

* Sono stringhe, cioè sequenze di simboli che possono essere terminali o non terminali.
* Però, $\alpha$ ha una regola importante: **deve contenere almeno un simbolo non terminale.**

**Perché?**

* Perché le regole servono a trasformare simboli non terminali in altre stringhe (più semplici o con più terminali).
* Se non ci fosse nessun simbolo non terminale in $\alpha$, non potremmo più fare trasformazioni: sarebbe come dire “sostituisci una parola fatta solo di simboli definitivi” — ma quelli non si sostituiscono più!

**La formula:**

$$
((V_T \cup V_N)^* \cdot V_N \cdot (V_T \cup V_N)^*) \times (V_T \cup V_N)^*
$$

* Qui:
  
  * $V_T$ sono i simboli terminali (cioè quelli che non si trasformano più).
  * $V_N$ sono i simboli non terminali (quelli che devono ancora essere sostituiti).
  * $\cup$ vuol dire “unione”, cioè prendo tutti i simboli terminali e non terminali insieme.
  * $^*$ vuol dire “qualsiasi sequenza (anche vuota) di simboli”.

* Quindi $(V_T \cup V_N)^*$ è “qualsiasi sequenza di simboli, terminali o non terminali”.

* $\cdot V_N \cdot$ indica che in mezzo alla sequenza c’è obbligatoriamente **almeno un simbolo non terminale**.

**Quindi, $\alpha$ è fatto così:**

$((V_T \cup V_N)^* \cdot V_N \cdot (V_T \cup V_N)^*) $

* Prima può esserci una sequenza di simboli (terminali o non terminali), anche vuota $(V_T \cup V_N)^*$
* Poi c’è almeno un simbolo non terminale $V_N$
* Poi un’altra sequenza di simboli (terminali o non terminali), anche vuota $(V_T \cup V_N)^*$

Questo garantisce che in $\alpha$ ci sia almeno un simbolo non terminale.

**$\beta$** invece può essere qualsiasi sequenza di simboli (anche vuota), terminali o non terminali; ed è fatto così:
$(V_T \cup V_N)^*$

Riassumendo:

* Le regole di produzione sono coppie $\alpha \implies \beta$.
* In $\alpha$ c’è sempre almeno un simbolo non terminale (quindi possiamo ancora trasformare).
* In $\beta$ può esserci qualsiasi sequenza di simboli, terminali o non terminali.
* Queste regole servono a generare o trasformare stringhe partendo dal simbolo iniziale $S$, fino a ottenere stringhe solo con simboli terminali (cioè parole vere e proprie del linguaggio).
