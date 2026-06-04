#include "queue.h"
#include "../../common/single_ref_node.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int isEmpty(struct queue *q){
    return (q->head == NULL);
}

void printQueue(struct queue *q){
    if(isEmpty(q)){
			printf(" ** EMPTY QUEUE ** ");
			return;
    }
    struct nodo *current =  q->head;

    printf("\n ** QUEUE ** \n ");
    printf(" (head) "); 
    while(current!=NULL){
			printDato(&(current->d));
			current=current->next;
    }
       
    printf(" (tail) "); 
}

int dequeue(struct queue *q, struct dato *d){
    if(isEmpty(q))
      return QUEUE_EMPTY;

    // copia il dato nell'area di memoria predisposta dallo user code
    //memcpy(d, &((q->head)->d), sizeof(struct dato));
    copyData(&(q->head->d), d);   

    struct nodo *tmp = q->head; 
    (q->head) = tmp->next; 

		freeData(&tmp->d); 
    free(tmp); // libera lo spazio occupato dal nodo    

    return 1; 
}

void enqueue(struct queue *q, struct dato *d){

    struct nodo *new_node = (struct nodo *) malloc(sizeof(struct nodo));
    memcpy(&(new_node->d), d, sizeof(struct dato));

    new_node->next = NULL;

    if(isEmpty(q))
			q->head = q->tail = new_node;
    
    else{
			(q->tail)->next = new_node;
			q->tail = new_node; 
    }
}
