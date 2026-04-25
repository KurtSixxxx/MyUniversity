#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

void print(int *arr, int n)
{
    cout << "[ ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]" << endl;
}

int ricercaBinaria(int v[], int basso, int alto, int chiave)
{
    int cont = 0;
    int centrale;
    int valoreCentrale;
    while (basso <= alto)
    {

        centrale = (basso + alto) / 2;
        valoreCentrale = v[centrale];

        if (chiave == valoreCentrale)
        {
            return cont;
        }

        else if (chiave < valoreCentrale)
        {
            alto = centrale - 1;
            cont++;
        }
        else
        {
            basso = centrale + 1;
            cont++;
        }
    }

    return cont;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int vec[], int dim)
{
    int indexMin;

    for (int c = 0; c < dim; c++)
    {
        indexMin = c;

        for (int i = c + 1; i < dim; i++)
        {
            if (vec[i] < vec[indexMin])
            {
                indexMin = i;
            }
        }

        swap(vec[c], vec[indexMin]);
    }
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int n = 0, x = 0, ris = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> n >> x;

        int arr[n]{0};

        for (int i = 0; i < n; i++)
        {
            fileInput >> arr[i];
        }

        selectionSort(arr, n);
        print(arr, n);
        ris = ricercaBinaria(arr, 0, n, x);

        fileOutput << ris << endl;
    }
}
