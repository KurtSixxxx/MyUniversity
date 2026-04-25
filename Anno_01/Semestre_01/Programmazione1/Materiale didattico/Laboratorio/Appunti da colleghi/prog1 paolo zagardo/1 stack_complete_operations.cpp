#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void push(struct node **head, int value) {
    struct node *newNode = (struct node*) malloc(sizeof(struct node));  //allocazione del nuovo nodo
    newNode->data = value;      //attribuisco il valore
    newNode->next = *head;      //collego il next alla testa 
    *head = newNode;            //la testa 
}

void pop(struct node **head) {
    struct node* tmp = *head;
    *head = tmp->next;
    free(tmp);
}

void printList(struct node *head) {
    printf("Stack: ");
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printTop(struct node *head) {
    if (head!= NULL) {
        printf("Top: %d\n", head->data);
    } else {
        printf("Stack is empty\n");
    }
}

int search(struct node *head, int value) {
    while (head != NULL) {
        if (head->data == value) {
            return 1; // element found
        }
        head = head->next;
    }
    return 0; // element not found
}

void freeList(struct node **head) {
    struct node *tmp;
    while (*head != NULL) {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

int main() {
    struct node *head = NULL;

    int values[] = {1, 2, 3, 4};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; ++i) {
        push(&head, values[i]);
        printTop(head);
        printList(head);
    }

    pop(&head);
    printTop(head);
    printList(head);

    int searchValue = 3;
    if (search(head, searchValue)) {
        printf("%d found in the stack\n", searchValue);
    } else {
        printf("%d not found in the stack\n", searchValue);
    }

    freeList(&head);

    return 0;
}
