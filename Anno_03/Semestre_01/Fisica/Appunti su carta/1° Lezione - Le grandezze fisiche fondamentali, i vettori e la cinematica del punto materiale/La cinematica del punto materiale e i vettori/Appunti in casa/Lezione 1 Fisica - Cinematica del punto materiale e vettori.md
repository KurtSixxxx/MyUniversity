# Lezione 1 Fisica - Cinematica del punto materiale e vettori

---

# LEZIONE COMPLETA – CINEMATICA DEL PUNTO MATERIALE

## 1. Il punto materiale e la cinematica

La fisica studia i fenomeni del mondo reale: corpi che cadono, pianeti che orbitano, oggetti che si muovono, forze, campi, energia.  
Ma se volessimo descrivere ogni singolo dettaglio (le viti di un’auto, le onde sull’acqua di una nave), diventeremmo matti.  
Per questo, la fisica introduce una **semplificazione geniale**: il **punto materiale**.

Un **punto materiale** è un corpo di cui non consideriamo le dimensioni o la forma, ma solo **la posizione**.  
Una nave nel mare, una macchina in autostrada, un pallone che vola: in molti casi ci basta sapere *dove si trova*, non com’è fatto.  
Trattiamo dunque tutto come un “puntino” nello spazio.

La parte della fisica che studia **come cambia la posizione di un punto nel tempo** si chiama **cinematica**.  
Essa non spiega *perché* il corpo si muove (quello è compito della dinamica), ma solo *come* si muove: lungo quale traiettoria, con che velocità, con che accelerazione.

---

## 2. Il sistema di riferimento e le coordinate

Per descrivere la posizione di un punto bisogna prima stabilire un **sistema di riferimento**, cioè un insieme di assi rispetto ai quali misuriamo tutto.  
Il più usato è il **sistema cartesiano** tridimensionale, formato da tre assi perpendicolari tra loro: X, Y e Z.

Un punto nello spazio ha coordinate $(x, y, z)$, che rappresentano le sue distanze dagli assi.  
Ecco perché si dice che un punto materiale nello spazio ha **tre gradi di libertà**: può muoversi liberamente in tre direzioni indipendenti.  
Se lo costringiamo a muoversi su un piano, i gradi di libertà diventano due; se lo costringiamo su una linea (per esempio un binario), resta un solo grado di libertà.

In generale:

- 3 gradi di libertà → moto nello spazio $(x, y, z)$

- 2 gradi di libertà → moto su un piano $(x, y)$

- 1 grado di libertà → moto su una linea $(x)$

---

## 3. La distanza tra due punti

Se abbiamo due punti A(xₐ, yₐ, zₐ) e B(x_b, y_b, z_b), la **distanza** che li separa si trova con il teorema di Pitagora esteso allo spazio:

$d=\sqrt{(xb​−xa​)2+(yb​−ya​)2+(zb​−za​)2}​$

Questa formula deriva semplicemente dall’idea che, in tre dimensioni, la distanza è la radice della somma dei quadrati delle differenze di posizione lungo ogni asse.

---

## 4. I vettori: rappresentare direzione e verso

Per studiare un movimento, non basta dire “quanto si muove” un punto, ma bisogna dire anche *in che direzione*.  
Una grandezza che ha solo valore numerico (come massa, tempo, temperatura) si chiama **scalare**.  
Una grandezza che invece ha anche direzione e verso (come spostamento, velocità, forza) si chiama **vettoriale**.

Un **vettore** è una freccia:

- La **lunghezza** della freccia rappresenta il **modulo** (cioè quanto vale la grandezza).

- La **retta su cui giace** la freccia rappresenta la **direzione**.

- La **punta** indica il **verso**.

Esempio: una velocità di 5 m/s verso nord non è la stessa di 5 m/s verso est.  
Hanno lo stesso modulo, ma direzione diversa.

Un vettore nello spazio si rappresenta come:

$\overrightarrow{v}=(v_x​,v_y​,v_z​)$

dove le componenti $v_x​,v_y​,v_z$​ indicano “quanto” del vettore è proiettato su ciascun asse.

---

## 5. Somma e differenza di vettori

I vettori si possono sommare e sottrarre:

$\overrightarrow{A}+\overrightarrow{B}=(A_x​+B_x​,A_y​+B_y​,A_z​+B_z​)$

$\overrightarrow{A}-\overrightarrow{B}=(A_x​-B_x​,A_y​-B_y​,A_z​-B_z​)$

Graficamente, per sommare due vettori, metti la **coda del secondo** sulla **punta del primo**: la diagonale che li unisce rappresenta il vettore somma.  
Per la differenza, invece, li unisci “punta con punta”: il vettore differenza va dalla punta di uno alla punta dell’altro.

Queste operazioni ti servono per calcolare spostamenti, variazioni di velocità, accelerazioni, e più avanti anche forze risultanti.

---

## 6. Prodotto scalare e angolo tra due vettori

Quando vuoi sapere quanto due vettori “puntano nella stessa direzione”, usi il **prodotto scalare**:

$\overrightarrow{A}\cdot\overrightarrow{B}=A_x​B_x​+A_y​B_y​+A_z​B_z​=∣\overrightarrow{A}∣∣\overrightarrow{B}∣cos\theta$

Il risultato non è un vettore ma un **numero (scalare)**.  
Serve per trovare l’**angolo θ** tra i due vettori:

- Se $\theta$=0°, i vettori sono paralleli e il prodotto è massimo.

- Se $\theta$=90°, sono perpendicolari e il prodotto è 0.

Questo concetto è fondamentale per capire la relazione tra **forze e spostamento**, perché da qui deriva il concetto di **lavoro** in fisica $(W = F \cdot s)$.

---

## 7. Spostamento e velocità media

Ora entriamo nella parte centrale della cinematica.  
Se un punto materiale si muove, la sua **posizione** cambia nel tempo.  
Chiamiamo $\overrightarrow{r}(t)$ il vettore posizione del punto al tempo t.  
Se al tempo $t_1$ si trova in A e al tempo $t_2$ in B, lo **spostamento** è:

$\Delta \overrightarrow{r}=\overrightarrow{r}(t_2​)−\overrightarrow{r}(t_1​)$

Questo vettore rappresenta la freccia che unisce il punto A con il punto B.  
La **velocità media** tra quei due istanti è:

$\overrightarrow{v}_{media​}=\frac{\Delta \overrightarrow{r}}{\Delta \overrightarrow{t}}​$

dove $\Delta t = t_2 - t_1$ è il tempo trascorso.

Ma questa è una media: non ci dice quanto “andava veloce” in un preciso istante, solo il valore medio nel tratto.

---

## 8. Dal moto medio al moto istantaneo: il limite di Δt→0

Ecco il punto più importante e il più bello da capire.

Se vuoi sapere **la velocità esatta in un istante preciso**, devi fare una cosa:  
immaginare che l’intervallo di tempo $\Delta t$ diventi sempre più piccolo.  
Così anche lo spostamento $\Delta r$ diventa sempre più corto, finché la freccia che univa i due punti diventa **tangente alla traiettoria**.

In quel momento ottieni la **velocità istantanea**:

$$
\overrightarrow{r} = \lim_{\Delta t \to 0} \frac{\Delta \overrightarrow{r}}{\Delta t} = \frac{d \overrightarrow{r}}{dt}
$$

Questa è la **derivata vettoriale** della posizione rispetto al tempo.  
In parole semplici:

> “la velocità è la variazione infinitamente piccola della posizione per unità di tempo.”

Il vettore velocità è **sempre tangente alla traiettoria** del punto in moto, e il suo verso è quello del moto.

---

## 9. Accelerazione

La velocità stessa può cambiare nel tempo, sia nel valore (più veloce o più lenta) sia nella direzione (una curva).  
L’**accelerazione** misura proprio quanto e come cambia la velocità:

$$
\overrightarrow{a} = \frac{d \overrightarrow{v}}{dt}  = \frac{d^2\overrightarrow{r}}{dt^2}
$$

Un’accelerazione costante (come la gravità) indica che la velocità aumenta di uguale quantità in ogni secondo.  
Se invece il corpo curva mantenendo lo stesso modulo di velocità, l’accelerazione cambia solo la direzione.

---

## 10. Riepilogo visivo (immagina così)

- Disegna una curva qualsiasi: quella è la **traiettoria** del punto materiale.

- Dal centro degli assi, traccia una freccia fino a un punto sulla curva: quella è $\overrightarrow{r}(t1​)$.

- Poi tracciane un’altra verso un punto vicino: $\overrightarrow{r}(t2​)$.

- La differenza tra le due punte è lo spostamento $\Delta r$.

- Dividilo per $\Delta t$: ottieni la velocità media.

- Ora avvicina i due punti sempre più fino a farli coincidere → il vettore $\Delta r$ diventa tangente → questa è la velocità istantanea.

- Se la velocità cambia, disegna un piccolo vettore che rappresenta come cambia nel tempo → quello è l’accelerazione.

---

## 11. Cosa hai imparato

- Il **punto materiale** è un modello per semplificare lo studio del moto.

- Le **coordinate** (x, y, z) servono per definire la posizione e i gradi di libertà.

- I **vettori** descrivono grandezze con direzione e verso.

- Lo **spostamento** è la variazione di posizione.

- La **velocità media** è $\Delta r / \Delta t$, ma la **velocità istantanea** si ottiene con il limite $\Delta t \rightarrow 0$.

- L’**accelerazione** è la derivata della velocità, cioè quanto rapidamente cambia la velocità.

Tutto questo è la base della **cinematica del punto materiale**: da qui in poi studierai i casi particolari di moto rettilineo, uniforme, accelerato e circolare.
