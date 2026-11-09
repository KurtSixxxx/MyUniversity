// Esercizio 7.2 - Selection sort decrescente, con stampa di ogni passata
#include <iostream>
using namespace std;

void stampa(const int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
}

void selectionSortDecrescente(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int iMax = i;                              // cerco il MASSIMO del resto
        for (int j = i + 1; j < n; j++)
            if (a[j] > a[iMax]) iMax = j;
        int t = a[i]; a[i] = a[iMax]; a[iMax] = t;
        cout << "dopo la passata " << i + 1 << ": ";
        stampa(a, n);
    }
}

int main() {
    int v[] = {29, 10, 14, 37, 13};
    selectionSortDecrescente(v, 5);
    return 0;
}
