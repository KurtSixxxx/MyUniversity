#include <iostream>
using namespace std;

class Base
{
protected:
    int n = 10;
};

class Derivata1 : protected Base
{
};

class Derivata2 : protected Base
{
};

int main()
{
    Derivata1 d1;
    Derivata2 d2;

    // cout << d1.n << endl; Protected, non accessibile al main
}