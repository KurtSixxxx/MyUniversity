#include <stdio.h>

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int swap = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                swap = 1;
            }
        }
        if(swap == 0){
            break;
        }
    }
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            int tmp = arr[i];
            arr[i] = arr[min];
            arr[min] = tmp;
        }
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printSort(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}
