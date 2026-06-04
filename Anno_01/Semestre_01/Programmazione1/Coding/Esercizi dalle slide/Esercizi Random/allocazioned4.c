#include <stdio.h>      //Libreria di default
#include <stdlib.h>     //Libreria per allocazione
#include <time.h>       //Libreria per generazioni pseudocasuali, la utilizzeremo per generare stringhe
#include <math.h>       //Per usare round()

int *mediaArtimetica(int **a, int **b, int n, int m, int k){
//Matrice A = N x M
//Matrice B = K x N

    int arr_A[n];
    int arr_B[n];
    int *c = malloc(sizeof(int) * n);

    for(int i = 0; i < n; i++) arr_A[i] = 0;
    for(int i = 0; i < n; i++) arr_B[i] = 0;

     for (int i = 0; i < n; i++) {
        int somma_riga = 0;
        int somma_colonna = 0;

        // Somma della riga i di A
        for (int j = 0; j < m; j++) {
            somma_riga += a[i][j];
        }

        // Somma della colonna i di B (dopo arrotondamento)
        for (int j = 0; j < k; j++) {
            somma_colonna += (int)round(b[j][i]);  // Arrotondiamo i double
        }

        int totale_elementi = m + k;
        int media = (somma_riga + somma_colonna) / totale_elementi;
        c[i] = media;
    }

    return c;
}

int main(){
    int n = 3;
    int m = 4;
    int k = 2;

    int **a = malloc(sizeof(int* ) * n); //n x m
    int **b = malloc(sizeof(int* ) * k); //k x n

    for(int i = 0; i < n; i++) a[i] = malloc(sizeof(int) * m);
    for(int i = 0; i < k; i++) b[i] = malloc(sizeof(int) * n);

    srand(time(0));

    int range_min = 1;
    int range_max = 25;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            a[i][j] = rand() % (range_max - range_min + 1) + range_min;
        }
    }

    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = rand() % (range_max - range_min + 1) + range_min;
        }
    }

    printf("Matrice A");
    for(int i = 0; i < n; i++){
        printf("\n");
            for(int j = 0; j < m; j++){
                printf("%d ", a[i][j]);
            }
        }

    printf("\n");
    printf("\n");

    printf("Matrice B");
    for(int i = 0; i < k; i++){
        printf("\n");
            for(int j = 0; j < n; j++){
                printf("%d ", b[i][j]);
            }
        }    

    printf("\n");
    printf("\n");

    int *arr_2d;
    arr_2d = mediaArtimetica(a, b, n, m, k); 

    printf("Array C\n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr_2d[i]);
    }

    return 0;
}