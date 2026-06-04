/*Consegna:
Dichiara int b[2][3][4];
Inserisci i valori con triplo for
Calcola e stampa la somma di tutti gli elementi.*/

#include <stdio.h>
int main(){

    //Dichiaro int b[2][3][4]
    int b[2][3][4];
    int inserito;

    //Inserisco i valori con triplo for
    for(int i = 0; i < 2; i++){
        printf("Piano %d:\n", i+1);
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 4; k++){
                printf("Inserire valore: ");
                scanf("%d", &inserito);
                b[i][j][k] = inserito;
            }
        }
    }

    //Stampo array 3D
    for(int i = 0; i < 2; i++){
        printf("Piano %d:\n", i+1);
        for(int j = 0; j < 3; j++){
            printf("|");
            for(int k = 0; k < 4; k++){
                printf("%d|", b[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //Sommo i valori
    int somma = 0;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 4; k++){
                somma+= b[i][j][k];
            }
        }
    }

    printf("Somma: %d", somma);
    return 0;
}