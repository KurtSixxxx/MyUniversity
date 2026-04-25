#include <iostream>
#include <cstring>

using namespace std;

// Prototipi delle funzioni
void merge(int* A, int i, int m, int f);
void mergeSort(int* A, int i, int f);
void mergeSort(int* A, int n);

void printArray(int *A, int n);

int main()
{
    int A[] = {9,6,8,7,5,10};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "Array prima dell'ordinamento: ";
    printArray(A,n);

    mergeSort(A,n);  // grazie alla funzione "wrapper" altrimenti mergeSort(A, 0, n-1);

    cout << "\nArray ordinato: ";
    printArray(A,n);

    return 0;
}

void mergeSort(int* A, int n)  // funzione "wrapper" 
{
    mergeSort(A, 0, n-1);
}

void merge(int* A, int i, int m, int f)
{  
    int n = f-i+1;         // lunghezza dell'array
    int* A2 = new int[n];  // array temporaneo da contenitore

    int p_meta = i;        // Puntatore prima metà
    int d_meta = m+1;      // Puntatore seconda metà
    int k = 0;             // Puntatore array temporaneo

    // Fusione delle due metà ordinate
    while((k < n) && (p_meta <= m) && (d_meta <= f))
    {
        if(A[p_meta] <= A[d_meta])  // Modificato per stabilità
        {
            A2[k] = A[p_meta];
            p_meta++;
        }
        else
        {
            A2[k] = A[d_meta];
            d_meta++;
        }
        k++;
    }

    // Copia gli elementi rimanenti della prima metà
    while(p_meta <= m)
    {
        A2[k] = A[p_meta];
        p_meta++;
        k++;
    }

    // Copia gli elementi rimanenti della seconda metà
    while(d_meta <= f)
    {
        A2[k] = A[d_meta];
        d_meta++;
        k++;
    }

    memcpy(A+i, A2, n * sizeof(int));
    delete[] A2;
}

void mergeSort(int* A, int i, int f)
{
    if(f <= i)  // Caso base: array di 0 o 1 elemento
    {
        return;
    }

    int m = i + (f-i)/2;  // Modificato per evitare overflow
    mergeSort(A, i, m);   // divisione ricorsiva prima metà 
    mergeSort(A, m+1, f); // divisione ricorsiva seconda metà
    merge(A, i, m, f);    // combinazione delle due metà
}

void printArray(int *A, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}