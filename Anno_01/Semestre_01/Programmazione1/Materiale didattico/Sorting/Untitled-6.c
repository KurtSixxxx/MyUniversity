#include <stdio.h>

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        //Scambia solo se necessario
        if(min != i){
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
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
    int arr[] = {5, 8, 1, 4, 3};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array prima: ");
    printArr(arr, n);

    printf("Array dopo: ");
    selectionSort(arr, n);
    printArr(arr, n);

    return 0;
}