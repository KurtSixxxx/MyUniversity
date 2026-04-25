#include <stdio.h>
#include <stdlib.h>

// Funzione per allocare una matrice tridimensionale NxMxP di interi
int*** allocate3DMatrix(int N, int M, int P) {
    int ***matrix =(int***) malloc(N * sizeof(int**));
    for (int i = 0; i < N; i++) {
        matrix[i] =(int**) malloc(M * sizeof(int*));
        for (int j = 0; j < M; j++) {
            matrix[i][j] =(int*) malloc(P * sizeof(int));
        }
    }
    return matrix;
}

// Funzione per riempire la matrice tridimensionale con valori incrementali
void fill3DMatrix(int ***matrix, int N, int M, int P) {
    int value = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < P; k++) {
                matrix[i][j][k] = value++;
            }
        }
    }
}

// Funzione per stampare la matrice tridimensionale
void print3DMatrix(int ***matrix, int N, int M, int P) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < P; k++) {
                printf("%d ", matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Funzione per deallocare la matrice tridimensionale
void free3DMatrix(int ***matrix, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int N = 2, M = 3, P = 4;
    int ***matrix = allocate3DMatrix(N, M, P);
    fill3DMatrix(matrix, N, M, P);
    printf("Matrice tridimensionale:\n");
    print3DMatrix(matrix, N, M, P);
    free3DMatrix(matrix, N, M);
    return 0;
}

