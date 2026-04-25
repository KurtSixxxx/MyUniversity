#include <stdio.h>

void selection(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j]<arr[min]){
                min = j; //L'elemento più piccolo che ho trovato finora nella parte non ordinata si trova ora all'indice j
            }
        }
        if(min != i){
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

void printA(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("|%d ", arr[i]);
    }
    printf("|\n");
}    

int main(){
    int arr[] = {5,2,4,6,1,3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array prima: \n");
    printA(arr, n); // Questa è utile per vedere l'array originale

    selection(arr, n);

    printf("Array dopo l'ordinamento: \n");
    printA(arr, n); // Questa dovrebbe mostrare l'array ordinato

    return 0;
}