// Esercizio 7.7 - QuickSort: il caso peggiore dipende dalla scelta del pivot
#include <iostream>
using namespace std;

long long confronti;

// Partizione con pivot = PRIMO elemento (versione "da manuale", vulnerabile)
int partiziona(int a[], int sx, int dx) {
    int pivot = a[sx];
    int i = sx;                                    // ultimo elemento < pivot
    for (int j = sx + 1; j <= dx; j++) {
        confronti++;
        if (a[j] < pivot) { i++; int t = a[i]; a[i] = a[j]; a[j] = t; }
    }
    int t = a[sx]; a[sx] = a[i]; a[i] = t;         // pivot al suo posto definitivo
    return i;
}
void quickPrimo(int a[], int sx, int dx) {
    if (sx >= dx) return;
    int p = partiziona(a, sx, dx);
    quickPrimo(a, sx, p - 1);
    quickPrimo(a, p + 1, dx);
}

// Versione delle slide: pivot = elemento CENTRALE
void quickCentro(int a[], int sx, int dx) {
    int i = sx, j = dx, pivot = a[(sx + dx) / 2];
    while (i <= j) {
        while (confronti++, a[i] < pivot) i++;
        while (confronti++, a[j] > pivot) j--;
        if (i <= j) { int t = a[i]; a[i] = a[j]; a[j] = t; i++; j--; }
    }
    if (sx < j) quickCentro(a, sx, j);
    if (i < dx) quickCentro(a, i, dx);
}

int main() {
    const int N = 2000;
    int* v = new int[N];
    for (int i = 0; i < N; i++) v[i] = i;          // GIA' ORDINATO
    confronti = 0; quickPrimo(v, 0, N - 1);
    cout << "ordinato, pivot primo:   " << confronti << " confronti (circa n^2/2 = " << (long long)N * N / 2 << ")" << endl;
    for (int i = 0; i < N; i++) v[i] = i;
    confronti = 0; quickCentro(v, 0, N - 1);
    cout << "ordinato, pivot centrale: " << confronti << " confronti" << endl;
    delete[] v;
    return 0;
}
