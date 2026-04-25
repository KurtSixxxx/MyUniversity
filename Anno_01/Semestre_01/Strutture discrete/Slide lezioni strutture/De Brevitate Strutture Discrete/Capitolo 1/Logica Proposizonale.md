##### Il linguaggio della logica

Ogni linguaggio è la composizione di due parti fondamentali: Sintassi e Semantica

* la sintassi definisce le frasi del linguaggio
* La semantica definisce il significato delle frasi, nel caso della logica proposizionale, se sono vere o false



##### Logica Proposizionale

La logica proposizionale è connessa al mondo 0/1 dei calcolatori. Si occupa di fatti, proposizioni e della loro veridicità.

Una proposizione è un'affermazione che è vera oppure falsa, ma non entrambe.

La costruzione sintattica di una formula avviene usando regole e operatori fondamentali.



##### Logica proposizionale: Sintassi

Il vocabolario consiste di un insieme di variabili proposizionali di solito denotate con p, q, r, … con eventuale numerazione sottoscritta, ovvero p1,p2, etc...

Le variabili proposizionali possono assumere solo 2 valori: vero o falso.

Ogni variabile proposizionale è, già da sé, una "formula" proposizionale.

Formule più complesse si possono costruire utilizzando i cosiddetti connettivi logici:

¬ negazione: si legge "non"

∨ disgiunzione logica: si legge "o"

∧ congiunzione logica: si legge "e"

⇒ implicazione logica: si legge "se . . . allora . . . " oppure "implica"

⇔ coimplicazione logica: si legge "se e solo se " oppure "implica e

co-implica"



##### Formule Proposizonali

L'ordine degli operatori segue regole di precedenza e può essere aggiustato usando le parentesi.

La negazione ¬ ha la precedenza maggiore, mentre i connettivi ∧ e ∨ hanno la stessa precedenza.



##### Tavole della verità

\\documentclass{article}

\\usepackage{amsmath}



\\begin{document}



\\begin{table}\[h!]

\\centering

\\begin{tabular}{|c|c|}

\\hline

\\textbf{p} \& \\textbf{$\\neg$p} \\\\

\\hline

V \& F \\\\

F \& V \\\\

\\hline

\\end{tabular}

\\caption{Negazione}

\\end{table}



\\begin{table}\[h!]

\\centering

\\begin{tabular}{|c|c|c|}

\\hline

\\textbf{p} \& \\textbf{q} \& \\textbf{$p \\land q$} \\\\

\\hline

F \& F \& F \\\\

F \& V \& F \\\\

V \& F \& F \\\\

V \& V \& V \\\\

\\hline

\\end{tabular}

\\caption{Congiunzione}

\\end{table}



\\begin{table}\[h!]

\\centering

\\begin{tabular}{|c|c|c|}

\\hline

\\textbf{p} \& \\textbf{q} \& \\textbf{$p \\lor q$} \\\\

\\hline

F \& F \& F \\\\

F \& V \& V \\\\

V \& F \& V \\\\

V \& V \& V \\\\

\\hline

\\end{tabular}

\\caption{Disgiunzione}

\\end{table}



\\begin{table}\[h!]

\\centering

\\begin{tabular}{|c|c|c|}

\\hline

\\textbf{p} \& \\textbf{q} \& \\textbf{$p \\Rightarrow q$} \\\\

\\hline

F \& F \& V \\\\

F \& V \& V \\\\

V \& F \& F \\\\

V \& V \& V \\\\

\\hline

\\end{tabular}

\\caption{Implicazione}

\\end{table}



\\begin{table}\[h!]

\\centering

\\begin{tabular}{|c|c|c|}

\\hline

\\textbf{p} \& \\textbf{q} \& \\textbf{$p \\Leftrightarrow q$} \\\\

\\hline

F \& F \& V \\\\

F \& V \& F \\\\

V \& F \& F \\\\

V \& V \& V \\\\

\\hline

\\end{tabular}

\\caption{Implicazione doppia}

\\end{table}



\\end{document}



##### Soddisfacibilità

* Una formula P è soddisfacibile se esiste un'assegnazione del valore di verità V/F per ogni variabile proposizionale, tale che I(P) è vera.
* Una formula P è insoddisfacibile se non esiste un'assegnazione del valore di verità V/F per ogni variabile proposizionale, tale che I(P) è vera.
* Una formula si dice tautologia se per ogni assegnazione del valore di verità V/F per ogni variabile proposizionale, la formula risulta vera.



##### Principi fondamentali della logica

Ci sono 3 principi fondamentali in logica proposizionale.
Per ogni proposizione P si ha:

* Principio di Identità: Ogni proposizione è uguale a se stessa (P = P). Sembra ovvio, ma stabilisce che il significato di un termine deve rimanere costante all'interno di un ragionamento. 
* Principio di Non-Contraddizione: Una proposizione non può essere contemporaneamente vera e falsa (¬(P ∧ ¬P)). In sostanza, P e il suo opposto (non-P) si escludono a vicenda. 
* Principio del Terzo Escluso: Una proposizione è o vera o falsa; non esiste una terza possibilità (P ∧ ¬P). Se una cosa non è vera, deve necessariamente essere falsa (e viceversa). 



Rendiamolo più semplice usando un esempio concreto: l'affermazione "La mela è rossa".

Ecco come funzionano i tre principi:

&nbsp;	Principio di Identità: Dice semplicemente che una cosa è uguale a se stessa. Se dico "mela", intendo quella cosa lì e non cambio significato a metà discorso. Una mela è una mela.



&nbsp;	Principio di Non-Contraddizione: Dice che non puoi dire due cose opposte nello stesso momento. Non può essere vero che "la mela è rossa" E "la mela NON è rossa". Una delle due deve essere per forza falsa.



&nbsp;	Principio del Terzo Escluso: Dice che non c'è una via di mezzo o una terza opzione. O la mela è rossa, o non lo è. Non esiste una "terza" possibilità logica (da qui il nome "terzo escluso").



In sintesi:

Identità: A è A.

Non-contraddizione: Non può essere A e non-A insieme.

Terzo escluso: O è A o è non-A, punto.



##### Equivalenze logiche

\\neg(\\neg p) \\equiv p \\quad (\\text{doppia negazione})



p \\Rightarrow q \\equiv \\neg q \\Rightarrow \\neg p \\quad (\\text{contrapposizione})



p \\Rightarrow q \\equiv \\neg p \\lor q \\quad (\\text{Eliminazione implicazione})



p \\Leftrightarrow q \\equiv (p \\Rightarrow q) \\land (q \\Rightarrow p) \\quad (\\text{Eliminazione doppia implicazione})



\\text{Leggi di De Morgan:}

\\neg(p \\lor q) \\equiv \\neg p \\land \\neg q \\quad \\text{ovvero, la negazione della disgiunzione è equivalente alla congiunzione delle negazioni}



\\neg(p \\land q) \\equiv \\neg p \\lor \\neg q \\quad \\text{ovvero, la negazione della congiunzione è equivalente alla disgiunzione delle negazioni}



\\text{Distributività:}

p \\land (q \\lor r) \\equiv (p \\land q) \\lor (p \\land r) \\quad \\text{distributività della congiunzione sulla disgiunzione}



p \\lor (q \\land r) \\equiv (p \\lor q) \\land (p \\lor r) \\quad \\text{distributività della disgiunzione sulla congiunzione}



##### Forme Normali

* Forma Normale Congiuntiva
  Una formula p è in Forma Normale Congiuntiva (CNF) se è scritta come congiunzione di disgiunzioni.
  (p ∨ q) ∧ (¬p ∨ ¬r ∨ s)
* Forma Normale Disgiuntiva
  Una formula p è in Forma Normale Disgiuntiva (DNF) se è scritta come disgiunzione di congiunzioni.
  (p ∧ q) ∨ (¬p ∧ ¬r ∧ s)



Una qualunque formula P si può trasformare in una delle due forme normali attraverso un semplice procedimento algoritmico.



Algoritmo di Trasformazione in Forma Normale:

1. Elimina le doppie implicazioni p ⇔ q dalla formula sostituendole con (p ⇒ q) ∧ (q ⇒ p)
2. Elimina le implicazioni p ⇒ q dalla formula sostituendole con ¬p ∨ q
3. Sposta le negazioni ¬ a ridosso delle variabili proposizionali utilizzando le regole di De Morgan, ed eliminando le doppie negazioni
   ¬(¬p ∨ ¬r ∨ s) diventa (p ∧ r ∧ ¬s)



4-a. Per costruire una CNF distribuire la congiunzione sulla disgiunzione ed eliminare tautologie.

4-b. Per costruire una DNF distribuire la disgiunzione sulla congiunzione ed eliminare disgiunti insoddisfacibili e ripetizioni.





