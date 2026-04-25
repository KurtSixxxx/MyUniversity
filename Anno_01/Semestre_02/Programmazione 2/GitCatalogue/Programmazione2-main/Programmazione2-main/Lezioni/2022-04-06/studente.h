#include "persona.h"
#include <iostream>
using namespace std;

#ifndef STUDENTE_H
#define STUDENTE_H

class Studente : public Persona
{
private:
    string matricola;

public:
    Studente(){};

    Studente(string n, string c, int e, string em, string m) : Persona(n, c, e, em), matricola(m){};

    Studente(const Studente &s) : Persona(s)
    {
        matricola = s.matricola;
    }

    void print()
    {
        Persona::print();
        cout << "Matrcola: " << matricola << endl;
    }
};

#endif