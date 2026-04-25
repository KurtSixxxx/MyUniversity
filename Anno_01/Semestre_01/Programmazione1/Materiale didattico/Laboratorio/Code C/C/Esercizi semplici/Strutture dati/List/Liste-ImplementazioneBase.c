#include <stdio.h>
#include <stdlib.h>

//Creazione struttura nodo
struct node{
        int data;
        struct node* next;
    };

//Creazione funzione stampa
void printLinkedlist (struct node *p){
    while(p != NULL){

        if(p->next != NULL)
        printf("|%d| -> ", p->data);
        else
        printf("|%d|", p->data);

        p = p->next;
    }
}

int main(){
    //Dichiarazione nodi
    struct node* testa;
    struct node* nodo1 = NULL;
    struct node* nodo2 = NULL;
    struct node* nodo3 = NULL;

//Allocaziond dinamica
nodo1 = malloc(sizeof(struct node));
nodo2 = malloc(sizeof(struct node));
nodo3 = malloc(sizeof(struct node));

//Attribuire valori ai nodi
nodo1->data = 10;
nodo2->data = 20;
nodo3->data = 30;

//Indicare i 'next'
nodo1->next = nodo2;
nodo2->next = nodo3;
nodo3->next = NULL;

//Indicare la testa
testa = nodo1;

//Chiamare la funzione di stampa
printLinkedlist(testa);

//Liberare la memoria dinamica
free(nodo1);
free(nodo2);
free(nodo3);

return 0;

}