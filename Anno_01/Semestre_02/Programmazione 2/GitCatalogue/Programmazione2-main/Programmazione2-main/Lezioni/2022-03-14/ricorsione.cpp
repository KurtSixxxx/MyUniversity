/**************************
 *     TORRI DI HANOI
 **************************/
#include <iostream>
using namespace std;

int succ(int n) // Dimostrazione per induzione
{
    if (n == 0) // caso base
    {
        return 1;
    }
    else // passo induttivo
    {
        return 1 + succ(n - 1);
    }
}

int somma(int a, int b)
{
    if (b == 1)
    {
        return succ(a);
    }
    else
    {
        return somma(a, b - 1) + 1;
    }

    return 0;
}

int prodotto(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return somma(a, prodotto(a, b - 1));
    }
}

int potenza(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return prodotto(a, potenza(a, b - 1)); // a * pow(a, b-1)
    }
}

int fattoriale(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return prodotto(n, fattoriale(n - 1));
    }
}

int fibonacci(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return somma(fibonacci(n - 1), fibonacci(n - 2));
    }
}

int fibonacci_iterativa(int n)
{
    int sum1 = 1; // Fibonacci fino ad n-1
    int sum2 = 1; // Fibonacci fino ad n-2
    int x = 0;

    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        for (int c = 2; c <= n; c++)
        {
            x = sum2;
            sum2 = sum1;
            sum1 = somma(x, sum2);
        }

        return sum1;
    }
}

void hanoi(int n, string partenza, string arrivo, string aus)
{

    if (n == 0)
    {
        return;
    }

    hanoi(n - 1, partenza, aus, arrivo);
    cout << "Sposto il numero " << n << " dal registro " << partenza << " al registro " << arrivo << endl;

    hanoi(n - 1, aus, arrivo, partenza);
}
int main()
{
    cout << "Successore di 5: " << succ(5) << endl;

    cout << "Somma tra 3 e 2: " << somma(3, 2) << endl;

    cout << "Prodotto tra 3 e 2: " << prodotto(3, 2) << endl;

    cout << "Elevamento a potenza tra 3 e 2: " << potenza(3, 2) << endl;

    cout << "Fattoriale di 5: " << fattoriale(5) << endl;

    cout << "Fibonacci di 7: " << fibonacci(7) << endl;

    cout << "Fibonacci iterativa di 7: " << fibonacci_iterativa(7) << endl;

    cout << "\n\n********************************************************\n\n";

    hanoi(5, "Sorgente", "Destinazione", "Ausiliario");
}