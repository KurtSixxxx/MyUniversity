/*Calcolo del cubo di un numero*/

#include <stdio.h>

int cubo (int base){
        int risultato = 1; // Iniziamo con 1 perché qualsiasi numero elevato a 0 è 1
        int esponente = 3; // Esponente fisso per il cubo
        for (int i = 0; i < esponente; i++){
            risultato *= base;
        }
        return risultato;
    }

int main (){

int base;

// Chiedere all'utente di inserire la base
    printf("Inserisci la base: ");
    scanf("%d", &base);

    // Calcolare il cubo e stampare il risultato
    printf("Il cubo di %d è %d\n", base, cubo(base));

    return 0;
}