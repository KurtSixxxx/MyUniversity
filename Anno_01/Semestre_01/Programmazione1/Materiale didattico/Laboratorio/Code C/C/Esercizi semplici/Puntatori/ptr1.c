/*Esercizio 1: Dichiarazione e Uso dei Puntatori
Scrivi un programma in C che:

Dichiara un puntatore a un intero.
Assegna il valore di una variabile intera a cui il puntatore deve puntare.
Modifica il valore della variabile tramite il puntatore.
Stampa il valore della variabile prima e dopo la modifica.*/


#include <stdio.h>

int main(){

    int a = 5; //dichiaro un intero

    int *ptr = &a; //dichiaro un puntatore e gli assegno l'indirizzo di memoria di int a

    printf("Valore prima della modifica: %d\n", *ptr); //Stampo il valore prima della modifica

    *ptr = 6;  //Modifico il valore della variabile

    printf("Valore dopo della modifica: %d\n", *ptr); //Stampo il valore dopo della modifica

    return 0;
}