//Calcolo della matrice trasposta

#include <stdio.h>

 #define righe 3 //Definisco le righe (che hanno un valore di 3)
 #define colonne 3 //Definisco le colonne (che hanno un valore di 3 dato che è una matrice 3x3)

int main(){

// Dichiaro e inizializzo la matrice
    int matrice[righe][colonne] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
    };

    int tra[colonne][righe]; // Indico la trasposta e dico che righe e colonne si invertono

// Calcolo della matrice trasposta
for(int i = 0; i < righe; i++){
    for(int j = 0; j < colonne; j++){
        tra[j][i] = matrice[i][j];
    }
}

//Stampa della matrice originale
printf("Matrice Originale:\n");
for(int i = 0; i < righe; i++){
    for(int j = 0; j < colonne; j++){
        printf("[%d]", matrice[i][j]);
    }
    printf("\n");
}

//Stampa della trasposta
printf("\nMatrice Trasposta:\n");
for(int i = 0; i < colonne; i++){
    for(int j = 0; j < righe; j++){
        printf("[%d]", tra[i][j]);
    }
    printf("\n");
}

return 0;
}