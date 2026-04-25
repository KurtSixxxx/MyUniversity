/*
Selection Sort
Ordina [29, 10, 14, 37, 13] e scrivi:
[X] il minimo trovato
[X] l'indice del minimo
[X] l'array dopo lo scambio
*/

#include <stdio.h>

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("|%d|", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){                                   //ricerca del minimo
            if(arr[j]<arr[min]){                                        //se trovo un minimo
                min = j;                                                //lo aggiorno
            }
        }
//Scambio
printf("Minimo trovato: %d\t", arr[min]);
printf("Indice del minimo: %d\n", min);

        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
printf("\n");
                        // Stampa l'array dopo lo scambio
                        printf("Array dopo lo scambio: \t");
                        printArr(arr, n);
                        printf("\n");
        }
    }
}

int main(){
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr, n);
    return 0;
}