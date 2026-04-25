# 6° Lezione Sistemi Operativi

#### Comunicazione fra processi

![Comunicazione fra processi](C:\Users\giuli\Pictures\Screenshots\Screenshot 2025-03-25 151408.png)

**Modello a pipe**: abbiamo due o più processi.

Se nella shell invochiamo una cosa del tipo:

```shell
> cmd1 | cmd2 | cmd3
```

ci saranno tre processi in comunicazione, sfruttando i canali di I/O.
Dato che i tre processi sono isolati, devono utilizzare un mezzo (I/O) per poter comunicare.
E inoltre, è importante che siano coordinati. Nel caso della shell sopra, il cmd2 è in attesa di cmd1 per poter continuare. 

Dietro i canali di I/O ci sono i buffer, che evitano i tempi morti di sincronia. Il buffer funge da cuscinetto per "parcheggiare" i dati inseriti dai processi, dove poi a loro volta li prelevano.

I processi possono essere messi in comunicazione in maniera unidirezionale oppure sfruttando una sistemazione più flessibile, dove più processi possono comunicare tra di loro piuttosto che uno con l'altro.
Dunque, in sintesi, è molto importante creare un'area di comunicazione. Possiamo usare dei segmenti di memoria condivisi. Ad esempio una variabile *x* può essere letta e scritta da entrambi i processi. Soffermiamoci sullo scenario del segmento di comunicazione.

> [!WARNING]
>
> ###### *Accavallamento delle operazioni sui dati comuni*???
>
> 

> [!WARNING]
>
> ###### Coordinamento tra le operazioni (o sincronizzazione)???
>
> Si possono creare le dipendenze logiche in cui thread e processi attendono i dati o le informazioni dai thread o processi precedenti.
> Abbiamo quindi bisogno di sincronizzazione.

###### Corse critiche???

Esempio: Versamento su conto corrente (errore di incrementi)

- aggiungi foto (paint)

Lo stesso tipo di errore può verificarsi nel codice del **kernel**. Possono crearsi flussi concorrenti che lavorano anche su strutture dati condivise.

**Mutua Esclusione**: garantire che quando un processo lavora su una variabile, allora l'altro processo dovrà essere bloccato in quell'istante se tenta di lavorare sulla struttura dati contemporaneamente al primo.

![Sezioni Critiche](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250325155800344.png)

**Sezioni critiche**: formalizzare e isolare i problemi.

![Sezioni Critiche - Tabella](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250325160225216.png)

![Come realizzare la mutua esclusione](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250325162438306.png)

Alternanza stretta, come funziona? [Vedi codice]

```pseudocode
int N=2
int turn /*indica di chi è il turno 0 o 1, quindi P0/P1 (che sono alternati prima p0 e poi p1), potrebbe avere qualunque valore*/

/*se turn = 0 e int process = 0...?*/

function enter_region(int process)
	while (turn != process) do
		nothing
		
function leave_region(int process)
	turn = 1 - process
```

i processi che si contendono la CPU vengono identificati come P_{0} e P_{1}

"do -> nothing" è il punto in cui il processo si blocca ed entra in attesa.

###### Soluzione di Peterson

![Soluzione di Peterson](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250325171515797.png)

Prevede alcune variabili condivise. (N=2)
Il codice funziona per due processi, e due strutture dati condivise. La seconda struttura dati è di supporto.
La variabile di appoggio interested è destinata per segnalare all'altro l'ingresso alla struttura; ma le condizioni che indicano l'ingresso sono altre...

Nonostante ciò, abbiamo il problema del busy waiting.

enter_region(): supponiamo che venga invocato con process = 0, allora osserviamo che la variabile di appoggio other...

se process = 1, allora other = 0.

```pseudocode
interested[process] = true
turn = process
```

impostare la propria variabile di interesse a 1.
la variabile turn invece viene impostata al proprio identificativo.

se invece la condizione bloccante (while) è vera, l'altro processo sta lavorando quindi l'ingresso è bloccato.
Se while ha entrambe le condizioni = 1 allora l'ingresso è bloccato.

A cosa serve "turn"? Ipotizziamo la situazione in cui entrambi i due processi vogliono accedere alla struttura dati. Quindi ipotizziamo che la "enter_region()" venga invocata quasi contemporaneamente.
Quello che succede è che entrambi scrivono nella propria variabile di turn, quindi si crea una coda e dopo troviamo l'identificativo di quello che arriva dopo. Dunque, se prima c'era 0 troviamo 1, e se c'era 1 troviamo 0. Quindi chi arriva per primo ad impostare la variabile turn si aggiudica l'ingresso alla struttura.
Quindi se nel while la variabile turn è false (quindi diversa) posso entrare. E se turn ha il mio valore, ossia true, entro nel loop di attesa finché la condizione è false.

[Solo il processo proprietario può scrivere su interested, l'altro si limita a leggere] 

La soluzione di Peterson può essere utilizzata per qualunque N di processi, e inoltre non ci sono turni rigidi. Se ci immaginiamo la soluzione di peterson come un torneo a scontri tra (es.10) processi, ne vincerà solo 1.

La Soluzione di Peterson cessò di funzionare nel momento in cui entrarono sul mercato i moderni multi-processori.