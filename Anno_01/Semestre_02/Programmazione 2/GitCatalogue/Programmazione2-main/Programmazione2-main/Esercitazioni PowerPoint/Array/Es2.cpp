/*Definire più metodi per stampare i numeri primi <=n,e valutare il loro tempo di esecuzione per valori di n crescenti.*/

#include <iostream>
#include <cmath>
using namespace std;

void metodo1()
{
    int num;
    bool flag = true;
    cout << "Inserisci un numero maggiore di 2: ";
    cin >> num;

    for (int i = 2; i <= num; i++)
    {
        flag = true;
        for (int j = 2; j <= i / 2; j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << i << endl;
        }
    }
}

void metodo2()
{
    int num;
    bool flag = true;
    cout << "Inserisci un numero maggiore di 2: ";
    cin >> num;

    for (int i = 2; i <= num; i++)
    {
        flag = true;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                flag = false;
                break;
            }
        }

        if (flag)
        {
            cout << i << endl;
        }
    }
}

void metodo3()
{
}

int main()
{
    int scelta = 0;

    cout << "------------ MENU ------------" << endl
         << endl;

    cout << "1) Metodo [2, num/2]" << endl;
    cout << "2) Metodo [2, sqrt(num)]" << endl;
    cout << "3) Metodo del Crivello di Eratostene" << endl
         << endl;
    ;

    cout << "------------------------------" << endl;

    cout << "Scegli una opzione: ";
    cin >> scelta;

    switch (scelta)
    {
    case 1:
    {
        metodo1();
        break;
    }
    case 2:
    {
        metodo2();
        break;
    }
    case 3:
    {
        metodo3();
        break;
    }
    default:
    {
        cout << "Scelta errata!";
        break;
    }
    }
}