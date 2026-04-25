#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    /*int votiStoria[]={10,20,30,40,50};
    votiStoria[0] = 8;
    votiStoria[1] = 10;
    votiStoria[2] = 8;
    votiStoria[3] = 7;
    votiStoria[4] = 9;

    printf("%d", votiStoria[0]);

    //printf("%zu", sizeof(votiStoria)/sizeof(votiStoria[0])); //%zu per vedere la grandezza in byte

    for(int i=0;i<sizeof(votiStoria)/sizeof(votiStoria[0]);i++){
        printf("\n%d",votiStoria[i]);
    }*/

    int matrix[3][3]={{10,20,30}, {40,50,60}, {70,80,90}};

    for(int riga=0; riga<3;riga++){
        for(int colonna=0; colonna<3;colonna++){
            printf("%d\n", matrix[riga][colonna]);
        }
    }
    return 0;
}