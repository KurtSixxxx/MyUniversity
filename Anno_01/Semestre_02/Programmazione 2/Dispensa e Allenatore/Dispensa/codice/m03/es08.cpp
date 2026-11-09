// Esercizio 3.8 - Fondere due array ordinati in un nuovo array ordinato
#include <iostream>
using namespace std;

int* fondi(const int* a, int na, const int* b, int nb) {
    int* r = new int[na + nb];
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb)                 // prendo sempre il più piccolo dei due "in testa"
        r[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    while (i < na) r[k++] = a[i++];          // avanzi del primo
    while (j < nb) r[k++] = b[j++];          // avanzi del secondo
    return r;
}

int main() {
    int a[] = {1, 4, 9, 12};
    int b[] = {2, 3, 10, 15, 20};
    int* f = fondi(a, 4, b, 5);
    for (int k = 0; k < 9; k++) cout << f[k] << " ";
    cout << endl;
    delete[] f;
    return 0;
}
