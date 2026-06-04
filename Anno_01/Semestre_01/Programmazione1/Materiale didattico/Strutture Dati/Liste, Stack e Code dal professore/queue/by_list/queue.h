#ifndef QUEUE_H
    #define QUEUE_H

    #include "../../common/single_ref_node.h"
    #include "../../common/data.h"

    #define QUEUE_EMPTY	-1
    
    struct queue{
	struct nodo *tail;
	struct nodo *head;
    }; 

    /* Inserisce un nuovo nodo in coda. 
    * Copia, nel nuovo nodo, il dato puntato dal 
    * parametro d 
    */     
    void enqueue(struct queue *q, struct dato *d);

    /* Rimuove il nodo presente in testa. 
    * Copia il dato presente nel nodo rimosso 
    * nell'area di memoria puntata dal parametro d
    * Restituisce QUEUE_EMPTY se la coda e' vuota
    */  
    int dequeue(struct queue *q, struct dato *d);

    /* visita l'intera coda, dalla testa fino alla fine, 
    * stampa tutti gli elementi della coda stessa
    */ 
    void printQueue(struct queue *q);

    /* per convenzione la coda e' vuota dei puntatori	
    * head e tail sono NULL
    * restituisce il valore zero se la coda non e' vuota
    * restituisce un valore diverso da zero in caso contrario
    */ 
    int isEmpty(struct queue *q); 

#endif     
