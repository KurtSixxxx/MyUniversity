#include <iostream>

using namespace std;

void printArray(int *A, int n);
void scambia(int &x, int &y);
void quickSort(int* A, int n);
void quickSort(int* A, int  f, int l);

int main()
{
    int A[] = {9,6,8,7,5,10};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "Array prima dell'ordinamento"<<endl;
    printArray(A,n);
    
    quickSort(A,n);

    cout <<"\nArray ordinato"<<endl;
    printArray(A,n);

}

void printArray(int *A, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << A[i];
    }
}

void scambia(int &x, int &y)
{
    int hold = x;
    x = y;
    y = hold;
}


void quickSort(int* A, int n)
{
    quickSort(A,0,n-1);
}

void quickSort(int* A, int  f, int l)   //f = first , l = last
{
    if(l <= f)       // Caso base: se l'indice last è minore o uguale a first, 
    return;           // l'array ha 0 o 1 elemento ed è già ordinato

    int p_index = f + (l - f) / 2; // indice centrale
    scambia(A[p_index], A[l]);     // porta il pivot in fondo
    int pivot = A[l];              // ora il pivot è in fondo

    int i = f-1;    //prima del primo elemento (f-1), terrà traccia della posizione corretta del pivot
    int j = f;      //parte dal primo elemento (f), scorre l'array

    while(j < l)    //Scorriamo l'array con j fino a prima del pivot (l)
    {
        if(A[j] <= pivot)
        {
            i++;
            scambia(A[i], A[j]);
        }
        j++;
    }

    scambia(A[i+1],A[l]);   // Alla fine del ciclo, posizioniamo il pivot al posto corretto (i+1)

    quickSort(A,f,i);     // Chiamata ricorsiva per ordinare la parte sinistra
    quickSort(A,i+2,l);   // Chiamata ricorsiva per ordinare la parte destra
}