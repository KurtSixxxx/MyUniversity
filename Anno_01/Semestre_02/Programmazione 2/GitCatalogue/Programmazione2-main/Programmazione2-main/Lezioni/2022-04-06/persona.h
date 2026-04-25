#include <iostream>
using namespace std;

#ifndef PERSONA_H
#define PERSONA_H

class Persona
{
private:
    string nome;
    string cognome;
    int age;
    string email;
    int *temp;

public:
    // Costruttore di default
    Persona()
    {
        temp = new int[100]; // Non si trova sullo stack ma sull'heap
    };

    // Costruttore completo
    Persona(string n, string c, int e, string em) : nome(n), cognome(c), age(e), email(em)
    {
        temp = new int[100];
    };

    // Costruttore copy construct
    Persona(const Persona &p)
    {
        nome = p.nome;
        cognome = p.cognome;
        age = p.age;
        email = p.email;
        temp = new int[100];
    }

    void print()
    {
        char essere = 138;
        cout << "Mi chiamo " << nome << " " << cognome << ", ho " << age << " anni e la mia email " << essere << ": " << email << endl;
    }

    ~Persona() // ALT+126
    {
        delete[] temp; // Distruttore, non implementarlo porterebbe ad un memory leak
    }
};
#endif