/*Somma di un Array Dinamico
Scrivi un programma che:
- Chiede all'utente di inserire il numero di elementi che desidera memorizzare.
- Utilizza malloc per allocare memoria per un array di interi.
- Chiede all'utente di inserire i valori degli interi.
- Calcola e stampa la somma degli elementi dell'array.
- Dealloca la memoria utilizzata
______________________________________________________________________________________________________*/

#include <stdio.h>
#include <stdlib.h>

//Funzione somma
int somma(int arr[], int dim){
    int s = 0;
    for(int i = 0; i < dim; i++){
        s += arr[i];
    }
    return s;
}

void printArray(int arr[], int dim){
    for(int i = 0; i < dim; i++){
        printf("[%d] ", arr[i]);
    }
    
    printf("\n");

    int totale = somma(arr, dim);
    printf("Sommma degli elementi dell'array dinamico: [%d]\n", totale);

}

int main(){

int dim;
printf("Inserire la dimensione dell'array:\n");
scanf("%d", &dim);


int *arr;
arr = (int*) malloc(dim * sizeof(int));
if (arr == NULL){
    printf("Allocazioe fallita.\n");
    return 1;
}

printf("Inserire i valori degli array:\n");
for(int i = 0; i < dim; i++){
scanf("%d", &arr[i]);
}

printArray(arr, dim);

free(arr);
return 0;
}