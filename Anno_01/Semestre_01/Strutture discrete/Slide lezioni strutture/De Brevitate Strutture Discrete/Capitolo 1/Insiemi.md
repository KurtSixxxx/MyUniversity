##### Il concetto di insieme

Un insieme è una collezione ben definita di oggetti.

Un insieme è caratterizzato dagli elementi che gli appartengono.



* Appartenenza:
  Se T è un insieme, l'espressione x \\in T si legge "x appartiene all'insieme T".
* Non Appartenenza:
  Scriveremo x \\notin T per indicare che x non appartiene all'insieme T.



##### Assioma di estensionalità (Uguaglianza tra insiemi)

Due insiemi che contengono gli stessi elementi, sono lo stesso insieme. In simboli:

A = B \\Leftrightarrow (\\forall x)(x \\in A \\Leftrightarrow x \\in B) 



##### Descrizione di un insieme

Per specificare un insieme sarà sufficiente elencarne gli elementi. Gli elementi di un insieme vengono elencati tra parentesi graffe.
Ad esempio:
{1,2,3} indica l'insieme dove appunti i suoi elementi soni i numeri 1,2,3.



* Singoletto
  La notazione {a} indica l'insieme costituito dal solo elemento a, detto insieme singoletto.
* Insieme vuoto
  Con il simbolo \\emptyset indicheremo un insieme vuoto che è l'insieme che non contiene alcun elemento.



Gli insiemi A = {1,2,3} e B = {2,3,1,2,3} sono uguali perché contengono gli stessi elementi. 
Anche gli insiemi A = {1,2,3} e B = {3,1,2} sono uguali.

Ogni insieme è caratterizzato dal fatto che i suoi elementi appaiono una sola volta e non importa in quale ordine essi sono elencati.
Possiamo specificare un insieme esplicitando la proprietà che caratterizza i suoi elementi. Se P è una proprietà ben definita, possiamo allora definire l'insieme {x : la proprietà P è vera per x} \\equal {x : P(x)}



Quindi, cosa vuol dire che P è una proprietà ben definita? Vuol dire che per ogni valore di x, P(x) può assumere solo i 2 valori vero o falso.



##### Cardinalità

Dato un insieme A, il numero di elementi che lo costituisce è denominato cardinalità dell'insieme ed è denotata con |A|. Se |A| è un numero intero l'insieme si dice finito, altrimenti infinito.

Esempio:

* La cardinalità dell'insieme vuoto è quindi zero, |\\emptyset| = 0, mentre |{1,2,3}| = 3 e |{a}| = 1.



##### Relazione di Inclusione



Se abbiamo due insiemi A e B e tutti gli elementi di A sono anche elementi di B allora diciamo che A è incluso in B, ovvero che A è un sottoinsieme di B.

A è un sottoinsieme di B, denotato con A \\subseteq B se:

A \\subseteq B \\Leftrightarrow (\\forall x) (x \\in A \\implies x \\in B)

Se A è un sottoinsieme di B allora B è un sovrainsieme di A ed in questo caso lo denotiamo con B \\supseteq A.

La relazione A \\subseteq B è verificata nel caso in cui A = B.

Per esprimere il fatto che A \\subseteq B ma A è diverso da B, cioè esistono elementi di B che non sono elementi di A, scriviamo A \\subset B o equivalentemente B \\supset A. In questo caso diciamo che A è un sottoinsieme proprio di B, ovvero A è propriamente contenuto in B.



