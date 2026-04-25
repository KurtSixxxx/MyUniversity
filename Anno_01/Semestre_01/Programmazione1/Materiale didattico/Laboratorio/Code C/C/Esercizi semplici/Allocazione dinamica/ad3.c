/*
Esercizio 3: Ridimensionamento con realloc()
Obiettivo
1. Alloca un array di 3 interi con malloc(),
2. inizializza i valori.
3. Poi usa realloc() per aumentare la dimensione dell'array a 6 elementi,
4. aggiungi nuovi valori
5. stampa tutto.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

//Alloco un array di 3 interi con malloc().
    int *arr = (int*) malloc(3 * sizeof(int));

//Inizializzo i valori
for(int i = 0; i < 3; i++){
    arr[i] = (i + 1) * 10;
}

//Aumento la dimensione 3 -> 6 con realloc()
arr = (int*) realloc(arr, 6 * sizeof(int));

//Aggiungo nuovi valori.
for(int i = 3; i < 6; i++){
    arr[i] = (i + 1) * 10;
}

//Stampo tutto l'array.
for(int i = 0; i < 6; i++){
    printf("[%d] ", arr[i]);
}
printf("\n");

//Libero la memoria.
free(arr);
return 0;
}