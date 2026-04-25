// Chiedere all'utente di inserire l'età e calcolare il costo del biglietto del cinema in base alla seguente tabella:
// Fino a 3 anni: gratuito
// Da 4 a 12 anni: 5 euro
// Da 13 a 17 anni: 8 euro
// Da 18 a 65 anni: 12 euro
// Oltre i 65 anni: 6 euro

#include <stdio.h>
#include <locale.h>

int main (){

    setlocale(LC_ALL, "it_IT.UTF8");

    int eta;

    printf("Inserire età: ");
    scanf("%d", &eta);

    switch (eta){
        case 0 ... 3:
        printf("Biglietto gratuito");
        break;

        case 4 ... 12:
        printf("5 euro");
        break;

        case 13 ... 17:
        printf("8 euro");
        break;

        case 18 ... 65:
        printf("12 euro");
        break;
        
        case 100 ... 200:
        printf("Sei morto...");
        break;

        default:
        printf ("6 euro");

    }

    return 0;
}