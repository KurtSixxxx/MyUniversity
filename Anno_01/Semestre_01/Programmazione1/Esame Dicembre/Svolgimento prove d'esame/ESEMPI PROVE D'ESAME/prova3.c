#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{ //Struttura dei parametri
    int N;
    char w;
} Params;

typedef struct node{ //Struttura del nodo
    char* data;
    struct node *next;
} Node;

typedef struct{ //Struttura della lista
    Node *head;
    Node *tail;
} List;

Params readInput(int argc, char *argv[]){ //Funzione che legge i parametri da riga di comando
    Params p = {0, 0}; //inzializzo struttura dei parametri

    if(argc != 3){ //il nummero di argomenti deve essere uguale a 3: nomeprogramma | int N | char w
        fprintf(stderr, "[ERROR]: Il numero di parametri deve essere pari a 2.\n");
        exit(-1);
    }
//                                                                                                                                                            qui
//Questo è il procedimento di utilizzo di strol                                                                                                                |
    char **end = malloc(sizeof(char*)); //Questo puntatore si chiama end perché serve per capire dove terminano i numeri e dove iniziano i caratteri, tipo: 123abc
    *end = NULL; //per sicurezza si mette sempre a NULL
    p.N = (int) strtol(argv[1], end, 0); //Si chiama la funzione e si dice che al campo N della struct p vogliamo memorizzare l'argv 1 con base 0(sarebbe la base numerica automatica), e ovviamente si fa il casting a int
    
    if(**end){ //se ci sono caratteri dopo il numero → [ERROR] 
        fprintf(stderr, "[ERROR]: Il primo parametro deve essere un intero.\n");
        exit(-1);
    }

    if(p.N < 10 || p.N > 20){ //Qui controlliamo se il valore int N sta nel range che abbiamo definito
        fprintf(stderr, "[ERROR]: Il parametero N deve essere nel range [10,20].\n");
        exit(-1);
    }

    p.w = argv[2][0]; //Memorizziamo il carattere all'argv 2
    if(strlen(argv[2]) != 1){
        fprintf(stderr, "[ERROR]: Il parametero inserito non è un intero.\n");
        exit(-1);
    }

    return p; //Ritorniamo la struct
}

void initList(List *l){ //Funzione che inizializza la lista
    l->head = NULL;
    l->tail = NULL;
}

//N stringhe pseudocasuali nell'intervallo a-z di lunghezza L [5,15]
char* genString(){ //Funzione che genera stringhe casuali
    int L = rand()%(15 - 5 + 1) + 5;

                                        //?char **str = malloc(sizeof(char*) * L);
    char *str = malloc(sizeof(char) * (L + 1)); //L+1 serve per il terminatore nullo
    if(str == NULL){
        fprintf(stderr, "ALlocazione stringa fallita.\n");
        exit(-1);
    }

    for(int i = 0; i < L; i++){
        char c = rand()%('z' - 'a' + 1) + 'a';
        str[i] = c;
    }
    str[L] = '\0';

    return str;
}

void insertString(List *l, char *new_string){ //Funzione che inserisce i nodi in maniera ordinata
	Node *newNode = malloc(sizeof(Node));
	if(newNode == NULL){
		fprintf(stderr, "[ERR]: Allocazione del nodo fallita.\n");
		exit(-1);
	}
	
	newNode->data = malloc(strlen(new_string)+1); //Allochiamo lo spazio per la nuova stringa
	strcpy(newNode->data, new_string); //Copiamo nel campo data del nuovo nodo la nuova stringa

	Node *curr = l->head;
	Node *prev = NULL;
	
	while(curr != NULL && strcmp(new_string, curr->data) > 0){ //Scorro finché non siamo allla fine e finché la mia nuova stringa è maggiore di quell nei nodi
		prev = curr;
		curr = curr->next;
	}
	
	if(prev == NULL){ //Inserimento in testa
		newNode->next = l->head;
		l->head = newNode;
	}else{ //Inserimento in mezzo
		newNode->next = curr;
		prev->next = newNode;
	}
}

void genList(List *l, Params *p){
    int N = p->N;
    for(int i = 0; i < N; i++){
        char *new_string = genString();
        insertString(l, new_string);
        free(new_string);
    }
}

void printList(List *l){ //Funzione che stampa la lista
    printf("\n---STAMPA---\n");
    Node *curr = l->head;
    while(curr != NULL){
        printf("%s\n", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int printOcc(List *l, Params *p){ //Funzione che stampa le occorrenze del carattere w
    int count = 0; //Inizializzo un contaore

    Node *curr = l->head; //Imposto il cursore "curr" alla testa della lista
    while(curr != NULL){ //Finché non arriviamo a fine lista...
        char* str = curr->data; //Inserisci il dato in una stringa
        for(int i = 0; i < strlen(str); i++){ //Itera su tutti i caratteri della stringa
            if(str[i] == p->w){ //Se un carattere è uguale a quello immesso come parametro
                count++; //Aggiorna il contatore
            }
        }
        curr->data = NULL; //Impostiamo il campo data di tmp a NULL per "ripulire"
        curr = curr->next; //Procediamo a scorrere
    } 
    printf("Totale di occorrenze di '%c' presenti in tutta la lista: %d", p->w, count); //Stampiamo le occorrenze
    return count; //Ritorniamo il valore totale di occorrenze
}

//---------------------------------------------------------------------------------------------------------------------------------------

int main(int argc, char *argv[]){
    srand(time(0));
    Params p = readInput(argc, argv);
    List l;
    initList(&l);
    genList(&l, &p);
    printList(&l);
    printOcc(&l, &p);
}