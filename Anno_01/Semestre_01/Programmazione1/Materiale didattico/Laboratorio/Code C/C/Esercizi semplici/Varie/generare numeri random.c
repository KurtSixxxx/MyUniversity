//generazione numeri pseudocasuali=sono un insieme di numeri che sembrano generati casualmente
#include <stdio.h>
#include <stdlib.h> //bisogna includere queste direttive
#include <time.h>
#define LunghezzaMax 8
int main(){
	
    //Generazione randomica interi
	int numeroRandom = rand() % 16 + 3;//numero randomico compreso tra 3(infatti è +3) e 18,rand()%16 genera un numero randomico tra 0 e 15 + 3 genera un numero compreso tra 3 e 18
	printf("%d\n", numeroRandom);

    //Generazione randomica double
	double numeroRandomico = 3 + ((double)rand() / RAND_MAX) * (18 - 3);/*numero randomico double tra 3 e 18,((double)rand() / RAND_MAX) genera un numero in virgola mobile compreso 
	tra 0 e 1, oltiplicando questo risultato per l'ampiezza dell'intervallo desiderato (in questo caso, (18 - 3)) e aggiungendo l'offset inferiore 
	(in questo caso, 3), otterrai un numero randomico double nell'intervallo specificato.*/

    //Generazione randomica char
	printf("Numero randomico double tra 3 e 18: %.3f\n", numeroRandomico);
	char letteraCasuale = 'A' + rand() % 26; // Genera una lettera maiuscola tra 0 e 25
	printf("Lettera casuale: %c\n", letteraCasuale);

	return 0;
}
