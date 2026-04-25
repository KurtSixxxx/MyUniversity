# Lezione del 18 maggio 2022

## Queue

Una serie di elementi uno dopo l'altro che verranno serviti in ordine di arrivo
Per questo motivo, le pile sono strutture dati di tipo FIFO (First In First Out)

### Attributi

Uguali alla classe DLList

### Metodi

* insertTail() => Enqueue
* removeHead() => Dequeue
* isEmpty() 

### Metodo enqueue
```C++

void enqueue(T val)
    {
        DLList<T>::insertTail(val);
        size++;
    }

```
### Metodo dequeue
```C++
   DLNode<T> *dequeue()
    {
        if (isEmpty())
        {
            return nullptr;
        }
        DLNode<T> *ptr = DLList<T>::head;
        DLList<T>::removeHead();
        size--;
        return ptr;
    }
```

### Metodo isEmpty
```C++
bool isEmpty()
    {
        return size == 0;
    }
```
## Static Queue class

### Metodo enqueue
```C++

void push(T val)
    {
        if (top == maxSize - 1)
        {
            return;
        }

        array[++top] = val;
    }

```
### Metodo dequeue
```C++
    T dequeue()
    {
        if (size == 0)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }

        T val = array[head];
        head = (++head % maxSize);
        size--;
        return val;
    }

```

### Metodo isEmpty
```C++
    bool isEmpty()
    {
        return head == -1;
    }
```