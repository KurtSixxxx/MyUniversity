/*Uno stack (pila) è una catena di nodi collegati, come una lista, ma con una regola:
puoi inserire o togliere elementi solo dalla cima (detta top).

Lo rappresentiamo così:
top → [10] → [20] → [30] → NULL

Le funzioni principali sono:
- push() → aggiunge un elemento sopra il top
- pop() → rimuove un elemento dal top
- isEmpty() → controlla se lo stack è vuoto
- printStack() → mostra gli elementi dall'alto verso il basso

Come si crea lo stack:
Si parte da una struct nodo:
*/

//Struttura di un nodo
typedef struct nodo{
    int data;
    struct nodo *next;
}Nodo;

//e nel main() si tiene il puntatore alla cima:
Nodo *top = NULL; //Stack vuoto

//Funzionalità fondamentali
// isEmpty()

int isEmpty(Nodo *top){
    return top == NULL;
}
//Serve per evitare di fare pop() su uno stack vuoto.

// push()

void push(Nodo **top, int value);

// Nodo **top → serve un doppio puntatore perché voglio modificare il puntatore 'top' del main (cioè cambiare chi è la cima)
// Se passassimo solo 'Nodo *top', lavoreremo su una copia locale e la modifica non andarebbe ad incidere sul dato che ci interessa, quin non uscirebbe dalla funzione
// int valore invece è il dato da inserire


void push(Nodo **top, int value){
    Nodo *nuovo = malloc(sizeof(Nodo)); //alloco un nuovo nodo
    if (nuovo == NULL) {                //controllo che sia allocato
        printf("Errore allocazione\n");
        exit(1);
    }
    nuovo->data = value;                //aggiungo un valore al campo 'data'
    nuovo->next = *top;                 //collego al vecchio top
    *top = nuovo;                       //aggiorno top, rendendo il nuovo valore il top ossia quello in cima
}

/*Esempio visivo
prima: top → [30] → [20] → [10]
push(40)
dopo:  top → [40] → [30] → [20] → [10]
*/

// pop()

int pop(Nodo **top);

//Doppio puntatore anche qui, perché dobbiamo spostare il top al nodo successivo.
//Restituisce l'int rimosso.

int pop(Nodo **top){
    if(isEmpty(*top)){                  //controlliamo se lo stack è vuoto
        printf("Stack vuoto!\n");
        return -1;
    }

    Nodo *tmp = *top;                   //creiamo un nodo per prelevare solo i dati che abbiamo rimosso
    int valore = tmp->data;             //creiamo una variabile valore per vedere cosa rimuoviamo
    *top = tmp->next;                   //aggiorniamo il puntatore di top, facendolo puntare al nodo sotto, che adesso è diventato il primo
    free(tmp);                          //qui fai la free di tmp, Quindi: stai liberando la memoria che era stata allocata da push() non qualcosa creata “dal nulla”.
    return valore;                      //ritorniamo il valore che abbiamo rimosso
}

/*
Con tmp non stiamo creando un nuovo nodo, ma solo un puntatore che punta allo stesso valore
Quindi:
nessun malloc
nessun nuovo spazio creato
solo un “nuovo dito” che indica il nodo in cima.

      +-----------+
top → | [30] next | → [20] → [10] → NULL
      +-----------+
tmp ──┘

malloc serve solo quando vuoi creare nuovo spazio in heap.
Nel caso di pop(), noi non vogliamo creare nulla,
vogliamo rimuovere qualcosa che è già stato allocato da push().
*/



/*
prima: top → [40] → [30] → [20]
pop() → ritorna 40
dopo:  top → [30] → [20]
*/

// peek()
int peek(Nodo *top){
    if(isEmpty(top)){
        printf("Stack vuoto!\n");
        return -1;
    }
    return top->data;
}

// stampa stack
void printStack(Nodo *top){
    if(isEmpty(top)) {
        printf("Stack vuoto!\n");
        return;
    }

    Nodo *corrente = top;
    printf("\n--- Stack ---\n");
    while(corrente != NULL){
        printf("[%d]\n", corrente->valore);
        corrente = corrente->next; //Significa letteralmente: “Sposta il puntatore 'corrente' al nodo successivo.”
    }
}