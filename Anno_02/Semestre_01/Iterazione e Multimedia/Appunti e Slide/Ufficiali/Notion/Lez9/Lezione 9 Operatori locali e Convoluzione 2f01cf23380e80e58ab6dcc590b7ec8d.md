# Lezione 9: Operatori locali e Convoluzione

### Base Canonica

La **base canonica** è l'insieme dei vettori più semplici che esistono per costruire tutti gli altri vettori di uno spazio. In pratica, sono i "mattoncini fondamentali" dove ogni mattoncino ha il valore **1** in una posizione e **0** in tutte le altre.
Dato un vettore di lunghezza N, scomponiamo andando a moltiplicare il numero per una base formata da tutti zeri tranne il numero 1 che si trova nella posizione equivalente a dov'era il numero prima:

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%201.png)

Base canonica è una possibile base, ne esistono anche altre tipo la base della trasformata del coseno.

**Lo stesso ragionamento vale anche per le immagini**, immaginiamo una matrice 3x3 che rappresenta la nostra immagine. Ad ogni cella viene associato un numero, e poi si fa la stessa applicazione che viene fatta per il vettore. Ossia: la cella che equivale alla posizione del numero che stiamo analizzando, vale 1, tutte le altre zero.
Dunque abbiamo una **somma di prodotti**.
Il processo da fare è:
individuare il numero e sostituirlo con 1, in tutte le altre mettere 0, e moltiplicare per il numero, poi sommare con gli altri prodotti degli altri numeri. Come vedi nella immagine qui sotto:

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%202.png)

### Operatori locali

Sono quegli operatori in cui il valore di un pixel in output, un solo pixel, dipende dall'equivalente valore del pixel di input, ma anche dell'**intorno** di questo pixel; quindi dei pixel che gli stanno vicini.
Quanto deve essere grande l'intorno? Dipende dall'operatore. Vi sono operatori 3x3, 5x5, 7x7, 3x5, 5x3. La dimensione è legata all'operatore che utilizziamo.
Noi studieremo operatori che utilizzano **dimensioni dispari**, perché è più facile **trovare il centro e dunque tutti i pixel che stanno intorno ad esso**.
[fare esempio con disegno di matrice 2x2 dove non c'è il centro e una 3x3 dove c'è il centro]
Quello che a noi interessa è prendere il pixel centrale della matrice, che è il perno su cui si basa l'operazione.

Una osservazione importante da fare è che se l'operatore locale che utilizziamo è 3x3 o 5x5 non cambia nulla nel tipo di operazione che voglio fare io, cambierà solo il risultato. L'unica differenza sta nell'intorno che usiamo: se abbiamo una matrice 3x3 abbiamo un intorno di 9px, se abbiamo una matrice 5x5 abbiamo un intorno di 25px.

### Operatori Lineari

Parliamo di operatori lineari ma facciamo una premessa: Prendiamo un operatore lineare, ma non è detto che gli operatori non lineari non siano buoni o non sono operatori locali, lo sono pure.

Un operatore è lineare, se presa la funzione $F : V \rightarrow W$, scrivere:

$$
F(a \cdot v_1 + b \cdot v_2) = a \cdot F(v_1) + b \cdot F(v_2)
$$

$v_1$ e $v_ 2$ sono una coppia di vettori in $V$, e $a,b$ sono una coppia di scalari.

Uno **scalare** è semplicemente un numero, che ha il compito di “scalare” le cose. Se hai un vettore (o una lista di pixel) e lo moltiplichi per uno scalare (ad esempio 2), quel vettore diventa "in scala" due volte più grande.

Quella a cui faremo rifermento noi è questa:

$$
a \cdot f(x_1,y_1)+b \cdot f(x_2,y_2)=f(ax_1+bx_2,ay_1+by_2)
$$

Cosa vuol dire "**lineare**"? Pensala come una **trasformazione onesta e prevedibile**.
Immagina di avere due punti su un foglio. Se li sommi (o li combini) e POI applichi la trasformazione, dovresti ottenere lo stesso risultato che otterresti applicando prima la trasformazione a ciascuno e POI sommandoli. Se la regola è "onesta", il risultato deve essere lo stesso in entrambi i casi.

La formula significa che l'uguaglianza deve essere soddisfatto. Quindi primo e secondo membro devono avere uguale valore

**Esempi:**
1° Esempio: la funzione $f(x,y) = (\frac{x}{2}, \frac{y}{3})$ è lineare? SI
Per essere lineare dovrebbe verificarsi l'uguaglianza:

$$
a \cdot f(x_1,y_1)+b \cdot f(x_2,y_2)=f(ax_1+bx_2,ay_1+by_2)
$$

L'obiettivo è dimostrare che il **Primo Membro** e il **Secondo Membro** dell'uguaglianza di linearità sono identici.

**Step 1: Capire la funzione $f(x,y)$**
La funzione prende una coppia $(x, y)$ e:

- Divide il primo numero per $2$.
- Divide il secondo numero per $3$.
Esempio: se l'input è $(10, 30)$, l'output è $(\frac{10}{2}, \frac{30}{3}) = (5, 10)$.

**Step 2: Analisi del Primo Membro $a \cdot f(x_1, y_1) + b \cdot f(x_2, y_2)$**
Questo significa: "applica la funzione ai punti separatamente, moltiplicali per $a$ e $b$, e poi somma tutto".

1. Applichiamo la funzione ai due punti:
$f(x_1, y_1) = (\frac{x_1}{2}, \frac{y_1}{3})$
$f(x_2, y_2) = (\frac{x_2}{2}, \frac{y_2}{3})$
2. Moltiplichiamo per $a$ e $b$:
$a \cdot (\frac{x_1}{2}, \frac{y_1}{3}) = (\frac{a \cdot x_1}{2}, \frac{a \cdot y_1}{3}) \\
b \cdot (\frac{x_2}{2}, \frac{y_2}{3}) = (\frac{b \cdot x_2}{2}, \frac{b \cdot y_2}{3})$
3. Sommiamo i risultati (primo con primo, secondo con secondo):
$(\frac{a \cdot x_1}{2} + \frac{b \cdot x_2}{2}, \quad \frac{a \cdot y_1}{3} + \frac{b \cdot y_2}{3})$
**[Risultato del Primo Membro]**

**Step 3: Analisi del Secondo Membro $f(a x_1 + b x_2, a y_1 + b y_2)$**
Questo significa: "combina prima i punti e poi applica la funzione all'intero blocco".

1. L'input unico per la funzione è la coppia: $(a x_1 + b x_2, \quad a y_1 + b y_2)$.
2. La funzione f deve dividere il primo blocco per $2$ e il secondo blocco per $3$:
$f( \text{blocco1}, \text{blocco2} ) = ( \frac{\text{blocco1}}{2}, \frac{\text{blocco2}}{3} )$
3. Inseriamo i nostri blocchi:
$(\frac{a x_1 + b x_2}{2}, \quad \frac{a y_1 + b y_2}{3})$
**[Risultato del Secondo Membro]**

**Step 4: Il confronto finale (Perché sono uguali?)**
Dobbiamo capire se le due espressioni dicono la stessa cosa. Usiamo una regola delle frazioni: $\frac{A+B}{C} = \frac{A}{C} + \frac{B}{C}$.

- **Secondo Membro:** $(\frac{a x_1 + b x_2}{2}, \quad \frac{a y_1 + b y_2}{3})$
- Se "spezziamo" le frazioni del Secondo Membro otteniamo:
$(\frac{a x_1}{2} + \frac{b x_2}{2}, \quad \frac{a y_1}{3} + \frac{b y_2}{3})$

Questo è **esattamente identico** al risultato che abbiamo ottenuto nello Step 2 (il Primo Membro).

**Risposta finale**
Poiché il Primo Membro $a \cdot f(x_1, y_1) + b \cdot f(x_2, y_2)$ produce lo stesso identico risultato del Secondo Membro $f(ax_1+bx_2, ay_1+by_2)$, la condizione di linearità è soddisfatta. La funzione è **lineare**.

Il concetto chiave è la **Linearità**. Una funzione è lineare se "rispetta" le somme e le moltiplicazioni per costanti.

In termini semplici:

1. **Omogeneità:** Se raddoppi l'input, il risultato raddoppia. $\frac{2x}{2}$ è uguale a $2 \cdot \frac{x}{2}$.
2. **Additività:** Il risultato della somma è uguale alla somma dei risultati. $\frac{x_1+x_2}{2}$ è uguale a $\frac{x_1}{2} + \frac{x_2}{2}$.

2° Esempio: La funzione $f(x,y)=(255-x,255-y)$ è lineare? NO
Per essere lineare dovrebbe verificarsi l'uguaglianza:
a \$cdot f(x_1,y_1)+b \cdot f(x_2,y_2)=f(ax_1+bx_2,ay_1+by_2)$

**Smontiamo i simboli:**

- $f$: La tua "macchina" di trasformazione.
- $(x_₁, y_₁)$ e $(x_₂, y_₂)$: Sono due punti qualsiasi. Pensali come due pixel in posizioni diverse, ognuno con le sue coordinate di colore.
- $a$ e $b$: Sono due numeri qualsiasi (pesi). Servono per fare combinazioni (ad esempio, se $a=1$ e $b=1$, stai sommando; se $a=0.5$ e $b=0.5$, stai facendo una media).
- Il **PRIMO MEMBRO** ($a\cdot f(x_₁,y_₁) + b \cdot f(x_₂,y_₂)$): Significa: **"Applica la funzione $f$ a ciascun punto SEPARATAMENTE, poi combina i risultati usando $a$ e $b$."**
- Il **SECONDO MEMBRO** ($f(a \cdot x_₁+b \cdot x_₂, a \cdot y_₁+b \cdot y_₂)$): Significa: **"PRIMA combina i due punti originali usando $a$ e $b$, e POI applica la funzione $f$ UNA sola volta al risultato combinato."**

Se l'uguaglianza è vera, la funzione è lineare. Se è falsa, non lo è.

Ora verifichiamolo per la funzione: $f(x, y) = (255 - x, 255 - y)$.

**PASSAGGIO 1: Calcoliamo il PRIMO MEMBRO**

Partiamo da: $a \cdot f(x_₁, y_₁) + b \cdot f(x_₂, y_₂)$

**Sottopassaggio 1A: Calcoliamo $f(x_₁, y_₁)$ e $f(x_₂, y_₂)$**

- Per definizione, $f(x_₁, y_₁) = (255 - x_₁, 255 - y_₁)$.
- Allo stesso modo, $f(x_₂, y_₂) = (255 - x_₂, 255 - y_₂)$.

**Sottopassaggio 1B: Moltiplichiamo per $a$ e $b$**
Moltiplicare una coppia per un numero significa moltiplicare **entrambi** i numeri nella coppia.

- $a \cdot f(x_₁, y_₁) = a \cdot (255 - x_₁, 255 - y_₁) = (a\cdot(255 - x_₁), a\cdot(255 - y_₁))$
Ora applichiamo la **proprietà distributiva** (il numero $a$ "entra" in entrambi i termini dentro la parentesi):
    - $a \cdot (255 - x_₁)$ diventa $a \cdot 255 - a \cdot x_₁$
    - $a \cdot (255 - y_₁)$ diventa $a \cdot 255 - a \cdot y_₁$
    Quindi: $a \cdot f(x_₁, y_₁) = (a\cdot 255 - a\cdot x_₁, a \cdot 255 - a\cdot y_₁)$
- Allo stesso modo: $b \cdot f(x_₂, y_₂) = (b\cdot255 - b\cdot x_₂, b\cdot255 - b\cdot y_₂)$

**ESEMPIO NUMERICO (per fissare l'idea):**
Poniamo $a=2$, $x_₁=10$, $y_₁=20$.
$2 \cdot f(10, 20) = 2 \cdot (255-10, 255-20) = 2 \cdot (245, 235) = (2\cdot245, 2\cdot235) = (490, 470)$.
Usando la formula con la distributiva: $(2\cdot255 - 2\cdot10, 2\cdot255 - 2\cdot20) = (510 - 20, 510 - 40) = (490, 470)$. È lo stesso!

**Sottopassaggio 1C: Sommiamo i due risultati**
Per sommare due coppie, sommiamo i primi componenti tra loro e i secondi componenti tra loro.

Primo membro = $(a\cdot255 - a\cdot x_₁, a\cdot255 - a\cdot y_₁) + (b\cdot255 - b\cdot x_₂, b\cdot255 - b\cdot y_₂)$
= $(a\cdot255 - a\cdot x_₁ + b\cdot255 - b\cdot x_₂, a\cdot255 - a\cdot y_₁ + b\cdot255 - b\cdot y_₂)$

Raggruppiamo i termini con $255$:
**PRIMO MEMBRO FINALE:** $(a\cdot255 + b\cdot255 - a\cdot x_₁ - b\cdot x_₂, a\cdot255 + b\cdot255 - a\cdot y_₁ - b\cdot y_₂)$

**PASSAGGIO 2: Calcoliamo il SECONDO MEMBRO**

Partiamo da: $f(a\cdot x_₁ + b\cdot x_₂, a\cdot y_₁ + b\cdot y_₂)$

**Sottopassaggio 2A: Capiamo l'input della funzione**
L'input non è più un semplice $x$ e $y$. È una **combinazione**:

- Il primo input è: $(a\cdot x_₁ + b\cdot x_₂)$
- Il secondo input è: $(a\cdot y_₁ + b\cdot y_₂)$

**Sottopassaggio 2B: Applichiamo la regola $f$ a questo input**
La regola $f$ dice: prendi il primo input, calcola $255 - (\text{primo input})$. Prendi il secondo input, calcola $255 - (\text{secondo input})$.

Quindi:
$f(a\cdot x_₁ + b \cdot x_₂, a \cdot y_₁ + b \cdot y_₂) = (255 - (a \cdot x_₁ + b  \cdot x_₂), 255 - (a*y_₁ + b \cdot y_₂))$

**Sottopassaggio 2C: Semplifichiamo (togliamo le parentesi interne)**
$255 - (a\cdot x_₁ + b \cdot x_₂)$ significa $255 - a\cdot x_₁ - b \cdot x_₂$. Il segno $-$ davanti alla parentesi cambia il segno di TUTTI i termini dentro.
Stessa cosa per l'altro componente: $255 - (a\cdot y_₁ + b\cdot y_₂) = 255 - a \cdot y_₁ - b \cdot y_₂$.

**SECONDO MEMBRO FINALE:** $(255 - a \cdot x_₁ - b \cdot x_₂, 255 - a \cdot y_₁ - b \cdot y_₂)$

**PASSAGGIO 3: Confrontiamo i Due Membri**

Mettiamoli uno sotto l'altro:

- **Primo Membro:** $(a\cdot255 + b\cdot255 - a\cdot x_₁ - b\cdot x_₂, a\cdot255 + b\cdot255 - a\cdot y_₁ - b \cdot y_₂)$
- **Secondo Membro:** $(255 - a\cdot x_₁ - b\cdot x_₂, 255 - a \cdot y_₁ - b\cdot y_₂)$

**Osserva la differenza CHIAVE:**
Nel primo membro, davanti a $255$ ci sono $a$ e $b$ che lo moltiplicano: $a\cdot255 + b\cdot255$.
Nel secondo membro, il $255$ è solo, **non è moltiplicato per $a$ e $b$**.

**Conclusione:** I due membri **NON sono uguali**. Perché? Perché nel primo membro la "costante 255" viene pesata con $a$ e $b$, mentre nel secondo membro la "costante 255" compare una volta sola, indipendentemente da $a$ e $b$.

**Esempio Numero Finale per Distruggere Ogni Dubbio:**
Poniamo $a=1$, $b=1$, $x_₁=0$, $y_₁=0$, $x_₂=0$, $y_₂=0$.

- Primo Membro: $(1\cdot 255 + 1\cdot 255 - 0 - 0, 1\cdot 255 + 1\cdot 255 - 0 - 0) = (510, 510)$
- Secondo Membro: $(255 - 0 - 0, 255 - 0 - 0) = (255, 255)$

**510 è diverso da 255!** Basta questo controesempio per dire che l'uguaglianza non è vera per tutti i numeri. Quindi, **la funzione NON È LINEARE**.

**IL SIGNIFICATO: Perché il "255" la Rende Non Lineare?**

Quel $255$ è una **traslazione** (uno spostamento). Le funzioni lineari "pure" passano sempre per l'origine (0,0). La tua funzione, invece, fa questo:

1. Prende il punto $(x, y)$.
2. Lo "ribalta" cambiandone il segno (da $x$ a $x$).
3. Poi lo **sposta** di 255 unità (fa $x + 255$).

Il metodo:

1. Scrivi i due membri dell'uguaglianza.
2. Sostituisci la definizione di $f$.
3. Sviluppa i calcoli con molta pazienza (distributiva, somma di coppie).
4. Confronta. Se vedi che i termini costanti (come $255$) si comportano in modo diverso, la funzione non è lineare.

### Invariate per traslazione (shift invariant)

Un operatore si dice **invariante per traslazione** quando il suo comportamento sulle immagini impulsive è sempre il medesimo indipendentemente dalla posizione in cui si trova il pixel.

Immagina di avere un filtro che "sfoca" l'immagine.

- Se applichi il filtro a un volto che si trova in **alto a sinistra**, ottieni un volto sfocato.
- Se sposti (**trasli**) quel volto in **basso a destra** e applichi lo stesso filtro, ti aspetti di ottenere lo stesso identico risultato, solo in una posizione diversa.

Se il filtro si comporta **sempre nello stesso modo** a prescindere da dove si trova l'oggetto, allora si dice **Invariante per Traslazione**.

- **Esempio di operatore NON invariante:** Un filtro che sfoca tantissimo i bordi dell'immagine ma lascia nitido il centro. Qui il comportamento **varia** a seconda della posizione (se sei al centro o se sei al bordo). Questo è difficile da studiare perché devi conoscere una regola diversa per ogni punto dell'immagine.
- **Operatore Invariante (Quello "buono"):** La regola è la stessa per tutti. Se sai cosa fa a un singolo pixel (l'impulso) al centro, sai cosa farà a tutti gli altri pixel in ogni posizione.
- **Tutti gli operatori puntuali sono invarianti per traslazione (anche se non sono lineari).**

Ricordiamo l’operatore puntuale per fare il negativo di un’immagine, consiste nell’associare al valore $f(x,y)$ del pixel il valore $255-f(x,y)$.
Cosa fa? L’operatore prende il valore di grigio nel punto $(x,y)$ e lo sottrae a $255$. Questo comportamento è sempre lo stesso per tutti i medesimi livelli, indipendentemente dalla posizione che occupano nell’immagine. Quindi è invariante per traslazione.

ATTENZIONE. La funzione $f(x,y)=(255-x,255-y)$ NON è la funzione negativo!

### Schema di descrizione di F

- F lineare: per descriverlo basta conoscere il comportamento su tutte le immagini impulsive.
- F shift invariant: si comporta allo stesso modo su tutti gli impulsi, indipendentemente dalla loro posizione
- F lineare e shift invariant: per descriverlo basta conoscere come si comporta su un solo impulso.

La “**risposta all’impulso**” o “**point spread function**” di F è la carta di indentità di tale operatore.

**Cos'è un "Impulso"?**
I**Impulso** (o PSF: point spread funciont) è un altro modo per chiamare un elemento della base canonica.
• **L'idea visiva:** Immagina un'immagine completamente nera (tutti 0) dove all'improvviso, in un solo punto, c'è un pixel bianco (valore 1). Quel singolo pixel bianco "acceso" è l'impulso.
• **A cosa serve?** Si usa per testare i filtri. È come dare un colpetto (un impulso) a una campana per sentire come suona. Se diamo un "impulso" (un pixel bianco) a un filtro, vediamo come quel filtro "risponde" distribuendo quel bianco intorno.

Ad ogni operatore lineare e shift variant corrisponde una **maschera**, e viceversa, ossia che ad ogni maschera corrisponde un simile operatore.

**Esempio**

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%203.png)

Tale “risposta all’impulso” o PSF definisce completamente un operatore lineare e invariante per traslazioni F. Spesso un operatore su una immagine prende il nome di “**filtro**”.

Tale maschera si chiama spesso **kernel** o **maschera di convoluzione**.
Il kernel, o maschera, è come una piccola tabella che viene applicata all'immagine durante la convoluzione. È proprio quella che definisce come verranno modificati i pixel, ad esempio per sfocare, accentuare i contorni o altro.
La grandezza del kernel può variare fino ad essere infinito, ma per ragioni pratiche vengono usati solo kernel di dimensioni finite.
Le dimensioni del kernel influenzano la complessità dell’operatore di filtraggio.
È importante sapere che la complessità dipende anche dal numero di pixel dell’immagine

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%204.png)

## Convoluzione

È un'operazione matematica, e in pratica, combina due funzioni per crearne una nuova, mostrandoti come la forma di una influisce sull'altra.

I filtri lineari e invarianti per traslazione vengono chiamati anche filtri convolutivi.
Esistono infatti le operazioni di convoluzione per capire come un filtro può essere calcolato.

### Proprietà della convoluzione:

Per indicare l’operazione di convoluzione di usa la notazione:

$$
g = f \otimes h
$$

E’ commutativa

$$
f \otimes h = h \otimes f
$$

E’ associativa

$$
(f \otimes h) \otimes h1 = f \otimes (h \otimes h1)
$$

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%205.png)

### Formula del Kernel (nel caso di dimensioni finite)

Prima di analizzare le formule, ecco cosa rappresenta ogni termine:

- **$g_{m,n}$**: Il valore del pixel nell'immagine di **output** (il risultato) alla posizione $(m, n)$.
- **$f$**: L'immagine di **input** originale.
- **$h$**: Il **kernel** (o maschera), ovvero la matrice di pesi che scorre sull'immagine.
- $s,t$: Le dimensioni del kernel (rispettivamente altezza e larghezza).
- **$\sum$**: Il simbolo di **sommatoria** (Sigma), che indica di sommare tutti i risultati delle moltiplicazioni.
- **$\lfloor \dots \rfloor$**: Funzione **Floor** (arrotonda per difetto).
- **$\lceil \dots \rceil$**: Funzione **Ceiling** (arrotonda per eccesso).

- Se il kernel $h$ ha dimensioni $s \times t$ la formula va riscritta nella seguente maniera e se gli indici del kernel sono disposti in modo da avere il punto di coordinate (0,0) nella posizione centrale, la
formula va riscritta nella seguente maniera

$$
g_{m,n} = \sum_{i = \left\lfloor s/2 \right\rfloor}^{\left\lceil s/2 \right\rceil-1} \sum_{j = -\left\lfloor t/2 \right\rfloor }^{\left\lceil t/2 \right\rceil -1} (h_{i,j} \space \cdot \space f_{m+i,n + j})
$$

**Spiegazione:**

• **Intervallo della somma:** Gli indici $i$ e $j$ variano da valori negativi a valori positivi (ad esempio da $-1$ a $+1$ per un kernel $3 \times 3$). Questo permette di "esplorare" l'intorno del pixel centrale.
• **Il calcolo:** Per calcolare il nuovo pixel $g$ in posizione $(m, n)$, la formula prende il kernel $h$ e lo moltiplica per i pixel dell'immagine $f$ spostandosi di $i$ e $j$ passi rispetto alla posizione corrente.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%206.png)

- Se il kernel $h$ ha dimensioni $s \times t$ la formula va riscritta nella seguente maniera e se gli indici del kernel sono disposti partendo da 1 fino ad arrivare a $s$ e $t$.

$$
g_{m,n} = \sum_{i=1, \space j=1}^{s, t}\space h_{i,j} \space \cdot \space f_m+(i-s+\left\lfloor s/2 \right\rfloor), n  + (j-t + \left\lfloor t/2 \right\rfloor)
$$

**Spiegazione:**
• **Intervallo della somma:** Qui $i$ e $j$ vanno semplicemente da $1$ fino alla dimensione massima del kernel ($s$ e $t$).
• **Il termine correttivo (Offset):** La parte complessa dentro la $f$, ovvero $(i - s + \lfloor s/2 \rfloor)$, serve a traslare l'indice. Poiché il kernel parte da $1$ invece che da un valore negativo, dobbiamo sottrarre una costante per assicurarci che il centro del kernel sia comunque allineato con il pixel $f_{m,n}$ che stiamo elaborando.

Entrambe le formule eseguono quella che viene chiamata **Somma di Prodotti Pesati**. Immagina di sovrapporre la mascherina (kernel) all'immagine:

1. Moltiplichi ogni numero della mascherina per il pixel che ci sta sotto.
2. Sommi tutti questi prodotti tra loro.
3. Il totale diventa il nuovo valore del pixel centrale.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%207.png)

**Esempi**

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%208.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%209.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2010.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2011.png)

Queste **quattro** immagini sono una sequenza che spiega, passo dopo passo, il "movimento" matematico della convoluzione. Immaginale come i fotogrammi di un video che mostra come viene costruita l'immagine finale.

Nel primo riquadro, quello rosso, il kernel (la maschera $3 \times 3$) viene "appoggiato" nell'angolo in alto a sinistra della matrice originale.
Le linee rosse tratteggiate collegano ogni numero della matrice con il corrispondente numero del kernel. Si moltiplicano i numeri tra loro e si somma tutto. Il risultato è **30.** Questo "30" viene scritto nella prima cella utile della matrice di output (quella a destra).

Nel secondo riquadro, quello verde, l'algoritmo sposta il kernel di **una colonna verso destra**. Adesso il kernel sta "guardando" una porzione di immagine leggermente diversa, spostata di un pixel. **Il calcolo:** Si rifà la stessa operazione (moltiplicazioni e somma). Il nuovo risultato è **45**. **Il risultato:** Il "45" viene scritto a fianco al 30 nella matrice di output.

Nel terzo riquadro, quello giallo, continua il movimento, e quindi il kernel si sposta ancora di una colonna verso destra. Seguendo la stessa logica, il risultato dell'operazione in questa nuova posizione è di nuovo **30**. Viene riempita la terza cella della prima riga nell'output.

Dopo aver finito la prima riga, il kernel torna a sinistra e scende di una riga (lo vedi dal riquadro rosa tratteggiato). In quella posizione il calcolo dà **46.** I colori diversi (rosso, verde, giallo, viola, marrone, ecc.) mostrano che **ogni singolo numero** nella matrice finale (a destra) corrisponde a una diversa posizione del kernel sulla matrice originale (a sinistra).

È grazie a questo "scorrimento" che il computer riesce a esaminare tutta l'immagine pezzetto per pezzetto, cercando bordi, forme o colori.

### Problemi nell’implementazione della convoluzione

Un problema è quello dei bordi: come fare la convoluzione e il filtraggio ai bordi?
POSSIBILI SOLUZIONI:

1. Filtrare solo le zone centrali dell’immagine
2. Supporre che tutto intorno all’immagine ci sia 0
3. Assumere una topologia “toroidale”: quando si “sfora a destra” si rientra a sinistra, quando si “sfora” in basso di rientra in alto e viceversa;
4. Aggiungere una riga all’inizio uguale alle riga precedente, una riga alla fine uguale all’ultima riga, una colonna all’inizio uguale alla colonna iniziale, e una colonna alla fine uguale alla colonna finale.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2012.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2013.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2014.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2015.png)

### Esempi di operatori locali

- **Mediano**

È un filtro non lineare che fornisce in uscita il valore mediano dell’intorno del pixel. Consiste in un effetto di smoothing dell’immagine.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2016.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2017.png)

- **Minimo**
    
    È un filtro che fornisce in uscita il valore minimo dell’intorno del pixel. Consiste in uno oscuramento dell’immagine. Preso un intorno $m\times m$ di un pixel (con $m$ generalmente dispari), sostituiscono il valore del pixel con il valore minimo di tutti i valori osservati in tale intorno.
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2018.png)
    
- **Massimo**
    
    È un filtro che fornisce in uscita il valore massimo dell’intorno del pixel. Consiste in uno schiarimento dell’immagine. Preso un intorno $m \times m$ di un pixel (con $m$ generalmente dispari), sostituiscono il valore del pixel con il valore massimo di tutti i valori osservati in tale intorno.
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2019.png)
    
- **N-box (o di media)**
    
    Sono definiti da kernel $N \times N$ con ogni elemento pari a $\frac{1}{N^2}$. Si sceglie generalmente un valore N dispari. Hanno l’effetto di sfocare le immagini. La sfocatura è molto forte in orizzontale e verticale ma meno in diagonale.
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/f9a32eb4-9758-4daa-9c0d-2110144fb354.png)
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2020.png)
    
- **N-binomiale**
    
    Sono filtri di smussamento con kernel derivati dalla distribuzione binomiale. Poiché tale distribuzione è una approssimazione discreta della distribuzione gaussiana sono anche detti filtri
    gaussiani. Hanno il pregio di smussare egualmente in tutte le direzioni. Smussano meno vigorosamente degli n-box.
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2021.png)
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2022.png)
    

### Conservazione dell’energia nei filtri

Si dice che un filtro “conserva l’energia” se la somma dei suoi pesi fa 1. Tutti i filtri di smoothing visti prima sono “*energy preserving*”: la somma dei valori totali della luminanza nella immagine non cambia. Esistono anche filtri “*non energy preserving*”.

### Noise cleaning e smoothing

I filtri appena visti servono anche a ridurre il rumore (noise) in una immagine. In questo caso, più è grande il kernel e migliore sarà il risultato anche se si rischia di aumentare la sfocatura

I filtri N-box e N-binomiali sono anche usati per sfocare l’immagine (smoothing). In questo caso, più è grande il kernel e maggiore sarà la sfocatura ma si riduce meglio il rumore.

## Il rumore

Ci sono due tipi principali di rumore:

1. **Rumore impulsivo**, detto anche “**sale e pepe**”. Viene caratterizzato dalla frazione dell’immagine modificata (in %);
2. **Rumore gaussiano bianco**. Viene caratterizzato dalla media e dalla varianza.

Analizziamoli nel dettaglio:

### Rumore impulsivo (sale e pepe)

$$
p(z) = \begin{cases} P_a & \text{per } z = a \\P_b & \text{per } z = b \\0 & \text{altrimenti}\end{cases}
$$

Se $a$ e $b$ sono valore «saturi» cioè sono uguali ai valori di massimo e di minimo dell’immagine (solitamente $a=0$ e $b=255$), abbiamo il rumore sale e pepe.

![Esempi di rumore «sale e pepe» con 1% di pixel danneggiati](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2023.png)

Esempi di rumore «sale e pepe» con 1% di pixel danneggiati

![Esempi di rumore «sale e pepe» con 10% di pixel danneggiati](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2024.png)

Esempi di rumore «sale e pepe» con 10% di pixel danneggiati

![Esempi di rumore «sale e pepe» con 20% di pixel danneggiati](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2025.png)

Esempi di rumore «sale e pepe» con 20% di pixel danneggiati

**Riduzione del rumore sale e pepe:**

- Sia il filtro media che il mediano hanno dimensioni 3x3
- Per questo tipo di rumore il filtro **mediano** funziona meglio
    
    

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2026.png)

### Rumore gaussiano

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2027.png)

$$
p(z) = \frac{1}{\sqrt{2\pi \sigma}} e^{-\frac{(z - \bar{z})^2}{2\sigma^2}}
$$

- $z$ rappresenta l’intensità
- $\bar{z}$ è il valore medio (media) di $z$
- $\sigma$ è la derivazione standard
- La derivazione standard al quadrato di $\sigma^2$ è detta varianza di $z$

**Riduzione del rumore gaussiano:**

- Sia il filtro media che il mediano hanno dimensioni 3x3
- Per questo tipo di rumore il filtro **media** funziona meglio
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2028.png)
    

### Dimensioni del kernel

Un kernel più grande (come il $5 \times 5$) "vede" un'area più vasta e media un numero maggiore di pixel ($25$ contro i $9$ di un $3 \times 3$). Questo porta a una drastica riduzione del rumore, ma causa una perdita di dettagli fini (bordi e texture) perché spalma i valori su una zona troppo ampia.

Applicare due volte un kernel $3 \times 3$ permette di ottenere un effetto di pulizia profonda ma con una "gradualità" diversa. Matematicamente, due passate di un kernel di media sono simili a un'unica passata con un kernel più grande che ha pesi diversi (più alti al centro), preservando meglio la struttura originale dell'immagine.

**Caso Studio: Rumore "Sale e Pepe" al 20%:
Rumore:** Pixel bianchi e neri sparsi casualmente.

- **Test $3 \times 3$ (x2):** Elimina i puntini di disturbo mantenendo una nitidezza accettabile.
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2029.png)
    

- **Test $5 \times 5$ (x1):** Elimina il rumore, ma l'immagine sembra vista attraverso un vetro smerigliato.
    
    ![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2030.png)
    

### Media vs Mediano

Perché i filtri mediani danno risultati migliori rispetto a quelli di media?

- Il filtro **media** tende a **creare dei livelli di grigio prima non esistenti.**
- Il filtro di **media non attenua solo il rumore ma anche tutte le alte frequenze** spaziali in maniera indiscriminata dando origine a immagini sfocate.
- Il filtro **mediano non deteriora i lati**, ma elimina i picchi con base piccola rispetto al kernel.

### Altri filtri per la riduzione del rumore (non lineari)

- **Outlier**: il valore del pixel centrale viene confrontato con il valore della media dei suoi 8 vicini. Se il valore assoluto della differenza è maggiore di una certa soglia, allora il punto viene sostituito dal valore medio, altrimenti non viene modificato.
- **Olimpico**: da un dato intorno si scartano i valori massimo e minimo e sul resto si fa la media.

### Estrazione di contorni

Gli operatori locali ci aiutano ad estrarre i contorni da una immagine.
I contorni sono definiti come delle discontinuità locali della luminanza.
Gli ***edge detector*** forniscono immagini in cui sono preservate le variazioni di luminanza ed eliminate tutte le altre informazioni.

---

Per capire se un pixel fa parte di un "contorno" (il bordo di un oggetto), non puoi guardare solo lui; devi guardare i suoi vicini per vedere se c'è un "salto" di colore. Se tutti i vicini sono bianchi, sei in una zona piatta. Se tu sei nero e il vicino è bianco, sei su un bordo. Questo concetto di "salto" o variazione improvvisa di luminosità è ciò che definiamo tecnicamente una **discontinuità locale della luminanza**.

Per visualizzare matematicamente questo salto utilizziamo dei grafici. Immagina di camminare lungo una linea dell'immagine e di tracciare un grafico della luminosità. Se passi da una zona scura a una chiara bruscamente, il grafico fa un gradino (chiamato **Step Edge**). Se il passaggio è sfumato, il grafico sale come una rampa (**Ramp Edge**). Se c'è una linea sottile, il grafico sale e scende subito (**Line Edge** o **Roof Edge**).

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2031.png)

Qui entra in gioco la matematica delle derivate per scovare questi punti
La **Derivata Prima** misura la "velocità" con cui cambia la luminosità. Immagina di guidare sul grafico della luminosità: se la strada è piatta (colore uniforme), la velocità è zero. Quando incontri una rampa (il bordo), la tua "velocità di salita" aumenta. Quindi, nel grafico della derivata prima ($f'(x)$), il bordo corrisponde esattamente al **picco massimo**. Dove la derivata è più alta, lì c'è il bordo più netto.

Esiste però un secondo metodo, basato sulla **Derivata Seconda** ($f''(x)$), che misura l'"accelerazione", ovvero come cambia la pendenza. Quando inizi a salire sul bordo, hai un'accelerazione positiva (spinta in avanti); quando finisci la salita e torni in piano, hai una decelerazione (frenata). Questo crea un grafico che va prima su e poi giù, attraversando lo zero esattamente nel centro del bordo. Questo passaggio per lo zero si chiama **Zero-crossing** ed è un metodo precisissimo per localizzare il contorno.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2032.png)

Come facciamo a calcolare queste derivate su un computer che conosce solo griglie di pixel? Usiamo i **Kernel** o maschere, che funzionano come finestre che scorrono sull'immagine.
I filtri più famosi per la derivata prima sono **Prewitt** e **Sobel**. Poiché l'immagine è 2D, dobbiamo cercare i bordi in due direzioni separate.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2033.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2034.png)

Cosa fanno queste matrici ($Sobel_x$ e $Prewitt_x$)?

Queste matrici con gli **zeri nella riga centrale** servono a trovare i **LATI ORIZZONTALI** (come le tapparelle o l'orizzonte).

**Perché? Guarda la matematica:**
Prendiamo la matrice $Sobel_x$: 

$$
\begin{bmatrix}
-1 & -2 & -1 \\
0 & 0 & 0 \\
1 & 2 & 1
\end{bmatrix}

$$

Quando questa "finestra" si sovrappone ai pixel dell'immagine, fa questa operazione:
$(\text{Riga Sotto} \times \text{positivi}) - (\text{Riga Sopra} \times \text{negativi})$

- Sta calcolando la differenza tra **Sotto** e **Sopra**.
- Se c'è una **linea orizzontale**, i pixel sopra saranno diversi da quelli sotto $\rightarrow$ Il risultato è un numero alto (bordo rilevato).
- Se c'è una linea verticale, i pixel sopra e sotto sono uguali $\rightarrow$ Il risultato è zero (bordo ignorato).

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2035.png)

**E per i lati verticali? ($Sobel_y$)**

Per trovare i **LATI VERTICALI**, la fonte usa le matrici ruotate di 90 gradi (slide), chiamate $Sobel_y$:

$$
\begin{bmatrix}
-1 & 0 & 1 \\
-2 & 0 & 2 \\
-1 & 0 & 1
\end{bmatrix}
$$

- Qui gli zeri sono nella **colonna centrale**.
- Questa matrice calcola la differenza tra **Destra** e **Sinistra**.
- Quindi rileva bordi verticali (come un palo della luce).

Per trovare le linee orizzontali, dobbiamo usare il filtro **Sobel Y**. La matrice è identica ma ruotata di 90 gradi: i $-1$ sono sopra e gli $1$ sono sotto. Questo calcola la differenza tra i pixel sopra e quelli sotto, facendo "accendere" nel risultato visivo solo i bordi orizzontali, come le tapparelle o i raggi orizzontali della ruota.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2036.png)

**Analogamente abbiamo $Prewitt_x$ e $Prewitt_y$**

**Prewitt X (Lati Orizzontali)**

La matrice è questa:  $\begin{bmatrix} -1 & -1 & -1 \\ 0 & 0 & 0 \\ 1 & 1 & 1 \end{bmatrix}$

- **Cosa cambia rispetto a Sobel:** Vedi che non c'è il `2` o il `2` al centro? Qui tutti i numeri sono `1` o `1`.
- **Cosa fa:** Tratta tutti i pixel vicini allo stesso modo, senza dare più importanza a quello centrale.
- **Il calcolo:** Fa la somma di tutta la riga **sotto** e sottrae la somma di tutta la riga **sopra**.
- **Risultato:** Rileva i **lati orizzontali** (dove c'è differenza tra sopra e sotto), ma in modo leggermente più "grezzo" rispetto a Sobel.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2037.png)

**Prewitt Y (Lati Verticali)**

La matrice è ruotata di 90 gradi:  $\begin{bmatrix} -1 & 0 & 1 \\ -1 & 0 & 1 \\ -1 & 0 & 1 \end{bmatrix}$

- **Struttura:** Gli zeri sono nella colonna centrale.
- **Il calcolo:** Fa la somma della colonna di **destra** e sottrae la somma della colonna di **sinistra**.
- **Risultato:** Rileva i **lati verticali** (dove c'è differenza tra sinistra e destra).

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2038.png)

**In sintesi:** Mentre Sobel è più preciso perché "pesa" di più il pixel centrale (quello più vicino al punto che stiamo analizzando), Prewitt è una media semplice.

### Magnitudo

A questo punto abbiamo due immagini parziali: una con i bordi verticali e una con quelli orizzontali. Per ottenere l'immagine finale completa dei contorni, dobbiamo unirle. Non possiamo fare una somma semplice; dobbiamo calcolare la **Magnitudo** (o modulo) del gradiente. Immagina che il bordo verticale sia un cateto e quello orizzontale l'altro cateto di un triangolo: la forza totale del bordo è l'ipotenusa. La formula usata è proprio il Teorema di Pitagora: radice quadrata di Sobel X al quadrato più Sobel Y al quadrato. Il risultato è un'immagine dove tutti i contorni, in qualsiasi direzione, sono visibili

Serve a unire le due immagini parziali (bordi orizzontali $X$e verticali $Y$) in **un'unica immagine finale** completa.

**La Formula (Teorema di Pitagora):**
$Magnitudo = \sqrt{Sobel_x^2 + Sobel_y^2}$

**Come funziona:**

1. **Eleva al quadrato:** Elimina i numeri negativi, così i bordi opposti non si annullano a vicenda.
2. **Somma e Radice:** Combina l'intensità orizzontale e verticale in un unico valore di forza del contorno.

**Il tocco finale (Soglia):**
L'immagine risultante è spesso "sporca". Si applica una **soglia** (es. > 50): i pixel deboli diventano neri, quelli forti diventano bianchi. Il risultato è una mappa pulita dei contorni.

### Migliori risultati

Un buon algoritmo deve:

- **Trovare tutto** (Sensibilità) senza inventare nulla (Specificità).
- Essere **sottile** (1 pixel di spessore) e **preciso**.
- Essere **continuo** (linee unite, non tratteggiate)

**Sobel (Lineare): Perché non basta?**

I filtri lineari basati solo sulla convoluzione del gradiente hanno 3 difetti:

1. **Bordi "grassi":** La sfocatura naturale del kernel crea linee spesse.
2. **Debolezza al rumore:** Ogni sbalzo di pixel viene scambiato per un bordo.
3. **Soglia rigida:** O perdi bordi veri o trovi troppo rumore.

**Cosa sono gli algoritmi "non lineari"?**

Un'operazione "lineare" è semplice e prevedibile: se raddoppio l'input, raddoppia esattamente l'output. Esempio: moltiplicare tutti i pixel per 2.

Un'operazione **non lineare** rompe questa regola semplice. Esempi:

- **Valore assoluto**: |x| non è lineare perché |-2| = 2, ma -|2| = -2
- **Quadrato**: x² non è lineare perché (2*3)² = 36, ma 2*(3²) = 18
- **Soglia**: "Se il valore è > 100, mettilo a 255, altrimenti a 0"

**Esempi di "strategie più intelligenti":**

- **Algoritmo di Canny**: Come già accennato, non si limita a calcolare il gradiente. Fa tre operazioni extra intelligenti:
    1. **Soppressione dei non-massimi**: Per ogni pixel, guarda la direzione del gradiente. Se lungo quella linea il pixel corrente non è il più forte, lo azzera. Risultato: bordi sottilissimi.
    2. **Isteresi a doppia soglia**: Usa due soglie (alta e bassa). I pixel sopra la soglia alta sono bordo sicuro. Quelli sotto la soglia bassa non sono bordo. Quelli in mezzo diventano bordo SOLO se toccano un pixel bordo-sicuro. Questo unisce linee spezzate.
    3. **Collegamento dei bordi**: Cerca di tracciare linee continue seguendo la direzione del gradiente.
- **Algoritmi basati su modelli**: Cercano di riconoscere pattern specifici di bordi (ad esempio, cercano linee dritte, curve, ecc.)
- **Algoritmi adattativi**: Cambiano i loro parametri in base alle caratteristiche locali dell'immagine (ad esempio, usano soglie diverse per zone scure e zone chiare)

**Perché questi metodi danno risultati migliori?**

Facciamo un'analogia:

- Il metodo Sobel semplice è come cercare i bordi con una torcia che illumina solo un punto alla volta, senza criterio.
- L'algoritmo di Canny è come cercare i bordi con un detective che:
    1. Usa una lente d'ingrandimento per vedere i dettagli (soppressione non-massimi)
    2. Ha due livelli di certezza: "sono sicuro" e "forse" (isteresi)
    3. Segue le tracce per ricostruire il percorso completo (collegamento)

Il detective trova bordi più precisi, continui e con meno errori.

**In sintesi estrema**

- **Sobel = Torcia:** Illumina tutto ciò che cambia, ma in modo sfocato e confuso.
- **Canny = Detective:** Analizza i dettagli, scarta i falsi indizi e segue le tracce per ricostruire il percorso intero.

### Kernel notevoli: il Laplaciano

Il filtro più diffuso per calcolare la derivata seconda è detto **Laplaciano**, ed è definito dalla maschera:

$$
\begin{matrix}-1 & 0 & -1\\0 & 4 & 0 \\-1 & 0 & -1 \end{matrix}
$$

Il Laplaciano è un **misuratore di "picchi" e "buchi"** in un'immagine. Ti dice se un pixel è una **montagnetta** (più chiaro dei vicini) o una **buca** (più scuro dei vicini) rispetto all'area circostante.

Pensa a quando tocchi la superficie di uno stagno:

- Se fai un piccolissimo splash (un "picco"), l'acqua intorno si alza e poi scende
- Se fai un piccolo buco (una "depressione"), l'acqua intorno scende e poi si rialza
- Se la superficie è piatta, non succede nulla

Il Laplaciano fa esattamente questo: misura quanto quel punto è "diverso" dalla media dei suoi dintorni.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2039.png)

Dopo aver applicato l’operatore Laplaciano è necessario che si verifichi la condizione di ***Zero-crossing***. Cioè, deve sempre accadere che rispetto al punto in questione ci sia nel suo intorno un valore positivo e un valore negativo.

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2040.png)

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2041.png)

### Filtri di sharpening

I filtri di sharpening sono filtri il cui scopo è quello di aumentare la nitidezza di una immagine aumetandone il contrasto locale. Ovviamente questa è una operazione opposta allo
sfocamento, in quanto “accentua” i dettagli.

Per ottenere tale effetto si può adottare una maschera che, derivata dal Laplaciano, “rinforza” i lati presenti nell’immagine. Purtroppo essa rinforza anche il rumore
presente nella immagine!

![image.png](Lezione%209%20Operatori%20locali%20e%20Convoluzione/image%2042.png)