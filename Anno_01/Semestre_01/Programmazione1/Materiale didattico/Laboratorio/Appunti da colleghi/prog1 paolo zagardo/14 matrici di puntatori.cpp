#include <stdio.h>
#include <stdlib.h>

// Funzione per allocare una matrice NxM di puntatori a interi
int*** allocatePointerMatrix(int N, int M) {
    int ***matrix =(int***) malloc(N * sizeof(int**));
    for (int i = 0; i < N; i++) {
        matrix[i] =(int**) malloc(M * sizeof(int*));
        for (int j = 0; j < M; j++) {
            matrix[i][j] = (int*) malloc(sizeof(int));
        }
    }
    return matrix;
}

// Funzione per riempire la matrice con valori puntatori a interi
void fillPointerMatrix(int ***matrix, int N, int M) {
    int value = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            *(matrix[i][j]) = value++;
        }
    }
}

// Funzione per stampare la matrice di puntatori a interi
void printPointerMatrix(int ***matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", *(matrix[i][j]));
        }
        printf("\n");
    }
}

// Funzione per deallocare la matrice di puntatori a interi
void freePointerMatrix(int ***matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int N = 3, M = 4;
    int ***matrix = allocatePointerMatrix(N, M);
    fillPointerMatrix(matrix, N, M);
    printf("Matrice di puntatori a interi:\n");
    printPointerMatrix(matrix, N, M);
    freePointerMatrix(matrix, N, M);
    return 0;
}

