//Es 1
//Ordina passo dopo passo questo array: 7 2 5 3 1

#include <stdio.h>

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j]>arr[j+1]){
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
    int arr[] = {7,2,5,3,1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array prima dell'ordinamento:\n");
    printArr(arr, n);

    printf("Array dopo l'ordinamento:\n");
    bubbleSort(arr, n);
    printArr(arr, n);

    return 0;
}