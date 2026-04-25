# Pumping Lemma per Linguaggi Regolari

Il **Pumping Lemma** è uno strumento che serve principalmente a **dimostrare che un certo linguaggio non è *regolare***.

Un "lemma" è un piccolo teorema, un risultato che ci aitua a dimostrare cose più grandi. 

Ricordiamo **cos'è un linguaggio regolare**:

> Un linguaggio L è detto regolare **se esiste un automa a stati finiti (sia deterministico che non deterministico) che lo riconosce**. Quindi se troviamo un ASFD o un ASFND che "accetta" tutte e sole le stringhe di quel linguaggio, allora quel linguaggio è regolare.

Se il linguaggio è dunque regolare allora ha una certa proprietà che possiamo chiamare "proprietà di pompaggio" (Pumping, ossia pompaggio).

Usiamo il lemma non per dire "Questo linguaggio L è regolare", ma per dimostrare che un linguaggio NON E' regolare.
Dunque, se un linguaggio non rispetta la proprietà di pompaggio, allora non può essere regolare.

> Un automa a stati finiti ha un numero finito di stati.  
> Se deve leggere una stringa **molto lunga**, più lunga del numero di stati, allora **per forza** passerà due volte dallo stesso stato → si crea **un ciclo**.  
> La parte della stringa letta dentro questo ciclo può essere **ripetuta più volte** (anche 0 volte) e l’automa finirà comunque dove deve finire.  
> Questo è il significato di **"pompaggio"**: prendere una parte e ripeterla.  
> Se un linguaggio è regolare, allora **tutte le stringhe sufficientemente lunghe** avranno questa proprietà.
