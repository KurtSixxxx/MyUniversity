#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funzione per allocare una matrice NxM di stringhe
char*** allocateStringMatrix(int N, int M) {
    char ***matrix =(char***) malloc(N * sizeof(char**));
    for (int i = 0; i < N; i++) {
        matrix[i] =(char**) malloc(M * sizeof(char*));
        for (int j = 0; j < M; j++) {
            matrix[i][j] =(char*) malloc(10 * sizeof(char)); // Allocazione per stringhe di max 10 caratteri
        }
    }
    return matrix;
}

// Funzione per riempire la matrice con stringhe fisse
void fillStringMatrix(char ***matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            sprintf(matrix[i][j], "S%d%d", i, j); // Riempie con stringhe del tipo "Sij"
        }
    }
}

// Funzione per stampare la matrice di stringhe
void printStringMatrix(char ***matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Funzione per deallocare la matrice di stringhe
void freeStringMatrix(char ***matrix, int N, int M) {
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
    char ***matrix = allocateStringMatrix(N, M);
    fillStringMatrix(matrix, N, M);
    printf("Matrice di stringhe:\n");
    printStringMatrix(matrix, N, M);
    freeStringMatrix(matrix, N, M);
    return 0;
}

