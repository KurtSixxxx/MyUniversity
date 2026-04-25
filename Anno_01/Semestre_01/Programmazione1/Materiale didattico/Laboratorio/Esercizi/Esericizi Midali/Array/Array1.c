/*Calcolo della somma degli elementi di un array*/

#include <stdio.h>

int main (){

    int numeri[] = {10, 4, 5, 9};
    int lunghezza = sizeof(numeri)/sizeof(numeri[0]);
    int somma = 0;

    for(int i = 0; i < lunghezza; i++)
    {
        somma += numeri[i];
    }
printf("%d\n", somma);

return 0;

}