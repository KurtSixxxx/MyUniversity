// Esercizio 4.8 - Una stringa fatta in casa (char* dinamico + Regola dei Tre)
#include <iostream>
using namespace std;

class MiaStringa {
private:
    char* testo;      // terminato da '\0', come in C
    int len;

    static int lunghezza(const char* s) {
        int l = 0;
        while (s[l] != '\0') l++;
        return l;
    }
    void copiaDa(const char* s, int l) {        // alloca e copia (usata in più punti)
        len = l;
        testo = new char[len + 1];
        for (int i = 0; i < len; i++) testo[i] = s[i];
        testo[len] = '\0';
    }

public:
    MiaStringa(const char* s = "") { copiaDa(s, lunghezza(s)); }
    MiaStringa(const MiaStringa& altra) { copiaDa(altra.testo, altra.len); }
    MiaStringa& operator=(const MiaStringa& altra) {
        if (this != &altra) {
            delete[] testo;
            copiaDa(altra.testo, altra.len);
        }
        return *this;
    }
    ~MiaStringa() { delete[] testo; }

    int size() const { return len; }

    MiaStringa concatena(const MiaStringa& altra) const {
        char* tmp = new char[len + altra.len + 1];
        for (int i = 0; i < len; i++) tmp[i] = testo[i];
        for (int i = 0; i < altra.len; i++) tmp[len + i] = altra.testo[i];
        tmp[len + altra.len] = '\0';
        MiaStringa risultato(tmp);              // il costruttore fa la SUA copia...
        delete[] tmp;                           // ...quindi tmp va liberato
        return risultato;
    }

    void maiuscolo() {
        for (int i = 0; i < len; i++)
            if (testo[i] >= 'a' && testo[i] <= 'z') testo[i] = testo[i] - 'a' + 'A';
    }

    void stampa() const { cout << "\"" << testo << "\" (" << len << ")" << endl; }
};

int main() {
    MiaStringa a("Ciao"), b(" mondo");
    MiaStringa c = a.concatena(b);
    c.stampa();
    MiaStringa d = c;           // copia
    d.maiuscolo();              // modifico SOLO la copia
    c.stampa();
    d.stampa();
    a = d;                      // assegnamento
    a.stampa();
    return 0;
}
