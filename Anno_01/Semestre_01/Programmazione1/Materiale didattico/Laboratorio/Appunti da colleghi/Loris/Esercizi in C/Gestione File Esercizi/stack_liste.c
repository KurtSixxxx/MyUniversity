#include <stdio.h>
#include <stdlib.h>

// Definizione della struttura del nodo
struct node {
    int data;              // Campo per memorizzare i dati del nodo
    struct node* next;     // Puntatore al nodo successivo
};

// Funzione per inserire un nuovo elemento nella pila FIFO
/*Passaggi:
- Si crea un newNode, nonchè nuovo elemento della pila
- Si assegna il valore a questo nuovo nodo
- Si collega il nuovo nodo al nodo attualmente in testa
- Si aggiorna la testa con il nuovo nodo */
void insert(struct node **head, int value) {       //Utilizza un doppio puntatore 'node** head' per poter aggiornare direttamente la testa della lista   
    struct node *newNode = (struct node*) malloc(sizeof(struct node)); // Alloca memoria per un nuovo nodo
    newNode->data = value;       // Assegna il valore al nuovo nodo
    newNode->next = *head;       // Collega il nuovo nodo al nodo attualmente in testa
    *head = newNode;             // Aggiorna la testa della lista per puntare al nuovo nodo
}

// Funzione per rimuovere l'elemento in cima alla pila
/*Passaggi:
- Si controlla se la pila è vuota tramite *head == NULL
- Si crea un nodo tmp che punta alla testa dalla lista, ossia la cima della pila
- Si aggiorna il next di tmp ad head: *head = tmp->next
- Si libera la materia del nodo rimosso*/
void pop(struct node **head) {
    if (*head == NULL) { // Controlla se la pila è vuota
        printf("Stack is empty, cannot pop.\n");
        return; // Esci dalla funzione se la pila è vuota
    }
    struct node* tmp = *head;    // Salva il nodo attuale in cima alla pila
    *head = tmp->next;            // Aggiorna la testa della lista per puntare al nodo successivo
    free(tmp);                    // Libera la memoria del nodo rimosso
}

// Funzione per stampare gli elementi della pila
/*Passaggi:
- Si itera con un while che lavora finché head == NULL (Nessun puntaore ad head dato che si tratta solo di visualizzare i nodi)
- Si stampa il dato del nodo corrente con head->data
- Si passa al nodo successivo: head = head->next */
void printList(struct node *head) {
    printf("Stack: ");
    while (head != NULL) {        // Itera finché non si raggiunge la fine della lista
        printf("%d ", head->data); // Stampa il dato del nodo corrente
        head = head->next;        // Passa al nodo successivo
    }
    printf("\n");                 // Stampa una nuova riga alla fine
}

// Funzione per stampare l'elemento in cima alla pila
/*Passaggi:
- Si controlla se la pila non è vuota
- Si stampa l'elemento in cima con data di head
- Oppure si dice che la pila è vuota*/
void printTop(struct node *head) {
    if (head != NULL) {           // Controlla se la pila non è vuota
        printf("Top: %d\n", head->data); // Stampa il dato dell'elemento in cima
    } else {
        printf("Stack is empty\n"); // Se la pila è vuota, informa l'utente
    }
}

// Funzione per cercare un valore nella pila
/*Passaggi:
- Finchè la testa della lista non è ugaule a NULL si itera tutta la pila
- Si controlla se il dato di head è uguale al valore cercato
- Si passa al nodo successivo con head = head->next, ossia con il puntatore next di head
- Se si è trovato si restituisce 1, altrimenti 0*/
int search(struct node *head, int value) {
    while (head != NULL) {        // Itera finché non si raggiunge la fine della lista
        if (head->data == value) { // Controlla se il valore corrente è quello cercato
            return 1;             // Elemento trovato, restituisce 1
        }
        head = head->next;        // Passa al nodo successivo
    }
    return 0;                     // Elemento non trovato, restituisce 0
}

// Funzione per liberare la memoria occupata dalla lista
/*Passaggi:
- Si crea un nodo tmp
- Si itera finché ci sono nodi nella lista
- Si aggiorna tmp = *head 
- Si aggiorna la testa del puntatore per puntare al nodo successivo
- Si fa la free(tmp) */
void freeList(struct node **head) {
    struct node *tmp;
    while (*head != NULL) {       // Itera finché ci sono nodi nella lista
        tmp = *head;              // Salva il nodo attuale in tmp
        *head = (*head)->next;    // Aggiorna la testa per puntare al nodo successivo
        free(tmp);                // Libera la memoria del nodo salvato in tmp
    }
}

// Funzione principale (main)
int main() {
    struct node *head = NULL;     // Inizializza la testa della lista a NULL

    int values[] = {1, 2, 3, 4};   // Array di valori da inserire nella pila
    int n = sizeof(values) / sizeof(values[0]); // Calcola il numero di elementi nell'array

    for (int i = 0; i < n; ++i) {  // Ciclo per inserire ogni valore nella pila
        insert(&head, values[i]);   // Inserisce il valore nella pila
        printTop(head);             // Stampa l'elemento in cima alla pila
        printList(head);            // Stampa tutti gli elementi nella pila
    }

    pop(&head);                    // Rimuove l'elemento in cima alla pila
    printTop(head);                // Stampa l'elemento in cima dopo il pop
    printList(head);               // Stampa gli elementi rimanenti nella pila

    int searchValue = 3;           // Valore da cercare nella pila
    if (search(head, searchValue)) { 
        printf("%d found in the stack\n", searchValue);
    } else {
        printf("%d not found in the stack\n", searchValue);
    }

    freeList(&head);               // Libera tutta la memoria occupata dalla lista

    return 0;                      // Termina il programma con successo
}