// Esercizio 5.1 - massimo e minimo generici
#include <iostream>
#include <string>
using namespace std;

template <typename T>
T massimo(T a, T b) { return (a > b) ? a : b; }

template <typename T>
T minimo(T a, T b) { return (a < b) ? a : b; }

int main() {
    cout << massimo(3, 8) << " " << minimo(3, 8) << endl;                 // T = int
    cout << massimo(2.71, 3.14) << " " << minimo(2.71, 3.14) << endl;     // T = double
    cout << massimo('a', 'z') << " " << minimo('a', 'z') << endl;         // T = char
    string x = "pera", y = "mela";
    cout << massimo(x, y) << " " << minimo(x, y) << endl;                 // T = string
    // massimo(3, 4.5);            // ERRORE: T dedotto sia int che double
    cout << massimo<double>(3, 4.5) << endl;                              // T forzato
    cout << massimo(static_cast<double>(3), 4.5) << endl;                 // oppure converto io
    return 0;
}
