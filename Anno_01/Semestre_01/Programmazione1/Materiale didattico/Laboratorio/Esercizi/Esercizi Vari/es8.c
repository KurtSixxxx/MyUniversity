/*Esercizio 8:
Crea una funzione che accetta due numeri interi e ritorni il maggiore dei due.
Crea un puntatore a funzione che punti a questa funzione e usa il puntatore per trovare il numero maggiore tra due numeri forniti.*/

#include <stdio.h>

// Funzione che restituisce il maggiore tra due numeri
int funzione (int A, int B){
    if (A > B){
        return A;
    } else {
        return B;
    }
}

int main(){

    // Dichiarazione del puntatore a funzione
    int (*ptr_funzione)(int, int);

    // Assegna l'indirizzo della funzione al puntatore
    ptr_funzione = &funzione;

    // Usa il puntatore a funzione per chiamare la funzione e ottenere il risultato
    int res = ptr_funzione (3, 6);

    // Stampa il risultato
    printf("Risultato: %d", res);

    return 0;
}