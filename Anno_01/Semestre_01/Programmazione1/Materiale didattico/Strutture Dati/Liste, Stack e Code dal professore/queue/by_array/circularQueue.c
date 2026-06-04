#include "circularQueue.h"
#include <stdlib.h>
#include <stdio.h>

void printQueue(struct circularQueue *q){
    if(isEmpty(q)){
			printf("\n ** QUEUE EMPTY **\n"); 
			return;
    }

    printf("\n (head) "); 
    int *ptr = q->data;
    unsigned int index = q->head; 
    while(index!=q->tail){
			printf(" %d ", ptr[index]);
			index =(index+1)%(q->size);
    }

    printf(" (tail) \n");

}

int isEmpty(struct circularQueue *q){
    return q->head == q->tail;    
}

int isFull(struct circularQueue *q){
    return q->head==(q->tail+1)%(q->size);
}

int initQueue(struct circularQueue *q, int n){
    q->head = q->tail = 0;
    q->data = (int *) malloc(sizeof(int)*n);
    if(!(q->data)){
			fprintf(stderr, "\n initQueue(): memory error!");
			return -1;
    }
    q->size = n;
    return 0;
}

int enqueue(struct circularQueue *q, int dato){
    if(isFull(q)){
			fprintf(stderr, "\n Queue is full! "); 
			return -1;
    }

    //tail punta al primo elemento libero dell'array 
    // per l'inserimento in coda
    q->data[q->tail] = dato;
    // gestione circolare dello array ..
    q->tail=(q->tail+1)%(q->size);
    return 1; 
}

/* 
* 
*/ 
int dequeue(struct circularQueue *q, int *dato){
    if(isEmpty(q)){
			fprintf(stderr, "\n Queue is empty! "); 
			return -1;
    }

    // head punta all'elemento in testa 
    *dato = q->data[q->head];
    // gestione circolare dell'array    
    q->head = (q->head+1)%(q->size);
    return 1; 
}
