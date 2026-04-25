#include <stdio.h>
int main(){
    int a[5][5] = {
        {8, 3, 9, 0, 10},
        {3, 5, 17, 1, 1},
        {2, 8, 6, 23, 1},
        {15, 7, 3, 2, 9},
        {6, 14, 2, 6, 0}
    };
    
    for(int i = 0; i < 5; i++){
        printf("\n");
        for(int j = 0; j < 5; j++){
            printf("%d ", a[i][j]);
        }
    }

    printf("\n");

    int sommarighe = 0;
    int sommacolonne = 0;

    printf("Somma righe\n");
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            sommarighe += a[i][j];
        }
        printf(" %d", sommarighe);
        sommarighe = 0;
    }

    printf("\nSomma colonne\n");

    for(int j = 0; j < 5; j++){
        for(int i = 0; i < 5; i++){
            sommacolonne += a[i][j];
        }
        printf(" %d", sommacolonne);
        sommacolonne = 0;
    }

return 0;
}