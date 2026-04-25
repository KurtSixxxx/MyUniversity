#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Definiamo 3 strutture: Parametri stdin, Nodo e Lista
typedef struct{
    int N;
    char w;
} Params;

typedef struct node{
    char *string;
    struct node *next;
} Node;

typedef struct{
    Node *head;
    Node *tail;
} List;

//Funzione per leggere input le inserisce tutto nella struct Params p
Params readInput(int argc, char *argv[]){
    Params p = {0, 0};

    if(argc != 3){
        fprintf(stderr, "[ERR]: il numero di parametri richiesti è pari a 2.\n");
        exit(-1);
    }

    char **end = malloc(sizeof(char*));
    *end = NULL;
    p.N = (int)strtol(argv[1], end, 0);

    if(p.N < 10 || p.N > 20){
        fprintf(stderr, "[ERR]: il valore del parametro N deve essere incluso nell'intervallo [10,20].\n");
        exit(-1);
    }

    p.w = argv[2][0];
    return p;
}

//Genera una stringa nell'intervallo a-z di lunghezza L nell'intervallo 5-15
char* genString(Params *p){
    int L = rand()%(15 - 5 + 1) + 5;
    char *str = malloc(sizeof(char) * (L + 1)); //Aggiungo 1 per il terminatore nullo \0
    if(str == NULL){
        fprintf(stderr, "[ERR]: errore nel processo di allocazione della stringa.\n");
        exit(-1);
    }
    for(int i = 0; i < L; i++){
        str[i] = rand()%('z' - 'a' + 1) + 'a';
    }
    str[L] = '\0'; //Aggiungiamo il terminatore come ultimo carattere

    return str;
}

//Inizializza la lista impostanto sia testa che coda a NULL
void initList(List *l){
    l->head = NULL;
    l->tail = NULL;
}

//Se la testa è NULL la lista è vuota
int isEmpty(List *l){
    return l->head == NULL;
}

//Inserire la stringa in ordine: Dopo la testa e in ordina lessicografico crescente
void insertString(List *l, Params *p){
    Node *new = malloc(sizeof(Node));
    if(new == NULL){
        fprintf(stderr, "[ERR]: fallimento nel processo di allocazione del nuovo nodo.\n");
        exit(-1);
    }

    new->string = genString(p);

    if(isEmpty(l)){
        l->head = new;
        l->tail = new;
        new->next = NULL;
        return;
    }

    //Se il nodo deve essere inserito in testa
    if(strcmp(new->string, l->head->string) < 0){
        new->next = l->head;
        l->head = new;
        return;
    }

    //Se il nodo deve essere inserito in mezzo
    Node *curr = l->head->next;
    Node *prev = l->head;

    while(curr != NULL && strcmp(new->string, curr->string) > 0){
        prev = curr;
        curr = curr->next;
    }

    if(curr != NULL){
        prev->next = new;
        new->next = curr;
        return;
    }else{ //Se il nodo va inserito in coda
        l->tail->next = new;
        l->tail = new;
        l->tail->next = NULL;
    }
}

//Chiama la funzione genstring N volte
void genList(List *l, Params *p){
    int n = p->N;
    for(int i = 0; i < n; i++){
        insertString(l, p);
    }
}

//Stampa la lista
void printList(List *l){
    printf("---LIST---\n");
    Node *curr = l->head;
    while(curr != NULL){
        printf("%s\n", curr->string);
        curr = curr->next;
    }
    printf("---END LIST---\n");
}

void printOcc(List *l, Params *p){
    Node *curr = l->head;
    int count = 0;
    while(curr!=NULL){
        for(int i = 0; i < strlen(curr->string); i++){
            if(curr->string[i] == p->w){
                count++;
            }
        }
        curr = curr->next;
    }
    printf("\nNumero di occorrenze: %d", count);
}

int main(int argc, char* argv[]) {
    srand(time(0));
    Params p = readInput(argc, argv);
    List l;
    initList(&l);
    genList(&l, &p);
    printList(&l);
    printOcc(&l, &p);
}