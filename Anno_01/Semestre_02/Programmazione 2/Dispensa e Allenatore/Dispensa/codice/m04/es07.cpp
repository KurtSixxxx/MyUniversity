// Esercizio 4.7 - Copia superficiale contro copia profonda
#include <iostream>
using namespace std;

// Versione SBAGLIATA: nessun costruttore di copia -> il compilatore copia il PUNTATORE.
// (Non ha distruttore apposta: con il distruttore il programma farebbe un doppio delete.)
class Superficiale {
public:
    int* valore;
    Superficiale(int v) : valore(new int(v)) {}
};

// Versione GIUSTA: Regola dei Tre
class Profonda {
public:
    int* valore;
    Profonda(int v) : valore(new int(v)) {}
    Profonda(const Profonda& altra) : valore(new int(*altra.valore)) {}   // blocco nuovo
    Profonda& operator=(const Profonda& altra) {
        if (this != &altra) *valore = *altra.valore;   // stessa dimensione: basta copiare il valore
        return *this;
    }
    ~Profonda() { delete valore; }
};

int main() {
    Superficiale s1(10);
    Superficiale s2 = s1;          // copia membro a membro: s2.valore == s1.valore
    *s2.valore = 99;
    cout << "Superficiale: s1 = " << *s1.valore << ", s2 = " << *s2.valore
         << "  stesso blocco? " << (s1.valore == s2.valore ? "SI" : "no") << endl;
    delete s1.valore;              // libero UNA volta sola (s2.valore ora è dangling!)

    Profonda p1(10);
    Profonda p2 = p1;              // costruttore di copia profondo
    *p2.valore = 99;
    cout << "Profonda:     p1 = " << *p1.valore << ", p2 = " << *p2.valore
         << "  stesso blocco? " << (p1.valore == p2.valore ? "SI" : "no") << endl;
    return 0;
}
