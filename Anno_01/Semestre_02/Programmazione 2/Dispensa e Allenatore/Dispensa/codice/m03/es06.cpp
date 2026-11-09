// Esercizio 3.6 - Array dinamico di dimensione scelta dall'utente
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Quanti numeri? ";
    cin >> n;
    if (!cin || n <= 0) {
        cerr << "dimensione non valida" << endl;
        return 1;
    }

    int* v = new int[n];          // n è noto solo ora, a run-time: serve lo heap
    for (int i = 0; i < n; i++) {
        cout << "v[" << i << "] = ";
        cin >> v[i];
    }

    cout << endl << "Al contrario: ";
    for (int i = n - 1; i >= 0; i--) cout << v[i] << " ";
    cout << endl;

    delete[] v;                   // creato con new[] -> delete[]
    v = nullptr;
    return 0;
}
