#ifndef BST_H
#define BST_H

#include "bst_node.h"
#include <iostream>

template <typename T>
class BST
{
    BSTNode<T> *root;

public:
    BST()
    {
        root = nullptr;
    }

    bool isEmpty()
    {
        return root == nullptr;
    }

    BSTNode<T> *getRoot()
    {
        return this->root;
    }

    void insert(T key) // Funzione che va richiamata nel main al quale passo un parametro T (key)
    {
        if (this->isEmpty()) // Se l'albero è vuoto inizializzo root creando un nuovo nodo con chiave key
        {
            root = new BSTNode<T>(key);
            return;
        }

        insert(root, key); // Altrimenti richiamo il metodo ricorsivo insert al quale passo la radice come nodo di partenza
    }

    void insert(BSTNode<T> *ptr, T key)
    {
        if (ptr->left == nullptr && key <= ptr->key) // La chiave che voglio inserire è più piccola di quella del nodo ptr? Ptr ha un figlio sinistro?
        {
            ptr->left = new BSTNode<T>(key); // il figlio sinistro di ptr sarà un nuovo nodo con chiave key
            ptr->left->parent = ptr;         // il genitore del nodo appena creato sarà ptr
            return;
        }
        if (ptr->right == nullptr && key > ptr->key) // La chiave che voglio inserire è più grande di quella del nodo ptr? Ptr ha un figlio destro?
        {
            ptr->right = new BSTNode<T>(key); // il figlio destro di ptr sarà un nuovo nodo con chiave key
            ptr->right->parent = ptr;         // il genitore del nodo appena creato sarà ptr
            return;
        }
        else if (key <= ptr->key) // Se ptr ha due figli ma la chiave è più piccola di quella di ptr
        {
            insert(ptr->left, key); // Richiamo la funzione insert controllando questa volta il figlio sinistro di ptr
        }
        else
        {
            insert(ptr->right, key); // Altrimenti richiamo la funzione insert controllando questa volta il figlio destro di ptr
        }
    }

    void postorder() // Metodo che verrà chiamato dall'utente nel main
    {
        postorder(root); // Passo la radice, rende più user-friendly il codice
    }

    void postorder(BSTNode<T> *ptr)
    {
        if (ptr == nullptr)
            return;

        postorder(ptr->left);  // Visito il sottoalbero sinistro
        postorder(ptr->right); // Visito il sottoalbero destro
        cout << *ptr << endl;  // Stampo la radice
    }

    BSTNode<T> *min(BSTNode<T> *from) // Restituisce il valore minimo dell'albero con radice from
    {
        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = from;

        while (ptr->left)
        {
            ptr = ptr->left;
        }

        return ptr;
    }

    BSTNode<T> *max()
    {
        return max(root);
    }

    BSTNode<T> *max(BSTNode<T> *from)
    {
        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = from;
        while (ptr->right)
        {
            ptr = ptr->right;
        }

        return ptr;
    }

    BSTNode<T> *successor()
    {
        return successor(root);
    }

    BSTNode<T> *successor(T value)
    {
        return successor(search(value));
    }

    BSTNode<T> *successor(BSTNode<T> *x)
    {
        if (this->isEmpty())
        {
            return nullptr;
        }

        // Dobbiamo studiare 2 casi:

        if (x->right) // X ha un figlio destro
        {

            return this->min(x->right); // Il successore di x sarà il valore più piccolo nel sottoalbero con radice x->right
        }

        // 2. x non ha figli destri

        BSTNode<T> *y = x->parent; // Nodo ausiliario y che contiene il nodo genitore di x

        while (y != nullptr && x == y->right) // Se x è uguale al figlio destro di y...
        {
            x = y;         // Il nodo x diventa y (genitore di x)
            y = y->parent; // Il nodo y diventa il genitore di y
        }

        return y;
    }

    BSTNode<T> *search(T key)
    {
        return search(root, key);
    }

    BSTNode<T> *search(BSTNode<T> *ptr, T key) // Funzione che cerca un elemento all'interno del BST data la chiave
    {
        if (ptr == nullptr)
        {
            std::cout << "Non ho trovato " << key << std::endl;
            return nullptr;
        }

        if (ptr->key == key) // Se la chiave trovata corrisponde restituisci il nodo corrispondente
            return ptr;

        if (key <= ptr->key)               // Se la chiave è minore di quella di ptr
            return search(ptr->left, key); // cerca nel sottoalbero con radice ptr->left
        else
            return search(ptr->right, key); // Altrimenti nel sottoalbero con radice ptr->right

        return nullptr;
    }

    int distanza_successore(T key)
    {
        int count = 0;
        BSTNode<T> *ptr = search(key);

        if (!ptr || ptr == max())
            return 0;

        if (ptr->right)
        {
            ptr = ptr->right;
            count++;

            while (ptr->left)
            {
                ptr = ptr->left;
                count++;
            }

            return count;
        }

        BSTNode<T> *y = ptr->parent;
        count++;

        while (ptr && ptr == y->right)
        {
            ptr = ptr->parent;
            y = y->parent;
            count++;
        }

        return count;
    }
};
#endif