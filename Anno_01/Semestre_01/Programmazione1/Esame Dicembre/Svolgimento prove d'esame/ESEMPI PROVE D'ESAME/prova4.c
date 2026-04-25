#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
    char word[101]; //La prima parola di ogni riga. Aggiungo +1 per '\n'
    int count;      //Il numero di occorrenze della parola 'word'
    struct node *next;
} Node;

typedef struct{ //Struttura che indica la lista
    Node *head;
    Node *tail;
} List;

int readN(int argc, char *argv[]){ //Funzione richiesta dal professore, legge il parametro n a riga di comando
    if(argc!=2){ //Se il numero di argomenti non comprende nomeprogramma + int n
        fprintf(stderr, "Devi inserire almeno un parametro.\n"); //Stampa dicendo che l'utente deve inserire un parametro
        exit(-1);
    }

    char **end = malloc(sizeof(char*)); //Allochiamo il puntatore end della funzione strol
    *end = NULL; //Lo impostiamo a null
    int n = (int) strtol(argv[1], end, 0); //E chiamiamo quest'ultima

    printf("Valore di 'n' inserito: %d", n); //Stampiamo per assicurarci che il valore sia stato inserito
    return n; //E lo restituiamo alla variabile
}

void initList(List *l){ //Funzione che chiamerò nel main per impostare la lista a NULL
    l->head = NULL;
    l->tail = NULL;
}

int isEmpty(List *l){ //Funzione che controlla se la lista è vuota
    return l->head == NULL;
}

void insertTail(List *l, Node *newNode){
    newNode->next = NULL;

    if(isEmpty(l)){ //Se la lista è vuota, il nuovo nodo sarà la testa e la coda della lista
        newNode->next = NULL;
        l->head = newNode;
        l->tail = newNode;
        return;
    }

    l->tail->next = newNode;						//Prendiamo la vecchia coda e facciamo puntare il suo next al nuovo nodo
	l->tail = newNode;
}

Node* allocationNode(){ //Funzione che alloca un nodo.
    Node *newNode = malloc(sizeof(Node));
    if(newNode == NULL){
        fprintf(stderr, "[ERR]: Allocazione nuvovo nodo fallita.\n");
        exit(-1);
    }

    return newNode;
}

int countOccurrences(const char *line, const char *word){
    char copia[1000];
    strcpy(copia, line);
    int counter = 0;
    char *token = strtok(copia, " ");
    
    while(token != NULL){
        if(strcmp(token, word) == 0){
            counter++;
        }
        token = strtok(NULL, " ");
    }
    
    return counter;
}

void insertInNode(Node *new, char *word, int occ){
    strcpy(new->word, word);
    new->count = occ;
}

List readFile(char *fileInputName){
    List l;
    initList(&l);

    FILE *fp = fopen(fileInputName, "r");
    if(fp == NULL){
        fprintf(stderr, "[ERR]: Processo di apertura file fallito.\n");
        exit(-1);
    }

    char riga[1000];
    while(fgets(riga, 1000, fp) != NULL){
        char firstword[101];
        sscanf(riga, "%s", firstword);
        int occ = countOccurrences(riga, firstword);
        Node *new = allocationNode();
        insertInNode(new, firstword, occ);
        insertTail(&l, new);
    }

    fclose(fp);
    return l;
}

void filterList(List *l, int n){
	Node *curr = l->head;
	Node *prev = NULL;
	
	while(curr != NULL){
		if(curr->count < n){
		Node *next = curr->next;
			//tutto il processo di eliminazione è qui sotto

			//Caso 1: curr è la testa
			if(curr == l->head){
				l->head = curr->next;
			}else{
			//Caso 2: curr è nel mezzo
				prev->next = next;
			}
			//Caso 3: curr è la coda
			if(curr == l->tail){
				l->tail = prev;
                if(l->tail != NULL){
				l->tail->next = NULL;
                }
			}
			
			free(curr);
			curr = next;
			
		}else{
			prev = curr;
			curr = curr->next;
		}
	}
}

void printList(List *l){
    Node *curr = l->head;
    printf("--- LISTA ---\n");
    while(curr != NULL){
        printf(" [ %s | %d ] -> ", curr->word, curr->count);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main(int argc, char *argv[]) {
    int n = readN(argc, argv);

    char *fileInputName = "prova4Input.txt";
    printf("\n");

    List l = readFile(fileInputName);

    printf("Lista prima di filtrazione.\n");
    printList(&l);

    filterList(&l, n);

    printf("Lista dopo filtrazione.\n");
    printList(&l);

    return 0;
}

// cd "C:\Users\giuli\Desktop\Desktop\Universita\1Anno\PrimoSemestre\Programmazione1\Esame Dicembre\Svolgimento prove d'esame\ESEMPI PROVE D'ESAME"
// gcc prova4.c -o prova4
// .\prova4 3