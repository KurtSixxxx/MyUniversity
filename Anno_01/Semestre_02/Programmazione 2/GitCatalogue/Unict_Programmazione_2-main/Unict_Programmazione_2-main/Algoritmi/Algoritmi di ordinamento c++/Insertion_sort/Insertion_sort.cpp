#include <iostream>

using namespace std;

void insertion_sort(int *A, int n)
{
    for(int i=1; i<n; i++)
    {
        int val = A[i];
        int j = i-1;

        while(j>=0 && A[j] > val )
        {
            A[j+1] = A[j];
            j--;
        }

        A[j+1] = val;
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

    insertion_sort(A,n);

    cout <<"\nArray ordinato"<<endl;
    printArray(A,n);

}

