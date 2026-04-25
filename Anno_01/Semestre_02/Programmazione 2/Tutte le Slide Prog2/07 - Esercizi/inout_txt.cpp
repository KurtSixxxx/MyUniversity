
 /*
 Leggo il file input.txt con un oggetto di tipo ifstream chiamato ciccioin.
 Il file contiene la stringa "4 7" (due numeri separati da spazio).
 Sommo i valori letti (4+7)
 Scrivo su un file output.txt con un oggetto di tipo ofstream chiamto cicciout
 */
#include <fstream>
#include <iostream>
using namespace std;

int main(){
	
	// creo una istanza di input file stream chiamtata ciccioin
	ifstream ciccioin("input.txt"); 
	ofstream cicciout("output.txt");
	
	int a, b;
	
//	cin >> a >> b; //... se li leggessi da stdin...
	ciccioin >> a >> b;
	cicciout << "Somma: " << a+b << endl;
	
	ciccioin.close();
	cicciout.close();
	
	/*
	getline prendeva 'cin' come parametro di tipo stream...
	ora usiamo un oggetto fstream collegato ad un file di testo
	per leggerlo riga per riga...
	*/
	
	// creo una istanza di fstream
	fstream filein("multilineinput.txt");
	cout << "Lettura del file multilineinput.txt:" << endl;
	for (string line; getline(filein, line);)
		cout << line << endl;
	
		
	return 0;
	}

	
	
	
	