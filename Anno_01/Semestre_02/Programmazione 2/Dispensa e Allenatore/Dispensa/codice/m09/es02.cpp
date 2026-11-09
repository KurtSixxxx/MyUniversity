// Esercizio 9.2 - "Trova l'errore" delle slide: public, protected, private nell'ereditarietà
#include <iostream>
using namespace std;

class Base {
public:
    void meth1() const { cout << "meth1 (public)" << endl; }
protected:
    void meth2() const { cout << "meth2 (protected)" << endl; }
private:
    void meth5() const { cout << "meth5 (private)" << endl; }
};

class Derived : public Base {
public:
    void meth3() const {
        meth2();               // OK: protected è visibile alle classi derivate
        // meth5();            // ERRORE: private non è visibile nemmeno alle derivate
    }
};

class DerivedDerived : public Derived {
public:
    void meth4() const { meth2(); }   // OK: protected resta visibile lungo la gerarchia
};

class DerivataPrivata : private Base {   // eredità PRIVATA: meth1 diventa private qui
public:
    void usa() const { meth1(); }        // dentro la classe si può usare
};

int main() {
    Derived d1;
    d1.meth1();
    d1.meth3();
    // d1.meth2();             // ERRORE delle slide: 'meth2' is protected within this context
    DerivedDerived d2;
    d2.meth4();
    DerivataPrivata dp;
    dp.usa();
    // dp.meth1();             // ERRORE: con eredità private, meth1 non è più pubblico
    return 0;
}
