// Modulo 4 - Laboratorio a step: playlist musicale
// Compila: g++ -g lab.cpp -o lab.exe
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

// ===== STEP 1 =====  Costruttori, lista di inizializzazione, const
class Brano {
private:
    string titolo;
    string artista;
    int durata;                                   // secondi

public:
    Brano() : titolo("?"), artista("?"), durata(0) {}            // di default
    Brano(string t, string a, int d) : titolo(t), artista(a), durata(d) {
        if (durata < 0) durata = 0;
    }
    Brano(string t) : Brano(t, "Sconosciuto", 180) {}            // costruttore con delega

    string getTitolo() const { return titolo; }
    int getDurata() const { return durata; }
    void stampa() const {
        cout << titolo << " - " << artista << " (" << durata / 60 << ":"
             << (durata % 60 < 10 ? "0" : "") << durata % 60 << ")";
    }
};

// ===== STEP 2 =====  Una classe che possiede un array dinamico: costruttore + distruttore
class Playlist {
private:
    string nome;
    Brano* brani;          // array nello heap
    int n, cap;
    static int vive;       // ===== STEP 6 ===== quante playlist esistono ora

    // ===== STEP 3 =====  crescita (metodo privato di servizio)
    void cresci() {
        cap *= 2;
        Brano* nuovo = new Brano[cap];
        for (int i = 0; i < n; i++) nuovo[i] = brani[i];
        delete[] brani;
        brani = nuovo;
    }

public:
    Playlist(string nomePlaylist) : nome(nomePlaylist), brani(new Brano[2]), n(0), cap(2) {
        vive++;
        cout << "  + creata \"" << nome << "\" (vive: " << vive << ")" << endl;
    }

    ~Playlist() {
        vive--;
        cout << "  - distrutta \"" << nome << "\" (vive: " << vive << ")" << endl;
        delete[] brani;
    }

    // ===== STEP 4 =====  Costruttore di copia PROFONDO
    Playlist(const Playlist& altra)
        : nome(altra.nome + " (copia)"), brani(new Brano[altra.cap]), n(altra.n), cap(altra.cap) {
        for (int i = 0; i < n; i++) brani[i] = altra.brani[i];
        vive++;
        cout << "  + copiata in \"" << nome << "\" (vive: " << vive << ")" << endl;
    }

    // ===== STEP 5 =====  Operatore di assegnamento (Regola dei Tre completa)
    Playlist& operator=(const Playlist& altra) {
        if (this == &altra) return *this;          // autoassegnamento
        Brano* nuovo = new Brano[altra.cap];       // prima alloco (se fallisce, non ho rotto nulla)
        for (int i = 0; i < altra.n; i++) nuovo[i] = altra.brani[i];
        delete[] brani;                            // poi libero il vecchio
        brani = nuovo;
        n = altra.n;
        cap = altra.cap;
        // il nome NON si copia: la playlist resta "se stessa"
        return *this;
    }

    void aggiungi(const Brano& b) {
        if (n == cap) cresci();
        brani[n++] = b;
    }

    // ===== STEP 6 =====  Eccezione invece di un valore "a caso"
    Brano& at(int i) {
        if (i < 0 || i >= n) throw out_of_range("brano " + to_string(i) + " inesistente");
        return brani[i];
    }

    int durataTotale() const {
        int s = 0;
        for (int i = 0; i < n; i++) s += brani[i].getDurata();
        return s;
    }

    static int quanteVive() { return vive; }      // metodo statico: niente this

    void stampa() const {
        cout << "Playlist \"" << nome << "\" (" << n << " brani, " << durataTotale() << " s):" << endl;
        for (int i = 0; i < n; i++) {
            cout << "  " << i + 1 << ". ";
            brani[i].stampa();
            cout << endl;
        }
    }
};

int Playlist::vive = 0;     // definizione dell'attributo statico (UNA volta, fuori dalla classe)

int main() {
    cout << "=== STEP 1 ===" << endl;
    Brano b1("Volare", "Modugno", 205);
    Brano b2("Azzurro");                         // delega: artista e durata di default
    b1.stampa(); cout << endl;
    b2.stampa(); cout << endl;

    cout << "\n=== STEP 2-3 ===" << endl;
    Playlist p("Classici");
    p.aggiungi(b1);
    p.aggiungi(b2);
    p.aggiungi(Brano("Caruso", "Dalla", 302));    // terzo brano: la capacità raddoppia
    p.stampa();

    cout << "\n=== STEP 4 ===" << endl;
    {
        Playlist q = p;                          // costruttore di copia
        q.aggiungi(Brano("Albachiara", "Vasco", 254));
        q.stampa();                              // 4 brani
        p.stampa();                              // ancora 3: le copie sono indipendenti
    }                                            // q muore qui

    cout << "\n=== STEP 5 ===" << endl;
    Playlist r("Vuota");
    r = p;                                       // operator=
    r = r;                                       // autoassegnamento: nessun danno
    r.stampa();

    cout << "\n=== STEP 6 ===" << endl;
    cout << "Playlist vive: " << Playlist::quanteVive() << endl;
    try {
        cout << "Brano 0: " << p.at(0).getTitolo() << endl;
        string t = p.at(9).getTitolo();                       // lancia: si salta al catch
        cout << "questa riga non viene eseguita: " << t << endl;
    } catch (const out_of_range& e) {
        cout << "Errore: " << e.what() << endl;
    }
    cout << "Fine del main" << endl;
    return 0;
}
