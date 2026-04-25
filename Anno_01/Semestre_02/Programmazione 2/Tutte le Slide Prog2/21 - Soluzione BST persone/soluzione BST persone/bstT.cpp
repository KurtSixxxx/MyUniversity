/*
    Questa classe implementa un BST per tipi generici
*/
#include<iostream>
#include <fstream>
#include <string>
#include <time.h>       




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

//  ******************* Inizio implementazione del compito **********************

// Gerarchia delle classi
class Persona{

public:
    int eta; string nome, cognome;
    int tipo;
    Persona(){}
    Persona(string nome, string cognome){
        this->nome = nome;
        this->cognome = cognome;
	this->eta = rand() % 101; // random within 0-100
    }
    Persona(string nome, string cognome, int eta){
        this->nome = nome;
        this->cognome = cognome;
        this->eta = eta;
    }
    


    bool operator<(const Persona& p2){return eta<p2.eta;}

    friend
    ostream& operator<<(ostream& out,const Persona& p) {
        out << p.nome << " " << p.cognome << " (" << p.eta << ")";
        return out;
    }


};

class Studente: public Persona{
private:
    static const int minEta = 5;
    static const int maxEta = 30;

public:
	Studente(string n, string c) {
		this->nome = n;
		this->cognome = c;
 		this->eta = rand() % (maxEta - minEta + 1) + minEta;
		tipo = 1;
	}

};

class Pensionato: public Persona{
private:
    static const int minEta = 65;
	static const int maxEta = 95;

public:
	Pensionato(string n, string c) {
		this->nome = n;
		this->cognome = c;
		this->eta = rand() % (maxEta - minEta + 1) + minEta;
		     tipo = 3;

	}

};


class Lavoratore: public Persona{
private:
    static const int minEta = 20;
	static const int maxEta = 70;


public:

	Lavoratore(string n, string c){
		this->nome = n;
		this->cognome = c;
		
		this->eta = rand() % (maxEta - minEta + 1) + minEta;
		    tipo = 2;
	}

};

/* SOLUZIONE: variabili globali per mantenere le somme ed i conteggi*/
int sS = 0; int sL = 0; int sP = 0;
int cS = 0; int cL = 0; int cP = 0;

// funzione ricorsiva ausiliaria
void medieAux(Nodo<Persona>* p){
    if (p!=nullptr) {
        medieAux(p->left);
        medieAux(p->right);
        if(p->val.tipo == 1){
            sS+=p->val.eta;
            cS++;
            }
        if(p->val.tipo == 2){
            sL+=p->val.eta;
            cL++;
            }
        if(p->val.tipo == 3){
            sP+=p->val.eta;
            cP++;
            }
    }
}
// funzione da chiamare nel main 
void medieEtaPersone(BST<Persona> t){
    cout << endl << "Calcolo delle medie per categoria:" << endl;
    medieAux(t.getRadice());
    cout << endl << "\t\tStud\tLav\tPens" << endl;
  //  cout << "somme:\t" << sS << "\t" << sL << "\t" << sP << endl;
    cout << "Eta' medie:\t" << (double)sS/cS << "\t" << (double)sL/cL << "\t" << (double)sP/cP << endl;

}



int main(){

    BST<Persona> tree;
    tree.inserisci(*(new Lavoratore("Luigi","L")));
    tree.inserisci(*(new Lavoratore("Ludovico","L")));
    tree.inserisci(*(new Studente("Salvo","S")));
    tree.inserisci(*(new Studente("Silvio","S")));
    tree.inserisci(*(new Pensionato("Pippo","P")));
    tree.inserisci(*(new Pensionato("Paolo","P")));

    cout << tree;
    medieEtaPersone(tree);
    return 0;
}