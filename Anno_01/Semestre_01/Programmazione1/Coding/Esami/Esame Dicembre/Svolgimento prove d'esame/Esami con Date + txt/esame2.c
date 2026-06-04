//16-02-2024
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char *programName;
    char *inputFile;
    char *outputFile;
} Params;

typedef struct {
    char nome[256];
    char cognome[256];
    int eta;
    int peso;
    int altezza;
    char sesso;
} Persona;

typedef struct node{
    Persona p;
    struct node *next;
} Node;

typedef struct{
    Node *head;
    Node *tail;
} List;

Params readInput(int argc, char *argv[]){
    Params p;

    if(argc != 3){
        fprintf(stderr, "I parametri devono essere 3.\n");
        exit(1);
    }

    char *txt = ".txt";

    char *risultato1 = strstr(argv[1], txt);
    if(risultato1 == NULL){
        fprintf(stderr, "Il file di input deve essere in formato .txt\n");
        exit(1);
    }

    char *risultato2 = strstr(argv[2], txt);
    if(risultato2 == NULL){
        fprintf(stderr, "Il file di output deve essere in formato .txt\n");
        exit(1);
    }

    p.programName = argv[0];
    p.inputFile = argv[1];
    p.outputFile = argv[2];

    printf("=======PUNTO A=======\n");
    printf("input = %s, output = %s", p.inputFile, p.outputFile);

    return p;
}

int isEmpty(List *l){
    return l->head == NULL;
}

Node* insertHead(Node *head, Persona *p){
    Node *nuovo = malloc(sizeof(Node)); //Allocare un nodo
    if(nuovo == NULL){ // Fare verifica di allocazione con relativo errore
        fprintf(stderr, "Allocazione nodo fallita.\n");
        exit(1);
    }
    //Inserire a priori la struct p nel nodo
    nuovo->p = *p;

    if(head == NULL){ //Caso 1: lista vuota
        head = nuovo;
        nuovo->next = NULL;
    }else if(head != NULL && nuovo->p.eta < head->p.eta){ //Caso 2: lista non vuota e inseriamo subito in testa
        nuovo->next = head;
        head = nuovo;
    }else{ //Caso 3: lista non vuota e inseriamo nel mezzo
        Node *curr = head;
        while(curr != NULL && curr->next != NULL && curr->next->p.eta < nuovo->p.eta){
            curr = curr->next;
        }
        nuovo->next = curr->next;
        curr->next = nuovo;
        return head;
    }
}

List readFile(Params *param){
    //Creo una lista vuola
    List l;
    l.head = NULL;
    l.tail = NULL;

    //Salvo il nome del file nel parametro inputFileName
    char *inputFileName = param->inputFile;

    //Dichiaro una struct Persona temporanea
    Persona temp_persona;
    
    //Apro il file
    FILE *fp = fopen(inputFileName, "r");
    if(fp == NULL){ //Faccio il controllo di apertura corretta
        fprintf(stderr, "Errore nell'apertura del file di input.\n");
        exit(1);
    }

    while(fscanf(fp, "%s %s %d %d %d %c", 
    temp_persona.nome, 
    temp_persona.cognome, 
    &temp_persona.eta, 
    &temp_persona.peso, 
    &temp_persona.altezza, 
    &temp_persona.sesso) == 6){
        insertHead(l.head, &temp_persona);
    }

    /*
    strcpy(temp_persona.nome, "Ciro");
    strcpy(temp_persona.cognome, "Esposito");
    temp_persona.eta = 33;
    temp_persona.peso = 121;
    temp_persona.altezza = 120;
    strcpy(&temp_persona.sesso, "M");
    insertHead(l.head, &temp_persona);
    */

    return l;    
}

void printList(List *l){ //printList: funzione che si occupa di stampare la lista a schermo
    if(isEmpty(l)){
        printf("Lista vuota, nessun elemento da stampare.\n");
        return;
    }

    Node *curr = l->head;
    printf("\n----LIST A----\n");
    while(curr != NULL){
        printf("%s\t %s\t %d\t %d\t %d\t %c\t\n", curr->p.nome, curr->p.cognome, curr->p.eta, curr->p.peso, curr->p.altezza, curr->p.sesso);
        curr = curr->next;
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    Params p = readInput(argc, argv);
    List A;
    A.head = NULL;
    A.tail = NULL;
    Persona temp_person;
    A = readFile(&p);
    insertHead(A.head, temp_person);
    a.
    printf("\n");
    printList(&A);
}
//  "cd C:\Users\giuli\Desktop\Desktop\Universita\1Anno\PrimoSemestre\Programmazione1\Esercizi ripasso dicembre"