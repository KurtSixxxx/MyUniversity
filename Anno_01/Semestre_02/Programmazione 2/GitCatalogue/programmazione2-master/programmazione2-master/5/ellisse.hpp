#include "forma.hpp"
#include <cmath>
using namespace std;

class Ellisse : public Forma{
	protected:
		double x, y;
		double r1, r2;
		
	public:
		Ellisse(double _x, double _y, double _r1, double _r2){
			this->x = _x;
			this->y = _y;
			this->r1 = _r1;
			this->r2 = _r2;
		}
		double perimetro(){
			return (2*M_PI)*sqrt((pow(r1, 2.0) + pow(r2, 2.0))/2);
		}
		double area(){
			return M_PI*r1*r2;
		}
		void setX(double x){
			this->x = x;
			return;
		}
		void setY(double y){
			this->y = y;
			return;
		}
		void setR1(double r1){
			this->r1 = r1;
			return;
		}
		void setR2(double r2){
			this->r2 = r2;
			return;
		}
		double getX(){
			return this->x;
		}
		double getY(){
			return this->y;
		}
		double getR1(){
			return this->r1;
		}
		double getR2(){
			return this->r2;
		}
		void toString(){
			cout << "Sono un'ellisse" << endl;
			return;
		}
};