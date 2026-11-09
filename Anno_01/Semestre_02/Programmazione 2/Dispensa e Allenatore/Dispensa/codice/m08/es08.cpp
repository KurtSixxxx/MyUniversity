// Esercizio 8.8 - La funzione "puzzle" delle slide (congettura di Collatz)
#include <iostream>
using namespace std;

// Se N è pari chiama se stessa su N/2, se è dispari su 3N+1.
// 3N+1 è PIÙ GRANDE di N: non possiamo garantire che si arrivi al caso base!
int passi(long long N) {
    if (N == 1) return 0;
    if (N % 2 == 0) return 1 + passi(N / 2);
    return 1 + passi(3 * N + 1);
}

void percorso(long long N) {
    cout << N;
    if (N == 1) { cout << endl; return; }
    cout << " -> ";
    percorso(N % 2 == 0 ? N / 2 : 3 * N + 1);
}

int main() {
    percorso(6);
    percorso(7);
    int record = 1;
    for (int n = 1; n <= 30; n++)
        if (passi(n) > passi(record)) record = n;
    cout << "fino a 30, il numero piu' lungo e' " << record << " con " << passi(record) << " passi" << endl;
    return 0;
}
