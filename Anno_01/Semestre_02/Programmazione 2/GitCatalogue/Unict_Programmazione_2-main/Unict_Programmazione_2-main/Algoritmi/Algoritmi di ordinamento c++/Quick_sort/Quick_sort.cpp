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


void quickSort(int* A, int f, int l)
{
    if(l <= f)  // se la sottosequenza ha zero o un elemento, la funzione termina subito perché non c’è nulla da ordinare.
    return;

    
    int i = f;
    int j = l;

    int pivot = A[(f+l)/2];

    while(i <= j)
    {
        while (A[i] < pivot) i++;
        while (A[j] > pivot) j--;

        if(i <= j)
        {
            scambia(A[i],A[j]);
            i++;
            j--;
        }
    }

    if (f < j)
    quickSort(A,f,j);

    if(i < l)
    quickSort(A,i,l);
}