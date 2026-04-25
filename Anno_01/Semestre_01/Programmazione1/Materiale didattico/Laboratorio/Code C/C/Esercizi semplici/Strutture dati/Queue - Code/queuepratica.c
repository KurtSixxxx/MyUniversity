#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct queue{
    struct node *front, *back;
};

int isEmpty(struct queue *queue){
    return queue->front == NULL;
}

void enqueue(struct queue *queue, int value){
    struct node *newNode = malloc(sizeof(struct node);
    
}