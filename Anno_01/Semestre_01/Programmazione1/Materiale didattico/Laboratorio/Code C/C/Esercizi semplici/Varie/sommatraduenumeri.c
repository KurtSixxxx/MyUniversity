#include <stdio.h>

int main() {
    int numero1;
    int numero2;
    
    // Chiedi all'utente di inserire il primo numero
    printf("Inserisci il primo numero: ");
    scanf("%d", &numero1);

    // Chiedi all'utente di inserire il secondo numero
    printf("Inserisci il secondo numero: ");
    scanf("%d", &numero2);

    // Calcola la somma dopo aver letto i numeri
    int somma = numero1 + numero2;

    // Stampa il risultato
    printf("La somma tra i due numeri equivale a: %d\n", somma);

    return 0;
}
