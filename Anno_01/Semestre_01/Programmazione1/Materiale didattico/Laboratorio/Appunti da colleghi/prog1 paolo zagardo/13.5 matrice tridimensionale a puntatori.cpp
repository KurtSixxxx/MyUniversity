#include <stdio.h>
#include <stdlib.h>

// Funzione per allocare una matrice tridimensionale NxMxP di puntatori a interi
int**** allocate3DPointerMatrix(int N, int M, int P) {
    int ****matrix =(int****) malloc(N * sizeof(int***));
    for (int i = 0; i < N; i++) {
        matrix[i] =(int***) malloc(M * sizeof(int**));
        for (int j = 0; j < M; j++) {
            matrix[i][j] =(int**) malloc(P * sizeof(int*));
            for (int k = 0; k < P; k++) {
                matrix[i][j][k] =(int*) malloc(sizeof(int));
            }
        }
    }
    return matrix;
}

// Funzione per riempire la matrice tridimensionale di puntatori a interi con valori incrementali
void fill3DPointerMatrix(int ****matrix, int N, int M, int P) {
    int value = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < P; k++) {
                *matrix[i][j][k] = value++;
            }
        }
    }
}

// Funzione per stampare la matrice tridimensionale di puntatori a interi
void print3DPointerMatrix(int ****matrix, int N, int M, int P) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < P; k++) {
                printf("%d ", *matrix[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

// Funzione per deallocare la matrice tridimensionale di puntatori a interi
void free3DPointerMatrix(int ****matrix, int N, int M, int P) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int k = 0; k < P; k++) {
                free(matrix[i][j][k]);
            }
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    int N = 2, M = 3, P = 4;
    int ****matrix = allocate3DPointerMatrix(N, M, P);
    fill3DPointerMatrix(matrix, N, M, P);
    printf("Matrice tridimensionale di puntatori a interi:\n");
    print3DPointerMatrix(matrix, N, M, P);
    free3DPointerMatrix(matrix, N, M, P);
    return 0;
}

