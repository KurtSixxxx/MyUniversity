// Utilizzare un ciclo for per stampare i numeri pari da 1 a 20.

#include <stdio.h>

int main (){
    
    int i;
// Partiamo da 2 poiché da qui partono i numeri pari.
// Dopo incrementiamo tramite += ossia i = i + 2, questo operatore somma 2 a i e poi lo assegna.
    for (i = 2; i <= 20; i += 2){
        printf("%d \n", i);
    }

    return 0;
}