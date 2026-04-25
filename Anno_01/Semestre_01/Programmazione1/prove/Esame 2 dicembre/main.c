//Giulio Filippo Casella, Matricola 100061366

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char filename[256];
    int N;
    int M;
} Params;

Params readInput(int argc, char *argv[]){
    if(argc != 4){
        fprintf(stderr, "[ERROR]: il numero di parametri deve essere pari a 3.\n"); //3 ovviamente ad esclusione del nome dell'eseguibile
        exit(-1);
    }

    Params p;

    strcpy(p.filename, argv[1]);

    char **end = malloc(sizeof(char*));
    *end = NULL;    
    p.N = (int)strtol(argv[2], end, 0); //uso strtol (con casting ad int) per vedere dove end trova caratteri. Se li trova il carattere non è accettato. Come base numerica uso 0 (automatica)
    p.M = (int)strtol(argv[3], end, 0);

    if(**end){
        fprintf(stderr, "[ERROR]: Il parametro deve essere un intero.\n");
        exit(-1);
    }

    if(p.N < 5 || p.N > 10){
        fprintf(stderr, "[ERROR]: N deve avere valori compresi nell'intervallo [5,10]\n");
        exit(-1);
    }

    if(p.M < 5 || p.M > 10){
        fprintf(stderr, "[ERROR]: M deve avere valore compreso nell'intervallo [5,10]\n");
        exit(-1);
    }

    return p; //ritorno la struct che contiene tutti i parametri
}

double*** allocateMatrix(Params *p){
    double ***matrix = malloc(sizeof(double**) * p->N);
    if(matrix == NULL){
        fprintf(stderr, "[ERROR]: Errore nel processo di allocazione matrice. (lv1) \n");
        return NULL;
    }

    for(int i = 0; i < p->N; i++){
        matrix[i] = malloc(sizeof(double*) * p->M);
        if(matrix[i] == NULL){
        fprintf(stderr, "[ERROR]: Errore nel processo di allocazione matrice. (lv2)\n");
        return NULL;
        }
    }

    for(int i = 0; i < p->N; i++){
        for(int j = 0; j < p->M; j++){
            matrix[i][j] = malloc(sizeof(double));
            if(matrix[i][j] == NULL){
                fprintf(stderr, "[ERROR]: Errore nel processo di allocazione matrice. (lv3)\n");
                return NULL;
                }
            }
        }

    return matrix;
}

void fillMatrix(double ***M, Params p){
    FILE *fp = fopen(p.filename, "r"); //apriamo in modalità lettura
    if(fp == NULL){
        fprintf(stderr, "[ERROR]: Errore nel processo di apertura del file.\n");
        exit(-1);
    }

    for(int i = 0; i < p.N; i++){
        for(int j = 0; j < p.M; j++){
            fscanf(fp, "%lf", M[i][j]); //preleviamo ogni double della matrice
        }
    }

    fclose(fp);
}

void printMatrix(double ***M, Params p){
    for(int i = 0; i < p.N; i++){
        for(int j = 0; j < p.M; j++){
            printf("%f ", *M[i][j]);
        }
        printf("\n");
    }
}

void normalize(double ***M1, double ***M2, Params p){
    double columnsMax[p.M]; //in questo array inserisco tutti i massimi che trovo per ogni colonna. E per normalizzare dividiamo per il numero di elementi

    for(int j = 0; j < p.M; j++){ //ceco il massimo in ogni colonna
        columnsMax[j] = *M1[0][j]; //partiamo dal primo della colonna j
        for(int i = 1; i < p.N; i++){ //scorriamo tutti gli elementi della colonna
            if(*M1[i][j] > columnsMax[j]){ //se si trova un nuovo massimo lo aggiorniamo
                columnsMax[j] = *M1[i][j];
            }
        }
    }

    //questa è la fase di normalizzazione, dove ogni elemento viene diviso
    //cioè facciamo l'elemento / massimo della colonna 
    for(int i = 0; i < p.N; i++){ 
        for(int j = 0; j < p.M; j++){
            *M2[i][j] = *M1[i][j] / columnsMax[j]; //e il risultato della divisione si inserisce nella M2
        }
    }
}

void sortMatrixCols(double ***M, Params p){
    //Uso algoritmo Bubble Sort + sentinella booleana
    for(int j = 0; j < p.M; j++){ //blocco le colonne
        for(int pass = 0; pass < p.N - 1; pass++){ //il for delle passate
            bool sentinel = 0;
            for(int i = 0; i < p.N - pass - 1; i++){ //confronto delle coppie adiacenti
                if(*M[i][j] > *M[i+1][j]){  //swap degli elementi adiacenti
                    double tmp = *M[i][j];
                    *M[i][j] = *M[i+1][j];
                    *M[i+1][j] = tmp;
                    sentinel = 1;
                }
            }
            if(sentinel == 0) break; //se non c'è stato nessuno swap -> fermati
        }
    }
}

//creo una funzione per liberare tutte le matrici che abbiamo creato
void freeMatrix(double ***M, Params p){
    for(int i = 0; i < p.N; i++){
        for(int j = 0; j < p.M; j++){
            free(M[i][j]); //libero il terzo livello
        }
        free(M[i]); //...il secondo
    }
    free(M); //...e il primo
}

int main(int argc, char *argv[]){
    Params p = readInput(argc, argv);

    //Alloco le due matrici A e B
    double ***A = allocateMatrix(&p);
    double ***B = allocateMatrix(&p);

    //Riempio la matrice A
    fillMatrix(A, p);
    printf("** A **\n"); //...e la stampo
    printMatrix(A, p);

    //Normalizzo
    normalize(A, B, p);
    printf("\n");

    printf("** B **\n");
    printMatrix(B, p);
    sortMatrixCols(B, p); //ordiniamo con bubble sort

    printf("\n");
    printf("** B (sorted columns) **\n");
    printMatrix(B, p);

    //libero tutto quello che ho allocato
    freeMatrix(A, p);
    freeMatrix(B, p);
}

// gcc main.c -o main
// .\main input.txt 5 6

//Output:
    // ** A **
    // 12.300000 1.200000 6.500000 7.800000 9.800000 3.400000 
    // 8.540000 0.340000 9.200000 8.600000 1.200000 45.300000
    // 1.200000 3.400000 5.600000 7.800000 9.123400 6.123000 
    // 21.345000 7.234000 8.231000 9.321000 5.123000 9.123000
    // 3.540000 1.340000 3.200000 5.600000 0.200000 12.300000

    // ** B **
    // 0.576247 0.165883 0.706522 0.836820 1.000000 0.075055
    // 0.400094 0.047000 1.000000 0.922648 0.122449 1.000000
    // 0.056219 0.470003 0.608696 0.836820 0.930959 0.135166
    // 1.000000 1.000000 0.894674 1.000000 0.522755 0.201391
    // 0.165847 0.185236 0.347826 0.600794 0.020408 0.271523

    // ** B (sorted columns) **
    // 0.056219 0.047000 0.347826 0.600794 0.020408 0.075055
    // 0.165847 0.165883 0.608696 0.836820 0.122449 0.135166
    // 0.400094 0.185236 0.706522 0.836820 0.522755 0.201391
    // 0.576247 0.470003 0.894674 0.922648 0.930959 0.271523
    // 1.000000 1.000000 1.000000 1.000000 1.000000 1.000000