#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>
using namespace std;

class Veicolo
{
public: 
    Veicolo(int t, string n_m, string m, int a) : targa(t), nome_modello(n_m), marca(m), anno(a) {}
    virtual ~Veicolo(){}

    
    int getTarga() const {return targa;}
    string getNome_modello() const {return nome_modello;}
    int getAnno() const {return anno;}
    string getMarca() const {return marca;}

    virtual void print(ostream& os) const = 0;


private:
    int targa;
    string nome_modello;
    int anno;
    string marca;

};

ostream& operator<< (ostream& os, const Veicolo& v)
{
    v.print(os);
    return os;
}


class Auto : public Veicolo
{
public:
    Auto(int t, string n_m, string m ,int a, int c, int nu_porte) : Veicolo(t,n_m,m,a) , cilindrata(c), numero_porte(nu_porte) {}

    int getNumero_porte() const {return numero_porte;}
    int getCilindrata() const {return cilindrata;}


    void print(ostream& os) const override 
    {
        os << "Auto:\n" << "Targa: " << getTarga() <<  "   Nome modello: " << getNome_modello() <<"\nMarca: " << getMarca() <<"   Anno fabbricazione: " << getAnno() << "\nCilindrata: " << getCilindrata() << "   Numero porte: " <<getNumero_porte() << endl;
    }



private:
    int numero_porte;
    int cilindrata;
};


class Moto : public Veicolo
{
public:
    Moto(int t, string n_m, string m, int a, int c, string t_m) : Veicolo(t,n_m,m,a) , cilindrata(c), tipo_moto(t_m) {}


    int getCilindrata() const {return cilindrata;}
    string getTipo_moto() const {return tipo_moto;}


    void print(ostream& os) const override 
    {
        os << "Moto:\n" << "Targa: " << getTarga() <<  "   Nome modello: " << getNome_modello() <<"\nMarca: " << getMarca() <<"   Anno fabbricazione: " << getAnno() << "\nCilindrata: " << getCilindrata() << "   Tipo moto: " << getTipo_moto() << endl;
    }



private:
    int cilindrata;
    string tipo_moto;
};

#endif