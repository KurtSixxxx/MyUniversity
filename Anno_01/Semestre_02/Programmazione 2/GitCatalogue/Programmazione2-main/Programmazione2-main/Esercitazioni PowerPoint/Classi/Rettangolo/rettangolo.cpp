#include <iostream>
#include <cmath>
using namespace std;

class Rettangolo
{
private:
    int base;
    int altezza;

public:
    Rettangolo(int base, int altezza) : base(base), altezza(altezza) {}

    Rettangolo() : base(0), altezza(0){};

    void setBase(int b)
    {
        base = b;
    }

    int const getBase()
    {
        return base;
    }

    void setAltezza(int a)
    {
        altezza = a;
    }

    int const getAltezza()
    {
        return altezza;
    }

    int const getArea()
    {
        return base * altezza;
    }

    int const getPerimetro()
    {

        return 2 * base + 2 * +altezza;
    }

    double const getDiagonale()
    {
        return sqrt(pow(base, 2) + pow(altezza, 2));
    }

    bool isQuadrato()
    {
        if (base == altezza)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    Rettangolo R1(3, 4);
    Rettangolo R2(5, 6);

    cout << R1.getArea() << endl;
    cout << R2.getPerimetro() << endl;
}