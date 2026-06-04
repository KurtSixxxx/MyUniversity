#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

int isEmpty(Node *top){
    return top == NULL;
}

void push(Node **top, int value){
    Node *nuovo = malloc(sizeof(Node));
    if(nuovo == NULL){
        printf("\nAllocazione fallita.\n");
        return;
    }
    nuovo->data = value;
    nuovo->next = *top;
    *top = nuovo;
}

int pop(Node **top){
    if(isEmpty(*top)){
        printf("Stack vuoto!\n");
        return -1;
    }
    Node *tmp = *top;
    int valore = tmp->data;
    *top = tmp->next;
    free(tmp);
    printf("\nNodo %d rimosso\n", valore);
    return valore;
}

int peek(Node *top){
    if(isEmpty(top)){
        printf("Stack vuoto!\n");
        return -1;
    }
    printf("Nodo in top: %d", top->data);
    return top->data;
}

void printStack(Node *top){
    if(isEmpty(top)){
        printf("Stack vuoto!\n");
        return;
    }

    Node *corrente = top;
    printf("\n--- STACK ---\n");
    while(corrente != NULL){
        printf("  [  %d  ]\n", corrente->data);
        corrente = corrente->next;
    }
    printf("--- NULL ---\n");
}

int main(){
    Node *top = NULL;

    for(int i = 0; i < 8; i++) push(&top, i+1);
    printStack(top);

    for(int i = 0; i < 3; i++) pop(&top);
    printStack(top);
}