

#include <iostream>
using namespace std;

// PROBLEMA DEL DIAMANTE (EREDITARIETA' MULTIPLA)

class A{
public:
    void meth(){ cout << "A::meth()" << endl;}
    int x = 5;
};

class B: public virtual A{
    public:
    void meth(){ cout << "B::meth()" << endl;}
};

class C: public virtual A{
    public:
    void meth(){ cout << "C::meth()" << endl;}
};

class D: public B, public C{};

int main(){

    D d;
 //   d.meth(); // ambiguo
    d.B::meth();
    d.C::meth();
    d.A::meth();
    cout << d.x << endl;
    return 0;
}
