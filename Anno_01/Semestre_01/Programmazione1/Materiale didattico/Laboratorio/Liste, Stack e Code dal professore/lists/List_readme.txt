Una lista e' una struttura dati costituita da una sequenza di 
elementi dello stesso tipo.

A differenza dell'array, lo spazio per gli elementi viene allocato dinamicamente 
quando vi e' necessita' di aggiungere l'elemento stesso, ed analogamente, 
tale spazio viene liberato quando viene cancellato un elemento. 

Gli spazi in memoria degli elementi non sono contigui, per questo motivo 
vi e' la necessita' di collegare un elemento al successivo mediante puntatori. 

Nelle liste semplici o ``semplicemente concatenate'' ogni nodo 
contiene il link al successivo. 
Se ogni singolo nodo contiene anche il link al precedente, 
allora si parla di liste doppiamente concatenate.

** Liste con collegamenti singoli ** 

Partendo dalle definizioni contenute in data.h, data.c (contenute nella
directory common) e single_ref_node.h,
si definiscano le segg. funzioni prototipate nel file single_linked_list.h per
le gestione di una lista con collegamenti singoli (commenti nel file header):

-  int isEmpty(const struct nodo *head);
-  void printList(const struct nodo *head);
-  insertNodo(struct dato* ptrDato, struct nodo **head);
-  void deleteNodo(struct dato* ptrDato, struct nodo **head);

** Liste con collegamenti doppi **

Partendo dalle definizioni contenute in data.h, data.c (contenuti 
nella directory common) e double_ref_node.h, 
si definiscano le segg. funzioni prototipate nel file double_linked_list.h per 
le gestione di una lista con collegamenti doppi (commenti nel file header):

int isEmptyDls(const struct double_ref_nodo *head);
void printListDls(const struct double_ref_nodo *head);
void insertNodoDls(struct dato* ptrDato, struct double_ref_nodo **head);
void deleteNodoDls(struct dato* ptrDato, struct double_ref_nodo **head);
