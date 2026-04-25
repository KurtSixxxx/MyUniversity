/* Battaglia Navale */

//Inclusione delle librerie necessarie
#include <stdio.h>  //Normale procedura di inclusione
#include <stdlib.h> //Per la generazione di numeri psuedocasuali e l'utilizzo di funzioni come rand()
#include <time.h>   //Per la generazione del seme con time(NULL)

//Define di alcuni valori necessari: dimensioni massime e minime della tabella, ...
#define MIN_T 2
#define MAX_T 10
#define ACQUA '~'
#define NAVE '#'
#define COLPITO 'X'
#define MANCATO 'O'

//Funzione 'giocatore': continene il nome del giocatore, la dimensione della tabella da lui scelta, e gli errori in caso le dimensioni delle tabelle non siano valide
void giocatore(char* nome, int* dim){
    printf("Benvenuto.\nInserisci il nome per giocare: \n");
    scanf("%s", nome);

    printf("Adesso inseriamo i valori della tabella, ricorda che:\n");
    printf("Minimo '1' \t Massimo '10'\n ");
    printf("Inserisci la dimenione della tabella: ");
    scanf("%d", dim);
    
    if(*dim < MIN_T){
        fprintf(stderr, "Valore non valido, la dimensione '1' non è disponibile");
        menu_principale(char* nome, int* dim);
    }else if(*dim > MAX_T){
        fprintf(stderr, "Valore non valido, la dimensione successiva a '10' non è disponibile");
        menu_principale(char* nome, int* dim);
    }else if(*dim < MIN_T || *dim > MAX_T){
        fprintf(stderr, "Valore non valido, il range disponibile è [2, 10]");
        menu_principale(char* nome, int* dim);
    }
}

//Funzione 'nuova_partita': contiene l'apertura del nuovo file in cui scrivere i dati della partita e poi salvare o eliminare
void nuova_partita(){
    FILE *file = fopen("NuovaPartita.txt", "w+");
    if (file == NULL) {
        perror("Errore creazione nuova partita");
        menu_principale();
    }
}

//Funzione 'carica_partita': contiene l'apertura di un file che contiene i dati una precedente partita che il giocatore vuole completare
void carica_partita() {
    printf("Funzione non ancora implementata.\n");
}

//Funzione 'quit': serve per uscire dal gioco
void quit() {
    printf("Uscita dal gioco...\n");
    exit(0);
}

//Funzione 'istruzioni': serve per far capire al giocatore come si gioca e com'è strutturato il gioco
void istruzioni(){
    printf("|-|-[BATTAGLIA NAVALE]-|-|\n\n");
    printf("SCOPI DEL GIOCO:\n");
    printf("- Hai una flotta di navi nascoste sulla tua griglia.\n");
    printf("- Anche il nemico ha le sue navi su una griglia segreta.\n");
    printf("- Il tuo obiettivo è colpire e affondare tutte le navi nemiche prima che lui affondi le tue.\n\n");

    printf("COME SI GIOCA:\n");
    printf("- La griglia è divisa in righe e colonne.\n");
    printf("- Ogni cella è identificata da due numeri: riga e colonna (es: 2 3).\n");
    printf("- Inserisci le coordinate dove vuoi sparare.\n");
    printf("- Vedrai se hai COLPITO o MANCATO una nave nemica.\n");
    printf("- Dopo ogni tua mossa, il nemico farà la sua.\n");
    printf("- Puoi interrompere il gioco in qualsiasi momento e salvare la partita.\n\n");

    printf("SIMBOLI DELLA GRIGLIA:\n");
    printf("~ = acqua (non colpita)\n");
    printf("O = colpo a vuoto\n");
    printf("X = colpo a segno\n");
    printf("N = nave tua (visibile solo nella tua griglia)\n\n");

    printf("ESEMPIO DI GRIGLIA:\n");
    printf("    1 2 3 4 5\n");
    printf("  -------------\n");
    printf("A | ~ ~ ~ ~ ~\n");
    printf("B | ~ ~ ~ ~ ~\n");
    printf("C | ~ ~ ~ ~ ~\n");
    printf("D | ~ ~ ~ ~ ~\n");
    printf("E | ~ ~ ~ ~ ~\n\n");

    printf("BUONA FORTUNA COMANDANTE!\n\n");
}

//Funzione 'menu_pricipale': é la funzione in cui il giocatore sceglie cosa fare. Può iniziare una nuova partita, caricarne una vecchia o aprire le istruzioni di gioco.
void menu_principale(char* nome, int* dim){
    char nome[50];
    int dim;
    int scelta;
    printf("-- Benvenuto --\n");
    printf("-- Fai la tua scelta --\n");
    printf("1. Nuova Partita\n");
    printf("2. Carica Partita\n");
    printf("3. Istruzioni\n");
    printf("4. Esci\n");

    printf("Naviga nel menù: \n");
    scanf("%d", &scelta);

    switch(scelta)
    {
        case 1:
        giocatore(nome, &dim);
        break;

        case 2:
        nuova_partita();
        break;

        case 3:
        carica_partita();
        break;

        case 4:
        istruzioni();
        break;

        case 5:
        quit();
        break;

        default:
        perror("Opzione non disponibile");
    }
}

int main(){t
    
    menu_principale(*nome, *dim);

    return 0;
}