# Lezione del 08 giugno 2022
 
### Cancellazione e gestione delle eccezioni

```C++
BSTNode<T> *min()
    {

        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = root;
        while (ptr->left)
        {
            ptr = ptr->left;
        }

        return ptr;
    }

    BSTNode<T> *max()
    {

        if (isEmpty())
        {
            return NULL;
        }

        BSTNode<T> *ptr = root;
        while (ptr->right)
        {
            ptr = ptr->right;
        }

        return ptr;
    }

```

### Ricerca di un nodo data la chiave

```C++
  BSTNode<T> *search(BSTNode<T> *ptr, T key)
    {
        if (ptr == nullptr)
        {
            return nullptr;
        }

        if (ptr->key == key)
        {
            return nullptr;
        }

        if (key <= ptr->key)
        {
            return search(ptr->left, key);
        }
        else
        {
            return search(ptr->right, key);
        }
    }
```

### Ricerca di successore e predecessore

```C++

    BSTNode<T> *successor(BSTNode<T> *x)
    {
        if (this->isEmpty())
        {
            return nullptr;
        }

        if (x->right)
        {
            return this->min(x->right);
        }

        BSTNode<T> *y = x->parent;

        while (x != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }

        return y;
    }

    BSTNode<T> *predecessor(BSTNode<T> *x)
    {
        if (this->isEmpty())
        {
            return nullptr;
        }

        if (x->left)
        {
            return this->max(x->left);
        }

        BSTNode<T> *y = x->parent;

        while (x != nullptr && x == y->right)
        {
            x = y;
            y = y->parent;
        }

        return y;
    }

```

### Visita Post-Order

Visito ricorsivamente il sottoalbero sinistro, il sottoalbero destro e poi la radice

