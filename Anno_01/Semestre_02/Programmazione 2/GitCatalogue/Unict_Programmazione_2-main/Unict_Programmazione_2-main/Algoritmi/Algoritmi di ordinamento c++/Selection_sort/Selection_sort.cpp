#include <iostream>
using namespace std;

void scambia(int &x, int &y)
{
    int hold = x;
    x = y;
    y = hold;
}

void selection_sort(int *A, int n)
{
    for(int i=0; i<n-1; i++)
    {
        int val = i;

        for(int j = i+1; j<n; j++)
        {
            if(A[j] < A[val])
            val = j;
        }

        scambia(A[i],A[val]);
    }
}


void printArray(int *A, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << A[i];
    }
}


int main()
{
    int A[] = {9,6,8,7,5,10};
    int n = sizeof(A) / sizeof(A[0]);
    
    cout << "Array prima dell'ordinamento"<<endl;
    printArray(A,n);

    selection_sort(A,n);

    cout <<"\nArray ordinato"<<endl;
    printArray(A,n);

}