#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, num = 0, x = 0, ris = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        fileInput >> n >> x;
        int arr[n]{0};

        for (int i = 0; i < n; i++)
        {
            fileInput >> num;
            arr[i] = num;
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
            {
                ris = i + 1;
                break;
            }

            if (i == n - 1 && arr[i] != x)
            {
                ris = 0;
            }
        }

        fileOutput << ris << endl;
    }
}