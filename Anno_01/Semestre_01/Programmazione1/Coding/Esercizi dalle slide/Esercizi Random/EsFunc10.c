/* Consegna:
   Scrivere una funzione che prende in input:
   - una matrice di stringhe A di dimensioni n × m (tipo char***),
   - una matrice di caratteri C di dimensioni k × z (tipo char**),
   - un numero intero w (short).

   La funzione deve restituire true se:
   In almeno UNA riga o UNA colonna della matrice A
   esiste una sequenza CONTIGUA di almeno w caratteri
   che compare anche in UNA riga o UNA colonna della matrice C.

   In altre parole:
   - Considera una riga o colonna di A come una stringa lunga.
   - Considera una riga o colonna di C come un’altra stringa lunga.
   - Se una sottostringa di lunghezza >= w appare in entrambe,
     la funzione ritorna true.
   - Se nessuna corrispondenza viene trovata, ritorna false.
*/

//todo Parametri: Matrice di stringhe ***A[n][m], matrice di caratteri **C[k][z], short w

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STR_LEN 15

bool func(char ***a, char **c, int n, int m, int k, int z, short w){
    char **righe_A = malloc(sizeof(char*) * m);
    for(int i = 0; i < m; i++) righe_A[i] = malloc(sizeof(char) * STR_LEN);

    char **colonne_A = malloc(sizeof(char*) * n);
    for(int i = 0; i < n; i++) colonne_A[i] = malloc(sizeof(char) * STR_LEN);

    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            strcat(righe_A[i], a[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            strcat(righe_A[i], a[i][j]);
        }
    }

}

int main(){
    int n = 4;
    int m = 4;
    int str_len = 10;

    int k = 15;
    int z = 15;

    short w = 3;

    //Allocazione della matrice di stringhe A
    char ***a = malloc(sizeof(char**) * n);

    if(a == NULL){
        fprintf(stderr, "Allocazione fallita");
        return -1;
    }

    for(int i = 0; i < n; i++) a[i] = malloc(sizeof(char*) * m);

    for(int i = 0; i < n; i++){
        for(int j = 0; i < m; j++){
            a[i][j] = malloc(sizeof(char) * str_len);
        }
    }

    //Allocazione dinamica della matrice di caratteri
    char **c = malloc(sizeof(char*) * k);

    if(c == NULL){
        fprintf(stderr, "Allocazione fallita");
        return -1;
    }

    for(int i = 0; i < n; i++) c[i] = malloc(sizeof(char) * z);

    /*
    *
    *
    *
    *
    *
    *
    *
    *
    * 
    */

    return 0;
}