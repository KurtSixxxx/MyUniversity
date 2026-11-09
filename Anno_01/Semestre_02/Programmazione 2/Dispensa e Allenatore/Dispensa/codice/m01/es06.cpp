// Esercizio 1.6 - Orologio
#include <iostream>
using namespace std;

class Orologio {
private:
    int ore, minuti, secondi;

    // Metodo PRIVATO: è un dettaglio interno, da fuori non serve
    void stampaDueCifre(int x) const {
        if (x < 10) cout << "0";
        cout << x;
    }

public:
    Orologio(int h, int m, int s) {
        bool valido = h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60;
        ore = valido ? h : 0;
        minuti = valido ? m : 0;
        secondi = valido ? s : 0;
    }
    void avanza() {                       // +1 secondo con i riporti
        secondi++;
        if (secondi == 60) { secondi = 0; minuti++; }
        if (minuti == 60)  { minuti = 0;  ore++; }
        if (ore == 24)     { ore = 0; }
    }
    void stampa() const {
        stampaDueCifre(ore);    cout << ":";
        stampaDueCifre(minuti); cout << ":";
        stampaDueCifre(secondi); cout << endl;
    }
};

int main() {
    Orologio o(23, 59, 58);
    for (int i = 0; i < 3; i++) {
        o.stampa();
        o.avanza();
    }
    Orologio sbagliato(25, 70, 0);        // non valido: parte da mezzanotte
    sbagliato.stampa();
    return 0;
}
