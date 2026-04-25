# Espressioni Regolari

Le Espressioni Regolari sono un metodo algebrico e formale per rappresentare un linguaggio. Sono uno strumento "finito" in grado di rappresentare linguaggi anche infiniti.

Sono delle scritture che usano i simboli di un alfabeto e i simboli delle operazioni.

> **Definizione.**
> Dati:
> 
> - un alfabeto $\Sigma$
> 
> - un insieme di simboli $\{+, *, (,) \cdot, \emptyset \}$
> 
> si definisce espressione regolare su $\Sigma$ una stringa $r \in (\{+, *, (,), \cdot, \emptyset \} \cup \Sigma)^+$ tale che valga una delle seguenti condizioni:
> 
> 1. $r = \emptyset$
> 
> 2. $r = a$ con $a \in \Sigma$
> 
> 3. $r = (s+t)$ oppure,
>    $r = (s \cdot t)$ oppure,
>    $r = (s^*)$ con $s,t$ espressioni regolari su $\Sigma$.
>    
>    > Ricordiamo che con la scrittura$ ( \{+, *, (,), \cdot, \emptyset\} \cup \Sigma)^+$ stiamo facendo riferimento alla chiusura positiva. Da cui quindi è esclusa $\epsilon$, ovvero la stringa vuota.

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

## Linguaggio rappresentato da un Espressione Regolare

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
> 4. Se $r = (s \cdot t)$, allora $\mathcal L(r) = \mathcal L(s) \cdot \mathcal L(t)$
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
\mathcal L((\emptyset)^*) = (\mathcal L(\emptyset))^*  = \Lambda^* = \{\epsilon\}
$$

> **Nota:** La chiusura di Kleene del linguaggio vuoto è sempre $\Lambda^* = {\epsilon}$.  
> Infatti, l’unica concatenazione possibile di zero stringhe è la stringa vuota.

### Espressioni equivalenti

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
>   $\{a,b\}\cdot\{b\}=\{ab,bb\}$
>   Ossia fai a per b, e b per b.
> 
> - **Somma (+)**: fai l’**unione** dei due insiemi di parole, cioè prendi tutte le parole di entrambi.  
>   Esempio:  
>   $\{ab\}+\{bb\}=\{ab,bb\}$

### Convenzioni sulle Espressioni Regolari

Per facilitare la scrittura delle espressioni regolari, si utilizzano delle convenzioni sia
sulle operazioni, che sulle parentesi:

- **Per quanto riguarda le operazioni**:
  Ci sono delle regole di precedenza, ossia
  **Chiusura riflessiva $^*$ > Concatenazione $\cdot$ > Somma**

- **Per quanto riguarda le parentesi**:
  $(a+b) \rightarrow a + b \\
  (a \cdot b) \rightarrow a \cdot b \\
  a \cdot b \rightarrow ab$

## Relazione fra Automi ed Espressioni Regolari

C'è una fortissima correlazione tra automi ed espressioni regolari.

> Teorema.
> Sia L \sub
