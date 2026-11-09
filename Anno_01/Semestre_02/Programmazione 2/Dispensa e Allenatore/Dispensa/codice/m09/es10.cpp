// Esercizio 9.10 - Ereditarietà multipla e problema del diamante (dalle slide)
#include <iostream>
using namespace std;

// --- Senza virtual: D contiene DUE copie di A ---
class A { public: int x = 5; A() { cout << "  costruisco A" << endl; } };
class B : public A {};
class C : public A {};
class D : public B, public C {};

// --- Con ereditarietà virtual: UNA sola copia di A ---
class A2 { public: int x = 5; A2() { cout << "  costruisco A2" << endl; } };
class B2 : public virtual A2 {};
class C2 : public virtual A2 {};
class D2 : public B2, public C2 {};

// --- Uso tipico e innocuo: due capacità indipendenti ---
class Volante { public: void vola() const { cout << "  volo" << endl; } };
class Nuotante { public: void nuota() const { cout << "  nuoto" << endl; } };
class Anatra : public Volante, public Nuotante {};

int main() {
    cout << "D senza virtual:" << endl;
    D d;
    // cout << d.x;                       // ERRORE: 'x' è ambiguo (quella di B o quella di C?)
    d.B::x = 1; d.C::x = 2;               // due copie distinte
    cout << "  B::x = " << d.B::x << ", C::x = " << d.C::x << endl;

    cout << "D2 con ereditarieta' virtual:" << endl;
    D2 d2;
    cout << "  d2.x = " << d2.x << " (richiesta non piu' ambigua)" << endl;

    cout << "Anatra:" << endl;
    Anatra a;
    a.vola();
    a.nuota();
    return 0;
}
