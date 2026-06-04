//Giulio Casella 1000061366

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *inputfile;
    char *outputfile;
    int n; // 5
    int m; // 7
} Params;

Params readInput(int argc, char *argv[]){
    Params p = {0, 0, 0, 0};

    if(argc != 5){
        fprintf(stderr, "Il numero di parametri non è corretto.\n");
        exit(-1);
    }

    char *ptrStr1 = strstr(argv[1], ".txt");
    if(ptrStr1 == NULL){
        fprintf(stderr, "Il file in input deve essere di tipo .txt\n");
        exit(-1);
    }

    p.inputfile = argv[1];

    char *ptrStr2 = strstr(argv[2], ".txt");
    if(ptrStr2 == NULL){
        fprintf(stderr, "Il file in input deve essere di tipo .txt\n");
        exit(-1);
    }

    p.outputfile = argv[2];

    char **end = malloc(sizeof(char*));
    *end = NULL;
    p.n = (int) strtol(argv[3], end, 0);

    if(**end){
        fprintf(stderr, "Il parametro inserito non è un intero positivo.\n");
        exit(-1);
    }

    if(p.n < 0){
        fprintf(stderr, "Il parametro inserito non è un intero positivo.\n");
        exit(-1);
    }

    p.m = (int) strtol(argv[4], end, 0);

    if(**end){
        fprintf(stderr, "Il parametro inserito non è un intero positivo.\n");
        exit(-1);
    }

    if(p.m < 0){
        fprintf(stderr, "Il parametro inserito non è un intero positivo.\n");
        exit(-1);
    }

    return p;
}  

double*** allocMatrix(Params *p){
    
    double ***matrix = malloc(sizeof(double**) * p->n);
    if(matrix == NULL){
        fprintf(stderr, "[ERR]: Errore nel processo di allocazione matrice (1lv).\n");
        return NULL;
    }

    for(int i = 0; i < p->n; i++){
        matrix[i] = malloc(sizeof(double*) * p->m);
        if(matrix[i] == NULL){
            fprintf(stderr, "[ERR]: Errore nel processo di allocazione matrice (2lv).\n");
            return NULL;
        }

        for(int j = 0; j < p->m; j++){
            matrix[i][j] = malloc(sizeof(double));
            if(matrix[i][j] == NULL){
            fprintf(stderr, "[ERR]: Errore nel processo di allocazione matrice (3lv).\n");
            return NULL;
            }
        }
    }

    return matrix;
}

// Legge una matrice di double fa file
// Memorizza la matrice in memoria
// Stampa la matrice su output
// Resistituisce la matrice

double*** readMatrix(Params *p){
    double ***M = allocMatrix(p);
    if(M == NULL){
        fprintf(stderr, "[ERR]: La funzione di allocazione ha avuto errore.\n");
        return NULL;
    }

    FILE *fp = fopen(p->inputfile, "r");
    if(fp == NULL){
        fprintf(stderr, "[ERR]: errore nel processo di apertura del file.\n");
        return NULL;
    }
    
    for(int i = 0; i < p->n; i++){
        for(int j = 0; j < p->m; j++){
            if(fscanf(fp, "%lf", M[i][j]) != 1){
                fprintf(stderr, "Errore di lettura file.\n");
                return NULL;
            }
        }
    }

    printf("Matrice letta:\n");
    for(int i = 0; i < p->n; i++){
        for(int j = 0; j < p->m; j++){
            printf("%.2lf ", *M[i][j]);
            }
            printf("\n");
        }

    fclose(fp);

    return M;
}

void printMatrix(double ***M, Params *p){
    for(int i = 0; i < p->n; i++){
        for(int j = 0; j < p->m; j++){
            printf("%.2lf ", *M[i][j]);
            }
            printf("\n");
        }
}

double*** transposeMatrix(double*** M, Params *p){
    // ATTENZIONE: la trasposta ha dimensioni m x n, NON n x m
    int newN = p->m; 
    int newM = p->n;

    Params q = { NULL, NULL, newN, newM };
    double ***A = allocMatrix(&q);   // matrice m x n

    for(int i = 0; i < p->n; i++){
        for(int j = 0; j < p->m; j++){
            *A[j][i] = *M[i][j];   // <-- CORRETTISSIMO: invertire gli indici
        }
    }

    return A;
}


int main(int argc, char *argv[]){
    Params p = readInput(argc, argv);
    double ***matrix = allocMatrix(&p);
    matrix = readMatrix(&p);
    printf("\n");  
    printf("\nMatrice trasposta:\n");
    double ***A = transposeMatrix(matrix, &p);

}

// cd "C:\Users\giuli\Desktop\Desktop\Universita\1Anno\PrimoSemestre\Programmazione1\Esame Dicembre\Svolgimento prove d'esame\29gennaio"
// gcc 29gennaio.c minput.txt minoutput.txt 5 7
// .\29gennaio minput.txt minoutput.txt 5 7
