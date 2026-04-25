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

void selectionSortAlfabetico(string vec[], int dim)
{
    int indexMin;

    for (int c = 0; c < dim; c++)
    {
        indexMin = c;

        for (int i = c + 1; i < dim; i++)
        {
            char p1 = vec[i][0];
            char p2 = vec[indexMin][0];

            // cout << p1 << " " << p2;
            if (p1 > p2)
            {
                indexMin = i;
            }
        }

        swap(vec[c], vec[indexMin]);
    }
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
            if (p1 >= p2)
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
    int freq = 0;
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

                freq = alfabeto[i];

                str << freq << " ";

                check = str.str();

                controllo[cont++] = check;
            }
        }
        selectionSortAlfabetico(controllo, cont);
        selectionSort(controllo, cont);
        for (int i = 0; i < cont; i++)
        {
            cout << controllo[i];
        }

        for (int i = 0; i < cont; i++)
        {
            fileOutput << controllo[i];
        }

        fileOutput << endl;
        cout << endl;
    }
}
