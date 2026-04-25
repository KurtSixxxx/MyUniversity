#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Se io specifico il parametro array come int *a, come gli passo la dimensione n? Se usi int *a invece di int a[n], la sintassi è diversa ma la logica è la stessa. Perché int *a e int a[n] sono equivalenti come parametri di funzione
int modifica_AB(int n, int a[n], int b[n]){
    int count = 0;
    srand(time(0));
    for(int i = 0; i < n; i++){
        if(b[i] != 0){
            if(((double)a[i]/b[i])<1){
                b[i] = a[i];
                a[i] = (rand()%(200-100+1)+100);
            }else if(((double)a[i]/b[i])>1){
                a[i] = b[i];
                b[i] = (rand()%(100-0+1)+0);
            }else if(((double)a[i]/b[i])==1){
                b[i] = a[i];
                a[i] = 0;
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n = 5;
    int a[n];
    int b[n];

    int valoriA[] = {50, 100, 75, 200, 0};
    int valoriB[] = {100, 50, 75, 100, 10};
    
    for(int i = 0; i < n; i++) {
        a[i] = valoriA[i];
        b[i] = valoriB[i];
    }

    int risultato = modifica_AB(n, a, b);
    printf("Numero di volte in cui a[i]/b[i] = 1: %d volte", risultato);

    return 0;
}

/*
ERRORE: "variable-sized object may not be initialized except with an empty initializer"

SPIEGAZIONE:
Gli array a lunghezza variabile (VLA) in C non possono essere inizializzati con una lista di valori {}.
Questo perché la dimensione 'n' è nota solo a tempo di esecuzione, mentre l'inizializzazione con {}
richiede che la dimensione sia nota a tempo di compilazione.

ESEMPIO SBAGLIATO (genera l'errore):
int n = 5;
// ❌ ERRORE: tentativo di inizializzare VLA con lista di valori
int A[n] = {50, 100, 75, 200, 0};
int B[n] = {100, 50, 75, 100, 10};

### SOLUZIONI CORRETTE:

1. INIZIALIZZAZIONE MANUALE (elemento per elemento):


int n = 5;
int A[n];  // Dichiarazione senza inizializzazione diretta
int B[n];

// Inizializzazione manuale
A[0] = 50; A[1] = 100; A[2] = 75; A[3] = 200; A[4] = 0;
B[0] = 100; B[1] = 50; B[2] = 75; B[3] = 100; B[4] = 10;


2. INIZIALIZZAZIONE CON CICLO:

int n = 5;
int A[n];
int B[n];
int valoriA[] = {50, 100, 75, 200, 0};
int valoriB[] = {100, 50, 75, 100, 10};

for(int i = 0; i < n; i++) {
    A[i] = valoriA[i];
    B[i] = valoriB[i];
}


3. USO DI MACRO PER DIMENSIONE FISSA:

#define N 5  // Dimensione nota a tempo di compilazione
int A[N] = {50, 100, 75, 200, 0};   // ✅ Ora funziona
int B[N] = {100, 50, 75, 100, 10};  // ✅ Ora funziona


4. ALLOCAZIONE DINAMICA:

int n = 5;
int *A = malloc(n * sizeof(int));
int *B = malloc(n * sizeof(int));
int valoriA[] = {50, 100, 75, 200, 0};
int valoriB[] = {100, 50, 75, 100, 10};

for(int i = 0; i < n; i++) {
    A[i] = valoriA[i];
    B[i] = valoriB[i];
}

Ricordati di free(A) e free(B) alla fine!
*/