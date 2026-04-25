#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int k;
    char w;
    int N;
    int M;
} Params;

Params readInput(int argc, char* argv[]){
    Params p = {0, 0, 0, 0}; //Azzeriamo tutto

    if(argc != 5){
        fprintf(stderr, "[ERR]: Il numero di parametri deve essere pari a 4.\n");
        exit(-1);
    }

    char **end = malloc(sizeof(char*));
    *end = NULL;
    p.k = (int) strtol(argv[1], end, 0);

    if(**end){ //se ci sono caratteri dopo il numero → [ERROR] \\!!! explain
        fprintf(stderr, "[ERROR]: Il primo parametro deve essere un intero.\n");
        exit(-1);
    }

    if(p.k < 10 || p.k > 15){
        fprintf(stderr, "[ERR]: Il valore di k deve appartenere all'intervallo [10, 15].\n");
        exit(-1);
    }
    
    if(strlen(argv[2]) != 1){
        fprintf(stderr, "[ERROR]: Il secondo parametro deve essere un carattere.\n");
        exit(-1);
    }


    p.w = argv[2][0];
    if(p.w < 'a' || p.w > 'z'){
        fprintf(stderr, "[ERR]: Il valore di w deve appartenere all'intervallo [a, z].\n");
        exit(-1);
    }

    p.N = (int) strtol(argv[3], end, 0);
    if(**end){ //se ci sono caratteri dopo il numero → [ERROR]
        fprintf(stderr, "[ERROR]: il terzo parametro deve essere un intero.\n");
        exit(-1);
    }

    if(p.N  < 4 || p.N > 8){
        fprintf(stderr, "[ERR]: Il valore di N deve appartenere all'intervallo [4, 8].\n");
        exit(-1);
    }

    p.M = (int) strtol(argv[4], end, 0);
    if(**end){
            fprintf(stderr, "[ERROR]: il quarto parametro deve essere un intero.\n");
            exit(-1);
    }

    if(p.M < 4|| p.M > 8){
        fprintf(stderr, "[ERR]: Il valore di M deve appartenere all'intervallo [4, 8].\n");
        exit(-1);
    }

    return p;
}

char*** allocateS(int N, int M, int k){
    char*** S = malloc(sizeof(char**) * N);
    if(S == NULL){
        fprintf(stderr, "[ERR]: Processo di allocazione matrice fallito.\n");
        exit(-1);
    }

    for(int i = 0; i < N; i++){
        S[i] = malloc(sizeof(char*) * M);

        if (S[i] == NULL) {
            fprintf(stderr, "[ERR]: Allocazione livello 2 fallita.\n");
            exit(-1);
        }

        for(int j = 0; j < M; j++){
            S[i][j] = malloc(sizeof(char) * k);

            if (S[i][j] == NULL) {
            fprintf(stderr, "[ERR]: Allocazione livello 3 fallita.\n");
            exit(-1);
        }
        }
    }

    return S;
}

char* genString(int k){
    int lenght = k;
    char* c = malloc(sizeof(char) * (lenght + 1));
    if(c == NULL){
        fprintf(stderr, "[ERR]: Allocazione stringa pseudo-casuale fallita.\n");
        return NULL;
    }
    for(int i = 0; i < lenght; i++){
        char randomChar = rand()%('z' - 'a' + 1) + 'a';
        c[i] = randomChar;
    }
    c[lenght] = '\0';

    return c;
}

void fillS(char*** S, int N, int M, int k){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            S[i][j] = genString(k);
        }
    }
}

void sortS(char*** S, int N, int M){
    for(int i = 0; i < M; i++){
        bool sentinella = 0;
        for(int pass = 0; pass < N-1; pass++){
            for(int j = 0; j < N - pass - 1; j++){
                if(strcmp(S[i][j], S[i+1][j]) > 0){
                    char* tmp = S[i][j];
                    S[i][j] = S[i+1][j];
                    S[i+1][j] = tmp;
                    sentinella = 1;
                }
            }
            if(sentinella == 0) break;
        }
    }
}

int conta(char *str, char w){
    int count = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == w) count++;
    }

    return count;
}

void printMax(char ***S, int N, int M, char w){
    int i_max = 0;
    int j_max = 0;
    int max = 0;

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int val = conta(S[i][j], w);
            if(val > max){
                max = val;
                i_max = i;
                j_max = j;
            }
        }
    }

    for(int z = 0; z < strlen(S[i_max][j_max]); z++){
        if(S[i_max][j_max][z] == w){
            S[i_max][j_max][z] = '*';
        }
    }
    printf("\nStringa con maggiori occorrenze: %s \n", S[i_max][j_max]);
    }

void printMatrix(char*** S, int N, int M){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("%s ", S[i][j]);
        }
        printf("\n");
    }
    printf("\n");   // riga dopo tutta la matrice
}

int main(int argc , char *argv[]){
    srand(time(0));

    Params p = readInput(argc, argv);
    char*** S = allocateS(p.N, p.M, p.k);
    fillS(S, p.N, p.M, p.k);
    sortS(S, p.N, p.M);
    printMatrix(S, p.N, p.M);
    printMax(S, p.N, p.M, p.w);
}

// cd "C:\Users\giuli\Desktop\Desktop\Universita\1Anno\PrimoSemestre\Programmazione1\Esame Dicembre\Svolgimento prove d'esame\ESEMPI PROVE D'ESAME\Prove rieseguite"
// gcc Prova1.c -o testprova1
// .\testprova1 10 x 5 4 