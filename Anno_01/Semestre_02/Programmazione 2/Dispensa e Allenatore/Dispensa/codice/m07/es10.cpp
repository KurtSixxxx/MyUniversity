// Esercizio 7.10 - Sfruttare l'ordinamento: coppia con somma data e intersezione, in O(n)
#include <iostream>
using namespace std;

// Array ORDINATO: esiste una coppia con somma x? Due indici che si vengono incontro.
bool coppiaConSomma(const int a[], int n, int x, int& i, int& j) {
    i = 0; j = n - 1;
    while (i < j) {
        int s = a[i] + a[j];
        if (s == x) return true;
        if (s < x) i++;            // serve una somma più grande: avanzo a sinistra
        else j--;                  // serve una somma più piccola: arretro a destra
    }
    return false;
}

// Elementi comuni a due array ORDINATI (come il merge)
int intersezione(const int a[], int na, const int b[], int nb, int out[]) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) i++;
        else if (a[i] > b[j]) j++;
        else { out[k++] = a[i]; i++; j++; }
    }
    return k;
}

int main() {
    int a[] = {1, 3, 4, 7, 10, 12, 15};
    int i, j;
    int obiettivi[] = {22, 8, 2};
    for (int t = 0; t < 3; t++) {
        if (coppiaConSomma(a, 7, obiettivi[t], i, j))
            cout << obiettivi[t] << " = " << a[i] << " + " << a[j] << endl;
        else
            cout << obiettivi[t] << ": nessuna coppia" << endl;
    }
    int b[] = {2, 3, 7, 8, 12, 20};
    int comuni[6];
    int k = intersezione(a, 7, b, 6, comuni);
    cout << "comuni: ";
    for (int t = 0; t < k; t++) cout << comuni[t] << " ";
    cout << endl;
    return 0;
}
