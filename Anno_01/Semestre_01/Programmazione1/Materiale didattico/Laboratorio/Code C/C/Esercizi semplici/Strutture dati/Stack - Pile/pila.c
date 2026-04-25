/*
La pila è un insieme di elementi che si può immaginare come una serie di elementi impilati tra di loro.
Ad esempio in un ristorante una serie di piatti sono posizionati uno sopra l'altro: quando dovrò andare ad aggiungerne uno lo andrò ad aggiungere in cima, quando dovrò toglierne uno andrò sempre a toglierlo dalla cima.
La pila segue il criterio LIFO: "Last In First Out" -> l'ultimo elemento aggiunto è il primo ad essere estratto.

Operazioni:
- PUSH: aggiunge un elemento
- POP: viene rimosso un elemento

La pila può essere implementata con array e liste.
____________________________________________________________________________
Partendo dalle definizioni contenute in data.h, data.c e single_ref_node.h, 
si definiscano le segg. funzioni prototipate nel file stack.h: 
 
-  void push(struct nodo **top, struct dato *d);
-  int pop(struct nodo **top, struct dato *d);
-  int isEmpty(struct nodo *top);
-  printStack(struct nodo *top);
*/

//IMPLEMENTAZIONE CON ARRAY

#include <stdio.h>
#include <stdbool.h>

#define LIMIT 5     // Definiamo la dimensione della pila (5 elementi)
#define EMPTY (-1)  // Definiamo la costante EMPTY con valore -1, indica che la pila è vuota


int stack[LIMIT]; // Dichiara un array stack di dimensione LIMIT (5), che funge da struttura dati per la pila
int top = EMPTY;  // Indice che mi indica l'ultimo elemento inserito
int nuovoElemento; // Variabile per salvare il valore del nuovoElemento da usare nelle funzioni

// Push: funzione per inserire un nuovo elemento
bool push(int nuovoElemento) { // Funzione per inserire un nuovo elemento nella pila. Restituisce true se l'operazione ha successo e false in caso di overflow.
    if(top == LIMIT - 1)       // Verifica se la pila è piena. Se top è uguale a LIMIT - 1 (5-1 = 4), significa che non ci sono più spazio per aggiungere nuovi elementi.
        return false;           // Overflow: lo stack è pieno, non posso aggiungere altro

    top++;                      // Incrementa l'indice top per spostare l'indice alla nuova posizione in cui inserire l'elemento
    stack[top] = nuovoElemento; // Dopo l'incremeto viene aggiunto l'elemento successivo
    return true;                // Operazione avvennuta con successo
}

// Pop: funzione per estrarre un elemento
int pop() {                     // Funzione per rimuovere l'elemento dalla cima della pila. Restituisce il valore dell'elemento rimosso
    if(top == EMPTY)            // Con questa riga verifichiamo se la pila è vuota
        return EMPTY;           // Underflow: lo stack è vuoto, non posso cancellare nulla (-1)

    top--;
    return stack[top + 1];      // Restituisco il valore cancellato (in questo caso 5)
}

void printStack() {   // Funzione per la stampa della pila
    if (top == EMPTY) // Se la pila è vuota, stampa "Stack vuoto!"
        printf("Stack vuoto!\n\n");

    else{
        printf("\t  ↑↓  \n");
        for(int i = top; i >= 0; i--) // Ciclo che itera dalla cima della pila fino al fondo per stampare ogni elemento, quindi va dall'alto verso il basso
            if(stack[i] != EMPTY) // Controlla se l'elemento è diverso da EMPTY (anche se in questa implementazione non sarebbe mai EMPTY dato che è la funzione di stampa della pila)
                printf("\t| %02d |\n", stack[i]); // Stampa l'elemento corrente nella pila. Viene usato 02 con lo specificatore puramente per estetica.

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