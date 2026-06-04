#include <stdio.h>
int main(){
    int a, b, c, k;
    printf("Inserisci un valore per a: \n");
        scanf("%d", &a);
    printf("Inserisci un valore per b: \n");
        scanf("%d", &b);
    printf("Inserisci un valore per c: \n");
        scanf("%d", &c);
    printf("Inserisci un valore per k: \n");
        scanf("%d", &k);
        
    if(a != c && k > 8){
        b = a + c;
        printf("Caso 1: %d\n", b);
    }else if(a == c && k < 8){
        a = c - b;
        printf("Caso 2: %d\n", a);
    }else{
        printf("Caso else: %d\n", (a+b+c)/3);
    }
    a = b = c = 0;
    printf("Valori finali -> a: %d, b: %d, c: %d\n", a, b, c);

    return 0;
}