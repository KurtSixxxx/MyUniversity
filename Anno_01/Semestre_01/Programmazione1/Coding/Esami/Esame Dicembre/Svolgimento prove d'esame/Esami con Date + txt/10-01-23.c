/*
Srivere un programma in C che:
A. prenda in input da tastiera (argomenti della funzione main) un intero positivo N in [10,20] ed un carattere w; se gli argomenti a riga di comando non rispondono ai suddetti requisiti, il programma stampa un messaggio di errore sullo standard error e termina la propria esecuzione;
B. generi, mediante successivi inserimenti, una lista concatenata semplice (ordinata in modo crescente - ordinamento lessicografico) che contenga N stringhe con caratteri pseudo-casuali in ['a'-'z'] di lunghezza pseudo-casuale L nell'intervallo [5,15];
C. stampi sullo standard output l'intera lista;
D. stampi sullo standard output il numero totale di occorrenze del carattere w in tutte le stringhe della lista.

Il programma potrà essere articolato in un unico file sorgente, ma dovrà contenere almeno le seguenti funzioni con opportuni parametri formali:
- readInput: funzione che prenda in input gli argomenti della funzione main argv ed argc, controlli i requisiti dei parametri e restituisca al chiamante un record (struct) che contenga tutti i parametri.
- genString: funzione che restituisca una stringa di caratteri pseudo-casuali appartenenti ad un determinato intervallo specificato mediante opportuni parametri formali.
- insertString: funzione che inserisca una stringa nella lista; per tale funzione e' possibile usare la funzione di libreria strcmp();
- genList: funzione che si occupa di creare e riempire la lista di stringhe come richiesto nel punto B;
- printList: funzione che si occupa di stampare la lista a schermo come specificato nel punto C;
- printocc: funzione che stampa sullo standard output il numero totale di occorrenze del carattere w in tutte le stringhe della lista, come specificato nel punto D.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Struttura dei parametri
typedef struct{
    int N;
    char w;
} Params;

//Struttura dei nodi
typedef struct node{
    char *str;
    struct node *next;
} Node;

//Struttura della lista
typedef struct{
    Node *head;
    Node *tail;
} List;

//Funzione per il controllo degli input
Params readInput(int argc, char *argv[]){
    
    Params p;

    if(argc != 3){
        fprintf(stderr, "Il numero di parametri deve essere uguale a 3.\n");
        exit(1);
    }

    int N = atoi(argv[1]);
    if(N < 10 || N > 20){
        fprintf(stderr, "Il valore di N deve appartenere all'intervallo [10, 20].\n");
        exit(1);
    }

    if(strlen(argv[2]) != 1){
        fprintf(stderr, "E' richiesto almeno un carattere.\n");
        exit(1);
    }

    p.N = atoi(argv[1]);
    p.w = argv[2][0]; 

    return p;
}

char* genString(){
    //Definiamo i valori per gli intervalli
    int minValue = 5;
    int maxValue = 15;
    char minChar = 'a';
    char maxChar = 'z';

    //Generiamo l'intervallo di lunghezza;
    int L = rand()%(maxValue - minValue + 1) + minValue;

    //Allochiamo la stringa
    char *randomString = malloc(sizeof(char) * (L+1)); //+1 viene aggiunto per il terminatore nullo

    //Ora creiamo le stringhe
    for(int i = 0; i < L; i++){
        randomString[i] = rand()%(maxChar - minChar + 1) + minChar;
    }
    randomString[L] = '\0'; //Inseriamo il terminatore nullo alla fine della stringa;

    return randomString;    //Restituiamo la stringa
}

int isEmpty(List *l){
    return l->head == NULL;
}

void printList(List *l){ //printList: funzione che si occupa di stampare la lista a schermo
    if(isEmpty(l)){
        printf("Lista vuota, nessun elemento da stampare.\n");
        return;
    }

    Node *curr = l->head;
    printf("---- LIST ----\n");
    while(curr != NULL){
        printf("%s\n", curr->str);
        curr = curr->next;
    }
    printf("\n");
}

void printOcc(List *l, char w){
    if(isEmpty(l)){
        printf("Lista vuota, nessun elemento da stampare.\n");
        return;
    }

    int count = 0;

    Node *curr = l->head;
    while(curr != NULL){
        // Scorri TUTTI i caratteri della stringa curr->str
        for(int i = 0; curr->str[i] != '\0'; i++){
            if(curr->str[i] == 'w'){
                count++;
            }
        }

        curr = curr->next;
    }

    printf("Occorrenze di '%c': %d\n", 'w', count);
}

void inserString(List *l, char *str){
    Node *nuovo = malloc(sizeof(Node)); //Allochiamo il nuovo nodo
    if(nuovo == NULL){ //Facciamo una verifica sull'allocazione 
        fprintf(stderr, "Allocazione del nodo fallita.\n");
        exit(1);
    }

    nuovo->str = str; //inseriamo la stringa nel campo str, tanto a prescindere deve andarci
    //caso 1: lista vuota
    if(isEmpty(l)){
        l->head = nuovo; //se la lista è vuota, il nuovo nodo sarà sia head che tail
        l->tail = nuovo; 
        nuovo->next = NULL; //e ovviamente se il nuovo nodo è l'unico punterà a null
        return; //usciamo, altrimenti la funzione compie le altre operazioni
    }

        //caso 2: inserimento in testa
        if(strcmp(str, l->head->str) < 0){ //poiché lista crescente, se la stringa è minore bisogna inserirla all'inizio
            nuovo->next = l->head; //diciamo che il next del nodo è la vecchia testa
            l->head = nuovo; //e che il nuovo nodo è la nuova testa
            return; //usciamo, altrimenti la funzione compie le altre operazioni
        }else{ 
        //caso 3: inserimenro in mezzo
        Node *curr = l->head; //creiamo un "Nodo cursore" per scorrere la lista

/* Perché confrontiamo strcmp(str, curr->next->str) e NON strcmp(str, curr->str)?

 Quando stiamo inserendo in una lista ordinata, dobbiamo capire se la nuova stringa
 'str' va inserita TRA il nodo corrente (curr) e il nodo successivo (curr->next).

 La domanda che dobbiamo farci è:
     "La nuova stringa deve andare PRIMA del nodo successivo?"

 Per questo confrontiamo:
     strcmp(str, curr->next->str)

 - Se il risultato è > 0 significa che 'str' è più grande del nodo successivo,
   quindi NON deve essere inserita qui → continuiamo a scorrere (curr = curr->next).

 - Se il risultato è < 0 significa che 'str' è più piccola del nodo successivo,
   quindi deve essere inserita PROPRIO tra curr e curr->next.

 NOTA:
 Confrontare con curr->str non serve, perché se siamo arrivati fino a curr
 significa che abbiamo già stabilito che str è più grande di curr.
 Quello che ci interessa è il NODO DOPO curr, che decide la posizione di inserimento.
*/
        while(curr->next != NULL && strcmp(str, curr->next->str) > 0){
            curr = curr->next; //scorriamo la lista
            }
            nuovo->next = curr->next; //dico che il next del nuovo nodo è quello che era il next di curr, quindi il nodo precedente
            curr->next = nuovo; //e che il next del nodo corrente è proprio il nuovo

            if(nuovo->next == NULL){ //se siamo a fine lista e il next del nuovo nodo è uguale a null allora il nuovo nodo è diventato coda della lista
                l->tail = nuovo;
            }
        }
    }

void genList(List *l, Params p){
    int N = p.N;

    for(int i = 0; i < N; i++){
        char *s = genString();
        inserString(l, s);
    }
}

void freeList(List *l){
    Node *curr = l->head;
    Node *tmp;

    while(curr != NULL){
        tmp = curr->next;
        free(curr->str);   // libera la stringa allocata da genString
        free(curr);        // libera il nodo
        curr = tmp;
    }

    l->head = NULL;
    l->tail = NULL;
}


int main(int argc, char *argv[]){
    srand(time(0)); //Chiamo la funzione per inizializzare il seme
    Params p = readInput(argc, argv);

    List l;
    l.head = NULL;
    l.tail = NULL;

    genList(&l, p);
    printList(&l);
    printOcc(&l, p.w);
    freeList(&l);
}