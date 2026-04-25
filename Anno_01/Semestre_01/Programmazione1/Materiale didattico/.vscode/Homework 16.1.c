/*
Homework 16.1
Codificare una funzione C che prenda in input un parametro formale matrice M di dimensioni n × m di stringhe (puntatori a caratteri),
e che restituisca il valore true (1) se esiste almeno una colonna in M che abbia un egual numero di stringhe palindrome di una delle righe di M.
*/

//Come prima cosa inseriamo le librerie che ci occorrono
#include <stdio.h> //Classica libreria che ci occorre sempre
#include <stdlib.h> //Libreria necessaria per allocazione dinamica
#include <stdbool.h> //Se si vuole utilizzare i tipi booleani bool, true e false per rendere il codice più leggibile e simile, ci occorre questa libreria
#include <string.h> //Libreria che ci occorre per alcune funzioni sulle stringhe

//Utilizziamo momentaneamente dei define con N e M per comodità, ma n e m saranno parametri attuali da passare in chiamata.
#define N 3
#define M 5

//Dichiariamo la funzione con valore di ritorno, nome e parametri formali.
bool palindrome(int n, int m, char *matrix[n][m]){ //Deve restituire true/false quindi tipo di ritorno "bool", il nome è autoesplicativo, i parametri sono quelli richiesti

    //Iniziamo con l'allocazione della matrice:
    matrix = malloc(sizeof(char**) * N); //Allochiamo le 3 righe

    //Effettuiamo un controllo per vedere se l'allocazione è andata a buon fine.
    if(matrix == NULL){
        fprintf(stderr, "Allocazione fallita.");
        return -1;
    }

    //Adesso allochiamo le colonne e i puntatori a stringhe
    for(int i = 0; i < N; i++){
        matrix[i] = malloc(sizeof(char*) * M);
    }

    //Ora allochiamo i singoli array contenenti i caratteri, ossia le stringhe. Poiché le stringhe palindrome sono brevi e ci occorre effettuare dei test, la lunghezza di ogni array di stringa sarà di 7 caratteri compreso temrinatore nullo. Quindi i caratteri effettivi sarano 6.
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            matrix[i][j] = malloc(sizeof(char) * 7); //Così in ogni casella della matrice 3x5 ci sarà una stringa da 6 caratteri + \0 = 7. Per un totale di 15 stringhe.
        }
    }

    //Adesso arriva il pezzo forte, ossia il controllo di stringhe palindrome,

}