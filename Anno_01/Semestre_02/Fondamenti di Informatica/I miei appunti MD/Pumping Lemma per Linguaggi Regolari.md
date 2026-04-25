# Pumping Lemma per Linguaggi Regolari

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
