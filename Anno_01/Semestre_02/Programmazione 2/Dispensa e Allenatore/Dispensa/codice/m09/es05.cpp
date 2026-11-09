// Esercizio 9.5 - La gerarchia Shape delle slide (UML): area media delle figure
#include <iostream>
#include <string>
using namespace std;

enum Color { ROSSO, VERDE, BLU };
string nomeColore(Color c) {
    string n[] = {"rosso", "verde", "blu"};
    return n[c];
}

class Shape {                                   // astratta
protected:
    Color color;
public:
    Shape(Color c = ROSSO) : color(c) {}
    virtual ~Shape() {}
    Color getColor() const { return color; }
    void setColor(Color c) { color = c; }
    virtual double getArea() const = 0;
    virtual void print() const { cout << " " << nomeColore(color) << ", area " << getArea() << endl; }
};

class Rectangle : public Shape {
    double height, width;
public:
    Rectangle(double h, double w, Color c = ROSSO) : Shape(c), height(h), width(w) {}
    double getArea() const override { return height * width; }
    bool isASquare() const { return height == width; }
    void print() const override { cout << "Rettangolo " << height << "x" << width; Shape::print(); }
};

class Circle : public Shape {
    double radius, xc, yc;
public:
    Circle(double r, double x = 0, double y = 0, Color c = ROSSO) : Shape(c), radius(r), xc(x), yc(y) {}
    double getArea() const override { return 3.14159 * radius * radius; }
    double getCircumference() const { return 2 * 3.14159 * radius; }
    bool isGoniometric() const { return radius == 1 && xc == 0 && yc == 0; }   // cerchio unitario centrato
    void print() const override { cout << "Cerchio r=" << radius; Shape::print(); }
};

class Triangle : public Shape {
    double base, height;
public:
    Triangle(double b, double h, Color c = ROSSO) : Shape(c), base(b), height(h) {}
    double getArea() const override { return base * height / 2; }
    void print() const override { cout << "Triangolo " << base << "x" << height; Shape::print(); }
};

int main() {
    // Input: numero di figure, poi per ognuna "tipo dati colore"
    int n;
    cin >> n;
    Shape** figure = new Shape*[n];            // array DINAMICO di puntatori
    for (int i = 0; i < n; i++) {
        char tipo; double a, b; int c;
        cin >> tipo;
        if (tipo == 'C') { cin >> a >> c; figure[i] = new Circle(a, 0, 0, Color(c)); }
        else if (tipo == 'R') { cin >> a >> b >> c; figure[i] = new Rectangle(a, b, Color(c)); }
        else { cin >> a >> b >> c; figure[i] = new Triangle(a, b, Color(c)); }
    }
    double somma = 0;
    for (int i = 0; i < n; i++) {
        figure[i]->print();
        somma += figure[i]->getArea();
    }
    cout << "Area media: " << somma / n << endl;
    for (int i = 0; i < n; i++) delete figure[i];
    delete[] figure;
    return 0;
}
