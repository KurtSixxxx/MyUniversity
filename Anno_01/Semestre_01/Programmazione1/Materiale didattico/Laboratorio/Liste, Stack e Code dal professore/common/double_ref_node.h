#ifndef DOUBLE_REF_NODE_H
    #define DOUBLE_REF_NODE_H
    #include "data.h"//contiene la definiz. del dato
    struct double_ref_nodo{
	struct dato d;
	struct double_ref_nodo * next; 
	struct double_ref_nodo * prev; 
    }; 
#endif 
