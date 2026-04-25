#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;
class Studente
{
public:
    Studente(int mat, string n, string c, double med) : matricola(mat), nome(n), cognome(c), media(med) {}

    int getMatricola() const {return matricola;}
    string getNome() const {return nome;}
    string getCognome() const {return cognome;}
    double getMedia() const {return media;}

    virtual int get_importo_borsa() const {return 0;}

    virtual void stampa(ostream& os) const
    {
        os << getMatricola() << ": " << getNome() << " " << getCognome() <<" - media " << getMedia() << endl;
    }

private:
    int matricola;
    string nome, cognome;
    double media;
};

class BorsaDiStudio
{
public: 
    BorsaDiStudio(int im, int dur) : importo(im), durata(dur) {}

    int getImporto() const { return importo; }
    int getDurata() const { return durata; }

    void setImporto(int imp) { importo = imp; }
    void setDurata(int dur) { durata = dur; }


private:
    int importo;
    int durata;
};

class StudenteBorsista : public Studente
{
public:
    StudenteBorsista (int mat, string n, string c, double med, BorsaDiStudio* b = nullptr) : Studente(mat,n,c,med) , borsa(b) {}
    ~StudenteBorsista() {delete borsa;}

    int get_importo_borsa() const {return borsa->getImporto();}

    void stampa (ostream& os) const override
    {
        os << getMatricola() << ": " << getNome() << " " << getCognome() <<" - media " << getMedia() << "[ borsa di " << get_importo_borsa() << " euro ]" << endl;
    }

private:
    BorsaDiStudio* borsa;
};

ostream& operator << (ostream& os, const Studente* s)
{
    s->stampa(os);
    return os;
}

#endif