/*
 * Homework H14.3.
 *
 * 1. Dichiarare un array V di N double, con N=200;
 * 2. Inizializzare gli elementi di V con numeri pseudo-casuali
 * nell’intervallo [10, 50]. NB: Usare sia aritmetica dei puntatori che
 * notazione con parentesi quadre.
 * 3. Dichiarare un puntatore al tipo const double. Mediante tale
 * puntatore, stampare gli elementi con indici che siano non divisibili
 * per due e non divisibili per tre.
 * 4. Dichiarare un puntatore const al tipo double. Mediante tale
 * puntatore, sostituire tutti gli elementi dell’array che abbiano gli
 * indici specificati al punto precedente, con un valore double
 * pseudo-casuale in [100, 200];
 *
 * 5. Per i precedenti due punti, per l’accesso agli elementi dell’array,
 * usare i) sia la notazione con parentesi quadre che ii) la notazione
 * che fa uso di aritmetica dei puntatori;
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 #define N 200 //Definisco N = 200

 int main() {
    srand(time(0)); //Attivo il seme della randomizzazione
    double v[N]; //Dichiaro l'array double v
    double high_v = 50; //Dichiaro l'estremo alto dell'intervallo
    double low_v = 10; //Dichiaro l'estremo basso dell'intervallo

    for(int i = 0; i < N; i++){ //Utilizzo un ciclo per riempire l'array
        v[i] = ((double)rand() / RAND_MAX)*(high_v - low_v) + low_v; //Inserisco valori random. Per l'esattezza N = 200 valori
    }
    
    printf("|");
    for(int i = 0; i < N; i++){ //Stampo l'intero array
        if(i % 20 == 0){printf("\n");} //Per una visione più pulita della stampa, ogni 20 celle di array vado a capo per poter visulizzare correttamente tutti i valori
        printf("%.2f|", v[i]);
    }


    printf("\n");
    printf("\n");
    printf("Stampa con puntatore a costante double: \n");
    const double *p = &v[0];
    for(int i = 0; i < N; i++){
        if(i % 50 == 0){printf("\n");}
        if((i % 2 !=0) && (i % 3 != 0)){
            printf(" %.2f ", *(p+i));
        }
    }

    double high_v2 = 200; //Dichiaro l'estremo alto dell'intervallo
    double low_v2 = 100; //Dichiaro l'estremo basso dell'intervallo
    double * const pp = &v[0];
        printf("\n");
        printf("\n");
        printf("Stampa con puntatore costante double: \n");

      for(int i = 0; i < N; i++){
        if(i % 50 == 0){printf("\n");}
        if((i % 2 !=0) && (i % 3 != 0)){
            pp[i] = ((double)rand() / RAND_MAX)*(high_v2 - low_v2) + low_v2;
            printf(" %.2f ", *(pp+i));
        }
    }
    return 0;
 }