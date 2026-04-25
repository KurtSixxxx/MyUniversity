/*
Implementazione di una pila tramite un array
Le pile seguono la logica FIFO (First In, First Out), ciò significa che il primo elemento che viene inserito è l'ultimo che viene tolto, come in una pila di piatti.
Le funzioni principali delle pile sono 2:
- push: l'azione di inserimento di un elemento nelle pile
- pop: l'azione di rimozione di un elemento nelle pile
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LIMIT 5     // Abbiamo definito il limite di grandezza della pila, ossia 5
#define EMPTY (-1)  // Abbiamo definito "EMPTY" ossia il valore che indica quando la pila è vuota

int stack[LIMIT]; // Dichiariazione della pila come array e LIMIT come sua dimensione massima
int top = EMPTY;  // Indice che mi indica dove vengono inseriti ed estratti gli elementi della pila. Ossia la parte più in alto. In questo momento inizializzato ad EMPTY perché non è stato inserito nessun elemento.

// Push: funzione per inserire un nuovo elemento
// (Questa funzione è stata implemenetata con valore di ritorno booleano, ma può essere funzionale anche un implementazione di tipo void e con la funzione di printf() al posto di return)
bool push(int nuovoElemento) {
    if(top == LIMIT - 1)        // Se top == LIMIT - 1, ossia 4, allora sappiamo che non possiamo aggiungere nulla perché la pila è piena.
        return false;           // Overflow: lo stack è pieno, non posso aggiungere altro

    top++;                      //top viene incrementata prima perché il top prima è inizilizzato ad EMPTY(-1), da -1 passo a 0, ossia l'indice in cui posso iniziare ad aggiungere elementi.
    stack[top] = nuovoElemento; //Qui dico: "in stack di top metti il nuovoElemento"
    return true;                //return true se la funzione è andata a buon fine
}

// Pop: funzione per estrarre un elemento
int pop() {
    if(top == EMPTY)            // Con if controllo se la pila è vuota. Se lo è stai cercando di toglere elementi dalla pila ma la pila è vuota
        return EMPTY;           // Underflow: lo stack è vuoto, non posso cancellare nulla

    top--;                      //top viene decrementato, e passa all'indice precendete. Il valore che verrà restituito è quello che corrisponde all' indice di prima. Es: se top->i[4] = 12 allora top-- mi porta a top->i[3] = 11 e mi restituisce 12, ossia l'elemento cancellato.
    return stack[top + 1];      // Restituisco il valore cancellato
}


void printStack() {
    if (top == EMPTY)               //if verifica se la pila è vuota, se è così rimanda al printf() sotto
        printf("Stack vuoto!\n\n");

    else{                           //Se la pila non è vuota si passa alla stampa della pila stessa
        printf("\t  ↑↓  \n");
        for(int i = top; i >= 0; i--)   //Il ciclo for inizia da top e scorre indietro fino a 0. Questo siginifica che si parte dall'elemento più recente inserito nella pila e si scorre fino in fondo.
            if(stack[i] != EMPTY)       //Controllo per verificafre se l'elemento corrente in stack[i] non è uguale ad EMPTY
                printf("\t| %02d |\n", stack[i]);   //Se l'elemento è valido, viene stampato in un formato specifico. L'uso di %02d formatta l'intero con almeno due cifre: 2 sarà 02

        printf("\n");
    }
}


int main() {
    printStack();

    printf("Inserisco 15:\n");
    push(15);
    printStack();

    printf("Inserisco 6:\n");
    push(6);
    printStack();

    printf("Inserisco 2, 21 e 77:\n");
    push(2);
    push(21);
    push(77);
    printStack();

    if(!push(9))
        printf("Con push(9) si è verificato overflow, elemento non aggiunto!\nStato attuale pila:\n");
    printStack();

    pop();
    printf("Dopo il primo pop:\n");
    printStack();   // E' stato cancellato 9 che è proprio l'ultimo elemento che ho aggiunto = LIFO

    pop();
    printf("Dopo il secondo pop:\n");
    printStack();

    // Cancello tutti gli elementi
    printf("Cancello tutti gli elementi:\n");
    int i;
    while((i = pop()) != EMPTY)
        printf("\tHo cancellato %d\n", i);

    // Provo ad eliminare un elemento dallo stack vuoto
    if(pop() == EMPTY)
        printf("\nCon quest'ultimo pop() si è verificato underflow, non ci sono più elementi da cancellare!\n");

    return 0;
}