// Modulo 1 - Laboratorio a step: Biblioteca
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// ===== STEP 1 =====  Classe con attributi privati, costruttore, getter, stampa
// ===== STEP 2 =====  Metodi che cambiano lo stato SOLO se l'operazione è valida
class Libro {
private:
    string titolo;
    string autore;
    int anno;
    bool disponibile;

public:
    // Costruttore "vuoto": serve per poter creare array di Libro (STEP 4)
    Libro() {
        titolo = "?";
        autore = "?";
        anno = 0;
        disponibile = false;
    }

    // STEP 2: il costruttore corregge i dati non validi
    Libro(string t, string a, int y) {
        titolo = (t == "") ? "Senza titolo" : t;
        autore = a;
        anno = (y < 1450 || y > 2026) ? 0 : y;   // 1450 = invenzione della stampa
        disponibile = true;
    }

    // STEP 2: prestito e restituzione rispettano lo stato
    bool presta() {
        if (!disponibile) return false;     // già in prestito: rifiuto
        disponibile = false;
        return true;
    }
    bool restituisci() {
        if (disponibile) return false;      // non era in prestito: rifiuto
        disponibile = true;
        return true;
    }

    string getTitolo() const { return titolo; }
    string getAutore() const { return autore; }
    int getAnno() const { return anno; }
    bool isDisponibile() const { return disponibile; }

    void stampa() const {
        cout << "  \"" << titolo << "\" di " << autore << " (" << anno << ") - "
             << (disponibile ? "disponibile" : "in prestito") << endl;
    }
};

// ===== STEP 4 =====  Una classe che CONTIENE altri oggetti (aggregazione)
class Biblioteca {
private:
    static const int MAX = 10;
    Libro scaffale[MAX];        // array di oggetti Libro: serve Libro()
    int n;                      // quanti libri ci sono davvero

public:
    Biblioteca() { n = 0; }

    bool aggiungi(Libro l) {
        if (n == MAX) return false;         // scaffale pieno
        scaffale[n] = l;
        n++;
        return true;
    }

    int getNumeroLibri() const { return n; }

    // La Biblioteca manda un MESSAGGIO al Libro: scaffale[i].presta()
    bool prestaTitolo(string titolo) {
        for (int i = 0; i < n; i++)
            if (scaffale[i].getTitolo() == titolo)
                return scaffale[i].presta();
        return false;                       // titolo non trovato
    }

    int contaDisponibili() const {
        int c = 0;
        for (int i = 0; i < n; i++)
            if (scaffale[i].isDisponibile()) c++;
        return c;
    }

    // ===== STEP 5 =====  Ricerca: restituisce l'indice, -1 se non c'è
    int indicePiuVecchio() const {
        if (n == 0) return -1;
        int iMin = 0;
        for (int i = 1; i < n; i++)
            if (scaffale[i].getAnno() < scaffale[iMin].getAnno())
                iMin = i;
        return iMin;
    }

    // Restituisce una COPIA del libro i-esimo (chi la riceve non tocca lo scaffale)
    Libro getLibro(int i) const {
        if (i < 0 || i >= n) return Libro();
        return scaffale[i];
    }

    void stampaAutore(string autore) const {
        cout << "Libri di " << autore << ":" << endl;
        for (int i = 0; i < n; i++)
            if (scaffale[i].getAutore() == autore)
                scaffale[i].stampa();
    }

    void stampa() const {
        cout << "Biblioteca (" << n << " libri, " << contaDisponibili() << " disponibili):" << endl;
        for (int i = 0; i < n; i++) scaffale[i].stampa();
    }
};

int main() {
    // ----- STEP 1 e 2: un oggetto da solo -----
    cout << "=== STEP 1-2 ===" << endl;
    Libro l1("Il nome della rosa", "Eco", 1980);
    Libro l2("", "Anonimo", 3000);           // dati sbagliati: corretti dal costruttore
    l1.stampa();
    l2.stampa();
    cout << "presta l1: " << l1.presta() << endl;     // 1 = true
    cout << "presta l1: " << l1.presta() << endl;     // 0 = false (già prestato)
    cout << "restituisci l1: " << l1.restituisci() << endl;

    // ----- STEP 3: array di oggetti + prestiti casuali -----
    cout << "\n=== STEP 3 ===" << endl;
    srand(111222333);
    const int N = 4;
    Libro v[N] = {
        Libro("Odissea", "Omero", 1488),
        Libro("I promessi sposi", "Manzoni", 1840),
        Libro("Il Gattopardo", "Tomasi", 1958),
        Libro("Fosca", "Tarchetti", 1869)
    };
    for (int k = 0; k < 5; k++) {
        int i = rand() % N;
        cout << "tentativo di prestito di \"" << v[i].getTitolo() << "\": "
             << (v[i].presta() ? "ok" : "RIFIUTATO") << endl;
    }

    // ----- STEP 4: la Biblioteca contiene i libri -----
    cout << "\n=== STEP 4 ===" << endl;
    Biblioteca b;
    for (int i = 0; i < N; i++) b.aggiungi(v[i]);    // COPIE dei libri (con il loro stato)
    b.aggiungi(Libro("Il nome della rosa", "Eco", 1980));
    b.aggiungi(Libro("Baudolino", "Eco", 2000));
    b.prestaTitolo("Baudolino");
    b.stampa();

    // ----- STEP 5: ricerche -----
    cout << "\n=== STEP 5 ===" << endl;
    b.stampaAutore("Eco");
    int iv = b.indicePiuVecchio();
    cout << "Il piu' vecchio (indice " << iv << "):" << endl;
    b.getLibro(iv).stampa();
    return 0;
}
