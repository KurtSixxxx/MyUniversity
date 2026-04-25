//Scrivi un programma in C che prenda in input due matrici 3x3 e calcoli la loro somma. La matrice somma deve essere stampata alla fine.
#include <stdio.h>

int main() {
    // Dichiarazione e inizializzazione delle matrici
    int m1[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int m2[3][3] = {
        {2, 4, 6},
        {8, 10, 12},
        {14, 16, 18}
    };

    int somma[3][3];

    // Ciclo per stampare gli elementi di m1 e m2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("m1[%d][%d] = %d\tm2[%d][%d] = %d\n", i, j, m1[i][j], i, j, m2[i][j]);
        }
    }


    // Ciclo per la somma di m1 e m2 e inserimento in somma
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            somma[i][j] = m1[i][j] + m2[i][j];
        }
    }

printf("\n");

    // Stampa della matrice somma
    printf("Somma delle due matrici: \n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("[%d]", somma[i][j]);
        }
        printf("\n");
    }
    return 0;
}
