#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    int num = 0, min = -1;
    string str;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {

        fileInput >> str;

        if (str != "STOP")
        {
            num = stoi(str);

            if (min == -1)
            {
                min = num;
            }

            if (num < min)
            {
                min = num;
            }
        }
        else
        {
            fileOutput << min << '\n';
            min = -1;
        }
    }
}
