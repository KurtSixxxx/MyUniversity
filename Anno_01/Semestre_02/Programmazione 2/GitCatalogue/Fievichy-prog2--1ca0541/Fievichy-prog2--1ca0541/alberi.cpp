#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Nodo{
    public:
    T valore;
    Nodo<T>* sinistro;
    Nodo<T>* destro;

    Nodo(T valore) : valore(valore), sinistro(nullptr), destro(nullptr) {}
};

template <typename T>
class Albero{
    public:
    Nodo<T>* root;

    Albero() : root(nullptr) {}

    //vista DFS radice->sinistro->destro
    void preorder(Nodo<T>* nodo) {
        if(nodo == nullptr) return;

        cout << nodo->valore << " ";
        preorder(nodo->sinistro);
        preorder(nodo->destro);
    }

    //vista DFS sinistro->radice->destro
    void inorder(Nodo<T>* nodo) {
        if(nodo == nullptr) return;

        inorder(nodo->sinistro),
        cout << nodo->valore << " ";
        inorder(nodo->destro);
    }

    //vista DFS sinistro->destro->radice
    void postorder(Nodo<T>* nodo) {
        if(nodo == nullptr) return;

        postorder(nodo->sinistro);
        postorder(nodo->destro);
        cout << nodo->valore << " ";
    }

    //inserimento BFS
    Nodo<T>* inserisci(Nodo<T>* nodo, T valore){
        if(nodo == nullptr) {
            return new Nodo<T> (valore);
        }
        
        if(valore < nodo->valore) {
            nodo->sinistro = inserisci(nodo->sinistro, valore);
        } else if (valore > nodo->valore) {
            nodo->destro = inserisci(nodo->destro, valore);
        }
        
        return nodo;
    }

    void inserisci(T valore) {
        root = inserisci(root, valore);
    }

    //ricerca BFS
    Nodo<T>* ricerca(Nodo<T>* nodo, T valore) {
        if(nodo == nullptr || nodo->valore == valore) {
            return nodo;
        }
        
        if(valore < nodo->valore) {
            return ricerca(nodo->sinistro, valore);
        } else {
            return ricerca(nodo->destro, valore);
        }
    }
    bool cerca (T valore) {
        return ricerca(root, valore) != nullptr;
    }
};

int main() {
    Albero <int> albero;

    albero.inserisci(5);
    albero.inserisci(3);
    albero.inserisci(7);
    albero.inserisci(1);
    albero.inserisci(4);
    albero.inserisci(6);
    albero.inserisci(8);

    cout << "Preorder:  ";
    albero.preorder(albero.root);   // 5 3 1 4 7 6 8
    cout << endl;

    cout << "Inorder:   ";
    albero.inorder(albero.root);    // 1 3 4 5 6 7 8 (ordine crescente)
    cout << endl;

    cout << "Postorder: ";
    albero.postorder(albero.root);  // 1 4 3 6 8 7 5
    cout << endl;

    // Ricerca
    cout << "Cerca 4: " << (albero.cerca(4) ? "trovato" : "non trovato") << endl;
    cout << "Cerca 9: " << (albero.cerca(9) ? "trovato" : "non trovato") << endl;
}