/*
    * malloc() is used to allocate memory blocks of a specific size, 
    * calloc() is used to allocate memory blocks of a specific size and initializes the memory with zero.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int get_random() { //Questa è una funzione che il professore fornisce con la traccia dell'esame, utile per generare caratteri in maniera pseudocausale. Suppongo...
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

struct data {   //Questa è la struct che contiene tutti i dati in input inseriti dall'utente
    int k, N, M; //Questi sono gli interi che utilizzeremo: 'k' è in input con intervallo 10-15, N ed M sono le dimensioni della matrice 
    char w; //Se questo char fosse un altro simbolo, ad esempio 'a', allora verrebbero trovate le occorrenze di 'a' piuttoso che quelle di 'w'. Ovviamente questo è solo il nome della varibaile, che per comodità è stata chiamata con il nome associato al carattere da trovare.
};

// Punto A
struct data readInput(char *argv[], int argc){  //Questa funzione legge in input i parametri arcgc e argv, ossia argoment counter e argoment vector. Non ho ancora ben chiaro cosa siano, ma so già che ad esempio il solo nome del programma e i dati in input occuopano degli "indici"
    if(argc != 5){ //Se i contenuti passati all'argoument counter sono diversi da 5 allora viene stampato il codice errore -1.
        fprintf(stderr, "I parametri non sono validi");
        exit(-1);
    }

    struct data d = {0,0,0,0}; //Credo che questa sia la struct data associata ad un array(?)

    //La parte sottostante si occupa di convertire la stringa ad intero con strtol()
    char **end = malloc(sizeof(char*)); //si alloca un puntatore a puntatore a char per capire dove si ferma la conversione della stringa
    *end = NULL; //il puntatore viene inizializzato

    d.k = (int) strtol(argv[1], end, 0); //
    //d.k = atoi(argv[1]); //Atoi dovrebbe essere una funzione che esegue una sorta di casting(?)

    if(**end){ //Questo è un messaggio d'errore che controlla se k è un dato di tipo intero o no, ma non so cosa sia '**end'
        fprintf(stderr, "Il k deve essere intero");
        exit(-1);
    }

    if(d.k<10 || d.k>15){ //Qui si accede alla struct e alla variabile int k, tramite il '.', e si controlla se l'intero k è compreso tra 10 e 15. Se non è così viene stampato un messaggio d'errore (-1)
        fprintf(stderr, "Il k deve essere compreso tra 10 e 15");
        exit(-1);
    }

    if(strlen(argv[2])!=1){ //Qui si usa la funzione string lenght. Se il dato all'indice 2 dell'argoument counter è diverso da 1 si stampa stderr (che penso stia per Standard Error, con un errore (-1)), e indica che la variabile char w è vuota, ossia non ha ricevuto alcun carattere in input.
        fprintf(stderr, "w è vuoto!");
        exit(-1);
    }

    d.w = argv[2][0]; //Qui si accede sempre con struct e con operatore '.' alla variabile 'w' e si controlla se si trova nella "matrice" dell'argoment vector [2][0]?

    if(d.w<'a' || d.w>'z'){ //Qui si fa un if per verificare se la variabile 'char w', presente nella struct, sia compresa tra 'a' e 'z'. Se non è compesa in questo intervallo alfabetico si stampa l'errore (-1)
        fprintf(stderr, "Il w deve essere compreso tra 'a' e 'z' ");
        exit(-1);
    }

    d.N = (int) strtol(argv[3],end,0); //Qui si accede al parametro N (utilizzato per le dimensioni della matrice) e si fa un casting, ma non so cosa sia (argv[3],end,0) e perchè o come si usi atoi
    //d.N = atoi(argv[3]);

    if(**end){ //Qui non so perché si prende come parametro (**end), ma so che controlla se N è un intero o meno, e in caso non sia un intero si stampa un errore.
        fprintf(stderr, "N deve essere intero");
        exit(-1);
    }

    if(d.N<4 || d.N>8){ //Qui si controlla che int N sia compreso tra 4 e 8, e in caso non lo sia si stampa un errore.
        fprintf(stderr, "N deve essere compreso tra 4 e 8");
        exit(-1);
    }
    d.M = (int) strtol(argv[4], end, 0);//Qui si accede al parametro M (utilizzato per le dimensioni della matrice) e si fa un casting, ma non so cosa sia (argv[4],end,0) e perchè o come si usi atoi
    //d.M = atoi(argv[4]);

    if(**end){ //Qui non so perché si prende come parametro (**end), ma so che controlla se M è un intero o meno, e in caso non sia un intero si stampa un errore.
        fprintf(stderr, "M deve essere intero");
        exit(-1);
    }

    if(d.M<4 || d.M>8){ //Qui si controlla che int M sia compreso tra 4 e 8, e in caso non lo sia si stampa un errore.
        fprintf(stderr, "M deve essere compreso tra 4 e 8");
        exit(-1);
    }

    return d; //Non so perchè ci sia il return, a cosa serva e perchè restitutisca d. Forse restituisce la struct d dopo aver inserito tutti i dati?
}

// Punto B
char*** allocateS(int N, int M){ //Qui si alloca, tramite funzione, una matrice di stringhe chiamata S con parametri N ed M che sono le sue dimensioni. Ma non so perchè ci sia (char***)
    char ***S = calloc(N, sizeof(char**)); //Viene fatta al calloc per azzerare tutto prima di allocare i dati.
    for(int i=0; i<N; i++){ //Penso che questo for venga utilizzato per iterare ogni riga e colonna della matrice S (?)
        S[i] = calloc(M, sizeof(char*));
    }
    return S; //Non so perché ci sia il return, a cosa serva e perché restituisca S. Ma penso che restituisce la matrice che è stata "compilata" con i dati necessari e allocata. (?)
}

// Punto C
char* genString(int len, char min, char max){ //Qii viene usata una funzione con tipo di ritorno (char*) - non so perché - che genera le stringhe da inserire nella matrice S. Prende come parametri un int len che sarebbe la lunghezza delle stringhe, e un char min e max che non so cosa siano.
    char *s = calloc(len, sizeof(char*)); //Qui viene allocata con calloc ogni stringa penso(?)

    for(int i=0; i<len; i++){ //Si itera con for sulla lunghezza della stringa e si creano le stringhe, generate con 'get_random() % (max-min+1) + min'
        s[i] = get_random() % (max-min+1) + min;
    }

    return s; //Non so perchè si faccia questa return
}

void fillS(char ***S, int N, int M, int k){ //Qui penso che questa funzione abbia il compito di "Riempire S", come suggerisce il nome, con le stringhe generate precedentemente.
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            S[i][j] = genString(k, 'a', 'z'); //Qui si usano due cicli for intersecati e si chiama la funzione genString che prende come parametri l'intero k e l'intervallo 'a-z'
        }
    }
}

// Punto D - bubblesort
void sortS(char ***S, int N, int M){ //Qui si usa il bubble sort per ordinare in maniera crescente lessicografica la matrice. Ma non ho mai studiato il bubble sort.
    for(int j=0; j<M; j++){
        for(int pass=0; pass<N-1; pass++){
            for(int i=0; i<N-1-pass; i++){
                if(strcmp(S[i][j], S[i+1][j]) > 0){
                    char *tmp = S[i][j];
                    S[i][j] =  S[i+1][j];
                    S[i+1][j] = tmp;
                }
            }
        }
    }
}

// Punto E
void printMatrix(char ***S, int N, int M){ //Qui viene scritta una funzione che serve per stampare la matrice S. Infatti prende in input la matrice e le sue dimensioni
    for(int i=0; i<N; i++){ //Itera sulle righe
        for(int j=0; j<M; j++){ //Itera sulle colonne
            printf("%s ", S[i][j]); //Stampa la stringa che si trova nella posizione NxM
        }
        printf("\n"); //Stampa una newline per distanziarle
    }
}

// Punto F
int conta(char* s, char w){ //Questa dovrebbe essere la funzione che conta il numero di occorrenze. Ma non so perchè prenda in input (char* s)
    int c = 0; //questa dovrebbe essere la variabile che contiene il numero di occorrenze trovate
    for(int i=0; i<strlen(s); i++){ //penso che strlen(s) in questo caso voglia dire "itera su tutta la stringa"...
        if(s[i]==w) //..."se nella stringa s alla posizone i trovi il carattere 'w"...
            c++; //..."incrementa c".
    }
    return c; //Ritorna c per dire il numero di occorrenze che hai trovato
}

void printMax(char ***S, int N, int M, char w){ //Questa è la funzione per la stampa della stringa con il maggior numero di occorrenze.
    //int max = 0;
    int max = 0;
    int i_max = 0;
    int j_max = 0;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            int contatore = conta(S[i][j], w);
            if(contatore > max){
                max = contatore;
                i_max = i;
                j_max = j;
            }
        }
    } //NON HO CAPITO QUESTA PARTE

    printf("\n Stringa con %d occorrenze di '%c' trovata agli indici %d,%d: ", max, w, i_max, j_max); //Qui deduco che max sia il numero di occorrenze trovate, w il carattere, e i_max e j_max gli indici/coordinate della stringa nella matrice

    for(int i=0; i<strlen(S[i_max][j_max]); i++){ //NON HO CAPITO QUESTA PARTE. Ma credo che serva per sostituire le occorrenze trovate con il simbolo '*'
        char c = S[i_max][j_max][i];
        c = (c==w) ? '*' : c;
        printf("%c", c);
    }
    printf("\n");
}

// main
int main(int argc, char* argv[]){ //Questo è il main dove vengono invocate tutte le funzioni che abbiamo creato
    struct data d = readInput(argv, argc);
    char ***S = allocateS(d.N, d.M);
    fillS(S, d.N, d.M, d.k);
    sortS(S, d.N, d.M);
    printMatrix(S, d.N, d.M);
    printMax(S, d.N, d.M, d.w);
}