// Esercizio 9.3 - Binding statico contro binding dinamico
#include <iostream>
using namespace std;

class Veicolo {
public:
    void descriviStatico() const { cout << "  [statico]  sono un veicolo generico" << endl; }
    virtual void descriviDinamico() const { cout << "  [dinamico] sono un veicolo generico" << endl; }
    virtual ~Veicolo() {}
};

class Moto : public Veicolo {
public:
    void descriviStatico() const { cout << "  [statico]  sono una moto" << endl; }       // NON virtual nella base
    void descriviDinamico() const override { cout << "  [dinamico] sono una moto" << endl; }
};

int main() {
    Moto m;
    cout << "Chiamata diretta sull'oggetto Moto:" << endl;
    m.descriviStatico();
    m.descriviDinamico();

    Veicolo* p = &m;                  // puntatore alla BASE che punta a una Moto
    cout << "Chiamata tramite Veicolo*:" << endl;
    p->descriviStatico();             // decide il TIPO DEL PUNTATORE (Veicolo): a compile-time
    p->descriviDinamico();            // decide il TIPO DELL'OGGETTO (Moto): a run-time

    Veicolo& r = m;                   // vale anche con le reference
    cout << "Chiamata tramite Veicolo&:" << endl;
    r.descriviDinamico();

    Veicolo copia = m;                // COPIA per valore: si perde la parte Moto (slicing)
    cout << "Chiamata su una copia di tipo Veicolo:" << endl;
    copia.descriviDinamico();
    return 0;
}
