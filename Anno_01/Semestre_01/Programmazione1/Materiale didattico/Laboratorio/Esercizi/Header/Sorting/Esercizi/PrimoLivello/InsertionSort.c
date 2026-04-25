/*
Insertion Sort
- Ordina [12, 11, 13, 5, 6] simulando ogni passo.
- Ordina l’array [1, 2, 3, 4, 5]. Conta quante volte entra nel while.
*/

#include <stdio.h>


void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("|%d|", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){
    int count = 0;
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        printf("\nPasso %d: inserisco %d\n", i, key);

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
            count++;
        }

        arr[j+1] = key;

        // Mostra l'array dopo aver inserito la chiave nella posizione giusta
        printArr(arr, n);
    }

    printf("\nNumero di volte che si entra nel while: %d\n", count);
}
int main(){
    int arr[] = {12, 11, 13, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr, n);
    printArr(arr, n);

    return 0;
}