#include <stdio.h>
#include <stdlib.h>

int sommaMatrix(int **m1, int **m2, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            m1[i][j] += m2[i][j];
        }
    }
    
    return m1[n][m];
}

int main(){
    int n, m = 4;
    
    //Alloco la matrice 1
    int **matrix1 = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        matrix1[i] = malloc(sizeof(int) * m);
    }
    
    //Alloco la matrice 2
    int **matrix2 = malloc(sizeof(int*) * n);
    for(int i = 0; i < n; i++){
        matrix2[i] = malloc(sizeof(int) * m);
    }
    
    //Riempio la matrice 1
    int val1 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix1[i][j] = val1 *= 2;
        }
    }
    
    //Riempio la matrice 2
    int val2 = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix2[i][j] = val2 *= 3;
        }
    }
    
    //Chiamo sommaMatrix()
    **matrix1 = sommaMatrix(matrix1, matrix2, n, m);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matrix1[i][j]);
        }
    }
    
    return 0;
}
