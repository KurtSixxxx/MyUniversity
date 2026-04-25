# Lezione del 04 aprile 2022

### Implementazione del Merge Sort:

* Complessità dell'algoritmo: Θ(n)

N.B: Questa funzione impiega sempre tempo n, quindi è limitata sia inferiormente che superiormente.

```C++
void merge(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int *L = new int[n1 + 1];
    int *R = new int[n2 + 1];

    for (int i = 0; i < n1 - 1; i++)
    {
        L[i] = A[p + i];
    }

    for (int j = 0; j <= n2; j++)
    {
        R[j - 1] = A[q + j];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

    int i = 0, j = 0, k = p;

    for (k = p; k <= r; k++)
    {
        if (L[i] < R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int A[], int p, int r)
{
    int q = 0;

    if (p < r)
    {
        q = floor((p + r) / 2.0);
    }

    mergeSort(A, p, q);
    mergeSort(A, q + 1, r);

    merge(A, p, q, r);
}
```