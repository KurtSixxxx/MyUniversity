/*
Scrivere una funzione di conversione che riceva come parametro una stringa rappresentante una data in formato gg/mm/aa
e la restituisca nel formato testuale, es:17/11/91-->17 novembre 1991
*/

#include <iostream>
#include <cstring>
using namespace std;

string converti(string input)
{
    int mese = 0, anno = 0;
    string giornos = "", meses = "", annos = "";
    int i = 0;

    while (input[i] != '/')
    {
        giornos += input[i];
        i++;
    }

    i++;

    while (input[i] != '/')
    {
        meses += input[i];
        i++;
    }

    mese = stoi(meses);
    meses = "";

    switch (mese)
    {
    case 1:
    {
        meses = " gennaio ";
        break;
    }
    case 2:
    {
        meses = " febbraio ";
        break;
    }
    case 3:
    {
        meses = " marzo ";
        break;
    }
    case 4:
    {
        meses = " aprile ";
        break;
    }
    case 5:
    {
        meses = " maggio ";
        break;
    }
    case 6:
    {
        meses = " giugno ";
        break;
    }
    case 7:
    {
        meses = " luglio ";
        break;
    }
    case 8:
    {
        meses = " agosto ";
        break;
    }
    case 9:
    {
        meses = " settembre ";
        break;
    }
    case 10:
    {
        meses = " ottobre ";
        break;
    }
    case 11:
    {
        meses = " novembre ";
        break;
    }
    case 12:
    {
        meses = " dicembre ";
        break;
    }
    default:
    {
        meses = " errore ";
        break;
    }
    }

    i++;

    while (i < input.length())
    {
        annos += input[i];
        i++;
    }

    anno = stoi(annos);
    annos = "";

    if (anno > 22)
    {
        annos += "19";
        annos += anno;
    }
    else
    {
        annos += "20";
        annos += anno;
    }

    string finale = giornos + meses + annos;
    return finale;
}

int main()
{
    string data = "17/11/91";

    cout << "Convertitore di data: " << converti(data);
}