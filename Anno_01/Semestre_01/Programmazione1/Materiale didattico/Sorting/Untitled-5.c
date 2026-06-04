//{9, 3, 5, 7, 1} -> {1, 3, 5, 7, 9}
#include <stdio.h>

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
    void printArr(int arr[], int n){
        for(int i = 0; i < n; i++){
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

int main(){
    int arr[] = {9, 3, 5, 7, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array prima del Sorting: ");
    printArr(arr, n);

    insertionSort(arr, n);
    printf("Array dopo il Sorting: ");
    printArr(arr, n);

    return 0;
}