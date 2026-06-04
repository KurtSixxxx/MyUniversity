/*
Creare due variabili con valori casuali, scambiarle usando un puntatore a funzione o semplicemente una funzione con parametri per riferimento (via puntatori).
Traccia
- Genera due numeri casuali in [1, 50].
- Passali a una funzione swap(int *a, int *b) che scambia i valori.
- Mostra i valori prima e dopo lo scambio.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    srand(time(0));

    int a = rand() % (50 - 1 + 1) + 1;
    int b = rand() % (50 - 1 + 1) + 1;

    printf("Valori prima di scambio\n");
    printf("A: %d \t B: %d\n", a, b);

    swap(&a, &b);
    printf("Valori dopo di scambio\n");
    printf("A: %d \t B: %d\n", a, b);

return 0;
}