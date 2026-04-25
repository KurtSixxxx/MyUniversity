
/*Un numero si dice perfetto se la somma dei suoi
divisori (incluso 1) escludendo se stesso coincide 
con il numero stesso.
Es. 6 = 1+2+3 */

#include <iostream>
using namespace std;

bool perfetto(int n){
	int acc = 1;
	cout << endl << "##############" << endl;
	cout << "Divisori di " << n << ":\t1\t";
	for(int i = 2; i<=n/2;i++)
		if(n%i==0){
			cout << i << "\t";
			acc += i;
		}
	cout << endl << "Somma dei divisori: "<< acc;
	cout << endl << "##############" << endl;
	return (acc == n);
	
}

int main(){
	
	int intero;
	cout << "Inserisci un intero: ";
	cin >> intero;
	
	if(perfetto(intero))
		cout << "Il numero " 
			<< intero 
			<< " e' un numero perfetto" << endl;
	else
		cout << "Il numero " 
			<< intero 
			<< " non e' un numero perfetto" << endl;
	
	cout << "Il numero " << intero << " ... "<<endl; 	
	(perfetto(intero)? cout<< endl << " ... ":cout << endl << " ... non ");
	cout <<"e' un numero perfetto" << endl;
	
	return 0;
}

