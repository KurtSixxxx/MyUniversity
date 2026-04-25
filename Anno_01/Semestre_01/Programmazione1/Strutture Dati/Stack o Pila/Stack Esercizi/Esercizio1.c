#include <stdio.h>
#include <stdlib.h>

//Struttura di un nodo
typedef struct nodo{
    int data;
    struct nodo *next;
}Nodo;

//Funzione isEmpty
int isEmpty(Nodo *top){
    return top == NULL;
}

//Funzione push
void push(Nodo **top, int value){
    Nodo *nuovo = malloc(sizeof(Nodo));
    if (nuovo == NULL) {
        printf("Errore allocazione\n");
        exit(1);
    }
    nuovo->data = value;
    nuovo->next = *top;
    *top = nuovo;
}

//Funzione pop
int pop(Nodo **top){
    if(isEmpty(*top)){
        printf("Stack vuoto!\n");
        return -1;
    }

    Nodo *tmp = *top;
    int valore = tmp->data;
    *top = tmp->next;
    free(tmp);
    return valore;
}

//Funzione di stampa
void printStack(Nodo *top){
    if(isEmpty(top)){
        printf("Stack vuoto!\n");
        return;
    }

    Nodo *corrente = top;
    printf("\n--- STACK ---\n");
    while(corrente != NULL){
        printf("[%d]\n", corrente->data);
        corrente = corrente -> next;
    }
    printf("\n---------\n");
}

int main(){
    Nodo *top = NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    printStack(top);
    pop(&top);
    pop(&top);
    printStack(top);
}