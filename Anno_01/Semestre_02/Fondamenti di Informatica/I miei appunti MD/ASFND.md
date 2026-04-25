# Automi a Stati Finiti Non Deterministici

Gli **automi deterministici** hanno la caratteristica che ogni configurazione ammette, per ogni coppia stato-simbolo, uno e un solo stato; ovvero, o abbiamo una configurazione successiva o altrimenti non l'abbiamo e la computazione termina. Come ad esempio nel caso di una configurazione del tipo $(q, \epsilon)$, in cui la computazione termina.

Parlando invece di automi non deterministici essi sono chiamati così poiché possono ammettere più configurazioni successive.

La differenza principale tra automi deterministici e automi non deterministici sta nella funzione di transizione, che viene chiamata $\delta_n$ e assume questa forma:

$$
\delta_n : Q \times \Sigma \rightarrow Pow(Q)
$$

Dove $Pow(Q)$ rappresenta l'insieme della parti di Q, ovvero l'insieme di stati, come ad esempio $Pow(Q) = \{q_0, q_1\}, \{q_1,q_2\}$ ecc...

Per l'insieme delle parti di $Q$ si intende un insieme i cui elementi sono anch'essi sottoinsiemi dell'insieme $Q$.

> Definizione: Un Automa a Stati Finiti Non Deterministici (ASFND) $A_N$ è una quintupla $A_n = < \Sigma, Q, \delta_n, q_0, F >$ dove:
> 
> - $\Sigma$ è l'alfabeto in input (finito)
> - $Q$ è l'insieme di stati finiti
> - $\delta_N$ è la funzione di transizione, che in particolare sarebbe: $\delta_n : Q \times \Sigma \rightarrow Pow(Q)$ 
>   Dove $Pow(Q)$ è l'insieme delle parti di Q
>   Questa funzione si legge come: delta è una funzione che dato uno stato q ∈ Q e un simbolo a ∈ Σ restituisce un nuovo stato. Dunque il nuovo stato in cui andare.
> - $q_0 \in Q$ è lo stato iniziale, da cui inizia la computazione
> - $F \subseteq Q$, ossia l'insieme degli stati finali. Gli stati finali, ricordiamolo, sono gli stati in cui si arriva se una stringa è accettata, ma non quelli in cui finisce la computazione.
>   La **computazione** sarebbe il "calcolo" della stringa, ossia la verifica di appartenenza o meno al linguaggio della stringa presa in esame

Gli ASFD e gli ASFND, a livello di capacitò di riconoscimento, sono perfettamente equivalenti, ovvero che con entrambi riusciamo a riconoscere gli stessi linguaggi. L'unica peculiarità, che è quella che conta, è che riescono a riconoscere certe classi di linguaggi, ovvero quelli dove è possibile avere diversce scelte di computazione piuttosto che una univoca.

**Esempio**: Dato l'alfabeto $\Sigma = \{a,b\}$, vogliamo costruire un automa che riconosca le stringhe che abbiano b come penultimo carattere, considerando che $Q = \{q_0,q_1,q_2\}$, $F = \{q_2\}$.

Come prima cosa, costuriamo la tabella di transizione richiesta dall'esercizio.

| $\delta_n$ | $a$         | $b$         |
|:----------:|:-----------:|:-----------:|
| $q_0$      | $\{q_0\}$   | $\{q0,q1\}$ |
| $q_1$      | $\{q_2\}$   | $\{q_2\}$   |
| $q_2$      | $\emptyset$ | $\emptyset$ |

Tale funzione di transizone è quella di un ASFND, ci permette molto facilmente di riconoscere stringhe che abbiano $b$ come penultimo carattere. Se avessimo dovuto creare in un automa deterministico con tali caratteristiche sarebbe stato parecchio più complesso.

Come abbiamo detto precedentemente, gl ASFD hanno la funzione di transizione totale, ossia che restituisce uno e un solo stato per ogni coppia stato-simbolo. Invece, per gli ASFND, la funzione **non è** sempre **totale**. Ovvero non è sempre definita per tutte le coppie di stato-simbolo. Questo però non implica che la computazione termini, perché stiamo parlando comunque di automi a stati finiti, che hanno la testina che si muove soltato verso destra con stringhe di lunghezza finita. Riprendendo l'esempio, e dunque la tabella, abbiamo che se mi trovo nel caso i cui $\delta(q_2,a)=\emptyset$, allora in quel caso la computazione termina.

### Computazione di un ASFND

Come detto in precedenza, la computazione di un ASFND è di tipo non deterministico. Ciò vuol dire che per ogni coppia stato-simbolo corrisponde un insieme di stati, e non uno solo. Per questo motivo si formerà un albero di computazione per tutte le possibili scelte per ogni caso. Se, almeno uno dei possibili alberi ha una computazione del tipo:

$$
(q_0,x)\vdash^*(q,\epsilon)\space\text{con}\space q \in F
$$

allora la **stringa** è **accettata**.

**Esempio**. Prendiamo in considerazione l'automa che ha il seguente diagramma di stati:

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-05-23-09-50-17-image.png" title="" alt="" data-align="center">

Data la stringa $x = bba$, vogliamo vedere se tale stringa è accettata dall'automa.

**Risoluzione**. Analizziamo tutti i possibili alberi di computazione:

<img title="" src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-05-23-09-52-30-image.png" alt="" data-align="center" width="445">

Come possiamo notare, poichè tra tutte le possibili computazioni vi è una con-
figurazione $(q_3, \epsilon)$, con $q_3 \in F$, allora possiamo dire che **x = bba** è accettata
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

Quindi utilizzando la chisura riflessiva, possiamo dire che in un numero di passi maggiore o uguale a 0:

> Definizone. Sia $A_N = < \Sigma, Q, \delta_n, q_0, F> $ ASFND. Il linguaggio rionosciuto è così definito:
> 
> $$

L(A_N) = \{x \in \Sigma^* \mid (\{q_0\}, x) \vdash^*_{A_N} (T, \epsilon),
\\
\text{con } T \in \text{Pow}(Q) \text{ e } T \cap F \neq \emptyset \}

> $$

Con tale definizione stiamo dunque dicendo che in zero, uno o più passi dobbiamo
arrivare alla configurazione $(T, \epsilon)$ dove $T$ appartiene all’insieme delle parti di $Q$
ovvero è un insieme di stati, proprio per la definizione di ASFND, e in modo tale che
T abbia almeno uno stato finale, il ché equivale a dire che l’intersezione $T\cap F \neq \emptyset $
