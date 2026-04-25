#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct elem{
    int dato;
    struct elem *next;
}Nodo;

void stampa(Nodo* puntatore){
    while(puntatore!=NULL){
        printf("\n%d", puntatore->dato);
        puntatore=puntatore->next;
    }
}

int main(){

    Nodo* head;
    Nodo* newelement;
    Nodo* prev;

    bool primonodo=true;

    for(int i=0; i<10;i++){
        newelement=malloc(sizeof(Nodo));
        newelement->dato=i;
        newelement->next=NULL;
        if(primonodo==true){
            newelement->next=NULL;
            head=newelement;
            prev=head;
            primonodo=false;
        }else{
            prev->next=newelement;
            prev=newelement;
        }
    }
    stampa(head);
    return 0;
}
