//selection sort
/*Il selection sort è un algoritmo di ordinamento che funziona selezionando l'elemento più piccolo (o più grande, a seconda dell'ordinamento desiderato) in un array e scambiandolo 
con l'elemento nella prima posizione non ancora ordinata. L'algoritmo ripete questo processo, selezionando l'elemento successivo più piccolo (o più grande) e scambiandolo 
con l'elemento nella seconda posizione non ancora ordinata, e così via, fino a quando non tutti gli elementi sono stati ordinati. In altre parole, il selection sort seleziona l'elemento 
più piccolo (o più grande) in un array e lo mette nella prima posizione, quindi seleziona l'elemento più piccolo (o più grande) tra i rimanenti e lo mette nella seconda posizione, 
e così via. Questo processo continua fino a quando l'intero array è ordinato.*/
#include <stdio.h>

/*Funzione per ordinare un array utilizzando il selection sort
ordinare le lettere di una stringa,ordinare una stringa in modo lessico grafico*/
void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;

    // Iteriamo su ogni elemento dell'array
    for (i = 0; i < n-1; i++) {
        // Inizializziamo l'indice dell'elemento più piccolo alla posizione corrente
        min_index = i;

        // Iteriamo sul resto dell'array per trovare l'elemento più piccolo
        for (j = i+1; j < n; j++) {
            // Se troviamo un elemento più piccolo, aggiorniamo l'indice
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // Se l'elemento più piccolo non è nella posizione corrente, scambiamoli
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}
//Ordinare le righe di una matrice
void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// Funzione per ordinare le righe di una matrice bidimensionale
void sort_rows(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        selection_sort(matrix[i], cols);
    }
}

// Ordinare le colonne di una matrice
void selection_sort(int arr[], int n) {
    int i, j, min_index, temp;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}

// Funzione per ordinare le colonne di una matrice bidimensionale
void sort_columns(int** matrix, int rows, int cols) {
    for (int col = 0; col < cols; col++) {
        // Estrarre la colonna come un array temporaneo
        int* temp = (int*)malloc(rows * sizeof(int));
        for (int row = 0; row < rows; row++) {
            temp[row] = matrix[row][col];
        }
        // Ordinare l'array temporaneo
        selection_sort(temp, rows);
        // Reinserire l'array temporaneo nella colonna
        for (int row = 0; row < rows; row++) {
            matrix[row][col] = temp[row];
        }
        // Liberare la memoria dell'array temporaneo
        free(temp);
    }
}
//Ordinare una stringa al contrario
void selection_sort_chars_desc(char arr[], int n) {
    int i, j, max_index;
    char temp;

    for (i = 0; i < n-1; i++) {
        max_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] > arr[max_index]) {
                max_index = j;
            }
        }
        if (max_index != i) {
            temp = arr[i];
            arr[i] = arr[max_index];
            arr[max_index] = temp;
        }
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
#include <stdio.h>
#include <string.h>

void selectionSortStrings(char **strings, int n) {
    int i, j, min_idx;
    char *temp;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (strcmp(strings[j], strings[min_idx]) < 0) {
                min_idx = j;
            }
        }
        temp = strings[min_idx];
        strings[min_idx] = strings[i];
        strings[i] = temp;
    }
}
//ordinare una stringa
void sortString(char *str) {
    int i, j;
    char temp;

    for (i = 0; i < strlen(str) - 1; i++) {
        for (j = i + 1; j < strlen(str); j++) {
            if (str[i] > str[j]) {
                temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    // Stampa l'array prima dell'ordinamento
    printf("Array prima dell'ordinamento:\n");
    print_array(arr, n);

    // Ordiniamo l'array utilizzando il selection sort
    selection_sort(arr, n);

    // Stampa l'array dopo l'ordinamento
    printf("Array dopo l'ordinamento:\n");
    print_array(arr, n);

    return 0;
}
/*In questo esempio, abbiamo definito una funzione selection_sort che prende come input un array e la sua lunghezza, e la ordina utilizzando il selection sort. La funzione utilizza due 
variabili di ciclo i e j per iterare sull'array, e una variabile min_index per tenere traccia dell'indice dell'elemento più piccolo. All'interno del ciclo esterno, la funzione itera 
sul resto dell'array per trovare l'elemento più piccolo, e se ne trova uno più piccolo, aggiorna il valore di min_index. Una volta che il ciclo è completato, la funzione scambia 
l'elemento nella posizione corrente con l'elemento più piccolo se min_index non è uguale a i. Questo processo viene ripetuto fino a quando l'intero array è stato ordinato.*/
