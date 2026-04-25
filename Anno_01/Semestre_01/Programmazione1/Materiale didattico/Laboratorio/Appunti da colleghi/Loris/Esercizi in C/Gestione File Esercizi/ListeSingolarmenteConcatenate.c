#include <stdio.h>
#include <stdlib.h>

/*
Indice delle Funzioni:
1. Struttura del Nodo
2. Funzione per creare un nuovo nodo | createNode
3. Funzione per inserire un nodo all'inizio della lista | insertHead
4. Funzione per inserire un nodo alla fine della lista | insertEnd
5. Funzione per stampare la lista | printList
6. Funzione per cancellare un nodo | nodeDelete
7. Funzione per cercare un nodo | searchNode
8. Funzione per costruire la lista da un array | buildList
9. Funzione principale (main)
*/

// 1. Struttura del Nodo
struct Node {
    int data;           // Campo per memorizzare i dati del nodo
    struct Node* next;  // Puntatore al nodo successivo
};

// 2. Funzione per creare un nuovo nodo
struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // Alloca memoria per il nuovo nodo
    if (new_node == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return NULL; // Restituisce NULL se l'allocazione fallisce
    }
    new_node->data = data; // Assegna il valore al campo 'data'
    new_node->next = NULL; // Inizializza il puntatore 'next' a NULL
    return new_node;       // Restituisce il nuovo nodo creato
}

// 3. Funzione per inserire un nodo all'inizio della lista
void insertHead(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data); // Crea un nuovo nodo

    if (new_node == NULL) {
        return; // Se la creazione del nodo fallisce, esci dalla funzione
    }

    new_node->next = *head; // Collega il nuovo nodo al nodo attualmente in testa
    *head = new_node;       // Aggiorna la testa della lista per puntare al nuovo nodo
}

// 4. Funzione per inserire un nodo alla fine della lista
void insertEnd(struct Node** head, int new_data) {
    struct Node* new_node = createNode(new_data); // Crea un nuovo nodo

    if (new_node == NULL) {
        return; // Se la creazione del nodo fallisce, esci dalla funzione
    }

    if (*head == NULL) { // Se la lista è vuota
        *head = new_node; // Il nuovo nodo diventa la testa della lista
        return;          // Esci dalla funzione
    }

    struct Node* end = *head; // Inizializza un puntatore chiamato end che punta alla testa

    while (end->next != NULL) { // Trova l'ultimo nodo della lista
        end = end->next;         // Scorri fino all'ultimo nodo
    }

    end->next = new_node;       // Collega il nuovo nodo all'ultimo nodo trovato
}

// 5. Funzione per stampare la lista
void printList(struct Node* head) {
    struct Node* current = head; // Inizializza un puntatore temporaneo alla testa

    while (current != NULL) {     // Itera finché non si raggiunge la fine della lista
        printf("[%d] -> ", current->data); // Stampa il dato del nodo corrente
        current = current->next;   // Passa al nodo successivo
    }
    printf("NULL\n");              // Indica la fine della lista
}

// 6. Funzione per cancellare un nodo dalla lista
void nodeDelete(struct Node** head, int key) {
    struct Node* tmp = *head;     // Inizializza un puntatore temporaneo alla testa della lista
    struct Node* prev = NULL;      // Inizializza un puntatore per il nodo precedente

    if (tmp != NULL && tmp->data == key) { // Controlla se il primo nodo è quello da cancellare
        *head = tmp->next;       // Aggiorna la testa per puntare al secondo nodo
        free(tmp);               // Libera la memoria del nodo da cancellare
        return;                  // Esci dalla funzione
    }

    while (tmp != NULL && tmp->data != key) { // Scorri la lista per trovare il nodo da cancellare
        prev = tmp;              // Aggiorna il puntatore 'prev' al nodo corrente
        tmp = tmp->next;         // Passa al prossimo nodo
    }

    if (tmp == NULL) return;     // Se abbiamo raggiunto la fine senza trovare il nodo, esci

    prev->next = tmp->next;      // Salta il nodo da cancellare nella lista
    free(tmp);                   // Libera la memoria del nodo da cancellare
}

// 7. Funzione per cercare un valore nella lista
int searchNode(Node* head, int key) {
    Node* current = head;

    while (current != NULL) {     // Itera finché non si raggiunge la fine della lista
        if (current->data == key) { 
            return 1;             // Valore trovato, restituisce 1 (vero)
        }
        current = current->next;   // Passa al prossimo nodo
    }
    
    return 0;                     // Valore non trovato, restituisce 0 (falso)
}

// 8. Funzione per costruire una lista a partire da un array di valori
struct node* buildList(int arr[], int size) {
    struct node* head = NULL; // Inizializza la testa della lista a NULL

    for (int i = 0; i < size; i++) { 
        insertEnd(&head, arr[i]); // Inserisci ogni valore dell'array alla fine della lista 
    }

    return head; // Restituisce la testa della lista costruita 
}

// 9. Funzione principale (main)
int main() {
    Node* head = NULL;            // La testa della lista va sempre inizializzata a 'NULL'.

    int values[] = {10, 20, 30};  // Array di valori da inserire nella lista

    head = buildList(values, sizeof(values)/sizeof(values[0]));  // Costruisce la lista a partire dall'array

    printf("Lista dopo l'inserimento:\n");
    printList(head);              // Stampa la lista costruita

    insertHead(&head, 5);         // Inserisce '5' all'inizio della lista 
    printf("Lista dopo l'inserimento in testa:\n");
    printList(head);              // Stampa la lista aggiornata

    insertEnd(&head, 40);         // Inserisce '40' alla fine della lista 
    printf("Lista dopo l'inserimento in coda:\n");
    printList(head);              // Stampa la lista aggiornata

    nodeDelete(&head, 20);        // Cancella il valore '20' dalla lista 
    printf("Lista dopo l'eliminazione di '20':\n");
    printList(head);              // Stampa la lista aggiornata

    int keyToSearch = 30;
    
   if(searchNode(head, keyToSearch)) { 
       printf("Il valore %d è stato trovato nella lista.\n", keyToSearch);
   } else {
       printf("Il valore %d non è stato trovato nella lista.\n", keyToSearch);
   }

   return 0;
}