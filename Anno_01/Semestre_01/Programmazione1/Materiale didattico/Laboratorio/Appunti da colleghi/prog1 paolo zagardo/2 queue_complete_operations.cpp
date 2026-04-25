#include <stdio.h>
#include <stdlib.h>

struct node {
    int number;
    struct node* next;
};

struct queue {
    struct node *front, *back;
};

int isEmpty(struct queue *queue) {
    return queue->front == NULL;
}

void enqueue(struct queue *queue, int value) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->number = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->back = newNode;
    } else {
        queue->back->next = newNode;
        queue->back = newNode;
    }
}

void dequeue(struct queue *queue) {
    if (isEmpty(queue)) {
        printf("La coda è vuota, impossibile rimuovere l'elemento\n");
        return;
    }

    struct node *temp = queue->front;
    queue->front = queue->front->next;
    free(temp);

    if (queue->front == NULL) {
        queue->back = NULL;
    }
}

void freeQueue(struct queue *queue) {
    while (!isEmpty(queue)) {
        dequeue(queue);
    }
}

int searchQueue(struct queue *queue, int value) {
    struct node *current = queue->front;
    while (current != NULL) {
        if (current->number == value) {
            return 1; // Elemento trovato
        }
        current = current->next;
    }
    return 0; // Elemento non trovato
}

void printQueue(struct queue *queue) {
    if (isEmpty(queue)) {
        printf("La coda è vuota\n");
        return;
    }

    struct node *current = queue->front;
    printf("Contenuto della coda: ");
    while (current != NULL) {
        printf("%d ", current->number);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct queue queue;
    queue.front = queue.back = NULL;

    int arr[] = {12, 3, 4, 5};
    int numElements = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < numElements; ++i) {
        enqueue(&queue, arr[i]);
        printQueue(&queue);
    }

    printf("Ricerca dell'elemento 3: %d\n", searchQueue(&queue, 3));
    printf("Ricerca dell'elemento 10: %d\n", searchQueue(&queue, 10));

    for (int i = 0; i < numElements; ++i) {
        dequeue(&queue);
        printQueue(&queue);
    }

    freeQueue(&queue);
    printQueue(&queue);

    return 0;
}
