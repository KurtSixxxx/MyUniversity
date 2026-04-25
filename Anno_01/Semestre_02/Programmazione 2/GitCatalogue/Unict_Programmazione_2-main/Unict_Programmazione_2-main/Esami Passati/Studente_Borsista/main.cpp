#include <iostream>
#include <fstream>
#include "student.h"
#include "pila.h"

using namespace std;

int main()
{
    fstream filename("input.txt",ios::in);

    if(!filename)
    {
        cerr << "File non trovato! " << endl;
        return -1;
    }

    Pila <Studente*> p1;
    int matricola; 
    string nome, cognome;
    double media;
    int importo, durata;

    Studente* s;
    BorsaDiStudio* b;

    while(filename >> matricola >> nome >> cognome >> media >> importo >> durata)
    {
        if(durata == 0)
            s = new Studente(matricola,nome,cognome,media);
        else
        {
            b = new BorsaDiStudio(importo,durata);
            s = new StudenteBorsista(matricola, nome, cognome, media, b);
        }
        p1.push(s);
    }

    Pila <Studente*> p2;

    int importo_tot = 0;

    while(!p1.isEmpty())
    {
        s = p1.pop();
        if(s->getMedia() < 25)
        {
            cout << "Studente insufficiente rimosso: " << s->getNome() << " " << s->getCognome() << " - Matricola: " << s->getMatricola() << endl;
            delete s;
        }
        else
        {
            p2.push(s);
            importo_tot = importo_tot + s->get_importo_borsa();
        }
    }
    
    cout <<endl;
    cout << "La pila contiene i seguenti studenti: "<< endl;

    cout << p2;
    cout << endl << "Totale importi borse di studio: " << importo_tot << endl;


}