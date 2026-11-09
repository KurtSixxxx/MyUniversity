// Esercizio 3.7 - Copia senza duplicati (nuovo array dinamico di dimensione esatta)
#include <iostream>
using namespace std;

bool contiene(const int* v, int n, int x) {
    for (int i = 0; i < n; i++) if (v[i] == x) return true;
    return false;
}

int* senzaDuplicati(const int* v, int n, int& m) {
    // 1a passata: conto i valori "nuovi" (che non compaiono prima di loro)
    m = 0;
    for (int i = 0; i < n; i++)
        if (!contiene(v, i, v[i])) m++;
    // 2a passata: alloco esattamente m celle e copio
    int* r = new int[m];
    int k = 0;
    for (int i = 0; i < n; i++)
        if (!contiene(v, i, v[i])) r[k++] = v[i];
    return r;
}

int main() {
    int v[] = {3, 1, 3, 2, 1, 1, 5, 2};
    int m;
    int* u = senzaDuplicati(v, 8, m);
    cout << "Valori distinti (" << m << "): ";
    for (int i = 0; i < m; i++) cout << u[i] << " ";
    cout << endl;
    delete[] u;
    return 0;
}
