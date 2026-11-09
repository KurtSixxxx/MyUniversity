// Esercizio 4.9 - Classe Matrice con int** e Regola dei Tre
#include <iostream>
#include <stdexcept>
using namespace std;

class Matrice {
private:
    int r, c;
    int** m;

    void allocaMemoria() {
        m = new int*[r];
        for (int i = 0; i < r; i++) {
            m[i] = new int[c];
            for (int j = 0; j < c; j++) m[i][j] = 0;
        }
    }
    void liberaMemoria() {
        for (int i = 0; i < r; i++) delete[] m[i];
        delete[] m;
    }

public:
    Matrice(int righe, int colonne) : r(righe), c(colonne), m(nullptr) {
        if (r <= 0 || c <= 0) throw invalid_argument("dimensioni non valide");
        allocaMemoria();
    }
    Matrice(const Matrice& altra) : r(altra.r), c(altra.c), m(nullptr) {
        allocaMemoria();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) m[i][j] = altra.m[i][j];
    }
    Matrice& operator=(const Matrice& altra) {
        if (this == &altra) return *this;
        liberaMemoria();                         // le dimensioni possono essere diverse
        r = altra.r; c = altra.c;
        allocaMemoria();
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) m[i][j] = altra.m[i][j];
        return *this;
    }
    ~Matrice() { liberaMemoria(); }

    void set(int i, int j, int v) {
        if (i < 0 || i >= r || j < 0 || j >= c) throw out_of_range("cella fuori dalla matrice");
        m[i][j] = v;
    }
    int get(int i, int j) const {
        if (i < 0 || i >= r || j < 0 || j >= c) throw out_of_range("cella fuori dalla matrice");
        return m[i][j];
    }
    Matrice somma(const Matrice& altra) const {
        if (r != altra.r || c != altra.c) throw invalid_argument("dimensioni diverse");
        Matrice ris(r, c);
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) ris.m[i][j] = m[i][j] + altra.m[i][j];
        return ris;
    }
    void stampa() const {
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) cout << m[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    try {
        Matrice a(2, 3);
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++) a.set(i, j, i * 3 + j);
        Matrice b = a;                 // copia profonda
        b.set(0, 0, 100);
        Matrice s = a.somma(b);
        cout << "a:" << endl; a.stampa();
        cout << "a + b:" << endl; s.stampa();
        Matrice piccola(1, 1);
        piccola = s;                   // assegnamento con dimensioni diverse
        cout << "piccola dopo l'assegnamento:" << endl; piccola.stampa();
        a.get(5, 5);                   // lancia out_of_range
    } catch (const exception& e) {
        cout << "Errore: " << e.what() << endl;
    }
    try {
        Matrice x(2, 2), y(3, 3);
        x.somma(y);
    } catch (const invalid_argument& e) {
        cout << "Errore: " << e.what() << endl;
    }
    return 0;
}
