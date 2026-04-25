#include <iostream>
#include <cmath>
using namespace std;

void func(int n)
{
    int count = 0;

    for (int i = n / 2; i <= n; i++) // Complessità: O(n)
    {
        for (int j = 1; j <= n; j = 2 * j) // Complessità: O(log n)
        {
            for (int k = 1; k <= n; k = k * 2) // Complessità: O(log n)
            {
                count++; // Complessità totale: log n * log n * n = O(n log^2 n)
            }
        }
    }
}

int main()
{
    int n = 5, c = 3;

    for (int i = 0; i <= n; i *= c) // Complessità: O(log n)
    {
        // Espressioni con costo O(1)
    }

    for (int i = 2; i <= n; i = pow(i, c)) // Complessità: O(log log n)
    {
        // Espressioni con costo O(1)
    }

    func(5);

    for (int i = 1; i < n; i *= 2) // Complessità: O(log n)
    {
        for (int j = 1; j < n / 2; j++) // Complessità: O(n)
        {
            for (int k = j; j < n; k *= 2) // Complessità: O(log n)
            {
                // Complessità totale: log n * n * log n = O(n log^2 n)
            }
        }
    }
}