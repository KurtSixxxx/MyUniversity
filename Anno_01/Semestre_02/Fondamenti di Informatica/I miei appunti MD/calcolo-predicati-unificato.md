# Calcolo dei Predicati - Appunti Completi

*Riferimento: Logica Martini pag. 33*

## Introduzione

Il **Calcolo dei Predicati** (o **Logica del Primo Ordine**) ci permette di ragionare in un mondo composto da **individui** e dalle **relazioni** tra di loro. È un'estensione della logica proposizionale che ci consente di esprimere affermazioni più complesse e dettagliate.

## 1. Segnatura (Σ)

### Definizione

I simboli che rappresentano gli **individui**, le **relazioni tra di loro e gli insiemi delle fbf** (W). Questi simboli vengono chiamati "**segnatura**" $\rightarrow$ insieme di simboli utilizzata per rappresentare gli individui e le relazioni che nella nostra logica vogliamo rappresentare tramite simboli.

La **segnatura** è l'insieme di simboli che utilizziamo per rappresentare gli individui e le relazioni nel nostro sistema logico.

$\Sigma = \{ \{ h^2, g^1, r^o \},\{ Q^3, P^1, R^2 \} \}$

$\{h^2, g^1, r^0\}$ **simboli di funzione**, usati nelle fbs per denotare individui (persone, oggetti, numeri...).

\${ Q^3, P^1, R^2 \}$ **simboli di relazione**, usati nelle fbs per denotare relazioni (essere più alto di, amare, essere figlio di...).

**Cosa significano:**

- $r^0$: una costante (es. "Mario")
- $g^1$: funzione che prende 1 argomento (es. "la mamma di...")
- $h^2$: funzione che prende 2 argomenti (es. "il figlio di ... e ...")
- $P^1$: proprietà di 1 individuo (es. "... è alto")
- $R^2$: relazione tra 2 individui (es. "... ama ...")
- $Q^3$: relazione tra 3 individui (es. "... ha dato ... a ...")

Una segnatura Σ è composta da due insiemi:

L'**esponente** (chiamato **arietà**) indica quanti argomenti accetta il simbolo:

- **0**: costante (nessun argomento)
- **1**: unario (un argomento)  
- **2**: binario (due argomenti)
- **3**: ternario (tre argomenti)
- e così via...

### Esempio Pratico

$\Sigma = \{ \\ 
  \text{Funzioni: } \{ r^0, g^1, h^2 \},\\
  \text{Relazioni: } \{ P^1, R^2, Q^3 \}
\\
\}$

**Interpretazione intuitiva:**

- $r^0$: una costante (es. "Mario")
- $g^1$: funzione unaria (es. "la mamma di...")
- $h^2$: funzione binaria (es. "il figlio di ... e ...")
- $P^1$: proprietà di un individuo (es. "... è alto")
- $R^2$: relazione tra due individui (es. "... ama ...")
- $Q^3$: relazione tra tre individui (es. "... ha dato ... a ...")

## 2. Termini

I **termini** rappresentano gli **individui** nel nostro mondo. L'insieme dei termini `Term_Σ` viene costruito in modo ricorsivo.

### Costruzione dei Termini

1. **Variabili individuali**: `x, y, z, ...` sono tutte termini
   - Rappresentano individui generici (come "segnaposto")
2. **Applicazione di funzioni**: Se `t₁, ..., tₙ` sono termini e `fⁿ` è un simbolo di funzione n-ario, allora `f(t₁, ..., tₙ)` è un termine

### Esempi di Termini

- `r` (costante)
- `x, y, z` (variabili)
- `g(x)` ("la mamma di x")
- `h(g(r), r)` ("il figlio della mamma di Mario e Mario")
- `h(g(r), x)` ("il figlio della mamma di Mario e x")

**Nota importante**: I termini ci dicono **chi** stiamo considerando, ma non fanno ancora affermazioni vere o false.

## 3. Formule Ben Formate (fbf)

Le **fbf** sono le espressioni che possono essere **vere** o **false**. Rappresentano affermazioni sul nostro mondo.

### Costruzione delle fbf

1. **Formule atomiche**: Se `Pⁿ` è un simbolo di relazione n-ario e `t₁, ..., tₙ` sono termini, allora `P(t₁, ..., tₙ)` è una fbf
2. **Negazione**: Se `α` è una fbf, allora `¬α` è una fbf
3. **Implicazione**: Se `α` e `β` sono fbf, allora `α → β` è una fbf
4. **Quantificatori**: Se `α` è una fbf e `x` è una variabile, allora:
   - `∀x α` (quantificatore universale)
   - `∃x α` (quantificatore esistenziale)

### Esempi di fbf

- `P(x)` ("x ha la proprietà P")
- `R(x, g(x))` ("x è in relazione R con la sua mamma")
- `¬(< (x,x))` ("x non è minore di se stesso")
- `∀x R(x, g(x))` ("per ogni x, x è in relazione R con la sua mamma")
- `∀x ∀y ∀z (< (x,y) ∧ < (y,z) → < (x,z))` ("< è transitiva")

## 4. Quantificatori

I quantificatori ci permettono di fare affermazioni che riguardano **tutti** gli individui o **alcuni** individui.

### Quantificatore Universale (∀)

- `∀x α` si legge: "**Per ogni** x vale α"
- L'affermazione è vera se α è vera per **tutti** gli individui possibili

### Quantificatore Esistenziale (∃)

- `∃x α` si legge: "**Esiste un** x tale che vale α"  
- L'affermazione è vera se α è vera per **almeno un** individuo
- **Definizione**: `∃x α ≡ ¬∀x ¬α`

### Esempio Comparativo

- `∀x P(x)`: "Tutti hanno la proprietà P"
- `∃x P(x)`: "Qualcuno ha la proprietà P"

## 5. α-Conversione (Alpha-Conversione)

Le variabili quantificate sono come "segnaposto". Due formule che differiscono solo nel nome delle variabili quantificate sono **equivalenti**.

### Esempio

Queste due fbf sono identiche nel significato:

- `∀x R(x, g(x))` 
- `∀y R(y, g(y))`

Entrambe dicono: "Per ogni individuo, quell'individuo è in relazione R con la sua mamma".

## 6. Regole di Deduzione Naturale

### 6.1 Quantificatore Universale (∀)

**Introduzione (∀I)**

```
[Assumiamo un x generico]
... deriviamo A(x)
─────────────────────── (x non deve essere libero nelle ipotesi)
∀x A(x)
```

**Eliminazione (∀E)**

```
∀x A(x)
─────────── (sostituiamo x con un termine t qualsiasi)
A(t)
```

### 6.2 Quantificatore Esistenziale (∃)

**Introduzione (∃I)**

```
A(t)    (abbiamo A vera per un termine specifico t)
───────
∃x A(x)  (quindi esiste qualcuno per cui A è vera)
```

**Eliminazione (∃E)**

```
∃x A(x)   [A(c)]ⁿ (assumiamo A vera per un c "fresco")
          ... deriviamo B
────────────────────── (c non deve apparire altrove)
B
```

## 7. Semantica: Come Interpretiamo le Formule

Per dare significato alle nostre formule, abbiamo bisogno di:

### 7.1 Struttura (Modello) A_Σ

Una **struttura** specifica:

```
A_Σ = ⟨ A, F, P ⟩
```

- **A**: insieme non vuoto di individui concreti (es. {Mario, Luigi, Peach})
- **F**: interpretazione delle funzioni (es. g¹ → "la funzione mamma")
- **P**: interpretazione dei predicati (es. R² → "la relazione amore")

### 7.2 Ambiente (p)

Un **ambiente** `p` assegna a ogni variabile un individuo specifico:

```
p : {x, y, z, ...} → A
```

Esempio: `p(x) = Mario, p(y) = Luigi`

### 7.3 Valutazione

- **Termini**: `[[t]]_p` ci dice quale individuo rappresenta il termine t
- **Formule**: `[[α]]_p ∈ {0,1}` ci dice se la formula α è vera (1) o falsa (0)

**Per i quantificatori:**

- `[[∀x α]]_p = 1` se α è vera per **tutti** i possibili valori di x
- `[[∃x α]]_p = 1` se α è vera per **almeno un** valore di x

## Esempi Pratici

Consideriamo il mondo delle persone con:

- Funzioni: `madre¹` (la madre di qualcuno)
- Predicati: `Ama²` (qualcuno ama qualcun altro)

### Esempi di Termini

- `x` (una persona generica)
- `madre(x)` (la madre di x)
- `madre(madre(x))` (la nonna materna di x)

### Esempi di Formule

- `Ama(x, madre(x))` ("x ama sua madre")
- `∀x Ama(x, madre(x))` ("tutti amano la propria madre")
- `∃x ∀y Ama(y, x)` ("esiste qualcuno che è amato da tutti")

## Riassunto dei Concetti Chiave

1. **Segnatura**: I simboli del nostro "vocabolario logico"
2. **Termini**: Rappresentano individui
3. **Formule**: Fanno affermazioni vere o false
4. **Quantificatori**: Permettono di parlare di "tutti" o "alcuni"
5. **Struttura**: Dà significato concreto ai nostri simboli
6. **Ambiente**: Assegna valori specifici alle variabili

Il Calcolo dei Predicati ci permette di esprimere ragionamenti complessi in modo preciso e rigoroso, fondamentale per la matematica, l'informatica e la logica formale.

[Calcolo dei predicati_Claude]("C:\Users\giuli\Desktop\Desktop\UniCT\1° Anno\Secondo Semestre\Fondamenti di Informatica\I miei appunti\Calcolo dei predicati_Claude.md")