//LANCIO DI UNA COPPIA DI DADI

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int n;
    printf("Numero di lanci: ");
    scanf("%d", &n);


    srand(time(0));
    //I dadi hanno 6 facce. [1, 6] con 1 < 6. Quindi rand()%(6 - 1 + 1) + 1
    printf("Dado 1 | Dado 2\n");
    for(int i = 0; i <= n; i++){
        int dado1 = rand()%(6 - 1 + 1) + 1;
        int dado2 = rand()%(6 - 1 + 1) + 1;
        printf("%d | %d\n", dado1, dado2);
    }

    return 0;
}