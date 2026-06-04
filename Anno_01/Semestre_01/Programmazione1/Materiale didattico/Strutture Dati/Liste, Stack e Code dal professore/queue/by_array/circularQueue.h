#ifndef CIRCULAR_QUEUE_H
    #define CIRCULAR_QUEUE_H

struct circularQueue{
    unsigned int head, tail; 
    int *data; 
    unsigned size;     
};

#define ENQUEUE_OK 1
#define ENQUEUE_FAIL -1

#define DEQUEUE_OK 1
#define DEQUEUE_FAIL -1


/*  NB il dato in questo header e' definito int. Eventualmente si definisce un 
*   alias (typedef) con il tipo voluto.   
*/ 


int isEmpty(struct circularQueue *q); 
int isFull(struct circularQueue *q);

/* Inizializzare gli indici tail ed head della coda */ 
int initQueue(struct circularQueue *q, int n);

/* Inserisce un dato in coda 
restituisce un numero che indica l'esito 
dell'operazione
*/ 
int enqueue(struct circularQueue *q, int dato);

/* Preleva un dato dala testa della coda, 
restituisce un numero che indica l'esito 
dell'operazione */ 
int dequeue(struct circularQueue *q, int *dato);

/* Stampa la coda */ 
void printQueue(struct circularQueue *q);  

#endif
