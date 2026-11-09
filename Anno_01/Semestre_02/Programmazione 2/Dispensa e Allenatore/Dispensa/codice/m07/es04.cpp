// Esercizio 7.4 - Ricerca binaria "al rallentatore"
#include <iostream>
using namespace std;

int ricercaBinaria(const int a[], int n, int x) {
    int sx = 0, dx = n - 1, passo = 0;
    while (sx <= dx) {
        int m = (sx + dx) / 2;
        passo++;
        cout << "  passo " << passo << ": sx=" << sx << " dx=" << dx
             << " m=" << m << " a[m]=" << a[m] << endl;
        if (a[m] == x) return m;
        if (a[m] < x) sx = m + 1;        // x è più a destra
        else dx = m - 1;                 // x è più a sinistra
    }
    return -1;
}

int main() {
    int a[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    cout << "cerco 23:" << endl;
    int r = ricercaBinaria(a, 10, 23);     // prima la chiamata (che stampa i passi)...
    cout << "-> indice " << r << endl;    // ...poi il risultato
    cout << "cerco 7:" << endl;
    r = ricercaBinaria(a, 10, 7);
    cout << "-> indice " << r << endl;
    return 0;
}
