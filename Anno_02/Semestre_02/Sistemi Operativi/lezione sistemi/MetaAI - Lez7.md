# Lezione 7 | Sistemi Operativi | 27/03/2025

# Introduzione alle Istruzioni TSL e XCHG
Nel campo dei sistemi operativi, la gestione delle risorse condivise è un aspetto cruciale per garantire la corretta esecuzione dei processi. A tal fine, molte architetture (soprattutto multi-processore) offrono specifiche istruzioni che consentono di gestire l'accesso alle risorse condivise in modo atomico.

![Istruzioni TSL e XCHG](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250327164450315.png)

### Istruzione TSL (Test and Set Lock)
La istruzione TSL (Test and Set Lock) è un'istruzione atomica che consente di verificare e impostare il blocco di una risorsa condivisa. L'istruzione TSL viene utilizzata per implementare la mutua esclusione (mutex) tra processi.

Funzionamento dell'Istruzione TSL
L'istruzione TSL funziona nel seguente modo:

1. La CPU esegue l'istruzione TSL e verifica se la risorsa condivisa è già bloccata.
2. Se la risorsa non è bloccata, la CPU imposta il blocco e memorizza un valore diverso da zero all'indirizzo di memoria della risorsa.
3. Se la risorsa è già bloccata, la CPU non esegue alcuna operazione e il processo viene bloccato fino a quando la risorsa non viene sbloccata.

Esempio di Utilizzo dell'Istruzione TSL
Ecco un esempio di utilizzo dell'istruzione TSL:

```shell
enter_region:
    TSL REGISTER, LOCK //copia il lock nel registro e lo imposta a 1
    CMP REGISTER, #0 //il lock era zero?
    JNE enter_region //se non era zero, il lock era stato impostatom poi eseui il ciclo
    RET //torna al chiamante; si è entrati nella regione critica
```


In questo esempio, la istruzione TSL viene utilizzata per verificare e impostare il blocco della risorsa condivisa. Se la risorsa non è bloccata, la CPU imposta il blocco e memorizza un valore diverso da zero all'indirizzo di memoria della risorsa. Se la risorsa è già bloccata, la CPU non esegue alcuna operazione e il processo viene bloccato fino a quando la risorsa non viene sbloccata.

### Istruzione XCHG (eXCHanGe)
La istruzione XCHG (eXCHanGe) è un'altra istruzione atomica che consente di scambiare il contenuto di due registri o di un registro e di una memoria. L'istruzione XCHG viene utilizzata per implementare la mutua esclusione (mutex) tra processi.

Funzionamento dell'Istruzione XCHG
L'istruzione XCHG funziona nel seguente modo:

1. La CPU esegue l'istruzione XCHG e scambia il contenuto di due registri o di un registro e di una memoria.
2. L'istruzione XCHG è atomica, quindi non può essere interrotta da altri processi.

Esempio di Utilizzo dell'Istruzione XCHG
Ecco un esempio di utilizzo dell'istruzione XCHG:

```shell
lock:
    XCHG REGISTER, LOCK
    CMP REGISTER, #0
    JNE lock
    RET


```


In questo esempio, la istruzione XCHG viene utilizzata per scambiare il contenuto del registro e della memoria. Se la memoria non è bloccata, la CPU scambia il contenuto e memorizza un valore diverso da zero all'indirizzo di memoria della risorsa. Se la memoria è già bloccata, la CPU non esegue alcuna operazione e il processo viene bloccato fino a quando la risorsa non viene sbloccata.

# Sleep e Wakeup

![Sleep & Wakeup](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250327164515763.png)

Le istruzioni TSL e XCHG sono utilizzate per implementare la mutua esclusione (mutex) tra processi, ma possono causare problemi di busy waiting. Per evitare questi problemi, i sistemi operativi utilizzano le primitive sleep e wakeup.

#### Funzionamento delle Primitive Sleep e Wakeup

Le primitive sleep e wakeup funzionano nel seguente modo:

1. Un processo esegue la primitiva sleep e si blocca fino a quando non viene svegliato.
2. Un altro processo esegue la primitiva wakeup e sveglia il processo bloccato.

#### Esempio di Utilizzo delle Primitive Sleep e Wakeup

Ecco un esempio di utilizzo delle primitive sleep e wakeup:

Supponiamo di avere due processi, P1 e P2, che condividono una risorsa. P1 esegue la seguente sequenza di istruzioni:

```shell
while (true) {
    // Sezione critica
    sleep();
    // Operazioni successive
}
```


P2 esegue la seguente sequenza di istruzioni:

```shell
while (true) {
    // Operazioni precedenti
    wakeup(P1);
    // Sezione critica
}
```


In questo esempio, P1 esegue la primitiva sleep e si blocca fino a quando non viene svegliato da P2. P2 esegue la primitiva wakeup e sveglia P1, che può quindi continuare l'esecuzione.

# Semafori

I semafori sono un tipo di variabile.
Possono avere:

- Valore 0, che sta a indicare che non sono stati salvati dei *wakeup*
- Valore positivo se uno o più *wakeup* sono in attesa.

Ci sono due operazioni:

- **down** (generalizzazione di *sleep*).
  L'operazione verifica se il valore è maggiore di 0. Se è così, decrementa il valore (cioè consuma un *wakeup* memorizzato) e quindi continua. Se il valore è 0 allora è messo in sleep, senza completare momentaneamente il down.
- **up** (generalizzazione di *wakeup*).
  L'operazione aumenta il valore del semaforo indirizzato. Se uno o più processi erano in *sleep* su quel semaforo, uno di loro è scelto dal sistema (per esempio casualmente) e gli è permesso di completare il suo *down*. In questo modo, dopo un *up* su un semaforo contente dei processi in *sleep*, il semaforo sarà sempre 0, ma ci sarà un processo in meno in stato di *sleep*. Anche l'operazione di incremento del semaforo e di risveglio del processo è indivisibile. Nessun processo si blocca nel fare un *up*, così come nessun processo si blocca nel fare un *wakeup* nel modello precedente.

Tutte le operazioni sono indivisibili azioni atomiche. Una volta che l'operazione è avviata, nessun altro processo può accedere al semaforo finché l'operazione non è completata o bloccata. L'atomicità è essenziale per risolvere problemi di sincronizzazione ed evitare ra*ce condition*.

> [!IMPORTANT]
>
> <u>***L'ordine dei semafori non è opinabile.***</u>

I semafori sono una tecnica di sincronizzazione utilizzata per controllare l'accesso a risorse condivise. Un semaforo è una variabile intera che può essere utilizzata per rappresentare la disponibilità di una risorsa.

![Semafori](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250327164532606.png)

#### Operazioni sui Semafori

I semafori supportano due operazioni principali:

- **Down** (o *Wait*): decrementa il valore del semaforo. Se il valore del semaforo è già 0, il processo che esegue l'operazione down viene bloccato fino a quando il semaforo non viene incrementato da un'altra operazione up.
- **Up** (o *Signal*): incrementa il valore del semaforo. Se ci sono processi bloccati in attesa del semaforo, uno di essi viene sbloccato e può continuare l'esecuzione.

#### Esempio di Utilizzo dei Semafori

Ecco un esempio di utilizzo dei semafori:
Supponiamo di avere due processi, P1 e P2, che condividono una risorsa. La risorsa è rappresentata da un semaforo S.

```
// Inizializzazione del semaforo
S = 1;

// Processo P1
while (true) {
    down(S);
    // Sezione critica
    up(S);
    // Operazioni successive
}

// Processo P2
while (true) {
    down(S);
    // Sezione critica
    up(S);
    // Operazioni successive
}
```

In questo esempio, i processi P1 e P2 condividono la risorsa rappresentata dal semaforo S. Il semaforo S è inizializzato a 1, indicando che la risorsa è disponibile.
Quando un processo esegue l'operazione *down(S)*, decrementa il valore del semaforo S. Se il valore del semaforo S è già 0, il processo viene bloccato fino a quando il semaforo non viene incrementato da un'altra operazione up.
Quando un processo esegue l'operazione *up(S)*, incrementa il valore del semaforo S. Se ci sono processi bloccati in attesa del semaforo, uno di essi viene sbloccato e può continuare l'esecuzione.
I semafori sono una tecnica di sincronizzazione efficace per controllare l'accesso a risorse condivise. Tuttavia, possono essere soggetti a problemi di *deadlock* e di *starvation*, che devono essere affrontati utilizzando tecniche di prevenzione e di risoluzione.

### Produttore-consumatore con i semafori

I semafori risolvono i problema della perdita di *wakeup*. Per far si che i semafori lavorino correttamente è essenziale che siano implementati in maniera indivisibile. Normalmente up e down si realizzano con chiamate di sistema, con il sistema operativo che disabilita brevemente tutti gli interrupt mentre testa il semaforo, lo aggiorna e se necessario lo mette in *sleep*.

![Produttore-consumatore con i semafori](C:\Users\giuli\AppData\Roaming\Typora\typora-user-images\image-20250327170911807.png)

### Mutex e Thread utente

(?)