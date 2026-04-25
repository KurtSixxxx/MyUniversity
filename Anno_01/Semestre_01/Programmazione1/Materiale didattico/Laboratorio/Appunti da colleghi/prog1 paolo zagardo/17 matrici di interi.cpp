#include <stdio.h>
#include <stdlib.h>

// Funzione per allocare una matrice NxM di interi
// Funzione per allocare una matrice NxM di interi
int** allocateIntMatrix(int N, int M) {
    int **matrix = (int**) malloc(N * sizeof(int*)); // Correzione: dichiarare matrix come puntatore a puntatore a interi (int**)
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*) malloc(M * sizeof(int)); // Correzione: cast a (int*) per la corretta assegnazione di matrix[i]
    }
    return matrix;
}


// Funzione per riempire la matrice con valori interi incrementali
void fillIntMatrix(int **matrix, int N, int M) {
    int value = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = value++;
        }
    }
}

// Funzione per stampare la matrice di interi
void printIntMatrix(int **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Funzione per deallocare la matrice di interi
void freeIntMatrix(int **matrix, int N) {
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int N = 3, M = 4;
    int **matrix = allocateIntMatrix(N, M);
    fillIntMatrix(matrix, N, M);
    printf("Matrice di interi:\n");
    printIntMatrix(matrix, N, M);
    freeIntMatrix(matrix, N);
    return 0;
}

