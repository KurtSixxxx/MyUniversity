// Esercizio 1.4 - Termometro
#include <iostream>
using namespace std;

class Termometro {
private:
    double celsius;      // UNA sola rappresentazione interna: niente dati duplicati
    static constexpr double ZERO_ASSOLUTO = -273.15;

public:
    Termometro() { celsius = 20; }
    bool setCelsius(double c) {
        if (c < ZERO_ASSOLUTO) return false;
        celsius = c;
        return true;
    }
    double getCelsius() const { return celsius; }
    // Le altre scale si CALCOLANO: chi usa la classe non sa come è fatta dentro
    double getFahrenheit() const { return celsius * 9 / 5 + 32; }
    double getKelvin() const { return celsius - ZERO_ASSOLUTO; }
};

int main() {
    Termometro t;
    t.setCelsius(100);
    cout << t.getCelsius() << " C = " << t.getFahrenheit() << " F = "
         << t.getKelvin() << " K" << endl;
    if (!t.setCelsius(-300))
        cout << "-300 C rifiutato: sotto lo zero assoluto" << endl;
    cout << "Temperatura rimasta: " << t.getCelsius() << " C" << endl;
    return 0;
}
