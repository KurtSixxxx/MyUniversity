// Esercizio 6.7 - Potenza: O(n) contro O(log n) (dalle slide)
#include <iostream>
using namespace std;

int moltiplicazioni;

long long potenzaLenta(long long x, int n) {        // x * x * ... * x (n volte)
    if (n == 0) return 1;
    moltiplicazioni++;
    return x * potenzaLenta(x, n - 1);
}

long long potenzaVeloce(long long x, int n) {       // dimezza l'esponente a ogni chiamata
    if (n == 0) return 1;
    long long y = potenzaVeloce(x, n / 2);          // n/2 con divisione intera
    if (n % 2 == 0) {
        moltiplicazioni++;
        return y * y;                               // x^n = (x^(n/2))^2
    }
    moltiplicazioni += 2;
    return x * y * y;                               // n dispari: x^n = x * (x^((n-1)/2))^2
}

int main() {
    int esponenti[] = {10, 30, 62};
    for (int t = 0; t < 3; t++) {
        int n = esponenti[t];
        moltiplicazioni = 0;
        long long a = potenzaLenta(2, n);
        int ml = moltiplicazioni;
        moltiplicazioni = 0;
        long long b = potenzaVeloce(2, n);
        cout << "2^" << n << " = " << a << (a == b ? "" : " ERRORE")
             << "\tlenta: " << ml << " molt.\tveloce: " << moltiplicazioni << " molt." << endl;
    }
    return 0;
}
