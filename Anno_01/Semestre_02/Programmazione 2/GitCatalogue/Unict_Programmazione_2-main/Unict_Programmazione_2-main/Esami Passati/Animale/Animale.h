#ifndef ANIMALE_H
#define ANIMALE_H

#include <iostream>
#include <string>

class Animale
{
public:
    Animale() : nome(""), razza(""), eta(0) {}
    Animale(std::string n, std::string r, int e) : nome(n), razza(r), eta(e) {}

    // get degli attributi
    std::string getNome() const {return nome;}
    std::string getRazza() const {return razza;}
    int getEta() const {return eta;}

    // set degli attributi
    void setNome(std::string n) {nome = n;}
    void setRazza(std::string r) {razza = r;}
    void setEta(int e) {eta = e;}

    virtual std::string verso() const { return "";}

    virtual void stampa(std::ostream& os) const
    {   
        os << "Nome: " << getNome() << " Razza: " << getRazza() << " Eta': " << getEta();
    };
    
    
    virtual ~Animale() {}


private:
    std::string nome, razza;
    int eta;
};

std::ostream& operator << (std::ostream& os, const Animale& a)
{
    a.stampa(os);
    return os;
}

class Cane : public Animale
{
public:
    Cane() : Animale("","",0) {}
    Cane(std::string n, std::string  r, int e) : Animale(n,r,e) {}
    
    std::string verso() const override  {return " Bau ";}

private:

};

class Gatto : public Animale
{
public:
    Gatto() : Animale("","",0) {}
    Gatto(std::string n, std::string  r, int e) : Animale(n,r,e) {}
    
    std::string verso() const override  {return " Miao ";}


private:

};

#endif