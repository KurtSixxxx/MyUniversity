#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int get_random() {
static unsigned int m_w = 123456;
static unsigned int m_z = 789123;
m_z = 36969 * (m_z & 65535) + (m_z >> 16);
m_w = 18000 * (m_w & 65535) + (m_w >> 16);
return (m_z << 16) + m_w;
}
 
struct parametri{
    int N;
    char w;
};

typedef struct node {
    char data[20];
    struct node *next;
} Node;

void insertHead(Node **head, char *string){
    if(*head == NULL){
        *head = malloc(sizeof(Node));
        strncopy((*head)->data, string);
        new->next = *head;
        *head = new;
    }
}

void insertString(Node **head, char *string){
    if(*head == NULL){
        insertHead(head, string);
        return;
    }
}

Node *ptr = *head;
Node *prev = NULL;

while(ptr && strcmp(ptr->data, string) < 0){
    prev = ptr;
    ptr = ptr->next;
}

if(prev == NULL){
    insertHead(head, string);
    return;
}

Node *new = malloc(sizeof(Node));
strncpy(new->data, string);
prev->next = new;
new->next = ptr;

void printList(Node *head){
    Node *tmp = head;

    while(tmp){
        printf("%s\n", tmp->data);
        tmp = tmp->next;
    }
}

char* genString(int len, const char range[2]){
    char *s =
}