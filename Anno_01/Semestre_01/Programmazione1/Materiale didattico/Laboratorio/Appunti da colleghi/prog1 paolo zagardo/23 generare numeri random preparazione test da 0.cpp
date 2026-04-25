//generazione numeri pseudocasuali=sono un insieme di numeri che sembrano generati casualmente
#include <stdio.h>
#include <stdlib.h>//bisogna includere queste direttive
#include <time.h>
#define LunghezzaMax 8
int main(){
	srand(time(0));/*sta per seme randomico seed random e deve essere presente per generare numeri randomici,con time(0) usiamo l'ora corrente come seme, se elimino il seme
	darà sempre gli stessi numeri*/
	int number1= (rand() %6) + 1; /*la funzione random genera un numero pseudocasuale da 0 a 32767,siccome talvolta dobbiamo generare un numero in un range prestabilito usiamo il modulo
	per indicare il numero massimo entro il quale generare il numero, con %6 viene generato un numero compreso tra 0 e 5, se aggiungiamo 1 viene generato un numero compreso tra 1
	e 6, i computer iniziano da 0*/
	printf("%d\n", number1);
	printf("%d\n", rand());//numero casuale senza seme numero randomico compreso tra 0 e 32767
	int numeroRandom = rand() % 16 + 3;//numero randomico compreso tra 3(infatti è +3) e 18,rand()%16 genera un numero randomico tra 0 e 15 + 3 genera un numero compreso tra 3 e 18
	printf("%d\n", numeroRandom);
	double numeroRandomico = 3 + ((double)rand() / RAND_MAX) * (18 - 3);/*numero randomico double tra 3 e 18,((double)rand() / RAND_MAX) genera un numero in virgola mobile compreso 
	tra 0 e 1, oltiplicando questo risultato per l'ampiezza dell'intervallo desiderato (in questo caso, (18 - 3)) e aggiungendo l'offset inferiore 
	(in questo caso, 3), otterrai un numero randomico double nell'intervallo specificato.*/
	printf("Numero randomico double tra 3 e 18: %.3f\n", numeroRandomico);
	char letteraCasuale = 'A' + rand() % 26; // Genera una lettera maiuscola tra 0 e 25
	printf("Lettera casuale: %c\n", letteraCasuale);
	//generare una parola casuale
    int lunghezza = rand() % LunghezzaMax + 1;// Lunghezza massima della parola
    char parolaCasuale[LunghezzaMax + 1]; // +1 per il terminatore null,questo è un array per la parola casuale
    for (int i = 0; i < lunghezza; ++i) {
        parolaCasuale[i] = 'a' + rand() % 26; // Utilizza lettere minuscole da 0 a 25,questo genera una parola per ogni cella dell'array,ciò genera la parola casuale
    }
    parolaCasuale[lunghezza] = '\0';//terminatore alla fine della parola è '\0'
    // Stampa la parola generata
    printf("Parola casuale: %s\n", parolaCasuale);
    
	return 0;
}
