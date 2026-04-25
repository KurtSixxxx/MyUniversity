/*Ricerca e conteggio delle occorrenze di un elemento in un array*/

#include <stdio.h>

int main (){
    int array []= {1, 1, 5, 7, 9};
    int lunghezza = sizeof(array)/sizeof(array[0]);
    int contatore = 0;
    int numeroDaCercare;
    
printf("Inserisci un numero: ");
scanf("%d", &numeroDaCercare);

for(int i = 0; i < lunghezza; i++){
    if(array[i] == numeroDaCercare)
    contatore++;
}

printf("Il numero di occorrenze è %d", contatore);

return 0;
}