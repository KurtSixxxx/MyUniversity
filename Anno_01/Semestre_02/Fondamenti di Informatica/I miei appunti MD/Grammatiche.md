# Grammatiche

Sono formate da un insieme di regole per generare linguaggi, e dunque tutte le stringhe del linguaggio.

Il simbolo utilizzato per indicare le grammatiche è $S$.

Le regole sono coppie ordinate di stringhe di questo tipo:

$$
(S,0A1)\space\space\space (0A, 00A1) \space\space\space (A,\epsilon)
$$

dove i simboli $\{0,1\}$ sono chiamati **simboli terminali** e sono quei simboli che ci danno l'alfabeto sul quale genero le stringhe del linguaggio. Mentre invece i simboli $\{S, A\}$ sono chiamati **simboli non terminali** e servono per ottenere le stringhe del linguaggio. Per ottenere le stringhe di un linguaggio utilizzo le regole di sostituzione.

Ecco un esempio

$$
S \space 0A1 \space 00A11 \space 00 \epsilon 11 = 0011
$$

---

# Grammatiche e linguaggi generati

### Cos'è una grammatica

Una grammatica è un insieme di regole che definiscono come costruire frasi o parole valide in un linguaggio.  
Una grammatica ha quattro elementi principali:

- **Simboli non terminali**: rappresentano categorie o simboli che devono ancora essere espansi (di solito lettere maiuscole, es. `S`, `A`)

- **Simboli terminali**: lettere o caratteri finali che compaiono nelle parole generate (es. `a`, `b`)

- **Regole di produzione**: indicano come sostituire i simboli non terminali con simboli terminali o altre combinazioni di simboli (es. `S → aS`)

- **Simbolo iniziale**: è il punto da cui si parte per generare le parole (di solito `S`)

**Esempio semplice di grammatica**

Simboli terminali: `a`, `b`  
Simboli non terminali: `S`  
Simbolo iniziale: `S`  
Regole:

- `S → aS`

- `S → b`

### Come si generano parole

Si parte dal simbolo iniziale `S` e si applicano le regole finché si ottiene una parola composta solo da simboli terminali.

Esempio di generazione:

1. `S`

2. Applico `S → aS`: ottengo `aS`

3. Applico `S → aS`: ottengo `aaS`

4. Applico `S → b`: ottengo `aab`

La parola `aab` appartiene al linguaggio generato da questa grammatica.

**Linguaggio generato da questa grammatica**

Il linguaggio è l’insieme di tutte le parole ottenibili da `S` applicando le regole.  
In questo caso il linguaggio è:

```
{ b, ab, aab, aaab, aaaab, ... }
```

cioè tutte le parole formate da una o più `a` seguite da una `b`.

**Chiarimento sul perché `S → aS` e non `aSS`**

La regola `S → aS` significa che si sostituisce un singolo simbolo `S` con la stringa `aS`.  
Non si aggiunge un secondo simbolo `S`, ma si rimpiazza quello presente.  
Se la regola fosse stata `S → aSS`, allora si avrebbe aggiunto un secondo `S`.

#### Esercizio guidato con grammatica più complessa

Grammatica:  
Simbolo iniziale: `S`  
Regole:

- `S → aS`

- `S → Sb`

- `S → ε` (ε è la stringa vuota)

Obiettivo: Generare una parola con soli simboli terminali `a` e `b`.

Esempio di generazione:

1. `S`

2. Applico `S → aS`: ottengo `aS`

3. Applico `S → aS`: ottengo `aaS`

4. Applico `S → Sb`: ottengo `aaSb`

5. Applico `S → ε`: ottengo `aab`

La parola generata è `aab`.

Conclusione

- Per generare una parola da una grammatica si parte da `S`

- Si applicano le regole di sostituzione finché la stringa contiene solo simboli terminali

- La parola finale è parte del linguaggio generato dalla grammatica

> Definizione. Una grammatica formale G è una quadrupla $G ? <V_T, V_N, P; S>$ dove:
> 
> - $V_T$ è l'alfabeto (o l'insieme finito) dei simboli terminali.
> 
> - $V_N$ è l'alfabeto (o l'insieme finito) dei simboli non terminali.
> 
> - $S \in V_N$ è il simbolo iniziale iniziale della grammatica (o assioma?).
> 
> - $P$ è l'insieme finito delle regole di produzione.
