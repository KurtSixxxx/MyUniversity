//Liste in C

/*
Le liste sono delle strutture dati fatti da nodi, collegati tramite puntatori.
I nodi sono formati da 2 parti: un dato e un puntatore detto next.
Il puntatore detto 'next' serve per collegare i nodi tra di loro, in modo da poter manipolare la lista ed il suo ordinamento.
Inoltre abbiamo bisogno di una struct List, che ha come puntatori head e tail, rispettivamente testa e coda della nostra lista.

 head                                   tail
  ↓                                       ↓
+------+------+    +------+------+    +------+------+
| 10   |  o----->  | 20   |  o----->  | 30   | NULL |
+------+------+    +------+------+    +------+------+

Vediamo come si implementa.
*/

//Struttura del nodo
typedef struct node{
	int data;
	struct node *next;
} Node;

/*
+-----------+-----------+
|   data    |   next    |
|   (int)   |  (Node*)  |
+-----------+-----------+

Esempio concreto di nodo:
+-----------+-----------+
|    10     |   NULL    |
+-----------+-----------+

*/

//Struttura della lista
typedef struct{
	Node *head;
	Node *tail;
} List;

//Funzioni:
//Funzione di Inizializzazione: initList
void initList(List *l){
	l->head = NULL;
	l->tail = NULL;
}
/*Con questa funzione abbiamo creato la nostra lista in memoria, significa: La lista esiste, ma non ci sono nodi.
   Head
    ↓
   NULL
    ↑
   Tail
   
E'importante chiarire che Sono puntatori (cursori) che indicano la posizione dei nodi nella memoria. Quindi sono delle etichette che assegnamo al primo e all'ultimo nodo della lista.
*/

//Funzione per capire se la lista è vuota: isEmpty
int isEmpty(List *l){
	return l->head == NULL;
}

//Stiamo dicendo: se la testa è uguale a NULL, allora la lista è vuota perché non punta a nessun elemento.

//Funzione di inserimento nodo in testa: insertHead
void insertHead(List *l, int value){				//La funzione non deve resitituire nulla. Gli passiamo l'indirizzo della lista per permettegli di modifcarla, e passiamo il valore da inserire nel nuovo nodo.
	Node *newNode = malloc(sizeof(Node));
	if(newNode == NULL){							//Allochiamo il nodo e facciamo il solito controllo di allocazione riuscita o fallita.
		printf("Allocazione nodo fallita.\n");
		return;										//Se l'allocazione non va a buon fine, return interrompe immediamente l'esecuzione e riporta al punto in cui l'esecuzione era stata chiamata.
    }
	
	newNode->data = value;							//Ora assegniamo al campo data del nodo che abbiamo appena creato il valore che vogliamo inserire in lista e che abbiamo passato alla funzione.
	newNode->next = l->head;						//Qui diciamo che il nuovo nodo che stiamo inserendo dovrà stare davanti al nodo che prima era la testa. Deve "spodestarlo" in sintesi. Quindi il next di questo nodo punta a quello che prima era la testa.
	
	l->head = newNode;								//Qui diciamo: "il nuovo nodo adesso è la testa della lista"
	
	if(l->tail == NULL) l->tail = newNode;			//Se la coda è uguale a NULL, ossia nessun nodo ha il ruolo di coda (e dunque la lista era vuota con testa e cosa a NULL), allora il nuovo nodo sarà la coda. Quindi la lista contiene solo un nodo che è sia head che tail.
}

//Funzione di inserimento nodo in coda: insertTail
void insertTail(List *l, int value){				
	Node *newNode = malloc(sizeof(Node));			//Come prima si alloca il nodo e si verifica che tutto sia andato a buon fine
	if(newNode == NULL){
		printf("Allocazione nodo fallita.\n");
		return;										
	}
	
	newNode->data = value;							//Inseriamo il valore passato alla funzione all'interno del nodo		
	newNode->next = NULL;							//Essendo un inserimento in coda, il nostro nodo dovrà puntare a NULL, poiché è l'ultimo in lista
	
	if(isEmpty(l)){									//Se la lista è vuota: il nuovo nodo è sia lista che coda
		l->head = newNode;
		l->tail = newNode;
		return;
	}
													//Facendo l'inserimento in coda:
	l->tail->next = newNode;						//Prendiamo la vecchia coda e facciamo puntare il suo next al nuovo nodo
	l->tail = newNode;								//Impostiamo il nuovo nodo come tail
}

//Funzione di cancellazione nodo in testa: removeHead
void removeHead(List *l){
	if(isEmpty(l)) return;							//Qui verifichiamo se la lista è vuota. Se lo è, naturalmente, non possiamo cancellare nulla.
	
	Node *tmp = l->head;							//Dobbiamo usare una variabile temporanea per verificare dove si trova la testa e poi rimuoverla.
	l->head = l->head->next;						//Qui diciamo: "Elimino il nodo in testa, quindi il prossimo nodo sarà la nuova testa della lista"
	
	if(l->head == NULL){							//Se quando eliminiamo il nodo in testa, ci accorgiamo che il next della testa è NULL, allora sappiamo che la la lista è vuota, e dunque dobbiamo impostare anche tail a null per coerenza.
		l->tail = NULL;
	}
	
	free(tmp);										//Liberiamo la memoria per il nodo che abbiamo eliminato.
}

//Funzione di cancellazione nodo in coda: removeTail
void removeTail(List *l){
    if(isEmpty(l)) return;							//Se la lista è vuota non possiamo eliminare nulla

    // Caso: abbiamo un solo nodo	
    if(l->head == l->tail){							//Se il nodo è in testa è lo stesso che è in coda, e quindi abbiamo un solo nodo...				
        free(l->head);								//Fai la free dell'unico nodo, e...
        l->head = NULL;								//Imposti i due cursori head e tail a NULL
        l->tail = NULL;
        return;
    }

    Node *curr = l->head;							//Mettiamo il cursore 'corrente' sulla testa della lista

    while(curr->next != l->tail){					//Finché il nodo successivo non è la tail...
        curr = curr->next;							//...vai avanti
    }

    free(l->tail);									//Eliminiamo il nodo tail dalla lista
    l->tail = curr;									//Il nodo precedente è la nuova cosa
    curr->next = NULL;								//E il puntatore next della nuova coda è NULL	
}

//Funzione per trovare un valore in lista: searchValue
int searchValue(List *l, int value){
    Node *curr = l->head;							//Creiamo un cursore detto 'corrente' che parte dalla testa

    while(curr != NULL){							//Finché corrente è diverso da NULL, quindi è diverso dall fine della lista...
        if(curr->data == value)						//Se il valore di corrente è uguale al valore cercato...
            return 1; 								// trovato

        curr = curr->next; 							// vai avanti
    }

    return 0; 										// non trovato
}

//Funzione per stampare tutta la lista: printList
void printList(List *l){
    Node *curr = l->head;							//Si parte dalla lista
	
    while(curr != NULL){							//Finché non abbiamo raggiunto la fine...
        printf("[%d] ", curr->data);				//Stampa il valore
        if(curr->next != NULL) printf(" -> ");		//Se non siamo alla fine della lista stampa la freccia
        curr = curr->next;							//Spostati al nodo successivo
    }			

    printf("\n");
}
