// Esercizio 8.7 - MCD di Euclide: ricorsione di coda e versione con il ciclo
#include <iostream>
using namespace std;

// mcd(a, b) = a               se b = 0
// mcd(a, b) = mcd(b, a % b)   altrimenti
int mcd(int a, int b) {
    cout << "  mcd(" << a << ", " << b << ")" << endl;
    if (b == 0) return a;
    return mcd(b, a % b);          // la chiamata è l'ULTIMA cosa: ricorsione di coda
}

int mcdCiclo(int a, int b) {       // stessa logica: i parametri diventano variabili
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int r = mcd(1071, 462);
    cout << "mcd(1071, 462) = " << r << ", con il ciclo: " << mcdCiclo(1071, 462) << endl;
    return 0;
}
