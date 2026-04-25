#include <stdio.h>
#include <stdbool.h>

#define N 5

void bubbleSort(int arr[], int dim){
    //Versione ottimizzata con sentinella. La sentinella ci permette di effettuare meno iterazioni, poiché tramite essa l'algorimto capisce se l'array è già ordinato o meno. 
    // il ciclo esterno decide quante volte si passa sull’array, for(int i = 0; i < N-1; i++)
    // il ciclo interno decide quali elementi confrontare in quella passata. for(int j = 0; j < N-i-1; j++)
bool scambiato;
    for(int i = 0; i < N-1; i++){ //
        scambiato = 0;
        for(int j = 0; j < N-i-1; j++){ //Questo for serve per "scandire" le iterazioni, spiego meglio, quando abbiamo già ordinato un elemento, lo si sposta nella posizione corretta. Quindi ad esempio l'elemento più grande va all'ultimo indice. Per questo ad un certo punto diminuiamo il numero di indici (N-i-1) perché l'elemento già ordinato non ci interessa più, ma ci interessanoo quelli non ordinati.
            if(arr[j] > arr[j+1]){ //Se l'elemento precedente è maggiore del successivo fai lo swap (sotto)
                int tmp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = tmp;
                scambiato = 1; //Imposta la sentinella su true, vuol dire che è avvenuto uno scambio
            }
        }
        if(scambiato == 0) break; //Se la sentinella è su false, quindi non è avvenuto uno scambio, allora esci dal ciclo
    }
    for(int i = 0; i < N; i++) printf("%d ", arr[i]);
}

void insertionSort(int arr[], int dim){
    //Questo algoritmo è molto simile a quando sistemiamo le carte che abbiamo in mano durante una partita
    for(int i = 1; i < N; i++){ //Si parte dal secondo elemento, perché consideriamo il primo già ordinato
        int key = arr[i]; //Selezioniamo una cosiddetta key, ossia il valore i da confrontare
        int j = i - 1; //j è il valore precedente alla key, e funge anche da cursore per vedere se siamo dentro i limiti dell'array

        while(j >= 0 && arr[j] > key){ //Finché j è maggiore o uguale a zero, e l'elemento in posizione j è maggiore di key
            arr[j+1] = arr[j]; //Si sposta l'elemento j al posto di j+1 (ossia la chiave)
            j--; //Si diminuisce il valore del cursore per vedere se siamo ancora dentro l'array e spostare tutto in posizione corretta
        }

        arr[j+1] = key; //E al posto dell'elemento che abbiamo scambiato (j+1) inseriamo quello che era nella chiave. Quindi questa è la fase di swapping
    }
    for(int i = 0; i < N; i++) printf("%d ", arr[i]);
}

void selectionSort(int arr[], int dim){
    //In questo algoritmo si cerca un minimo e lo si sposta nella "parte ordinata" dell'array
    for(int i = 0; i < N - 1; i++){ //Si imposta n-1 perché dopo tutte le passate l'elemento in posizione finale è già ordinato,.
        int min = i; //Assumiamo che l'elemento i sia il minimo
        for(int j = i + 1; j < N; j++){ //Parte da i + 1 perché stiamo ordinando solo la parte non ordinata dell'array. gli elementi da 0 fino a i-1 sono già sistemati e non devono più essere toccati.
            if(arr[j] < arr[min]) min = j; //Se l'elemento in posizione j è minore del minimo allora il minimo è j, e quindi aggiorniamo min = j dicendo che l'elemento minimo si trova in indice j
        }
        if(min != i){ //Se alla fine del ciclo vediamo che il minimo è diverso da i, ossia da ciò che avevamo assunto all'inizio, allora facciamo lo swap
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
    for(int i = 0; i < N; i++) printf("%d ", arr[i]);
} 

int main(){
    int arr[N] = {8, 2, 5, 1, 9};

    printf("Bubble Sort: ");
    bubbleSort(arr, N);

    int arr2[N] = {8, 2, 5, 1, 9};
    printf("\nInsertion Sort: ");
    insertionSort(arr2, N);

    int arr3[N] = {8, 2, 5, 1, 9};
    printf("\nSelection Sort: ");
    selectionSort(arr3, N);

    printf("\n");
    return 0;

}