//bubble sort
/*Il bubble sort è un algoritmo di ordinamento che funziona scambiando ripetutamente gli elementi adiacenti di un array se sono fuori ordine. L'algoritmo continua a scorrere 
l'array e a scambiare gli elementi adiacenti finchè l'array non è completamente ordinato. In altre parole, il bubble sort funziona come se stessimo mescolando un mazzo di carte: 
prendiamo due carte alla volta e le scambiamo se sono fuori ordine. Ripetiamo questo processo fino a quando l'intero mazzo è ordinato.*/
#include <stdio.h>

// Funzione per ordinare un array utilizzando il bubble sort
/*Ordinare le lettere di una stringa,Ordinare in maniera 
lessicografica una stringa,ordinare un array*/
void bubble_sort(int arr[], int n) {
    int i, j, temp;

    // Iteriamo sull'array n-1 volte
    for (i = 0; i < n-1; i++) {
        // Iteriamo sull'array a partire dal secondo elemento
        for (j = 0; j < n-i-1; j++) {
            // Se gli elementi adiacenti sono fuori ordine, scambiamoli
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

//ordinare le colonne di una matrice
void bubble_sort(int arr[], int n) {
    int i, j, temp;

    // Iteriamo sull'array n-1 volte
    for (i = 0; i < n-1; i++) {
        // Iteriamo sull'array a partire dal secondo elemento
        for (j = 0; j < n-i-1; j++) {
            // Se gli elementi adiacenti sono fuori ordine, scambiamoli
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Funzione per ordinare le colonne di un array bidimensionale
void sort_columns(int** matrix, int rows, int cols) {
    for (int col = 0; col < cols; col++) {
        // Estrarre la colonna come un array temporaneo
        int* temp = (int*)malloc(rows * sizeof(int));
        for (int row = 0; row < rows; row++) {
            temp[row] = matrix[row][col];
        }
        // Ordinare l'array temporaneo
        bubble_sort(temp, rows);
        // Reinserire l'array temporaneo nella colonna
        for (int row = 0; row < rows; row++) {
            matrix[row][col] = temp[row];
        }
        // Liberare la memoria dell'array temporaneo
        free(temp);
    }
}

//Ordinare al contrario una stringa
void bubble_sort_chars_desc(char arr[], int n) {
    int i, j;
    char temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//ordinare la matrice le righe di un array
void bubble_sort(int arr[], int n) {
    int i, j, temp;

    // Iteriamo sull'array n-1 volte
    for (i = 0; i < n-1; i++) {
        // Iteriamo sull'array a partire dal secondo elemento
        for (j = 0; j < n-i-1; j++) {
            // Se gli elementi adiacenti sono fuori ordine, scambiamoli
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void sort_rows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        bubble_sort(matrix[i], cols);
    }
}
//ordinare una matrice 
void bubble_sort(double *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                double tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

void sortCols(double ***matrix, int rows, int cols) {
    for (int col = 0; col < cols; col++) {
        double *column = &matrix[0][col][0];
        bubble_sort(column, rows);
    }
}
//ordinare una matrice di stringhe
void bubbleSortStrings(char **strings, int n) {
    int i, j;
    char *temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(strings[j], strings[j + 1]) > 0) {
                temp = strings[j];
                strings[j] = strings[j + 1];
                strings[j + 1] = temp;
            }
        }
    }
}


/*Tieni presente che ho cambiato il modo in cui accedi agli elementi
della tua matrice 3D. Invece di *matrix[i][j], dovresti usare
matrice[i][j][0]. Questo perchè matrice[i][j] è un puntatore a un doppio,
 ed è necessario dereferenziarlo per ottenere il doppio valore effettivo.*/
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Stampa l'array prima dell'ordinamento
    printf("Array prima dell'ordinamento:\n");
    print_array(arr, n);

    // Ordiniamo l'array utilizzando il bubble sort
    bubble_sort(arr, n);

    // Stampa l'array dopo l'ordinamento
    printf("Array dopo l'ordinamento:\n");
    print_array(arr, n);

    return 0;
}
/*In questo esempio, abbiamo definito una funzione bubble_sort che prende come input un array e la sua lunghezza, e lo ordina utilizzando il bubble sort. La funzione utilizza 
due variabili di ciclo i e j per iterare sull'array, e una variabile temp per scambiare i valori degli elementi. All'interno del ciclo esterno, la funzione itera sull'array n-1 volte, 
dove n è la lunghezza dell'array. In ogni iterazione del ciclo esterno, la funzione itera sull'array a partire dal secondo elemento e confronta ogni coppia di elementi adiacenti. 
Se gli elementi adiacenti sono fuori ordine, la funzione li scambia. Questo processo viene ripetuto fino a quando l'intero array è stato ordinato.*/