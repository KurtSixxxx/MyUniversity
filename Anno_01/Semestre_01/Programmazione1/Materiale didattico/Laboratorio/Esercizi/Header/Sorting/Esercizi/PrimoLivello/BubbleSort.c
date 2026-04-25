//Ordina l’array [5, 1, 4, 2, 8] e mostra ogni passaggio.
//Cosa succede se l’array è già ordinato? Provalo con [1, 2, 3, 4, 5].

#include <stdio.h>

void printArr(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("|%d|", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; i++){
        int swap = 0;
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap = 1;
            }
        }
        
        // 🔽 Qui stampi dopo ogni passaggio
        printf("Passaggio %d: ", i+1);
        printArr(arr, n);

        if(swap == 0){
            printf("Array già ordinato!\n");
            break;
        }
    }
}


int main(){
    int arr[] = {5, 1, 4, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array prima del bubbleSort:\n");
    printArr(arr, n);

    printf("\n");

    printf("Array dopo il bubbleSort:\n");   
    bubbleSort(arr, n);
    printArr(arr, n);

    return 0;
}