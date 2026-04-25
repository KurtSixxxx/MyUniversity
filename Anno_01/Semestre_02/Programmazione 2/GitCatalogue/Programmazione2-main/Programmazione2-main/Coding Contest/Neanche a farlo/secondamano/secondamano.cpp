#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, m = 0, risultato = 0, num = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {

        fileInput >> n;
        fileInput >> m;

        int vendite[n]{0};
        int acquisti[m]{0};
        risultato = 0;

        for (int i = 0; i < n; i++)
        {
            fileInput >> num;
            vendite[i] = num;
        }

        for (int i = 0; i < m; i++)
        {
            fileInput >> acquisti[i];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (acquisti[i] == vendite[j])
                {
                    risultato += 5;
                }
            }
        }

        fileOutput << risultato << '\n';
    }
}
