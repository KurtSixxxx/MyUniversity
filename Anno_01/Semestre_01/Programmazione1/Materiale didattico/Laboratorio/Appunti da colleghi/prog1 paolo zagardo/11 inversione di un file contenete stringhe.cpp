#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void strrev(char *str) {
    int length = strlen(str);//calcola la lunghezza
    int start = 0;//serve per fare la conversione della stringa dall'inizio
    int end = length - 1;
    char temp;

    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

void reverseMatrixFile(char *filename) {
    FILE *fp = fopen(filename, "r");
    char line[1024];
    char **matrix;
    int rows = 0;
    int cols = 0;

    // Leggi il file e crea la matrice
    while (fgets(line, 1024, fp)) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            matrix[rows][col] = token;
            token = strtok(NULL, ",");
            col++;
        }
        rows++;
        cols = col; // update cols here
    }

    // Inverte le stringhe nella matrice
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            strrev(matrix[i][j]);
        }
    }

    // Stampa la matrice con stringhe invertite
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s,", matrix[i][j]);
        }
        printf("\n");
    }

    fclose(fp);
}

int main() {
    char filename[] = "matrix.txt";
    reverseMatrixFile(filename);
    return 0;
}
