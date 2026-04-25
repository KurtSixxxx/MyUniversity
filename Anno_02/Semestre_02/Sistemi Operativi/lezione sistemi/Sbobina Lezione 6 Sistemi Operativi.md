# Sbobina Lezione 6 Sistemi Operativi

#### Ripasso delle precedenti lezioni

I **processi** di per sé sono delle entità isolate. Ognuno ha il proprio spazio di indirizzamento che sono isolati anch'essi, per un livello di sicurezza. Tale concetto l'abbiamo "violato" quando abbiamo parlato di *thread*, dato che quest'ultimi non hanno protezione l'uno dall'altro, ma sono dei flussi che sono destinati a collaborare; condividono lo spazio di indirizzamento.

### Comunicazione fra processi

![Comunicazione fra processi](C:\Users\giuli\Pictures\Screenshots\Screenshot 2025-03-25 151408.png)

Quali sono le metodologie e i problemi che emergono quando si parla di comunicazione fra processi?

Ad esempio, nel **[modello a pipe](# "Meccanismo di comunicazione tra processi in cui l'output di un processo diventa l'input di un altro")**, abbiamo due o più processi; nel particolare nell'uso della *shell* è abbastanza comune usare un'invocazione del genere:

```shell
> cmd1 | cmd2 | cmd3
```

Quindi i comandi possono essere eseguiti in parallelo mettendoli in comunicazione, utilizzando quello che in gergo è chiamato pipelining. 
Quello farà la shell, a seguito di un invocazione come quella appena vista, sarà creare altrettanti processi:

```shell
> cmd1 | cmd2 | cmd3
  P1 	 P2		P3
```

I processi saranno creati in modo indipendente e di per sé questi tre processi verranno messi in comunicazione sfruttando i classici canali di I/O che ognuno di esso ha. Il canale di output standard di qualunque processo, lanciato sulla shell, è il terminale stesso; così come il canale di input è la tastiera. 
Questa sintassi quindi mette in comunicazione i canali di output di uno con i canali di input del successivo: creando dunque quello che in genere è inteso come una ***pipe***.
Nella sua semplicità questa implementazione risolve una molteplicità di aspetti del problemi di "interprocess communication" (?). Ovvero, per scambiarsi i dati i processi - nonostante siano isolati - hanno bisogno di un mezzo per comunicare, e di fatti utilizzano i canali di I/O.
Un secondo aspetto è quello del **coordinamento**: quando ci troviamo in una pipe, ci troviamo di fronte alla cosiddetta dipendenza di dato. Ossia, il comando 2 ha bisogno di quello che gli fornirà il comando uno; e finché il dato non verrà fornito il comando si troverà in una situazione di stallo.