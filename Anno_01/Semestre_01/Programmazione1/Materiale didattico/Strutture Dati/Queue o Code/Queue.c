#include <stdio.h>
#include <stdlib.h>

//Struttura del nodo
typedef struct node{
    int data;
    struct node *next;
} Node;

//Struttura della coda
typedef struct {
    Node *front; //chi viene servito per primo
    Node *rear; //chi arriva per ultimo
} Queue;

//Funzione per inizializzare puntatori front e rear a NULL
void initQueue(Queue *q){
    q->front = NULL;
    q->rear = NULL;
}

//Funzione isEmpty
int isEmtpy(Queue *q){
    return q->front == NULL; //Se front è a NULL, anche rear lo sarà
}

//Funzione enqueue: Inserire un nodo in fondo alla coda
void enqueue(Queue *q, int value){
    Node *nuovo = malloc(sizeof(Node));
    if(nuovo == NULL){
        printf("Allocazione del nodo fallita.\n");
        exit(-1);
    }
    nuovo->data = next;
    nuovo->next = NULL;
    if(isEmpty(q)){
        q->front = nuovo;
        q->rear = nuovo;
    }else{
        q->rear->next = nuovo;
        q->rear = nuovo;
    }
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Coda vuota: impossibile rimuovere elementi\n");
        return -1;
    }
    Node *tmp = q->front;
    int valore = tmp->data;
    q->front = q->front->next;
    free(tmp);
    return valore;
}

