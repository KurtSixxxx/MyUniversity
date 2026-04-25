//lavorare con i file
#include <stdio.h>

int main (){
	
	FILE *file = fopen("prova.txt", "r");/*per lavorare con un file devo creare una variabile pointer di tipo file e associo il pointer a file open 
	inserisco il percorso del file e si specifica la modalità con cui aprire il file apertura,append o scrivere ,con w scrivo nel file,con a di append sovrascrivo*/
	// Verifica se l'apertura del file è riuscita
    if (file == NULL) {//non è riuscito ad aprire il file
        printf("Errore nell'apertura del file.\n");
        return 1;  // Termina il programma con codice di errore
    }
    /*fprintf(file, "\nciao sono pirla");//se scrivo nel file tutto ciò che scrivo viene cancellato
	//remove("prova.txt");//per rimuovere il file*/
	fclose(file);/*nessuno dopo la chiusura del file può scrivere se no il flusso di dati rimane aperto e quindi qualsiasi riga di codice aggiuntiva messa per sbaglio 
	può andare a modificare il contenuto del file*/
	char contenuto[100];
	/*fgets(contenuto, 100, file);//prende la prima riga 
	printf("%s",contenuto);*/
	while(fgets(contenuto,100,file)){//legge tutto fin quando individua righe,fin quando fgets prende una riga dal file la manda allo schermo
		printf("%s",contenuto);
	}
	return 0;
}
