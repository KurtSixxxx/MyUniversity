# Lezione del 28 marzo 2022

### Ricerca di un elemento all'interno di un array non ordinato:

V[] = {10, 7, 4, 2, 6, 8, 3, 1, 5, 9}

Per trovare i numeri 5, 3 e 7 effettuo 9, 7 e 2 controlli

```C++

int ricercaLineare(int vettore[], int dim, int chiave) //O(n)
{
    for(int i=0; i<dim; i++)
    {
        if(vettore[i]==chiave)
        {
            return 1;
        }

        return -1;
    }
}

```

V[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}

Possiamo cercare i numeri 5, 3 e 7 dividendo ogni volta a metà l'array in base al criterio che il numero cercato sia maggiore o minore della metà cercata.

### Ricerca binaria o dicotomica:

```C++

bool ricercaBinaria(int array[], int dim, int key)
{
    bool found = false;
    int start = 0, end = dim - 1;

    while (!found && (start != end))
    {
        int midpoint = start + ((end - start) / 2); // dim / 2

        if (array[midpoint] == key)
        {
            found = true;
        }
        else if (key < array[midpoint]) // Considerare la metà inferiore
        {
            // Aggiorniamo end
            end = midpoint;
        }
        else // Considerare la metà superiore
        {
            // Aggiorniamo start
            start = midpoint + 1;
        }

        cout << "Start: " << start << "\tMidpoint: " << midpoint << "\tEnd:" << end << endl;
    }

    return found;
}

```

### Metodi di ordinamento di un array:

```C++
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selectionSort(int vec[], int dim) //O(n*n)
{
    int indexMin;

    for (int c = 0; c < dim; c++)
    {
        indexMin = c;

        for (int i = c + 1; i < dim; i++)
        {
            if (vec[i] < vec[indexMin])
            {
                indexMin = i;
            }
        }

        swap(vec[c], vec[indexMin]);
    }
}

void bubbleSort(int vec[], int dim) //O(n*n)
{
    for (int c = 0; c < dim; c++)
    {
        for (int i = c + 1; i < dim; i++)
        {
            if (vec[i] < vec[c])
            {
                swap(vec[c], vec[i]);
            }
        }
    }
}

void insertionSort(int vec[], int dim) //O(n*n)
{
    int temp = 0, j = 0;

    for (int i = 0; i < dim; i++)
    {
        temp = vec[i];

        for (j = i; j > 0; j--)
        {
            if (temp < vec[j - 1])
            {
                vec[j] = vec[j - 1];
            }
            else
            {
                break;
            }
        }

        vec[j] = temp;
    }
}

```

I 3 metodi di ordinamento hanno complessità O(n*n) ma differiscono nel numero di controlli effettuati all'interno dei due cicli for