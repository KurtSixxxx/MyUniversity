// Esercizio 9.4 - Principio di sostituzione di Liskov (dalle slide)
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nome;
public:
    Persona(string n) : nome(n) {}
    string getNome() const { return nome; }
    virtual ~Persona() {}
};

class Studente : public Persona {
    int esamiSostenuti = 0;
public:
    Studente(string n) : Persona(n) {}
    void superaEsame() { esamiSostenuti++; }
    int getEsami() const { return esamiSostenuti; }
};

void cammina(const Persona& p) { cout << p.getNome() << " cammina" << endl; }
void studia(Studente& s) { s.superaEsame(); cout << s.getNome() << " ha " << s.getEsami() << " esami" << endl; }

int main() {
    Persona p("Paolo");
    Studente s("Sara");
    cammina(p);      // OK
    cammina(s);      // OK: uno studente E' una persona (dove serve una Persona, va bene uno Studente)
    studia(s);       // OK
    // studia(p);    // ERRORE: una persona qualunque NON è uno studente
    Persona* elenco[2] = {&p, &s};   // array di Persona* che contiene anche uno Studente
    for (int i = 0; i < 2; i++) cammina(*elenco[i]);
    return 0;
}
