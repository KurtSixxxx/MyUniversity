

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	
	if(argc < 3){
		cout << "Bisogna fornire il nome di due file come argomento!" << endl;
		exit(1);
	}
	
	//fstream infile(argv[1], ios::in) // solo lettura
	ifstream infile(argv[1]); // solo lettura
	
//	ofstream outfile(argv[2]); // solo scrittura
//	fstream outfile(argv[2], ios::out); // solo scrittura
	// voglio scrivere su file e poi leggere per verificarne il contenuto...
	fstream outfile(argv[2], ios::in | ios::out); // lettura e scrittura
	//NB: l'istruzione precedente potrebbe non creare il file se non esiste...
	if(!infile || !outfile){ 
		cerr << "Errore: file in/out non puo' essere aperto.\n";
		exit(2);
	}
	
	char c;
	cout << "Contenuto del file originale:" << endl;
	while(infile.get(c))
		cout << c;
	infile.clear(); /* devo farlo per resettare i flag che sono stati
		modificati quando ha terminato il file (EOF).*/
	
	//resetto il cursore che legge il file
	infile.seekg(0, ios::beg);
	
	cout << endl << "Sto processando il file " << argv[1] << "...\n";
	while(infile.get(c)){
		if(islower(c))
			c = toupper(c);
		outfile.put(c); // scrivo sul secondo file un carattere per volta.
	}
	
	infile.close();
	
	cout << endl << "Il file " << argv[2] << " e' stato modificato!" << endl;
	cout << "Contenuto del file di output:" << endl;
	outfile.seekg(0, ios::beg);
	while(outfile.get(c))
		cout << c;
	
	outfile.close();
	return 0;
}