
/*
TODO:
- completare la classe implementando i metodi dichiarati
- aggiungere un metodo inserisci(T val_prec, T val) che inserisce
  un nuovo nodo con valore 'val' e lo posiziona come precedente
  del nodo in 'prec', verificando prima che tale nodo esista.
*/

#include <iostream>
using namespace std;

template <typename T>
class Nodo{
public:
    T valore;
    Nodo<T>* succ;
    Nodo<T>* prec;
};


template <typename T>
class ListaDoppiaT{
    Nodo<T>* testa;
public:
    ListaDoppiaT() {testa=nullptr;}
    ~ListaDoppiaT();
    Nodo<T>* getTesta() const {return this->testa;}
    void inserisci(T val);
    Nodo<T>* ricerca(T val) const;
    void rimuovi (T val);

    template <typename U>
    friend
    ostream& operator<<(ostream& out, const ListaDoppiaT<U>& ls);
};

template <typename T>
ListaDoppiaT<T>::~ListaDoppiaT(){
    Nodo<T>*iter = this->testa;
    while(iter!=nullptr){
        Nodo<T>* tmp = iter->succ;
        delete iter;
        iter = tmp;
    }
}

template <typename U>
ostream& operator<<(ostream& out, const ListaDoppiaT<U>& ls){
        Nodo<U>* iter;
        for(iter = ls.testa;iter!=nullptr;iter = iter->succ){
            out << "Valore:\t" << iter->valore << endl;
            out << "\t--> ";
            if(iter->succ!=nullptr)
                out << iter->succ->valore;
            else
                out << "null";
            out << endl;
            // stampo il precedente
            out << "\t <--";
            if(iter->prec!=nullptr)
                out << iter->prec->valore;
            else
                out << "null";
            out << endl << endl;
        }
        return out;
}

template <typename T>
Nodo<T>* ListaDoppiaT<T>::ricerca(T val) const{
    Nodo<T>* p;
    for(p=this->testa; p!=nullptr; p=p->succ)
        if(p->valore == val)
            return p;
    return nullptr;
}
template <typename T>
void ListaDoppiaT<T>::inserisci(T val){
    Nodo<T>* nuovo = new Nodo<T>;
    nuovo->valore = val;
    if(this->testa!=nullptr){
        this->testa->prec = nuovo;
        nuovo->succ = this->testa;
        nuovo->prec = nullptr;
        this->testa = nuovo;
    }
    else{
        nuovo->succ = nullptr;
        this->testa = nuovo;
        nuovo->prec = nullptr;
    }
}


int main(){

    ListaDoppiaT<int> lista;
    for(int i=0;i<10;i++){
        if(i%2==0)
            lista.inserisci(i+1);
        else
            lista.inserisci(i-1);
    }

    cout << lista;
    return 0;
}


