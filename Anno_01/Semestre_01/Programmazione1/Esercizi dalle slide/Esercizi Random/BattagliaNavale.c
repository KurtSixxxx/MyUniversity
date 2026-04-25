//Battaglia Navale: v2.0

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX 21  //Questo è il massimo della dimensione del campo. Corrisponde alle 21 lettere dell'alfabeto.
#define MIN 10   //Questo è il valore minimo della dimensione del campo.
#define WATER 0
#define SHIP  1
#define HIT   2
#define MISS  3

/* === INDICE FUNZIONI ===
clearBoard         : azzera una board
cellToChar_*       : mapping numeri -> simboli
printBoards        : stampa due tabelle
coordToIndex       : legge STOP/coordinate (scrive row/col)
inBounds           : check bordi
randInRange/Bool   : casualità base
canPlaceShip       : verifica posizionamento
writeShip          : (DA FARE) scrive nave
placeShip          : (DA FARE) trova punto valido e chiama writeShip
placeFleet         : (DA FARE) piazza più navi
*/


//Funzione che azzera tutta la griglia di battaglia.
void clearBoard(int b[MAX][MAX], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            b[i][j] = 0; //Iteriamo su tutta la matrice ed impostiamo ogni parte a 0.
        }
    }
}

//Funzione che 'converte' il valore in char per il player
char cellToChar_player(int v){
    if (v == WATER) return ' ';
    if (v == SHIP)  return 'S';
    if (v == HIT)   return 'X';
    if (v == MISS)  return '-';
    return '?';            //Caso imprevisto
}  

//Funzione che 'converte' il valore in char per l'avversario
char cellToChar_enemy(int v){
    if(v == WATER) return ' '; //Mare sconosciuto
    if(v == SHIP) return ' '; //Non mostrare la nave, altrimenti bari
    if(v == HIT) return 'X'; //Colpita nave nemica
    if(v == MISS) return '-'; //Acqua (tiro a vuoto)
    return '?';            //Caso imprevisto

}

//Funzione che stampa 2 array: a sinistra playerBoard con cellToChar_player, a destra enemyview con cellToChar_enemy
void printBoards(int n, const char* nome, int playerBoard[MAX][MAX], int enemyView[MAX][MAX]){
    printf("%sBoard\t\t\tEnemyView\n", nome);

    printf("  ");
    for(int j = 0; j < n; j++) printf("|%c|", 'A' +  j);
    printf("\t");
    printf("  ");
    for(int j = 0; j < n; j++) printf("|%c|", 'A' +  j);
    printf("\n");

    for (int i = 0; i < n; ++i) {
        printf("%2d ", i + 1);
        for (int j = 0; j < n; ++j) printf("[%c]", cellToChar_player(playerBoard[i][j]));
        printf("    ");
        for (int j = 0; j < n; ++j) printf("[%c]", cellToChar_enemy(enemyView[i][j]));
        printf("\n");
    }
}

//Funzione che converte le coordinate inserite dall'utente in punti della matrice e si occupa di gestire 'Stop' nel flusso di gioco
int coordToIndex(char input[], int n, int *row, int *col){
    //Abbiamo 3 variabili:
    int letti;
    char lettera;
    int numero;
    /*
    Legge una riga con (fgets) e toglie \n con strcspn
    Se l'input è STOP/Stop/stop --> return 1
    Altrimenti prova a leggere lettera + numero
    Converte in indici della matrice, controlla i limiti, e scrive i valori in *row e *col, con finale in return 0
    se qualcosa non va: return -1
    */
    fgets(input, 20, stdin); //Qui stiamo dicendo di prelevare da tastiera (stdin) il contenuto di 'input' (che ha un buffer di 20)
    input[strcspn(input, "\n")]  = '\0'; //Qui stiamo dicendo --> "Se in input trovi \n vuol dire che siamo arrivati alla fine della stringa, allora sostituisci con \0 (terminatore di stringa)"
    if(strcmp(input, "STOP") == 0 || strcmp(input, "Stop") == 0 || strcmp(input, "stop") == 0) return 1; //Qui diciamo --> "Se quello che trovi nella comparazione tra la stringa contenuta in input è uguale a "STOP/Stop/stop" (quindi da esito 0) allora ritorna 1.

    //Adesso usiamo la funzione sscanf
    letti = sscanf(input, " %c%d", &lettera, &numero);
    if(letti != 2) return -1; //I valori letti da sscanf non sono 2, come dovrebbero essere.
    if(letti == 2){
    int c = toupper((unsigned char)lettera) - 'A'; //usare la funzione toupper() | Converte un minuscolo in maiuscolo. Se il carattere è già minuscolo rimane invariato.
    int r = numero - 1;
    if(c < 0 || c >= n || r < 0 || r >= n) return -1;
    *col = c;
    *row = r;
    return 0;
    }
}

//Funzione che serve per dire se una cella (r,c) sta dentro una griglia n×n.
bool inBounds(int n, int r, int c){
    return (r >= 0 && r < n && c >= 0 && c < n);
}

//Funzione che resitutisce un intero randomico nel range n (dimensione del campo)
int randInRange(int n){
    if(n <= 0) return 0;
    return(rand()%n);
}

//Funzione che si occupa di randomizzare il posizionamento verticale o orizzontale delle navi
bool randBool(){    
    int scelta = rand()%2;
    if(scelta == 0){return false;
    }else return true;
}

// Funzione che dice se una nave può essere posizionata a partire da (r,c) | lunga 'len' e orientata orizzontalmente (horizontal=true) o verticalmente (false) | senza uscire dalla griglia n×n e senza sovrapporsi ad altre navi.
bool canPlaceShip(int board[MAX][MAX], int n, int r, int c, int len, bool horizontal){
    // Scegliamo i "passi" (delta) da fare ad ogni segmento della nave:
    // se horizontal = true  -> dr=0 (la riga non cambia),  dc=1 (la colonna avanza di 1)
    // se horizontal = false -> dr=1 (la riga avanza di 1), dc=0 (la colonna non cambia)
    int dr = horizontal ? 0 : 1;
    int dc = horizontal ? 1 : 0;

    // Cicliamo su tutti i segmenti della nave: k = 0 .. len-1 (sono esattamente 'len' celle)
    for(int k = 0; k < len; k++){
        // Calcoliamo la cella k-esima occupata dalla nave:
        // rr = r + dr*k  (nuova riga dopo k passi)
        // cc = c + dc*k  (nuova colonna dopo k passi)
        int rr = r + dr * k;
        int cc = c + dc * k;

        // 1) Controllo bordi: se (rr,cc) è fuori dalla griglia n×n, non si può posizionare
        if(!inBounds(n, rr, cc)) return false;

        // 2) Controllo sovrapposizione: se la cella NON è vuota (0), c’è già qualcosa → vietato
        if(board[rr][cc] != 0) return false;
    }
    // Se tutti i segmenti passano i due controlli, la nave "ci sta" → ok
    return true;
}


int main(){

    //Definiamo le matrici:
    int playerBoard[MAX][MAX];  //Il campo dell'user, contiene le sue navi. Mostrerà sempre mare e navi.
    int enemyBoard[MAX][MAX];   //Il campo dell'avversario con le sue navi. Non verrà mostrato al giocatore.
    int enemyView[MAX][MAX];    //Il campo dell'avversario che mostreremo al giocatore, qui si vedrà solo se un colpo andrà a segno o no.
    /* Legenda stati cella:
    0 = '[ ]' (mare)
    1 = 'S' (nave)
    2 = 'X' (colpita)
    3 = '-' (acqua) */

    //Definiamo le variabili che useremo come input utente
    char nome[30];      //Nome utente.
    int n;              //Dimensione del campo.
    int minLen, maxLen; //Dimensione minima e massima delle navi.
    char input[20];     //Lo uso per far scrivere 'STOP'/'Stop'/'stop' e coordinate all'utente

    //Prendiamo gli input utente:
    printf("Benvenuto, giochiamo a 'BATTAGLIA NAVALE'\n");
    printf("Inserisci il tuo nome: ");
    scanf("%29s", nome); //Memorizziamo la variabile nome.

    printf("Inserisci la dimensione del campo che desideri (max: %d): ", MAX);
    scanf("%d", &n);    //Memorizza la dimensione del campo, occorre un solo valore perchè il campo è quadrato.

    //Controlliamo se i valori inseriti sono validi o no. E inseriamo anche ulteriori messaggi di errore
    if (n < MIN || n > MAX) {
        fprintf(stderr, "Dimensione non valida. Consentito: [%d..%d]\n", MIN, MAX);
        return 1;
    }

    printf("Inserisci la dimensione minima delle navi: ");
    scanf("%d", &minLen); //Memorizza la dimensione minima delle navi in campo, intesa come le celle occupate.
    printf("Inserisci la dimensione massima delle navi: ");
    scanf("%d", &maxLen); //Memorizza la dimensione massima delle navi in campo, intesa come le celle occupate.

    // Controlli coerenza lunghezze nave
    if (minLen < 2){ 
        fprintf(stderr, "Lunghezza minima troppo piccola (>=2).\n"); return 1;
    }
    if (maxLen > n){
        fprintf(stderr, "Lunghezza massima non può superare n (%d).\n", n); return 1;
    }
    if (minLen > maxLen){ 
        fprintf(stderr, "MIN non può essere > MAX.\n"); return 1;
    }

    srand(time(0)); //Chiamo la fuzione srand() con time(0) per generare numeri pseudo casuali al fine di posizionare casualmente le navi user e avversarie.

    return 0;
}