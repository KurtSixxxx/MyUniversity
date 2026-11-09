// Esercizio 9.7 - RTTI: typeid e dynamic_cast su un array misto
#include <iostream>
#include <typeinfo>
#include <cstdlib>
using namespace std;

class Veicolo {
public:
    virtual ~Veicolo() {}
    virtual int ruote() const = 0;
};
class Auto : public Veicolo { public: int ruote() const override { return 4; } };
class Moto : public Veicolo { public: int ruote() const override { return 2; } };
class Camion : public Veicolo {
    int assi;
public:
    Camion(int a) : assi(a) {}
    int ruote() const override { return assi * 4; }
    int getAssi() const { return assi; }
};

int main() {
    srand(111222333);
    const int N = 12;
    Veicolo* parcheggio[N];
    for (int i = 0; i < N; i++) {
        int t = rand() % 3;
        if (t == 0) parcheggio[i] = new Auto();
        else if (t == 1) parcheggio[i] = new Moto();
        else parcheggio[i] = new Camion(2 + rand() % 3);
    }
    int nAuto = 0, nMoto = 0, nCamion = 0, ruoteTotali = 0, assiTotali = 0;
    for (int i = 0; i < N; i++) {
        ruoteTotali += parcheggio[i]->ruote();                    // polimorfismo: non serve sapere il tipo
        if (typeid(*parcheggio[i]) == typeid(Auto)) nAuto++;       // typeid: il tipo VERO dell'oggetto
        else if (typeid(*parcheggio[i]) == typeid(Moto)) nMoto++;
        Camion* c = dynamic_cast<Camion*>(parcheggio[i]);          // dynamic_cast: è un Camion?
        if (c != nullptr) { nCamion++; assiTotali += c->getAssi(); }   // solo Camion ha getAssi()
    }
    cout << "auto " << nAuto << ", moto " << nMoto << ", camion " << nCamion << endl;
    cout << "ruote totali " << ruoteTotali << ", assi dei camion " << assiTotali << endl;
    cout << "nome del tipo secondo il compilatore: " << typeid(*parcheggio[0]).name() << endl;
    for (int i = 0; i < N; i++) delete parcheggio[i];
    return 0;
}
