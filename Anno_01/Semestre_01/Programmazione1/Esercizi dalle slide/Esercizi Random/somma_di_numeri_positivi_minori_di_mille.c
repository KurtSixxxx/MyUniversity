/*Codificare in linguaggio C un programma che stampi a ritroso i numeri positivi pari minori o uguali a mille;
inoltre le iterazioni finiscono se la somma dei numeri precedentemente
stampati `e maggiore o uguale a centomila.
*/

#include <stdio.h>
int main(){
int sum = 0;

for(int i = 1000; i >= 0; i--){
    if(i % 2 == 0){
        sum += i;
        printf("%d\n", i);
        
        if(sum >= 100000){
        break;
        }
    }
}
printf("Somma dei numeri positivi minori o uguali a mille: %d", sum);
return 0;
}