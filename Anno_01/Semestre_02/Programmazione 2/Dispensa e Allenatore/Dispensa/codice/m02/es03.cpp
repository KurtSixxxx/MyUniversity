// Esercizio 2.3 - Due namespace con funzioni dallo stesso nome
#include <iostream>
#include <string>
using namespace std;

namespace italiano {
    string saluta(string nome) { return "Ciao, " + nome + "!"; }
    const string LINGUA = "italiano";
}

namespace inglese {
    string saluta(string nome) { return "Hello, " + nome + "!"; }
    const string LINGUA = "inglese";
}

int main() {
    // Con il nome completo (cognome::nome) non c'è nessuna ambiguità
    cout << italiano::LINGUA << ": " << italiano::saluta("Mario") << endl;
    cout << inglese::LINGUA << ": " << inglese::saluta("Mario") << endl;

    {
        using namespace inglese;          // vale solo dentro questo blocco
        cout << "Nel blocco: " << saluta("Anna") << endl;
    }
    // Qui fuori "saluta" da sola non esiste più: bisogna di nuovo scrivere il namespace.
    // Se facessi "using namespace" di ENTRAMBI, saluta("x") sarebbe AMBIGUA: errore.
    cout << "Fuori: " << italiano::saluta("Anna") << endl;
    return 0;
}
