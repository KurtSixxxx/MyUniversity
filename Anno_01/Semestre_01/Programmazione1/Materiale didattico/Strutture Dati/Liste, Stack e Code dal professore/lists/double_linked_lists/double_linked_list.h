#ifndef DOUBLE_LIST_H
    #define DOUBLE_LIST_H    

    #include "../../common/double_ref_node.h" 


    /* Vedi commenti all'interno del file header 
    * single_linked_list.h. La semantica delle funzioni	  
    * e' identica, tranne per il fatto che ogni nodo 
    * dispone di due puntatori next e prev.  
    */     
    int isEmptyDls(const struct double_ref_nodo *head);
    void printListDls(const struct double_ref_nodo *head);
    
    void insertNodoDls(struct dato* ptrDato, struct double_ref_nodo **head);
    void deleteNodoDls(struct dato* ptrDato, struct double_ref_nodo **head); 

#endif
