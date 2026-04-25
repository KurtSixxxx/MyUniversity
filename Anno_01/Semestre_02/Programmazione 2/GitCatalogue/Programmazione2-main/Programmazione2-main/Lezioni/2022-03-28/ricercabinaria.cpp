#include <iostream>
using namespace std;

bool ricercaBinaria(int array[], int dim, int key)
{
    bool found = false;
    int start = 0, end = dim - 1;

    while (!found && (start != end))
    {
        int midpoint = start + ((end - start) / 2); // dim / 2

        if (array[midpoint] == key)
        {
            found = true;
        }
        else if (key < array[midpoint]) // Considerare la metà inferiore
        {
            // Aggiorniamo end
            end = midpoint;
        }
        else // Considerare la metà superiore
        {
            // Aggiorniamo start
            start = midpoint + 1;
        }

        cout << "Start: " << start << "\tMidpoint: " << midpoint << "\tEnd:" << end << endl;
    }

    return found;
}

int main()
{
    int vec[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    if (ricercaBinaria(vec, 10, 7) == true)
    {
        cout << "Ho trovato il numero" << endl;
    }
    else
    {
        cout << "Numero non trovato" << endl;
    }
}