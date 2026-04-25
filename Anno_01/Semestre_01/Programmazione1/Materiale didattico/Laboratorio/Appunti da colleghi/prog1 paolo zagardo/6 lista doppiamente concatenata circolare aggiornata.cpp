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
        newNode->prev = newNode; // Collegamento circolare
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

    // Aggiorna il collegamento circolare
    struct node *last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = *head;
    (*head)->prev = last;
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
            (*head)->prev = current->prev;
        }
    } else {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
    }

    free(current);

    // Aggiorna il collegamento circolare
    struct node *last = *head;
    while (last->next != *head) {
        last = last->next;
    }
    last->next = *head;
    (*head)->prev = last;
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("La lista è vuota\n");
        return;
    }

    struct node *current = head;
    do {
        printf("%d ", current->number);
        current = current->next;
    } while (current != head);
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

    return 0;
}
