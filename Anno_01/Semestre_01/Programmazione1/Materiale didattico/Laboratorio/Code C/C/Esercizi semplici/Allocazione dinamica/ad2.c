/*Esercizio 2: Uso di calloc()
Obiettivo: Alloca un array di 4 interi usando calloc(), e verifica che tutti i valori siano inizializzati a zero.
Poi modifica i valori e stampa.*/


//Includo <stdlib.h> per utilizzare la funzione calloc()
#include <stdio.h>
#include <stdlib.h>

int jmain(){
    
    //Alloco un array di 4 interi usando calloc.
    int *arr = (int*) calloc(4, sizeof(int));

    //Stampo tutti i valori per verificare che siano inzializzati a zero, il tutto tramite ciclo for.
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Adesso modifico i valori manualmente.
    arr[0] = 2;
    arr[1] = 4;
    arr[2] = 6;
    arr[3] = 8;
    arr[4] = 10;

    //Una volta modificati i valori li stampo
    for(int i = 0; i < 4; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    //Libero la memoria allocata.   
    free(arr); 

return 0;
}