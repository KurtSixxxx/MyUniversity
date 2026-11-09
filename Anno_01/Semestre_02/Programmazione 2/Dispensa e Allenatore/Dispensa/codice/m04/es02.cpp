// Esercizio 4.2 - Quando nascono e quando muoiono gli oggetti?
#include <iostream>
#include <string>
using namespace std;

class Traccia {
private:
    string nome;
public:
    Traccia(string n) : nome(n) { cout << "  nasce " << nome << endl; }
    ~Traccia() { cout << "  muore " << nome << endl; }
};

Traccia globale("GLOBALE");              // nasce PRIMA del main, muore DOPO

void funzione() {
    cout << "inizio funzione" << endl;
    Traccia locale("LOCALE_F");
    cout << "fine funzione" << endl;
}                                        // LOCALE_F muore qui

int main() {
    cout << "inizio main" << endl;
    Traccia a("A");
    {
        Traccia b("B");
        Traccia c("C");
        cout << "fine blocco" << endl;
    }                                    // muoiono C e poi B (ordine inverso)
    funzione();
    Traccia* h = new Traccia("HEAP");    // nello heap: vive finché non faccio delete
    Traccia d("D");
    delete h;                            // HEAP muore ORA, prima di D
    cout << "fine main" << endl;
    return 0;
}                                        // muoiono D e poi A
