// Esercizio 8.2 - Prodotto come somme ripetute (dalle slide)
#include <iostream>
using namespace std;

// prod(a, b) = a                    se b = 1
// prod(a, b) = a + prod(a, b - 1)   altrimenti
int prod(int a, int b) {
    if (b == 1) return a;
    return a + prod(a, b - 1);
}

// Versione che accetta anche b = 0 (caso base più "naturale")
int prod0(int a, int b) {
    if (b == 0) return 0;
    return a + prod0(a, b - 1);
}

int main() {
    cout << "prod(7, 4) = " << prod(7, 4) << endl;      // 7 + 7 + 7 + 7
    cout << "prod(5, 1) = " << prod(5, 1) << endl;
    cout << "prod0(5, 0) = " << prod0(5, 0) << endl;
    // prod(5, 0) andrebbe all'infinito: b = 0, -1, -2, ... non arriva mai a 1!
    return 0;
}
