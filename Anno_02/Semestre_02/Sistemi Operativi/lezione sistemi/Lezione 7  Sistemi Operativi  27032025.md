  # Lezione 7 | Sistemi Operativi | 27/03/2025

### Istruzioni TSL e XCHG (?)

Molte architetture (soprattutto multi-processore) offrono specifiche istruzioni:

- **TSL (Test and Set Lock)**

  - uso: **TSL registro, lock**

  - operazione atomica (non deve scindere in più parti) e blocca il bus di memoria;

    ```shell
    enter_region:
    	TSL REGISTER, LOCK
    	CMP REGISTER, #0
    	JNE enter_reagion
    	RET
    ```

    TSL sta per Test and Set Lock, verifica e imposta il blocco.
    TSL modifica un registro, e lo utilizzo all'interno di una *enter_region()*.
    Funziona come segue:

    ```
    TSL RX, LOCK
    ```

    - Mette il contenuto della parola di memoria *lock* nel registro RX
    - Memorizza un valore diverso da zero all'indirizzo di memoria di *lock*.

    La CPU che segue l'istruzione TSL blocca il bus di memoria per impedire alle altre CPU di accedere alla memoria finché non ha finito

    ```shell
    leave region:
    	MOVE LOCK, #0
    	RET
    ```

    - **XCHG** (**eXCHanGe**);
      - disponibile in tutte le CPU Intel x86;
    - ancora busy waiting.

### Sleep e wakeup

- Tutte le soluzioni viste fino ad ora fanno **spin lock**; (Spin-lock: lock implementato tramite il busy waiting.)
  - **problema dell'inversione di priorità.**
- **Soluzione**: dare la possibilità al processo di bloccarsi in modo passivo (rimozione dai processi pronti);
  - primitive: **sleep** e **wakeup**.
- **Problema del produttore-consumatore** (**buffer limitato** – N):
  - variabile condivisa count inizialmente posta a 0;
    

...?

### Semafori

Un semaforo è una variabile intera condivisa che viene utilizzata per controllare l'accesso a una risorsa condivisa. Il semaforo può essere utilizzato per implementare la mutua esclusione (mutex) o per sincronizzare l'accesso a una risorsa.

#### Operazioni sul semaforo

Il semaforo supporta due operazioni principali:

- **Down** (o *Wait*): decrementa il valore del semaforo. Se il valore del semaforo è già 0, il processo che esegue l'operazione down viene bloccato fino a quando il semaforo non viene incrementato da un'altra operazione up.
- **Up** (o *Signal*): incrementa il valore del semaforo. Se ci sono processi bloccati in attesa del semaforo, uno di essi viene sbloccato e può continuare l'esecuzione.

#### Implementazione del semaforo

Il semaforo può essere implementato utilizzando diverse tecniche, tra cui:

- Disabilitazione interrupt: disabilitare gli interrupt durante l'esecuzione delle operazioni sul semaforo per garantire l'atomicità.
- Spin lock TSL/XCHG: utilizzare istruzioni di spin lock per garantire l'accesso esclusivo al semaforo.

#### Tipi di utilizzo del semaforo

Il semaforo può essere utilizzato in due modi principali:

- **Semaforo mutex** (mutua esclusione): il semaforo viene utilizzato per garantire l'accesso esclusivo a una risorsa condivisa.
- **Conteggio risorse** (sincronizzazione): il semaforo viene utilizzato per sincronizzare l'accesso a una risorsa condivisa e garantire che non venga superato un certo limite di utilizzo.
