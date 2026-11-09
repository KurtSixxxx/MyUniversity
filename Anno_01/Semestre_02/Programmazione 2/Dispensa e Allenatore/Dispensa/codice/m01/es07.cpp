// Esercizio 1.7 - Studente con libretto
#include <iostream>
#include <string>
using namespace std;

class Studente {
private:
    string nome;
    int voti[30];        // il libretto: massimo 30 esami
    int nVoti;

public:
    Studente(string n) { nome = n; nVoti = 0; }

    bool aggiungiVoto(int v) {
        if (v < 18 || v > 30) return false;   // voto non valido
        if (nVoti == 30) return false;        // libretto pieno
        voti[nVoti] = v;
        nVoti++;
        return true;
    }
    double media() const {
        if (nVoti == 0) return 0;
        int somma = 0;
        for (int i = 0; i < nVoti; i++) somma += voti[i];
        return (double)somma / nVoti;
    }
    int votoMassimo() const {
        int m = 0;
        for (int i = 0; i < nVoti; i++)
            if (voti[i] > m) m = voti[i];
        return m;
    }
    void stampa() const {
        cout << nome << ": " << nVoti << " esami, media " << media()
             << ", voto massimo " << votoMassimo() << endl;
    }
};

int main() {
    Studente s("Mario");
    int prove[] = {28, 15, 30, 24, 33, 27};
    for (int i = 0; i < 6; i++)
        if (!s.aggiungiVoto(prove[i]))
            cout << "Voto " << prove[i] << " rifiutato" << endl;
    s.stampa();
    return 0;
}
