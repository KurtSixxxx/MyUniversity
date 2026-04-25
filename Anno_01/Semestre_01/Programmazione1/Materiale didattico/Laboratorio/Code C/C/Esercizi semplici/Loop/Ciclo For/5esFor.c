// Chiedere all'utente di inserire un numero intero base e un numero intero esponente,
// quindi calcolare la potenza base^esponente utilizzando un ciclo for.

#include <stdio.h>

int main (){

int base, esponente;
int potenza = 1;

printf("Inserisci un intero base e un numero intero esponente \n");

printf("Base: ");
scanf("%d", &base);

printf("Esponente: ");
scanf("%d", &esponente);

// potenza = base^esponente

for (int i = 1; i <= esponente; i++) {
        potenza *= base;
    }

printf("%d elevato a %d equivale a %d\n", base, esponente, potenza);

    return 0;
}