// Esercizio 1.2 - Contatore
#include <iostream>
using namespace std;

class Contatore {
private:
    int valore;

public:
    Contatore() { valore = 0; }
    void incrementa() { valore++; }
    bool decrementa() {
        if (valore == 0) return false;   // mai sotto zero
        valore--;
        return true;
    }
    void reset() { valore = 0; }
    int getValore() const { return valore; }
};

int main() {
    Contatore persone;                   // conta le persone in una stanza
    for (int i = 0; i < 3; i++) persone.incrementa();
    cout << "Dentro: " << persone.getValore() << endl;
    persone.decrementa();
    cout << "Dopo un'uscita: " << persone.getValore() << endl;
    persone.reset();
    if (!persone.decrementa())
        cout << "Impossibile scendere sotto zero" << endl;
    cout << "Valore finale: " << persone.getValore() << endl;
    return 0;
}
