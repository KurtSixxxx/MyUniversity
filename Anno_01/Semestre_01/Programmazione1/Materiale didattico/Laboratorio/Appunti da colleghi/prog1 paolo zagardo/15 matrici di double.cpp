#include <stdio.h>
#include <stdlib.h>

// Funzione per generare un numero double casuale tra x e y
double genDouble(double x, double y) {
    return x + ((double)rand() / RAND_MAX) * (y - x);
}


// Funzione per allocare una matrice NxN di numeri double
double** allocateDoubleMatrix(int N) {
    double **matrix = (double**) malloc(N * sizeof(double*)); // Cast a (double**) per la corretta assegnazione
    for (int i = 0; i < N; i++) {
        matrix[i] = (double*) malloc(N * sizeof(double));
    }
    return matrix;
}


// Funzione per riempire la matrice con valori double casuali tra x e y
void fillDoubleMatrix(double **matrix, int N, double x, double y) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = genDouble(x, y);
        }
    }
}

// Funzione per stampare la matrice di double
void printDoubleMatrix(double **matrix, int N) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Funzione per deallocare la matrice di double
void freeDoubleMatrix(double **matrix, int N) {
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int N = 4;
    double x = 0.0, y = 10.0;
    double **matrix = allocateDoubleMatrix(N);
    fillDoubleMatrix(matrix, N, x, y);
    printf("Matrice di double:\n");
    printDoubleMatrix(matrix, N);
    freeDoubleMatrix(matrix, N);
    return 0;
}

