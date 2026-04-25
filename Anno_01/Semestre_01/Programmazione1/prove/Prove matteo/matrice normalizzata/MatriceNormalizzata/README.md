# MatriceNormalizzata

## Descrizione del progetto

Questo programma implementa un'applicazione in C per il **preprocessing e l'ordinamento di matrici numeriche**. 
Le funzionalità principali includono:

- **Lettura** di una matrice da file di input
- **Normalizzazione** dei dati (min-max normalization per colonna)
- **Ordinamento** delle colonne della matrice normalizzata utilizzando algoritmi di sorting efficienti
- **Output** sia su console che su file dei risultati

Il programma utilizza quattro diversi algoritmi di ordinamento (insertion sort, bubble sort, selection sort, quick sort), 
con quick sort come implementazione di default per le prestazioni ottimali.

## Requisiti di sistema

- **Compilatore**: GCC o Clang con supporto C99
- **Sistema operativo**: Linux, macOS, o Windows (con MSYS/MinGW)
- **Make**: GNU Make o compatibile

## Parametri di input

Il programma richiede tre argomenti da riga di comando:

```bash
./bin/MatriceNormalizzata <file.txt> <righe> <colonne>
```

Dove:

- `<file.txt>`: Percorso del file di input contenente i valori della matrice (numeri double separati da spazi o newline)
- `<righe>`: Numero di righe della matrice (intervallo valido: [5, 10])
- `<colonne>`: Numero di colonne della matrice (intervallo valido: [5, 10])

**Esempio**:

```bash
./bin/MatriceNormalizzata input.txt 5 6
```

## File di input e output

### Input

- **[input.txt](input.txt)**: File contenente i valori della matrice in formato tabulare o riga per riga

### Output

- **output.txt**: File generato dal programma contenente:
  - Matrice originale (etichettata come "A")
  - Matrice normalizzata (etichettata come "B")
  - Matrice normalizzata con colonne ordinate (etichettata come "B (sorted columns)")

## Compilazione

Per compilare il progetto, eseguire dal terminale:

```bash
make
```

Questo genererà l'eseguibile `bin/MatriceNormalizzata`.

### Opzioni di compilazione

```bash
make clean     # Rimuove gli oggetti compilati e l'eseguibile
make rebuild   # Ricompila da zero
```

## Esecuzione

### Esecuzione standard

```bash
make run ARGS="input.txt 5 6"
```

In alternativa, eseguire direttamente:

```bash
./bin/MatriceNormalizzata input.txt 5 6
```

### Output

Il programma stampa su console:

- La matrice originale
- La matrice normalizzata
- La matrice normalizzata con colonne ordinate

Gli stessi risultati vengono salvati nel file `output.txt`.

## Debug

Per eseguire il programma sotto debugger:

```bash
make debug DEBUGGER="gdb"
```

Se non specificato il parametro `DEBUGGER`, viene utilizzato **GDB** di default.

Debugger supportati:

- `gdb`: GNU Debugger
- `lldb`: LLVM Debugger
- `valgrind`: Strumento di profiling e memory checking

**Esempio con Valgrind**:

```bash
make debug DEBUGGER="valgrind"
```

## Struttura del progetto

```
MatriceNormalizzata/
├── Makefile                          # File di build
├── Prova_lab_06_Settembre_2023.pdf   # Consegna dell'esercizio
├── README.md                         # Questo file
├── input.txt                         # File di input di esempio
└── src/
    ├── MatriceNormalizzata.h         # Header file con definizioni e dichiarazioni
    └── MatriceNormalizzata.c         # File sorgente con implementazioni
```

## Algoritmi di ordinamento implementati

Il programma implementa quattro algoritmi di ordinamento per colonna:

| Algoritmo          | Caso migliore                   | Caso medio                      | Caso peggiore      | Utilizzo                           |
| ------------------ | ------------------------------- | ------------------------------- | ------------------ | ---------------------------------- |
| **Insertion Sort** | $\mathcal{O}(n)$                | $\mathcal{O}(n^2)$              | $\mathcal{O}(n^2)$ | Dati parzialmente ordinati         |
| **Bubble Sort**    | $\mathcal{O}(n)$                | $\mathcal{O}(n^2)$              | $\mathcal{O}(n^2)$ | Semplicità implementativa          |
| **Selection Sort** | $\mathcal{O}(n^2)$              | $\mathcal{O}(n^2)$              | $\mathcal{O}(n^2)$ | Minimizza scambi in memoria        |
| **Quick Sort**     | $\mathcal{O}(n \cdot \log (n))$ | $\mathcal{O}(n \cdot \log (n))$ | $\mathcal{O}(n^2)$ | **Prestazioni generali** (default) |

## Funzioni principali

- `readInput()`: Legge e valida gli argomenti da riga di comando
- `allocateMatrix()`: Alloca dinamicamente una matrice di puntatori a double
- `fillMatrix()`: Popola la matrice dai dati del file
- `normalize()`: Normalizza la matrice per colonna
- `sortMatrixCols()`: Ordina tutte le colonne della matrice
- `printMatrix()`: Stampa la matrice su file o console
- `freeMatrix()`: Libera la memoria allocata

Per documentazione dettagliata delle funzioni, consultare i commenti Doxygen nel codice sorgente.

## Consegna

- [Prova_lab_06_Settembre_2023](Prova_lab_06_Settembre_2023.pdf)

## Codice sorgente

- [MatriceNormalizzata.h](src/MatriceNormalizzata.h) - Definizioni di strutture e dichiarazione di librerie di supporto
- [MatriceNormalizzata.c](src/MatriceNormalizzata.c) - Implementazione delle [funzioni](#funzioni-principali)

---

#### Credits

[MoonLightLucrix](https://www.github.com/MoonLightLucrix)
