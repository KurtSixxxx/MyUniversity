/*CONSEGNA: Definisci una struttura Libro con i campi titolo (stringa), autore (stringa) e annoPubblicazione (intero).
Crea un array di 4 libri e inizializzalo con valori a tua scelta.
Stampa i dettagli di tutti i libri usando una funzione stampaLibri.*/

#include <stdio.h>

//Definisco la struttura
struct Libro {
    char titolo [50];
    char autore [50];
    int annoPubblicazione;
};

//Definisco la funzione che stamperà i dati della struttura
void stampaLibri (struct Libro libri[], int n){
    for(int i = 0; i < n; i++) {
printf("Titolo: %s\n", libri[i].titolo);
printf("Autore: %s\n", libri[i].autore);
printf("Anno di Pubblicazione: %d\n", libri[i].annoPubblicazione);
printf("\n");  // Per separare i dettagli di ciascun libro;
  }
}

//Apro il main()
int main(){

//Compilo il profilo della struct
struct Libro libri[4] = {
    {"La foresta dei cazzi volanti", "Nanno", 2012 },
    {"U facimmu stu cazzu di punti", "Checco Zalone", 2009},
    {"Quali patatine mi piacciono?", "U Calabrisi", 2023},
    {"Sivallettoh", "Dario Moccia", 1999}
};

//Chiamo la funzione stampa libri, che dovrà stampare i dati di 4 array
stampaLibri(libri, 4);

    return 0;
    
    }