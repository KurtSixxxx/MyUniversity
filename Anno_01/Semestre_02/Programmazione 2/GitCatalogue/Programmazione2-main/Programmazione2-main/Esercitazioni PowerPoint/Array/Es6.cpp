/*Definire un programma che visualizzi un triangolo di Pascal*/

#include <iostream>
using namespace std;
#define N 7

int main()
{
    int arr[N][N];

    arr[0][0] = 1;

    for (int i = 0; i < N; i++)
    {
        arr[0][i] = 0;
    }

    for (int i = 1; i < N; i++)
    {
        arr[i][0] = 1;

        for (int j = 1; j < N; j++)
        {
            arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " " << arr[i][j];
        }

        cout << endl;
    }
}
