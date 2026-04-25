#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}Node;

void insertHead (Node** head, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        return;
    }

    new_node->data = data;
    new_node->next = *head;
    *head = new_node;
};

void insertEnd (Node** head, int data){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Errore nell'allocazione della memoria.\n");
        return;
    }

    Node* end = *head;
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL){
        *head = new_node;
        return;
    };

    while(end->next != NULL){
        end = end->next; 
    }

    end->next = new_node;
};

void printList(Node* head){
    printf("HEAD -> ");
    Node* current = head;
    while(current != NULL){
        printf("[%d] -> ", current->data);
        current = current->next; //Questa sintassi (come in insertEnd) serve per scorrere
    }
    printf("NULL\n");
};

int searchNode(Node* head, int key){
    Node* current = head;

    while(current != NULL){
        if(current->data == key){
            return 1; //Valore trovato
        }
        current = current->next;
    }
    return 0; //Valore non trovato
};

int main(){
    Node* head = NULL; //La testa della lista va sempre inizializzata a 'NULL'.

    insertHead(&head, 20);
    insertHead(&head, 10);
    insertEnd(&head, 30);
    insertEnd(&head, 40);

    printf("La lista: \n");
    printList(head);


    int key = 20;
    if(searchNode(head, key)) {
        printf("Valore %d: trovato nella lista.\n", key);
    } else {
        printf("Valore %d: trovato nella lista.\n", key);
    }

    return 0;
}