/*Esercizio 2*/

#include <stdio.h>

int main(){

int arr[5] = {10, 20, 30, 40, 50};
int *p = arr;

// Stampo l'indirizzo e il primo elemento. Consideriamo che l'array è puntatore a primo elemento dell'array.
printf("Elemento indice zero: %d | Indirizzo array: [%p]\n", *p, p);

printf("\n");

// Stampo gli elementi tramite aritmetica dei puntatori
printf("Elemento di indice zero: %d\n", *p);
printf("Elemento di indice uno: %d\n", *(p+1));
printf("Elemento di indice due: %d\n", *(p+2));
printf("Elemento di indice tre: %d\n", *(p+3));
printf("Elemento di indice quattro: %d\n", *(p+4));

printf("\n");

// Con un ciclo FOR incrememto il puntatore per accedere agli elemeti successivi
for(int i = 0; i < 4; i++){
printf("Elementi stampati tramite ciclo FOR: %d\n", arr[i]);
}

return 0;
}