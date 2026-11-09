// Esercizio 10.8 - MiaStringa con +, ==, [] e << (seguito dell'Esercizio 4.8)
#include <iostream>
#include <stdexcept>
using namespace std;

class MiaStringa {
    char* t;
    int len;
    void copia(const char* s, int l) {
        len = l;
        t = new char[len + 1];
        for (int i = 0; i < len; i++) t[i] = s[i];
        t[len] = '\0';
    }
public:
    MiaStringa(const char* s = "") { int l = 0; while (s[l]) l++; copia(s, l); }
    MiaStringa(const MiaStringa& o) { copia(o.t, o.len); }
    MiaStringa& operator=(const MiaStringa& o) {
        if (this != &o) { delete[] t; copia(o.t, o.len); }
        return *this;
    }
    ~MiaStringa() { delete[] t; }

    char& operator[](int i) {
        if (i < 0 || i >= len) throw out_of_range("indice fuori dalla stringa");
        return t[i];
    }
    MiaStringa operator+(const MiaStringa& o) const {
        MiaStringa r;
        delete[] r.t;
        r.len = len + o.len;
        r.t = new char[r.len + 1];
        for (int i = 0; i < len; i++) r.t[i] = t[i];
        for (int i = 0; i < o.len; i++) r.t[len + i] = o.t[i];
        r.t[r.len] = '\0';
        return r;
    }
    bool operator==(const MiaStringa& o) const {
        if (len != o.len) return false;
        for (int i = 0; i < len; i++) if (t[i] != o.t[i]) return false;
        return true;
    }
    friend ostream& operator<<(ostream& os, const MiaStringa& s) { return os << s.t; }
};

int main() {
    MiaStringa a("Prog"), b("rammazione"), c = a + b;
    cout << c << endl;
    c[0] = 'p';                                   // [] restituisce char&: posso scrivere
    cout << c << endl;
    cout << (a + b == MiaStringa("Programmazione") ? "uguali" : "diverse") << endl;
    try { c[100] = 'x'; } catch (const out_of_range& e) { cout << "errore: " << e.what() << endl; }
    return 0;
}
