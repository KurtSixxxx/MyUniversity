#include <iostream>
using namespace std;

class Forma{
	public:	
		virtual double perimetro() = 0; //Funzione puramente virtuale(o astratta)
		virtual double area() = 0;
		virtual void toString(){
			return;
		}
		friend ostream& operator << (ostream& stream, const Forma& f){
			return stream;
		}
};