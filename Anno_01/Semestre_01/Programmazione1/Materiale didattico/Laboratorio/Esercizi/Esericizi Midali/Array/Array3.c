/*Ricerca di un elemento in un array*/

#include <stdio.h>

int main (){
int numeri[] = {2, 4, 6, 8, 10};
int lunghezza = sizeof(numeri)/sizeof(numeri[0]);
int numeroDaCercare;
int trovato = 0; //booleano.

printf("Inserisci un numero da cercare: ");
scanf("%d", &numeroDaCercare);

for(int i = 0; i < lunghezza; i++){
    if (numeri[i] == numeroDaCercare){ //se i numeri sono uguali al numero da cercare allora trovato è 1, ossia vero.
        trovato = 1; //booleano.
        break; //break per uscire dal ciclo.
    }
} //inserisco if fuori dal for per evitare ripetizioni di stampa.
if (trovato) {
        printf("Il numero è presente nell'array.\n");
    } else {
        printf("Il numero non è presente nell'array.\n");
    }

    return 0;
}