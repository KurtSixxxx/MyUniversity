#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include "static_queue.h"
#include "bst.h"
using namespace std;

class Shape
{
public:
    Shape(){};
    virtual double getArea() = 0;

    virtual ostream &put(ostream &os)
    {
        os << "Classe: " << typeid(*this).name(); //...

        return os;
    }
};

ostream &operator<<(ostream &os, Shape &obj)
{
    return obj.put(os);
}

class Rectangle : public Shape
{
private:
    double base;
    double altezza;

public:
    Rectangle(double base, double altezza) : Shape(), base(base), altezza(altezza){};

    double getArea() { return base * altezza; };

    ostream &put(ostream &os)
    {
        Shape::put(os);
        os << "\nBase: " << base << "\nAltezza: " << altezza << "\nArea: " << getArea() << endl;
        return os;
    }
};

class Circle : public Shape
{
private:
    double raggio;

public:
    Circle(double raggio) : Shape(), raggio(raggio){};

    double getArea() { return pow(M_PI * raggio, 2); };

    ostream &put(ostream &os)
    {
        Shape::put(os);
        os << "\nRaggio: " << raggio << "\nArea: " << getArea() << endl;
        return os;
    }
};

class Triangle : public Shape
{
private:
    double base;
    double altezza;

public:
    Triangle(double base, double altezza) : Shape(), base(base), altezza(altezza){};

    double getArea() { return (base * altezza) / 2; };

    ostream &put(ostream &os)
    {
        Shape::put(os);
        os << "\nBase: " << base << "\nAltezza: " << altezza << "\nArea: " << getArea() << endl;
        return os;
    }
};

int main()
{
    srand(time(NULL));
    int n = 0, aux = 0;
    double area = 0;

    // Punto 1

    do
    {
        cout << "\nInserire il numero di oggetti da creare: ";
        cin >> n;
    } while (n <= 0);

    StaticQueue<Rectangle *> rettangoli(n);
    StaticQueue<Circle *> cerchi(n);
    StaticQueue<Triangle *> triangoli(n);

    // Punto 2

    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "\nInserire il tipo di oggetto da creare (1: Rettangolo / 2: Cerchio / 3: Triangolo): ";
            cin >> aux;
        } while (aux != 1 && aux != 2 && aux != 3);

        switch (aux)
        {
        case 1:
        {
            double base = ((double)rand() / RAND_MAX) * 100.0;
            double altezza = ((double)rand() / RAND_MAX) * 100.0;
            rettangoli.enqueue(new Rectangle(base, altezza));
            break;
        }
        case 2:
        {
            double raggio = ((double)rand() / RAND_MAX) * 100.0;
            cerchi.enqueue(new Circle(raggio));
            break;
        }
        case 3:
        {
            double base = ((double)rand() / RAND_MAX) * 100.0;
            double altezza = ((double)rand() / RAND_MAX) * 100.0;
            triangoli.enqueue(new Triangle(base, altezza));
            break;
        }
        }
    }

    cout << "\n\n**** VISUALIZZAZIONE QUEUE ****\n\n"
         << endl;

    cout << rettangoli << endl;
    cout << cerchi << endl;
    cout << triangoli << endl;

    BST<Shape *> forme;

    // Punto 3

    while (!rettangoli.isEmpty())
    {
        forme.insert(rettangoli.dequeue());
    }

    while (!triangoli.isEmpty())
    {
        forme.insert(triangoli.dequeue());
    }

    while (!cerchi.isEmpty())
    {
        forme.insert(cerchi.dequeue());
    }

    // Punto 4

    cout << "Inserisci un valore di area: "; // Si consiglia di inserire un valore di circa 3000
    cin >> area;

    cout << "\n\n**** VISUALIZZAZIONE BST ****\n\n"
         << endl;

    // forme.inorder();

    forme.deleteUnder(area);

    cout << "\n\n**** VISUALIZZAZIONE BST CON ELEMENTI DI AREA >= " << area << " ****\n\n"
         << endl;

    forme.visualizza();
}
