# Esame di Interazione e Multimedia

## Laboratorio Processing - 27 Febbraio 2026

**Tempo a disposizione:** 120 minuti
**Note:** Usare solo l'editor interno e le Reference. Non è consentito l'uso di librerie esterne.

---

### [17] Esercizio 1

Si implementino in Processing le seguenti **classi** con le caratteristiche dichiarate:

* **Classe Bullet**:
  
  * Identificato da una **posizione (x,y)**, una **velocità** di spostamento rispetto a x (**sx**) e da un **colore**.
  * Appare come un cerchio di raggio **10 pixel**, senza bordi e del colore che lo caratterizza.
  * Deve prevedere una funzione che ad ogni ciclo di `draw()` modifica la propria posizione di un valore pari alla sua velocità.

* **Classe Warp**:
  
  * Identificato da una **posizione**, un **colore** e una **velocità**.
  * Appare formato da **3 cerchi concentrici** di raggio 35, 30 e 25 rispettivamente.
  * Il cerchio più esterno è nero, il secondo è grigio e il terzo (più interno) è del colore caratteristico del Warp.
  * Al centro è indicata la velocità dello stesso tramite testo bianco di grandezza 40.
  * **Funzione shot()**: genera un `Bullet` del colore del Warp che si muove verso destra alla velocità indicata dal Warp. La posizione iniziale del Bullet corrisponde a quella del Warp.
  * **Funzione di verifica**: permette di verificare se il puntatore del mouse si trova all'interno del cerchio colorato (quello più piccolo). Il Warp è fermo.

**Implementazione dello sketch:**

1. Finestra 600x600, sfondo bianco.
2. Parametro intero **K**. Istanziare **K Warp** con coordinate casuali (tra 50 e 550) e colori RGB casuali.
3. In `draw()`: aggiornare la finestra e muovere tutti i Bullet presenti.
4. Al click del mouse: se il click avviene all'interno del cerchio colorato di un Warp, quel Warp deve generare un nuovo Bullet tramite `shot()`.

---

### [15] Esercizio 2

Si implementi in Processing la seguente **funzione**:

* **saltPepper(PImage I, float k)**:
  * **Input**: Un'immagine RGB e un numero `k` compreso tra 0 e 100.
  * **Output**: Una nuova immagine RGB con aggiunta di rumore "sale e pepe".
  * **Regole**:
    * Un pixel diventa **bianco** (sale) con probabilità pari a **k/2**.
    * Un pixel diventa **nero** (pepe) con probabilità pari a **k/2**.
    * Il resto dei pixel rimane invariato.

(Nota: il testo nell'immagine nell'ultima riga dell'esercizio 2 è parzialmente tagliato, ma il senso logico del rumore sale e pepe implica la probabilità speculare per il nero).