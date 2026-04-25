/*Esercizio 4: Puntatori a Funzione
Scrivi un programma in C che:

Definisce una funzione che prende due numeri interi e restituisce la loro somma.
Dichiara un puntatore a funzione e lo fa puntare alla funzione di somma.
Usa il puntatore a funzione per chiamare la funzione di somma e stampa il risultato.*/

#include <stdio.h>

int somma (int A, int B){ // Dichiarazione della funzione
   return (A+B);
}

int main(){

    int (*ptr_somma)(int, int); // Dichiarazione del puntatore a funzione

    ptr_somma = &somma; // Assegnazione del puntatore alla funzione 'somma'

    int res = ptr_somma(4, 6);     // Chiamata della funzione tramite il puntatore
    printf("Risultato %d\n", res); // Stampa del risultato

return 0;
}