# Algoritmi di Ordinamento - Sorting

---

Prima di introdurre i tre algoritmi che andremo a studiare, è opportuno introdurre il concetto di **complessità**, per capire quali sono le caratteristiche di un algoritmo e cosa influisce in un algoritmo che sia più efficiente di un altro.

### Complessità

La complessità è un modo per definire il **comportamento** nel **tempo** e nella **memoria** impiegato da un algoritmo in relazione al **numero di dati** che vogliamo ordinare con un algoritmo.
La complessità serve proprio a **stimare come cresce la fatica** dell’algoritmo **quando aumenta il numero di dati** da elaborare.
Più elementi abbiamo, più tempo e fatica occorreranno all'algoritmo per poter arrivare alla fine del lavoro in cui tutto è ordinato.

Esempio:

Immaginiamo di voler lavare 5 piatti, il tempo sarà poco.
Ma immaginiamo di voler lavare 200 piatti. Utilizzeremo lo stesso metodo - quindi lo stesso algoritmo (bagnare, insaponare, sciacquare, asciugare, ...) - ma il tempo impiegato sarà ovviamente molto di più.

##### Come si indica?

Si utilizza la lettera $O()$, chiamata **Big O**, e indica **quanto “grande”** diventa il tempo necessario al crescere di $n$. La lettera $n$, invece, indica il **numero di dati** da voler ordinare.

##### I loop:

Quando utilizziamo un ciclo for come:
`for(int i = 0; i < n; i++)` stiamo dicendo che la complessità temporale sarà $O(n)$, quindi il carico di lavoro è impiegato su $n$ elementi nel tempo.
Ma se noi abbiamo questa struttura di loop:
`for(int i = 0; i < n; i++) {`
`for(int j = 0; j < n; j++){`

`...}`
allora, avendo un for dentro un for, vuol dire che la complessità sarà $n \space \times \space n$, quindi $O(n^2)$, vuol dire che ci sarà del lavoro da fare in più per l'algoritmo, e quindi più tempo da impiegare. Per ogni $'i'$ ci sono $n$ $'j'$ da "eseguire/iterare".

###### Casi comuni:

Ci sono diversi "**casi comuni**" di complessità.

- La complessità costante
  $O(1)$, il tempo è costante, e se pensiamo che in O(n) la lettera n indica il numero di elementi, allora abbiamo un solo elemento.

- La complessità lineare
  $O(n)$, molto semplicemente: il tempo raddoppia al raddoppiare dei dati.

- La complessità logaritmica
  $O(log \space n)$, qui il tempo cresce molto lentamente.

- La complessità quasi lineare
   $O(n \space log \space n)$, è una "versione" un po’ più lenta di lineare.

- La complessità quadratica
  $O(n²)$ al raddoppiare dei dati raddoppia il tempo.

- La complessità esponenziale
  $O(2^n)$ Quando diciamo che un algoritmo ha complessità esponenziale significa che ogni volta che aggiungi un solo elemento in più, il numero di operazioni raddoppia. Il simbolo “$^2$” o “$^n$” indica una crescita esplosiva: più cresce $n$, più il lavoro cresce a velocità folle.

---

# Algoritmi

### 1. Bubble Sort

E' un algoritmo di ordinamento che effettua confronti di coppie adiacenti (quindi una accanto all'altra). In base all'ordine - che sia crescente o decrescente - verifica quale dei due elementi è maggiore e quale è minore e li inserisce nella posizione corretta.
Il motivo del nome "Bubble" è definito in relazione alla similitudine che viene applicata ai valori in questo algoritmo poiché i valori risalgono in posizione come se fossero delle bolle.
Per non perdere il dato contenuto nella cella dell'array al momento della sostituzione del valore, si utilizza una variabile temporanea.
La complessità dell'algoritmo nel caso peggiore (ossia quando non è ordinato) equivale a $O(n^2)$, nel migliore invece (ossia quando è già ordinato) equivale a $O(n)$.

Un punto debole di questo algoritmo di sorting è quello di effettuare un iterazione aggiuntiva per verificare che sia tutto in ordine. Per questo esiste una versione detta "Bubble Sort con Sentinella"
Qui sotto la versione base del Bubble Sort:

```c
for(int i = 0; i < N-1; i++){
   for(int j = 0; j < N-i-1; j++){
      if(arr[j] > arr[j+1]){
      int tmp = arr[j];
      arr[j] = arr[j+1];
      arr[j+1] = tmp;
         }
       }
     } 
```

### 1.1 Bubble Sort con Sentinella

Dicevamo prima che: una versione migliorata rispetto a quella del classico bubble sort è quella che viene detta “con sentinella”; consiste nel verificare se nelle “passate” tra i vari elementi venga fatto almeno uno scambio, qualora non ne vengano fatti vuol dire che l’array è ordinato e si può fermare con l’esecuzione; piuttosto che eseguire un'altra iterazione per così dire "a vuoto".
Quindi aggiungiamo un valore booleano che chiameremo "scambiato". Se `scambiato == 0` allora non è avvenuto nessuno scambio e l'array è ordinato. Se `scambiato == 1` allora è avvenuto almeno uno scambio
Ecco il codice:

```c
bool scambiato;

for(int i = 0; i < N-1; i++){
    scambiato = 0;
        for(int j = 0; j < N-i-1; j++){
            if(arr[j] > arr[j+1]){
            int tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
            scambiato = 1;
         }
      }
  if (scambiato == 0) break;
}
```

### 2. Insertion Sort

È basato sull’idea di costruire **progressivamente** una porzione ordinata dell’array, **inserendo ogni nuovo elemento nella posizione corretta** rispetto a quelli già ordinati.

L’idea è intuitiva: è lo stesso modo in cui una persona ordinerebbe **le carte in mano**.  
Prende una carta alla volta e la infila nel punto giusto, spostando le altre verso destra se necessario.

L’algoritmo parte dal **secondo elemento** dell’array (indice 1), poiché il primo elemento è già “ordinato da solo”.  
Per ogni elemento, chiamato **chiave** (`key`), l’algoritmo:

1. Lo confronta con gli elementi che si trovano **a sinistra** (già ordinati).

2. **Sposta verso destra** tutti gli elementi che sono maggiori della chiave.

3. Quando trova la posizione corretta, **inserisce la chiave** in quel punto.

Dopo ogni iterazione, la parte sinistra dell’array risulta ordinata.

Codice:

```c
for(int i = 1; i < N; i++){
    int key = arr[i];
    int j = i - 1;

    while(j >= 0 && arr[j] > key){
    arr[j + 1] = arr[j];
    j--;
    }

    arr[j + 1] = key;
}
```

Ecco una versione commentata:

```c
#include <stdio.h>
#define N 5 //Definisco, per comodità, la dimensione dell'array con il define. Il preprocessore saprà cosa fare al momento della compilazione.

int main(){
    int arr[N] = {8, 2, 3, 6, 9}; //Definisco l'array.

    for(int i = 1; i < N; i++){ //Seleziono il secondo elemento come chiave e inizio le passate dell'algoritmo.
        int key = arr[i]; //Ecco che definisco quale elemento sarà la chiave.
        int j = i - 1; //Imposto j all'elemento precedente di i.

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j]; // Sposta l'elemento a destra
            j = j - 1;           // Passa all'elemento precedente
        }
        arr[j + 1] = key; // Inserisce 'key' nella posizione corretta
    }
//Qui j viene incrementata. Es. Se j = 1 e i = 1 allora j + 1 = 2.
        arr[j+1] = key; //Infine imposta la nuova chiave per continuare l'algoritmo.
    }

    for(int i = 0; i < N; i++) printf("%d ", arr[i]); //Poi stampo tutto per verificare che l'array sia stato ordinato.
}
```

### 3. Selection Sort

Il **Selection Sort** è un algoritmo di ordinamento semplice e intuitivo.  
Si basa sull’idea di **selezionare** (da cui il nome “selection”) ogni volta l’**elemento minimo** dell’array non ordinato e posizionarlo **nella sua posizione corretta**.

In pratica, l’array viene diviso idealmente in due parti:

- una **parte ordinata** a sinistra,

- e una **parte non ordinata** a destra.

A ogni passo, l’algoritmo trova il **minimo** della parte non ordinata e lo **scambia** con il primo elemento di quella parte.  
Dopo ogni iterazione, la sezione ordinata cresce di un elemento.

##### Funzionamento

Si parte dal primo elemento dell’array.

1. Si cerca l’elemento **più piccolo** tra tutti quelli rimanenti.

2. Si **scambia** con l’elemento attuale (cioè quello in posizione `i`).

3. Si passa all’indice successivo e si ripete fino alla fine dell’array.

Alla fine di ogni passata, il valore più piccolo tra quelli rimasti “scivola” nella posizione corretta.

```c
for (int i = 0; i < N - 1; i++)        // per ogni posizione dell’array
{
    min = i;                           // suppongo che l’attuale sia il più piccolo

    for (int j = i + 1; j < N; j++)    // confronto con tutti quelli successivi
    {
        if (arr[j] < arr[min])         // se ne trovo uno più piccolo...
            min = j;                   // ...segno dov’è
    }

    if (min != i) {                    // se ho trovato un vero minimo altrove...
        temp = arr[i];                 // ...faccio lo scambio.
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
```
