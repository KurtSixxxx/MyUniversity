// Esercizio 2.7 - Somma dei soli numeri validi in una riga
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Prova a convertire una parola in double: true se TUTTA la parola è un numero
bool comeNumero(string s, double& valore) {
    stringstream ss(s);
    if (!(ss >> valore)) return false;      // non inizia con un numero
    char resto;
    if (ss >> resto) return false;          // es. "12abc": avanzano caratteri
    return true;
}

int main() {
    string riga;
    getline(cin, riga);
    stringstream ss(riga);
    string parola;
    double somma = 0, v;
    int scartate = 0;
    while (ss >> parola) {                  // leggo PAROLE, non numeri: così non mi blocco
        if (comeNumero(parola, v)) somma += v;
        else {
            cout << "scarto \"" << parola << "\"" << endl;
            scartate++;
        }
    }
    cout << "Somma = " << somma << " (" << scartate << " parole scartate)" << endl;
    return 0;
}
