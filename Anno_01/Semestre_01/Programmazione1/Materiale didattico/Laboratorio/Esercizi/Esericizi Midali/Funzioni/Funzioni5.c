/*Calcolo della potenza di un numero*/

#include <stdio.h>

int calcolo (int base, int esponente){
    int potenza = 1;

    for (int i = 1; i <= esponente; i++) {
        potenza *= base;
    }

    return potenza;
}

int main (){

    int base, esponente;

    printf("inserisci una base: ");
    scanf("%d", &base);

    printf("Inserisci un'esponente: ");
    scanf("%d", &esponente);

    int potenza = calcolo(base, esponente);

    printf("Risultato: %d", potenza);

    return 0;
}