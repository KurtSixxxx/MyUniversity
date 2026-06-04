#include <stdio.h>      // Libreria standard input/output (printf, fprintf, ecc.)
#include <stdlib.h>     // Libreria per funzioni di allocazione dinamica (malloc, free)
#include <string.h>     // Libreria per funzioni sulle stringhe (strlen, strcpy, ecc.)
#include <stdbool.h>    // Libreria per il tipo booleano (true/false)
#include <time.h>       // Libreria per il tempo (usata per il seme di rand())

// Funzione che controlla se esistono righe e colonne con almeno una stringa più corta di k caratteri
bool foo(char ***s, int str_len, int n, int m, short w, short k){
    int righetotali = 0;      // Contatore di righe che contengono almeno una stringa di lunghezza < k
    int colonnetotali = 0;    // Contatore di colonne che contengono almeno una stringa di lunghezza < k

    // Iteriamo sulle righe della matrice
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            // Se la stringa s[i][j] ha lunghezza inferiore a k
            if(strlen(s[i][j]) < k){
                righetotali++;  // Incrementa contatore righe
            }
        }
    }

    // Iteriamo sulle colonne della matrice
    for(int j = 0; j < m; j++){
        for(int i = 0; i < n; i++){
            // Se la stringa s[i][j] ha lunghezza inferiore a k
            if(strlen(s[i][j]) < k){
                colonnetotali++;  // Incrementa contatore colonne
            }
        }
    }

    // Condizione finale: se esiste almeno 1 riga (righetotali > 0)
    // E almeno 1 colonna (colonnetotali > 0) con stringhe corte
    if((righetotali != 0) && (colonnetotali != 0)){
        return true;   // Allora ritorna vero
    }
        
    return false;      // Altrimenti ritorna falso
}

int main(){
    int n = 3;       // Numero di righe della matrice
    int m = 4;       // Numero di colonne della matrice
    short w = 3;     // Parametro NON utilizzato nella funzione foo
    short k = 13;    // Soglia massima per la lunghezza di una stringa
    int str_len = 10; // Lunghezza fissa per ogni stringa allocata (incluso '\0')

    // Allocazione della matrice di stringhe (tipo char***)
    char ***s = malloc(sizeof(char**) * n); // Alloca spazio per n righe (array di puntatori a char**)

    if(s == NULL){
        // Controllo errore: malloc non riuscita
        fprintf(stderr, "Allocazione fallita.");
        return 1;
    }

    // Per ogni riga allochiamo m colonne (array di puntatori a char*)
    for(int i = 0; i < n; i++) s[i] = malloc(sizeof(char*) * m);

    // Per ogni cella della matrice allochiamo una stringa di lunghezza str_len
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            s[i][j] = malloc(sizeof(char) * str_len);
        }
    }

    // Inizializzazione del generatore di numeri casuali con seme = orario attuale
    srand(time(0));

    char range_min = 'a';   // Carattere minimo (a)
    char range_max = 'z';   // Carattere massimo (z)

    // Riempimento della matrice con stringhe casuali
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            for(int z = 0; z < str_len; z++){    
                // Genera carattere casuale tra 'a' e 'z'
                s[i][j][z] = rand() % (range_max - range_min + 1) + range_min;
            }
            // Ultimo carattere della stringa = terminatore '\0'
            s[i][j][str_len - 1] = '\0';
        }
    }

    // Stampa a video della matrice di stringhe generate
    for(int i = 0; i < n; i++){
        printf("\n");
        for(int j = 0; j < m; j++){
            printf("%s ", s[i][j]);
        }
    }

    printf("\n");
    printf("\n");

    // Chiamata alla funzione foo per verificare la condizione
    bool risultato = foo(s, str_len, n, m, w, k);

    // Stampa risultato (true/false)
    printf("%s", risultato ? "true" : "false");

    // DEALLOCAZIONE memoria
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            free(s[i][j]);  // Libera ogni stringa
        }
        free(s[i]);         // Libera le colonne
    }
    free(s);                // Libera le righe

    return 0;
}
