// Esercizio 2.5 - Lettura robusta di un intero in [1, 10]
#include <iostream>
#include <limits>
using namespace std;

int leggiTraUnoEDieci() {
    int x;
    int tentativi = 0;
    while (true) {
        tentativi++;
        cout << "Numero tra 1 e 10: ";
        if (cin >> x) {                  // l'estrazione è riuscita?
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (x >= 1 && x <= 10) {
                cout << "(valido dopo " << tentativi << " tentativi)" << endl;
                return x;
            }
            cout << "fuori intervallo" << endl;
        } else {
            if (cin.eof()) {             // finito l'input (es. Ctrl+Z): esco
                cout << "fine input" << endl;
                return -1;
            }
            cout << "non e' un numero" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

int main() {
    int n = leggiTraUnoEDieci();
    cout << "Hai scelto " << n << endl;
    return 0;
}
