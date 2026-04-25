/* Esercizio 1: Bubble Sort
Scrivi il codice per ordinare l'array {10, 3, 5, 8, 2} in ordine crescente usando il Bubble Sort.
Aggiungi un comando che stampi l'array ad ogni passaggio, in modo da vedere come cambia l'array ad ogni scambio.*/

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swap = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swap = 1;
            }
        }
        // Stampa l'array ad ogni passaggio
        printf("Passaggio %d: ", i + 1);
        for (int k = 0; k < n; k++) {
            printf("|%d", arr[k]);
        }
        printf("|\n");

        if (swap == 0) { // Se non ci sono stati scambi, l'array è già ordinato
            break;
        }
    }
}

void printA(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("|%d", arr[i]);
    }
    printf("|\n");
}

int main() {
    int arr[] = {10, 3, 5, 8, 2};
    int n = 5;

    printf("Array prima del sort: ");
    printf("\n");
    printA(arr, n);

    printf("Array dopo il sort:\n");
    bubbleSort(arr, n);
    printA(arr, n);

    return 0;
    exit(0);
}