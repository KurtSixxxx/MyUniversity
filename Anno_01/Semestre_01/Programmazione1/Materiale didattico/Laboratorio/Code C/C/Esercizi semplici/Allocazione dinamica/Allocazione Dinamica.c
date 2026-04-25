/*Panoramica sull'Allocazione Dinamica
In C, puoi allocare memoria dinamicamente usando le funzioni della libreria standard <stdlib.h>. Le principali funzioni sono:
*/
malloc(size_t size) //Alloca un blocco di memoria di dimensione size byte e restituisce un puntatore al blocco. La memoria non viene inizializzata.

calloc(size_t num, size_t size) //Alloca un blocco di memoria per un array di num elementi, ciascuno di dimensione size, e inizializza la memoria a zero.

realloc(void *ptr, size_t size) //Ridimensiona un blocco di memoria precedentemente allocato. Se ptr è NULL, si comporta come malloc.

free(void *ptr) //ibera un blocco di memoria precedentemente allocato.