/*Esercizio 2: Puntatori e Array
Scrivi un programma in C che:

Dichiara un array di 5 interi e lo inizializza.
Dichiara un puntatore a un intero e lo fa puntare al primo elemento dell'array.
Usa il puntatore per iterare sull'array e stampare ogni elemento.*/

#include <stdio.h>

int main(){

    int array[5] = {3, 6, 9, 12, 15}; //Dichiaro un array di 5 interi e lo inizializzo

    int *ptr_array = &array[0]; //Dichiaro un puntatore e lo faccio puntare al primo elemento dell'array.

    // Calcolo della lunghezza dell'array
    int length = sizeof(array) / sizeof(array[0]);

    // Iterazione sull'array utilizzando il puntatore
    for(int i = 0; i < length; i++) {
        printf("Elemento %d: %d\n", i+1, *ptr_array);
        ptr_array++; // Incrementa il puntatore per passare al prossimo elemento
    }
return 0;
}