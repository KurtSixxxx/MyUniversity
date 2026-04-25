#include <iostream>
using namespace std;
// DEV BRENCH


class EssereVivente{
    private:
        string nome;

    public:
        int eta;
        EssereVivente(int _eta, string _nome, string _regno, string _specie){
            this->eta = _eta; //Puntatore all'istanza corrente dell'oggetto
            this->nome = _nome;
            this->regno = _regno;
            this->specie = _specie;
        }
        void print(){
            cout << "Sono un'istanza della classe EssereVivente" << " --> \t";
            cout << nome << ", " << regno << ", " << specie << ", " << eta << " anni" << endl;  
        }
        string getNome(){
            return nome;
        }

    protected:
        string specie;
        string regno;
};

class Animale : protected EssereVivente{
    public:
        Animale(int _eta, string _nome, string _specie) : EssereVivente(_eta, _nome, "Animale", _specie){}
        /*void print(){
            cout << "Sono un'istanza della classe Animale" << " --> \t";
            cout << getNome() << ", " << regno << ", " << specie << ", " << eta << " anni" << endl;  
        }*/
};

class Mammifero : private Animale{
    public:
        Mammifero(int _eta, string _nome) : Animale(_eta, _nome, "Mammifero"){}
        void print(){
            cout << "Sono un'istanza della classe Mammifero" << " --> \t";
            cout << getNome() << ", " << regno << ", " << specie << ", " << eta << " anni" << endl;  
        }
};

int main(){
    EssereVivente e = EssereVivente(12, "Patrick", "Animale", "Homo Sapiens");
    e.print();
    
    Animale a = Animale(3, "Fuffi", "Canidi");
    //a.print();

    Mammifero m = Mammifero(21, "Ofelia");
    m.print();

    return 0;
}
