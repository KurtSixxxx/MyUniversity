#include <stdio.h>
#include <stdlib.h>

/*
Indice delle Funzioni:
1. Struttura del Nodo
2. Funzione per creare un nuovo nodo | 'createNode'
3. Funzione per inserire un nodo all'inizio della lista | 'insertHead'
4. Funzione per inserire un nodo alla fine della lista | 'insertEnd'
5. Funzione per stampare la lista | 'printList'
6. Funzione per cancellare un nodo | 'nodeDelete'
7. Funzione per costruire la lista da un array | 'buildList'
8. Funzione principale (main)
*/

// 1. Struttura del Nodo
struct node {
    int data;           // Campo per memorizzare i dati del nodo
    struct node* next;  // Puntatore al nodo successivo
    struct node* prev;  // Puntatore al nodo precedente
};

// 2. Funzione per creare un nuovo nodo
struct node* createNode(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node)); // Alloca memoria per il nuovo nodo
    if (new_node == NULL) {
        printf("Errore nell'allocazione in memoria del nodo.\n");
        return NULL; // Restituisce NULL se l'allocazione fallisce
    }
    new_node->data = data; // Assegna il valore al campo 'data'
    new_node->next = NULL; // Inizializza il puntatore 'next' a NULL
    new_node->prev = NULL; // Inizializza il puntatore 'prev' a NULL
    return new_node;       // Restituisce il nuovo nodo creato
}

// 3. Funzione per inserire un nodo all'inizio della lista
void insertHead(struct node** head, int new_data) {
    struct node* new_node = createNode(new_data); // Crea un nuovo nodo

    if (new_node == NULL) {
        return; // Se la creazione del nodo fallisce, esci dalla funzione
    }

    new_node->next = *head; // Collega il nuovo nodo al nodo attualmente in testa
    new_node->prev = NULL;  // Il nuovo nodo diventa il primo, quindi prev è NULL

    if (*head != NULL) {     // Se la lista non è vuota
        (*head)->prev = new_node; // Aggiorna il puntatore prev del nodo attuale
    }

    *head = new_node;       // Aggiorna la testa della lista per puntare al nuovo nodo
}

// 4. Funzione per inserire un nodo alla fine della lista
void insertEnd(struct node** head, int new_data) {
    struct node* new_node = createNode(new_data); // Crea un nuovo nodo

    if (new_node == NULL) {
        return; // Se la creazione del nodo fallisce, esci dalla funzione
    }

    new_node->next = NULL; // Questo sarà l'ultimo nodo

    if (*head == NULL) {   // Se la lista è vuota
        new_node->prev = NULL; // Il nuovo nodo diventa la testa della lista
        *head = new_node;
        return;            // Esci dalla funzione
    }

    struct node* last = *head; // Inizializza un puntatore chiamato last che punta alla testa

    while (last->next != NULL) { // Trova l'ultimo nodo della lista
        last = last->next;         // Scorri fino all'ultimo nodo
    }

    last->next = new_node;       // Collega il nuovo nodo all'ultimo nodo trovato
    new_node->prev = last;       // Collega il nuovo nodo al precedente
}

// 5. Funzione per stampare la lista
void printList(struct node* head) {
    struct node* current = head; // Inizializza un puntatore temporaneo alla testa

    while (current != NULL) {     // Itera finché non si raggiunge la fine della lista
        printf("%d <-> ", current->data); // Stampa il dato del nodo corrente
        current = current->next;   // Passa al nodo successivo
    }
    
    printf("NULL\n");              // Indica la fine della lista
}

// 6. Funzione per cancellare un nodo dalla lista
void nodeDelete(struct node** head, int key) {
    struct node* tmp = *head;     // Inizializza un puntatore temporaneo alla testa della lista
    struct node* prev = NULL;      // Inizializza un puntatore prev che punta a NULL

    if (tmp != NULL && tmp->data == key) { // Se il primo nodo è quello da cancellare
        *head = tmp->next;       // Aggiorna la testa alla prossima posizione
        
        if (*head != NULL) {     // Se la lista non è vuota dopo la cancellazione
            (*head)->prev = NULL; // Aggiorna il prev della nuova testa a NULL 
        }
        
        free(tmp);               // Libera la memoria del nodo da cancellare 
        return;
    }

    while (tmp != NULL && tmp->data != key) { // Scorri fino a trovare il nodo da cancellare 
        prev = tmp;              // Aggiorna il puntatore 'prev' al nodo corrente 
        tmp = tmp->next;         // Passa al prossimo nodo 
    }

    if (tmp == NULL) return;     // Nodo non trovato 

    prev->next = tmp->next;      // Salta il nodo da cancellare 

    if (tmp->next != NULL) {      // Se esiste un successore 
        tmp->next->prev = prev;   // Aggiorna il puntatore prev del successore 
    }

    free(tmp);                   // Libera la memoria del nodo da cancellare 
}

// 7. Funzione per costruire una lista a partire da un array di valori
struct node* buildList(int arr[], int size) {
    struct node* head = NULL;     // Inizializza la testa della lista a NULL

    for (int i = 0; i < size; i++) { 
        insertEnd(&head, arr[i]);  // Inserisci ogni valore dell'array alla fine della lista 
    }

    return head;                  // Restituisce la testa della lista costruita 
}

// 8. Funzione principale (main)
int main() {
    struct node* head = NULL;     // La testa della lista va sempre inizializzata a 'NULL'.

    int values[] = {10, 20, 30};   // Array di valori da inserire nella lista

    head = buildList(values, sizeof(values)/sizeof(values[0]));  // Costruisce la lista a partire dall'array

    printf("Lista costruita:\n");
    printList(head);               // Stampa la lista costruita

    insertHead(&head, 5);          // Inserisce '5' all'inizio della lista 
    printf("Lista dopo l'inserimento in testa:\n");
    printList(head);               // Stampa la lista aggiornata

    insertEnd(&head, 40);          // Inserisce '40' alla fine della lista 
    printf("Lista dopo l'inserimento in coda:\n");
    printList(head);               // Stampa la lista aggiornata

    nodeDelete(&head, 20);         // Cancella il valore '20' dalla lista 
    printf("Lista dopo l'eliminazione di '20':\n");
    printList(head);               // Stampa la lista aggiornata

   int keyToSearch = 30;
   if(searchNode(head, keyToSearch)) { 
       printf("Il valore %d è stato trovato nella lista.\n", keyToSearch);
   } else {
       printf("Il valore %d non è stato trovato nella lista.\n", keyToSearch);
   }

   return 0;
}