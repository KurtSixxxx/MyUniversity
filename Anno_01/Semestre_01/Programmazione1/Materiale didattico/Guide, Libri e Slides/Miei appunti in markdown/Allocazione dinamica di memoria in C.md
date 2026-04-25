# Allocazione dinamica di memoria in C

### I 3 diversi tipi di allocazione

1. **Allocazione automatica.**
   Avviene quando dichiariamo una **variabile locale** ad una funzione.
   La sua visibilità è **limitata al blocco di codice** in cui è stata dichiarata.
   Il suo ciclo di vita termina quando termina l'esecuzione del blocco di memoria in cui viene allocata. Infatti il compilatore dealloca la sua memoria automaticamente.
   L'area di memoria utilizzata è denominata **STACK**.
   
   ```c
   void foo(){
      int a = 0; //a visibile solo in foo()
   }
   ```

2. **Allocazione dinamica**.
   Effettuata mediante funzione `malloc()` (stdlib.h) in qualunque punto del programma.
   Area di memoria utilizzata è denominata **HEAP**.
   Il ciclo di vita del blocco di memoria termina con l'invocazione della funzione `free()` sul puntatore.
   
   ```c
   //qualunque punto del programma
   int *p = malloc(sizeof(int));
   //...
   free(p); //deallocazione della cella puntata da p
   ```

3. **Allocazione statica**
   Dichiarazione di variabili al di fuori da qualunque blocco.
   Il segmento di memoria ospitante è detto **segmento DATA**.
   Il ciclo di vita di una variabile statica inizia e termina con il programma stesso.
   Viene detta variabile globale.
   
   ```c
   //...
   double data = 0.5;
   //...
   int main(){
       //...
   }
   ```

![https://craftofcoding.wordpress.com/wp-content/uploads/2015/12/stackmemory4.jpg?w=640](https://craftofcoding.wordpress.com/wp-content/uploads/2015/12/stackmemory4.jpg?w=640)

### Allocazione dinamica: Heap o Free Store

Lo HEAP è un segmento di memoria che permette alle applicazioni di memorizzare dati in modo dinamico

In questo caso l'allocazione e la deallocazione avvengono mediante apposite chiamate a funzioni: `malloc()` e `free()`. L'header che ci occorre per utilizzare tali funzioni è <stdlib.h>
Questa cosa non accade con l'allocazione automatica (STACK), in quanto l'allocazione e la deallocazione sono azioni svolte automaticamente dal compilatore.

```c
#include <stdlib.h>
double *arr = malloc(sizeof(double) * 10);
//...
free(arr); //allocazione
```

`malloc()` alloca dinamicamente un blocco di memoria nello HEAP.
L'argomento della funzione è la dimensione in byte `sizeof(double)`.
La funzione restituisce un puntatore generico, ovvero di tipo `void *`, per questo bisogna effettuare un casting al tipo desiderato.

La funzione `free()` **libera la memoria precedentemente allocata**.

### Deallocazione: funzione `free()`

1) Allocazione automatica (stack): memoria automaticamente deallocata dopo ultima istruzione del blocco in cui la variabile è e stata dichiarata.

2) Viceversa: la memoria allocata dinamicamente va successivamente liberata mediante la funzione free.
   
   ```c
   double ∗arr = malloc(sizeof(double) * 10);
   //...
   free(arr);
   ```

Una volta deallocato un puntatore con free, l'indirizzo di memoria rimane invariato!

```c
double *arr = malloc(sizeof(double) * 10);
printf("%p", arr);
//...
free(arr); //deallocazione
//...
printf("%p", arr);
```

### Memory leak / aliasing

```c
double *arr = malloc(sizeof(double) * 10);
double *v   = malloc(sizeof(double) * 10);
v = arr;   // aliasing
```

Come possiamo vedere nelle prime due linee di codice ogni puntatore ha il suo indirizzo di memoria. Dopo invece viene associato al puntatore v lo stesso indirizzo di memoria di arr. Dunque v perderà il riferimento a cui punraca prima.
Questo avvenimento viene chiamato **aliasing**: più puntatori che puntano allo stesso indirizzo.

Se vogliamo dellocare il blocco di memoria puntato da v inizialmente non possiamo farlo perchè abbiamo perso il puntatore. Questo avvenimento prende il nome di **memory leak**.

- **Aliasing**: è come avere **due telecomandi diversi che comandano la stessa TV**. Puoi cambiare canale con uno o con l’altro, ma se butti via il secondo telecomando non hai perso nulla, perché il primo controlla comunque la stessa TV. Il rischio è confondersi su chi controlla cosa.

- **Memory Leak**: è come **dimenticare le chiavi dentro una stanza e chiudere la porta a chiave**. La stanza è ancora occupata (la memoria è presa), ma non puoi più entrarci: hai perso il riferimento.
  
  ![Nuovo progetto.png](C:\Users\giuli\Desktop\Nuovo%20progetto.png)

### Double free

```c
double *arr = malloc(sizeof(double) * 10);
//...
free(arr);
//...
free(arr); //!! comportamento indefinito
```

Può capitare di operare per errore una **doppia free**.

Cosa succede? Come già detto in precedenza, il valore del puntatore, dopo la chiamata free() rimane invariato.

Un ulteriore tentativo di deallocazione avrà un coportamento **indefinito**.

Per questo, è buona norma, ad ogni tentativo di deallocazione:

- inserire un controllo sul valore del puntatore

- "azzerare" il puntatore dopo invocazione a funzione free()

```c
double *arr = malloc(sizeof(double) * 10);
//...
if(arr){
    free(arr);
    arr = NULL;
}
//..altri tentativi di deallocazione
```

### Premature free

```c
double *arr = malloc(sizeof(double) * 10);
//...
double *v = arr; //adesos v è alias di arr
//...
if(arr){
    free(arr);
    arr = NULL;
}
//...
v[5] = 4.56789; //Conserva il valore di arr
```

Dopo la `free` di `arr`, operata per errore, esso sarà `NULL`, ma `v` conserva il vecchio valore di `arr`!!

### Funzioni che restituiscono un puntatore

```c
int *func(int k){
    int arr[k];
    for(int i = 0; i < k, i++){
        arr[i] = 2 * i;
    }
    return arr; // NO!!
}


int *array = func(10);
```

Corretto? .. NO!
Infatti arr rappresenta un blocco di memoria allocato nello stack, qundi il suo ciclo di vita è limitato solo dentro func().

Dopo l'instruzione di return arr viene automaticamente deallocato.

```c
int *func(int k){
    int *arr = malloc(sizeof(int) * k);
    for(int i = 0; i < k, i++){
        arr[i] = 2 * i;
    }
    return arr; // OK
}


int *array = func(10);
```

arr allocato dinamicamente nell'heap. POtrà essere utilizzato finché non sarà liberato con la chiamata free(arr).

### Allocazione dinamica di un array multidimensionale

```c
double *arr[ROWS];
//oppure
double **arr = malloc(sizeof(double *) * ROWS);
for(int i = 0; i < ROWS; i++){
    arr[i] = malloc(sizeof(double) * COLS);
}
```

Accesso agli elementi sintatticamente equivalente a quelli allocati nello stack

```powershell
1. arr[i][j]
2. (*(arr+i))[j];
3. *(arr[i] + j);
4. *(*arr+i)+j);
```

### Passaggio di array a funzioni. (Allocazione Dinamica)

##### Passaggio di array a una dimensione

Il passaggio di un array come parametro di una funzione avviene sempre per indirizzo. Ricordiamo: il nome di uno array è un puntatore costante al primo elemento dello array).

```c
void init(int *v, int n){
    //...
    for(int j = 0; j < n; j++){
    v[j] = 0;
    }
}
int main(){
    //...
    int *x = malloc(sizeof(int) * 10); //HEAP
    init(x, 10);
}
```

Forma equivalente:

```c
void init(int v[], int n){ //equivalente a int *v
    //...
    for(int j = 0; j < n; j++){
    v[j] = 0;
    }
}
int main(){
    //...
    int *x = malloc(sizeof(int) * 10); //HEAP
    init(x, 10);
}
```

##### Passaggio di array multidimensionali

Per il passaggio di array multidimensionali allocati nell'HEAP, il prototipo della funzione che riceve il dato deve specificare un array di puntatori di un certo tipo che dipende dal numero di dimensioni dello array.

```c
void init(int **v, int m) //OK
void init(int *v[], int m) //OK
void main(){
    //...
    int **v = malloc(sizeof(int*) * 5);
    for(int i = 0; i < 5; i++){
        v[i] = malloc(sizeof(int) * 10);
    }
    init(v, 5, 10);
}
```

Array a tre dimensioni:

```c
void init(int ***w, int n, int m, int l); //OK
void init(int **w[], int n, int m, int l) //OK
void main(){
    //...
    int **v = malloc(sizeof(int**) * 5);
    for(int i = 0; i < 5; i++){
        v[i] = malloc(sizeof(int*) * 7);
        for(int j = 0; j < 7; j++){
            v[i][j] = malloc(sizeof(int) * 9);
        }
    }
    init(v, 5, 7, 9);
}
```

### Funzioni calloc() e realloc()

**Calloc** accetta due argomenti.

- dimensione del singolo elemento da allocare [sizeof()]

- numero di elementi totali da allocare

A differenza della funzione malloc, in questo caso tutti i byte dei blocchi che stiamo richiedendo verranno inizializzati a zero.

```c
double *ptr = (double *) calloc(SIZE, sizeof(double));
```

Realloc consente di ridimensionare un blocco di memoria precedentemente allocato nello HEAP.
Se la nuova dimensione è maggiore dell'attuale, i dati già presenti nel blocco non subiranno cambiamenti.

```c
double *ptr = (double *) malloc(sizeof(double) * SIZE);
//...
ptr = (double *) realloc(ptr, SIZE * 2);
```

-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-

### Diagrammi grafici delle strutture allocate dinamicamente.

##### int *a | Puntatore dinamico a int

![int_1_levels.png](C:\Users\giuli\Desktop\int_1_levels.png)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *a = malloc(sizeof *a);  // alloco un int su heap
    *a = 42;                     // scrivo il valore dentro al blocco
    printf("%d\n", *a);          // leggo tramite dereferenziazione
    free(a);                     // libero il blocco
    return 0;
}
```

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-12-19-17-15-image.png" title="" alt="" data-align="center">

##### int **a |

![int_2_levels.png](C:\Users\giuli\Desktop\int_2_levels.png)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int **a = malloc(sizeof *a);   // livello 1: alloco (int**) su heap
    *a = malloc(sizeof **a);       // livello 2: alloco (int*) su heap
    **a = 7;                       // livello 3: l'int vero su heap
    printf("%d\n", **a);           // triplo cammino: a -> *a -> **a
    free(*a);                      // libero l'int*
    free(a);                       // libero l'int**
    return 0;
}
```

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-12-19-17-55-image.png" title="" alt="" data-align="center">

##### int ***a |

<img src="file:///C:/Users/giuli/Desktop/int_3_levels.png" title="" alt="int_3_levels.png" width="824">

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int ***a = malloc(sizeof *a);     // L1: alloco (int***)
    *a = malloc(sizeof **a);          // L2: alloco (int**)
    **a = malloc(sizeof ***a);        // L3: alloco (int*)
    ***a = 100;                       // L4: l'int reale su heap

    printf("%d\n", ***a);             // a -> *a -> **a -> ***a

    free(**a);                        // libero l'int* (blocchetto dell'int)
    free(*a);                         // libero l'int**
    free(a);                          // libero l'int***
    return 0;
}
```

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-12-19-18-53-image.png" title="" alt="" data-align="center">

##### Matrice di int (2x3)

```c
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 2, m = 3;

    // alloco un array di n righe (puntatori a int)
    int **mat = malloc(n * sizeof *mat);

    for (int i = 0; i < n; i++) {
        // ogni riga è un array di m interi
        mat[i] = malloc(m * sizeof *mat[i]);
    }

    // riempio la matrice con valori semplici
    int val = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mat[i][j] = val++;
        }
    }

    // stampo la matrice
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    // libero la memoria
    for (int i = 0; i < n; i++) {
        free(mat[i]);
    }
    free(mat);

    return 0;
}
```

<img title="" src="file:///C:/Users/giuli/Desktop/Screenshot%202025-09-12%20192316.png" alt="Screenshot 2025-09-12 192316.png" data-align="center">

##### char *c | Puntatore dinamico a char

![char_1_levels.png](C:\Users\giuli\Desktop\char_1_levels.png)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char *c = malloc(6);        // alloco 6 byte su heap: "hello" + '\0'
    strcpy(c, "hello");         // riempio il buffer
    printf("%s\n", c);          // uso c come puntatore alla stringa
    free(c);                    // libero il buffer
    return 0;
}
```

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-12-18-19-57-image.png" title="" alt="" data-align="center">

##### char **c | Array dinamico di stringhe

![char_2_levels.png](C:\Users\giuli\Desktop\char_2_levels.png)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n = 2;                                 // voglio 2 stringhe
    char **c = malloc(n * sizeof *c);          // alloco vettore di n (char*)
    c[0] = malloc(6);                          // alloco 1a stringa: "pippo"
    c[1] = malloc(6);                          // alloco 2a stringa: "pluto"
    strcpy(c[0], "pippo");
    strcpy(c[1], "pluto");
    printf("%s %s\n", c[0], c[1]);             // stampo entrambe
    free(c[0]);                                // libero le stringhe
    free(c[1]);
    free(c);                                   // libero il vettore di (char*)
    return 0;
}
```

<img src="file:///C:/Users/giuli/AppData/Roaming/marktext/images/2025-09-12-18-21-12-image.png" title="" alt="" data-align="center">

##### char ***c | Matrice dinamica di stringhe

![char_3_levels.png](C:\Users\giuli\Desktop\char_3_levels.png)

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int n = 2, m = 2;                          // matrice 2x2
    char ***c = malloc(n * sizeof *c);         // alloco vettore di n righe (char**)

    for (int i = 0; i < n; i++) {
        c[i] = malloc(m * sizeof *c[i]);       // per ogni riga, alloco m colonne (char*)
        for (int j = 0; j < m; j++) {
            c[i][j] = malloc(8);               // alloco ogni stringa (max 7 + '\0')
        }
    }

    strcpy(c[0][0], "abba");                    // riempio qualche cella
    strcpy(c[0][1], "noon");
    strcpy(c[1][0], "ciao");
    strcpy(c[1][1], "ok");

    printf("%s %s | %s %s\n",                  // leggo come c[i][j]
           c[0][0], c[0][1], c[1][0], c[1][1]);

    // free in ordine inverso: stringhe → colonne → righe
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) free(c[i][j]);
        free(c[i]);
    }
    free(c);
    return 0;
}
```

<img src="file:///C:/Users/giuli/Desktop/graphviz.svg" title="" alt="graphviz.svg" data-align="center">
