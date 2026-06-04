Una pila (STACK) e' una struttura dati basata sul modello FIFO 
(First In, First Out).

Le operazioni definite sulla struttura stack sono sostanzialmente due: 

- push(..) Copia un dato sul top dello stack. 
- pop(..) preleva il dato dal top dello stack. 

Partendo dalle definizioni contenute in data.h, data.c e single_ref_node.h, 
si definiscano le segg. funzioni prototipate nel file stack.h: 
 
-  void push(struct nodo **top, struct dato *d);
-  int pop(struct nodo **top, struct dato *d);
-  int isEmpty(struct nodo *top);
-  printStack(struct nodo *top);

