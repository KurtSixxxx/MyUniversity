// Esercizio 9.6 - Perché il distruttore della base deve essere virtual
#include <iostream>
using namespace std;

class BaseSbagliata {
public:
    ~BaseSbagliata() { cout << "  ~BaseSbagliata" << endl; }      // NON virtual
};
class DerivataSbagliata : public BaseSbagliata {
    int* buffer;
public:
    DerivataSbagliata() : buffer(new int[1000]) {}
    ~DerivataSbagliata() { cout << "  ~DerivataSbagliata (libero il buffer)" << endl; delete[] buffer; }
};

class BaseGiusta {
public:
    virtual ~BaseGiusta() { cout << "  ~BaseGiusta" << endl; }    // virtual
};
class DerivataGiusta : public BaseGiusta {
    int* buffer;
public:
    DerivataGiusta() : buffer(new int[1000]) {}
    ~DerivataGiusta() override { cout << "  ~DerivataGiusta (libero il buffer)" << endl; delete[] buffer; }
};

int main() {
    cout << "delete tramite puntatore alla base, distruttore NON virtual:" << endl;
    BaseSbagliata* p = new DerivataSbagliata();
    delete p;            // comportamento indefinito: di solito parte solo ~BaseSbagliata -> leak
    cout << "delete tramite puntatore alla base, distruttore virtual:" << endl;
    BaseGiusta* q = new DerivataGiusta();
    delete q;            // partono entrambi, prima la derivata
    return 0;
}
