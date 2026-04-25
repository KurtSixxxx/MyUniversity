/*
Definire un convertitore da Celsius a Fahrenheit
Nel main, chiedere all‘utente di inserire un valore di temperatura seguito da
una delle due unità di misura, verificare l‘input e successivamente
mostrare il risultato della conversione.

F = (C x 9/5) + 32
C = (F - 32) x 5/9

*/

#include <iostream>
#include <limits>
#include "modulo.h"
using namespace std;

int main(){
	double inp;
	char unit, out_unit;
	
	do{
		if(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		
		cout << "Inserisci un valore di temperatura seguito dalla sua unita' di misura (es. -4 C): ";
		cin >> inp ;
		cin >> unit;
		
	}while((unit!='C' && unit!='F') || cin.fail());
	
	cout << inp << " " << unit <<"\t-->\t";
	
	if(unit == 'C'){
		out_unit = 'F';
		cout << c2f(inp) << " " << out_unit << endl;
	}
	else{
		out_unit = 'C';
		cout << f2c(inp) << " " << out_unit << endl;
	}
	
	return 0;
}








