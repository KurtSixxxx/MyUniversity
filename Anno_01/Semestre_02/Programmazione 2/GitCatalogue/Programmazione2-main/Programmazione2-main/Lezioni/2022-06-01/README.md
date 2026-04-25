# Lezione del 01 giugno 2022

## Alberi Binari e Ricerca

Una struttura dati gerarchica che possiede una radice, dei rami e delle foglie (nodi senza figli).

### Proprietà di un nodo

* Arietà: Numero di figli possibili (definisce il grado di ramificazione dell'albero)
* Figli: Elenco di nodi
* Parent

Numero di nodi: (2^h)-1 (h = ceil(log2(n)))

### Definizione di albero binario completo

Un albero binario si dice completo se e solo se ha esattamente 2^h nodi, dove h è l'altezza dell'albero.

### Definizione di albero binario bilanciato

Un albero binario si dice bilanciato se la differenza di altezza tra il sottoalbero destro e sinistro è al massimo 1

### BST - Binary Search Tree

Un albero binario di ricerca è un particolare tipo di albero binario
Ogni nodo u è un oggetto costituito da diversi campi: key, un campo left, right e parent che puntano
rispettivamente al figlio sinistro, al figlio destro e al padre u.
 

### Metodo di inserimento ricorsivo


La procedura ricorsiva deve avere due parametri:
* Valore da inserire
* Radice del sottoalbero

```C++

void insert(T key)
    {
        if (isEmpty())
        {
            root = new BSTNode<T>(key);
            return;
        }

        insert(root, key);
    }

    void insert(BSTNode<T> *ptr, T key)
    {
        if (ptr == nullptr)
        {
            ptr = new BSTNode<T>(key);
            return;
        }
        if (key <= ptr->key)
        {
            insert(ptr->left, key);
        }
        else
        {
            insert(ptr->right, key);
        }
    }

```

### Metodi di visita di un albero

* Pre-order
* In-order
* Post-order

### Visita Pre-Order
Visito la radice, il sottoalbero sinistro e poi il sottoalbero destro

### Visita In-Order

Visito prima il sottoalbero sinistro, poi il nodo ed infinine il sottoalbero destro

```C++
   void visit(BSTNode<T> *ptr)
    {
        cout << ptr << endl;
    }

    void inOrder()
    {
        inOrder(root);
    }

    void inOrder(BSTNode<T> *ptr)
    {
        if(ptr==nullptr)
        {
            return;
        }
        
        inOrder(ptr->left);
        visit(ptr);
        inOrder(ptr->right);
    }
```

### Visita Post-Order

Visito ricorsivamente il sottoalbero sinistro, il sottoalbero destro e poi la radice

