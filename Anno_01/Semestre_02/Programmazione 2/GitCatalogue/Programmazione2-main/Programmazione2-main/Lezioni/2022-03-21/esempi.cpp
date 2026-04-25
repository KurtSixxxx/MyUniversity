#include <iostream>
using namespace std;

int potenza(int a, int b)
{
    if (b == 1) // Caso base
    {
        return a;
    }
    else // Passo induttivo
    {
        return a * potenza(a, b - 1);
    }
}

// n chiamate ricorsive, tempo e spazio O(n)

int potenza2(int x, int n)
{
    int y = 0;

    if (n == 0) // Caso base
    {
        return 1;
    }
    if (n % 2 != 0)
    {
        y = potenza2(x, (n - 1) / 2);
        return x * y * y;
    }
    else // Passo induttivo
    {
        y = potenza2(x, n / 2);
        return y * y;
    }
}

// log n chiamate ricorsive, tempo e spazio O(log n)

int sommaMassima1(int S[], int n) // Costo n^3
{
    int max = 0;
    int somma;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            somma = 0;
            for (int k = i; k <= j; k++)
            {
                somma = somma + S[k];

                if (somma > max)
                {
                    max = somma;
                }
            }
        }
    }

    return max;
}

int sommaMassima2(int S[], int n) // Costo n^2
{
    int max = 0;
    int somma;

    for (int i = 0; i < n; i++)
    {
        somma = 0;

        for (int j = i; j < n; j++)
        {
            somma = somma + S[j];

            if (somma > max)
            {
                max = somma;
            }
        }
    }

    return max;
}

int sommaMassima3(int S[], int n) // Costo n
{
    int max = 0;
    int somma = max;

    for (int i = 0; i < n; i++)
    {
        if (somma > 0)
        {
            somma = somma + S[i];
        }
        else
        {
            somma = S[i];
        }

        if (somma > max)
        {
            max = somma;
        }
    }

    return max;
}

/* Utilizziamo la strategia del divide and conqueer, scomponiamo il problema in 3 sottoproblemi:

- Somma massima nella metà di sinistra
- Somma massima nella metà di destra
- Somma massima della sequenza che incrocia il punto mediano
*/

int max_of(int a, int b) { return (a > b) ? a : b; }

int max_of(int a, int b, int c) { return max_of(max_of(a, b), c); }

// Trova la somma massima in arr[] t.c. il segmento include arr[m]
int maxCrossingSum(int arr[], int l, int m, int h)
{ // Cerco nella parte sx di mid.
    int sum = 0;
    int left_sum = INT_MIN; // posso mettere anche -100000...
    for (int i = m; i >= l; i--)
    {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    // Cerco nella parte dx di mid.
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++)
    {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    // restituire direttamente left_sum + right_sum
    // fallirebbe in caso di somme parziali negative
    return max_of(left_sum + right_sum, left_sum, right_sum);
}

// Ritorna la somma del segmento con somma massima
// in arr[l....h]
int maxSubArraySum(int arr[], int l, int h)
{
    // Caso base: un solo elemento
    if (l == h)
        return arr[l];

    // middle point
    int m = (l + h) / 2;

    /* Restituisce il massimo dei tre
    a) Max somma a sx
    b) Max somma a dx
    c) Max considerando sequenze che includono arr[m] */
    return max_of(maxSubArraySum(arr, l, m),
                  maxSubArraySum(arr, m + 1, h),
                  maxCrossingSum(arr, l, m, h));
}

int sommaMassima4(int S[], int n) // Costo n log n
{
    return maxSubArraySum(S, 0, n - 1);
}

int main()
{
    int x = 2, n = 3;

    cout << "\nPrimo caso: " << potenza(x, n);

    cout << "\nSecondo caso: " << potenza2(x, n);

    int array[] = {1, 12, 3, 10, 4, 2, 7, 11};

    cout << "\nSomma Massima 1: " << sommaMassima1(array, 8);

    cout << "\nSomma Massima 2: " << sommaMassima2(array, 8);

    cout << "\nSomma Massima 3: " << sommaMassima3(array, 8);

    cout << "\nSomma Massima 4: " << sommaMassima4(array, 8);
}