#include <iostream>
#include <fstream> //Fondamentale per usare ofstream
using namespace std;


//Possiamo passare al membro friend anche un oggetto const, in modoo che la procedura non ne modifichi il valore. Funziona anche senza const, ma con il const abbiamo maggiore sicurezza

class Punto {
    double x, y;

    public:
        Punto(double x, double y) : x(x), y(y){}
        Punto() : Punto(0.0, 0.0){} // Costruttore con valori di default
        void print(){
            cout << "(" << x << ", " << y << ") \n";
        }
        double getX(){
            return this->x;
        }
        double getY(){
            return this->y;
        }
        //Dichiarazione e definizione allo stesso momento
        friend ostream& operator << (ostream& os, const Punto& p){ //Overloading operatore <<
             os << "(" << p.x << ", " << p.y << ")";
             return os;
        }
        friend istream& operator >> (istream&, Punto&); //Overloading operatore >>
        //Quando facciamo overloading degli operatori è sempre consigliato andare a passare il valore del costruttore per indirizzo e non per valori
};


//Possiamo dichiarare friend la funzione nella classe e definirla fuori dalla classe se preferiamo cosi
istream& operator >> (istream& is, Punto& p){ //Overloading operatore >>
    is >> p.x;
    is >> p.y;
    return is;
}


int main(){
    Punto p;
    cout << "Oggetto della classe Punto con valori standard: " <<  p << endl; 
    cin >> p;
    cout << "Oggetto della classe Punto dopo l'input" << p << endl;


    ofstream ofs("file.txt"); //Apro un file in scrittura
    ofs << p; // Posso sfruttare l'overloaing dello'operatore anche per scrivere su file
    ofs.close(); //Buona norma chiudere il file una volta usato


    ifstream ifs("fileFile.txt");
    ifs >> p;
    ifs.close();

    cout << p << endl;

    return 0;
}



