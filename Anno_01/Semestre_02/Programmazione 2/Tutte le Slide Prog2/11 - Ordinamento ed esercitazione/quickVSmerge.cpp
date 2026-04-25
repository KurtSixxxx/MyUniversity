
/* Confronto tra QS e MS al crescere delle dimensioni dell'array **/
#include <iostream>
#include <time.h>
#include "ordinamRicorsivo.h"
#include "performanceChrono.h"

using namespace std;

void stampa(int *a, int n){
	for (int i=0; i<n;i++)
		cout << a[i] << " ";
	cout << endl;
}



void generaArrayCasuale(int *a, int num){
	for(int i =0;i<num;i++)
		a[i] = rand() % 101;
}

int main(){

	int *arr;
	int n = 10;

	/*
	arr = new int[n];
	generaArrayCasuale(arr,n);
	stampa(arr,n);
	mergesort(arr,0,n-1);
	stampa(arr,n);
	
	
	n = 20;
	arr = new int[n];
	generaArrayCasuale(arr,n);
	stampa(arr,n);
	mergesort(arr,0,n-1);
	stampa(arr,n);
	return 0;*/
	
	n=1;
	for(int i = 0;i<5;i++){
		n *= 10;
		arr = new int[n];
		generaArrayCasuale(arr,n);
		//stampa(arr, n);
		
		cout << "N:\t" << n << "\t";
		auto t1 = high_resolution_clock::now();
		quicksort(arr, n);
		auto t2 = high_resolution_clock::now();
		duration<double, milli> ms_double = t2 - t1;
		cout << "QS: " << ms_double.count() << " ms";
		t1 = high_resolution_clock::now();
		//NB: anche se arr e' gia' ordinato la complessita' del MS e' la stessa
		mergesort(arr, 0, n-1);
		t2 = high_resolution_clock::now();
		ms_double = t2 - t1;
		cout << "\tMS: " << ms_double.count() << " ms" << endl;

	}


    return 0;
}
