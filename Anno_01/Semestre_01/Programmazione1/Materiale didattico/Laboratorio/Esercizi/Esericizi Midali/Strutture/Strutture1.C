/*Definisci una struttura Persona con i campi nome (stringa), eta (intero) e sesso (carattere).
Crea un'istanza della struttura e inizializzala con i valori "Mario", 25, 'M'. Stampa i valori dei campi.*/

#include <stdio.h>
#include <string.h>

struct Persona{
    char nome[50];
    int eta;
    char sesso;
};

int main (){

    struct Persona persona1;
    strcpy(persona1.nome, "Luca");
    persona1.eta = 25;
    persona1.sesso = 'M';

    printf("Nome: %s\n", persona1.nome);
    printf("Eta: %d\n", persona1.eta);
    printf("Sesso: %c\n", persona1.sesso);
    
    return 0;
    
    }