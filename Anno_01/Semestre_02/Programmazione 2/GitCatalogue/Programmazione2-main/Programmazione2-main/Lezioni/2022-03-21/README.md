# Lezione del 21 marzo 2022

### Ricerca di un elemento:

V[] = {2, 5, 3, 0, 12, 45, 55, 12, 4}

Caso migliore: 1

Caso peggiore: n

Caso medio: (n+1)/2

```C++

int ricercaLineare(int vettore[], int dim, int chiave)
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

### Ricorrenze:

* Divide and Conqueer

1. Dividi: dividere il problema in sottoproblemi
2. Conquista: risolvere i ottoproblemi ricorsivamente
3. Combina: combinare le soluzioni dei sottoproblemi ottenendo la soluzione del problema originale

### Relazioni di Ricorrenza:

L'analisi degli algoritmi ricorsivi si riduce spesso alla risoluzione di una o più equazioni di ricorrenza.

La loro comprensione ci permetterà di capire a fondo le prestazioni degli algoritmi studiati in seguito.

### Sommatorie:

Quando un algoritmo contiene un ciclo, il suo tempo di esecuzione può essere espresso come sommatoria dei tempi impiegati in ogni ciclo.

Si dividono in:
* serie aritmetiche (base cambia, esponente uguale)
* serie geometriche (base uguale, esponente cambia)
* serie armoniche

Godono delle proprietà: associativa e distributiva
