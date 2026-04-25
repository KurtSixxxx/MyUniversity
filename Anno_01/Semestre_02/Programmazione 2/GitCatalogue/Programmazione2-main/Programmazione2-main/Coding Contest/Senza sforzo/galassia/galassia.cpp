#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int n = 0, pos = 0;
    long double max = 0;
    bool flag = false;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {

        fileInput >> n;

        string values[n]{""};
        long double num, max = 0.0;
        pos = 0;

        for (int i = 0; i < n; i++)
        {
            fileInput >> values[i];

            num = stold(values[i]);

            if (i == 0)
            {
                max = num;
                pos = i;
            }

            if (num > max)
            {
                max = num;
                pos = i;
            }
        }

        fileOutput << values[pos] << endl;
    }
}
