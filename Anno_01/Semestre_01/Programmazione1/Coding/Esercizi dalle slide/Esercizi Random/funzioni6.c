#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int numeroColonne(int n, int m, int a[n][m], double y){ //Dichiaro il tipo di ritorno, il nome funzione e i parametri formali

    int b[n]; //Dichiaro l'array in cui inserire i valori prelevati da ogni colonna
    int valori = 0; //Con questa variabile raccolgo i valori prelevati da ogni colonna
    double media = 0; //Mentre con questa variabile raccolgo la media di ogni colonna
    int numeroColonne = 0; //Questo sarà il valore che dobbiamo restituire, ossia il numero di colonne la cui media aritmetica sia minore o uguale a y

    for(int j = 0; j < m; j++){ //Questi sono due cicli for annidati utili ad iterare la matrice e prelevare gli elementi di ogni colonna inserendoli in un vettore
        valori = 0; //Ed infine la azzero
        for(int i = 0; i < n; i++){
            b[i] = a[i][j]; //Inserisco gli elementi di ogni cella della colonna in un vettore
            valori += b[i]; //Sommo i valori in una variabile per contenere tutti i valori
        }
        media = (double)valori / n; //Qui sposto i valori in un'altra variabile perché "valori" deve essere azzerata per raccogliere nuovi valori e faccio la media, ossia (somma di ogni valore) / n, n è la misura delle celle di colonna disponibili
        

        if(media <= y){ //Se la media è minore o uguale a y
        numeroColonne += 1; //Inserisco +1 nel conteggio delle colonne che hanno la media minore o uguale a y
        }
    }

    return numeroColonne;
}

int main(){
    srand(time(0)); //Dobbiamo inizializzare il seme per poter riempire la matrice con elementi a piacere
    int n = 5, m = 5;  //Dichiariamo le dimensioni, per comodità uso una matrice quadrata
    int a[n][m]; //Dichiariamo l'array
    //double y = 75; //Dichiaro il valore double

    /*for(int i = 0; i < n; i++){ //Uso un ciclo for per inserire i valori pseudocasuali nell'array 
        for(int j = 0; j < m; j++){
            a[i][j] = rand() % (175 - 75 + 1) + 75;
        }
    }

    int risultato = numeroColonne(n, m, a, y); //Chiamo la funzione nella variabile risultato
    printf("Risultato: %d", risultato);*/

    printf("=== TEST CON RANGE 50-100 (media ~75) ===\n");
    // Range 1: Valori piccoli (media ~75)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] = rand() % 51 + 50;   // 50-100
        }
    }
    
    double test_values[] = {75, 125, 175, 225, 300};
    for(int i = 0; i < 5; i++) {
        int risultato = numeroColonne(n, m, a, test_values[i]);
        printf("y=%-5.0f: %d colonne\n", test_values[i], risultato);
    }
    
    printf("\n=== TEST CON RANGE 75-175 (media ~125) ===\n");
    // Range 2: Valori medi (media ~125)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] = rand() % 101 + 75;  // 75-175
        }
    }
    
    for(int i = 0; i < 5; i++) {
        int risultato = numeroColonne(n, m, a, test_values[i]);
        printf("y=%-5.0f: %d colonne\n", test_values[i], risultato);
    }
    
    printf("\n=== TEST CON RANGE 125-275 (media ~200) ===\n");
    // Range 3: Valori grandi (media ~200)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            a[i][j] = rand() % 151 + 125; // 125-275
        }
    }
    
    for(int i = 0; i < 5; i++) {
        int risultato = numeroColonne(n, m, a, test_values[i]);
        printf("y=%-5.0f: %d colonne\n", test_values[i], risultato);
    }

    return 0;
}