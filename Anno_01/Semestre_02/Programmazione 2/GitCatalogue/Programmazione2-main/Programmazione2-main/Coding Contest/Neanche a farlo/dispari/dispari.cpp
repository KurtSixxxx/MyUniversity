#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, num = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {

        fileInput >> n;

        for (int i = 0; i < n; i++)
        {
            fileInput >> num;
            if (num % 2 != 0)
            {
                fileOutput << num << " ";
            }
        }

        fileOutput << '\n';
    }
}
