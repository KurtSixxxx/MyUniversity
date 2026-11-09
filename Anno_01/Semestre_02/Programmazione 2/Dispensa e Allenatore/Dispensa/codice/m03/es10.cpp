// Esercizio 3.10 - Array dinamico con inserimento/rimozione in posizione
//                  che cresce (x2) e si restringe (/2)
#include <iostream>
using namespace std;

void ridimensiona(int*& v, int n, int& cap, int nuovaCap) {
    int* nuovo = new int[nuovaCap];
    for (int i = 0; i < n; i++) nuovo[i] = v[i];
    delete[] v;
    v = nuovo;
    cap = nuovaCap;
    cout << "  [capacita' -> " << cap << "]" << endl;
}

bool inserisci(int*& v, int& n, int& cap, int pos, int x) {
    if (pos < 0 || pos > n) return false;
    if (n == cap) ridimensiona(v, n, cap, cap * 2);
    for (int i = n; i > pos; i--) v[i] = v[i - 1];   // sposto a destra, partendo dal fondo
    v[pos] = x;
    n++;
    return true;
}

bool rimuovi(int*& v, int& n, int& cap, int pos) {
    if (pos < 0 || pos >= n) return false;
    for (int i = pos; i < n - 1; i++) v[i] = v[i + 1]; // sposto a sinistra
    n--;
    if (cap > 2 && n <= cap / 4) ridimensiona(v, n, cap, cap / 2);   // spreco troppo: dimezzo
    return true;
}

void stampa(const int* v, int n, int cap) {
    cout << "n=" << n << " cap=" << cap << ": ";
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

int main() {
    int cap = 2, n = 0;
    int* v = new int[cap];
    for (int x = 1; x <= 5; x++) inserisci(v, n, cap, n, x * 10);   // in coda
    stampa(v, n, cap);
    inserisci(v, n, cap, 0, 5);          // in testa
    inserisci(v, n, cap, 3, 25);         // in mezzo
    stampa(v, n, cap);
    if (!inserisci(v, n, cap, 99, 1)) cout << "posizione 99 non valida" << endl;
    while (n > 1) rimuovi(v, n, cap, 0); // svuoto dalla testa
    stampa(v, n, cap);
    delete[] v;
    return 0;
}
