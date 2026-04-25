# Calcolo dei Predicati

## 1. Segnatura (Σ)
- **Definizione**: insieme di simboli di funzione e di relazione (predicato), ciascuno con la propria **arietà** (numero di argomenti).
- Esempio di segnatura:
  ```text
  Σ = { 
    funzioni: { 0⁰, S¹ },
    predicati: { <², P¹ }
  }
  ```
  - `0⁰` è un simbolo di funzione costante (arietà 0).  
  - `S¹` è un simbolo di funzione unaria (es.: “successore di…”).  
  - `<²` è un predicato binario (es.: “minore di”).  
  - `P¹` è un predicato unario.

## 2. Termini
L’insieme dei **termini** `Term_Σ` è costruito così:
1. Ogni **variabile** individuale `x, y, z, …` ∈ `Term_Σ`.  
2. Se `t₁,…,tₙ` ∈ `Term_Σ` e `fⁿ` ∈ Σ (funzione n-aria), allora  
   `f(t₁,…,tₙ)` ∈ `Term_Σ`.  
3. Non ci sono altri termini.

**Esempi di termini**:  
- `0`  
- `S(0)`  
- `S(S(x))`  
- `h(g(r),\,r)` (usando una funzione binaria `h` e una unaria `g`).

## 3. Formule Ben Formate (fbf)
L’insieme delle fbf, `W`, su Σ è definito:
1. Se `Pⁿ` ∈ Σ (predicato n-ario) e `t₁,…,tₙ` ∈ `Term_Σ`, allora  
   `P(t₁,…,tₙ)` ∈ `W`.  
2. Se `α` ∈ `W`, allora `(¬α)` ∈ `W`.  
3. Se `α, β` ∈ `W`, allora `(α → β)` ∈ `W`.  
4. Se `α` ∈ `W` e `x` variabile, allora `∀x.α` ∈ `W` e `∃x.α` ∈ `W`.  

**Esempi di fbf**:  
- `P(S(S(0)))`  
- `<(0, S(x))`  
- `¬(<(x,y))`  
- `∀x (P(x) → ∃y Q(y,x))`  

## 4. Deduzione Naturale per i Quantificatori

### 4.1 Quantificatore Universale (∀)
- **Introduzione (∀I)**  
  ```
  [⋯]
     … derivazione di A
  ───────────────────
    ∀x.A           (se x non compare libero nelle ipotesi non scaricate)
  ```
- **Eliminazione (∀E)**  
  ```
    ∀x.A
  ───────
    A[t/x]
  ```
  Sostituisci `x` con un termine `t`.

### 4.2 Quantificatore Esistenziale (∃)
- **Introduzione (∃I)**  
  ```
    A[t/x]
  ───────────
    ∃x.A
  ```
- **Eliminazione (∃E)**  
  ```
    ∃x.A   [A(x)]ⁿ
           ⋯ derivazione di B
    ─────────────────── (x non libero altrove)
         B
  ```

## 5. Semantica: Struttura (Modello) e Ambiente

### 5.1 Struttura (A_Σ)
Una **struttura** per Σ è la tripla  
```
A_Σ = ⟨ A, F, P ⟩
```
- **A**: insieme non vuoto di **individui**.  
- **F**: per ogni `fⁿ` ∈ Σ (simbolo di funzione) una funzione  
  ```
  f̃ⁿ : Aⁿ → A
  ```
- **P**: per ogni `Pⁿ` ∈ Σ (predicato) una relazione  
  ```
  P̃ⁿ : Aⁿ → {0,1}
  ```  

### 5.2 Ambiente (p)
Un **ambiente** `p` è una funzione che assegna a ciascuna variabile individuale un elemento di `A`:  
```
p : {variabili} → A
```

### 5.3 Valutazione di Termini e Formule
- Un termine `t` ha valore `[[t]]ₚ ∈ A` calcolato ricorsivamente:  
  ```text
  [[x]]ₚ = p(x)  
  [[f(t₁,…,tₙ)]]ₚ = f̃ⁿ([[t₁]]ₚ,…,[[tₙ]]ₚ)
  ```
- Una formula `α` ha valore `[[α]]ₚ ∈ {0,1}`:
  - `[[P(t₁,…,tₙ)]]ₚ = P̃ⁿ([[t₁]]ₚ,…,[[tₙ]]ₚ)`
  - `[[¬α]]ₚ = 1 – [[α]]ₚ`
  - `[[α → β]]ₚ = max(1 – [[α]]ₚ, [[β]]ₚ)`
  - `[[∀x.α]]ₚ = minₐ { [[α]]_{ₚ[x↦a]} }`  
  - `[[∃x.α]]ₚ = maxₐ { [[α]]_{ₚ[x↦a]} }`  

dove `ₚ[x↦a]` è l’ambiente che come `p` ma invia `x ↦ a`.

---

Con questi appunti hai ora:

1. **Segnatura**, **termini** e **fbf** ben definiti.  
2. **Regole di deduzione naturale** per ∀ e ∃, con condizioni di applicazione.  
3. **Semantica formale** completa di struttura e ambiente.