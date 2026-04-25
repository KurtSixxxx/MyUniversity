# Lezione del 16 maggio 2022

## Le pile (stack)

Le operazioni di inserimento e rimozione in o da una pila avvengono sempre dalla cima della stessa.

Per questo motivo, le pile sono strutture dati di tipo LIFO (Last In First Out)

### Attributi

* Size (Dimensione)
* Top (Cima della pila)

### Metodi

* push() aggiunge un elemento alla pila
* pop() rimuove un elemento dalla pila
* isEmpty() 

### Metodo push
```C++

void push(T val)
    {
        List<T>::insertHead(val);
        size++;
    }

```
### Metodo pop
```C++

    Node<T> *pop()
    {
        if (List<T>::isEmpty())
        {
            return nullptr;
        }

        Node<T> *ptr = top();
        List<T>::deleteHead();
        size--;
        return ptr;
    }

```
## Static Stack class

### Metodo push
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
### Metodo pop
```C++
    T pop()
    {
        if (isEmpty())
        {
            return -1;
        }

        return array[top--];
    }

```

### Metodo isEmpty
```C++
    bool isEmpty()
    {
        return top == -1;
    }
```

## Complessità delle operazioni stack

* push => O(1)
* pop => O(1)
* top => O(1)
