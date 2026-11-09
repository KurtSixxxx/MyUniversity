// Esercizio 6.10 - Fibonacci: ricorsione "ingenua" esponenziale contro ciclo lineare
#include <iostream>
using namespace std;

long long chiamate;

long long fibRicorsivo(int n) {        // T(n) = T(n-1) + T(n-2) + 1  -> cresce come 2^n circa
    chiamate++;
    if (n <= 1) return n;
    return fibRicorsivo(n - 1) + fibRicorsivo(n - 2);
}

long long fibIterativo(int n, long long& giri) {   // un giro per ogni n -> O(n)
    long long a = 0, b = 1;
    giri = 0;
    for (int i = 0; i < n; i++) {
        giri++;
        long long c = a + b;
        a = b;
        b = c;
    }
    return a;
}

int main() {
    for (int n = 10; n <= 35; n += 5) {
        chiamate = 0;
        long long r = fibRicorsivo(n);
        long long giri;
        long long s = fibIterativo(n, giri);
        cout << "fib(" << n << ") = " << r << (r == s ? "" : " ERRORE")
             << "\tchiamate ricorsive: " << chiamate << "\tgiri del ciclo: " << giri << endl;
    }
    // Ogni +5 su n moltiplica le chiamate per circa 11: crescita esponenziale.
    return 0;
}
