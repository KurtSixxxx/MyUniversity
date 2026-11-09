// Esercizio 8.4 - Potenza ricorsiva con la traccia delle chiamate
#include <iostream>
using namespace std;

long long potenza(long long b, int n, int livello) {
    for (int i = 0; i < livello; i++) cout << "  ";
    cout << "potenza(" << b << ", " << n << ")" << endl;
    if (n == 0) return 1;
    long long r = b * potenza(b, n - 1, livello + 1);
    for (int i = 0; i < livello; i++) cout << "  ";
    cout << "-> " << r << endl;
    return r;
}

int main() {
    long long r = potenza(3, 4, 0);
    cout << "3^4 = " << r << endl;
    return 0;
}
