// Esercizio 4.6 - Tempo con eccezioni invece di exit(1)
#include <iostream>
#include <stdexcept>
using namespace std;

class Tempo {
private:
    int ore, minuti, secondi;

public:
    Tempo(int h = 0, int m = 0, int s = 0) : ore(0), minuti(0), secondi(0) {
        setOre(h);            // se un valore è sbagliato, il costruttore lancia:
        setMinuti(m);         // l'oggetto NON viene creato
        setSecondi(s);
    }
    void setOre(int h) {
        if (h < 0 || h > 23) throw invalid_argument("ore valide: 0-23");
        ore = h;
    }
    void setMinuti(int m) {
        if (m < 0 || m > 59) throw invalid_argument("minuti validi: 0-59");
        minuti = m;
    }
    void setSecondi(int s) {
        if (s < 0 || s > 59) throw invalid_argument("secondi validi: 0-59");
        secondi = s;
    }
    void stampa() const { cout << ore << "h " << minuti << "m " << secondi << "s" << endl; }
};

int main() {
    Tempo t(10, 30, 0);
    t.stampa();

    try {
        t.setOre(100);
        cout << "non arrivo qui" << endl;
    } catch (const invalid_argument& e) {
        cout << "Eccezione: " << e.what() << endl;
    }
    t.stampa();                       // t non è stato modificato

    try {
        Tempo sbagliato(12, 75, 0);   // lancia dal costruttore
        sbagliato.stampa();
    } catch (const exception& e) {    // exception è la "madre" di tutte le eccezioni standard
        cout << "Costruzione fallita: " << e.what() << endl;
    }

    try {
        throw 42;                     // si può lanciare anche un int...
    } catch (const invalid_argument& e) {
        cout << "non sono io" << endl;
    } catch (...) {                   // ...che viene preso dal catch "pigliatutto"
        cout << "Eccezione sconosciuta catturata" << endl;
    }
    return 0;
}
