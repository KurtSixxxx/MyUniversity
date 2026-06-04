# Generazione di numeri pseudo-casuali

L'output di una generazione di numeri pseudo-casuali è rappresentato da una sequenza di numeri appartenenti ad un intervallo $[a,b]$ che sembrino casuali.

I generatori di numeri pseudo-casuali sono **algoritmi**.
Fissati dati di parametri in input otterremo in output lo stesso risultato, ovvero la sequenza di numeri generati dalla logica dell'algoritmo.

Un generatore deve avere le seguenti caratteristiche

- **random**: deve superare alcuni testi di randomicità sulle sequenze che produce. [!]
- **controllabile**: con lo stesso input dovrebbe generare sempre la stessa identica sequenza.
- **portabile**: su differenti architetture, quindi su computer diversi.
- **efficiente**: ossia non deve consumare troppe risorse di calcolo per via della sua occupazione durante l'esecuzione.

In C ci sono due librerie che ci occorrono per la generazione di numeri pseudo-casuali.

1. `<stdlib.h>` per la funzione rand() e srand()
2. `<time.h>` per la funzione time()

Esempio di generazione di 1000 numeri "casuali"

```c
#include <stdlib.h>
#include <time.h>

srand(111222333); //Questo è quello che viene chiamato "seme" (seed)
//oppure possiamo usare
srand(time(0));

//Infine stampiamo la sequenza di 1000 numeri
for(int i = 0; i < 1000; i++)
printf("%d", rand());
```

- La funzione `rand()` è quella che si occupa di estrarre il prossimo numero dalla sequenza causale.
  L'invocazione della funzione `rand()` dà come risultato un unsigned int nel range che va da 0 a RAND_MAX
  E' importante notare che non si tratta davvero di numeri randomici, infatti una volta fissato il seme, la sequenza sarà sempre la stessa ad ogni esecuzione del programma.

- La funzione `time()` si occupa di generare numeri che corrispondono ai secondi decorsi a partire dall'1 Gennaio 1970 rispetto alla data e ora corrispondendi all'esecuzione del programma in cui è invocata la funzione. Dunque usare `time()` garantisce che a differenti esecuzioni del programma corrispondano differenti sequenze di numeri pseudo-casuali.

**Come generare numeri (interi) nel range $ [a,b] \in \mathbb{N} (a < b)?$**
Dati due numeri naturali a e b con a < b, ci sono (b - a + 1) valori che intercorrono tra gli estremi dell'intervallo

Voglio un numero intero casuale compreso tra **a** e **b** inclusi.

Esempio: tra 3 e 7 → possibili valori: 3, 4, 5, 6, 7.

Quanti sono gli interi tra a e b inclusi?  
b - a + 1
Da 3 a 7: 7 - 3 + 1 = 5 valori (3, 4, 5, 6, 7).

Mediante l'istruzione dunque:

```c
unsigned int r = rand()%(b - a + 1) + a
```

Nella variabile r quindi sarà copiato un numero compreso tra a e b (estremi inclusi).

**Come generare invece numeri pseudo-casuali in virgola mobile?** Ad esempio, numeri compresi tra 0 e 1?

Bisogna chiedere al compilatore una divisione in virgola mobile:

```c
double r = rand() / (RAND_MAX * 1.0);
```

###### Tips e Avvertimenti

- srand() si usa una sola volta, per inizializzare la generazione casuale. Dopo la prima chiamata a srand() si utilizza rand()
