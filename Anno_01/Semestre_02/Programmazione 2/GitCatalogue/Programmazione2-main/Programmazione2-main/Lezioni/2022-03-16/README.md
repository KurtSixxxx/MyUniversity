# Lezione del 16 marzo 2022

### Complessità:

* Costo di un algoritmo -> dipende dall'input -> tempo, spazio
```C++

if(x % 2 == 0) //Guardia
{
    ... //Corpo
}

```
* Ordinamento -> Caso migliore, medio, peggiore

### Complessità temporale: 

#### Assunzione 1:
* Proporzionale al numero di operazioni eseguite (istruzioni)
* Indipendente dall'HW considerato

#### Assunzione 2:
* Dipendenza dalla dimensione dell'input
* Comportamento asintotico ( n -> ∞)

```C++

for(int i=0; i<N; i++)
{
    swap(i, i+1);
    swap(i+2, i+1);
    v[i] = -4;
}

```

### Notazione asintomatica 

* f(x) funzione principale

* g(x) limite asintotico superiore -> asintoto che limita superiormente f(x)

* h(x) limite asintotico inferiore -> asintoto che limita inferiormente f(x)

<h3 align="center">g(x)<=f(x)<=h(x)</h3>

### Notazione O 

Si utilizza per stabilire delle classi di equivalenza


O(g(n)) insieme di tutte le funzioni f(n) tali che esistono delle costanti c, n0 appartenenti ai numeri naturali tali che 0 <= f(n) <= cg(n) per ogni n >= n0

O(g(n)) = { f(n) : ∃ c,n0 ∈ N | 0 <= f(n) <= cg(n) ∀n >= n0 }

<h3 align="center">f(n)=O(n)</h3>

### Funzioni notevoli

* f(n) = c -> funzione costante
* f(n) = log in base b di n con b>1
* f(n) = a*n -> funzione lineare
* f(n) = n*log(n) -> funzione log lineare
* f(n) = a^n, a>1 -> funzione esponenziale
* f(n) = n^a, a>1 -> funzione polinomiale

![Immagine dei grafici](grafici.jpg?raw=true)

### Notazione Ω

Ω(g(n)) = { f(n) : ∃ c,n0 ∈ N | 0 <= cg(n) <= f(n) ∀n >= n0 }

<h3 align="center">f(n)=Ω(n)</h3>

### Notazione Θ

Θ(g(n)) = { f(n) : ∃ c1,c2,n0 ∈ N | 0 <= c1g(n) <= f(n)<=c2g(n) ∀n >= n0 }
