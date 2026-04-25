//ricerca sequenziale/lineare in un array
#include <stdio.h>

int sequential_search(int arr[], int size, int target) {
    int i;
    for(i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i; // restituisce l'indice dell'elemento trovato
        }
    }
    return -1; // restituisce -1 se l'elemento non è stato trovato
}

int main() {
    int arr[] = {1, 3, 5, 7, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 5;

    int result = sequential_search(arr, size, target);

    if(result != -1) {
        printf("Elemento trovato all'indice %d\n", result);
    } else {
        printf("Elemento non trovato nell'array\n");
    }

    return 0;
}
/*La ricerca sequenziale è un algoritmo di ricerca che consiste nel cercare un elemento all'interno di un array uno per uno, partendo dal primo elemento dell'array. Ecco i passi 
da seguire per sviluppare un algoritmo di ricerca sequenziale: 1)Inizializza un indice i a 0, che indica la posizione corrente dell'elemento nell'array.
2)Controlla se l'elemento nell'array alla posizione i è uguale al valore che stai cercando. Se sì, hai trovato l'elemento e puoi interrompere il ciclo.
3)Se l'elemento non è quello che stai cercando, incrementa l'indice i di 1 e ripeti il passo 2, fino a quando non hai controllato tutti gli elementi dell'array.
4)Se hai controllato tutti gli elementi dell'array senza trovare l'elemento che stai cercando, significa che l'elemento non è presente nell'array.*/
/*Nel codice sopra, la funzione sequential_search prende come argomenti un array arr, la sua dimensione size, e il valore target che si sta cercando. La funzione restituisce l'indice 
dell'elemento trovato se è presente nell'array, altrimenti restituisce -1. Nella funzione main, viene definito un array arr di interi, la sua dimensione size, e il valore target 
da cercare. La funzione sequential_search viene chiamata con questi argomenti, e il risultato viene memorizzato nella variabile result. Se il risultato è diverso da -1, l'elemento 
è stato trovato e l'indice viene stampato utilizzando printf. Se il risultato è uguale a -1, l'elemento non è stato trovato e viene stampato un messaggio di errore.*/
