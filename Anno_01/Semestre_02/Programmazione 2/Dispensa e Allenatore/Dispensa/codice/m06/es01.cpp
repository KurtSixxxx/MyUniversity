// Esercizio 6.1 - Ciclo che avanza di 2: quanti giri?
#include <iostream>
using namespace std;

int main() {
    int dims[] = {10, 100, 1000, 10000};
    for (int t = 0; t < 4; t++) {
        int n = dims[t];
        long long passi = 0;
        for (int i = 0; i < n; i += 2) passi++;    // salta di 2: circa n/2 giri
        cout << "n = " << n << "\tpassi = " << passi << "\tpassi/n = " << (double)passi / n << endl;
    }
    // passi/n resta fisso a 0.5: i passi crescono COME n -> O(n). Il "/2" non conta.
    return 0;
}
