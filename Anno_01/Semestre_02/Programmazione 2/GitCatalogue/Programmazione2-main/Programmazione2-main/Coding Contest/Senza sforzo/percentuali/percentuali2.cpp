#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

void swap(string &a, string &b)
{
    string temp = a;
    a = b;
    b = temp;
}

void selectionSort(string vec[], int dim)
{
    int indexMin;

    for (int c = 0; c < dim; c++)
    {
        indexMin = c;

        for (int i = c + 1; i < dim; i++)
        {
            double p1 = stod(vec[i].substr(2, vec[i].length() - 1));
            double p2 = stod(vec[indexMin].substr(2, vec[indexMin].length() - 1));

            // cout << p1 << " " << p2;
            if (p1 < p2)
            {
                indexMin = i;
            }
        }

        swap(vec[c], vec[indexMin]);
    }
}

int main()
{
    fstream fileInput("input.txt", fstream::in);
    fstream fileOutput("output.txt", fstream::out);

    string nome, check = "";
    stringstream str;
    double perc = 0.0;
    char c = '\0';
    int cont = 0;

    if (!fileInput.is_open())
    {
        cout << "File di input non trovato!";
    }

    while (fileInput.good())
    {
        getline(fileInput, nome);

        int alfabeto[25]{0};
        string controllo[25]{""};

        cont = 0;
        double totale = 0;

        for (int i = 0; i < nome.length(); i++)
        {
            if (nome[i] != ' ')
            {
                alfabeto[nome[i] - 97]++;
                totale++;
            }
        }

        // selectionSort(alfabeto, 25);

        /*for (int i = 0; i < 25; i++)
        {
            if (alfabeto[i] != 0)
            {
                c = i + 97;
                fileOutput << c << ':';
                perc = (double)(alfabeto[i] / totale) * 100.0;

                fileOutput << fixed << setprecision(2) << perc << " ";
            }
        }*/

        for (int i = 0; i < 25; i++)
        {
            str.str("");
            check = "";

            if (alfabeto[i] != 0)
            {
                c = i + 97;
                str << c << ":";

                perc = (double)(alfabeto[i] / totale) * 100.0;
                str << fixed << setprecision(2) << perc << " ";

                check = str.str();

                if (check[check.length() - 2] == '0')
                {
                    check = check.substr(0, check.length() - 2) + " ";
                }

                controllo[cont++] = check;
            }
        }

        /*for (int i = 0; i < cont; i++)
        {
            cout << controllo[i];
        }*/

        selectionSort(controllo, cont);

        for (int i = 0; i < cont; i++)
        {
            fileOutput << controllo[i];
        }

        fileOutput << endl;
    }
}
