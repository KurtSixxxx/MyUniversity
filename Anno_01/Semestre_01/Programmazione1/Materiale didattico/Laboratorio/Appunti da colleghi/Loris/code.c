#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 30

struct parametri{
    char input[4096];
    int k;
};

struct parametri readInput(int argc, char *argv[]){
    struct parametri pt;

    if(argc!=3){
        fprintf(stderr, "Usage %s <input.txt> <k>", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(pt.input, argv[1], MAX_SIZE+1);  //prima passo da dove voglio inserirla la stringa, poi dove voglio prenderla
    pt.k=atoi(argv[2]);

    if(pt.k<7||pt.k>13){
        fprintf(stderr, "Errore! K deve essere compreso tra 7 e 13");
        exit(EXIT_FAILURE);
    }

    return pt;
}

typedef struct node{
    char stringa[31];
    struct node *next;
}nodo;

void enqueue(nodo **head, nodo **tail, char *string){
    nodo* newNode=(nodo*)malloc(sizeof(nodo));
    newNode->next=NULL;

    strcpy(newNode->stringa, string);

    if(*head==NULL){
        *head=newNode;
        *tail=newNode;
    }else{
        (*tail)->next=newNode;   //successivo della coda attuale prima di modificarla
        (*tail)=newNode;         //modifica per mettere il nuovo nodo come nuova coda
    }
}

void dequeue(nodo **head){
    if(*head==NULL){
        return;
    }
    nodo *temp= *head;
    *head=temp->next;
    free(temp);
}

void riempiLista(nodo **head, nodo **tail, struct parametri pt){
    FILE *fp=fopen(pt.input, "r");
    if(fp==NULL){
        fprintf(stderr, "Errore lettura file");
        exit(-1);
    }

    char buffer[MAX_SIZE+1];

    while(fgets(buffer, MAX_SIZE, fp)){
        enqueue(head, tail, buffer);
    }
}

void printList(nodo **head){
    nodo *temp=*head;
    while(temp!=NULL){
        printf("%s", temp->stringa);
        temp=temp->next;
    }
}

int main(int argc, char *argv[]){
    struct parametri pt=readInput(argc, argv);
    nodo *head=NULL;
    nodo *tail=NULL;

    riempiLista(&head, &tail, pt);
    printList(&head);

    dequeue(&head);
    dequeue(&head);
    printf("\n");
    printList(&head);
}