#include <iostream>
using namespace std;

int ricerca_squenziale(int *A, int dim, int key)
{
    for(int i=0; i<dim; i++)
    {
        if(key == A[i]){
            return i;
        }
    }

    return -1;
}

void sort(int &a, int &b)
{
    int hold = a;
    a = b;
    b = hold;
}

void bubblesort(int *A, int dim)
{
    for(int i=0; i<dim-1; i++)
    {
        for(int j=0; j<dim-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                sort(A[j],A[j+1]);
            }
        }
    }
    
}


int ricerca_binaria(int *A, int dim, int left, int right, int key)
{
    int i = 0;

    while(left<=right)
    {
        
        int mid = (left + right)/2;

        if(A[mid] == key)
        {
            cout << "Numero di controlli : " << i << endl;
            return key;
        }

        else if(A[mid] < key)
        {
            left = mid + 1;
        }

        else
        {
            right = mid - 1; 
        }
        i++;

        
    }

   

    return -1;
}


int main()
{
    int A[] = {0,6,5,9,8,1,2,3,4,7,10};
    int dim = sizeof(A)/sizeof(A[0]);
    int key = 7;
    int l = 0;
    int r = dim - 1;

    int s = ricerca_squenziale(A,dim,key);

    cout << "Ricerca -sequenziale- Chiave trovata all'indice : " << s << endl;

    bubblesort(A,dim);

    int b = ricerca_binaria(A,dim,l,r,key);

    cout << "Ricerca -binaria- Chiave trovata all'indice : " << b << endl;    
}
