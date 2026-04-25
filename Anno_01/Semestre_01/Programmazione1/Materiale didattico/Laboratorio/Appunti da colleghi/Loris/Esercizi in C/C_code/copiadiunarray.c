/*
Scrivi un programma che:
    Chiede all'utente di inserire il numero di elementi che desidera memorizzare.
    Utilizza malloc per allocare memoria per un array di interi.
    Chiede all'utente di inserire i valori degli interi.
    Utilizza malloc per allocare un secondo array e copia i valori dal primo array al secondo.
    Stampa i valori del secondo array.
    Dealloca la memoria utilizzata.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){

int dim;
int * arr1;
int * arr2;

printf("Inserire il numero di elementi che desidera memorizzare:\n");
scanf("%d", &dim);

arr1 = (int*)malloc(dim * sizeof(int));
    if(arr1 == NULL){
        printf("Allocazione fallita.\n");
        return 1;
    }

printf("Inserire il valore degli interi che si desidera memorizzare:\n");
for(int i = 0; i < dim; i++){
    scanf("%d", &arr1[i]);
}

arr2 = (int*)malloc(dim * sizeof(int));
if(arr2 == NULL){
        printf("Allocazione fallita.\n");
        free(arr1);
        return 1;
    }

//Copia degli elementi di arr1 in arr2:
for(int i = 0; i < dim; i++){
    arr2[i] = arr1[i];
}


printf("Stampa degli elementi dell'array2 copiati dall'array1:\n");
for(int i = 0; i < dim; i++){
    printf("[%d] ", arr2[i]);
}

free(arr1);
free(arr2);

return 0;
}