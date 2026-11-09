// Esercizio 2.6 - Conta le parole di una riga e trova la più lunga
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string riga;
    while (getline(cin, riga)) {                // una riga alla volta fino a fine input
        stringstream ss(riga);
        string parola, piuLunga;
        int conta = 0;
        while (ss >> parola) {                  // >> salta gli spazi: una parola alla volta
            conta++;
            if (parola.length() > piuLunga.length()) piuLunga = parola;
        }
        cout << conta << " parole";
        if (conta > 0) cout << ", la piu' lunga e' \"" << piuLunga << "\"";
        cout << endl;
    }
    return 0;
}
