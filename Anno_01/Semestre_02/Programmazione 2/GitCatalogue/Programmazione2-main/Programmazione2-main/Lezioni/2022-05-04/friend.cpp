#include <iostream>
using namespace std;

class A
{
private:
    int n = 10;

    friend void set_member(A &a, int val)
    {
        a.n = val;
    }

public:
    void set_n(int val)
    {
        n = val;
    }

    int get_n()
    {
        return n;
    }

    friend ostream &operator<<(ostream &os, A &a)
    {
        os << a.n << endl;
        return os;
    }
};

int main()
{
    A a;

    // a.set_member(3); Errore

    set_member(a, 5);

    cout << a;
}