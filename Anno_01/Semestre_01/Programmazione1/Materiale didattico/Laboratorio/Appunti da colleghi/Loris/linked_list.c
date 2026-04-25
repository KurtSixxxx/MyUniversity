#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* head;

void insert(int x){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->next=head;
    if(head!=NULL){
        temp->next=head;
    }
    head=temp;
}

void print(){
    struct node* temp = head;
    printf("La lista e':");

    while(temp!=NULL){
        printf(" %d", temp->data);
        temp= temp->next;
    }
    printf("\n");
}

int main(){
    head = NULL;// empty list
    printf("Quanti numeri?\n");
    int n, x;
    scanf("%d", &n);
    printf("Metti i numeri:\n");
    for(int i=0; i<n;i++){
        scanf("%d", &x);
        insert(x);
        print();
    }
}