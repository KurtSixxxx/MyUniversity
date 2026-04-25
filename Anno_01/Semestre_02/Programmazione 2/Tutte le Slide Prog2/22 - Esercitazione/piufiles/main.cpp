
#include <iostream>
#include <cstring>
#include <ctime>
#include <fstream>
#include "prodottivenditori.h"

using namespace std;

// insertion sort
template <typename T>
void insertionSort(T arr[], int n, bool crescente=true){
	int i,j;
	T key;
	for (i = 1; i < n; i++)	{
		key = arr[i];
		j = i - 1;
		if(crescente)
            while (j >= 0 && arr[j] > key){
                arr[j + 1] = arr[j];
                j = j - 1;
            }
        else // ordinamento decrescente
            while (j >= 0 && key > arr[j]){
                arr[j + 1] = arr[j];
                j = j - 1;
            }
		arr[j + 1] = key;
	}
}



int main(){
/*
    Prodotto p;
    Prodotto p2;
    Prodotto p3(12.4, "detersivo");

    cout << p << endl << p2 << endl << p3 << endl;

//    p.leggi_stdin();

    cout << p << endl;

    ProdottoAlimentare pa(100.0, "caviale", "11/04/2025");
    ProdottoAlimentare pa2(100.0, "formaggio", "11/04/2022");
    cout << pa << endl;
  //  cout << "verifica: " << pa.verifica() << endl;
    cout << pa2 << endl;

*/

    Venditore pipposhop = *(new Venditore("pipposhop"));
    caricaVenditore("pipposhop", &pipposhop);
    cout << "stampo venditore"<< endl;
    cout << pipposhop << endl<< endl;
    cout << "pipposhop prezzo totale:\tEUR " << pipposhop.calcolaPrezzoTotale() << endl;
    cout << "pipposhop valore magazzino:\tEUR " << pipposhop.calcolaValoreMagazzino() << endl;



    Venditore cristaldi = *(new Venditore("cristaldi"));
    caricaVenditore("cristaldi", &cristaldi);
    cout << "stampo venditore"<< endl;
    cout << cristaldi << endl<< endl;
    cout << "cristaldi prezzo totale:\tEUR " << cristaldi.calcolaPrezzoTotale() << endl;
    cout << "cristaldi valore magazzino:\tEUR " << cristaldi.calcolaValoreMagazzino() << endl;


    Venditore rinascente = *(new Venditore("rinascente"));
    caricaVenditore("rinascente", &rinascente);
    cout << "stampo venditore"<< endl;
    cout << rinascente << endl<< endl;
    cout << "rinascente prezzo totale:\tEUR " << rinascente.calcolaPrezzoTotale() << endl;
    cout << "rinascente valore magazzino:\tEUR " << rinascente.calcolaValoreMagazzino() << endl;


    Venditore mercato[] = {pipposhop, cristaldi, rinascente};
    // menu per l'utente
    int scelta;
    do{
        cout << "Scegliere una operazione:" << endl
            << "0) stampa venditori in ordine crescente di prezzo totale" << endl
            << "1) stampa i venditori in ordine decrescente di prezzo totale" << endl
            << "Qualsiasi altro valore per uscire" << endl;
        cin >> scelta;
        cout << "Hai inserito: " << scelta << endl;

        switch(scelta){
        case 0:
            insertionSort(mercato,3);
            for(int i=0;i<3;i++)
                cout << mercato[i] << endl;
            break;
        case 1:
            insertionSort(mercato,3,false);
            for(int i=0;i<3;i++)
                cout << mercato[i] << endl;
            break;
        default:
		scelta =2;
		cout << "Ciao ciao!" << endl;
		break;
    }


    }while(scelta !=2);
    return 0;

}
