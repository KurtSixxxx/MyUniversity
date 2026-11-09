// Esercizio 2.10 - Scontrino da righe "prodotto;quantita;prezzo"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

namespace scontrino {
    // Separa la riga sui ';' con getline(stream, stringa, delimitatore)
    bool analizza(string riga, string& prodotto, int& qta, double& prezzo) {
        stringstream ss(riga);
        string campoQta, campoPrezzo, avanzo;
        if (!getline(ss, prodotto, ';')) return false;
        if (!getline(ss, campoQta, ';')) return false;
        if (!getline(ss, campoPrezzo, ';')) return false;
        if (getline(ss, avanzo, ';')) return false;      // un campo di troppo
        if (prodotto.empty()) return false;

        stringstream sq(campoQta), sp(campoPrezzo);      // conversione testo -> numero
        if (!(sq >> qta) || qta <= 0) return false;
        if (!(sp >> prezzo) || prezzo < 0) return false;
        return true;
    }
}

int main() {
    string riga, prodotto;
    int qta, nRiga = 0;
    double prezzo, totale = 0;
    while (getline(cin, riga) && !riga.empty()) {        // riga vuota = fine scontrino
        nRiga++;
        if (scontrino::analizza(riga, prodotto, qta, prezzo)) {
            double parziale = qta * prezzo;
            cout << prodotto << " x" << qta << " = " << parziale << endl;
            totale += parziale;
        } else {
            cerr << "riga " << nRiga << " non valida: " << riga << endl;
        }
    }
    cout << "TOTALE: " << totale << endl;
    return 0;
}
