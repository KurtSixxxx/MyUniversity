#include <stdio.h>
#include <stdlib.h>

int main() {
    int righe, colonne;

    // 1. Richiedi l'input dell'utente per righe e colonne
    printf("Inserisci il numero di righe: ");
    scanf("%d", &righe);
    printf("Inserisci il numero di colonne: ");
    scanf("%d", &colonne);

    // 2. Alloca memoria per le righe della matrice
    int **matrice = (int **)malloc(righe * sizeof(int *));
    if (matrice == NULL) {
        printf("Errore nell'allocazione della memoria per le righe.\n");
        return 1;
    }

    // 3. Alloca memoria per le colonne di ogni riga
    for (int i = 0; i < righe; i++) {
        matrice[i] = (int *)malloc(colonne * sizeof(int));
        if (matrice[i] == NULL) {
            printf("Errore nell'allocazione della memoria per la riga %d.\n", i);
            // Libera la memoria già allocata
            for (int j = 0; j < i; j++) {
                free(matrice[j]);
            }
            free(matrice);
            return 1;
        }
    }

    // 4. Inserisci i valori nella matrice
    printf("Inserisci i valori per la matrice:\n");
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("Inserisci il valore per matrice[%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }

    // 5. Stampa la matrice
    printf("Matrice inserita:\n");
    for (int i = 0; i < righe; i++) {
        for (int j = 0; j < colonne; j++) {
            printf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    // 6. Libera la memoria allocata
    for (int i = 0; i < righe; i++) {
        free(matrice[i]); // Libera la memoria per le colonne
    }
    free(matrice); // Libera la memoria per le righe

    return 0;
}