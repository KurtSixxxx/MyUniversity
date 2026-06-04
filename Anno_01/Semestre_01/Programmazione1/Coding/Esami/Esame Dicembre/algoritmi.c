#include <stdio.h>
#include <stdbool.h>
#define N 5


// =========================
// BUBBLE SORT (con commenti)
// =========================
void bubble_sort_con_commenti(){
    int arr[5] = {8, 2, 3, 6, 9};     //Dichiaro l'array di dimensione N ed i suoi elementi
    for(int i = 0; i < N-1; i++){     //Questo for conta le iterazioni totali per ordinare N elementi. La condizione di terminazione si basa sul fatto che, ad ogni passaggio del ciclo esterno, l'elemento più grande tra quelli non ancora ordinati viene posizionato correttamente alla fine del sotto-array considerato (come una "bolla" che sale).
        bool sentinella = 0;      //Dichiaro la sentinella booleana che ci serve per poter capire se l'array è ordinato o no
            for(int j = 0; j < N - i - 1; j++){ //La condizione j < N-i-1 serve a limitare i confronti del ciclo interno alla porzione dell'array ancora da ordinare, escludendo gli elementi già posizionati correttamente in coda.
                if(arr[j] > arr[j+1]){ //Se l'elemento adiacente a j è maggiore di j scambia (contenuto dell'if)
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                sentinella = 1;    //Imposto scambiato ad 1 perché è avvenuto uno scambio
                }
            }
        if(sentinella == 0) break;     //Se la sentinella è uguale a 0 allora non è avvenuto nessuno scambio e non serve iterare ancora
        }
}


// ==============================
// BUBBLE SORT (senza commenti)
// ==============================
void bubble_sort(){
    int arr[N] = {8, 2, 3, 6, 9};
    for(int i = 0; i < N-1; i++){
        bool sentinella = 0;
        for(int j = 0; j < N - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                sentinella = 1;
            }
        }
        if(sentinella == 0) break;
    }
}


// ==================================
// INSERTION SORT (con commenti)
// ==================================
void insertion_sort_con_commenti(){
    int arr[5] = {8, 2, 3, 6, 9};     //Dichiaro l'array di dimensione N ed i suoi elementi

    for(int i = 1; i < N; i++){ //Iteriamo dal secondo elemento in poi tenendo in mente il primo come elemento ordinato
        int key = arr[i];        //Impostiamo l'elemento in posizione i come chiave, quindi elemento da confrontare
        int j = i-1;            //Impostiamo un cursore j, che controlla se siamo dentro l'array e si occupa degli scambi

        /*
        * Ciclo interno: Sposta gli elementi della parte ordinata (a sinistra)
        * che sono maggiori di 'key' per fare spazio a 'key'.
        * Continua finché non si trova un elemento minore di 'key' o si arriva all'inizio dell'array.
        */

        while(j >= 0 && arr[j] > key){    //Impostiamo un ciclo while con la condizione: finche j è maggiore o uguale a 0, e l'elemento in posizione j sarà maggiore di k, allora...
            arr[j+1] = arr[j];        //Sposta l'elemento a destra
            j--;                //Passa all'elemento precedente
        }
        
        arr[j+1] = key;         //Inserisci key nella posizione corretta. Nota bene: qui siamo fuori dal ciclo while, quindi j sarà uguale allo somma di (i-1)+1
    }
}


// ==================================
// INSERTION SORT (senza commenti)
// ==================================
void insertion_sort(){
    int arr[N] = {8, 2, 3, 6, 9};

    for(int i = 1; i < N; i++){
        int key = arr[i];
        int j = i-1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        
        arr[j+1] = key;
    }
}


// ================================
// SELECTION SORT (con commenti)
// ================================
void selection_sort_con_commenti(){
    int arr[5] = {8, 2, 3, 6, 9};    //Definisco l'array di dimensione N con i suoi elementi
    
    for(int i = 0; i < N-1; i++){   //per ogni posizione dell’array
        int min = i;            // suppongo che l’attuale sia il più piccolo
        
        for(int j = i + 1; j < N; j++){ // confronto con tutti quelli successivi
            if(arr[j] < arr[min]) min = j;  /// se ne trovo uno più piccolo, allora segno dov'è
        }

        if(min != i){    // se ho trovato un vero minimo altrove, allora faccio lo scambio
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}


// ================================
// SELECTION SORT (senza commenti)
// ================================
void selection_sort(){
    int arr[5] = {8, 2, 3, 6, 9};
    
    for(int i = 0; i < N-1; i++){
        int min = i;

        for(int j = i + 1; j < N; j++){
            if(arr[j] < arr[min]) min = j;
        }

        if(min != i){
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}


// =======================
// MAIN (solo di esempio)
// =======================
int main(){
    printf("File compilato correttamente.\n");
    return 0;
}
