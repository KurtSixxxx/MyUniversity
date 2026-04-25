/*Esercizio 5: Puntatori a Puntatori
Scrivi un programma in C che:

Dichiara un puntatore a un intero e lo inizializza a un valore specifico.
Dichiara un puntatore a un puntatore a intero e lo fa puntare al primo puntatore.
Modifica il valore dell'intero utilizzando il puntatore a puntatore.
Stampa il valore dell'intero prima e dopo la modifica.*/

#include <stdio.h>

int main(){

// Dichiaro un intero
int x = 10;

// Dichiaro un puntatore a un intero e lo inizializzo al valore di int x
int *p1 = &x;

//Dichiaro un puntatore a un puntatore a intero e lo faccio puntare al primo puntatore
int **p2 = &p1;

// Stampo il valore dell'intero prima della modifica
printf("Valore di x prima della modifica: %d\n", x);

//Modifico il valore dell'intero utilizzando il puntatore a puntatore, ossia p2
**p2 = 6;

printf("Valore di x dopo la modifica: %d\n", x);

return 0;
}