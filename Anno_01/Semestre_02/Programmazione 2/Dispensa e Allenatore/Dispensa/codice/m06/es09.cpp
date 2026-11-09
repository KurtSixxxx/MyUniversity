// Esercizio 6.9 - Ricerca lineare contro ricerca binaria (anteprima del Modulo 7)
#include <iostream>
using namespace std;

int confronti;

int lineare(const int v[], int n, int x) {
    for (int i = 0; i < n; i++) {
        confronti++;
        if (v[i] == x) return i;
    }
    return -1;
}

int binaria(const int v[], int n, int x) {      // v deve essere ORDINATO
    int sx = 0, dx = n - 1;
    while (sx <= dx) {
        int m = (sx + dx) / 2;                  // guardo a metà
        confronti++;
        if (v[m] == x) return m;
        if (v[m] < x) sx = m + 1;               // butto la metà sinistra
        else dx = m - 1;                        // butto la metà destra
    }
    return -1;
}

int main() {
    int dims[] = {1000, 100000, 1000000};
    for (int t = 0; t < 3; t++) {
        int n = dims[t];
        int* v = new int[n];
        for (int i = 0; i < n; i++) v[i] = 2 * i;        // ordinato, solo numeri pari
        confronti = 0; lineare(v, n, -1); int cl = confronti;   // assente: caso peggiore
        confronti = 0; binaria(v, n, -1); int cb = confronti;
        cout << "n = " << n << "\tlineare: " << cl << "\tbinaria: " << cb << endl;
        delete[] v;
    }
    return 0;
}
