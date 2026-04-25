//Esercizio 5

#include <stdio.h>

// Mi servono: una funzione, un puntatore e la variabile di tipo 'int' da modificare.

int *ptr; // Dichiaro il puntatore

void func (int *ptr){ // Dichiaro la funzione
*ptr = *ptr + 5; // Incrementa il valore a cui punta il puntatore
}

int main(){
int x = 20; // Dichiaro la variabile intera

func(&x); // Chiamo la funzione e come parametro passo il puntatore alla variabile x alla funzione

printf("l nuovo valore di x è: %d\n", x);

return 0;
}