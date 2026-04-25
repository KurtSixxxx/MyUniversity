#include <stdio.h>
#include <string.h>

void sortMatrixFile(char *filename) {
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
    }
/*The first call to strtok(line, ",") returns a pointer to the first token, say "1".
The next call to strtok(NULL, ",") continues tokenizing from where it left off, which 
is after the first token. It returns a pointer to the next token, say "2".
The next call to strtok(NULL, ",") continues tokenizing from where it left off, which is after the second token. 
It returns a pointer to the next token, say "3".*/
    // Ordina la matrice
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            for (int k = j + 1; k< cols; k++) {
                if (strcmp(matrix[i][j], matrix[i][k]) > 0) {
                    char temp[100];
                    strcpy(temp, matrix[i][j]);
                    strcpy(matrix[i][j], matrix[i][k]);
                    strcpy(matrix[i][k], temp);
                }
            }
        }
    }

    // Stampa la matrice ordinata
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
    sortMatrixFile(filename);
    return 0;
}
