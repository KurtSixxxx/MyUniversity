#include <stdio.h>
#include "sorting.h"

int main() {
    int arr[] = {9, 1, 5, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Originale: ");
    printSort(arr, n);

    // Scommenta uno alla volta per provare
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    insertionSort(arr, n);

    printf("Ordinato: ");
    printSort(arr, n);

    return 0;
}