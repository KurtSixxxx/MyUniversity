// Esercizio 2.4 - Indovina l'output: scope e shadowing
#include <iostream>
using namespace std;

int x = 1;                          // globale

void f() {
    cout << "A: " << x << endl;     // nessuna x locale ancora: usa la globale -> 1
    int x = 2;
    cout << "B: " << x << endl;     // la locale -> 2
    x++;                            // incrementa la LOCALE
    ::x = 10;                       // modifica la GLOBALE
}

int main() {
    f();
    cout << "C: " << x << endl;     // la globale, modificata da f -> 10
    for (int x = 0; x < 2; x++)     // la x del for nasconde la globale
        cout << "D: " << x << endl; // 0 e poi 1
    cout << "E: " << x << endl;     // finito il for, torna visibile la globale -> 10
    {
        int x = 5;
        { cout << "F: " << x + ::x << endl; }   // 5 + 10 = 15
    }
    return 0;
}
