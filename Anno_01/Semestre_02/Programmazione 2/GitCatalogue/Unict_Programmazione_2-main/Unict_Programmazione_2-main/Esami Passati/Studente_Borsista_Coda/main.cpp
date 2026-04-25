#include <iostream>
#include <fstream>
#include <sstream>
#include "Studente.h"
#include "Coda.h"

using namespace std;

int main()
{
    fstream file("input.txt",ios::in);

    if(!file.is_open())
    {
        throw runtime_error("File inesistente!");
    }

    Studente *s;
    BorsaDiStudio *b;

    Queue <Studente*> c1;

    string line;
    string str;

    int matricola;
    string nome, cognome;
    double media;

    int importo;
    int durata;

    while(file>> line)
    {
        stringstream ss(line);

        getline(ss,str,',');
        matricola = stoi(str);

        getline(ss,nome,',');
        getline(ss,cognome,',');

        getline(ss,str,',');
        media = stof(str);

        getline(ss,str,',');
        importo = stoi(str);

        getline(ss,str,',');
        durata = stoi(str);

        if(durata == 0)
        {
            s = new Studente(matricola,nome,cognome,media);
        }
        else
        {
            b = new BorsaDiStudio(importo,durata);
            s = new StudenteBorsista(matricola,nome,cognome,media,b);
        }

        c1.enqueue(s);
    }

    Studente* x = c1.dequeue();
    Studente* x2 = c1.dequeue();
   
    c1.enqueue(x);
    c1.enqueue(x2);

    Queue <Studente*> c2;

    int importo_tot = 0;

    while(!c1.isEmpty())
    {
        s = c1.dequeue();

        if(s->getMedia() < 25)
        {
            cout << "Studente insufficiente rimosso: " << s->getNome() << " " << s->getCognome() << " - Matricola: " << s->getMatricola() << endl;
            delete s;
        }
        else
        {
            c2.enqueue(s);
            importo_tot += s->getImportoBorsa();
        }
    }

    cout << endl;
    cout << c2 ;
    cout <<"\nImporto totale delle borse di studio: " << importo_tot;

    return 0;
}