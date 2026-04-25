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