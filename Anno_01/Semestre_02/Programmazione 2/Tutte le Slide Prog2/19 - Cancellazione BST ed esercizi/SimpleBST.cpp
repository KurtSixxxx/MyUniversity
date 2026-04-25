


#include <iostream>

using namespace std;

class Nodo{
    public:
    int val;
    Nodo* left;
    Nodo* right;
    Nodo* parent;
};


class BST{
public:
    BST(): root(nullptr){};
    void insert(int);
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    int getH(Nodo*) const;

    friend
    ostream& operator<<(ostream&, const BST&);
private:
    Nodo* root;
    int num_elem = 0; // facoltativo...
    void inOrder(Nodo* p) const;

};

void stampaLivello(Nodo* p ,int level){
    if(p ==nullptr){
        cout << "_\t";
        return;
        }

    if(level==0)
        cout << p->val << "\t";
    else if (level >0){
        stampaLivello(p->left, level-1);
        stampaLivello(p->right, level-1);
    }
}
int BST::getH(Nodo* p)const{
    if (p == nullptr)
        return 0;
    else{
        int lh = getH(p->left);
        int rh = getH(p->right);

        if(lh >rh)
            return (lh+1);
        else
            return (rh+1);
    }
}
ostream& operator<<(ostream& out, const BST& t){
    int h = t.getH(t.root);
    for(int i=0; i<h; i++){
        stampaLivello(t.root, i);
        cout << endl;
    }
}


void BST::inOrder() const { inOrder(root);}
void BST::inOrder(Nodo* p)const {
   if (p){
      inOrder(p->left);   // visita il sottoalbero sinistro
      cout << p->val << "\t";   // visita la radice
      inOrder(p->right);     // visita il sottoalbero destro
   }
}

void BST::insert(int _val){
    // Fase 1: inizializzazione
    Nodo* nuovo = new Nodo;
    Nodo* x = root;
    Nodo* y = nullptr;
    nuovo->val = _val;
    nuovo->left = nuovo->right = nullptr;
    // Fase 2: ricerca della posizione per il nuovo nodo
    while(x!=nullptr){
        y = x;
        if(_val < x->val)
            x = x->left;
        else
            x = x->right;
    }
    // Fase 3: inserisco il nuovo nodo come figlio di y
    nuovo->parent = y;
    if(y ==nullptr)
        root = nuovo;
    else if(_val < y->val)
        y->left = nuovo;
    else
        y->right = nuovo;

    num_elem++;

}


int main(){

    BST t;
    t.insert(6);
    t.insert(5);
    t.insert(7);
    t.insert(2);
    t.insert(4);
    t.insert(8);
    t.insert(3);

    t.inOrder();

    cout << endl << "Stampa BST:" << endl;
    cout << t;
    return 0;
}


