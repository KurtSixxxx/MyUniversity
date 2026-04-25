/*
Scrivere un programma che legga una frase, sostituisca tutte le sequenze di uno o due spazi con uno spazio singolo
e visualizzi la frase risultante.
*/
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string frase_iniziale = "Questa  frase  ha  due  spazi";
    string frase_finale = "";

    cout << "Frase iniziale: " << frase_iniziale << endl;

    for (int i = 0; i < frase_iniziale.length(); i++)
    {
        if (frase_iniziale[i] == ' ' && frase_iniziale[i + 1] == ' ' && i != frase_iniziale.length())
        {
            frase_finale += " ";
            i++;
        }
        else
        {
            frase_finale += frase_iniziale[i];
        }
    }

    cout << "Frase finale: " << frase_finale;
}