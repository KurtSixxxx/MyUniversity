
#include <iostream>
#include <math.h>
using namespace std;

class Punto2D{
public:
    int x,y;

    friend
    ostream& operator<<(ostream& out, const Punto2D& p){
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};


class Rettangolo{
    Punto2D top_left, bot_right;
    double base, altezza;

    void aggiornaBaseAltezza(){
        base = bot_right.x - top_left.x;
        altezza = top_left.y - bot_right.y;
    }

public:
    // Costruttore con i due punti in input
    Rettangolo(const Punto2D&, const Punto2D&);

    const Punto2D& getTL()const {return top_left;}
    const Punto2D& getBR()const {return bot_right;}

    void setTL(int x, int y){
        top_left.x = x;
        top_left.y = y;
        aggiornaBaseAltezza();
    }

    void setBR(int x, int y){
        bot_right.x = x;
        bot_right.y = y;
        aggiornaBaseAltezza();
    }

    double getBase()const{return base;}
    double getAltezza() const{return altezza;}
    double area() const {return base*altezza;}

    double misuraDiagonale() const;
    double perimetro() const;
    bool sonoQuadrato() const;
    bool contiene(const Punto2D&);
    bool contiene(const Rettangolo&);

    friend
    ostream& operator<<(ostream& out, const Rettangolo& r);

};

double Rettangolo::misuraDiagonale() const{
    return sqrt(base*base + altezza*altezza);
}
double Rettangolo::perimetro() const{
    return 2*(base+altezza);
}
bool Rettangolo::sonoQuadrato() const{
    return base == altezza;
}


ostream& operator<<(ostream& out, const Rettangolo& r){
    out << r.getBase() << "X" << r.getAltezza() << endl;
    out << "Diag = " << r.misuraDiagonale() << endl;
    out << "Top left:\t" << r.top_left << endl;
    out << "Bot right:\t" << r.bot_right << endl;
    out << "Perim = " << r.perimetro() << endl;
    out << "Area = " << r.area() << endl;
    out << "Quadrato? " << (r.sonoQuadrato()? "Si":"No") << endl << endl;
    return out;
}

Rettangolo::Rettangolo(const Punto2D& p1, const Punto2D&p2){
    top_left = p1; bot_right = p2;
    aggiornaBaseAltezza();
}

int main(){
    Punto2D pp = {10,20};
    Punto2D qq = {50,10};
    cout <<"Punto pp:\t"<< pp << endl;
    cout <<"Punto qq:\t"<< qq << endl;


    Rettangolo A(pp,qq);
    Rettangolo B({10,20},{50,10});

    cout << "Rettangolo A:"<< endl;
    cout << A;

    cout << "Rettangolo B:"<< endl;
    cout << B;

    B.setTL(20,40);
    cout << "Rettangolo B:"<< endl;
    cout << B;



    return 0;
}














