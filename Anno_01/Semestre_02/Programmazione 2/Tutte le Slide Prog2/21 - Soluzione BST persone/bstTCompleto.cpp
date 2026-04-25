/*
    Questa classe implementa un BST per tipi generici
*/
#include<iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

template <typename T>
class Nodo{
    public:
    Nodo(){}
	T val;
	Nodo<T>* left;
	Nodo<T>* right;
	Nodo<T>* padre;
};


template <typename T>
class BST{
public:
	BST() : radice(nullptr) {};
	void inserisci(T valore);

	void inOrder()const;
	void preOrder()const;
	void postOrder()const;
	int altezza(Nodo<T>* p)const;
	int altezza()const { return altezza(radice);}
    Nodo<T>* ricercaRicorsiva(T valore);
    Nodo<T>* getRadice(){return radice;}

    friend
	ostream& operator<<(ostream& out, const BST<T>& t){
        int h = t.altezza(t.radice);
        cout << "Albero di oggetti Persona:" << endl;
        for (int i=0; i<h; i++) {
            stampaLivello(t.radice, i);
            cout << endl;
        }
        return out;
	}


private:
	Nodo<T>* radice;

	int num_elem = 0;
	void inOrder(Nodo<T>* p)const;
	void preOrder(Nodo<T>* p)const;
	void postOrder(Nodo<T>* p)const;
    Nodo<T>* ricercaRicorsiva(Nodo<T>* x, T valore);
};

/* stampa i nodi ad un dato livello */
template <typename T>
void stampaLivello(Nodo<T>* p, int level)
{

    // Il nodo non contiene una chiave
    if (p == nullptr){
        cout << "_\t";
        return;
        }

    if (level == 0)
        cout << p->val << "\t";
    else if (level > 0){
        stampaLivello(p->left, level-1);
        stampaLivello(p->right, level-1);
    }
}

template <typename T>
void BST<T>::inserisci(T valore) {
	Nodo<T>* nuovo= new Nodo<T>;
	Nodo<T>* x=radice, *y=nullptr;

	nuovo->val=valore;
	nuovo->left=nuovo->right=nullptr;

	// cerco una foglia disponibile dove inserirlo
	while(x!=nullptr) {
		y=x; // y tiene traccia del padre di x
		if (valore < x->val)
            x=x->left;
		else
            x=x->right;
    }
	nuovo->padre=y;
	if (y==nullptr)
        radice=nuovo;
	//In tal caso l'albero è vuoto
	else if (valore < y->val)
        y->left=nuovo;
	else
        y->right=nuovo;

    num_elem++;
}

template <typename T>
void BST<T>::inOrder(Nodo<T>* p)	const{
	if (p!=nullptr) {
		inOrder(p->left);
		cout << p->val << "\t";
		inOrder(p->right);
		}
}
// versione pubblica
template <typename T>
void BST<T>::inOrder()	const{inOrder(radice);}

template <typename T>
void BST<T>::preOrder(Nodo<T>* p)	const{
	if (p!=nullptr) {
		cout << p->val << "\t";
		preOrder(p->left);
		preOrder(p->right);
		}
}
template <typename T>
void BST<T>::preOrder()	const{preOrder(radice);}

template <typename T>
void BST<T>::postOrder(Nodo<T>* p)	const{
	if (p!=nullptr) {
		postOrder(p->left);
		postOrder(p->right);
		cout << p->val << "\t";
		}
}
template <typename T>
void BST<T>::postOrder() const{ postOrder(radice);}

template <typename T>
int BST<T>::altezza(Nodo<T>* p)const{
    if (p == nullptr)
        return 0;
    else
    {
        int lheight = altezza(p->left);
        int rheight = altezza(p->right);

        if (lheight > rheight)
            return(lheight + 1);
        else
          return(rheight + 1);
    }
}


template <typename T>
Nodo<T>* BST<T>::ricercaRicorsiva(T valore) {
    return ricercaRicorsiva(radice,valore);
}
template <typename T>
Nodo<T>* BST<T>::ricercaRicorsiva(Nodo<T>* x, T valore) {
    if(x==nullptr || x->val==valore)
        return x;

    cout << endl << "-->" << x->val;
    if(valore < x->val)
        return ricercaRicorsiva(x->left, valore);
    else
        return ricercaRicorsiva(x->right, valore);
}

// ******************* Inizio implementazione esercizio ********************************

enum Status {PERSONA, STUDENTE, LAVORATORE, PENSIONATO};

class Persona{
	
	protected: 
		int minEta = 0;
		int maxEta = 100;
		const Status stato;
		Persona(Status _tipo, int _min=0, int _max=100): stato(_tipo), minEta(_min), maxEta(_max){ 
			if(this->minEta ==0 && this->stato != PERSONA)
				throw invalid_argument("Persona deve essere di tipo PERSONA");
			}
	public:
		int eta; string nome; string cognome;
		Persona():Persona(PERSONA){}
		Persona(string _n, string _c):Persona(){
			this->nome = _n;
			this->cognome = _c;
			this->eta = rand() % 101;
		}
		Persona(string _n, string _c, int _e): Persona(_n,_c){ this->eta = _e;}
		
		bool operator<(const Persona& p) {return eta<p.eta;}
		
		Persona& operator=(const Persona& p) {
			this->nome = p.nome;
			this->cognome = p.cognome;
			this->eta = p.eta;
			return *this;
			}
		
		
		friend
		ostream& operator<<(ostream& out, const Persona& p){
			out << p.nome << " " << p.cognome << " (" << p.eta << ")";
			return out;
		}
	
	};


class Studente: public Persona{

public: 
	Studente(string _n, string _c): Persona(STUDENTE,5,30){
		this->nome = _n;
		this->cognome = _c;
		this->eta = rand() % (maxEta - minEta +1) + minEta;
	}
};


class Pensionato: public Persona{


public: 
	Pensionato(string _n, string _c): Persona(PENSIONATO,65,96){
		this->nome = _n;
		this->cognome = _c;
		this->eta = rand() % (maxEta - minEta +1) + minEta;
	}
};

class Lavoratore: public Persona{


public: 
	Lavoratore(string _n, string _c): Persona(LAVORATORE,20,70){
		this->nome = _n;
		this->cognome = _c;
		this->eta = rand() % (maxEta - minEta +1) + minEta;
	}
};


int main(){
	BST<Persona> tree;
	//Persona pp;
	
	tree.inserisci(*(new Lavoratore("Luigi", "L.")));
	tree.inserisci(*(new Lavoratore("Ludovico", "C.")));
	tree.inserisci(*(new Studente("Silvio", "C.")));
	tree.inserisci(*(new Studente("Pippo", "C.")));
	tree.inserisci(*(new Lavoratore("Paolo", "C.")));
	tree.inserisci(*(new Lavoratore("Carlo", "C.")));
	
	cout << tree;
	
	return 0;
}






