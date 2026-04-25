#ifndef STUDENTE_H
#define STUDENTE_H

#include <iostream>
using namespace std;

class Studente
{
public:
    Studente() : matricola(0), nome(""), cognome(""), media(0) {}
    Studente(int ma, string n, string c, double med) : matricola(ma), nome(n), cognome(c), media(med) {}
    Studente(const Studente &s) : matricola(s.matricola), nome(s.nome), cognome(s.cognome), media(s.media) {}

    virtual ~Studente() {}

    int getMatricola() const {return matricola;}
    string getNome() const {return nome;}
    string getCognome() const {return cognome;}
    double getMedia() const {return media;}

    virtual int getImportoBorsa() const {return 0;}

    virtual void stampa(ostream& os) const
    {
        os << getMatricola() << ": " << getNome() << " " << getCognome() << " - " << getMedia();
    } 


private:
    int matricola;
    string nome, cognome;
    double media;
};


class BorsaDiStudio
{
public:
    BorsaDiStudio() : importo(0), durata(0) {}
    BorsaDiStudio(int imp, int du) : importo(imp), durata(du) {}
    BorsaDiStudio(const BorsaDiStudio& b) : importo(b.importo), durata(b.durata) {}

    int getImporto() const {return importo;}

private:
    int importo;
    int durata;
};

class  StudenteBorsista : public Studente
{
public:
    StudenteBorsista(int ma, string n, string c, double med, BorsaDiStudio* b) : Studente(ma,n,c,med) , borsa(b) {}
    ~StudenteBorsista()
    {
        delete borsa;
    }


    int getImportoBorsa() const override {return borsa->getImporto();}

    void stampa(ostream& os) const override
    {
        Studente::stampa(os);
        os << " [borsa di " << getImportoBorsa() << " euro]";
    }

private:
    BorsaDiStudio* borsa;
};

#endif