/*
Codificare una funzione in C che prenda in input un array di caratteri ed un parametro che indica la sua lunghezza.
La funzione dovrà riempire l'array di caratteri con caratteri pseudocasuali nell'intervallo [a-z].
La funzione dovrà resitutire il numero di vocali all'interno della stringa.
Per l’accesso in scrittura agli elementi dell’array di caratteri, usare sia la notazione con ’*’ e aritmetica dei puntatori, sia la notazione
con parentesi quadre.
NB: porre attenzione al carattere di terminazione stringa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int string_lenght(int n, char c[n]){
    srand(time(0)); //inizializziamo il random
    int contatorevocali = 0; //imposto un contatore per il totale delle vocali

    for(int i = 0; i < n; i++){ //for per inseirire i caratteri dell'intervallo nel 
        *(c+i) = (char)(rand() % ('z' - 'a' + 1) + 'a'); //alla posizione i (di i che va da 0 a n) inserisco un carattere casuale
    }

    printf("Stringa casuale: "); //Stampo la stringa
    for(int i = 0; i < n; i++){
        printf("%c", c[i]);
    }

    *(c + n) = '\0';

    printf("\n");

    for(int i = 0; i < n; i++){ //faccio il controllo delle vocali
        if((c[i] == 'a') || (c[i] == 'e') || (c[i] == 'i') || (c[i] == 'o') || (c[i] == 'u')){
            contatorevocali += 1; //se trovo una vocale la aggiungo alla variabile contatore
        }

    }
    return contatorevocali; //ritorno la somma del contatore con le varie vocali
}

int main(){
    int n = 10;
    char c[n];

    int risultato = string_lenght(n, c);
    printf("Numero vocali: %d", risultato);

    return 0;
}