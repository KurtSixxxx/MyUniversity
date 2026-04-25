//Compito 26-06-2024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definiamo i limiti di lunghezza della stringa 8-12
#define MIN_LUNGH 8 
#define MAX_LUNGH 12
//Definiamo i limiti di valore dell'intero n 3-12
#define MIN_N 3
#define MAX_N 12

int main (int argc, char * argv[]){
    //Verifica della presenza di 4 argomenti
    if(argc != 4){
        fprint(stderr, "Sono necessari 3 argomenti.\n"); //Messaggio d'errore
        return 1; //Codice di terminazione 1
    }

    char *file_di_input.txt = argv[1]; //1° Argomento - Nome del file di input
    int n = atoi(argv[2]); //2° Argomento - Con atoi() convertiamo la stringa n in intero per eseguire calcoli
    char *file_di_output.txt = argv[3]; //3° Argomento - Nome del file di output

    //Verifica che int n sia cpmpreso tra 3 e 12
    if(n < MIN_N || n > MAX_N){
        fprintf(stderr, "Errore, l'intero deve essere compreso tra 3 e 12.\n"); //Messaggio d'errore
        return 2; //Codice di terminazione 2
    }

    //Apertura del file di input
    FILE *file = fopen(file_di_input, "r");
    if (file == NULL){
        fprintf(stderr, "Errore: impossibile aprire il file di input.\n");
        return 3; //Codice di terminazione 3
    }

    //Lettura della stringa dal file
    char str[100]; //Array per memorizzare la stringa dal file
    fscanf(file, "%s", str); //Legge la prima stringa dal file
    fclose(file); //CHiusura del file


}