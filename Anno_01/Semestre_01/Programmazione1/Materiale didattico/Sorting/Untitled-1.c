#include <stdio.h>

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){ //Questo for itera sui giri totali che deve fare l'algoritmo
        for(int j = 0; j < n-i-1; j++){ //Questo for itera sulle coppie da confrontare
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {5, 3, 1, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array prima dell'ordinamento:\n");
    printArr(arr, n);

    bubbleSort(arr, n);    // chiamata alla funzione di ordinamento

    printf("Array dopo l'ordinamento:\n");
    printArr(arr, n);

    return 0;
}