/*Esercizio 1*/

#include <stdio.h>

int main(){

int x = 10;
int *p = &x;

printf("Valore: [%d], Indirizzo: [%p]", *p, p);

return 0;
}