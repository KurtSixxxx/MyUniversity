/*Stampa con etichette*/

#include <stdio.h>
int main(){
    int a[2][2][2];

   //Inserire gli elementi
    for(int i = 0; i < 2; i++){
        printf("Piano %d\n", i+1);
         for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                printf("Inserire valore: ");
                 scanf("%d", &a[i][j][k]);
            }
        }
    }

printf("\n");

    //Stampa con etichetta
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                printf("Piano %d, Riga %d, Colonna %d -> valore %d\n", i+1, j+1, k+1, a[i][j][k]);
            }
        }
    }

return 0;
}