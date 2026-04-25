/*
Scrivere un programma che permetta di simulare una sequenza di N lanci di una coppia di dadi,
dove N è un numero scelto dall’utente oppure una costante scelta a tempo di compilazione.
Il programma dovrà stampare le sequenze dei due numeri (output primo dado e output secondo dado) in due colonne separate.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n;
    printf("Benvenuto! Per decidere quante volte lanciare i dati inserisci un numero: ");
    scanf("%d", &n);

    srand(time(NULL));

    for(int i = 1; i <= n; i++){
        int num1 = rand()%(6-1+1)+1;
        int num2 = rand()%(6-1+1)+1;
        printf("\n %d° lancio: %d\t%d\n", i, num1, num2);
    }

    printf("\nGrazie per aver giocato!");

    return 0;
}