/*Esercizio 1: Allocazione di un Array Dinamico*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n; //Questo valore corrisponde al numero di elementi dell'Array.
    printf("Inserisci il numero di elementi per l'array:\n");
    scanf("%d", &n);

    //Alloco dinamicamente l'array
    int *array = (int*) malloc (n * sizeof(int));

    //Verifico se l'allocazione è andata a buon fine.
    if (array == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        return 1;
    }

    //L'utente inserisce i valori dell'array.
    printf("Inserisci %d valori:\n", n);
    for (int i = 0; i < n; i++){
        scanf("%d", &array[i]);
    }

    //Stampo i valori.
    printf("Valori inseriti:\n");
    for (int i = 0; i < n; i++){
        printf("%d| ", array[i]);
    }
    printf("\n");

    //Libero la memoria.
    free(array);

    return 0; //Termina il programma con successo.
}