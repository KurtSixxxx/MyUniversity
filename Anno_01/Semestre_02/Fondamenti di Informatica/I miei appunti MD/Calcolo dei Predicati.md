# Calcolo dei Predicati

(logica martini pag 33)

Si parla di logica del prim'ordine in un mondo composto da individui e delle relazioni tra di loro.

Oggi studieremo la **logica dei predicati**.

I simboli che rappresentano gli individui, le relazioni tra di loro e gli insiemi delle fbf ($W$). Questi simboli vengono chiamati "**segnatura**" $\rightarrow$ insieme di simboli utlizzata per rappresentare gli individui e le relazioni che nella nostra logica vogliamo rappresentare tramite simboli.

$\Sigma = \{ \{ h^2, g^1, r^o \},\{ Q^3, P^1, R^2 \} \}$ 

$\{h^2, g^1, r^o\}$ **simboli di funzione**, usati nelle fbs per denotare individui (persone, oggetti, numeri...).

$\{ Q^3, P^1, R^2 \}$ **simboli di relazione**, usati nelle fbs per denotare relazioni (essere più alto di, amare, essere figlio di...).

$g$ simbolo di funzione, elevato a $1$, rappresenta una funzione che opera su un individuo ("La mamma di..."). Dobbiamo dare un termine affinché 

A partire dai simboli di funzione definisco un insieme di termini.

Qualsiasi simboli di funzione elevato a $0$ è un termine ($r^0$).

$g(t)$ sarà anch'esso un termine.

$h(t_1,t_2)$ rappresentazione dell'informazione di un individuo.

Con questi simboli io costruisco delle espressioni.

esempi di termini: $h(g(r), r))$

Nella mia sintassi, per costruire un insieme di termini, uso anche un insieme numerabile di simboli, chiamati **Variabili Individuali**, usato per rappresentare individui generici. $Variabili = x, y, z, ...$

Nuovo esempio di un termine: $h(g(r,x),y)$

L'insieme dei termini è indicato come $Term_\Sigma$.

$g(x)$ può essere letto come "*La mamma di (x)*" x come individuo generico.

Mi servono se io voglio fare delle affermazioni che riguardano tutti gli individui.

> Definizione dell'insieme dei termini: ...

$P^1$ indica la relazione di 1 individuo (vedi esponente). C'è una relazione tra alcuni termini.

Se noi scrivessimo $R(h(g(x),r), g(h(r,r)) x,y,z...$. R applicato a questi due termini sono nella relazione R, una relazione semplice.

Useremo i connettivi logici della logica proposizionale: negazione ¬ e implicazione ⇒.

$$
¬\alpha
\\
\alpha \rightarrow \beta
$$

Se $\alpha$ è una fomula ben formata allora $\forall x \alpha$ è una fbf.

$$
\forall x, P(h(x,r))
$$

Letto come "*Per ogni indivudo x vale P ...*"

$\exist x\alpha \equiv \neg\forall x \neg\alpha$

Esempio (pagina 34): $F b f_{p O}$ contiene le seguenti fbf:

- $\neg (< (x,x))$

- $(\forall x(\forall y(\forall x(< (x,y) \land < (y,z) \rightarrow \space < (x,z)))))$

Una fbf naturalmente ha un valore di verità (vera o falsa) e la sua verità vale dal mondo rispetto al quale viene fatta l'affermazione e rispetto al quale consideriamo i simboli di funzione e relazione

fbf: $\forall x, R(x, g(x))$ 

fbf: $\forall y, R(y, g(y))$

Sono due rappresentazioni esattamente della stessa cosa, a prescindere dal simbolo usato.
Quindi si disintigue solo la variabile quantificata usata, che sia $x$ o $y$.
Sono due termini $\alpha$-convertibili. Riguarda tutti gli operatori che legano le variabili e rendono le variabili come una sorta di segnaposto rispetto al quale si utilizza l'operatore.
Quindi diciamo che in $\forall x, R(x, g(x))$ posso scrivere "qualsiasi cosa" al posto del quantificatore $x$. E dunque è a tutti gli effetti un "segnaposto".

> L'alfa conversione, o anche scritta α-conversione, è una tecnica utilizzata in informatica, in particolare in linguaggi funzionali e nella teoria del lambda calcolo, per risolvere conflitti di nomi tra variabili. Implica il rinominare una variabile legata in modo che non si confonda con altre variabili, spesso per garantire che le espressioni possano essere ridotte in modo corretto durante l'esecuzione di programmi. 
> 
> Come funziona:
> L'alfa conversione consiste nel sostituire tutte le occorrenze di una variabile legata con un'altra variabile, purché questa nuova variabile non sia già presente nello scope dell'espressione e non crei conflitti con altre variabili libere. Questo processo non cambia il significato dell'espressione, ma la rende più semplice da analizzare e da ridurre.

#### Quali funzioni e relazioni - tra indivudui - rappresentano i simboli definiti negli insiemi?

Il concetto di mondo possibile, che dobbiamo definire rispetto a una segnatura Σ
viene formalizzato tramite il concetto di struttura o modello . La definiamo nel
seguente modo:

> Sia $\Sigma$ una segnatura; una struttura $A_\Sigma$ per $\Sigma$ è una tripla $<A,\space F,\space P>$ dove:
> 
> - $A$ rappresenta l’insieme di individui del mondo, e viene spesso indicato con il
>   simbolo $|A_\Sigma|$.
> 
> - $P$ rappresenta una famiglia di relazioni, dove per ogni $P^n$ simbolo di predicato
>   appartenente alla segnatura $\Sigma$ è definita nell’insieme $P$ una funzione $\overline{P}_n$ che
>   è definita nel seguente modo:
>   $\overline{P}_n : A^n \rightarrow \{0,1\}$
>   
>   ovvero associa all’insieme di tutti i possibili individui $A^n$ il valore di verità $0$
>   o $1$. In parole povere, stiamo assegnando una semantica a tutte le possibili
>   relazioni, ovvero ai simboli di predicato appartenenti alla segnatura. Se per
>   esempio avessimo nella nostra segnatura un simbolo di predicato $R = \{<^2\}$,
>   la funzione $\overline{R} \in P$ potrebbe associare, ad esempio, all’individuo $< (0, 1)$ il
>   valore $1$, se intendessimo il simbolo $<$ come relazione "essere strettamente
>   minore di"
> 
> - $F$ rappresenta la famiglia di funzioni, ovvero che preso ogni $f^n$ simbolo di
>   funzione appartenente alla segnatura $\Sigma$, definiamo una funzione $\overline{f}^n$ che è
>   definita nel seguente modo:
>   
>   $\overline{f}^n : A^n \rightarrow A$
>   ovvero associa all’insieme di possibili individui $A^n$ un individuo $A$. In parole
>   povere, in questo caso stiamo associando una semantica ai simboli di funzione.
>   Se, per esempio, avessimo $S^1$ come simbolo di funzione appartenente alla
>   nostra segnatura $\Sigma$ al quale vogliamo associare la funzione successore, allora possiamo dire che la funzione $\overline{S}$ associerà ad esempio al termine $S(x)$ :
>   $\overline{S} : S(x) \rightarrow S(S(x))$
>   ovvero un individuo che rappresenta il successore di $S(x)$
>   
>   Possiamo dunque vedere il nostro mondo possibile come struttura $A_\Sigma =< A, F, P >$.

...-appunti mancanti-...

Ambiente: qualcosa che mi dice "*dietro mister x si cela 5*". Per dare un valore di verità ad ogni fbf.
Qual è l'individuo che associamo a tali variabili, essendo generiche?  Esiste una funzione $p$, detta **ambiente**, definita per una segnatura $\Sigma$ nel seguente modo:

$$
p : \text{Variabili individuali} \rightarrow |A_\Sigma|
$$

ovvero associa ad ogni variabile individuale libera un individuo della struttura $A_\Sigma$.
