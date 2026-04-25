# Lezione del 11 maggio 2022

### Inserimento ordinato

```C++
void insertInOrder(T val)
    {
        if (this->isEmpty())
        {
            this->insertHead(val);
            return;
        }

        if (head->val >= val)
        {
            this->insertHead(val);
            return;
        }

        Node<T> *ptr = head;

        while (ptr->getNext() != nullptr && (val >= ptr->val))
        {
            if (val <= ptr->next->val)
            {
                break;
            }

            ptr = ptr->getNext();
        }

        if (ptr->next == nullptr)
        {
            this->insertTail(val);
            return;
        }

        Node<T> *toInsert = new Node<T>(val);
        toInsert->next = ptr->next;
        ptr->next = toInsert;
    }
```

Modificare il codice dell'inserimento ordinato in modo che sia possibile inserire sia in ordine ascendente che discendente, scrivendo due nuovi metodi, selezionado l'inserimento appropriato tramite parametro.

### Cancellazione primo elemento (head)

```C++
void deleteHead()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        Node<T> *temp = head;
        head = head->next;

        delete temp;
    }
```

### Cancellazione ultimo elemento (tail)

```C++
void deleteTail()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        Node<T> *cur = head;
        Node<T> *prev = nullptr;

        while (cur->next)
        {
            prev = cur;
            ptr = ptr->next;
        }

        prev->next = nullptr;
        delete cur;
    }

```

### Cancellazione elemento generico

```C++
void remove(T val)
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        if (val == head->val)
        {
            deleteHead();
            return;
        }

        Node<T> *cur = head;
        Node<T> *prev = nullptr;

        while (cur->next && cur->val != val)
        {
            prev = cur;
            cur = cur->next;
        }

        if (!(cur->next) && cur->val != val)
        {
            cout << "Element with value " << val << " not found!" << endl;
            return;
        }

        prev->next = cur->next;
        delete cur;
    }
```
Aggiungere alla classe lista un contatore che tenga conto del numero di elementi inseriti e quindi della dimensione della lista.

Aggiugnere un puntatore alla coda e modificare tutti i metodi che accedono alla coda.

Implementare l'operatore di accesso ([]) sfruttando la conoscenza del numero di elementi inseriti (potrebbe richiedere modifiche al nodo).

Valutare la complessità computazionale di inserimento e cancellazione.

### Liste doppiamente linkate

Sequenza di elementi (nodi) collegati tra loro in modo successivo

### Carattristiche di un nodo in una lista doppiamente linkata

* valore : tipo di dato
* nodo successivo
* nodo precedente

### Inserimento in testa

```C++
    void insertHead(T val)
    {
        if (this->isEmpty())
        {
            head = new DLNode(val);
            tail = head;
            return;
        }

        DLNode<T> *toInsert = new DLNode(val);
        toInsert->next = head;
        head->prev = toInsert;
        head = toInsert;
    }
```

### Inserimento in coda

```C++
    void insertTail(T val)
    {
        if (this->isEmpty())
        {
            this->insertHead(val);
            return;
        }

        DLNode<T> *toInsert = new DLNode<T>(val);
        toInsert->prev = tail;
        tail->next = toInsert;
        tail = toInsert;
    }
```

### Cancellazione primo elemento (head)

```C++
    void removeHead()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        if (head == tail)
        {
            DLNode<T> *ptr = head;
            head = nullptr;
            tail = nullptr;
            delete ptr;
        }

        DLNode<T> *ptr = head;
        ptr->next->prev = nullptr;
        head = ptr->next;

        delete ptr;
    }
```

### Cancellazione ultimo elemento (tail)

```C++
    void removeTail()
    {
        if (this->isEmpty())
        {
            cout << "Empty list!" << endl;
            return;
        }

        if (head == tail)
        {
            DLNode<T> *ptr = head;
            head = nullptr;
            tail = nullptr;
            delete ptr;
        }

        DLNode<T> *ptr = tail;
        ptr->prev->next = nullptr;
        tail = ptr->prev;

        delete ptr;
    }
```
