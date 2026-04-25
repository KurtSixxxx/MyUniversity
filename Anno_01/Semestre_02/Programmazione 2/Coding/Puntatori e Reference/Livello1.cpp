//! Esercizi di ripasso sui puntatori. (Come in C)

#include <iostream>
using namespace std;

//Esercizio 1.
//Scrivi una funzione void swap(int* a, int* b) che scambia il valore di due variabili usando i puntatori. Provala nel main.

//Esercizio 2.
//Crea un array di 5 interi. Usa un puntatore per scorrere l'array e stampare ogni elemento (usa p++ per spostarti).

//Esercizio 3.
//Dichiarazione di un int x = 10;, un puntatore int* p = &x; e un puntatore a puntatore int** pp = &p;. Cambia il valore di x passando solo attraverso pp.

void swap(int *a, int *b);

int main() {
	//Inizio blocco di codice esercizo 1.
	//---------------------------
	int n, m;
	n = 5;
	m = 6;

	int *a = &n;
	int *b = &m;

	cout << "Prima dello swap   ->   Valore di a: " << *a << "\t" << "Valore di b: " << *b << "\t\t ||   ";
	swap(a, b);
	cout << "Dopo dello swap    ->   Valore di a: " << *a << "\t" << "Valore di b: " << *b << "\n";
	//Fine blocco di codice esercizo 1.
	//---------------------------


	//Inizio blocco di codice esercizo 2.
	//---------------------------
	int arr[5] = {2,4,6,8,10};
	int *p = arr; //Non inserisco il puntatore poichC) in un array il nome della variabile C( giC  puntatore alla prima casella.
	cout << "Stampa dell'array: ";
	for (int *p = arr; p < arr + 5; p++) {
    cout << *p << " ";
    }
	cout << "\n";
	//Fine blocco di codice esercizo 2.
	//---------------------------

    //Inizio blocco di codice esercizo 3.
    //---------------------------
    int x = 10;
    int *p1 = &x; //Uso p1 come nome variabile poiché p l'ho già utilizzato negli altri esercizi
    int **pp = &p1;
    cout << "Valore di x prima: " << **pp << "\t";
    **pp = 12;
    cout << "Valore di x dopo:  " << **pp << "\n";
    //Fine blocco di codice esercizo 3.
    //---------------------------
    
	return 0;
}

void swap(int *a, int *b){
	int *tmp;

	*tmp = *a;
	*a = *b;
	*b = *tmp;
}