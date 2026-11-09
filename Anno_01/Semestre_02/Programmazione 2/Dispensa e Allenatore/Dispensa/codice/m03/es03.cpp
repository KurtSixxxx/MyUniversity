// Esercizio 3.3 - Somma e massimo con l'aritmetica dei puntatori (niente [])
#include <iostream>
using namespace std;

int somma(const int* inizio, const int* fine) {     // fine = uno DOPO l'ultimo
    int s = 0;
    for (const int* p = inizio; p < fine; p++)       // p avanza di un int alla volta
        s += *p;
    return s;
}

const int* posizioneMassimo(const int* v, int n) {
    const int* best = v;
    for (const int* p = v + 1; p < v + n; p++)
        if (*p > *best) best = p;
    return best;                                     // restituisco un INDIRIZZO
}

int main() {
    int v[6] = {4, 8, 15, 16, 23, 42};
    cout << "Somma: " << somma(v, v + 6) << endl;
    cout << "Somma dei primi 3: " << somma(v, v + 3) << endl;
    const int* pm = posizioneMassimo(v, 6);
    cout << "Massimo: " << *pm << " in posizione " << (pm - v) << endl;   // differenza = indice
    return 0;
}
