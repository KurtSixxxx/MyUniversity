#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main(){
    double p;
    printf("Inserisci un numero qualunque maggiore o uguale a 0:\n");
    scanf("%lf", &p);

    if(p<0){
        printf("Errore!\n");
        printf("Il numero deve essere maggiore di 0:\n");
        scanf("%lf", &p);
    }

    if(p>=0){
        printf("Numero arrotondato p e': %.2lf\n", round(p));
        double *array = malloc(sizeof(double) *p);
        if(array==0){
            printf("L'array e' nullo!");
        }else{
            printf("L'array e' stato allocato correttamente con dimensione: %.2lf\n", array);
            printf("\nL'array allocato e':\n");
            for (double i=0;i<p;i++){
                printf("%.2lf\n", array);
        }
        free(array);
        printf("\n");
        }
    }
}