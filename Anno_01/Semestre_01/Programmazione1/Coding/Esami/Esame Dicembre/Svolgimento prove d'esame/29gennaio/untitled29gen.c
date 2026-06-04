#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *input;
    char *output;
    int n;
    int m;
} Params;

Params readInput(int argc, char *argv[]){
    Params p = {0};

    if(argc != 5){
        fprintf(stderr, "Uso: prog <input> <output> <n> <m>\n");
        exit(1);
    }

    p.input = argv[1];
    p.output = argv[2];

    char *endptr;
    p.n = strtol(argv[3], &endptr, 10);
    if(*endptr || p.n <= 0){
        fprintf(stderr, "n non valido\n");
        exit(1);
    }

    p.m = strtol(argv[4], &endptr, 10);
    if(*endptr || p.m <= 0){
        fprintf(stderr, "m non valido\n");
        exit(1);
    }

    return p;
}


double ***allocMatrix(int n, int m){
    double ***M = malloc(n * sizeof(double**));
    if(!M) return NULL;

    for(int i = 0; i < n; i++){
        M[i] = malloc(m * sizeof(double*));
        if(!M[i]) return NULL;

        for(int j = 0; j < m; j++){
            M[i][j] = malloc(sizeof(double));
            if(!M[i][j]) return NULL;
        }
    }

    return M;
}


void freeMatrix(double ***M, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            free(M[i][j]);

        free(M[i]);
    }
    free(M);
}

double ***readMatrix(Params *p){
    FILE *fp = fopen(p->input, "r");
    if(!fp){
        fprintf(stderr, "Errore apertura file\n");
        exit(1);
    }

    double ***M = allocMatrix(p->n, p->m);
    if(!M){
        fprintf(stderr, "Errore allocazione\n");
        exit(1);
    }

    for(int i = 0; i < p->n; i++){
        for(int j = 0; j < p->m; j++){
            if(fscanf(fp, "%lf", M[i][j]) != 1){
                fprintf(stderr, "Errore lettura file\n");
                exit(1);
            }
        }
    }

    fclose(fp);

    printf("Matrice letta:\n");
    for(int i = 0; i < p->n; i++){
        for(int j = 0; j < p->m; j++)
            printf("%8.2lf ", *M[i][j]);
        printf("\n");
    }

    return M;
}

void writeMatrix(char *filename, double ***M, int n, int m){
    FILE *fp = fopen(filename, "w");
    if(!fp){
        fprintf(stderr, "Errore apertura output\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++)
            fprintf(fp, "%.2lf ", *M[i][j]);
        fprintf(fp, "\n");
    }

    fclose(fp);
}


int main(int argc, char *argv[]){
    Params p = readInput(argc, argv);
    double ***M = readMatrix(&p);
    elabMatrix(M, p.n, p.m);
    writeMatrix(p.output, M, p.n, p.m);
    freeMatrix(M, p.n, p.m);
    return 0;
}
