// Modulo 8 - Pattern: una funzione ricorsiva che RACCONTA cosa sta facendo
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
using namespace std;

// Stampa 4 spazi per ogni livello di profondità: così si vede chi ha chiamato chi
void rientra(int livello) {
    for (int i = 0; i < livello; i++) cout << "    ";
}

// Fattoriale: n! = n * (n-1)!   e   0! = 1
// Il parametro "livello" serve SOLO per la stampa: l'algoritmo non ne ha bisogno.
int fattoriale(int n, int livello) {
    rientra(livello);
    cout << "fattoriale(" << n << "): ";
    if (n == 0) {                                   // 1. CASO BASE: so rispondere subito
        cout << "caso base, restituisco 1" << endl;
        return 1;
    }
    cout << "non lo so ancora, chiedo fattoriale(" << n - 1 << ")" << endl;
    int risultatoPiccolo = fattoriale(n - 1, livello + 1);   // 2. PASSO RICORSIVO: problema più piccolo
    int risultato = n * risultatoPiccolo;                    // 3. uso la risposta per la mia
    rientra(livello);
    cout << "fattoriale(" << n << "): mi e' tornato " << risultatoPiccolo
         << ", restituisco " << n << " * " << risultatoPiccolo << " = " << risultato << endl;
    return risultato;
}

// La stessa funzione, SENZA stampe: ecco come la scriveresti all'esame
int fatt(int n) {
    if (n == 0) return 1;           // caso base
    return n * fatt(n - 1);         // passo ricorsivo
}

// Per confronto: la versione iterativa (con un ciclo)
int fattIterativo(int n) {
    int r = 1;
    for (int i = 2; i <= n; i++) r *= i;
    return r;
}

int main() {
    int r = fattoriale(4, 0);         // prima la chiamata (che stampa la traccia)...
    cout << "Risultato: " << r << endl << endl;   // ...poi il risultato
    cout << "fatt(5) = " << fatt(5) << ", fattIterativo(5) = " << fattIterativo(5) << endl;
    return 0;
}
