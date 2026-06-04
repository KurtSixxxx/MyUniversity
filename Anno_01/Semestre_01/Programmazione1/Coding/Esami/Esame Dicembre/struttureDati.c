/**************************************************************
 *  RIPASSO STRUTTURE DATI IN C
 *  Liste singole, Pila (Stack), Coda (Queue), Liste doppie
 *  Ogni riga è commentata in modo chiaro.
 **************************************************************/

#include <stdio.h>    // Include standard per printf, ecc.
#include <stdlib.h>   // Include standard per malloc, free, NULL

/**************************************************************
 *                  LISTE SINGOLARMENTE CONCATENATE
 **************************************************************/

/*
Struttura del NODO di lista:

+-----------+-----------+
|   data    |   next    |
|   (int)   |  (Node*)  |
+-----------+-----------+

Esempio concreto di nodo:

+-----------+-----------+
|    10     |   NULL    |
+-----------+-----------+
*/

// Definizione del tipo di nodo per lista (e coda)
typedef struct node{          // Definisco una struct chiamata 'node'
    int data;                 // Campo che contiene il valore intero
    struct node *next;        // Puntatore al prossimo nodo della lista (Node*)
} Node;                       // Creo un alias 'Node' per 'struct node'

/*
Struttura della LISTA:

 head                                   tail
  ↓                                       ↓
+------+------+    +------+------+    +------+------+
| 10   |  o----->  | 20   |  o----->  | 30   | NULL |
+------+------+    +------+------+    +------+------+

La lista contiene solo DUE puntatori: head e tail.
*/

// Definizione della struct List
typedef struct{               // Struct anonima con typedef
    Node *head;               // Puntatore al primo nodo (testa)
    Node *tail;               // Puntatore all’ultimo nodo (coda)
} List;                       // Alias 'List' per questa struct

/**************************************************************
 *  void initList(List *l)
 *  Inizializza una lista: head e tail = NULL
 *  Perché List *l? Perché dobbiamo modificare la lista vera.
 **************************************************************/
void initList(List *l){       // l è un PUNTATORE alla lista reale
    l->head = NULL;           // Imposto la testa a NULL (lista vuota)
    l->tail = NULL;           // Imposto la coda a NULL (lista vuota)
    // Dopo questa funzione, la lista esiste ma non ha nodi.
}

/**************************************************************
 *  int isEmpty(List *l)
 *  Ritorna 1 se la lista è vuota, 0 altrimenti.
 **************************************************************/
int isEmpty(List *l){         // Riceve un puntatore alla lista
    return l->head == NULL;   // Se head è NULL → lista vuota → ritorna 1, altrimenti 0
}

/**************************************************************
 *  void insertHead(List *l, int value)
 *  Inserisce un nuovo nodo all'inizio della lista (testa).
 **************************************************************/
void insertHead(List *l, int value){   // l è la lista da modificare, value è il dato da inserire
    Node *newNode = malloc(sizeof(Node)); // Alloco in heap memoria per un nuovo nodo

    if(newNode == NULL){               // Controllo se malloc è fallita
        printf("Allocazione nodo fallita.\n"); // Messaggio di errore
        return;                        // Esco dalla funzione senza modificare la lista
    }

    newNode->data = value;             // Assegno 'value' al campo data del nuovo nodo
    newNode->next = l->head;           // Il nuovo nodo punta all’attuale head (anche se è NULL)
                                       // ASCII prima:
                                       // head → [10] → [20]
                                       // dopo insertHead(5):
                                       // head → [5] → [10] → [20]

    l->head = newNode;                 // Adesso la testa diventa il nuovo nodo

    if(l->tail == NULL){               // Se tail era NULL, significa che la lista era vuota
        l->tail = newNode;             // Quindi il nuovo nodo è sia head che tail
    }
}

/**************************************************************
 *  void insertTail(List *l, int value)
 *  Inserisce un nuovo nodo alla fine della lista (coda).
 **************************************************************/
void insertTail(List *l, int value){   // l è la lista da modificare, value è il dato da inserire
    Node *newNode = malloc(sizeof(Node)); // Alloco un nuovo nodo
    if(newNode == NULL){               // Controllo malloc
        printf("Allocazione nodo fallita.\n"); // Errore se malloc fallisce
        return;                        // Esco
    }

    newNode->data = value;             // Assegno il valore al nuovo nodo
    newNode->next = NULL;              // Essendo in coda, dopo di lui non c’è nessun nodo

    if(isEmpty(l)){                    // Se la lista è vuota (head == NULL)
        l->head = newNode;             // Sia head
        l->tail = newNode;             // sia tail puntano allo stesso nodo
        return;                        // Ho finito
    }

    // Caso lista NON vuota:
    l->tail->next = newNode;           // Il vecchio tail punta al nuovo nodo
    l->tail = newNode;                 // tail ora diventa il nuovo nodo
}

/**************************************************************
 *  void removeHead(List *l)
 *  Rimuove il nodo in testa alla lista.
 **************************************************************/
void removeHead(List *l){              // l è la lista da modificare
    if(isEmpty(l)) return;             // Se la lista è vuota non c’è niente da togliere

    Node *tmp = l->head;               // Salvo un puntatore alla vecchia head per poter fare free
                                       // ASCII prima:
                                       // head → [10] → [20] → [30]
                                       // dopo:
                                       // head → [20] → [30]

    l->head = l->head->next;           // Sposto head al nodo successivo

    if(l->head == NULL){               // Se dopo lo spostamento head è NULL
        l->tail = NULL;                // allora anche tail deve diventare NULL (lista vuota)
    }

    free(tmp);                         // Libero la memoria del nodo rimosso
}

/**************************************************************
 *  void removeTail(List *l)
 *  Rimuove il nodo in coda alla lista.
 **************************************************************/
void removeTail(List *l){              // l è la lista da modificare
    if(isEmpty(l)) return;             // Se lista vuota, non faccio niente

    if(l->head == l->tail){            // Caso: un solo nodo (head e tail puntano allo stesso nodo)
        free(l->head);                 // Libero l’unico nodo
        l->head = NULL;                // Lista vuota → head = NULL
        l->tail = NULL;                // Lista vuota → tail = NULL
        return;                        // Fine
    }

    Node *curr = l->head;              // Parto dalla testa per cercare il penultimo nodo

    while(curr->next != l->tail){      // Scorro finché il next non è l’attuale tail
        curr = curr->next;             // Avanzo di un nodo
    }

    free(l->tail);                     // Libero il nodo che era in coda
    l->tail = curr;                    // La nuova coda diventa il penultimo nodo
    curr->next = NULL;                 // Il nuovo tail non deve puntare a nulla
}

/**************************************************************
 *  int searchValue(List *l, int value)
 *  Cerca 'value' nella lista. Ritorna 1 se trovato, 0 se no.
 **************************************************************/
int searchValue(List *l, int value){   // l è la lista da cercare, value è il valore da trovare
    Node *curr = l->head;              // Parto dalla testa

    while(curr != NULL){               // Finché non arrivo alla fine (NULL)
        if(curr->data == value)        // Se il dato del nodo corrente è uguale al valore cercato
            return 1;                  // Ritorno 1 (trovato)
        curr = curr->next;             // Passo al nodo successivo
    }

    return 0;                          // Se esco dal while, non ho trovato niente → ritorno 0
}

/**************************************************************
 *  void printList(List *l)
 *  Stampa tutti gli elementi della lista.
 **************************************************************/
void printList(List *l){               // l è la lista da stampare
    Node *curr = l->head;              // Parto dalla testa

    printf("Lista: ");                 // Prefisso di stampa
    while(curr != NULL){               // Scorro tutti i nodi finché arrivo a NULL
        printf("[%d]", curr->data);    // Stampo il valore del nodo corrente
        if(curr->next != NULL)         // Se NON sono all’ultimo nodo
            printf(" -> ");            // stampo una freccia per indicare il collegamento
        curr = curr->next;             // Passo al nodo successivo
    }
    printf("\n");                      // Alla fine vado a capo
}

/**************************************************************
 *                          PILA (STACK)
 **************************************************************/

/*
Idea: LIFO (Last In First Out)

 top
  ↓
+-----+
|  30 |
+-----+
  |
+-----+
|  20 |
+-----+
  |
+-----+
|  10 |
+-----+
  |
 NULL

push: inserisce SEMPRE in cima (top)
pop:  toglie SEMPRE dalla cima (top)
*/

// Struttura del nodo per la pila (stack)
typedef struct nodo{           // Definisco una struct per la pila
    int data;                  // Valore intero del nodo
    struct nodo *next;         // Puntatore al nodo successivo
} Nodo;                        // Alias 'Nodo' per struct nodo

/**************************************************************
 *  int isEmpty(Nodo *top)
 *  Controlla se lo stack è vuoto (top == NULL).
 **************************************************************/
int isEmpty(Nodo *top){        // top è il puntatore alla cima dello stack
    return top == NULL;        // Se top è NULL → stack vuoto → 1, altrimenti 0
}

/*
Perché nelle funzioni push e pop usiamo Nodo **top?

- Nel main abbiamo qualcosa tipo: Nodo *top = NULL;
- Se passassimo solo Nodo *top, dentro push/pop lavoreremmo su una COPIA.
- Non potremmo cambiare davvero chi è il nuovo top.

Con Nodo **top:
- passiamo l’INDIRIZZO della variabile top (&top)
- dentro la funzione, *top è il vero puntatore usato nel main
- assegnando *top = nuovoNodo; cambiamo davvero la cima dello stack.
*/

/**************************************************************
 *  void push(Nodo **top, int value)
 *  Inserisce un nuovo elemento in cima allo stack.
 **************************************************************/
void push(Nodo **top, int value){      // top è un puntatore al puntatore alla cima
    Nodo *nuovo = malloc(sizeof(Nodo)); // Alloco un nuovo nodo in heap
    if(nuovo == NULL){                 // Controllo malloc
        printf("Allocazione fallita\n"); // Messaggio di errore
        return;                        // Esco dalla funzione
    }

    nuovo->data = value;               // Assegno il valore al campo data del nuovo nodo

    // Collegamento del nuovo nodo allo stack esistente:
    nuovo->next = *top;                // Il nuovo nodo punta al vecchio top (può essere NULL)

    *top = nuovo;                      // Aggiorno il top: ora la cima è il nuovo nodo
}

/**************************************************************
 *  int pop(Nodo **top)
 *  Toglie l’elemento dalla cima e ritorna il suo valore.
 **************************************************************/
int pop(Nodo **top){                   // top è l’indirizzo della variabile top del main
    if(isEmpty(*top)){                 // Se *top è NULL → stack vuoto
        printf("Stack vuoto!\n");      // Messaggio di errore
        return -1;                     // Valore di errore
    }

    Nodo *tmp = *top;                  // tmp punta al nodo attuale in cima
    int valore = tmp->data;            // Salvo il valore da ritornare

    *top = tmp->next;                  // Sposto il top al nodo sottostante

    free(tmp);                         // Libero il nodo che era in cima
    return valore;                     // Ritorno il valore che ho tolto
}

/**************************************************************
 *  int peek(Nodo *top)
 *  Ritorna il valore in cima allo stack senza rimuoverlo.
 **************************************************************/
int peek(Nodo *top){                   // Passo solo una COPIA del puntatore top
    if(isEmpty(top)){                  // Se top è NULL → stack vuoto
        printf("Stack vuoto!\n");      // Messaggio di avviso
        return -1;                     // Valore di errore
    }
    return top->data;                  // Ritorno il valore del nodo in cima
}

/**************************************************************
 *  void printStack(Nodo *top)
 *  Stampa lo stack dall’alto verso il basso.
 **************************************************************/
void printStack(Nodo *top){            // top è la cima della pila (solo lettura)
    if(isEmpty(top)){                  // Se è vuoto
        printf("Stack vuoto!\n");      // Messaggio
        return;                        // Esco
    }

    Nodo *corrente = top;             // Puntatore che scorre dallo stack
    printf("\n--- STACK (top in alto) ---\n"); // Intestazione

    while(corrente != NULL){          // Finché ci sono nodi
        printf("   +-------+\n");     // Bordo superiore del "blocco"
        printf("   |  %3d  |\n", corrente->data); // Stampo il valore centrato
        printf("   +-------+\n");     // Bordo inferiore
        if(corrente->next != NULL)    // Se c’è un nodo sotto
            printf("       |\n");     // Stampo la "linea" verso il basso
        corrente = corrente->next;    // Passo al nodo successivo
    }

    printf("      NULL\n\n");        // Fine della pila
}

/**************************************************************
 *                              CODA (QUEUE)
 **************************************************************/

/*
Concetto di coda (FIFO: First In, First Out):

front → [10] → [20] → [30] → NULL
                                ↑
                               rear

- enqueue: inserisce in fondo (rear)
- dequeue: toglie dal fronte (front)
*/

// Struttura della coda: usa i Node definiti prima
typedef struct{
    Node *front;             // Puntatore al primo elemento (esce per primo)
    Node *rear;              // Puntatore all’ultimo elemento (entra per ultimo)
} Queue;                     // Alias 'Queue'

/**************************************************************
 *  void initQueue(Queue *q)
 *  Inizializza la coda: front e rear = NULL
 **************************************************************/
void initQueue(Queue *q){    // q è un puntatore alla coda da inizializzare
    q->front = NULL;         // Nessun elemento in testa
    q->rear = NULL;          // Nessun elemento in coda
}

/**************************************************************
 *  int isEmtpy(Queue *q)
 *  (nome volutamente scritto così)
 *  Ritorna 1 se la coda è vuota, 0 altrimenti.
 **************************************************************/
int isEmtpy(Queue *q){       // q è un puntatore alla coda
    return q->front == NULL; // Se front è NULL → coda vuota
}

/**************************************************************
 *  void enqueue(Queue *q, int value)
 *  Inserisce un nuovo elemento in fondo alla coda (rear).
 **************************************************************/
void enqueue(Queue *q, int value){   // q è la coda da modificare, value è il dato inserito
    Node *nuovo = malloc(sizeof(Node)); // Alloco un nuovo nodo
    if(nuovo == NULL){                // Controllo l'allocazione
        printf("Allocazione nodo fallita.\n"); // Messaggio di errore
        return;                       // Esco
    }

    nuovo->data = value;              // Assegno il valore al nodo
    nuovo->next = NULL;               // In coda → dopo non c’è nessun nodo

    if(isEmtpy(q)){                   // Se la coda è vuota
        q->front = nuovo;             // front punta al nuovo nodo
        q->rear  = nuovo;             // rear punta allo stesso nodo
    }else{
        q->rear->next = nuovo;        // Il vecchio rear punta al nuovo nodo
        q->rear = nuovo;              // Aggiorno rear al nuovo nodo
    }
}

/**************************************************************
 *  int dequeue(Queue *q)
 *  Rimuove l'elemento in testa (front) e ne ritorna il valore.
 **************************************************************/
int dequeue(Queue *q){                // q è la coda da cui togliere
    if(isEmtpy(q)){                   // Se la coda è vuota
        printf("Coda vuota: impossibile rimuovere elementi\n"); // Messaggio
        return -1;                    // Valore di errore
    }

    Node *tmp = q->front;             // tmp punta al nodo in testa (da eliminare)
    int valore = tmp->data;           // Salvo il valore da ritornare

    q->front = q->front->next;        // Sposto front al nodo successivo

    if(q->front == NULL){             // Se front è diventato NULL
        q->rear = NULL;               // allora anche rear deve essere NULL (coda vuota)
    }

    free(tmp);                        // Libero il nodo eliminato
    return valore;                    // Ritorno il valore rimosso
}

/**************************************************************
 *  void printQueue(Queue *q)
 *  Stampa tutti gli elementi della coda dal front al rear.
 **************************************************************/
void printQueue(Queue *q){            // q è la coda da stampare
    Node *curr = q->front;            // Parto dal front

    printf("Queue: FRONT → ");        // Prefisso di stampa
    while(curr != NULL){              // Scorro tutti gli elementi
        printf("[%d] → ", curr->data);// Stampo il valore del nodo corrente
        curr = curr->next;            // Passo al nodo successivo
    }
    printf("NULL (REAR)\n");          // Indico la fine della coda
}

/**************************************************************
 *                     LISTE DOPPIAMENTE CONCATENATE
 **************************************************************/

/*
Nodo doppio:

+-----------+-----------+-----------+
|   prev    |   data    |   next    |
|  (DNode*) |   (int)   |  (DNode*) |
+-----------+-----------+-----------+

Esempio:

NULL ← [10] ↔ [20] ↔ [30] → NULL
*/

// Definizione del nodo per lista doppia
typedef struct dnode{                 // Struct per nodo doppio
    int data;                         // Valore intero del nodo
    struct dnode *prev;               // Puntatore al nodo precedente
    struct dnode *next;               // Puntatore al nodo successivo
} DNode;                              // Alias 'DNode'

// Definizione della lista doppia
typedef struct{                       // Struct con head e tail
    DNode *head;                      // Puntatore al primo nodo
    DNode *tail;                      // Puntatore all’ultimo nodo
} DList;                              // Alias 'DList'

/**************************************************************
 *  void initDList(DList *l)
 *  Inizializza la lista doppia: head e tail = NULL.
 **************************************************************/
void initDList(DList *l){             // l è la lista doppia da inizializzare
    l->head = NULL;                   // Nessun nodo in testa
    l->tail = NULL;                   // Nessun nodo in coda
}

/**************************************************************
 *  int isEmptyD(DList *l)
 *  Ritorna 1 se la lista doppia è vuota, 0 altrimenti.
 **************************************************************/
int isEmptyD(DList *l){               // l è un puntatore alla lista doppia
    return l->head == NULL;           // Se head è NULL → lista vuota
}

/**************************************************************
 *  void insertHeadD(DList *l, int value)
 *  Inserisce un nodo in testa (inizio) della lista doppia.
 **************************************************************/
void insertHeadD(DList *l, int value){  // l è la lista da modificare, value è il valore
    DNode *newNode = malloc(sizeof(DNode)); // Alloco un nuovo nodo doppio
    if(newNode == NULL){               // Controllo malloc
        printf("Allocazione DNode fallita.\n"); // Messaggio errore
        return;                        // Esco
    }

    newNode->data = value;             // Assegno il valore
    newNode->prev = NULL;              // In testa: prima non c’è nessuno
    newNode->next = l->head;           // Il suo next sarà l’attuale head (può essere NULL)

    if(l->head != NULL){               // Se la lista non è vuota
        l->head->prev = newNode;       // Il vecchio head ora ha un prev che punta al nuovo nodo
    }else{
        l->tail = newNode;             // Se era vuota, questo nodo è anche la tail
    }

    l->head = newNode;                 // Il nuovo nodo diventa la head

    // ASCII:
    // Prima: head → [10] ↔ [20]
    // Dopo insertHeadD(5): head → [5] ↔ [10] ↔ [20]
}

/**************************************************************
 *  void insertTailD(DList *l, int value)
 *  Inserisce un nodo in coda (fine) della lista doppia.
 **************************************************************/
void insertTailD(DList *l, int value){ // l è la lista doppia da modificare
    DNode *newNode = malloc(sizeof(DNode)); // Alloco nuovo nodo
    if(newNode == NULL){               // Controllo malloc
        printf("Allocazione DNode fallita.\n"); // Messaggio errore
        return;                        // Esco
    }

    newNode->data = value;             // Assegno il valore
    newNode->next = NULL;              // In coda: dopo non c’è nessuno
    newNode->prev = l->tail;           // Prima c’è la vecchia tail (se esiste)

    if(l->tail != NULL){               // Se la lista non è vuota
        l->tail->next = newNode;       // Il vecchio tail ora punta al nuovo nodo
    }else{
        l->head = newNode;             // Se era vuota, questo è anche la head
    }

    l->tail = newNode;                 // Aggiorno la tail al nuovo nodo

    // ASCII:
    // Prima: [10] ↔ [20] → NULL (tail su 20)
    // Dopo insertTailD(30): [10] ↔ [20] ↔ [30] → NULL (tail su 30)
}

/**************************************************************
 *  void removeHeadD(DList *l)
 *  Rimuove il nodo in testa dalla lista doppia.
 **************************************************************/
void removeHeadD(DList *l){            // l è la lista doppia da modificare
    if(isEmptyD(l)) return;            // Se lista vuota, esco

    DNode *tmp = l->head;              // tmp punta al nodo da eliminare (head)

    l->head = l->head->next;           // Sposto head al nodo successivo

    if(l->head != NULL){               // Se esiste una nuova head
        l->head->prev = NULL;          // Il suo prev deve essere NULL (nessuno prima)
    }else{
        l->tail = NULL;                // Se head è NULL, lista vuota → anche tail NULL
    }

    free(tmp);                         // Libero il nodo rimosso
}

/**************************************************************
 *  void removeTailD(DList *l)
 *  Rimuove il nodo in coda dalla lista doppia.
 **************************************************************/
void removeTailD(DList *l){            // l è la lista doppia
    if(isEmptyD(l)) return;            // Se vuota, niente da fare

    DNode *tmp = l->tail;              // tmp punta alla vecchia coda

    l->tail = l->tail->prev;           // Sposto tail al nodo precedente

    if(l->tail != NULL){               // Se c’è una nuova tail
        l->tail->next = NULL;          // Il suo next deve essere NULL (nessuno dopo)
    }else{
        l->head = NULL;                // Se tail è NULL → lista vuota → head NULL
    }

    free(tmp);                         // Libero il nodo rimosso
}

/**************************************************************
 *  int searchValueD(DList *l, int value)
 *  Cerca un valore nella lista doppia.
 **************************************************************/
int searchValueD(DList *l, int value){ // l è la lista doppia, value è il valore cercato
    DNode *curr = l->head;             // Parto dalla testa

    while(curr != NULL){               // Finché ci sono nodi
        if(curr->data == value)        // Se il valore nel nodo coincide
            return 1;                  // Ritorno 1 (trovato)
        curr = curr->next;             // Passo al prossimo nodo
    }

    return 0;                          // Se esco dal while, non trovato → 0
}

/**************************************************************
 *  void printDListForward(DList *l)
 *  Stampa la lista doppia da head a tail.
 **************************************************************/
void printDListForward(DList *l){      // l è la lista da stampare in avanti
    DNode *curr = l->head;             // Parto dalla testa

    printf("DList forward: HEAD → ");  // Prefisso
    while(curr != NULL){               // Scorro finché non arrivo a NULL
        printf("[%d]", curr->data);    // Stampo il valore del nodo
        if(curr->next != NULL)         // Se non è l’ultimo
            printf(" ↔ ");             // stampo il doppio collegamento
        curr = curr->next;             // Passo al nodo successivo
    }
    printf(" → NULL\n");               // Fine lista
}

/**************************************************************
 *  void printDListBackward(DList *l)
 *  Stampa la lista doppia da tail a head.
 **************************************************************/
void printDListBackward(DList *l){     // l è la lista da stampare al contrario
    DNode *curr = l->tail;             // Parto dalla coda

    printf("DList backward: TAIL → "); // Prefisso
    while(curr != NULL){               // Finché non arrivo all’inizio
        printf("[%d]", curr->data);    // Stampo il valore
        if(curr->prev != NULL)         // Se non è il primo nodo
            printf(" ↔ ");             // stampo collegamento
        curr = curr->prev;             // Mi muovo all’indietro con prev
    }
    printf(" → NULL\n");               // Fine
}

/**************************************************************
 *                          MAIN DI ESEMPIO
 *  Solo per mostrare come si usano le funzioni.
 *  Puoi ignorarlo se ti interessa solo la teoria.
 **************************************************************/
int main(){                            // Funzione principale di esempio
    printf("=== ESEMPI RAPIDI DI USO (per ripasso) ===\n\n");

    // ----------------- Lista singola -----------------
    List l;                            // Dichiarazione di una lista
    initList(&l);                      // Inizializzo la lista (head/tail = NULL)
    insertHead(&l, 20);                // Inserisco 20 in testa
    insertHead(&l, 10);                // Inserisco 10 in testa (diventa il nuovo head)
    insertTail(&l, 30);                // Inserisco 30 in coda
    printList(&l);                     // Stampo la lista

    // ----------------- Stack (pila) -----------------
    Nodo *top = NULL;                  // Inizio con la cima dello stack a NULL (vuoto)
    push(&top, 1);                     // Metto 1 nello stack
    push(&top, 2);                     // Metto 2 sopra 1
    push(&top, 3);                     // Metto 3 sopra 2
    printStack(top);                   // Stampo lo stack
    pop(&top);                         // Tolgo l’elemento in cima (3)
    printStack(top);                   // Stampo lo stack dopo la pop

    // ----------------- Queue (coda) -----------------
    Queue q;                           // Dichiarazione della coda
    initQueue(&q);                     // Inizializzo la coda
    enqueue(&q, 100);                  // Inserisco 100
    enqueue(&q, 200);                  // Inserisco 200
    enqueue(&q, 300);                  // Inserisco 300
    printQueue(&q);                    // Stampo la coda
    dequeue(&q);                       // Rimuovo il primo (100)
    printQueue(&q);                    // Stampo dopo la dequeue

    // ------------- Lista doppiamente concatenata -------------
    DList dl;                          // Dichiarazione lista doppia
    initDList(&dl);                    // Inizializzo la lista doppia
    insertHeadD(&dl, 20);              // Inserisco 20 in testa
    insertHeadD(&dl, 10);              // Inserisco 10 in testa (diventa nuovo head)
    insertTailD(&dl, 30);              // Inserisco 30 in coda
    printDListForward(&dl);            // Stampo dalla head alla tail
    printDListBackward(&dl);           // Stampo dalla tail alla head

    return 0;                          // Fine del programma di esempio
}
