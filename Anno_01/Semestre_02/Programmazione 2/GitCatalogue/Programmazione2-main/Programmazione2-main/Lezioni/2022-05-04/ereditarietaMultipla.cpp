#include <iostream>
using namespace std;

class A
{
public:
    A()
    {
        cout << "Costruttore A" << endl;
    }

    void foo()
    {
        cout << "foo A" << endl;
    }
};

class B
{
public:
    B()
    {
        cout << "Costruttore B" << endl;
    }

    void foo()
    {
        cout << "foo B" << endl;
    }
};

class C : public A, public B
{
public:
    C()
    {
        cout << "Costruttore C" << endl;
    }
};

int main()
{
    C c;

    c.A::foo();
    c.B::foo();
}