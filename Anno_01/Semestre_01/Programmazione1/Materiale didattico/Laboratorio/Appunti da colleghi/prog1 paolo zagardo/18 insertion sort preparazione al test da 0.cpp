//insertion sort
/*L'insertion sort è un algoritmo di ordinamento che funziona inserendo gli elementi di un array nella posizione corretta rispetto agli elementi precedenti. 
L'algoritmo mantiene un array parzialmente ordinato a sinistra dell'indice corrente, e in ogni iterazione prende l'elemento successivo e lo inserisce nella posizione corretta 
all'interno dell'array parzialmente ordinato. In altre parole, l'insertion sort funziona come se stessimo ordinando un mazzo di carte: prendiamo una carta alla volta e la inseriamo 
nella posizione corretta all'interno del mazzo parzialmente ordinato che abbiamo a sinistra.*/
#include <stdio.h>

/*Funzione per ordinare un array utilizzando l'insertion sort
le lettere di una stringa,ordinare una stringa in modo lessicografico*/
void insertion_sort(int arr[], int n) {
    int i, j, key;

    // Iteriamo sull'array a partire dal secondo elemento
    for (i = 1; i < n; i++) {
        // Salviamo il valore dell'elemento corrente
        key = arr[i];

        // Iteriamo sull'array a sinistra dell'elemento corrente
        for (j = i-1; j >= 0 && arr[j] > key; j--) {
            // Spostiamo gli elementi piè grandi alla destra dell'elemento corrente
            arr[j+1] = arr[j];
        }

        // Inseriamo l'elemento corrente nella posizione corretta
        arr[j+1] = key;
    }
}
//Ordinare le righe di una matrice
#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        for (j = i-1; j >= 0 && arr[j] > key; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void sort_rows(int matrix[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        insertion_sort(matrix[i], cols);
    }
}

void print_matrix(int matrix[][4], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
//Ordinare le colonne di una matrice
#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;

    for (i = 1; i < n; i++) {
        key = arr[i];
        for (j = i-1; j >= 0 && arr[j] > key; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}

void sort_columns(int matrix[][3], int rows, int cols) {
    for (int col = 0; col < cols; col++) {
        int temp[rows];
        for (int row = 0; row < rows; row++) {
            temp[row] = matrix[row][col];
        }
        insertion_sort(temp, rows);
        for (int row = 0; row < rows; row++) {
            matrix[row][col] = temp[row];
        }
    }
}

void print_matrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}
//Ordinare una stringa al contrario
void insertion_sort_chars_desc(char arr[], int n) {
    int i, j;
    char key;
	
    for (i = 1; i < n; i++) {
        key = arr[i];
        for (j = i-1; j >= 0 && arr[j] < key; j--) {
            arr[j+1] = arr[j];
        }
        arr[j+1] = key;
    }
}


// Funzione per stampare un array
void print_array(int arr[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

//ordinare una matrice di stringhe
void insertionSortStrings(char **strings, int n) {
    int i, j;
    char *key;

    for (i = 1; i < n; i++) {
        key = strings[i];
        j = i - 1;
        while (j >= 0 && strcmp(strings[j], key) > 0) {
            strings[j + 1] = strings[j];
            j--;
        }
        strings[j + 1] = key;
    }
}


int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Stampa l'array prima dell'ordinamento
    printf("Array prima dell'ordinamento:\n");
    print_array(arr, n);

    // Ordiniamo l'array utilizzando l'insertion sort
    insertion_sort(arr, n);

    // Stampa l'array dopo l'ordinamento
    printf("Array dopo l'ordinamento:\n");
    print_array(arr, n);

    return 0;
}
/*In questo esempio, abbiamo definito una funzione insertion_sort che prende come input un array e la sua lunghezza, e lo ordina utilizzando l'insertion sort. La funzione utilizza 
due variabili di ciclo i e j per iterare sull'array, e una variabile key per salvare il valore dell'elemento corrente. All'interno del ciclo esterno, la funzione itera sull'array 
a partire dal secondo elemento, e in ogni iterazione salva il valore dell'elemento corrente nella variabile key. Quindi, la funzione itera sull'array a sinistra dell'elemento corrente
e sposta gli elementi piè grandi alla destra dell'elemento corrente, finchè non trova la posizione corretta per inserire key. Infine, la funzione inserisce key nella posizione corretta 
 all'interno dell'array parzialmente ordinato. Questo processo viene ripetuto fino a quando l'intero array è stato ordinato.*/
