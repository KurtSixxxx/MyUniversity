#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node *next;
};

void insertNode(struct node **head, int number) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->number = number;

    if (*head == NULL || (*head)->number >= number) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *current = *head;
    while (current->next!= NULL && current->next->number < number) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void deleteNode(struct node **head, int number) {
    if (*head == NULL) return;

    if ((*head)->number == number) {
        struct node *tmp = *head;
        *head = (*head)->next;
        free(tmp);
        return;
    }

    struct node *current = *head;
    while (current->next!= NULL && current->next->number!= number) {
        current = current->next;
    }

    if (current->next == NULL) return;

    struct node *toDeleteNode = current->next;
    current->next = toDeleteNode->next;
    free(toDeleteNode);
}

void printList(struct node *head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (head!= NULL) {
        printf("%d ", head->number);
        head = head->next;
    }
    printf("\n");
}

int searchNode(struct node *head, int number) {
    while (head != NULL) {
        if (head->number == number) {
            return 1; // elemento trovato
        }
        head = head->next;
    }
    return 0; // elemento non trovato
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

int main() {
    struct node *head = NULL;

    int values[] = {6, 5, 4};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        insertNode(&head, values[i]);
        printList(head);
    }

    deleteNode(&head, 4);
    printList(head);

    int searchValue = 5;
    if (searchNode(head, searchValue)) {
        printf("%d found in the list\n", searchValue);
    } else {
        printf("%d not found in the list\n", searchValue);
    }

    freeList(&head);

    return 0;
}