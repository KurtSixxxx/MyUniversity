#include <iostream>
using namespace std;

class A {
  public:
  A(int _pippo, int _pluto, int _paperino){
    pippo = _pippo;
    pluto = _pluto;
    paperino = _paperino;
  }
  A(){ // Costruttore senza parametri (di default)
    this->pippo = 10; //Per usare un costruttore di default dobbiamo usare il puntatore this->
    this->paperino = 20;
    this->pluto = 30;
  }
  int pippo = 0;
  void print(){
    cout << "La somma e: " << somma() << endl;
  }

  private:
  int paperino = 0;

  protected:
  int pluto = 0;
  int somma(){
    return pippo + paperino + pluto;
  }
};

//_______________________________________________________________________________________________________

class B : public A{
  public:
  B() : A(){}
};


int main(){
  A a1 = A(2, 3, 4);
  a1.print();

  A a2; //Sintassi per richiamere costruttore di default
  a2.print(); //Per una stessa classe possono esserci anche piu di un costruttore di default

  B b1;
  b1.print();

}
