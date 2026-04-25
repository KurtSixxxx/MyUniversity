//Liste in C - Passaggi

//1. Creazione di un nodo
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data; //Dato effettivo di ogni singolo nodo
    struct node* next; //Next è il puntatore, ossia il collegamento tra nodi
}

//2. Inizializzazione dei nodi
int main(){
    struct node* testa; //Puntatore aalla testa della lista
    struct node* nodo1 = NULL; //Puntatore al primo nodo
    struct node* nodo2 = NULL; //Puntatore al secondo nodo
    struct node* nodo3 = NULL; //Puntatore al terzo nodo
//Qui si dichiarano dei puntatori a nodi
//Inizialmente i nodi vengono impostati a 'NULL' (Non puntano a nessuna area di memoria)

//3. Allocazione della memoria dinamica
nodo1 = malloc(sizeof(struct node));
nodo2 = malloc(sizeof(struct node));
nodo3 = malloc(sizeof(struct node));
/*Inseriamo nella memoria dinamica delle 'struct node'.
Malloc restituirà un puntaore a questa memoria.
Ora i nodi possono essere memorizzati*/

//4. Assegnazione dei valori ai nodi
nodo1->data = 2;
nodo2->data = 4;
nodo3->data = 6;
/*L'arrow operator (->) viene utilizzato per accedere ai campi di struttura tramitr puntatore.
ES: nodo->data accede al campo data del nodo.*/

//5. Collegamento dei nodi
nodo1->next = nodo2;
nodo2->next = nodo3;
nodo3->next = NULL;
/*Qui stiamo dicendo quali saranno i 'next' di ogni nodo.
Quindi in nodo1 avremo 'data = 2', e in 'next' avremo l'indirizzo di nodo2 */

//6. Assegnazione della testa alla lista
testa = nodo1;
/*La testa avrà come indirizzo quella del primo nodo*/

//7. Stampa della lista
printLinkedlist(testa);

//8. Liberazione della memoria allocata
free(nodo1);
free(nodo2);
free(nodo3);

return 0;
}
/*Qui viene chiamata la funzione per stampare la lista*/

// Funzione per stampare la lista
void printList(struct node *p){ //Void indica che la funzione non restituisce valori. 'p' è un puntatore al nodo1.
    while (p != NULL) { //Il ciclo continua finché p non è NULL. Quando lo è significa che abbiamo raggiunto la fine della lista.

        if(p->next != NULL) //Se p->next non è NULL significa che il nodo corrente non è l'ultimo della lista
        printf("|%d| -> ", p->data); //Quindi stampiamo il |valore| per mostrare che c'è un collegamento con il nodo successivo
        else
        printf("|%d|", p->data); //Se invece p->next è NULL signiffica che siamo all'utlimo nodo della lista. Quindi stampiamo il valore senza freccia dato che non ci sono nodi successivi.

        p = p->next; //Aggiorna p per puntare al nodo successivo della lista,
    }
    //Il ciclo while continua finché ci sono nodi da stampare. Una volta che p diventa NULL (quando non ci sono più nodi), il ciclo termina e la funzione finisce.
}