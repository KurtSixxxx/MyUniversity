/*Calcolo della somma di una sequenza di numeri*/

#include <stdio.h>

//creo la funzione per effettuare il calcolo somma
int calcolo (int sequenza [], int lunghezza){

int somma = 0;

    for(int i = 0; i < lunghezza; i++){
        somma += sequenza[i];
    }

return somma; //chiedo il ritorno di "somma", ossia del risultato dovuto dalla funzione

}

int main(){

int lunghezza;

printf("Inserisci la lunghezza: "); //chiedo all'utente di inserire la lunghezza dell'array
scanf("%d", &lunghezza);

int sequenza[lunghezza]; //la sequenza di numeri avrà come lunghezza quella inserita dall'utente

printf("Inserisci gli elementi della sequenza: \n"); //chiedo all'utente di inserire gli elementi della sequenza di numeri
    for (int i = 0; i < lunghezza; i++) { //ho inizializzato un ciclo for
        scanf("%d", &sequenza[i]);
    }

int somma = calcolo(sequenza, lunghezza); // Chiamata corretta della funzione

printf("La somma è %d\n", somma); // Stampa corretta del risultato

return 0;

}