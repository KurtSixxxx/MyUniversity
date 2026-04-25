/*Esercizio 1: Allocazione e Inizializzazione con malloc()
Obiettivo: Alloca un array di 5 interi usando malloc(), inizializza i valori a 1, 2, 3, 4, 5 e stampa i valori.*/

#include <stdio.h>
#include <stdlib.h>

int main(){

int numEl = 5; //definisco il numero di elementi
int *arr = (int*) malloc(numEl * sizeof(int)); //chiamo la funzione calloc

//inizializzo i valori
for(int i = 0; i<numEl; i++){
    arr[i] = i + 1;
}

//scrivo un ciclo for per la stampa dell'array
for(int i = 0; i<numEl; i++){
    printf("[%d]", arr[i]);
}
printf("\n");

free(arr); //libera la memoria allocata

return 0;
}