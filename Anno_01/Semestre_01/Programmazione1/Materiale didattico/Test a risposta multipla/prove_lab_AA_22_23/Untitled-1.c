// 10-01-2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int k;
    char w;
    int N;
    int M;
} InputData;

// Questa funzione prende gli argomenti dalla riga di comando
InputData readInput(int argc, char * argv[]){
    InputData input; //Crea una struttura per contenere i dati

// Controlla se il numero di argomenti è corretto (programma + 4 argomenti = 5)
if(argc!=5){
    fprintf(stderr, "Errore: numero di argomenti errato.\n");
    exit(-1);
}

// Converte e salva gli argomenti:
input.k = atoi(argv[1]);        // Converte la stringa in intero
input.w = argv[2][0];           // Prende il primo carattere della stringa
input.N = atoi(argv[3]);        // Converte la stringa in intero
input.M = atoi(argv[4]);        // Converte la stringa in intero

// Verifica se i range dei valori sono corretti e restituisce un eventuale errore
if(input.k < 10 || input.k > 15){
    fprintf(stderr, "Errore: k deve essere compreso tra 10 e 15.\n");
    exit(-1);
}

if(input.w < 'a' || input.w > 'z'){
    fprintf(stderr, "Errore: w deve essere compreso tra 'a' e 'z'.\n");
    exit(-1);
}

if(input.N < 4 || input.N > 8 || input.M < 4 || input.M > 8){
    fprintf(stderr, "Errore: N e M devono essere compresi tra 4 e 8.\n");
    exit(-1);
}

return input; // Restituisce la struttura con i dati validati

} // Fine funzione

// Funione numeri pseudocasuali
unsigned int get_random() {
    static unsigned int m_w = 123456;
    static unsigned int m_z = 789123;
    m_z = 36969 * (m_z & 65535) + (m_z >> 16);
    m_w = 18000 * (m_w & 65535) + (m_w >> 16);
    return (m_z << 16) + m_w;
}

int main(int argc, char *argv[]){
    InputData input = readInput(argc, argv);

    return 0;
}