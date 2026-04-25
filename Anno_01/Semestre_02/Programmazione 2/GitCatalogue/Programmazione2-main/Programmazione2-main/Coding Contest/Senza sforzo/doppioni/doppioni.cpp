#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, num = 0, cont = 0, x = 0;
    bool trovato = false;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> n;
        int arr[n]{0};
        int duplicati[n]{0};
        x = 0;
        cont = 0;
        for (int i = 0; i < n; i++)
        {
            fileInput >> num;
            arr[i] = num;
        }

        for (int i = 0; i < n; i++)
        {
            trovato = false;

            for (int j = 0; j < n; j++)
            {
                if (arr[i] == duplicati[j])
                {
                    trovato = true;
                    break;
                }
            }
            if (!trovato)
            {
                duplicati[i] = arr[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (duplicati[i] == 0)
            {
                cont++;
            }
        }

        fileOutput << cont << endl;
    }
}
