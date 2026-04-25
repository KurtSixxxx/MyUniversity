

#include <iostream>
using namespace std;

enum Color {ROSSO, VERDE, GIALLO, BLU, NERO, VIOLA};

void printColor(Color c){
    switch(c){
        case ROSSO: cout << "Rosso"; break;
        case VERDE: cout << "Verde"; break;
        case GIALLO: cout << "Giallo"; break;
        case BLU: cout << "Blu"; break;
        case NERO: cout << "Nero"; break;
        case VIOLA: cout << "Viola"; break;
    }
}


class Shape{

protected:
    Color color;
public:
    Shape(Color c = ROSSO): color(c){}
    virtual ~Shape() {}

    Color getColor()const {return color;}
    void setColor(Color c) {color = c;}

    // late binding (binding dinamico)
    virtual void print() const {
        cout << "--- Stampo Shape ---" << endl;
        cout << "Color:\t";
        printColor(color);
        cout << endl;
    }

    virtual double getArea() const = 0;
};

class Rectangle: public Shape{
private:
    double width, height;
public:
    Rectangle(double w=1, double h=1): Shape(), width(w), height(h){}
    Rectangle(double w, double h, Color c): Shape(c), width(w), height(h){}
    ~Rectangle() {}

    double getH() const {return height;}
    double getW() const {return width;}
    void setH(double h) {height = h;}
    void setW(double w) {width = w;}
    bool isSquare() const {return height == width;}

    //override metodo virtuale
    void print() const{
        cout << "--- Stampo Rectangle ---" << endl;
        cout << "Color:\t";
        printColor(color);
        cout << endl;
        cout << "H:\t" << height << "\tW:\t" << width << endl;
    }

    // implemento il metodo virtuale puro
    double getArea() const{ return height*width;}
};

class Circle: public Shape{
private:
    double r, xc, yc;
public:
    Circle (double _r=1, double _xc=0, double _yc=0):
            Shape(), r(_r), xc(_xc), yc(_yc){}
    Circle (double _r, double _xc, double _yc, Color c):
            Shape(c), r(_r), xc(_xc), yc(_yc){}

    double getR()const {return r;}
    double getXC() const { return xc;}
    double getYC() const {return yc;}
    void setR(double _r) {r = _r;}
    void setXC(double _xc) {xc = _xc;}
    void setYC(double _yc) {yc = _yc;}

    double getCirc() const {return 2*3.14*r;}
    bool isGoniometric() const {
        if((xc == 0) && (yc ==0) && (r==1))
            return true;
        else
            return false;
    }

    void print() const {
        cout << "--- Stampo Circle ---" << endl;
        cout << "Color:\t";
        printColor(color);
        cout << endl;
        cout << "Radius:\t" << r << endl;
        cout << "Center:\t(" << xc << ", " << yc << ")" << endl;
    }


    double getArea() const { return 3.14*r*r;}

};

class Triangle: public Shape{
private:
    double b, h;
public:
    Triangle(double _b=1, double _h=1):
            Shape(), b(_b), h(_h){}
    Triangle(double _b, double _h, Color c):
            Shape(c), b(_b), h(_h){}
    ~Triangle(){}

    double getH(){ return h;}
    double getB(){ return b;}
    void setH(double v){h= v;}
    void setB(double v){b= v;}

    void print()const {
        cout << "--- Stampo Triangle ---" << endl;
        cout << "Color:\t";
        printColor(color);
        cout << endl;
        cout << "Base:\t" << b << "\tHeight:\t" << h << endl;
    }

    double getArea()const{
        return b*h/2;
    }
};


int main(){
    Rectangle r1(5,4);
    r1.print();

    r1.setColor(BLU);
    r1.print();

    Shape* figs[4];
    int i = 0;
    char res = 'x';

    while(i<4){
        cout << "Scegliere una figura geometrica"<< endl;
        cout << "R per rettangolo, C per cerchio e T per triangolo" << endl;
        cout << "Scelta: ";
        cin >> res;
        Color cc;
        if(i%2 ==0)
            cc = VIOLA;
        else
            cc = VERDE;

        switch(res){

        case 'R':

            figs[i] = new Rectangle(2*i +2, 4*i+1,cc);
            i++; break;

        case 'C':

            figs[i] = new Circle(i+2, 0,0,cc);
            i++; break;

        case 'T':

            figs[i] = new Triangle(2*i+5, i*3);
            i++; break;
        }
        cout << "figure attualmente inserite: " << i << "/4"<< endl;

    }

    for(i=0;i<4;i++){
        figs[i]->print();
        cout << "Area:\t" << figs[i]->getArea()<< endl;
    }

    delete[] figs;
    return 0;
}




