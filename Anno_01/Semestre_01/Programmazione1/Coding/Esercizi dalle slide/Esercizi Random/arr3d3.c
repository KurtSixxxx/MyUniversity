/*Trova il massimo e il minimo in un array 3D [3][2][2].*/

#include <stdio.h>
int main(){
    int a[3][2][2];
    
    //Inserire gli elementi
    for(int i = 0; i < 3; i++){
        printf("Piano %d\n", i+1);
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                printf("Inserire valore: ");
                scanf("%d", &a[i][j][k]);
            }
        }
    }

    //Stampare valori:
    for(int i = 0; i < 3; i++){
        printf("Piano %d\n", i+1);
        for(int j = 0; j < 2; j++){
            printf("|");
            for(int k = 0; k < 2; k++){
                printf("%d|", a[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //Trovare i valori massimi e minimi;
    int min = a[0][0][0];
    int max = a[0][0][0];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                if(min > a[i][j][k]){
                    min = a[i][j][k];
                }else if(max < a[i][j][k]){
                    max = a[i][j][k];
                }
            }
        }
    }

    printf("Minimo: %d | Massimo: %d", min, max);

    return 0;
}