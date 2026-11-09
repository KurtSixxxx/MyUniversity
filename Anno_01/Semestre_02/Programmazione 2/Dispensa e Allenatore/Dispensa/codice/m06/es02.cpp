// Esercizio 6.2 - Due cicli annidati: quadrato pieno e triangolo
#include <iostream>
using namespace std;

int main() {
    int dims[] = {10, 100, 1000};
    cout << "n\tpieno\ttriangolo\tpieno/n^2\ttriangolo/n^2" << endl;
    for (int t = 0; t < 3; t++) {
        int n = dims[t];
        long long pieno = 0, triangolo = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) pieno++;          // n * n
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++) triangolo++;  // (n-1) + (n-2) + ... + 1 = n(n-1)/2
        cout << n << "\t" << pieno << "\t" << triangolo << "\t\t"
             << (double)pieno / ((double)n * n) << "\t\t" << (double)triangolo / ((double)n * n) << endl;
    }
    // Il triangolo fa circa META' dei passi, ma il rapporto con n^2 si stabilizza: anche lui è O(n^2).
    return 0;
}
