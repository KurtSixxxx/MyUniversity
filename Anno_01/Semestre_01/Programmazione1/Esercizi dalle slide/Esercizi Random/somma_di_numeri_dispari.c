/*Codificare in linguaggio C un programma che produca la somma dei numeri interi dispari da 1 a 99,
facendo uso del costrutto for.
Dalla somma vanno esclusi i numeri divisibili per tre.
*/

#include <stdio.h>
int main(){
int sum = 0;                                                    //variabile somma
for(int i = 1; i <= 99; i++){                                   //per i = 0, finchè i è minore o uguale a 99 incrementa
    if(i % 2 == 1 && i % 3 != 0){                               //se i è dispari (ossia divisibile per 2 con resto almeno di 1) e non è divisibile per 3
        sum += i;                                               //allora sommalo alla variabile 'sum'
        printf("N: %d\n", i);                                   //e stampa il singolo numero dispari
    }
}

printf("Somma con numeri divisibili per tre: %d\n", sum);       //Stampa la sommma dei numeri dispari, memorizzato nella variabile 'sum'


return 0;
}