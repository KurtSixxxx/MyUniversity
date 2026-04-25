#include <stdio.h>
int main(){

    //Dichiaro l'array e la variabile per inserire i valori
    int a[2][2][2];
    int inserito;

    //Inserisco i valori da tastiera usando un triplo for
    for(int i = 0; i < 2; i++){
        printf("Piano %d:\n", i);
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                printf("Inserisci un elemento: ");
                scanf("%d", &inserito);
                a[i][j][k] = inserito;
            }
        }
    }


    //Stampo gli otto valori, nello stesso ordine
    for(int i = 0; i < 2; i++){
        printf("Piano %d:\n", i);
            for(int j = 0; j < 2; j++){
                printf("|");
                for(int k = 0; k < 2; k++){
                    printf("%d|", a[i][j][k]);
                }
                printf("\n");
            }
            printf("\n"); //Separatore tra piani
        }

return 0;
}