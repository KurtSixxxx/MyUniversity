#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char input[256];
    int N;
    int M;
} Params;

Params readInput(int argc, char* argv[]){
    Params p = {0, 0, 0};

    if(argc != 4){
        fprintf(stderr, "[ERR]: Il numero di parametri deve essere pari a 3.\n");
        exit(-1);
    }

    strcpy(p.input, argv[1]);
    if(strlen(argv[1]) > 256){
        fprintf(stderr, "[ERR]: Nome di file input troppo lungo. (MAX: 265)\n");
        exit(-1);
    }

    char **end = malloc(sizeof(char*));
    *end = NULL;
    p.N = (int) strtol(argv[2], end, 0);
    p.M = (int) strtol(argv[3], end, 0);
    
    if(**end){
        fprintf(stderr, "[ERR]: I parametri N e M devono essere un interi.\n");
        exit(-1);
    }

    if(p.N < 5 || p.N > 10){
        fprintf(stderr, "[ERR]: Il parametro N deve essere compreso tra [5,10].\n");
        exit(-1);
    }

    if(p.M < 5 || p.M > 10){
        fprintf(stderr, "[ERR]: Il parametro N deve essere compreso tra [5,10].\n");
        exit(-1);
    }

    return p;
}

double*** allocateMatrix(Params p){
    double ***M = malloc(sizeof(double**) * p.N);
    if(M == NULL){
        fprintf(stderr, "[ERR]: Errore nel processo di allocazione matrice. (lv1)\n");
        return NULL;
    }

    for(int i = 0; i < p.N; i++){
        M[i] = malloc(sizeof(double*) * p.M);
        if(M[i] == NULL){
        fprintf(stderr, "[ERR]: Errore nel processo di allocazione matrice. (lv1)\n");
        return NULL;
        }
    }

    for(int i = 0; i < p.N; i++){
        for(int j = 0; j < p.M; j++){
            M[i][j] = malloc(sizeof(double));
            if(M[i][j] == NULL){
                fprintf(stderr, "[ERR]: Errore nel processo di allocazione matrice. (lv1)\n");
                return NULL;
            }
        }
    }

    return M;
}

void fillMatrix(double ***M, Params p){
    FILE *fp = fopen(p.input, "r");
    if(fp == NULL){
        fprintf(stderr, "[ERR]: Errore nel processo di apertura file.\n");
        exit(-1);
    }

    for(int i = 0; i < p.N; i++){
        for(int j = 0; j < p.M; j++){
            fscanf(fp, "%lf ", M[i][j]);
        }
    }

    fclose(fp);
}

void printMatrix(double ***M, Params p){
    for(int i = 0; i < p.N; i++){
        for(int j = 0; j < p.M; j++){
            printf("%lf ", *M[i][j]);
        }
        printf("\n");
    }
}

void normalize(double ***M1, double ***M2, Params p){
    double columnsMax[p.M]; //in questo array inserisco tutti i massimi che trovo per ogni colonna. E per normalizzare dividiamo per il numero di elementi

    for(int j = 0; j < p.M; j++){ //ceco il massimo in ogni colonna
        columnsMax[j] = *M1[0][j]; //partiamo dal primo della colonna j
        for(int i = 1; i < p.N; i++){ //scorriamo tutti gli elementi della colonna
            if(*M1[i][j] > columnsMax[j]){ //se si trova un nuovo massimo lo aggiorniamo
                columnsMax[j] = *M1[i][j];
            }
        }
    }

    //questa è la fase di normalizzazione, dove ogni elemento viene diviso
    //cioè facciamo l'elemento / massimo della colonna 
    for(int i = 0; i < p.N; i++){ 
        for(int j = 0; j < p.M; j++){
            *M2[i][j] = *M1[i][j] / columnsMax[j]; //e il risultato della divisione si inserisce nella M2
        }
    }
}

void sortMatrixCols(double ***M, Params p){
    for(int j = 0; j < p.M; j++){
        for(int pass = 0; pass < p.N - 1; pass++){
            bool sentinella = 0;
                for(int i = 0; i < p.N - pass - 1; i++){
                    if(*M[i][j] > *M[i+1][j]){
                        double tmp = *M[i][j];
                        *M[i][j] = *M[i+1][j];
                        *M[i+1][j] = tmp;
                        sentinella = 1;
                    }
                }
            if(sentinella == 0) break;
        }
    }
}

void freeMatrix(double*** M, Params p){
    for(int i = 0; i < p.N; i++){
        for(int j = 0; j < p.M; j++){
            free(M[i][j]);
        }
        free(M[i]);
    }
    free(M);
}

int main(int argc, char* argv[]){
    Params p = readInput(argc, argv);

    double*** A = allocateMatrix(p);
    double*** B = allocateMatrix(p);

    fillMatrix(A, p);
    fillMatrix(B, p);

    printf("\n** A **\n");
    printMatrix(A, p);

    printf("\n");

    //normalize
    normalize(A, B, p);
    printf("\n** B **\n");
    printMatrix(B, p);

    printf("\n** B (sorted columns) **\n");
    sortMatrixCols(B, p);
    printMatrix(B, p);

    freeMatrix(A, p);
    freeMatrix(B, p);
}

