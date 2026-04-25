/*
Le code, o "queue", sono strutture dati che seguono il principio FIFO (First-In, First-Out), ovvero "primo ad entrare, primo ad uscire".
Questo significa che l'elemento inserito per primo nella coda sarà anche il primo ad essere rimosso.
Si può pensare ad una coda come la fila in un ufficio postale: chi arriva per primo viene servito per primo.
Esistono due metodi principali per implementare le code in C:

● Utilizzando un array: questo metodo ha la limitazione della dimensione fissa dell'array.
Per ovviare a questo problema, si può definire una costante che rappresenta il limite massimo di elementi.
La gestione della coda avviene tramite una variabile "Tail" che tiene traccia dell'indice dove inserire il prossimo elemento.
L'inserimento (enqueue) avviene in posizione "Tail", e l'estrazione (dequeue) avviene in posizione 0.

● Utilizzando le liste concatenate: questo metodo non ha la limitazione della dimensione fissa.
L'implementazione con liste concatenate offre maggiore flessibilità ma richiede una gestione più complessa dei puntatori.

Nel caso di implementazione con array, è necessario gestire due situazioni particolari:
● Overflow: si verifica quando si tenta di inserire un elemento in una coda piena. In questo caso, la funzione di inserimento restituisce un valore "false" (o un messaggio di errore).
● Underflow: si verifica quando si tenta di estrarre un elemento da una coda vuota. In questo caso, la funzione di estrazione restituisce un valore speciale, come -1 o "Empty".
*/

//IMPLEMENTAZIONE "FACILE"

#include <stdio.h>
#include <stdbool.h>

#define LIMIT 5 //Definiamo una costante limit

int queue[LIMIT] //Definiamo un array "coda" di dimensione limit
int tail = 0; //Indice che indica da dove inserire
/*
'tail' è un indice che tiene traccia della posizione degli ultimi elementi inseriti nella coda. Viene inizializzato a zero, questo significa che l'ultimo elemento aggiunto assumerà posizione nell'array indicata dall'indice - che parte da 0 - e ad ogni inserimento 'tail' viene incrementato di 1 per indicare la prossima posizione disponibile nell'array coda.
Un altro compito di 'tail' è quello di verificare se la coda è piena. Se 'tail' raggiunge il valore di LIMIT significa che non c'è spazio per i nuovi elementi.
*/

// Enqueue: funzione per inserire un nuovo elemento
bool enqueue(int nuovoElemento){
    if(tail == LIMIT)      //Se tail è uguale a LIMIT si verifica overflow
    return false;

    queue[tail] = nuovoElemento;
    tail++;
    return true;
}

// Dequeue: funzione per estrarre un elemento
int dequeue(){
    if(tail == 0)       //Se tail è uguale a 0 vuol dire che non ci sono elementi da estrarre, quindi si tratta di underflow
    return -1;

    int deleted = queue[0];     //Salvo il primo elemento all'indice 0, ossia quello che voglio estrarre, perché tutti gli altri devono scorrere

    //Cambio gli indici degli elementi

}for(int i = 0; i < tail-1; i++){
    queue[i] = queue[i+1];

    tail--;     //Decremento tail per far indicare la posizione dove inserire il nuovo elemento
    return deleted;
}