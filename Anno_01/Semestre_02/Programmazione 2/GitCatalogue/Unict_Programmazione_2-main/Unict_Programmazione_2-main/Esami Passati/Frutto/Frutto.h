#ifndef FRUTTO_H
#define FRUTTO_H

#include <iostream>
using namespace std;

class Frutto
{
public:
    Frutto() : nome(""), colore(""), stagione("") {}
    Frutto(string n, string c, string s) : nome(n), colore(c), stagione(s) {}
    Frutto(const Frutto& f) : nome(f.nome), colore(f.colore), stagione(f.stagione) {}

    string getNome() const {return nome;}
    string getColore() const {return colore;}
    string getStagione() const {return stagione;}

  

    virtual void stampa(ostream& os) const
    {
        os << getNome() << " - " << getColore() << " - " << getStagione();
    }

    virtual string get_sapore() const = 0;   //senza ""= 0" non è un metodo virtuale puro
   
    virtual string getTipo() const = 0;

private:
    string nome , colore, stagione;
};

ostream& operator << (ostream& os, const Frutto& f)
{
    f.stampa(os);
    return os;
} 

class Mela : public Frutto
{
public:
    Mela() : Frutto("","",""), sapore("") {}
    Mela(string n, string c, string s, string sap) : Frutto(n,c,s), sapore(sap) {}
    Mela(const Mela& m) : Frutto(m), sapore(m.sapore) {}
    
   string get_sapore() const override
   {
        return sapore;
   }

   
    string getTipo() const override
    {
        return "Mela";
    }

   void stampa(ostream& os) const override
    {
       Frutto::stampa(os);
       os << " - " << get_sapore() << endl;;
    }


private:
    string sapore;
};

class Arancia : public Frutto
{
public:
    Arancia() : Frutto("","",""), sapore("") {}
    Arancia(string n, string c, string s, string sap) : Frutto(n,c,s), sapore(sap) {}
    Arancia(const Arancia& a) : Frutto(a), sapore(a.sapore) {}
    
   string get_sapore() const override
   {
        return sapore;
   }

   
    string getTipo() const override
    {
        return "Arancia";
    }



   void stampa(ostream& os) const override
    {
       Frutto::stampa(os);
       os << " - " << get_sapore() << endl;;
    }

private:
    string sapore;
};




#endif