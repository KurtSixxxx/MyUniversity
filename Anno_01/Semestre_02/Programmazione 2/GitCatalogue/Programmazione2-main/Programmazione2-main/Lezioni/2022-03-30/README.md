# Lezione del 30 marzo 2022

### Algoritmi ricorsivi di ordinamento:

Utilizziamo la strategia del Divide & Conqueer

1. Suddividere il problema in sottoproblemi più piccoli
2. Risolvere i sottoproblemi in maniera indipendenti
3. Combinare le soluzioni dei sottoproblemi per risolvere il problema generale

* Caso base: Un elemento è sempre ordinato

Passo 1: Spezzare l'array fino ad ottenere sottoproblemi di dimensione 1

Passo 2: Nel caso base non devo fare nulla

Passo 3: Combinare

### Merge Sort:

* Complessità dell'algoritmo: Θ(n)

N.B: Questa funzione impiega sempre tempo n, quindi è limitata sia inferiormente che superiormente.

```C++
/*
 *
 *  p = indice iniziale sottoArray
 *  q = indice p <= q <= r
 *  r = indice finale sottoArray
 *
 *  n1 = q - p + 1
 *  n2 = r - q
 *
 *  Creo due A L e Q con rispettiva dimensione n1 ed n2
 *
 *  L <- A[p -> q]
 *  R <- A[q -> r]
 *
 *  k, i, j indici che scorrono rispettivamente A, L ed R
 *
 */

void merge(int A[], int const p, int const q, int const r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1],
        *R = new int[n2];

    for (int i = 0; i < n1; i++)
    {
        L[i] = A[p + i];
    }

    for (int j = 0; j < n2; j++)
    {
        R[j] = A[q + 1 + j];
    }

    int indiceL = 0,
        indiceR = 0,
        indiceA = p;

    while (indiceL < n1 && indiceR < n2)
    {
        if (L[indiceL] <= R[indiceR])
        {
            A[indiceA] = L[indiceL];
            indiceL++;
        }
        else
        {
            A[indiceA] = R[indiceR];
            indiceR++;
        }

        indiceA++;
    }

    while (indiceL < n1)
    {
        A[indiceA] = L[indiceL];
        indiceL++;
        indiceA++;
    }

    while (indiceR < n2)
    {
        A[indiceA] = R[indiceR];
        indiceR++;
        indiceA++;
    }
}

void mergeSort(int vec[], int p, int r)
{
    int q = 0;

    if (p < r)
    {
        q = floor((p + r) / 2);
    }
    else
    {
        return;
    }

    mergeSort(vec, p, q);
    mergeSort(vec, q + 1, r);

    merge(vec, p, q, r);
}

```

### Quick Sort:

1. La scelta del pivot è casuale, non stiamo quindi facendo alcuna considerazione sul suo valore effettivo

### Complessità dell'algoritmo: 

* Caso peggiore: O(n*n)
* Caso medio: O(n log n)
* Caso migliore: O(n log n)

```C++
/*
 *
 *  p = indice iniziale sottoarray
 *  i = p - 1
 *  j = p
 *  r = indice finale sottoarray
 *
 *  Far scorrere j da p ad r-1, se l'elemento A[j] < pivot
 *  allora faccio avanzare e scambio A[i] ed A[j]
 *  alla fine scambio il pivot con A[i+1]
 *
 */

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int vec[], int p, int q)
{
    int pivot = vec[q]; // pivot
    int i = (p - 1);

    for (int j = p; j <= q - 1; j++)
    {
        if (vec[j] < pivot)
        {
            i++;
            swap(vec[i], vec[j]);
        }
    }

    swap(vec[i + 1], vec[q]);

    return (i + 1);
}

void quickSort(int vec[], int p, int r)
{
    int q = 0;

    if (p < r)
    {
        q = partition(vec, p, r);
    }
    else
    {
        return;
    }

    quickSort(vec, p, q - 1);
    quickSort(vec, q + 1, r);
}

```