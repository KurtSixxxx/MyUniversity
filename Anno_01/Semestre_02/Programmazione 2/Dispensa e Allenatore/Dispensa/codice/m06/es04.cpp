// Esercizio 6.4 - Blocchi in sequenza: vince il più pesante
#include <iostream>
using namespace std;

int main() {
    int dims[] = {10, 100, 1000};
    cout << "n\tblocco A (n)\tblocco B (n^2)\ttotale\tquota di B" << endl;
    for (int t = 0; t < 3; t++) {
        int n = dims[t];
        long long a = 0, b = 0;
        for (int i = 0; i < n; i++) a++;                  // blocco A: O(n)
        for (int i = 0; i < n; i++)                       // blocco B: O(n^2)
            for (int j = 0; j < n; j++) b++;
        cout << n << "\t" << a << "\t\t" << b << "\t\t" << a + b << "\t"
             << 100.0 * b / (a + b) << "%" << endl;
    }
    // Il totale è n + n^2, ma per n grande il blocco B è quasi tutto: O(n + n^2) = O(n^2).
    return 0;
}
