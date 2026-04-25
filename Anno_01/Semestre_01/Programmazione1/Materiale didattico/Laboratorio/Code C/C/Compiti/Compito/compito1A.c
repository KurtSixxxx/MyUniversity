#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Funzione per generare numeri casuali
unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;  // Restituisce il numero casuale generato
}

// Struttura per memorizzare i dati di input
struct data {
    int k;  // lunghezza delle stringhe
    char w; // carattere da generare
    int N;  // numero di righe
    int M;  // numero di colonne
};

// Funzione per leggere e validare gli input
struct data readInput(int argc, char *argv[]) {
    if (argc != 5) {  // Controlla se ci sono 4 parametri
        fprintf(stderr, "Numero di parametri errato\n");
        exit(-1);
    }

    struct data d = {0, 0, 0, 0};  // Inizializzazione della struttura

    // Controllo per il primo parametro (k)
    d.k = atoi(argv[1]);
    if (d.k < 10 || d.k > 15) {
        fprintf(stderr, "Il parametro k deve essere compreso tra 10 e 15.\n");
        exit(-1);
    }

    // Controllo per il secondo parametro (w)
    if (strlen(argv[2]) != 1) {
        fprintf(stderr, "w deve essere un singolo carattere.\n");
        exit(-1);
    }
    d.w = argv[2][0];
    if (d.w < 'a' || d.w > 'z') {
        fprintf(stderr, "w deve essere un carattere compreso tra 'a' e 'z'.\n");
        exit(-1);
    }

    // Controllo per il terzo parametro (N)
    d.N = atoi(argv[3]);
    if (d.N < 4 || d.N > 8) {
        fprintf(stderr, "Il parametro N deve essere compreso tra 4 e 8.\n");
        exit(-1);
    }

    // Controllo per il quarto parametro (M)
    d.M = atoi(argv[4]);
    if (d.M < 4 || d.M > 8) {
        fprintf(stderr, "Il parametro M deve essere compreso tra 4 e 8.\n");
        exit(-1);
    }

    return d;  // Restituisce la struttura con i dati letti
}

// Funzione per allocare dinamicamente una matrice di stringhe
char*** allocateS(int N, int M, int k) {
    char*** S = (char***)calloc(N, sizeof(char**));  // Allocazione memoria per le righe
    for (int i = 0; i < N; i++) {
        S[i] = (char**)calloc(M, sizeof(char*));  // Allocazione memoria per le colonne
        for (int j = 0; j < M; j++) {
            S[i][j] = (char*)calloc(k + 1, sizeof(char));  // Allocazione memoria per ogni stringa (k + 1 per il terminatore '\0')
        }
    }
    return S;
}

// Funzione per generare una stringa di lunghezza k con caratteri tra 'min' e 'max'
char* genString(int k, char min, char max) {
    char* S = calloc(k + 1, sizeof(char));  // Allocazione memoria per la stringa
    for (int i = 0; i < k; i++) {
    S[i] = (get_random() % (max - min + 1)) + min; 
    }
    S[k] = '\0';  // Aggiunge il terminatore di stringa, ma viene già incluso in calloc, quindi l'assegnazione S[k] = '\0'; non è necessaria
    return S;
}

// Funzione per riempire la matrice di stringhe con valori casuali
void fillS(char*** S, int N, int M, int k) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            S[i][j] = genString(k, 'a', 'z');  // Riempie la cella con una stringa casuale
        }
    }
}

// Funzione per ordinare la matrice di stringhe in ordine lessicografico
void sortS(char*** S, int N, int M) {
    for (int j = 0; j < M; j++) {
        for (int pass = 0; pass < N - 1; pass++) {
            for (int i = 0; i < N - pass - 1; i++) {
                if (strcmp(S[i][j], S[i + 1][j]) > 0) {  // Confronta le stringhe
                    // Scambia le stringhe
                    char* temp = S[i][j];
                    S[i][j] = S[i + 1][j];
                    S[i + 1][j] = temp;
                }
            }
        }
    }
}

// Funzione per stampare la matrice di stringhe
void printMatrix(char*** S, int N, int M) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%s ", S[i][j]);  // Stampa ogni stringa
        }
        printf("\n");  // A capo dopo ogni riga
    }
}

int countOccurrencesInString(char* str, char target) {
    int count = 0;
    while (*str) {
        if (*str == target) count++;
        str++;
    }
    return count;
}

void replaceCharInString(char* str, char target, char replacement) {
    while (*str) {
        if (*str == target) {
            *str = replacement;
        }
        str++;
    }
}

void findAndReplaceMax(char*** S, int N, int M, char target, char replacement) {
    char* maxString = NULL;
    int maxCount = 0;

    // Trova la stringa con il massimo numero di occorrenze di 'target'
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int count = countOccurrencesInString(S[i][j], target);
            if (count > maxCount) {
                maxCount = count;
                maxString = S[i][j];
            }
        }
    }

    // Sostituisci i caratteri nella stringa con più occorrenze
    if (maxString != NULL) {
        replaceCharInString(maxString, target, replacement);
    }
}

void printMax(char*** S, int N, int M, char target) {
    char* maxString = NULL;
    int maxCount = 0;
    int maxRow = -1, maxCol = -1;

    // Trova la stringa con il massimo numero di occorrenze di 'target'
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int count = countOccurrencesInString(S[i][j], target);
            if (count > maxCount) {
                maxCount = count;
                maxString = S[i][j];
                maxRow = i;
                maxCol = j;
            }
        }
    }

    // Stampa la stringa e gli indici
    if (maxString != NULL) {
        printf("Stringa con il maggior numero di occorrenze di '%c': %s (Riga: %d, Colonna: %d)\n", target, maxString, maxRow, maxCol);
    } else {
        printf("Nessuna stringa trovata.\n");
    }
}


int main(int argc, char *argv[]) {
    // Legge i dati di input
    struct data d = readInput(argc, argv);

    // Alloca memoria per la matrice di stringhe
    char*** S = allocateS(d.N, d.M, d.k);

    // Riempie la matrice con stringhe casuali
    fillS(S, d.N, d.M, d.k);

    // Stampa la matrice originale
    printf("Matrice originale:\n");
    printMatrix(S, d.N, d.M);

    // Trova e sostituisce nella stringa con il maggior numero di occorrenze di 'w'
    findAndReplaceMax(S, d.N, d.M, d.w, '*');

    // Stampa la matrice modificata
    printf("\nMatrice modificata:\n");
    printMatrix(S, d.N, d.M);

    // Libera la memoria allocata (aggiungi una funzione di deallocazione)
    return 0;  // Fine del programma
}