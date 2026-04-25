/*Implementare una matrice in C implica l'uso di puntatori e l'allocazione dinamica della memoria. Di seguito viene presentato un esempio completo che copre 
i vari punti richiesti, come l'allocazione dinamica di una matrice di stringhe, il riempimento con stringhe casuali, l'ordinamento, la stampa e la gestione 
di una matrice di numeri double con calcolo di minimi e massimi.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funzione per generare un numero casuale
int get_random() {
    return rand();
}

// Funzione per generare un numero double casuale tra x e y
double genDouble(double x, double y) {
    return x + (rand() / (double) RAND_MAX) * (y - x);
}

// Funzione per allocare una matrice di stringhe NxM
char*** allocateS(int N, int M) {
    char ***S =(char***) calloc(N, sizeof(char**));
    for (int i = 0; i < N; i++) {
        S[i] =(char**) calloc(M, sizeof(char*));
    }
    return S;
}

// Funzione per generare una stringa casuale di lunghezza len con caratteri tra min e max
char* genString(int len, char min, char max) {
    char *s =(char*) calloc(len + 1, sizeof(char)); // +1 per il terminatore nullo
    for (int i = 0; i < len; i++) {
        s[i] = get_random() % (max - min + 1) + min;
    }
    s[len] = '\0'; // Terminatore nullo
    return s;
}

// Funzione per riempire la matrice S con stringhe casuali
void fillS(char ***S, int N, int M, int k) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            S[i][j] = genString(k, 'a', 'z');
        }
    }
}

// Funzione per ordinare ogni colonna della matrice S in modo crescente
void sortS(char ***S, int N, int M) {
    for (int j = 0; j < M; j++) { // Scorro le colonne
        for (int pass = 0; pass < N - 1; pass++) {
            for (int i = 0; i < N - 1 - pass; i++) {
                if (strcmp(S[i][j], S[i + 1][j]) > 0) {
                    char *tmp = S[i][j];
                    S[i][j] = S[i + 1][j];
                    S[i + 1][j] = tmp;
                }
            }
        }
    }
}

// Funzione per stampare la matrice S
void printMatrix(char ***S, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%s ", S[i][j]);
        }
        printf("\n");
    }
}

// Funzione per allocare una matrice NxN di numeri double
double ** genMatrix(int N, double x, double y) {
    double **A =(double**) calloc(N, sizeof(double*));
    for (int i = 0; i < N; i++) {
        A[i] =(double*) calloc(N, sizeof(double));
        for (int j = 0; j < N; j++) {
            A[i][j] =(double) genDouble(x, y);
        }
    }
    return A;
}

// Funzione per calcolare mind, maxd e contare gli elementi in [mind, maxd]
int computeMinMax(double **A, int N, double *mind, double *maxd) {
    *mind = A[0][0];
    *maxd = A[0][N-1];
    for (int i = 0; i < N; i++) {
        if (A[i][i] < *mind)
            *mind = A[i][i];
        if (A[i][N-1-i] > *maxd)
            *maxd = A[i][N-1-i];
    }
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (A[i][j] >= *mind && A[i][j] <= *maxd) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Esempio di utilizzo delle funzioni sopra definite
    
    int N = 5, M = 4, k = 10; // Dimensioni della matrice di stringhe
    char ***S = allocateS(N, M);
    fillS(S, N, M, k);
    printf("Matrice di stringhe generata:\n");
    printMatrix(S, N, M);
    sortS(S, N, M);
    printf("\nMatrice di stringhe ordinata:\n");
    printMatrix(S, N, M);

    double x = 0.0, y = 10.0;
    double **A = genMatrix(N, x, y);
    printf("\nMatrice di numeri double generata:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f ", A[i][j]);
        }
        printf("\n");
    }

    double mind, maxd;
    int count = computeMinMax(A, N, &mind, &maxd);
    printf("\nMinimo della diagonale principale: %.2f\n", mind);
    printf("Massimo della diagonale secondaria: %.2f\n", maxd);
    printf("Numero di elementi in [%.2f, %.2f]: %d\n", mind, maxd, count);

    // Deallocazione della memoria
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            free(S[i][j]);
        }
        free(S[i]);
    }
    free(S);

    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);

    return 0;
}
/*Generazione di numeri casuali: get_random e genDouble sono utilizzati per generare numeri interi e double casuali rispettivamente.
Allocazione della matrice di stringhe: allocateS alloca una matrice NxM di puntatori a stringhe (char*).
Generazione di stringhe casuali: genString genera una stringa di lunghezza len con caratteri tra min e max.
Riempimento della matrice di stringhe: fillS riempie la matrice S con stringhe casuali di lunghezza k.
Ordinamento delle colonne della matrice di stringhe: sortS ordina ogni colonna della matrice in modo lessicografico.
Stampa della matrice di stringhe: printMatrix stampa la matrice di stringhe.
Allocazione della matrice di numeri double: genMatrix alloca una matrice NxN di numeri double e la riempie con valori casuali tra x e y.
Calcolo di minimi, massimi e conteggio: computeMinMax calcola il minimo della diagonale principale (mind), il massimo della diagonale secondaria (maxd), 
e conta quanti elementi della matrice sono compresi tra mind e maxd.
Deallocazione della memoria: Il codice nel main dealloca la memoria per le matrici di stringhe e double.*/
