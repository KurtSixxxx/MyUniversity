// Modulo 8 - Laboratorio a step: ricorsione su numeri, array, stringhe e liste
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
using namespace std;

// ===== STEP 1 =====  Il PRIMA e il DOPO della chiamata ricorsiva
void contoAllaRovescia(int n) {          // stampa PRIMA di chiamare: n, n-1, ..., 1
    if (n == 0) return;                  // caso base: non faccio niente
    cout << n << " ";
    contoAllaRovescia(n - 1);
}
void contoInAvanti(int n) {              // stampa DOPO la chiamata: 1, 2, ..., n
    if (n == 0) return;
    contoInAvanti(n - 1);                // prima faccio contare fino a n-1...
    cout << n << " ";                    // ...poi aggiungo il mio numero
}

// ===== STEP 2 =====  Somma di un array: "il primo + la somma del resto"
int somma(const int v[], int n) {
    if (n == 0) return 0;                       // array vuoto: somma 0
    return v[0] + somma(v + 1, n - 1);          // v + 1 = l'array che parte dal secondo elemento
}

// ===== STEP 3 =====  Massimo con divide et impera (esercizio delle slide)
int massimo(const int v[], int sx, int dx) {
    if (sx == dx) return v[sx];                 // un solo elemento: è lui il massimo
    int m = (sx + dx) / 2;
    int maxSx = massimo(v, sx, m);              // massimo della metà sinistra
    int maxDx = massimo(v, m + 1, dx);          // massimo della metà destra
    return (maxSx > maxDx) ? maxSx : maxDx;     // il più grande dei due
}

// ===== STEP 4 =====  Palindromo: primo == ultimo E il "dentro" è palindromo
bool palindromo(const string& s, int i, int j) {
    if (i >= j) return true;                    // 0 o 1 carattere: sempre palindromo
    if (s[i] != s[j]) return false;             // estremi diversi: fallito subito
    return palindromo(s, i + 1, j - 1);         // controllo la parte interna
}

// ===== STEP 5 =====  Ricorsione su una lista (anteprima del Modulo 11)
struct Nodo {
    int valore;
    Nodo* next;          // puntatore al nodo successivo (nullptr = fine lista)
};
int lunghezza(Nodo* p) {
    if (p == nullptr) return 0;                 // lista vuota
    return 1 + lunghezza(p->next);              // io + la lunghezza del resto
}
void stampaAlContrario(Nodo* p) {
    if (p == nullptr) return;
    stampaAlContrario(p->next);                 // prima stampa il resto...
    cout << p->valore << " ";                   // ...poi me (come contoInAvanti)
}
void distruggi(Nodo* p) {                       // libera la memoria, ricorsivamente
    if (p == nullptr) return;
    distruggi(p->next);
    delete p;
}

// ===== STEP 6 =====  Ricorsione di coda: l'accumulatore porta avanti il risultato
int sommaCoda(const int v[], int n, int accumulatore) {
    if (n == 0) return accumulatore;            // il risultato è già pronto
    return sommaCoda(v + 1, n - 1, accumulatore + v[0]);   // ULTIMA cosa che faccio
}
int sommaCiclo(const int v[], int n) {          // la stessa cosa trasformata in ciclo
    int accumulatore = 0;
    while (n != 0) { accumulatore += v[0]; v = v + 1; n = n - 1; }
    return accumulatore;
}

int main() {
    cout << "STEP 1: "; contoAllaRovescia(5); cout << "| "; contoInAvanti(5); cout << endl;

    int v[] = {7, 3, 12, 5, 9, 1};
    cout << "STEP 2: somma = " << somma(v, 6) << endl;
    cout << "STEP 3: massimo = " << massimo(v, 0, 5) << endl;

    string parole[] = {"radar", "osso", "ciao", "a", "anna"};
    cout << "STEP 4:";
    for (int k = 0; k < 5; k++)
        cout << " " << parole[k] << (palindromo(parole[k], 0, parole[k].length() - 1) ? "(si)" : "(no)");
    cout << endl;

    Nodo* testa = nullptr;                      // costruisco la lista 1 -> 2 -> 3 -> 4
    for (int x = 4; x >= 1; x--) testa = new Nodo{x, testa};   // inserimento in testa
    cout << "STEP 5: lunghezza = " << lunghezza(testa) << ", al contrario: ";
    stampaAlContrario(testa);
    cout << endl;
    distruggi(testa);

    cout << "STEP 6: sommaCoda = " << sommaCoda(v, 6, 0) << ", sommaCiclo = " << sommaCiclo(v, 6) << endl;
    return 0;
}
