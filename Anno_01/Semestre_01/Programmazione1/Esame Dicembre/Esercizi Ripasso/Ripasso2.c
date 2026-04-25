#include <stdio.h>
#include <stdlib.h>

/*
1. Alloca dinamicamente un blocco di memoria sufficiente per contenere un valore di tipo double utilizzando la funzione malloc().
2. Esegua il casting del puntatore generico (void *) restituito da malloc() al tipo desiderato.
3. Dopo aver utilizzato la memoria allocata, liberi esplicitamente il blocco di memoria utilizzando la funzione free().
4. Spiega quale header è necessario includere per utilizzare malloc() e free().
*/

int main(){
    double *a = (void*)malloc(sizeof(double));
    if(a == NULL) printf("Allocazione Fallita");
    *a = 11.5;
    printf("%.1f", *a);
    free(a);
    a = NULL;
}