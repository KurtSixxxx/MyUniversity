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

void print(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << endl;
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int bubbleSort(int vec[], int dim)
{
    int cont = 0;
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (vec[c] > vec[i])
            {
                cont++;
                swap(vec[c], vec[i]);
            }
        }
    }

    return cont;
}

int *getSommaDiagonali(int **arr, int n, int m)
{
    int *somma = new int[n + m - 1];
    int k = 0;

    // Diagonali della matrice triangolare sinistra
    for (int j = m - 1; j >= 1; j--)
    {
        int tempCol = j;
        int tempn = 0;
        int tempSum = 0;

        while (tempCol < m && tempn < n)
        {
            tempSum += arr[tempn][tempCol];
            tempCol++;
            tempn++;
        }

        somma[k++] = tempSum;
    }

    // Diagonale principale
    int princDiagonalSum = 0;
    for (int i = 0; i < n && i < m; i++)
    {
        princDiagonalSum += arr[i][i];
    }

    somma[k++] = princDiagonalSum;

    // Diagonali della matrice triangolare destra
    for (int i = 1; i < n; i++)
    {
        int tempn = i;
        int tempCols = 0;
        int tempSum = 0;

        while (tempn < n && tempCols < m)
        {
            tempSum += arr[tempn][tempCols];
            tempn++;
            tempCols++;
        }

        somma[k++] = tempSum;
    }

    return somma;
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);
    int num = 0, r = 0, c = 0, ris = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> r >> c;
        int **mat, *somma;

        mat = new int *[r];
        somma = new int[r + c - 1];
        for (int i = 0; i < r; i++)
        {
            mat[i] = new int[c];
            for (int j = 0; j < c; j++)
            {
                fileInput >> num;
                mat[i][j] = num;
            }
        }

        // print(mat, r, c);

        somma = getSommaDiagonali(mat, r, c);

        bubbleSort(somma, r + c - 1);

        for (int i = 0; i < (r + c - 1); i++)
        {
            fileOutput << somma[i] << " ";
        }

        fileOutput << endl;
    }
}
