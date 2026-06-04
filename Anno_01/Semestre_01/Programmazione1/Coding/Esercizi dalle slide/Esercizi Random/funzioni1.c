/*Homework H15.2
Modificare il precedente esercizio affinché la funzione prenda input, oltre alla coppia di interi short, anche un puntatore ad un numero short unsigned
La funzione dovrà scrivere il risultato della computazione nella locazione di memoria rappresentata dal puntatore in input.
La funzione non avrò alcun tipo di ritorno.
Invocare la funzione all'interno della funzioner main() con alcuni valori di test. Stampare opportunamente i risultati.*/

#include <stdio.h>
#include <limits.h>

void valore_assoluto(short a, short b, short unsigned *cc) {
    short tmp = a * b; //Dato che si parla di short unsigned è importante trovare un modo di preservare il segno nel caso di "Valore assoluto tra un positivo e un negativo" in cui il risultato è negativo e poi reso positivo tramite il valore assoluto. Per questo dobbiamo usare una variabile che preservi il risultato, ossia un int. Avremmo potuto usare uno short ma con valori grandi il prodotto potrebbe essere troppo grande e causare overflow!
	if(tmp < 0){ //Se prodotto è minore di 0, ossia negativo
		*cc = -tmp; //Il puntatore cc scrive nella variabile corrispondente all'indirizzo che ha puntato il valore di 'prodotto'. -(-tmp) = tmp.
	} else {
		*cc = tmp; //la stessa cosa fa qui
	}
}

int main() {
	short unsigned risultato; //dichiaro la variabile risultato 
	short unsigned *cc = &risultato; //e faccio puntare al puntatore cc l'indirizzo di risultato, cosicchè ogni valore che assume tramite la funzione valore_assoluto lo scrive dentro la variabile risultato
	short a = 2;
	short b = 3;
	valore_assoluto(a, b, cc); //chiamo la funzione con i due short che contengono i valori da moltiplicare e chiamo il puntatore da utilizzare, ossia *cc
	printf("Valore assoluto tra due positivi: %hu\n", risultato); //quando stampo, passo come variabile la variabile 'risultato', che contiene appunto il valore inserito dal puntatore che lui stesso ha prelevato dalla funzione. diciamo che *cc fa da ponte tra la funzione e la variabile risultato

	short c = 2;
	short d = -3;
	valore_assoluto(c, d, cc);
	printf("Valore assoluto tra un positivo e un negativo: %hu\n", risultato);

	short e = -6;
	short f = -7;
	valore_assoluto(e, f, cc);
	printf("Valore assoluto tra due negativi: %hu\n", risultato);

	short g = 0;
	short h = 0;
	valore_assoluto(g, h, cc);
	printf("Valore assoluto tra due zeri: %hu\n", risultato);

	short i = SHRT_MIN;
	short j = SHRT_MAX;
	valore_assoluto(i, j, cc);
	printf("Valore assoluto tra due numeri grandi: %hu\n", risultato);

	return 0;
}