#include <iostream>
using namespace std;

void ricercaSequenziale(int vec[], int dim)
{
    int cont = 0;

    for (int i = 0; i < dim; i++)
    {
        for (int j = 0; j < dim; j++)
        {
            if (vec[i] == vec[j] && i != j)
            {
                cont++;
            }
        }

        cout << "L'elemento " << vec[i] << " ha " << cont << " ripetizioni" << endl;
        cont = 0;
    }
}

int main()
{
    int vec[10] = {10, 7, 10, 8, 2, 6, 4, 3, 1, 9};

    ricercaSequenziale(vec, 10);
}
