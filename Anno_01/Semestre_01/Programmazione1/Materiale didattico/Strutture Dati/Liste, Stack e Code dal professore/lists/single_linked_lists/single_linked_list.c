#include "single_linked_list.h"
#include "../../common/single_ref_node.h"

#include <stdlib.h> 
#include <stddef.h>
#include <string.h>
#include <stdio.h>


// implementazione delle funzioni 
// prototipate al'interno del file list.h

int isEmpty(const struct nodo *head){
    return head == NULL; 
}

void printList(const struct nodo *head){
    const struct nodo *ptr = head; 

    printf("\n ** LIST **"); 
    while(ptr!=NULL){
			printDato(&(ptr->d)); 
			ptr=ptr->next; 
    }

    printf(" **END LIST** \n"); 
}

void insertNodo(struct dato* ptrDato, struct nodo **head){
    struct nodo *nuovo_nodo = (struct nodo *) malloc(sizeof(struct nodo)); // nuovo nodo 
    nuovo_nodo->next = NULL;
    copyData(&nuovo_nodo->d, ptrDato); // copia i dati nel nodo 

    if(isEmpty(*head)){
			*head = nuovo_nodo;
			return;
    }

    struct nodo *current = *head, *previous=NULL;  // per la ricerca
    while(current!=NULL && confronta_dati(&(current->d), &(nuovo_nodo->d))<0){
			previous = current; 
			current=current->next;
    }

    if(previous!=NULL)
			previous->next = nuovo_nodo; 
    else
			*head = nuovo_nodo; // inserimento in testa 
	
    // se current == NULL, l'elemento sara' aggiunto in coda alla lista  
    if(current!=NULL)
			nuovo_nodo->next = current; 
	
}

void deleteNodo(struct dato* ptrDato, struct nodo **head){
    if(isEmpty(*head))
			return; 

    struct nodo *current = *head, *previous = NULL;
    while(current!=NULL && confronta_dati( &(current->d), ptrDato)!=0){
			previous = current; // mantiene il riferimento al nodo appena visitato
			current=current->next; // aggiorna il riferimento al prossimo nodo da visitare
    }

    if(current!=NULL){ //elemento esiste nella lista 
			if(previous) // e non e' la testa della lista
	    	previous->next = current->next; // aggiorna il link..
		else
	    *head = current->next; // aggiorna il puntatore al primo elemento 
			freeData(&current->d); 
			free(current);
    }   
}
