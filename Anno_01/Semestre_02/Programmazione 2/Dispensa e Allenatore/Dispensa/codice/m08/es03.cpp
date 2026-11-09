// Esercizio 8.3 - Somma e numero delle cifre di un intero
#include <iostream>
using namespace std;

// 4721 -> 1 + sommaCifre(472) -> ... ; n % 10 = ultima cifra, n / 10 = "toglie" l'ultima cifra
int sommaCifre(int n) {
    if (n < 10) return n;                       // una sola cifra
    return n % 10 + sommaCifre(n / 10);
}

int numeroCifre(int n) {
    if (n < 10) return 1;
    return 1 + numeroCifre(n / 10);
}

int main() {
    int numeri[] = {4721, 9, 100000, 987654321};
    for (int k = 0; k < 4; k++)
        cout << numeri[k] << ": somma cifre " << sommaCifre(numeri[k])
             << ", cifre " << numeroCifre(numeri[k]) << endl;
    return 0;
}
