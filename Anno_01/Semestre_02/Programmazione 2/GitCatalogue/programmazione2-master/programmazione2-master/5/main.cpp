#include <iostream>
#include "ellisse.hpp"
using namespace std;

int main(){
	Ellisse e(0.0, 0.0, 3.0, 4.0);
	cout << "Perimetro: " << e.perimetro() << endl;
	cout << "Area: " << e.area() << endl;
	e.toString();
	
	cout << endl;
	
	
	//Posso puntare sempre ad un oggetto. Ma puntando a Ellisse se non dichiaro virtual i metodi che voglio richiamare tramite puntatore a Ellisse in Forma, mi verrano richiamati di default le funzioni di Forma e non di Ellisse
	Ellisse e1(0.0, 0.0, 5.0, 7.0);
	Forma *ptr = &e1; 
	
	cout << "Perimetro: " << e.perimetro() << endl;
	cout << "Area: " << e.area() << endl;
	e1.toString();

	cout << endl;
	return 0;
}