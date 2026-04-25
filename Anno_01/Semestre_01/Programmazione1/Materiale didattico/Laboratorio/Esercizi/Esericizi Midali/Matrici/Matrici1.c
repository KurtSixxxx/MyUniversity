/*Inizializzazione e stampa di una matrice 3x3*/

#include <stdio.h>

int main (){

    int array [3][3] = {{11, 22, 33},{44, 55, 66},{77, 88, 99}};
    

    for(int riga = 0; riga < 3; riga++){
        for(int colonna = 0; colonna < 3; colonna++){
        printf("%d", array[riga][colonna]);
    }
    printf("\n");
    }

    return 0;
    }