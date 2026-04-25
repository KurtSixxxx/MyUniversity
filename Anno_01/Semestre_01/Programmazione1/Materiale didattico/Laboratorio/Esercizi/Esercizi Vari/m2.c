//Prodotto di una Matrice per uno Scalare

#include <stdio.h>

int main(){

    //Dichiarazione della matrice e dello scalare+
    int mat[4][4];
    int scalare;

    //Chiedo input con scanf della matrice
    printf("Inserisci i valori per la matrice 4x4: ");
    printf("\n");
    for(int i = 0; i <4; i++){
        for(int j = 0; j < 4; j++){
            printf("Matrice[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    //Inserimento del valore scalare
    printf("Inserisci il valore da attribuire allo scalare: ");
    scanf("%d", &scalare);

    //Moltriplicazione della matrice per lo scalare
    for(int i = 0; i <4; i++){
        for(int j = 0; j < 4; j++){
            mat[i][j]*=scalare;
        }
    }

        //Stampa della matrice dopo la moltiplicazione
        printf("Ecco la matrice dopo la moltiplicazione:\n");
        for(int i = 0; i <4; i++){
        for(int j = 0; j < 4; j++){
        printf("[%d]", mat[i][j]);
        }
        printf("\n");
        }

return 0;
}