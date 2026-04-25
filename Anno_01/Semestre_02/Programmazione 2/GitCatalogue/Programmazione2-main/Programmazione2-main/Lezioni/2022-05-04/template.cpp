#include <iostream>
#include <typeinfo>
using namespace std;

template <class T1, class T2>
class A
{
private:
    T1 a;
    T2 b;

public:
    A(T1 aux, T2 aux2) : a(aux), b(aux2){};

    void setA(T1 aux) { a = aux; }
    void setB(T2 aux) { b = aux; }

    T1 getA() { return a; }
    T2 getB() { return b; }

    virtual ostream &put(ostream &os)
    {
        os << "Tipo variabile a: " << typeid(a).name() << "\nContenuto variabile a: " << a << endl;

        os << "Tipo variabile b: " << typeid(b).name() << "\nContenuto variabile b: " << b << endl;

        return os;
    }
};

template <class T1, class T2>
ostream &operator<<(ostream &os, A<T1, T2> &obj)
{
    return obj.put(os);
}

int main()
{
    int a = 2;
    double b = 3;
    A obj(a, b);

    cout << obj << endl;
}
