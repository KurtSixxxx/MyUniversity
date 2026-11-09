// Esercizio 9.9 - Dipendenti: stipendio polimorfico e ordinamento di puntatori
#include <iostream>
#include <string>
using namespace std;

class Dipendente {
protected:
    string nome;
public:
    Dipendente(string n) : nome(n) {}
    virtual ~Dipendente() {}
    virtual double stipendio() const = 0;
    virtual string ruolo() const = 0;
    void stampa() const { cout << nome << " (" << ruolo() << "): " << stipendio() << " euro" << endl; }
};

class Impiegato : public Dipendente {
protected:
    double fisso;
public:
    Impiegato(string n, double f) : Dipendente(n), fisso(f) {}
    double stipendio() const override { return fisso; }
    string ruolo() const override { return "impiegato"; }
};

class Manager : public Impiegato {                // 3 livelli: Manager -> Impiegato -> Dipendente
    double bonus;
public:
    Manager(string n, double f, double b) : Impiegato(n, f), bonus(b) {}
    double stipendio() const override { return Impiegato::stipendio() + bonus; }   // riuso la base
    string ruolo() const override { return "manager"; }
};

class Operaio : public Dipendente {
    int ore;
    double pagaOraria;
public:
    Operaio(string n, int o, double p) : Dipendente(n), ore(o), pagaOraria(p) {}
    double stipendio() const override { return ore * pagaOraria; }
    string ruolo() const override { return "operaio"; }
};

// Ordino i PUNTATORI (non gli oggetti) per stipendio decrescente: insertion sort
void ordina(Dipendente* v[], int n) {
    for (int i = 1; i < n; i++) {
        Dipendente* x = v[i];
        int j = i - 1;
        while (j >= 0 && v[j]->stipendio() < x->stipendio()) { v[j + 1] = v[j]; j--; }
        v[j + 1] = x;
    }
}

int main() {
    Dipendente* staff[5] = {
        new Impiegato("Anna", 1600), new Operaio("Bruno", 160, 11.5),
        new Manager("Carla", 2500, 900), new Operaio("Dario", 120, 13),
        new Impiegato("Elisa", 1750)
    };
    ordina(staff, 5);
    double totale = 0;
    for (int i = 0; i < 5; i++) { staff[i]->stampa(); totale += staff[i]->stipendio(); }
    cout << "Monte stipendi: " << totale << " euro" << endl;
    for (int i = 0; i < 5; i++) delete staff[i];
    return 0;
}
