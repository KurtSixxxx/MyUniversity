#include <stdio.h>    // Per funzioni di I/O (input/output) come printf, fgets, e sscanf
#include <string.h>   // Per funzioni di manipolazione stringhe (anche se qui non usata)
#include <stdlib.h>   // Per le funzioni di conversione numerica come atof e strtof

int main(){

    // Dichiarazione degli array di caratteri (stringhe) per memorizzare l'input
    // Ogni array può contenere fino a 9 caratteri + il terminatore di stringa '\0'.
    char arr1[10];
    char arr2[10];
    char arr3[10];

    // --- PRIMO INSERIMENTO ---
    // Chiede all'utente di inserire il primo numero.
    printf("Inserire un numero in virgola mobile: ");
    // Legge l'input da tastiera (stdin) in modo sicuro.
    // Legge al massimo 'sizeof(arr1)' caratteri e li salva in arr1.
    fgets(arr1, sizeof(arr1), stdin);
    printf("\n");

    // --- SECONDO INSERIMENTO ---
    printf("Inserire un numero in virgola mobile: ");
    // Stessa logica di prima, ma salva l'input nel secondo array.
    fgets(arr2, sizeof(arr2), stdin);
    printf("\n");

    // --- TERZO INSERIMENTO ---
    printf("Inserire un numero in virgola mobile: ");
    // Stessa logica di prima, ma salva l'input nel terzo array.
    fgets(arr3, sizeof(arr3), stdin);
    printf("\n");

    // --- STAMPA DEI DATI ---
    printf("Numeri\n");
    // Stampa il contenuto degli array, che sono ancora stringhe.
    printf("%s\n", arr1);
    printf("%s\n", arr2);
    printf("%s\n", arr3);

    // --- CONVERSIONE E STAMPA DEI RISULTATI ---
    // Converte la stringa in arr1 in un numero double usando atof().
    // atof() è la più semplice ma non gestisce errori.
    double num1 = atof(arr1);
    printf("Numero tramite atof: %.2f\n", num1);

    // Converte la stringa in arr2 in un numero double usando sscanf().
    // sscanf() è come scanf() ma legge da una stringa invece che dalla tastiera.
    // Il '%lf' indica di convertire la stringa in un double.
    double num2;
    sscanf(arr2, "%lf", &num2);
    printf("Numero tramite sscanf: %.2f\n", num2);

    // Converte la stringa in arr3 in un numero double usando strtof().
    // strtof() è la più robusta: restituisce un puntatore (endptr) alla fine
    // del numero trovato, permettendo di controllare se la conversione ha avuto successo.
    char *endptr;
    double num3 = strtof(arr3, &endptr);
    printf("Numero tramite strtof: %.2f\n", num3);

    // --- CALCOLO E STAMPA DELLA MEDIA ---
    double media = (num1 + num2 + num3) / 3;
    printf("Media numerica: %.2f", media);

    return 0;
}