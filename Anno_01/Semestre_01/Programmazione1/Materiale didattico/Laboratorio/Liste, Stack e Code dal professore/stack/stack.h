#ifndef STACK_H
    #define STACK_H

    #include "../common/data.h"
    #include "../common/single_ref_node.h"

    #define STACK_EMPTY -1
    
    /* Copia il dato puntato da d sul top dello stack*/ 
    void push(struct nodo **top, struct dato *d); 

    /* - rimuove il dato presente nel top dello stack, e lo copia 
    * nell'area di memoria puntata dal parametro d; 
    * - restituisce un numero > 0 se e' presente almeno un dato, 
    * il quale viene copiato nell'area di memoria puntata da d;	
    * altrimenti restituisce STACK_EMPTY
    */ 
    int pop(struct nodo **top, struct dato *d);

    /* per convenzione, lo stack e' vuoto se il puntatore 
    * top e' NULLA
    */ 
    int isEmpty(struct nodo *top); 

    /* Stampa tutti i dati presenti nello stack, 
    * a partire dalla cima 
    */ 
    void printStack(struct nodo *top); 

#endif 



