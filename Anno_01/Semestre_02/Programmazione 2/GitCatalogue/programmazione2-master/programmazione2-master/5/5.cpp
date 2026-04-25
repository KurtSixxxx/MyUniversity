#include <iostream>
using namespace std;

class A{
    private:
        int x;
        int y;
    
    public:
        /*A(int _x, float _y){ // Modo classico per definire un costruttore e passare i valori al costruttore
            x = x;
            y = y; 
        }*/
        A(int _x, float _y) : x(_x), y(_y) {} //Un secondo strumento che mette a disposizione C++ per definrie un costruttore in manierea più sintentica
        //I due costruttori sono equivalenti, è solo un modo differente.
        /*
        Possiamo anche unire i dure modi:
            A(int _x, float _y) : x(_x) {
                this->y = _y;
            }
        */
       A(int _x){ //Con un parametro di default
           this->x = _x;
           this->y = 0.0f;
       }
    
        void print(){
            cout << "Classe A" << endl;
            cout << "x = " << x << ", " << "y = " << y << endl;
        }
};

int main(){
    //inizializzazione classica -> A a = A(1, 2.0);
    //inizializzazione con la sintassi degli array A a = {1, 2.0}
    A a = {1, 2.0}; //Non posso richiamare questo se ho dichiarato explicit il costruttore
    a.print();

    A a2 = 2; //Cosi richiamo il costruttore dove passo solo il valore intero. Questo rappresenta un terzo modo ma nulla vieta di usare quelli precedenti
    a2.print();
}