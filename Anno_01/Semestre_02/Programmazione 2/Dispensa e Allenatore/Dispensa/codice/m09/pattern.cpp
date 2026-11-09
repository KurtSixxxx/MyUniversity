// Modulo 9 - Pattern: gerarchia con classe astratta, virtual e polimorfismo
// Compila: g++ -g pattern.cpp -o pattern.exe
#include <iostream>
#include <string>
using namespace std;

// CLASSE BASE ASTRATTA: ha almeno un metodo virtuale puro (= 0) -> non si può istanziare
class Figura {
protected:                          // visibile alle classi derivate, non al main
    string nome;
public:
    Figura(string n) : nome(n) { cout << "  [costruttore Figura]" << endl; }
    virtual ~Figura() { cout << "  [distruttore Figura " << nome << "]" << endl; }   // SEMPRE virtual

    virtual double area() const = 0;            // virtuale PURO: ogni figura la calcola a modo suo
    virtual void stampa() const {               // virtuale con un comportamento di default
        cout << nome << ", area " << area() << endl;   // area() chiama la versione GIUSTA
    }
    string getNome() const { return nome; }     // non virtuale: uguale per tutti
};

class Rettangolo : public Figura {              // Rettangolo "è una" Figura
protected:
    double b, h;
public:
    Rettangolo(double base, double altezza, string n = "rettangolo")
        : Figura(n), b(base), h(altezza) {      // PRIMA si costruisce la parte Figura
        cout << "  [costruttore Rettangolo]" << endl;
    }
    ~Rettangolo() { cout << "  [distruttore Rettangolo]" << endl; }
    double area() const override { return b * h; }       // override: ridefinisco
};

class Quadrato : public Rettangolo {            // Quadrato "è un" Rettangolo (3 livelli)
public:
    Quadrato(double lato) : Rettangolo(lato, lato, "quadrato") {
        cout << "  [costruttore Quadrato]" << endl;
    }
    ~Quadrato() { cout << "  [distruttore Quadrato]" << endl; }
    void stampa() const override {              // estendo la stampa della base
        Figura::stampa();                       // riuso la versione di Figura...
        cout << "    (e' anche un rettangolo " << b << "x" << h << ")" << endl;   // ...e aggiungo
    }
};

class Cerchio : public Figura {
    double r;
public:
    Cerchio(double raggio) : Figura("cerchio"), r(raggio) { cout << "  [costruttore Cerchio]" << endl; }
    ~Cerchio() { cout << "  [distruttore Cerchio]" << endl; }
    double area() const override { return 3.14159 * r * r; }
};

int main() {
    // Figura f("x");        // ERRORE: Figura è astratta (area() è = 0)
    cout << "Creo le figure:" << endl;
    Figura* figure[3];                          // array di PUNTATORI alla base
    figure[0] = new Rettangolo(3, 4);
    figure[1] = new Cerchio(1);
    figure[2] = new Quadrato(2);

    cout << "\nStampo (polimorfismo: stesso messaggio, comportamenti diversi):" << endl;
    double totale = 0;
    for (int i = 0; i < 3; i++) {
        figure[i]->stampa();                    // collegamento DINAMICO
        totale += figure[i]->area();
    }
    cout << "Area totale: " << totale << endl;

    cout << "\nDistruggo:" << endl;
    for (int i = 0; i < 3; i++) delete figure[i];   // grazie a ~Figura virtual parte il distruttore giusto
    return 0;
}
