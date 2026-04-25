# Ripasso fast:

## **Generazione di numeri pseudocasuali**

### A cosa servono

I numeri pseudocasuali sono valori che **sembrano casuali**, ma vengono prodotti da **un algoritmo.**
Si chiamano *pseudo* perché la sequenza non è veramente casuale: dipende da un **seme (seed)**.

---

### Come si generano e cosa serve

Servono due librerie:

`#include <stdlib.h> // per rand() e srand()`

`#include <time.h>   // per time()`

- `srand()` inizializza il **seme** (seed) da cui parte la sequenza casuale.  
  Se non viene chiamata, il seme predefinito è 1 → ogni esecuzione produce la **stessa sequenza**.

- `rand()` genera il numero pseudocasuale successivo della sequenza.

Il seme si imposta in due modi:

`srand(111222333);   // seme fisso (sequenza sempre uguale) srand(time(0));     // seme variabile (dipende dall’orario di esecuzione)`

> `time(0)` restituisce i secondi trascorsi dal 1° gennaio 1970 (epoch).  
> Se esegui due volte nello stesso secondo → stessa sequenza.

**Importante:** `srand()` va chiamata **una sola volta** all’inizio del programma, mai dentro i cicli.

---

### Generazione di numeri interi

Per ottenere un intero nell’intervallo `[a, b]`:

`int r = rand() % (b - a + 1) + a;`

Esempio: numeri tra 1 e 10 → `rand() % (10 - 1 + 1) + 1` = `rand() % 10 + 1`

---

### Generazione di numeri in virgola mobile

`rand()` restituisce un intero tra `0` e `RAND_MAX`.  
Per convertirlo in un numero decimale tra `0.0` e `1.0`:

`double r = rand() / (RAND_MAX * 1.0);`

Puoi poi **scalare e traslare** il valore per ottenere un intervallo personalizzato `[a, b]`:

`double r = (rand() / (RAND_MAX * 1.0)) * (b - a) + a;`

Esempio: numero tra `3.0` e `6.0`

`double r = (rand() / (RAND_MAX * 1.0)) * (6.0 - 3.0) + 3.0;`

---

### Esempio completo

`#include <stdio.h> #include <stdlib.h> #include <time.h>  int main() {     srand(time(0)); // inizializza seme una sola volta      for (int i = 0; i < 5; i++) {        int n = rand() % (10 - 1 + 1) + 1;  // intero tra 1 e 10         double x = (rand() / (RAND_MAX * 1.0)) * (6.0 - 3.0) + 3.0; // decimale tra 3.0 e 6.0         printf("int: %d   double: %.2f\n", n, x);     }    return 0; }`

---

### Idee chiave da ricordare

- `rand()` → genera il numero.

- `srand()` → imposta il seme (una sola volta).

- `RAND_MAX` → costante che rappresenta il massimo valore generabile.

- Senza `srand()` → stessa sequenza ogni volta.

- Con `srand(time(0))` → sequenza diversa ad ogni esecuzione.
