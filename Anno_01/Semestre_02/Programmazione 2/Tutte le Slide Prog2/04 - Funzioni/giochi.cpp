
/*
Scrivere un programma che richiede all’utente 
quale operazione svolgere tra quelle elencate 
(specificando il suo numero) e 
successivamente la esegue:

1 - Simula l’andamento di una partita a carta forbice sasso,
determinando le scelte dei due contendenti 
(giocatore A e giocatore B) in modo casuale. 
Vince chi fa meglio in N tentativi, con N dato
dall’utente. Il valore di N deve essere dispari.

2 - Simulare l’esito della somma del lancio di 
due dadi, visualizzare il risultato di N lanci 
dopo aver letto N dalla tastiera.

3 - Uscire dal programma.
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main (){

	int scelta;
	int N, dado1, dado2, esito;
	int cnt[11] = {0};
	srand(123);
	
	do{
		cout << endl;
		cout << "Selezionare l'operazione desiderata"<< endl;
		cout << "1) Carta forbice sasso" << endl;
		cout << "2) Lancio di 2 dadi" << endl;
		cout << "3) Uscire dal programma" << endl;
		cout << "Scelta: ";
		// TOFIX: gestire input non numerici
		// TODO: chiedere l'inserimento finche' non valido
		cin >> scelta;
		cout << endl; 

		switch(scelta){
			case 1: //.... 
				cout << "Hai scelto 1: carta forbice sasso" << endl;
				break;
			case 2: //....
				cout << "Hai scelto 2: lancio di 2 dadi" << endl;
				cout << "Quanti lanci? ";
				cin >> N;
			
				for(int i=0;i<N;i++){
					cout << "Lancio " << (i+1) << "/" << N;
					dado1 = (rand()%6) +1;
					dado2 = (rand()%6) +1;
					
					esito =  dado1+dado2;
					cout <<"\tesito: " << esito << " ("<< dado1 <<
											" + " <<
											dado2 << ")" <<endl;
					cnt[esito-2]++;
				}
				
				// Visualizzo i conteggi degli N esiti
				for(int i=0; i<11;i++){
					cout << i+2 <<": ";
					for(int j=0;j<cnt[i];j++) cout << "*";
					cout << endl;
				}
				
			
				break;
			case 3: //....
				cout << "Hai scelto 3: uscita dal programma" << endl;
				break;
		
			default:
				cout << "Scelta non valida" << endl;		
		}
		
	}while(scelta!=3);
	
}





