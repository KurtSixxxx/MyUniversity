/*Esercizio 6: Puntatori e Stringhe
Dichiara una stringa e usa un puntatore per stampare ogni carattere della stringa separatamente.
Mostra come muoversi attraverso la stringa utilizzando l'aritmetica dei puntatori.*/

#include <stdio.h>
#include <string.h>

int main(){

char str[] = "Ciao"; // Dichiaro la stringa
char *ptr = str; // Dichiaro il puntatore a stringa, che adesso punta a 'C'

for(int i = 0; i<4; i++){ // Ciclo for che deve stampare ogni carattere finchè non finisce
    //*(ptr + i);
    printf("%c\n", *(ptr + i)); // Usa l'aritmetica dei puntatori per accedere ai caratteri
}

//Modifica del primo carattere della stringa
*(ptr + 0) = 'B';
printf("Stringa modificata: '%s'\n", str);

return 0;

}