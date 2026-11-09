// Esercizio 9.1 - Persona e Studente: costruttori e distruttori in catena
#include <iostream>
#include <string>
using namespace std;

class Persona {
protected:
    string nome;
public:
    Persona(string n) : nome(n) { cout << "costruttore Persona(" << nome << ")" << endl; }
    ~Persona() { cout << "distruttore Persona(" << nome << ")" << endl; }
    void saluta() const { cout << "Ciao, sono " << nome << endl; }
};

class Studente : public Persona {
    int matricola;                                       // ESTENSIONE: un attributo in più
public:
    Studente(string n, int m) : Persona(n), matricola(m) {   // chiamo il costruttore della base
        cout << "costruttore Studente(" << matricola << ")" << endl;
    }
    ~Studente() { cout << "distruttore Studente(" << matricola << ")" << endl; }
    void presentaMatricola() const {                     // ESTENSIONE: un metodo in più
        cout << nome << " ha matricola " << matricola << endl;   // nome è protected: lo vedo
    }
};

int main() {
    {
        Studente s("Mario", 1000123);
        s.saluta();                  // ereditato da Persona
        s.presentaMatricola();       // aggiunto in Studente
        cout << "--- fine blocco ---" << endl;
    }
    return 0;
}
