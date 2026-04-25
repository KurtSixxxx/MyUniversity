#include <iostream>
#include <cstdlib>
using namespace std;

// funzioni generali per randomizzare un array, verificare se è ordinato, scambiare il valore di due variabli, stampare i valori di un array
void randomize(int * vett, int dim)
{
    while (dim>0)
    {
        dim-=1;
        vett[dim]=rand()%100;
    }
}

bool issorted(int * vett, int dim)
{
    if (dim<2)
        return true;
    if (vett[dim-1]>=vett[dim-2])
        return issorted(vett, dim-1);
    return false;
}

void swap (int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

void print(int * vett, int dim)
{
    for(int i=0; i<dim; ++i)
        cout << vett[i] << ' ' ;
    cout << endl;
}


// funzioni di ordinamento
void insertion(int * vett, int dim)
{
    for(int i=1; i<dim; ++i)
    {
        int pos=i;
        while (vett[pos]<vett[pos-1] && pos>0)
        {
            swap(vett[pos], vett[pos-1]);
            print(vett,dim);
            pos-=1;
        }
    }
}

void selection(int * vett, int dim)
{
    for(int i=0; i<dim; ++i)
    {
        int m=i;
        for(int j=i+1; j<dim; ++j)
        {
            if (vett[j]<vett[m])
                m=j;
        }
        swap(vett[i], vett[m]);
        print(vett, dim);
    }
}

void bubble(int * vett, int dim)
{
    while (dim>0)
    {
        dim-=1;
        for(int i=0; i<dim; ++i)
            if (vett[i]>vett[i+1])
            {
                swap(vett[i], vett[i+1]);
                print(vett, dim);
            }
    }
}


int main()
{
    srand(time(0));
    
    int n=5;
    
    int *a=new int[n];
    randomize(a, n);
    
    print(a,n);
    sort::bubble(a, n);
    cout << issorted(a,n);
}
