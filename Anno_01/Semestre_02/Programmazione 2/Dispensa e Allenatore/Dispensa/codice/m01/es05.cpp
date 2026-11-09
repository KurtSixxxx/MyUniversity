// Esercizio 1.5 - Lampadina che si brucia
#include <iostream>
using namespace std;

class Lampadina {
private:
    bool accesa;
    bool bruciata;
    int accensioni;
    int durata;          // numero massimo di accensioni

public:
    Lampadina(int maxAccensioni) {
        accesa = false;
        bruciata = false;
        accensioni = 0;
        durata = (maxAccensioni > 0) ? maxAccensioni : 1;
    }
    bool accendi() {
        if (bruciata || accesa) return false;
        accensioni++;
        if (accensioni > durata) {       // l'ultima accensione la brucia
            bruciata = true;
            return false;
        }
        accesa = true;
        return true;
    }
    void spegni() { accesa = false; }
    void stampa() const {
        cout << "Lampadina: "
             << (bruciata ? "BRUCIATA" : (accesa ? "accesa" : "spenta"))
             << " (accensioni: " << accensioni << "/" << durata << ")" << endl;
    }
};

int main() {
    Lampadina l(2);
    for (int i = 1; i <= 3; i++) {
        bool ok = l.accendi();
        cout << "Accensione " << i << ": " << (ok ? "riuscita" : "fallita") << endl;
        l.spegni();
    }
    l.stampa();
    return 0;
}
