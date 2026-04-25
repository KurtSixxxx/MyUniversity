/*Esercizio 4*/

#include <stdio.h>

int main(){

// Dichiaro un array di 10 caratteri
char array[11] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', '\0'};

// Con un ciclo for stampo tutti i caratteri prima della modifica
for (int i = 0; i<10; i++){
printf("Prima della modifica: %c\n", array[i]);
}

// Dichiaro il puntatore e lo faccio puntare all'array
char *ptr = array;

printf("\n");

// Provo a far modificare gli elementi tramite ciclo for
for(int i = 0; i<10; i++){
*(ptr + i) = *(ptr + i) + 1; // *(ptr + 1) Accede all' elemento i dell'array, +1 Incrementa il carattere di 1
printf("Dopo la modifica: %c\n", array[i]);
}

return 0;
}
