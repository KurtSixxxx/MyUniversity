/*L'algoritmo di ricerca dicotomica (o ricerca binaria) è un algoritmo di ricerca efficiente che si applica solo a array ordinati.
Il principio alla base della ricerca dicotomica è quello di dividere l'array in due parti uguali, confrontare il valore della posizione centrale con il valore che si sta cercando, e quindi ripetere il processo su una delle due parti 
dell'array. Ecco i passi per implementare l'algoritmo di ricerca dicotomica:
1)Inizializza due indici low e high per indicare le estremità dell'array.
2)Calcola l'indice mid della posizione centrale dell'array come mid = (low + high) / 2.
3)Se il valore alla posizione mid è uguale al valore che si sta cercando, hai trovato l'elemento 
e puoi interrompere il ciclo.
4)Se il valore alla posizione mid è minore del valore che si sta cercando, imposta low su mid + 1 e ripeti i passi 2-4.
5)Se il valore alla posizione mid è maggiore del valore che si sta cercando, imposta high su mid - 1 e ripeti i passi 2-4.
6)Se hai controllato tutti gli elementi dell'array senza trovare l'elemento che stai cercando, significa che l'elemento non è presente nell'array.*/
#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == target) {
            return mid; // restituisce l'indice dell'elemento trovato
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // restituisce -1 se l'elemento non è stato trovato
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = binary_search(arr, size, target);

    if(result != -1) {
        printf("Elemento trovato all'indice %d\n", result);
    } else {
        printf("Elemento non trovato nell'array\n");
    }

    return 0;
}
/*Nel codice sopra, la funzione binary_search prende come argomenti un array arr, la sua dimensione size, e il valore target che si sta cercando. La funzione restituisce l'indice 
dell'elemento trovato se è presente nell'array, altrimenti restituisce -1. Nella funzione main, viene definito un array arr di interi, la sua dimensione size, e il valore target 
da cercare. La funzione binary_search viene chiamata con questi argomenti, e il risultato viene memorizzato nella variabile result. Se il risultato è diverso da -1, l'elemento 
è stato trovato e l'indice viene stampato utilizzando printf. Se il risultato è uguale a -1, l'elemento non è stato trovato e viene stampato un messaggio di errore.*/
