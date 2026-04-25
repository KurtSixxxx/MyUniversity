#include <iostream>
using namespace std;
#define MAX 100

double array[MAX] = {0};
int counter = 0;

void leggiElementi()
{
    double input = 0.0;

    cout << "\nInserisci un numero: ";
    cin >> input;

    while (input != 0 && counter < MAX)
    {
        array[counter] = input;
        counter++;

        cout << "\nInserisci un numero: ";
        cin >> input;
    }
}

void stampaElementi()
{
    cout << "Array: [ ";
    for (int c = 0; c < counter; c++)
    {
        cout << array[c] << " ";
    }

    cout << "]";
}

int main()
{
    leggiElementi();
    stampaElementi();
}