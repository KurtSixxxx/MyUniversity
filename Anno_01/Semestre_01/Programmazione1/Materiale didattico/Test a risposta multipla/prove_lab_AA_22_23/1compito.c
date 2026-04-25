#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funzione get_random
unsigned int get_random() {
 static unsigned int m_w = 123456;
 static unsigned int m_z = 789123;
 m_z = 36969 * (m_z & 65535) + (m_z >> 16);
 m_w = 18000 * (m_w & 65535) + (m_w >> 16);
 return (m_z << 16) + m_w;
}

//Inizializzo la struct con le 4 variabili
struct data{
    int k;
    char w;
    int N;
    int M;
};

//Dichiaro la funzione readInput
struct data readInput (int argc, char*argv[]){
//Con questo if indico che sono stati inseriti o più, o meno dei caratteri richiesti
if(argc != 5){
    fprintf(stderr, "Errore il numero di paramertri inseriti è errato.\n");
    exit (-1);
}

//Inizializzo tutte le variabili della struct a zero
struct data c = {0, 0, 0, 0};

char **end = malloc(sizeof(char*)); //Serve per capire se il primo elemento è una stringa, e per terminare la conversione di 'strtod'
*end = NULL; //

c.k = (int) strtod(argv[1], end); //Accedo alla prima variabile della struct e converte la stringa in long e con (int) effettua il casting 

//1° errore: Se "end" esiste è una stringa, mentre deve essere un valore intero.
if(**end){
    fprintf(stderr, "Il primo elemento deve essere un valore intero.\n");
    exit (-1);
}

//2° errore: Il valore k non appartiene al range richiesto
if(c.k < 10 || c.k > 15){
    fprintf(stderr, "Il valore deve trovarsi nel range [10,15]\n");
    exit (-1);
}

//3° errore: La variabile w deve essere un carattere 'char'
if(strlen(argv[2]) != 1){
    fprintf(stderr, "Il valore deve essere un carattere.\n");
    exit (-1);
}

if(c.w < 'a' || c.w > 'z'){
    fprintf(stderr, "Il valore deve trovarsi nel range ['a','z']\n");
    exit (-1);
}

c.w = argv[2][0]; /*Questo indica che stai accedendo al primo carattere della stringa argv[2]. In C, le stringhe sono array di caratteri, e gli indici partono da 0. Quindi, argv[2][0] è il primo carattere di quella stringa.*/

if(**end){
    fprintf(stderr, "L'elemento N deve essere un intero.\n");
    exit (-1);
}

if(c.N < 4 || c.N > 8){
    fprintf(stderr, "Il valore deve trovarsi nel range [10,15]\n");
    exit (-1);
}

if(**end){
    fprintf(stderr, "L'elemento M deve essere un intero.\n");
    exit (-1);
}

if(c.M < 4 || c.M > 8){
    fprintf(stderr, "Il valore deve trovarsi nel range [10,15]\n");
    exit (-1);
}

return c;

};

//Funzione allocateS
char*** allocateS(int N, int M){
char*** S = malloc(N * sizeof(char**));
for(int i = 0; i < N; i++){
    S[i] = malloc(M * sizeof(char*));
}
return S;
}

//Funz genString
char* genString(int len, char min, char max){
    char* S = malloc(sizeof(char));
    for(int i = 0; i < len; i++){
        S[i] = getRandom() % (max-min+1)+min; //Non deve avere parametri
    }
    return S;
}

// Funzione fillS
void fillS(char***S, int N, int M, int k){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            S[i][j] = genString (k, 'a', 'z');
        }
    }
}

//Algoritmo -sort
void sortS(char***S, int N, int M){
    for(int j = 0; j < M; j++){
        for(int pass = 0; pass < N-1 ; pass++){
            for(int i = 0; i < N-pass-1; i++){
            if(strcmp(S[i][j],S[i+1][j])>0){
                char* tmp = S[i][j];
                S[i][j] = S[i+1][j];
                S[i+1][j] = tmp;
            }
            }
        }
    }   

}

int main (int argc, char*argv []){
    struct data c = readInput(argc, argv);
    chatr***S = allocateS(c.N, c.M);
    fills(S, c.N, c.M, c.k);
    return 0;
}