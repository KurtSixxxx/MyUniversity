#include <stdio.h>      //Libreria di default
#include <stdlib.h>     //Libreria per allocazione
#include <string.h>     //Libreria per le stringhe
#include <stdbool.h>    //Libreria per i booleani
#include <time.h>       //Libreria per generazioni pseudocasuali, la utilizzeremo per generare stringhe

#define LEN 10          //Definiamo 10 come lunghezza per tutte le stringhe [9 caratteri + \0]

bool exist_in_Matrix(char ***s, int n, int m, char *c, float w){ //Deve restituire true se esiste almeno una riga o colonna in cui la percentuale di caratteri appartenenti a c è maggiore di w
    int rowCount[n]; //quanti caratteri di c sono stati trovati nella riga i.
    int colCount[m]; //quanti caratteri di c sono stati trovati nella colonna j.
    for(int i = 0; i < n; i++) rowCount[i] = 0; //azzeriamo con i for
    for(int j = 0; j < m; j++) colCount[j] = 0; //azzeriamo con i for

    int totalRow[n];
    int totalCol[m];

    //Scansione della matrice
    //Intanto dobbiamo fare un for per iterare sulle stringhe
    for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
        for (int k = 0; s[i][j][k] != '\0'; k++) { // scorre ogni carattere nella stringa s[i][j]
            for (int h = 0; c[h] != '\0'; h++) {   // confronta con ogni carattere presente in c
                if (s[i][j][k] == c[h]) { //Se c’è match → incrementa contatori di riga e colonna.
                    rowCount[i]++;
                    colCount[j]++;
                    //rowCount[i] e colCount[j] contengono il numero di caratteri trovati.
                    break; // trovato, non serve continuare con gli altri h. evita doppio conteggio sullo stesso char.
                    }
                }
            }
            totalRow[i] = (LEN - 1) * m;
            totalCol[j] = (LEN - 1) * n;
        }
    }


    float percentualeRighe = 0;
    float percentualeColonne = 0;
    //Calcolo percentuali nelle righe
    for(int i = 0; i < n; i++){
    float percentualeRiga = ((float) rowCount[i] / totalRow[i]) * 100; //Calcolo della percentuale
    if (percentualeRiga > w) return true; //Se una percentuale supera w, la funzione torna subito true.
}
    //Calcolo percentuali nelle righe
    for(int j = 0; j < m; j++){ 
    float percentualeColonna = ((float) colCount[j] / totalCol[j]) * 100;
    if (percentualeColonna > w) return true;
}

return false; //se non è true ritorna false
}


int main(){
    //Dichiariamo le dimensioni
    int n = 3;
    int m = 4; 
    float w = 35.0;
    char c[LEN] = "programma"; //Dichiariamo la stringa di confronto

    //Allocazione matrice dinamica in main --> Risultato: matrice 3D matrix[n][m][LEN].
    char ***matrix = malloc(sizeof(char**) * n); //dichiariamo e allochiamo il puntatore per poi allocare n puntatori a puntatori a char (le righe)

    if(matrix != NULL){ //Facciamo un controllo sull'allocazione
        printf("Allocazione riuscita.\n");
    }else{
        fprintf(stderr, "Allocazione fallita.\n");
        return -1;
    }

    for(int i = 0; i < n; i++){
        matrix[i] = malloc(sizeof(char*) * m); //Allochiamo le colonne e per ogni cella della matrice 
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            matrix[i][j] = malloc(sizeof(char) * LEN); //allochiamo le stringhe di lunghezza LEN per ogni cella
        }
    }

    //A questo punto la fase di allocazione è al completo, iniziamo la fase di riempimento della matrice

    srand(time(0)); //Impostiamo il seme.
    char range_A = 'a', range_B = 'z'; //Impostiamo il range delle stringhe casuali
    char casuali[LEN];
    for(int i = 0; i < LEN; i++) {
        casuali[i] = (rand() % (range_B - range_A + 1)) + range_A;
    }
    casuali[9] = '\0';
    
    //Ora riempiamo la matrice
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int k = 0; k < LEN; k++){
                casuali[k] = (rand() % (range_B - range_A + 1)) + range_A;
                }
            casuali[9] = '\0';
            strcpy(matrix[i][j], casuali);
        }
    }

    //Stampiamo la matrice 
    for(int i = 0; i < n; i++){
        printf("\n");
            for(int j = 0; j < m; j++){
                printf(" %s ", matrix[i][j]);
            }
        }

    printf("\n");
    printf("\n");

    bool risultato = exist_in_Matrix(matrix, n, m, c, w);
    printf("%s", risultato ? "true" : "false");

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                free(matrix[i][j]);
            }
            free(matrix[i]);
        }
    free(matrix);

    return 0;
}