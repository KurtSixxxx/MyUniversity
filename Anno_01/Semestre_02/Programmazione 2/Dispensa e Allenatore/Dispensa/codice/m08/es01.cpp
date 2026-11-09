// Esercizio 8.1 - Stessa funzione, cout prima o dopo: cambia tutto
#include <iostream>
using namespace std;

void giu(int n) {               // cout PRIMA della chiamata
    if (n < 1) return;
    cout << n << " ";
    giu(n - 1);
}

void su(int n) {                // cout DOPO la chiamata
    if (n < 1) return;
    su(n - 1);
    cout << n << " ";
}

void suEGiu(int n) {            // cout PRIMA e DOPO
    if (n < 1) return;
    cout << n << " ";
    suEGiu(n - 1);
    cout << n << " ";
}

int main() {
    giu(5);    cout << endl;
    su(5);     cout << endl;
    suEGiu(3); cout << endl;
    return 0;
}
