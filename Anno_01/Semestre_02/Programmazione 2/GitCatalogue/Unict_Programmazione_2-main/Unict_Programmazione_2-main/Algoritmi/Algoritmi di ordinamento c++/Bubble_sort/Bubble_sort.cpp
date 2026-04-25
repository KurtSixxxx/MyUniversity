#include <iostream>

using namespace std;

void scambia(int &x, int &y)
{
    int hold = x;
    x = y;
    y = hold;
}

void bubble_sort(int *A, int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-i-1; j++)
        {
            if(A[j] > A[j+1])
            {
                scambia(A[j],A[j+1]);
            }
        }
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

    bubble_sort(A,n);

    cout <<"\nArray ordinato"<<endl;
    printArray(A,n);

}