/*Esercizio 3*/

#include <stdio.h>

// Dichiaro la funzione (Per tonrare il prodotto si deve fare "return A * B")
int prodotto (int A, int B){
return A * B;
}

int main(){

int a, b;
int res;

printf("Inserisci due numeri: ");
scanf("%d %d", &a, &b);

int (*ptr_prodotto)(int, int); // Dichiaro il puntatore a funzione
ptr_prodotto = &prodotto; // Assegno il puntatore all'indirizzo della funzione

res = ptr_prodotto(a, b); // Salvo il risultato del puntatore a funzione in 'res' che contiene il risultato

printf("Prodotto: %d\n", res);

return 0;
}