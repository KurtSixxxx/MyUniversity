#include "../common/single_ref_node.h" 
#include "stack.h"
#include "../common/data.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void push(struct nodo **top, struct dato *d){
    struct nodo *nuovo_nodo = malloc(sizeof(struct nodo));
    nuovo_nodo->next = NULL; 
    memcpy(&(nuovo_nodo->d), d, sizeof(struct dato)); 
    if(!isEmpty(*top))
	nuovo_nodo->next = *top;
    
    *top = nuovo_nodo;
}

int pop(struct nodo **top, struct dato *d){
    if(!isEmpty(*top)){
      struct nodo *n = *top;
      (*top)=(*top)->next;
      copyData(&n->d, d);  
			//memcpy(d, &(n->d), sizeof(struct dato)); // TODO funzione copiaDato() 
			freeData(&n->d); 
			free(n);
			return 1;
    }

    else
			return STACK_EMPTY; 
}

int isEmpty(struct nodo *top){
    return (top==NULL); 
}

void printStack(struct nodo *top){
    if(isEmpty(top)){
	printf("\n ** STACK is EMPTY ** \n"); 
	return; 
    }

    struct nodo *current = top; 
    printf("\n **STACK ** \n");
    while(current!=NULL){
	printDato(&(current->d));
	if(current->next!=NULL)
	    printf("\n  | \n");
	current=current->next;  
    }

    printf("\n"); 
}
