/*Calcolo della somma degli elementi di una matrice 3x3*/

#include <stdio.h>

int main (){

    int matrice [3][3] = {{2, 2, 2},{3, 3, 3},{4, 4, 4}};

    int somma = 0;

    for(int riga = 0; riga < 3; riga++){
        for(int colonna = 0; colonna < 3; colonna++){
            somma += matrice[riga][colonna];
        }
    }


printf("IL risultato della somma è %d", somma);

    return 0;
}