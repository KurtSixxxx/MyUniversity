#ifndef SINGLE_LIST_H
    #define SINGLE_LIST_H
    #include "../../common/single_ref_node.h" 

    /* generalmente, la lista e' vuota 
    * se il puntatore alla testa e' NULL
    */     
    int isEmpty(const struct nodo *head);

    /* Visita l'intera lista per stampare tutti i dati della 
    * lista */ 
    void printList(const struct nodo *head);

    /* NB: la lista va mantenuta in modo ordinato
    * (ordinamento crescente o decrescente); 
    * quindi visitare la lista per identificare il punto di 
    * inserimento del nuovo nodo, copiare il dato 
    * puntato da ptrDato nel dato contenuto nel nuovo nodo
    * ed infine mantenere l'integrita' della struttura dati 
    * modificando opportuni puntatori. 
    * Porre attenzione ai differenti casi: 
    * - inserimento in testa 
    * - inserimento in coda
    * - inserimento tra due elementi 
    */     
    void insertNodo(struct dato* ptrDato, struct nodo **head);
    /* 
    * La semantica e' simile a quella della funzione insertNodo: 
    * - identificare il nodo da rimuovere, sulla base del dato 
    * puntato da ptrNodo 
    * - eliminare il nodo pur mantenendo l'integrita' delle struttura 
    * dati
    */ 
    void deleteNodo(struct dato* ptrDato, struct nodo **head);   

#endif 
