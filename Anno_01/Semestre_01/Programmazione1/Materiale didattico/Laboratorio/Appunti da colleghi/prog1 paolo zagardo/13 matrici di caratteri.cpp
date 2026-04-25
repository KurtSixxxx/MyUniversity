#include <stdio.h>
#include <stdlib.h>

// Funzione per allocare una matrice NxM di caratteri
char** allocateCharMatrix(int N, int M) {
    char **matrix = (char**) malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        matrix[i] = (char*) malloc(M * sizeof(char)); // Casting di malloc a char*
    }
    return matrix;
}




// Funzione per riempire la matrice con caratteri incrementali
void fillCharMatrix(char **matrix, int N, int M) {
    char value = 'A';
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = value++;
            if (value > 'Z') value = 'A';
        }
    }
}

// Funzione per stampare la matrice di caratteri
// Funzione per stampare la matrice di caratteri
void printCharMatrix(char **matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c ", matrix[i][j]); // Utilizza %c per stampare il singolo carattere
        }
        printf("\n");
    }
}


// Funzione per deallocare la matrice di caratteri
void freeCharMatrix(char **matrix, int N) {
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int N = 5, M = 6;
    char **matrix = allocateCharMatrix(N, M);
    fillCharMatrix(matrix, N, M);
    printf("Matrice di caratteri:\n");
    printCharMatrix(matrix, N, M);
    freeCharMatrix(matrix, N);
    return 0;
}

