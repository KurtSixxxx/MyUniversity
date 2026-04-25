1. Riassunto: Cosa Abbiamo Visto Finora
La Logica dei Predicati ci permette di parlare di un mondo fatto di:

Individui (persone, oggetti, numeri...)
Relazioni tra questi individui (essere più alto di, amare, essere figlio di...)

2. Segnatura (Σ) - Il Nostro "Vocabolario"
La segnatura è come un dizionario che elenca tutti i simboli che useremo:
Σ = { 
  Simboli di Funzione: {h², g¹, r⁰},
  Simboli di Relazione: {Q³, P¹, R²}
}
Cosa significano:

r⁰: una costante (es. "Mario")
g¹: funzione che prende 1 argomento (es. "la mamma di...")
h²: funzione che prende 2 argomenti (es. "il figlio di ... e ...")
P¹: proprietà di 1 individuo (es. "... è alto")
R²: relazione tra 2 individui (es. "... ama ...")
Q³: relazione tra 3 individui (es. "... ha dato ... a ...")

3. Termini - Chi Stiamo Considerando
I termini rappresentano gli individui. Possiamo costruirli così:
Esempi:

r (Mario)
x, y, z (persone generiche - variabili individuali)
g(x) (la mamma di x)
h(g(r), r) (il figlio della mamma di Mario e Mario stesso)


Punto chiave: Le variabili x, y, z sono "segnaposto" per individui generici!

4. Formule Ben Formate (fbf) - Le Nostre Affermazioni
Le fbf sono frasi che possono essere vere o false:
Esempi:

P(x) ("x ha la proprietà P")
R(x, g(x)) ("x è in relazione R con sua mamma")
∀x P(x) ("tutti hanno la proprietà P")
∃x P(x) ("qualcuno ha la proprietà P")

Quantificatori

∀x = "per ogni x" (quantificatore universale)
∃x = "esiste un x tale che" (quantificatore esistenziale)
Relazione: ∃x α ≡ ¬∀x ¬α (esistere = non è vero che per tutti non vale)

5. α-Conversione - Cambiare Nome alle Variabili
Queste due formule dicono la stessa cosa:

∀x R(x, g(x))
∀y R(y, g(y))

Entrambe significano: "Per ogni individuo, quell'individuo è in relazione R con la sua mamma"

Il nome della variabile quantificata (x o y) non importa - è solo un "segnaposto"!

6. LA PARTE NUOVA: Come Dare Significato Concreto (Semantica)
Fino ad ora abbiamo visto la sintassi (come scrivere le formule). Ora vediamo la semantica (cosa significano nel mondo reale).
6.1 Struttura (o Modello) A_Σ
Una struttura è un mondo concreto che dà significato ai nostri simboli:
A_Σ = ⟨A, F, P⟩
Dove:
A - L'Universo degli Individui
A è l'insieme di tutti gli individui che esistono nel nostro mondo.
Esempio: A = {Mario, Luigi, Peach, Bowser}
F - Interpretazione delle Funzioni
Per ogni simbolo di funzione nella segnatura, F specifica cosa fa quella funzione.
Esempio: Se g¹ è "la mamma di...", allora:
g̃¹: A → A
g̃¹(Mario) = Peach
g̃¹(Luigi) = Peach  
g̃¹(Peach) = ?     (bisogna specificarlo)
La funzione g̃¹ (g con la tilde) è l'interpretazione concreta di g¹.
P - Interpretazione delle Relazioni
Per ogni simbolo di relazione, P specifica quando quella relazione è vera.
Esempio: Se R² è "ama", allora:
R̃²: A × A → {0, 1}  (0 = falso, 1 = vero)
R̃²(Mario, Peach) = 1    (Mario ama Peach)
R̃²(Bowser, Peach) = 1   (anche Bowser ama Peach)
R̃²(Mario, Mario) = 0    (Mario non ama se stesso)
6.2 Ambiente (p) - A Chi Corrispondono le Variabili
L'ambiente p ci dice a quale individuo concreto corrisponde ogni variabile:
p: {variabili} → A
Esempio:
p(x) = Mario
p(y) = Luigi
p(z) = Peach
Quindi quando scriviamo R(x, y), con questo ambiente significa R(Mario, Luigi).
7. Come Valutare le Formule
Ora possiamo calcolare se una formula è vera o falsa!
Per i Termini:

[[x]]_p = p(x) (il valore di x secondo l'ambiente p)
[[g(t)]]_p = g̃([[t]]_p) (applica la funzione g al valore di t)

Per le Formule:

[[R(t₁, t₂)]]_p = R̃([[t₁]]_p, [[t₂]]_p) (applica la relazione R)
[[∀x α]]_p = 1 se α è vera per tutti i possibili valori di x
[[∃x α]]_p = 1 se α è vera per almeno un valore di x

8. Esempio Completo
Segnatura: Σ = {{mamma¹}, {Ama²}}
Struttura: A = {Mario, Luigi, Peach}

mamma(Mario) = Peach
mamma(Luigi) = Peach
mamma(Peach) = ? (non specificato)
Ama(Mario, Peach) = vero
Ama(Luigi, Peach) = falso

Formula: ∀x Ama(x, mamma(x)) ("tutti amano la loro mamma")
Valutazione:

Ama(Mario, mamma(Mario)) = Ama(Mario, Peach) = vero ✓
Ama(Luigi, mamma(Luigi)) = Ama(Luigi, Peach) = falso ✗

Risultato: La formula è falsa perché Luigi non ama sua mamma!
Riassunto dei Concetti Chiave

Segnatura: Il nostro vocabolario di simboli
Termini: Rappresentano individui (concreti o generici)
Formule: Affermazioni che possono essere vere o false
Struttura: Un mondo concreto che dà significato ai simboli
Ambiente: Assegna individui concreti alle variabili
Valutazione: Come calcolare se una formula è vera o falsa

La bellezza della logica dei predicati è che separa la sintassi (come scrivere) dalla semantica (cosa significa), permettendoci di ragionare in modo preciso e generale!