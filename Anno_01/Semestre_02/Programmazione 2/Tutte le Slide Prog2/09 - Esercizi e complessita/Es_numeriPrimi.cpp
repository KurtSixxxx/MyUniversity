
/*Definire più metodi per stampare i numeri 
primi <=n, e valutare il loro tempo di esecuzione 
per valori di n crescenti.*/

/*  per ogni k in [2, n]:
     (1) cerco i divisori di k in [2, k/2] oppure
     (2) in [2, sqrt(k)] ...

	k = a*b
	a = sqrt(k)   b = ??? =>> b = sqrt(k)  infatti k = sqrt(k)*sqrt(k)
*/

#include <iostream>
#include <cmath>
using namespace std;


void metodoSqrt(int n){
	if(n<2) return;
	cout << "2\t";

	bool divisibile;
	for(int k = 3;k<=n;k+=2){
		divisibile= false;
		for(int j = 3; j<=sqrt(k);j++){
			if(k%j == 0){
				divisibile = true;
				break;
			}
		}
		if(!divisibile)
			cout << k << "\t";
	}
		
}
	
int main(){
	cout << "Inserisci un valore per n: ";
	int num;
	cin >> num;
	metodoSqrt(num);
	return 0;
}
	
	
	
	
	
	
	