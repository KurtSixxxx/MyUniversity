#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

/*Prendere in input da tastiera:
    intero k in [10,15]
    carattere w in ['a' - 'z']
    intero N in [4,8]
    intero M in [4,8]
Se gli argomenti non corrispondono ai requisiti -> fprintf e [ERROR]e -1
*/

typedef struct{
    int k;
    char w;
    int N;
    int M;
} Params;

Params readInput(int argc, char *argv[]){
    Params p = {0, 0, 0, 0}; //Imposto tutti i campi a 0

    if(argc != 5){ //Se gli argomenti non sono quattro + nome programma...
        fprintf(stderr, "[ERROR]: Il numero di parametri deve essere pari a 4.\n");
        exit(-1);
    }

    //Questo serve per usare strtol
    //strtol è una funzione che converte una stringa in un numero intero.
    char **end = malloc(sizeof(char*)); //serve per sapere dove finisce il numero
    *end = NULL;
    p.k = (int) strtol(argv[1], end, 0); //0 è la base di conversione, e 0 prende la base in automatico

    if(**end){ //se ci sono caratteri dopo il numero → [ERROR]e
        fprintf(stderr, "[ERROR]: Il primo parametro deve essere un intero.\n");
        exit(-1);
    }

    if(p.k < 10 || p.k > 15){
        fprintf(stderr, "[ERROR]: Il valore deve essere compreso tra 10 e 15.\n");
        exit(-1);
    }

    if(strlen(argv[2]) != 1){
        fprintf(stderr, "[ERROR]: Il secondo parametro deve essere un carattere.\n");
        exit(-1);
    }

    p.w = argv[2][0];
    if(p.w < 'a' | | p.w > 'z'){
        fprintf(stderr, "[ERROR]: Il secondo parametro deve essere nel range [a-z].\n");
        exit(-1);
    }

    p.N = (int) strtol(argv[3], end, 0);
    if(**end){ //se ci sono caratteri dopo il numero → [ERROR]e
        fprintf(stderr, "[ERROR]: il terzo parametro deve essere un intero.\n");
        exit(-1);
    }

    if(p.N < 4 || p.N > 8){
        fprintf(stderr, "[ERROR]: Il terzo parametro deve essere nel range [4,8].\n");
        exit(-1);
    }

    p.M = (int) strtol(argv[4], end, 0);
    if(**end){ //se ci sono caratteri dopo il numero → [ERROR]
        fprintf(stderr, "[ERROR]: il quarto parametro deve essere un intero.\n");
        exit(-1);
    }

    if(p.M < 4 || p.M > 8){
        fprintf(stderr, "[ERROR]: Il quarto parametro deve essere nel range [4,8].\n");
        exit(-1);
    }

    return p;
}

char*** allocateS(int N, int M){
    char*** S = malloc(sizeof(char**) * N);

    if(S == NULL){
        fprintf(stderr, "[ERROR]: Allocazione fallita.\n");
        exit(-1);
    }

    for(int i = 0; i < N; i++){
        S[i] = malloc(sizeof(char*) * M);
    }

    return S;
}

char* genString(int k){
    int lenght = k;

    char *string = (char*)malloc(sizeof(char) * (lenght + 1));
    if(string == NULL){
        fprintf(stderr, "[ERROR]: Allocazione fallita.\n");
        return NULL;
    }

    for(int i = 0; i < lenght; i++){
    char randomChar = rand()%('z' - 'a' + 1) + 'a';
        string[i] = randomChar;
    }
    string[lenght] = '\0';
    
    return string;
}

void fillS(char ***S, int N, int M, int k){
    if(S == NULL){
        fprintf(stderr, "[ERROR]: Matrice non esistente.\n");
        return;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            S[i][j] = genString(k);
        }
    }
}

void sortS(char ***S ,int N, int M){
    for(int j = 0; j < M; j++){//Blocco le colonne
        for(int pass = 0; pass < N-1; pass++){ //Passate
            bool sentinella = 0;
            for(int i = 0; i < N-1-pass; i++){
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

void printMatrix(char*** S, int N, int M){
    printf("\n");   // riga di separazione

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            printf("[%s] ", S[i][j]);
        }
        printf("\n");  // fine riga
    }

    printf("\n");   // riga dopo tutta la matrice
}

int conta(char *s){
    //accedo alla stringa contenuta nella casella
    //se nella stringa c'è w lo aggiugno al count
    //ritorno il conteggio di w presenti

    int cont = 0;
    for(int i = 0; i < strlen(s); i++){
        if(s[i] == 'w') cont++;
    }

    return cont;
}

void printMax(char*** S, int N, int M){
    //Inizializziamo indici massimi e massimo, tutti a 0
    int i_max = 0;
    int j_max = 0;
    int max = 0;

    //Iteriamo sulla matrice e teniamo conto del confronto con max e counter
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            int counter = conta(S[i][j]);
            if(counter > max){
            max = counter;
            i_max = i;
            j_max = j;
            }
        }
    }

    printf("\nStringa con %d occorrenze di 'w' trovata agli indici S[%d][%d]", max, i_max, j_max);
    printf("\n");

    //Qui accediamo al carattere della stringa con maggior numero di occorrenze, e se il carattere è uguale a w lo sostituiamo con *
    for(int i = 0; i < strlen(S[i_max][j_max]); i++){
        char w = S[i_max][j_max][i];
        if(w == 'w'){
           S[i_max][j_max][i] = '*';
        }
    }
    printf("Stringa con maggior numero di occorrenze di 'w': %s", S[i_max][j_max]);  
}

int main(int argc, char *argv[]){
    Params p = readInput(argc, argv);
    char ***S = allocateS(p.N, p.M);
    fillS(S, p.N, p.M, p.k);
    sortS(S, p.N, p.M);
    printMatrix(S, p.N, p.M);
    printMax(S, p.N, p.M);
}