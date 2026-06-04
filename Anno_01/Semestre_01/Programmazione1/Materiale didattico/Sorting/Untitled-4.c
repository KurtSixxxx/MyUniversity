//Implementazione della funzione <<Insertion Sort>>

#include <stdio.h>

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];          // prendi il valore corrente
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];   // sposta a destra gli elementi maggiori
            j = j - 1;
        }
        arr[j + 1] = key;          // inserisci la key nel posto giusto
    }
}