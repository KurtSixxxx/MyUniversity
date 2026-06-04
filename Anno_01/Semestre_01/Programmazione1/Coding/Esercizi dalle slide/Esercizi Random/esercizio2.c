/*Codificare un programma che stampi le prime N potenze di 2,
dove N `e un parametro scelto dall’utente (input da tastiera).
*/

#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("Inserisci un valore per N, al fine di cacolare le prime N potenze di 2: ");
    scanf("%d", &n);

    for(int i = 0; i <= n; i++){
        printf("2^%d = %.0f\n", i, pow(2, i));
    }
return 0;
}