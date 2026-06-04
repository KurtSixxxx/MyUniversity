/* Esercizio 2 — Bubble Sort al contrario
Invece di ordinare in ordine crescente, fai il Bubble Sort decrescente

Crea un array: {1, 4, 2, 5, 3}

Modifica il confronto da > a <

Risultato atteso: 5 4 3 2 1 */

#include <stdio.h>

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j<n-i-1; j++){
            if(arr[j]<arr[j+1]){
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {1, 4, 2, 5, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array prima: ");
    printArr(arr, n);

    bubbleSort(arr, n);
    
    printf("Array dopo: ");
    printArr(arr, n);

    return 0;
}