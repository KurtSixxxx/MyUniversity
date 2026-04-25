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

    strncpy(pt.input, argv[1], MAX_SIZE+1);  //prima passo dove voglio inserirla la stringa, poi dove voglio prenderla
    pt.k=atoi(argv[2]);

    if(pt.k<7||pt.k>13){
        fprintf(stderr, "Errore! K deve essere compreso tra 7 e 13");
        exit(EXIT_FAILURE);
    }

    return pt;
}

typedef struct node{
    char stringa[MAX_SIZE+1];
    struct node* next;
} nodo;


void inserisciNodo(nodo** head, char *string){
    nodo* newNode=(nodo*)malloc(sizeof(nodo));
    newNode->next=NULL;

    strncpy(newNode->stringa, string, MAX_SIZE+1);
    if(*head!=NULL){
        newNode->next=(*head);
    }

    (*head)=newNode;
}

void buildList(nodo** head, struct parametri pt){
    FILE *fp=fopen(pt.input, "r");
    if(fp==NULL){
        fprintf(stderr, "Errore lettura file");
        exit(-1);
    }
    char buffer[MAX_SIZE+1];

    while(fgets(buffer, MAX_SIZE, fp)){
        inserisciNodo(head, buffer);
    }
    fclose(fp);
}

void printList(nodo** head){
    nodo* temp=*head;   //creiamo un nodo ausiliario in modo da poterlo modificare, senza modificare head
    while(temp!=NULL){
        printf("%s", temp->stringa);
        temp=temp->next;
    }
}

int main(int argc, char *argv[]){
    struct parametri pt=readInput(argc, argv);
    nodo *head=NULL;

    buildList(&head, pt);
    printList(&head);
}