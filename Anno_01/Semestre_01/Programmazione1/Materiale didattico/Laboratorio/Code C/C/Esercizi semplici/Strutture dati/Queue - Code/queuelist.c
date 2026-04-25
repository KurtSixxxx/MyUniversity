//Implementazione di una coda usando le liste concatenate

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct queue {          //Struttura della coda.
    struct node *front; //Puntatore al primo elemento (testa) della coda.
    struct node *back;  //Puntatore all'ultimo elemento (coda).
};

int isEmpty(struct queue *queue) {  //Controlla se la coda è vuota.
    return queue->front == NULL;    //Se front == NULL allora la coda è vuota.
}

// Enqueue: funzione per inserire un nuovo elemento
void enqueue(struct queue *queue, int value) {  //Si accettano come valori la struct queue, ossia la coda, e il valore da inserire
    struct node *newNode = malloc(sizeof(struct node)); //Si alloca un nuovo nodo nella memoria dinamica, servirà per salvare il nuovo valore
    newNode->data = value;  //Si aggiunge il nuovo valore al campo data
    newNode->next = NULL;   //Si aggiorna il puntatore next del nodo del nuovo dato a NULL. Questo segnala che il nodo è l'ultimo della lista.

    if (isEmpty(queue)) {   //Verifica se la coda è vuota
        queue->front = queue->back = newNode; //Se la coda è vuota, il nuovo nodo diventa sia il primo (front) che l'ultimo (back) elemento della coda.
    } else {    //Se la lista non è vuota
        queue->back->next = newNode; //Questo passaggio collega il nuovo nodo alla fine della coda. Stiamo dicendo all'ultimo nodo di "puntare" al nuovo nodo.
        queue->back = newNode; //Questo passaggio aggiorna il puntatore back della coda, in modo che punti al nuovo nodo, che è diventato l'ultimo elemento della coda.
    }
}

// Dequeue: funzione per estrarre un elemento
void dequeue(struct queue *queue) { //Si accetta come parametro la coda stessa
    if (isEmpty(queue)) {   //Se la coda è vuota, stampa il messaggio sotto
        printf("La coda è vuota, impossibile rimuovere l'elemento\n");
        return;
    }

    struct node *temp = queue->front;   //Crea un nodo temporaneo e lo imposta come testa della coda
    queue->front = queue->front->next;  //Qui viene aggiornato il nuovo next della testa nella coda
    free(temp);                         //Viene fatta la free per liberare la memoria del nodo temporaneo

    if (queue->front == NULL) {     //Se la testa della coda è ugule a NULL allora anche al coda sarà NULL
        queue->back = NULL;
    }
}

void freeQueue(struct queue *queue) {   //Questa funzione viene utilizzata per liberare la coda
    while (!isEmpty(queue)) {   //Finchè la coda non sarà vuota allora elimina tutti i nodi
        dequeue(queue);
    }
}

int searchQueue(struct queue *queue, int value) {   //Questa funzione serve per cercare un valore all'interno della coda, per questo accetta come parametri la coda stessa e il valore da cercare
    struct node *current = queue->front;    //Current è un puntatore alla testa che serve per scorrere la coda e trovare l'elemento
    while (current != NULL) {               //Finché ci sono elementi:
        if (current->data == value) {       //Verifica se il valore di current è uguale a quello che stiamo cercando
            return 1; // Elemento trovato   //Se lo è restituisce 1
        }
        current = current->next;            //Aggiorna il next di current affinchè scorre la lista e l'elemento cercato non viene trovato
    }
    return 0; // Elemento non trovato, restituisce 0
}

void printQueue(struct queue *queue) {  //Funzione per stampare la coda, il parametro è la coda stessa
    if (isEmpty(queue)) {   //Se la coda è vuota allora non potremmo stamparla e ci verrà detto che la coda è vuota
        printf("La coda è vuota\n");
        return;
    }

    struct node *current = queue->front;    //Current è un puntatore alla testa che serve per scorrere la coda e stampare gli elementi
    printf("Contenuto della coda: ");
    while (current != NULL) {               //Finchè current è diverso da null stampa gli elementi, quindi finchè non finisce di scorrere la lista
        printf("%d ", current->data);
        current = current->next;            //Aggiorna il next di current affinchè scorre la lista e finisce di stamparla
    }
    printf("\n");
}

int main() {
    struct queue queue;
    queue.front = queue.back = NULL;

    int arr[] = {12, 3, 4, 5};
    int numElements = sizeof(arr) / sizeof(arr[0]); //Serve per sapere la dimensione dell'array che serve per inserire tutti gli elementi

    for (int i = 0; i < numElements; ++i) { //Finchè i < numElements, allora inserisce elementi e li stampa
        enqueue(&queue, arr[i]);
        printQueue(&queue);
    }

    printf("Ricerca dell'elemento 3: %d\n", searchQueue(&queue, 3));
    printf("Ricerca dell'elemento 10: %d\n", searchQueue(&queue, 10));

    for (int i = 0; i < numElements; ++i) { //Finchè i < numElements allora elimina gli elementi
        dequeue(&queue);
        printQueue(&queue);
    }

    freeQueue(&queue);
    printQueue(&queue);

    return 0;
}