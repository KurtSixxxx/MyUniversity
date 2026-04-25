#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int main(){

    //insertion sort
    int a[10]={10,2,3,7,8,6,5,43,21,11};
    int temp;

    for(int i=0; i<10;i++){
        printf("\nPrimo array[%d]:%d", i, a[i]);
    }

    for (int i = 1; i < 10; i++) { 
        temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    printf("\n");
    for(int i=0; i<10;i++){
        printf("\nInsertion sort[%d]:%d", i, a[i]);
    }

    printf("\n");

    /*void insertion(int A[], unsigned lunghezza) {

    for (int i = 1; i < lunghezza; i++){
        int key = A[i];
        int j = i - 1;
        while (j >= 0 && key<A[j]){
            A[j+1] = A[j];
            j--;
        }
    A[j+1] = key;
    }
}

int main(){
    int A[] = {90, 23, 45, 12, 2, 5, 9};
    int n = sizeof (A)/sizeof (A[1]);

    insertion (A, n);

    for (int i=0; i<n; i++){
        printf("\n%d", A[i]);
    }
}*/

    //bubble sort
    int b[10]={83,42,35,1,2,6,54,90,112,4};
    int temp2;

    for(int i=0; i<10;i++){
        printf("\nSecondo array[%d]:%d", i, b[i]);
    }

    for(int j = 0; j < 10 - 1; j++){
        for(int i = 0; i < 10 - 1; i++){
            if(b[i] > b[i + 1]){
                temp2 = b[i];
                b[i] = b[i + 1];
                b[i + 1] = temp2;
            }
        }
    }

    printf("\n");
    for(int i=0;i<10;i++){
        printf("\nBubble sort[%d]:%d", i, b[i]);
    }
    printf("\n");

    /*void bubble(int arr[], int n) {           //void bubble (int *A, unsigned size)           pseudocodice
    for (int i = 0; i < n-1; i++) {             // unsigned short swap=1;
                                                // unsigned step = 0;
        for (int j = 0; j < n-i-1; j++) {       //while(swap){
            if (arr[j] > arr[j+1]) {            // swap = 0;
                // swap arr[j] e arr[j+1]       // for (int = 0; i < n-1-step; i++){
                int temp = arr[j];              // if (A[i]>A[i+1]){
                arr[j] = arr[j+1];              // int temp= A[i];
                arr[j+1] = temp;                // A[i]= A[i+1];
            }                                   // A[i+1] = temp;
        }
    }
}

int main() {
    int arr[] = {5, 6, 1, 2, 8, 2, 3, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    bubble(arr, n);

    printf("L'array scambiato è: ");
    for (int i=0; i < n; i++)
        printf("%d ", arr[i]);
}*/


    //selection sort
    int temp3;
    int min;
    int c[10]={33,50,17,20,29,15,7,84,42,31};

    for(int i=0; i<10;i++){
        printf("\nTerzo array[%d]:%d", i, c[i]);
    }
    printf("\n");

    for(int i = 0; i < 10; i++) {
      min = i;
      for (int j = i + 1; j < 10; j++) {
         if (c[j] < c[min])
            min = j;
      }
      temp3 = c[min];
      c[min] = c[i];
      c[i] = temp3;
    }

    for(int i=0;i<10;i++){
        printf("\nSelection sort[%d]:%d", i, c[i]);
    }
}