/*Homework H15.3
Codificare una funzione in C che prenda in input un array di caratteri.
Tale funzione dovrà restituire la lunghezza della stringa.*/

#include <stdio.h>

int string_lenght(char *c){ //forma equivalente = char *c
    //char c[]; //dichiariamo l'array che contiene la stringa
    //usiamo una variabile per contare i caratteri
    //Dato che la stringa contiene il carattere nullo '\0' dobbiamo fare in modo che quando lo incontriamo usciamo
    int i;
    for(i = 0; c[i] != '\0'; i++){
    }
    return i;
}

int main(){
    char c[] = {"Hello World!"};
    int risultato = string_lenght(c);
    printf("%d", risultato);

    return 0;
}