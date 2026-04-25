#include "double_linked_list.h"
#include "../../common/double_ref_node.h"
#include "../../common/data.h"

#include <stdlib.h> 
#include <stddef.h>
#include <string.h>
#include <stdio.h>


// implementazione delle funzioni 
// prototipate al'interno del file double_linked_lists.h

int isEmptyDls(const struct double_ref_nodo *head){
    return head == NULL; 
}

void printListDls(const struct double_ref_nodo *head){
    const struct double_ref_nodo *ptr = head; 

    printf("\n ** LIST **"); 
    while(ptr!=NULL){
			printDato(&(ptr->d)); 
			ptr=ptr->next; 
    }

    printf(" **END LIST** \n"); 
}

void insertNodoDls(struct dato* ptrDato, struct double_ref_nodo **head){
    struct double_ref_nodo *nuovo_nodo = (struct double_ref_nodo *) malloc(sizeof(struct double_ref_nodo)); // nuovo double_ref_nodo 

    nuovo_nodo->next = NULL; 
    (nuovo_nodo)->prev = NULL; 

    copyData(&nuovo_nodo->d, ptrDato); // nuova funzione  

//    memcpy((void *) &(nuovo_nodo->d), (void *) ptrDato, sizeof(struct dato)); // copia i dati nel double_ref_nodo 

    if(isEmptyDls(*head)){
	*head = nuovo_nodo;
	return; 
    }

    // il riferimento previous va mantenuto nel caso di inserisca in coda
    struct double_ref_nodo *current = *head, *previous=NULL;

    while(current!=NULL && confronta_dati(&(current->d), &(nuovo_nodo->d))<0){
			previous = current; 	
			current=current->next;
    }

    if(current!=NULL){ // inserimento in testa o tra due elementi 
			if(previous==NULL) //inserimento in testa
	    	*head = nuovo_nodo;
			

			// colegamenti nuovo_nodo <--> previous
			else { // previous != NULL
	  		previous->next = nuovo_nodo;
	   		nuovo_nodo->prev = previous;
			}

			// collegamenti nuovo_nodo <--> current
			current->prev = nuovo_nodo; 
	    nuovo_nodo->next = current;
   	}

    else{ // inserimento in coda	
			previous->next = nuovo_nodo; 
			nuovo_nodo->prev = previous; 	
    }	
}

void deleteNodoDls(struct dato* ptrDato, struct double_ref_nodo **head){
    if(isEmptyDls(*head))
	return; 

    struct double_ref_nodo *current = *head, *previous = NULL;

    while(current!=NULL && confronta_dati( &(current->d), ptrDato)!=0){
			previous = current; // mantiene il riferimento al double_ref_nodo appena visitato
			current=current->next; // aggiorna il riferimento al prossimo double_ref_nodo da visitare
    }

    if(current!=NULL){ //elemento esiste nella lista 
			if(previous){ // e non e' la testa della lista
	    	previous->next = current->next; // aggiorna il link..
	    if(current->next!=NULL)
				(current->next)->prev = previous; // double link! 
			}
			else{
	    	*head = current->next; // aggiorna il puntatore al primo elemento 
	    	(*head)->prev = NULL; // double link! 
			}
			freeData(&current->d); 
			free(current);
    }
	}
