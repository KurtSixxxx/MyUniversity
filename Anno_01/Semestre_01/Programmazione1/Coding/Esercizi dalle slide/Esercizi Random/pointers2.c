/*
 * Homework H14.2.
 *
 * 1. Dichiarare un array D di 10 elementi double ed un array A di 10
 * elementi int.
 * 2. Inizializzare gli elementi di D ed A con numeri pseudo-casuali negli
 * intervalli [1.25, 90] [10, 50] rispettivamente. NB: Usare sia
 * aritmetica dei puntatori che notazione con parentesi quadre.
 * 3. Dichiarare due variabili puntatore ptr_D e ptr_A di tipo double e int
 * rispettivamente, ed inizializzare tali puntatori in modo che puntino
 * ai primi elementi di D ed A rispettivamente.
 * 
 * 4. Codificare opportunamente un ciclo che stampi, su ogni riga di
 * output
 * i) sia il valore, che
 * ii) l’indirizzo in memoria, di ogni
 * elemento di indice dispari dell’array D, e di ogni elemento di indice
 * pari dell’array A. In particolare:
 * 
 * Per stampare i dati, impiegare sia le variabili puntatore che i
 * nomi degli array (ovvero le variabili che rappresentano gli
 * array); usare sia aritmetica dei puntatori (e operatore '*') che
 * notazione con parentesi quadre in entrambi i casi;
 * 
 * - Per stampare gli indirizzi, impiegare sia le variabili puntatore
 * che i nomi degli array (ovvero le variabili che rappresentano gli
 * array); usare sia aritmetica dei puntatori che notazione con
 * parentesi quadre (e operatore '&');
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 
 int main(){

    srand(time(0));

    //Inizializzazione degli intervalli di D e A
    // D = [1.25, 90]
    // A = [10, 50]

    double d[10];
    int a[10];

    double n1 = 0;
    int n2 = 0;

    double high_d = 90;  //b
    double low_d = 1.25; //a
    printf("\n");

    for(int i = 0; i < 10; i++){
        n1 = ((double)rand()/ RAND_MAX) * (high_d - low_d) + low_d;
            // ((double) rand() / RAND_MAX) * (b - a) + a 
        d[i] = n1;
    }
    for(int j = 0; j < 10; j++){
        n2 = rand()%(50 - 10 + 1) + 10;
        a[j] = n2;
    }

    for(int i = 0; i < 10; i++){
        printf(" %.2f|", d[i]);
    }
    
    printf("\n");
    printf("\n");
    
    for(int j = 0; j < 10; j++){
        printf(" %d|", a[j]);
    }

    printf("\n");

    double *ptr_D = d;
    int *ptr_A = a;

    printf("\n");
    printf("Array D tramite puntatori [Solo dispari]\n");
    for(int i = 0; i < 10; i++){
        if(i % 2 == 1){
        printf("Valore mediante puntatore: %.2f \t Indirizzo mediante puntatore: %p\n", *( ptr_D + i), ptr_D[i]);
        }
    }

    printf("\n");
    printf("Array A tramite puntatori [Solo pari]\n");
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
        printf("Valore mediante puntatore: %d \t\t Indirizzo mediante puntatore: %p\n", *( ptr_A + i), ptr_A[i]);
        }
    }
    
    printf("---------------------------------------------------------------------------------------\n");
    printf("\n");
    printf("Array D tramite variabili [Solo dispari]\n");
    for(int i = 0; i < 10; i++){
        if(i % 2 == 1){
        printf("Valore mediante variabili: %.2f \t Indirizzo mediante variabili: %p\n", d[i], (void*)&d[i]);
        }
    }

    printf("\n");
    printf("Array A tramite variabili [Solo pari]\n");
    for(int i = 0; i < 10; i++){
        if(i % 2 == 0){
        printf("Valore mediante variabili: %d \t\t Indirizzo mediante variabili: %p\n", a[i], (void*)&a[i]);
        }
    }

    return 0;
 }