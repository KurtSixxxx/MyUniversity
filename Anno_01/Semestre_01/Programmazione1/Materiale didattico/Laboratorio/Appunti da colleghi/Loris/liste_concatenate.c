#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**/

struct node{
    char data[30+1];
    struct node* next;
};

/*void stampaLista(struct node *p){
    while(p!=NULL){
        if(p->next!=NULL){
            printf("%d->", p->data);
        }else{
            printf("%d", p->data);
        }
        p=p->next;
    }
}*/


//inserimento in lista
void list_insert(struct node** head, char *data){  //il doppio puntatore sta perché passiamo per riferimento head, e quindi dopo posso andare a modificarlo
    //per prima cosa alloco la memoria per il nuovo nodo e preparo i suoi campi, così facendo creo il nuovo nodo
    struct node* newNode=(struct node*)malloc(sizeof(struct node));

    //faccio un controllo
    if(newNode==NULL){
        exit(0);
    }


    nuovo->data=data;  //setto così al suo interno il dato che serve a noi
    nuovo->next=(*head);   //essendo in testa, facciamo così l'inserimento alla testa della pila

    (*head)=newNode;      //mettiamo la testa uguale al primo elemento in lista
}

void list_display(struct node *p){    //utilissimo per la stampa, *p punterà al primo elemento in testa
    printf("\n");

    while(p!=NULL){                   //entro nel while, ovvero in un ciclo, per stampare tutti gli elementi in lista in ordine di inserimento
        printf("%d->", p->data);
        p=p->next;
    }
    printf("NULL\n");
}

//funzione per ricerca di nodo
int list_search(struct node** head, int ricercato){
    struct node *corrente=*head;

    while(corrente!=NULL){
        if(corrente->data==ricercato){
            return 1;
        }
        corrente=corrente->next;
    }
    return 0;
}

void list_delete(struct node** head, int key){
    struct node *temp=*head;
    struct node *prev=NULL;

    //Elimino la testa
    if(temp!=NULL && temp->data==key){
        *head=temp->next;
        free(temp);
        return;
    }

    //Cerco il nodo da eliminare tenendo riferimento il precedente(per modificare prev->next)

    while(temp!=NULL && temp->data!=key){
        prev=temp;
        temp=temp->next;
    }

    //nessun nodo ha come dato "key"
    if(temp==NULL){
        return;
    }
    prev->next=temp->next;
    free(temp);
}

int main(){
    struct node* head=NULL;
    int nodoCercato, new_data, nodoCancellato;


    list_insert(&head, new_data= 53);
    list_insert(&head, new_data= 86);
    list_insert(&head, new_data= 17);

    //inserimento nuovo nodo in lista come primo nodo
    list_display(head);
    list_insert(&head, new_data= 12);
    list_display(head);

    //cerco nodo tramite list_search()
    nodoCercato=86;
    if(list_search(&head, nodoCercato)){
        printf("\nNodo %d trovato", nodoCercato);
    }else{
        printf("\nNodo %d non trovato", nodoCercato);
    }

    nodoCercato=90;
    if(list_search(&head, nodoCercato)){
        printf("\nNodo %d trovato", nodoCercato);
    }else{
        printf("\nNodo %d non trovato", nodoCercato);
    }

    nodoCancellato=17;
    list_delete(&head, nodoCancellato);
    printf("\nNodo %d cancellato", nodoCancellato);

    //Funzione non ottimale, quindi non buona
    /*struct node* nodo1=NULL;
    struct node* nodo2=NULL;
    struct node* nodo3=NULL;

    //alloco la memoria
    nodo1=malloc(sizeof(struct node));
    nodo2=malloc(sizeof(struct node));
    nodo3=malloc(sizeof(struct node));

    //assegno i valori
    nodo1->data=17;
    nodo2->data=86;
    nodo3->data=53;

    //collego i nodi tra di loro
    nodo1->next=nodo2;
    nodo2->next=nodo3;
    nodo3->next=NULL;

    head=nodo1;

    stampaLista(head);*/

    return 0;
}