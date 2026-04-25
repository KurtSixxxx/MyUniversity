/*Definisci una struttura Persona con i campi nome (stringa), eta (intero) e sesso (carattere).
Crea un'istanza della struttura e inizializzala con i valori "Mario", 25, 'M'. Stampa i valori dei campi.

Estendi l'esercizio 1 aggiungendo una funzione stampaPersona che accetta una struttura Persona e ne stampa i dettagli.*/

#include <stdio.h>
#include <string.h>

struct Persona{
    char nome[50];
    int eta;
    char sesso;
};

void stampaPersona (struct Persona persona){
    printf("Nome: %s\n", persona.nome);
    printf("Eta: %d\n", persona.eta);
    printf("Sesso: %c\n", persona.sesso);
}

int main (){

    struct Persona Mario = {"Mario", 25, 'M'};
    
    /*strcpy(persona1.nome, "Luca");
    persona1.eta = 25;
    persona1.sesso = 'M';*/ //qui ho commentato per favorire la versione "compatta" sopra.

    stampaPersona(Mario);
    
    return 0;
    
    }