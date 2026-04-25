/*Ricerca del valore massimo in una matrice 3x3*/

#include <stdio.h>

int main (){

    int matrice [3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};

    int massimo = matrice[0][0];

    for (int riga = 0; riga < 3; riga++){
        for (int colonna = 0; colonna < 3; colonna++){
            if(matrice[riga][colonna]>massimo){
                massimo = matrice[riga][colonna];
        }
    }
}

printf("Valore massimo: %d", massimo);

return 0;
}