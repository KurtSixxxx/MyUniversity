# Lezione del 09 maggio 2022

### Liste:

### Caratteristiche degli array

* Dimensione massima fissa
* Possiamo accedere ad ogni elemento in tempo costante

### Cos'è una linked list semplice?

Sequenza di elementi (nodi) collegati tra loro in modo successivo

* Dimensione non prefissata ma variabile
* Nodi composti da due parti, valore e puntatore (link)
* Il primo elemento si chiama **head**, l'ultimo punterà ad un **nullpointer**

### Carattristiche di un nodo

* valore : tipo di dato
* nodo successivo

### Operazioni sulle liste

* Inserimento
* Accesso
* Ricerca
* Cancellazione
* Ordinamento
* Copia
* Controllo lista vuota

### Controllo lista vuota

```C++
bool isEmpty()
    {
        return head = nullptr;
    }
```

### Inserimento

```C++
void insert(T val)
    {
        if (this->isEmpty())
        {
            head = new Node<T>(val);
        }
    }
```

### Inserimento in testa

```C++
void insertHead(T val)
    {
        if (!this->isEmpty())
        {
            Node<T> *temp = new Node<T>(val);
            temp->next = head;
            this->head = temp;
        }
        else
        {
            insert(val);
            return;
        }
    }
```

### Inserimento in coda

```C++
void insertTail(T val)
    {
        if (this->isEmpty())
        {
            this->insertHead(val)
        }

        Node<T> *ptr = head;
        while (ptr->getNext() != nullptr)
        {
            ptr = ptr->getNext();
        }

        Node<T> *temp = new Node<T>(val);
        ptr->next = temp;
    }
```