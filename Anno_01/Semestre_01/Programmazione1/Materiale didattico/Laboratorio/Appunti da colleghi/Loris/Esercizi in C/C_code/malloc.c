/* Esercizio 1: Allocazione con malloc
Scrivi un programma che:
- Chiede all'utente di inserire il numero di interi che desidera memorizzare.
- Utilizza malloc per allocare memoria per quell'array.
- Chiede all'utente di inserire i valori degli interi.
- Stampa i valori inseriti.
- Dealloca la memoria utilizzata.
Suggerimento: Assicurati di controllare se l'allocazione è andata a buon fine. */
/*_______________________________________________________________________________________________________________________________________*/

#include <stdio.h>
#include <stdlib.h>

int main(){

    int dim;
    printf("Inserisci la dimensione dell'array:\n");
    scanf("%d", &dim);

    int *a = (int*) malloc(dim * sizeof(int));
    if (a == NULL){
        printf("Allocazione fallita.\n");
        return 1;
    }

    printf("Inserisci i valori degli interi:\n");
    for(int i = 0; i < dim; i++){
        scanf("%d", &a[i]);
    }
    
    printf("Stampa dell'array:\n");
    for(int i = 0; i < dim; i++){
        printf("[%d]", a[i]);
        }

    free(a); 

    return 0;
}