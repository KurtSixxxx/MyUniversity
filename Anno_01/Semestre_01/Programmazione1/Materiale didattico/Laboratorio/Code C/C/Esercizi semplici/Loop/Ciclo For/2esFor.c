// Utilizzare un ciclo for per calcolare la somma dei numeri da 1 a 100 e stampare il risultato.

#include <stdio.h>

int main (){

    int somma;

    for (int i = 0; i <= 100; i++){
        somma += i;
    }

    printf("La somma dei numeri da 1 a 100 equivale a: %d", somma);

    return 0;
}