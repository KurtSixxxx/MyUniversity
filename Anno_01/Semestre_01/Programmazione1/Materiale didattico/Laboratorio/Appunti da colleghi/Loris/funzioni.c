#include <stdio.h>
#include <stdlib.h>

/*void operazioni(){
    int n;
    int k;
    int somma=0;
    int moltiplicazione=0;
    float media=0;

    printf("Inserisci n:");
    scanf("%d", &n);
    printf("Inserisci k:");
    scanf("%d", &k);

    somma=n+k;
    moltiplicazione=n*k;
    media=(n+k)*1.0/2;

    printf("\nSomma:%d", somma);
    printf("\nMoltiplicazione:%d", moltiplicazione);
    printf("\nMedia:%.2f", media);
}*/

int somma(int x, int y); //se la definizione sta sotto il main, ma conviene metterlo sopra, si fa solo per convenienza

int main(){

    int z = somma(100, 51);
    somma(10, 20);  //x y argomenti
    printf("%d", z);
    return 0;
    //operazioni();
}

int somma(int x, int y){  //x y parametri

    int risultato= x+y+100;
    return risultato;
} 