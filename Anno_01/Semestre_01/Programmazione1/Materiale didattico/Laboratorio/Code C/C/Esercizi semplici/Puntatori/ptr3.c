/*Esercizio: Puntatori e Array di Float
Scrivi un programma in C che:

Dichiari un array di 6 numeri in virgola mobile (float) e lo inizializzi con valori a tua scelta.
Dichiari un puntatore a float e lo faccia puntare al primo elemento dell'array.
Usa il puntatore per iterare sull'array e stampare ogni elemento. Durante l'iterazione,
calcola e stampa anche la somma totale degli elementi dell'array. */

#include <stdio.h>

int main(){

    float array[6] = {1.2, 2.2, 3.3, 4.4, 5.5, 6.6}; //Dichiaro un array di 6 elementi float.

    float *ptr_arr = &array[0]; //Dichiaro un puntaotre a float. Poiché un array è puntatore stesso, inoltre alla prima cella, non indico l'indice.

    int lunghezza = sizeof(array)/sizeof(array[0]); //Calcolo la lunghezza dell'array dividendo il totale dei byte per i byte di una singola cella.

    float somma = 0; // Inizializzo la somma a 0.

    for(int i = 0; i < lunghezza; i++){
        printf("Contenuto della cella di indice %d: [%.1f]\n", i, *ptr_arr);
        somma += *ptr_arr; // Aggiungo il valore corrente alla somma.
        ptr_arr++;
    }

printf("Somma: %.1f\n", somma);

return 0;
}
