#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *prev;
    struct node *next;
};

void insertNode(struct node **head, int num) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->number = num;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL || (*head)->number >= num) {
        newNode->next = *head;
        if (*head != NULL) {
            (*head)->prev = newNode;
        }
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next != NULL && current->next->number < num) {
        current = current->next;
    }

    newNode->next = current->next;
    if (current->next != NULL) {
        current->next->prev = newNode;
    }
    current->next = newNode;
    newNode->prev = current;
}

void deleteNode(struct node **head, int num) {
    if (*head == NULL)
        return;

    struct node *current = *head;
    while (current != NULL && current->number != num) {
        current = current->next;
    }

    if (current == NULL)
        return; // Elemento non trovato

    if (current->prev == NULL) { // Primo elemento
        *head = current->next;
        if (*head != NULL) {
            (*head)->prev = NULL;
        }
    } else {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
    }

    free(current);
}

void freeList(struct node **head) {
    struct node *current = *head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int searchNode(struct node *head, int num) {
    struct node *current = head;
    while (current != NULL) {
        if (current->number == num) {
            return 1; // Elemento trovato
        }
        current = current->next;
    }
    return 0; // Elemento non trovato
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("La lista è vuota\n");
        return;
    }

    while (head != NULL) {
        printf("%d ", head->number);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct node *head = NULL;

    int arr[] = {12, 34, 4, 6, 87, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        insertNode(&head, arr[i]);
        printList(head);
    }

    deleteNode(&head, 12);
    printList(head);

    printf("Ricerca dell'elemento 34: %d\n", searchNode(head, 34));
    printf("Ricerca dell'elemento 100: %d\n", searchNode(head, 100));

    freeList(&head);
    printList(head);

    return 0;
}
