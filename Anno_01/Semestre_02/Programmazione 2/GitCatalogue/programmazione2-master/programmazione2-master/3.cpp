#include <iostream>
using namespace std;


/*
tipo_di_ritorno nome_funzione(parametri){
    ..istruzioni..
}

Facciamo overloding delle funzioni nel casi in cui dichiariamo funzioni con lo stesso nome e tipo di ritorno ma parametri differenti.
Ciò che identifica una funzione è il nome e il tipo e il numero di parametri che prende. Nome e tipo o numero di parametri prende il nome di firma della funzione.

(Questo discorso è valido anche per le classi, nel nostro caso la funzione parla ha due dichiarazioni ma con due firme differenti e quindi il codice compila e non da errori )
*/

class Persona{
    public:
        Persona(){
            this->nome = "";
            this->eta = 0;
        }
        Persona(string _nome, int _eta){
            this->nome = _nome;
            this->eta = _eta;
        }
        void parla(){
            cout << "La Persona parla" << endl;
        }
        void parla(string s){ //*Overloading della funzione parla()
            cout << "La Persona parla e dice '" << s << "'" << endl;
        }
        void print(){
            cout << "Nome: " << nome << ", Eta: " << eta << endl;
        }

    protected:
        string nome;
        int eta;
};

class Oratore : public Persona{
    public:
        Oratore() : Persona(){}
        Oratore(string _nome, int _eta) : Persona(_nome, _eta){}
        void parla(){
            Persona::parla(); //Richiamo un membro della classe Persona da Oratore
            cout << "Io sono l'oratore " << nome << " di eta " << eta << endl;
        }
};

int main(){
    Persona p = Persona("Patrick", 21);
    p.parla();
    p.parla("ciao mondo");
    p.print();

    Oratore p2 = Oratore("Enzo", 40);
    p2.parla();
}

/*
 Implementare una classe persona (UML DIAGRAM)

 Persona:
 +print(): void
 +parla(): void
 +parla(string s): void

 *nome
 *eta

 Estendere la classe Persona con la classe Oratore
 

 Oratore:
 +parla(): void //Quale dei due? Quello senza parametri

 *


*/