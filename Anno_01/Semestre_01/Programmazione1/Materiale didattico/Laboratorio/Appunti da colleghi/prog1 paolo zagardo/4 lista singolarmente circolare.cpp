#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Struttura del nodo della lista
struct Node {
    int data;
    struct Node* next;
};

// Struttura della lista
struct CircularList {
    struct Node* head;
};

// Funzione per creare un nuovo nodo
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        perror("Errore di allocazione di memoria\n");
        exit(-1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Funzione per creare una nuova lista
struct CircularList* createList() {
    struct CircularList* list = (struct CircularList*)malloc(sizeof(struct CircularList));
    if (list == NULL) {
        perror("Errore di allocazione di memoria\n");
        exit(-1);
    }
    list->head = NULL;
    return list;
}

// Funzione per aggiungere un elemento alla lista
void addElement(struct CircularList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode; // Collegamento circolare
    } else {
        struct Node* current = list->head;
        while (current->next != list->head) {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = list->head; // Collegamento circolare
    }
}

void deleteNode(struct CircularList* list, int data) {
    if (list->head == NULL) return; // lista vuota

    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (current->data != data) {
        prev = current;
        current = current->next;
        if (current == list->head) break; // nodo non trovato
    }

    if (current == NULL) return; // nodo non trovato

    if (current == list->head) {
        // caso speciale: eliminare il nodo head
        if (list->head->next == list->head) {
            list->head = NULL;
        } else {
            struct Node* temp = list->head;
            while (temp->next != list->head) {
                temp = temp->next;
            }
            list->head = current->next;
            temp->next = list->head;
        }
    } else {
        prev->next = current->next;
    }

    free(current);
}

// Funzione per stampare la lista
void printList(struct CircularList* list) {
    struct Node* current = list->head;
    struct Node* start = current; // memorizzo il nodo iniziale
    if (current == NULL) {
        printf("Lista vuota\n");
        return;
    }
    while (true) {
        printf("%d ", current->data);
        current = current->next;
        if (current == start) break; // esco quando torno al nodo iniziale
    }
    printf("\n");
}

int main() {
    struct CircularList* list = createList();
    int array[] = {1, 2, 3, 4, 5};
    int size = sizeof(array) / sizeof(array[0]);

    // Aggiungi elementi dall'array alla lista
    for (int i = 0; i < size; i++) {
        addElement(list, array[i]);
    }

    printf("Lista originale: ");
    printList(list);

    // Rimuovi tutti gli elementi dalla lista
    while (list->head != NULL) {
        deleteNode(list, list->head->data);
    }

    printf("Lista dopo la rimozione di tutti gli elementi: ");
    printList(list);

    return 0;
}
