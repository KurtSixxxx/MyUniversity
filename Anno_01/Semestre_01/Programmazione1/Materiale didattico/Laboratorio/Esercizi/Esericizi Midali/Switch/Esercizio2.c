/*Chiedere all'utente di inserire l'età e calcolare il costo del biglietto del cinema in base alla seguente tabella:
Fino a 3 anni: gratuito
Da 4 a 12 anni: 5 euro
Da 13 a 17 anni: 8 euro
Da 18 a 65 anni: 12 euro
Oltre i 65 anni: 6 euro*/

#include <stdio.h>
int main(){

int eta;
float prezzo;

printf("Inserisci l'età per scoprire il prezzo del tuo biglietto: \n");
scanf("%d", &eta);

switch (eta){
    case 0 ...3:
    prezzo = 0;
    break;
    
    case 4 ... 12:
    prezzo = 5;
    break;
    
    case 13 ... 17:
    prezzo = 8;
    break;
    
    case 18 ... 65:
    prezzo = 12;
    break;
    
    default:
    prezzo = 6;
    break;
    
}

printf("Il prezzo del biglietto è €%.2f", prezzo);

return 0;

}