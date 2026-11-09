// Modulo 4 - Pattern: classe che possiede memoria dinamica + Regola dei Tre
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <stdexcept>
using namespace std;

class Vettore {
private:
    int* dati;          // blocco nello HEAP: lo possiede l'oggetto
    int n;

public:
    // 1. COSTRUTTORE (con parametro di default e lista di inizializzazione)
    Vettore(int dim = 3) : dati(nullptr), n(dim) {
        if (n < 1) n = 1;
        dati = new int[n];
        for (int i = 0; i < n; i++) dati[i] = 0;
        cout << "  [costruttore n=" << n << "]" << endl;
    }

    // 2. DISTRUTTORE: restituisce la memoria presa dal costruttore
    ~Vettore() {
        cout << "  [distruttore n=" << n << "]" << endl;
        delete[] dati;
    }

    // 3. COSTRUTTORE DI COPIA: copia PROFONDA (un blocco nuovo tutto suo)
    Vettore(const Vettore& altro) : dati(nullptr), n(altro.n) {
        dati = new int[n];
        for (int i = 0; i < n; i++) dati[i] = altro.dati[i];
        cout << "  [costruttore di copia]" << endl;
    }

    // 4. OPERATORE DI ASSEGNAMENTO: libera il vecchio, copia il nuovo
    Vettore& operator=(const Vettore& altro) {
        cout << "  [operator=]" << endl;
        if (this == &altro) return *this;     // a = a: non fare danni
        delete[] dati;                        // libero il MIO vecchio blocco
        n = altro.n;
        dati = new int[n];                    // ne prendo uno della misura giusta
        for (int i = 0; i < n; i++) dati[i] = altro.dati[i];
        return *this;                         // permette a = b = c
    }

    // Accesso controllato: eccezione se l'indice è fuori dai limiti
    void set(int i, int valore) {
        if (i < 0 || i >= n) throw out_of_range("indice non valido");
        dati[i] = valore;
    }
    int get(int i) const {
        if (i < 0 || i >= n) throw out_of_range("indice non valido");
        return dati[i];
    }
    int size() const { return n; }

    void stampa() const {
        cout << "[ ";
        for (int i = 0; i < n; i++) cout << dati[i] << " ";
        cout << "]" << endl;
    }
};

int main() {
    cout << "Creo a:" << endl;
    Vettore a(3);
    a.set(0, 10); a.set(1, 20); a.set(2, 30);

    cout << "Creo b come copia di a:" << endl;
    Vettore b = a;              // costruttore di copia (b NASCE ora)
    b.set(0, 99);               // modifico solo b
    cout << "a = "; a.stampa();
    cout << "b = "; b.stampa();

    cout << "Creo c e poi assegno c = a:" << endl;
    Vettore c(5);
    c = a;                      // operator= (c esisteva già)
    cout << "c = "; c.stampa();

    cout << "Provo un indice sbagliato:" << endl;
    try {
        a.set(7, 1);
    } catch (const out_of_range& e) {
        cout << "  eccezione catturata: " << e.what() << endl;
    }

    cout << "Fine del main: distruzione in ordine inverso (c, b, a)" << endl;
    return 0;
}
