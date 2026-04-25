# Esercizi Guida (Svolti)

**Esercizio 1: Traslazione Pura**

**Problema:** L'immagine è stata spostata di +10 pixel a destra e +5 in basso. Trova l'origine del pixel di output (15, 25).

- Matrice $T^{-1}$:
$T^{-1} = \begin{pmatrix} 1 & 0 & 0 \\ 0 & 1 & 0 \\ -10 & -5 & 1 \end{pmatrix}$
- **Calcolo:**
    ◦ $v = 15 - 10 = \mathbf{5}$
    ◦ $w = 25 - 5 = \mathbf{20}$
- **Risultato:** Il colore viene preso da (5, 20)

---

**Esercizio 2: Scalatura (Ingradimento)**

**Problema**: L’immagine è stata raddoppiata (s = 2). Trova l’origine del pixel di input (12, 30).

- Matrice $T^{-1}$:
$T^{-1} = \begin{pmatrix} 0.5 & 0 & 0 \\ 0 & 0.5 & 0 \\ 0 & 0 & 1 \end{pmatrix}$
- **Calcolo:**
    ◦ $v = 12 \cdot 0.5 = \mathbf{6}$
    ◦ $w = 30 \cdot 0.5 = \mathbf{15}$
- **Risultato:** Il colore viene preso da (6, 15)

---

Esercizio 3: Trasformazione Composta 

**Problema**:  L'immagine è stata spostata di +6 (x) e poi ingrandita di 2. Trova l'origine del pixel (20, 10).

- Matrice $T^{-1}$:
$T^{-1} = \begin{pmatrix} 0.5 & 0 & 0 \\ 0 & 0.5 & 0 \\ -6 & 0 & 1 \end{pmatrix}$
- **Calcolo:**
    ◦ $v = (20 \cdot 0.5) - 6 = 10 - 6 = \mathbf{4}$
    ◦ $w = (10 \cdot 0.5) = \mathbf{5}$
- **Risultato:** Il colore viene preso da (4, 5)