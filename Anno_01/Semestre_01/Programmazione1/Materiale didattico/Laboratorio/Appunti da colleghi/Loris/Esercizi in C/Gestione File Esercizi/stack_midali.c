#include <stdio.h>
#include <stdlib.h>

#define MAX 100

//DEFINIZIONE DELLA STRUTTURA STACK
struct Stack {
    int top;                // Indice dell'elemento in cima alla pila
    int elementi[MAX];      // Array per memorizzare gli elementi della pila
};

//Funzioni per Gestire lo Stack

//1. Inizializzazione dello Stack
void init_stack(struct Stack* stack) {
    stack->top = -1;        // Imposta 'top' a -1 per indicare che la pila è vuota
}

//2. Operazione Push
void push(struct Stack* stack, int valore) {
    if(stack->top >= MAX - 1){      // Controlla se la pila è piena
        printf("Stack Overflow\n"); // Stampa un messaggio di errore se la pila è piena
        return;                     // Esci dalla funzione
    }
    stack->elementi[++(stack->top)] = valore;   // Incrementa 'top' e inserisce il valore nella pila
}

//3. Operazione Pop
int pop(struct Stack* stack) {
    if(stack->top < 0){                 // Controlla se la pila è vuota
        printf("Stack Underflow\n");    // Stampa un messaggio di errore se la pila è vuota
        return -1;                      // Restituisce -1 per indicare che non ci sono elementi da rimuovere
    }
    return stack->elementi[(stack->top)--]; // Restituisce l'elemento in cima alla pila e decrementa 'top'
}

//4. Operazione Peek
int peek(struct Stack* stack) {
    if(stack->top < 0){                 // Controlla se la pila è vuota
        printf("Stack is empty\n");     // Stampa un messaggio di errore se la pila è vuota
        return -1;                      // Restituisce -1 per indicare che non ci sono elementi nella pila
    }
    return stack->elementi[stack->top]; // Restituisce l'elemento in cima alla pila senza rimuoverlo
}

int main() {
    struct Stack stack;                                 // Dichiarazione della variabile 'stack' di tipo 'struct Stack'
    init_stack(&stack);                                 // Inizializza la pila

    push(&stack, 10);                                   // Aggiunge 10 alla pila
    push(&stack, 20);                                   // Aggiunge 20 alla pila
    push(&stack, 30);                                   // Aggiunge 30 alla pila

    printf("Elemento in cima: %d\n", peek(&stack));     // Mostra l'elemento in cima alla pila

    printf("Elemento rimosso: %d\n", pop(&stack));      // Rimuove e mostra l'elemento in cima della pila
    printf("Elemento rimosso: %d\n", pop(&stack));      // Rimuove e mostra l'elemento in cima della pila

    return 0;                                           // Termina il programma con successo
}