# Lezione 11: Fourier

[Draft](Lezione%2011%20Fourier/Draft%202f41cf23380e80afab4ad268cc356f2b.md)

Di solito pensiamo a una foto come a un insieme di oggetti (un viso, un albero). In questo contesto, invece, dobbiamo vederla come un **segnale**.

Immagina di scorrere il dito su una riga orizzontale di un'immagine in bianco e nero:

- Quando incontri pixel neri, il valore è basso.
- Quando incontri pixel bianchi, il valore è alto.
- Se ci sono strisce alternate (bianco-nero-bianco-nero), il valore sale e scende regolarmente.

Le immagini, quindi, possono essere viste anche come segnali, ossia come frequenze costruite da sinusoidi e cosinusoidi. E questo è fondamentale perché tramite queste frequenze possiamo lavorare sulle immagini.

Viene in nostro aiuto il matematico Fourier, che ha inventato il:

<aside>
💡

**Teorema di Fourier**

***Un’onda complessa può essere scomposta in onde più semplici.***

</aside>

Fourier dice che una **funzione periodica** (ad esempio un'onda sinusoidale che si ripete nel tempo) può essere espressa come **somma di seni e coseni** con diverse frequenze e ampiezze. In pratica, un'oscillazione visivamente complessa può essere scomposta in una serie di oscillazioni più "semplici" (sinusoidi) che, sommate tra loro, ricostruiscono l'onda originale. Questo processo di scomposizione e ricostruzione si realizza tramite la **Serie di Fourier**.

Se invece abbiamo una **funzione non periodica** (cioè che non si ripete in modo regolare), essa può essere espressa come **integrale di seni e coseni** moltiplicati per opportune **funzioni-peso** (o coefficienti). Questo strumento è la **Trasformata di Fourier**.

In sintesi, attraverso gli strumenti di Fourier possiamo **scomporre e ricostruire** un segnale o una funzione **senza perdere informazioni**.

![image.png](Lezione%2011%20Fourier/image.png)

Sia la serie di Fourier che la Trasformata di Fourier condividono il fatto che una funzione possa essere “ricostruita” con un semplice processo di inversione senza perdita di informazione.  E’ cioè possibile lavorare nel cosiddetto dominio di Fourier (frequenze) e tornare nel dominio originale della funzione in maniera del tutto naturale.

**Quindi passiamo dal dominio spaziale (dei pixel) a quello delle frequenze.**

### Immagini e Segnali

Nell'**elaborazione delle immagini** (image processing) questo approccio è applicabile perché possiamo interpretare un'immagine come un **segnale che varia nello spazio** (in due dimensioni). In questo contesto, il valore della funzione in ogni punto (pixel) definisce la sua intensità (es. il **livello di grigio**).

![image.png](Lezione%2011%20Fourier/image%201.png)

### Trasformata e Antitrasformata di Fourier

Nel caso di 2-D la coppia di trasformata antitrasformata assume la seguente forma

$$
F(u,v) = \frac{1}{MN}\sum_{x = 0}^{M-1} \sum_{y = 0}^{N-1} f(x, y) e^{-i2\pi(\frac{ux}{M} + \frac{vy}{N})}
$$

$$
f(x,y) = \sum_{x = 0}^{M-1} \sum_{y = 0}^{N-1} F(u, v) e^{i2\pi(\frac{ux}{M} + \frac{vy}{N})}
$$

u e v sono gli indici relativi agli assi frequenze discretizzati, mentre M e N sono le dimensioni (in pixel) dell’immagine.

Analizziamo nel dettaglio entrambe.

1. **Scomporre l’immagine**
    
    $$
    F(u,v) = \frac{1}{MN}\sum_{x = 0}^{M-1} \sum_{y = 0}^{N-1} f(x, y) e^{-i2\pi(\frac{ux}{M} + \frac{vy}{N})}
    $$
    
    Cosa significa ogni pezzo:
    
    - $\color{green} \bold{f(x,y)}$: Questa è la nostra immagine. E’ un insieme di punti.
    $x$ e $y$ sono le coordinate di un singolo **pixel**. $f(x, y)$ è il suo colore (o livello di grigio).
     $x$ è la riga e $y$ la colonna di una griglia.
    - $\color{green} \bold{F(u, v)}$: Questo è il risultato della scomposizione. $u$ e $v$ NON sono coordinate spaziali, ma “**codici per le frequenze**”. Ricordiamoci che passiamo dal dominio spaziale al dominio delle frequenze.
        - $u$ è il codice per le righe ondulate
        - $v$ è il codice per le colonne ondulate
        - $F(u,v)$ ti dice: “Per la tua immagine, quanta dose di frequenza con codice riga $u$ e colonna $v$ ti serve?”
    - $\color{green} \bold{(\frac{1}{MN})}$: E’ un **normalizzatore**. MN è il numero totale di pixel (M per le righe, N per le colonne). Dividendo per $MN$, stiamo dicendo: "Ok, calcoliamo la **percentuale media** di ogni valore nell’immagine". Questo fa sì che il valore non sia proporzionale alla dimensione dell’immagine. Così che anche immagini di dimensioni diverse ma stessi valori possono essere confrontate.
    **Esempio 1 (Immagine 2×2):** Pixel: 10, 20, 30, 40 → Somma=100 → Normalizzato: 100/4=25
    **Esempio 2 (Stessa immagine in 4×4):** Ogni pixel raddoppiato → Somma=400 → Normalizzato: 400/16=25
    **Risultato:** Entrambe danno 25. Il fattore $(1/MN)$ compensa la dimensione diversa, mantenendo il valore medio costante.
    - $\color{green} \bold{\sum_{x = 0}^{M-1} \sum_{y = 0}^{N-1}}$:  Queste due sommatorie fanno una cosa molto precisa: **"Per una data coppia di frequenze (u,v), esaminiamo ogni singolo pixel dell'immagine, uno per uno, facciamo un calcolo, e sommiamo tutti i risultati."**
    - $\color{green} \bold{e^{-i2\pi(\frac{ux}{M} + \frac{vy}{N})}}$: $e$ è la formula di Eulero in azione. La quale ci permette, in matematica, di scrivere seno e coseno come esponenziale.
    Mentre $\frac{ux}{M} + \frac{vy}{N}$ ci permette di creare un’onda di controllo. Ossia un’oscillazione da cercare nella nostra immagine.
    Il **segno meno $-$** nell'esponente è fondamentale. Pensa a un **metal detector che cerca una frequenza specifica**. Il segno meno fa sì che la lente **risuoni in opposizione** alla frequenza che sta cercando. Se la frequenza c'è, l'opposto si annulla e il risultato della somma sarà un numero grande. Se non c'è, non succede nulla e il risultato è vicino a zero.
    La **$i$ (immaginaria)** è qui perché ci serve un **doppio metal detector**. Uno per cercare le parti dell'onda che sono come un coseno (simmetriche) e uno per le parti che sono come un seno (sfasate). Il numero $i$ ci permette di tenere separati questi due risultati in un unico numero (il numero complesso $F(u,v) = a + bi$).
    
    **In breve (TRASFORMATA):** Prendi l'immagine, la passi sotto una serie di metal detector ($u,v$) che cercano specifiche onde. Ogni metal detector ti dà un numero $F(u,v)$ che dice "quanto" di quell'onda c'è. Dividi per $MN$ per avere una media. Il -i fa parte del metal detector.
    

1. **Ricostruire l’immagine**
    
    $$
    f(x,y) = \sum_{u = 0}^{M-1} \sum_{v = 0}^{N-1} F(u, v) e^{i2\pi(\frac{ux}{M} + \frac{vy}{N})}
    $$
    

Cosa significa ogni pezzo:

- $\color{green} \bold{f(x, y)}$: È il valore del pixel ricostruito alla posizione specifica $(x, y)$ nell'immagine.
- $\color{green} \bold{F(u, v)}$:  Sono i **coefficienti della trasformata di Fourier** ottenuti dalla prima formula. Ogni $F(u, v)$ è un numero complesso che contiene:
    - **Modulo:** quanto è presente la frequenza $(u, v)$ nell'immagine
    - **Fase:** informazione sulla posizione relativa di questa frequenza
- NON c’è $\color{green} \bold{\frac{1}{MN}}$. Perché?
    
    Nella prima formula, $(1/MN)$ serviva a **normalizzare** i valori perché:
    
    - Stavi sommando su tutti i pixel $(x, y)$
    - Senza normalizzazione, immagini più grandi avrebbero coefficienti più grandi
    
    Nella seconda formula:
    
    - $F(u, v)$ contiene **già valori normalizzati** (sono medie)
    - Se mettessi $(1/MN)$ ancora, **sottostimeresti** il valore di ogni frequenza
    - L'immagine ricostruita sarebbe **più scura** e sbagliata
- $\color{green} \bold{\sum \sum}$: Queste sommatorie dicono: **"Per ricostruire UN singolo pixel $(x, y)$, devi usare TUTTE le frequenze"**.
    
    **Procedimento:**
    
    1. Fissi un pixel specifico $(x, y)$ dove vuoi calcolare il valore
    2. **Per ogni frequenza possibile $(u, v)$** (da $(0,0)$ a $(M-1, N-1)$):
        - Prendi il coefficiente $F(u, v)$ corrispondente
        - Lo moltiplichi per il valore dell'onda pura $e^{i2\pi(...)}$ valutata nel punto $(x, y)$
        - Aggiungi il risultato a un accumulatore
    3. Dopo aver fatto questo per **tutte** le $M×N$ frequenze, l'accumulatore contiene il valore $f(x, y)$ di quel pixel
    - **Il Pezzo con $\color{green}\bold{e}$ e $\color{green}\bold{i}$**: Qui è **$e^{+i2\pi(...)}$**.
    
    Questa è l'**onda pura** di frequenza $(u, v)$ valutata nel punto $(x, y)$.
    
    - **Segno $+$**: Nella prima formula avevamo $e^{-i...}$ perché stavamo **analizzando** (usavamo il complesso coniugato per il prodotto scalare). Qui abbiamo $e^{+i...}$ perché stiamo **sintetizzando** (stiamo generando l'onda, non analizzandola).
    - **La $i$**: Rappresenta l'unità immaginaria. Permette di combinare correttamente le parti reale e immaginaria (che corrispondono a seno e coseno).
    - **La formula di Eulero**: $e^{i\theta} = \cos\theta + i\sin\theta$ ci dice che questa espressione rappresenta un'onda sinusoidale bidimensionale.

**In breve (ANTITRASFORMATA):** Prendi la lista dei risultati dei metal detector $F(u,v)$ (che ti dicono quanto di ogni onda c'era). Per ricostruire ogni singolo pixel $(x,y)$, generi tutte le onde originali $e^{+i...}$ nella posizione di quel pixel, le moltiplichi per i loro coefficienti $F(u,v)$ corrispondenti, e le sommi tutte insieme. Il $+i$ fa parte dell'onda originale che stai generando. Non devi più dividere perché i coefficienti $F(u,v)$ sono già valori medi corretti.

Poiché la trasformata di Fourier ha valori complessi (composti da una parte reale e una immaginaria $a + bi$), può essere espressa in termini della sua parte reale e della sua parte immaginaria.

- ***Spettro della trasformata***
Mostra **quanto** (con quale intensità) è presente ciascuna frequenza nel segnale.
L’ampiezza, dunque, contiene solo l’informazione relativa al fatto che una certa struttura periodica è presente nell’immagine.

$$
|F(u,v)| = \sqrt{R^2(u,v) + I^2 (u,v)}
$$

- ***Angolo di Fase***
La fase contiene le informazioni essenziali per la struttura dell’immagine, quelle cioè relative al dove le strutture periodiche evidenziate dalla trasformata siano collocate
Mostra, dunque, **dove** (con quale sfasamento) inizia ciascuna componente sinusoidale. La fase determina da quale punto del suo ciclo l'onda inizia.
    
    $$
    \phi (u,v) = \tan^{-1}  \left[\frac{I(u,v)}{R(u,v)} \right]
    $$
    
- ***Potenza Spettrale***
Mostra **quanta energia** è associata a ciascuna frequenza.
    
    $$
    P(u,v) = |F(u,v)|^2 = R^2 (u,v) + I^2 (u,v)
    $$
    

### Range Dinamico

Lo spettro di Fourier dell'immagine di Lena ha valori che vanno:

- **Minimo:** circa 0
- **Massimo:** 6.470.000

Il tuo schermo può mostrare solo **256 livelli di grigio** (da 0 = nero a 255 = bianco).

**Se mappi direttamente 6.470.000 in 255 livelli:**

- 6.470.000 ÷ 255 ≈ 25.400
- Quindi ogni "salto" di grigio vale circa 25.400 unità
- Tutti i valori sotto 25.400 → diventano **NERO (0)**
- Solo valori sopra ~6.440.000 → diventano visibili (grigi chiari)

**Risultato:** Vedresti solo pochissimi pixel bianchi su uno sfondo completamente nero. Perdi tutta l'informazione delle frequenze basse e medie.

**Perché il Logaritmo Risolve il Problema**

Il logaritmo ha questa proprietà speciale:

- log(10) = 1
- log(100) = 2
- log(1.000) = 3
- log(1.000.000) = 6
- log(6.470.000) ≈ 6,8

**Vedi che:**

Da 10 a 1.000.000 c'è una differenza di 999.990

Ma i loro logaritmi differiscono solo di 5 (da 1 a 6)

**Traduciamo:**

- Il valore 10 → log(10) = 1
- Il valore 6.470.000 → log(6.470.000) ≈ 6,8

Ora invece di avere numeri da 0 a 6.470.000, abbiamo numeri da ~0 a ~6,8.

Questa scala è gestibile.

**La soluzione**
Usiamo una funzione di compressione di tipo logaritmico

$$
D(u,v) = c \cdot log(1 + F(u,v))
$$

**Ogni pezzo:**

- **$\green{\bold{F(u,v)}}$**: il valore originale (può essere da 0 a milioni)
- **$\green{\bold{+1}}$**: evita problemi con log(0) che non esiste
- **$\green{\bold{log(...)}}$**: schiaccia i numeri grandi
- **$\green{ \bold{c}}$**: costante che "stira" i valori schiacciati per riempire i 256 livelli di grigio

**Passo 1: Capire l'intervallo di $D(u,v)$**

Sappiamo che:

$0 < |F(u,v)| < R$ (dove R = 6.47 milioni)

Quindi:

$0 < D(u,v) < c * log(1 + R)$

**Nota Importante:** Siccome R è un numero gigantesco (6.47 milioni), $(1 + R)$ è praticamente uguale a $R$. Quindi possiamo approssimare:

$D(u,v) ≈ c * log(R)$

**Passo 2: Trovare la Costante $c$**

Noi vogliamo che **D(u,v)** vada esattamente da **0 a 255** per usare tutti i livelli di grigio.

Quindi imponiamo che il **massimo** valore di D sia 255:

$c * log(R) = 255$

(perché 255 = L-1, dove L=256 livelli)

Da questa equazione ricaviamo c:

$c = 255 / log(R)$

**Passo 3: Calcolare $c$**

Calcoliamo con i numeri della slide:

$R = 6.47 × 10^6$

$log(6.47 × 10^6) ≈ log(6.47) + log(10^6) ≈ 0.81 + 6 ≈ 6.81$

(usando logaritmo in base 10; in base e sarebbe circa 15.68)

Quindi:

$c = 255 / 6.81 ≈ 37.4$ (se log in base 10)

Oppure:

$c = 255 / 15.68 ≈ 16.26$ (se log in base e, come nella slide)

La slide usa il logaritmo naturale (in base e) e ottiene **c = 16.26**.

**Passo 4: Risultato Finale**

Ora abbiamo la formula completa:

$D(u,v) = 16.26 * log(1 + |F(u,v|)$

**Cosa succede nella pratica:**

- Se $|F(u,v)| = 0$ → $D ≈ 16.26 * log(1) = 0$ → **Nero (0)**
- $Se |F(u,v)| = R = 6.47$ milioni → $D ≈ 16.26 * 15.68 ≈ 255$ → **Bianco (255)**
- Tutti i valori intermedi vengono "schiacciati" in modo logaritmico nell'intervallo **0-255**

**Perché Funziona?**

Il logaritmo fa questo miracolo:

- I valori **altissimi** (milioni) vengono molto compressi
- I valori **medi** e **bassi** guadagnano più spazio nella scala 0-255
- Risultato: invece di vedere solo i picchi massimi (pochi pixel bianchi su nero), ora vediamo **una gradazione completa di grigi** che mostra sia le frequenze deboli che quelle forti!

![image.png](Lezione%2011%20Fourier/image%202.png)

![Modulo di Lena](Lezione%2011%20Fourier/image%203.png)

Modulo di Lena

![Logaritmo del modulo di Lena](Lezione%2011%20Fourier/image%204.png)

Logaritmo del modulo di Lena

![Fase di Lena](Lezione%2011%20Fourier/image%205.png)

Fase di Lena

Un esempio di trasformata discreta nel caso 2-D: un impulso approssimato da un piccolo cerchio bianco su fondo nero, in un’immagine di circa 200 x 200 pixels. I differenti livelli di grigio nell’immagine di intensità dello spettro evidenziano le ampiezze decrescenti dei diversi lobi.

![image.png](Lezione%2011%20Fourier/image%206.png)

### Esempio

![image.png](Lezione%2011%20Fourier/image%207.png)

![image.png](Lezione%2011%20Fourier/image%208.png)

La visualizzazione dello spettro (compressa logaritmicamente) $|F(u,v)|$ ma una sua versione compressa logaritmicamente. Se non fosse stata compressa logaritmicamente si vedrebbe solo un puntino al centro.

L’ampiezza contiene l’informazione relativa al fatto che una certa struttura periodica è
presente nell’immagine.

![image.png](Lezione%2011%20Fourier/image%209.png)

La fase contiene l’informazione relativa al dove le strutture periodiche evidenziate nella DFT sono collocate. Quindi è molto più significativa di quello che possa sembrare nell’immagine.
**La fase contiene l'informazione della FORMA e della POSIZIONE.
Senza la fase, non riconosceresti nessuna immagine, anche se hai tutte le ampiezze corrette.**

**DFT** sta per **Trasformata Discreta di Fourier**. È semplicemente la versione "digitale" della Trasformata di Fourier che funziona su immagini fatte di pixel (quindi numeri discreti, non continui). È lo strumento che usi per passare dal dominio spaziale (l'immagine normale) al dominio delle frequenze (lo spettro).

![image.png](Lezione%2011%20Fourier/image%2010.png)

### Esempi di Trasformazioni e Spettri 3D

![Screenshot 2026-01-28 180006.png](Lezione%2011%20Fourier/Screenshot_2026-01-28_180006.png)

![Screenshot 2026-01-28 180026.png](Lezione%2011%20Fourier/Screenshot_2026-01-28_180026.png)

**Nello spettro:**

Vedi **due punti a SINISTRA e DESTRA** del centro.

Perché? Perché le strisce cambiano colore **in orizzontale** (da sinistra a destra).

**Spettro 3D:**

Due montagne, una a sinistra e una a destra del centro.

---

![Screenshot 2026-01-28 180033.png](Lezione%2011%20Fourier/Screenshot_2026-01-28_180033.png)

![Screenshot 2026-01-28 180042.png](Lezione%2011%20Fourier/Screenshot_2026-01-28_180042.png)

**Nello spettro:**

Vedi **due punti SOPRA e SOTTO** il centro.

Perché? Perché le strisce cambiano colore **in verticale** (dall'alto al basso).

Sono **più lontani dal centro** rispetto all'Esempio 1 perché le strisce sono più fitte (cambi più rapidi).

**Spettro 3D:**

Due montagne, una sopra e una sotto il centro, più lontane.

---

![Screenshot 2026-01-28 180048.png](Lezione%2011%20Fourier/Screenshot_2026-01-28_180048.png)

![Screenshot 2026-01-28 180057.png](Lezione%2011%20Fourier/Screenshot_2026-01-28_180057.png)

**Nello spettro:**

Vedi **4 punti a forma di X** → in alto-sinistra, alto-destra, basso-sinistra, basso-destra.

**Perché?**

Perché la scacchiera cambia colore sia **in orizzontale** che **in verticale** insieme. Quindi ha frequenze in entrambe le direzioni.

**Spettro 3D:**

Quattro montagne ai quattro angoli.

---

### Trasformate di Fourier: vantaggi

Che vantaggio si può ottenere dalla trasformata di Fourier?

Nello spazio delle frequenze è possibile:

- sopprimere frequenze indesiderate
- ridurre lo spazio occupato dai dati pur limitando la degenerazione del segnale (JPEG, MP3, ecc…)
- rigenerare segnali degradati

**Trasformata Diretta = ANALISI (Scomporre)**
Come analizzare di cosa è fatto un suono o un'immagine.

- Segnale f(x): è la tua immagine o suono originale
- Vettori di base: sono le "onde base" più semplici (sinusoidi)
- Coefficienti: ti dicono QUANTO di ogni onda base c'è nel tuo segnale
Esempio: Se analizzi un accordo musicale, i coefficienti ti dicono quanto DO, quanto MI, quanto SOL ci sono.

**Trasformata Inversa = SINTESI (Ricostruire)**
Come ricreare il suono o l'immagine dalle sue componenti.

- Somma pesata: Prendi ogni onda base
- La moltiplichi per il suo coefficiente (quanto ce n'è)
- Sommi tutte queste onde moltiplicate
- Risultato: ottieni di nuovo il segnale originale
Esempio: Per ricreare l'accordo, suoni un DO al volume giusto + un MI al volume giusto + un SOL al volume giusto = ottieni lo stesso accordo.

**Coefficiente = CORRELAZIONE**
Il coefficiente misura quanto il segnale assomiglia a quell'onda base.
**Coefficiente alto** = il segnale assomiglia molto a quell'onda base
**Coefficiente basso** = il segnale non assomiglia a quell'onda base
Esempio: Se il tuo segnale è fatto principalmente di onde basse, avrà coefficienti alti per le basse frequenze e bassi per le alte.

Nessuna perdita di informazione
È come descrivere la stessa cosa in due lingue diverse:

- Lingua 1 (spazio/tempo): "immagine con pixel..."
- Lingua 2 (frequenza): "combinazione di onde con coefficienti..."
Puoi tradurre avanti e indietro senza perdere nulla.

**In sintesi:**
ANALIZZI: Scomponi il segnale in onde semplici → ottieni i coefficienti
I coefficienti ti dicono quanto ogni onda è presente
SINTETIZZI: Ricostruisci il segnale sommando tutte le onde × i loro coefficienti
Tutto qua. È solo un modo diverso (più utile per certe operazioni) di rappresentare la stessa informazione.

### Alcune proprietà della DFT 2-D

### **1. SEPARABILITÀ (La Scomposizione "Fai da Te")**

**Il problema:** Calcolare la trasformata 2D di un'immagine è **pesantissimo**.

**La soluzione:** Invece di fare tutto in un colpo solo, la spezzi in due operazioni più semplici:

1. **Trasformi tutte le RIGHE** (come se fossero segnali 1D)
2. Con il risultato in mano, **trasformi tutte le COLONNE**

**Perché ti interessa:** Perché i software la calcolano davvero così. È un trucco per farla **velocemente**.

**Esempio pratico:**

È come fare la spesa: invece di pensare a tutto il carrello in una volta, prima prendi tutto il fresco, poi tutto il secco, poi le bevande. Passo dopo passo.

---

### **2. TRASLAZIONE/SHIFT (Il Centratore)**

**Il problema:** Quando calcoli la trasformata, il risultato ha le **frequenze basse** (le più importanti) agli **angoli**, e quelle alte al centro. È scomodo da guardare.

**La soluzione:** Prima di fare la trasformata, moltiplichi l'immagine per una **scacchiera** ($(-1)^{(x+y)}$). Questo **sposta** tutto.

**Risultato:** Dopo questo trucco, nello spettro:

- Le **basse frequenze** vanno **AL CENTRO**
- Le **alte frequenze** vanno **AI BORDI**

**Cosa cambia davvero:** Cambia solo **la posizione** delle frequenze nel grafico (la *fase*), ma **non quanto** sono forti (l'*ampiezza*). È solo per comodità di visualizzazione.

**Da ricordare:**

SENZA shift → basse freq ai bordi, alte al centro (strano)

CON shift → basse freq al centro, alte ai bordi (come si vede sempre)

![image.png](Lezione%2011%20Fourier/image%2011.png)

![image.png](Lezione%2011%20Fourier/image%2012.png)

![image.png](Lezione%2011%20Fourier/image%2013.png)

---

### **3. VALOR MEDIO / COMPONENTE DC (Il Punto Bianco al Centro)**

**F(0,0)** è semplicemente **la media di tutti i pixel** dell'immagine.

**Dove lo vedi:** Nello spettro (DOPO lo shift) è quel **punto bianchissimo BRUCIANTE al centro**.

**Perché è così luminoso?** Perché rappresenta tutto ciò che nell'immagine è **costante**, non varia, è piatto (come lo sfondo).

**Esempio:** Se fai la trasformata di un'immagine con sfondo grigio chiaro e un oggetto scuro, quel punto bianco centrale dice "questa immagine in media è di questo grigio chiaro".

**Nome tecnico:** Si chiama **componente DC** (come la corrente continua). È la parte "che non oscilla".

### Fast Fourier Trasform

$$
F(u) = \frac{1}{N} \sum_{x=0}^{N-1} f(x) \exp \left( -i 2\pi ux/N \right)
$$

È l'algoritmo **veloce** per calcolare la trasformata di Fourier.

**Senza FFT:** Se hai N pixel, ci vogliono circa **N²** operazioni → MOLTO LENTO.

**Con FFT:** Ci vogliono circa **N·log₂(N)** operazioni → MOLTO VELOCE.

**Esempio numerico:**

Per un'immagine 1024×1024 (≈1 milione di pixel):

- DFT normale: 1.000.000² = **1.000 MILIARDI** di operazioni
- FFT: 1.000.000 × log₂(1.000.000) ≈ 1.000.000 × 20 = **20 MILIONI** di operazioni

**50.000 volte più veloce!**

**Perché esiste?**

Perché senza FFT non potresti usare la trasformata di Fourier in tempo reale (filtri, compressione, ecc.). Con la FFT, invece, diventa pratico.

**Cosa devi ricordare:**

"FFT = algoritmo veloce per calcolare la DFT. Complessità O(N log N) invece di O(N²)."

### Frequenze: low and high

**Basse Frequenze = Variazioni LENTE**

- Sono le parti dell'immagine che **cambiano poco e gradualmente**
- Esempi: un cielo sereno, una parete liscia, lo sfondo sfocato
- Nello spettro di Fourier: stanno **vicino al centro** (dopo lo shift)

**Alte Frequenze = Variazioni BRUSCHE**

- Sono le parti dell'immagine che **cambiano improvvisamente**
- Esempi: il bordo di un oggetto, una ruga sul viso, i capelli, il rumore digitale
- Nello spettro di Fourier: stanno **lontano dal centro** (ai bordi)

**LA "PERDITA DI LOCALIZZAZIONE SPAZIALE"**

Questa è la parte importante: **non puoi dire con precisione** "questo punto nello spettro corrisponde a QUEL punto nell'immagine".

**Perché?**
Perché la trasformata di Fourier analizza **tutta** l'immagine insieme.
È come ascoltare un'ora di musica e dire "in quest'ora c'è molto basso" - non puoi dire **esattamente a che minuto** c'è quel basso.

**Esempio pratico:**
Se hai due bordi in punti diversi dell'immagine, nello spettro vedrai semplicemente che ci sono alte frequenze, ma non potrai dire "queste alte frequenze vengono dal bordo di sinistra, quelle dal bordo di destra".

**ASSOCIAZIONI GENERALI (NON PRECISE)**

Pur non potendo fare corrispondenze **punto per punto**, possiamo fare queste associazioni:

| **Nell'immagine originale** | **Nello spettro di Fourier** |
| --- | --- |
| **Zona grande e uniforme** → | **Punto luminoso vicino al centro** (basse freq) |
| **Molti bordi e dettagli** → | **Molti punti luminosi lontani dal centro** (alte freq) |
| **Bordo verticale** → | **Punti sull'asse orizzontale** |
| **Bordo orizzontale** → | **Punti sull'asse verticale** |
| **Rumore sparso** → | **Punti sparsi ovunque** |

**Immagina questa immagine:**

```
███████████████
██████   ██████
██████   ██████
███████████████

(Un rettangolo bianco con un buco nero al centro)
```

**Nello spettro vedrai:**

1. **Un punto BRUCIANTE al centro** → la componente DC (media dell'immagine)
2. **Pattern simmetrici attorno al centro** → le basse frequenze (la forma generale)
3. **Altri pattern più lontani** → le alte frequenze (i bordi del buco)

**MA NON PUOI SAPERE:** "Questo punto specifico corrisponde al bordo SINISTRO del buco, quell'altro al bordo DESTRO del buco".

Anche se perdi la localizzazione precisa, puoi comunque:

1. **Rimuovere il rumore** → tagli le alte frequenze sparse
2. **Sfocare l'immagine** → riduci le alte frequenze
3. **Migliorare i bordi** → esalti le alte frequenze
4. **Comprimere** → scarti le alte frequenze meno importanti

**Esempio concreto:**

Il JPEG funziona così: guarda lo spettro, dice "queste alte frequenze qui non si vedono molto", le butta via, e l'immagine occupa meno spazio.

### Filtraggio nel Dominio della Frequenza

![image.png](Lezione%2011%20Fourier/image%2014.png)

**CONCETTO DI FILTRO:**

Un **filtro** è una **"regola di modifica"** che dice come cambiare un'immagine.
Pensa a Instagram: quando scegli un filtro "Nashville" o "Valencia", stai applicando una regola che modifica i colori della tua foto. Nel nostro caso, invece di modificare i colori, modifichiamo le **frequenze**.

### Tipi di filtri principali

1. **FILTRO PASSA-BASSO (LOW-PASS)**
    
    **Cosa fa:** Lascia passare solo le **basse frequenze**
    
    **Effetto sull'immagine:** La **SFOCA**
    
    **Dove si usa:** Per ridurre il rumore, per sfocare sfondi
    
2. **FILTRO PASSA-ALTO (HIGH-PASS)**
    
    **Cosa fa:** Lascia passare solo le **alte frequenze**
    
    **Effetto sull'immagine:** Evidenzia i **BORDI e DETTAGLI**
    
    **Esempio pratico:** Come gli occhiali per vedere meglio i dettagli
    
    **Dove si usa:** Per lo sharpening, per evidenziare contorni
    
3. FILTRO PASSA-BANDA (BAND-PASS)
    
    **Cosa fa**: Lascia passare solo un intervallo di frequenze
    **Effetto**: Una via di mezzo tra i due
    **Esempio**: Come un equalizzatore che lascia solo i medi
    

### Come si rappresenta un filtro

- **Nel dominio spaziale**
E’ una matrice (maschera) di numeri che scorre sull’immagine
Esempio di filtro sfocante 3x3
    
    ```
    1/9  1/9  1/9
    1/9  1/9  1/9  
    1/9  1/9  1/9
    
    (La media dei 9 pixel vicini)
    ```
    
- **Nel dominio delle frequenze**
    
    È una **funzione** $H(u,v)$ che dice quanto attenuare ogni frequenza.
    
    **Esempio filtro passa-basso:**
    
    - $H(u,v) = 1$ per frequenze vicine al centro
    - $H(u,v) = 0$ per frequenze lontane dal centro

Torniamo al diagramma del filtraggio nel **Dominio della Frequenza**.

![image.png](Lezione%2011%20Fourier/image%2014.png)

È la **ricetta** per applicare un filtro a un'immagine usando la trasformata di Fourier:

**PASSAGGIO 1: PRE-PROCESSING**

Prendi l'immagine originale $f(x,y)$

**PASSAGGIO 2: TRASFORMATA DI FOURIER**

Calcoli $F(u,v)$ = la trasformata di Fourier dell'immagine

**PASSAGGIO 3: APPLICA IL FILTRO**

- Hai una **funzione filtro** $H(u,v)$ (che scegli tu)
- Fai: $G(u,v) = H(u,v) × F(u,v)$
- Moltiplichi **punto per punto** il filtro con la trasformata

**PASSAGGIO 4: ANTITRASFORMATA**

Calcoli l'antitrasformata per tornare all'immagine

**PASSAGGIO 5: POST-PROCESSING**

Ottieni l'immagine filtrata $g(x,y)$

### Teorema della Convoluzione

Prima di tutto: **cos'è la convoluzione** nel dominio spaziale?
È un'operazione dove una **maschera** (kernel) scorre sull'immagine e fa una **media pesata** dei pixel vicini.

**Esempio pratico:** Filtro sfocante 3×3

```
1/9 1/9 1/9
1/9 1/9 1/9
1/9 1/9 1/9
```

Questa maschera scorre su tutta l'immagine. Per ogni pixel, prende i 9 pixel intorno, li media, e mette il risultato al centro.
**Problema:** La convoluzione spaziale è **LENTISSIMA** se la maschera è grande.

Il teorema dice:

> "Fare la CONVOLUZIONE nello spazio è come fare una MOLTIPLICAZIONE in frequenza"
> 

O meglio:

**Se vuoi fare:**

```
Immagine * Maschera  (nel dominio spaziale)
```

**Puoi invece fare:**

```
Trasformata(Immagine) × Trasformata(Maschera)  (nel dominio frequenze)
```

**Poi fai l'antitrasformata e ottieni lo STESSO RISULTATO!**

E’ importante perché **moltiplicare** due matrici in frequenza è **MOLTO più veloce** che fare la convoluzione nello spazio.

Il **teorema della convoluzione** dice che:

Se nel **dominio spaziale** (quello delle coordinate $x, y$) fai un’operazione di **convoluzione** tra due funzioni $f$ e $h$ (che nel caso delle immagini è come applicare un filtro), allora nel **dominio delle frequenze** (ottenuto con la **Trasformata di Fourier - DFT**) questa operazione si traduce in una semplice **moltiplicazione**.

In formule:

1. **Spaziale**:
$g(x, y) = f(x, y) \otimes h(x, y)$

(dove $\otimes$ è la convoluzione)
2. **Frequenza**:
$G(u, v) = F(u, v) \cdot H(u, v)$
dove $F$ e $H$ sono le trasformate di Fourier di $f$ e $h$.

Quindi invece di fare la convoluzione, che è un’operazione pesante a livello di calcolo, puoi:

- Trasformare $f$ e $h$ in frequenza,
- Moltiplicarle,
- Trasformare il risultato indietro nello spazio.

Questo è alla base dei filtri per immagini nel dominio delle frequenze.

Inoltre, vediamo la complessità per un segnale 1D:
Nel dominio delle frequenze $O(n \space log n)$
Nel dominio spaziale $O(n^2)$

Effettivamente vale la pena passare al dominio delle frequenze!

**PERO’!!!**

- **Filtri grandi** → conviene lavorare in frequenza.
- **Filtri piccoli** → conviene lavorare nello spazio.

### Come ottenere un filtro (per il dominio delle frequenze) da una maschera/kernel spaziale

<aside>
💡

1. Il filtro H ha la stessa dimensione
dell’immagine I;
2. H deve avere in alto a sinistra i valori della
maschera spaziale, nel resto sempre il
valore 0;
3. Si fa lo shift di H
4. Si calcola da H la trasformata di fourier.
</aside>

Immaginiamo di **prendere una maschera piccola** (es. 3×3) e **trasformarla in un filtro in frequenza** grande come l'immagine (es. 512×512).

**Passo 2: “H deve avere in alto a sinistra i valori della maschera spaziale, nel resto 0”**

Immagina la maschera spaziale (kernel) piccola, per esempio di sfocatura 3×3:
$\begin{bmatrix}
1 & 1 & 1 \\
1 & 1 & 1 \\
1 & 1 & 1
\end{bmatrix}$

L’immagine **I** è grande, per esempio 512×512.
Il filtro **H** deve essere grande 512×512, quindi inizialmente è tutta di zeri.
Dove mettiamo la nostra maschera 3×3? La **incastoniamo in alto a sinistra** di H:
$H_{\text{prima}} =
\begin{bmatrix}
1 & 1 & 1 & 0 & 0 & \dots & 0 \\
1 & 1 & 1 & 0 & 0 & \dots & 0 \\
1 & 1 & 1 & 0 & 0 & \dots & 0 \\
0 & 0 & 0 & 0 & 0 & \dots & 0 \\
\vdots & \vdots & \vdots & \vdots & \vdots & \ddots & \vdots \\
0 & 0 & 0 & 0 & 0 & \dots & 0
\end{bmatrix}$

Quindi **H** ora è:

- nei primi 3×3 elementi = i valori della maschera spaziale
- altrove = 0.

**Passo 3: “Si fa lo shift di H”**

Nell’elaborazione di immagini con la **Trasformata di Fourier** (DFT), l’origine del dominio delle frequenze $(u=0, v=0)$ è **al centro dell’immagine**, non in alto a sinistra.

Per evitare che il kernel sia “spostato” rispetto al centro dell’immagine, dobbiamo fare uno **spostamento circolare** della matrice **H** di metà dimensione lungo le righe e colonne.

Questo **shift** significa:

- prendi la matrice H (con il kernel in alto a sinistra)
- sposta le righe circolarmente di **M/2** (se M è l'altezza)
- sposta le colonne circolarmente di **N/2** (se N è la larghezza)

Nel caso semplice, se la maschera 3×3 è in alto a sinistra, dopo lo shift finisce **al centro** della matrice 512×512.

**Perché si fa questo shift?**

Perché la DFT assume che il **punto (0,0)** della maschera corrisponda al centro della matrice. Se lo metti in alto a sinistra senza shift, la convoluzione in frequenza produrrebbe un’immagine shiftata.

Questo passaggio garantisce che la moltiplicazione in frequenza sia **corrispondente esatta** della convoluzione spaziale con lo stesso kernel centrato.

**Passo 4: Trasformata di Fourier di H**

Ora calcoli la DFT di H_shifted, e ottieni $H(u,v)$ — il filtro nel dominio delle frequenze pronto per moltiplicare per $F(u,v)$ (DFT dell’immagine).

### **Riassunto visivo dei passaggi:**

1. Crea una matrice H grande come l’immagine tutta zeri.
2. Metti la maschera piccola nel suo angolo in alto a sinistra.
3. Sposta la matrice in modo che la maschera sia centrata.
4. Fai la DFT di H → ottieni il filtro in frequenza.

Così, quando moltiplichi la DFT dell’immagine per questa $H(u,v)$ e fai l’antitrasformata, ottieni lo stesso risultato della convoluzione spaziale con la maschera originale.

### **Filtri Low Pass nel Dominio della Frequenza**

Questa sezione è cruciale per capire come si applica la teoria di Fourier all'elaborazione pratica delle immagini. I filtri passa-basso (low pass) sono funzioni, denominate $*H(u,v)*$, che operano nel dominio delle frequenze (cioè sulla Trasformata di Fourier $*F(u,v)*$ dell'immagine). Il loro scopo è **attenuare o eliminare le componenti ad alta frequenza** dell'immagine. Nel contesto spaziale, le alte frequenze corrispondono a cambiamenti rapidi di intensità: **bordi, dettagli fini e rumore**. Pertanto, applicare un filtro passa-basso significa:

- **Sfocare (Blurring)** l'immagine.
- **Ridurre il rumore** (che spesso si manifesta come variazioni improvvise e localizzate, cioè alte frequenze).
- **Smussare** le texture.

### Filtri Low Pass nel Dominio della Frequenza

Questa sezione è cruciale per capire come si applica la teoria di Fourier all'elaborazione pratica delle immagini. I filtri passa-basso (low pass) sono funzioni, denominate \( H(u,v) \), che operano nel dominio delle frequenze (cioè sulla Trasformata di Fourier \( F(u,v) \) dell'immagine). Il loro scopo è **attenuare o eliminare le componenti ad alta frequenza** dell'immagine. Nel contesto spaziale, le alte frequenze corrispondono a cambiamenti rapidi di intensità: **bordi, dettagli fini e rumore**. Pertanto, applicare un filtro passa-basso significa:

- **Sfocare (Blurring)** l'immagine.
- **Ridurre il rumore** (che spesso si manifesta come variazioni improvvise e localizzate, cioè alte frequenze).
- **Smussare** le texture.

![image.png](Lezione%2011%20Fourier/image%2015.png)

### Low Pass Ideale

Questo è il filtro concettualmente più semplice, ma praticamente il più problematico.

**Concetto a Parole**

Il filtro passa-basso ideale agisce con un **taglio netto e brutale**. Immagina di avere un cerchio centrato nell'origine dello spettro di frequenze (dopo aver applicato lo *shift* per centrare le basse frequenze). Il filtro dice:

- "**Tutte** le componenti di frequenza che si trovano **entro** una certa distanza $D_0$ dal centro (la *frequenza di taglio*) passano **inalterate** (moltiplicate per 1)."
- "**Tutte** le componenti di frequenza che si trovano **oltre** questa distanza vengono **completamente eliminate** (moltiplicate per 0)."

La distanza $D(u,v)$ si calcola come la distanza euclidea dal centro dello spettro: $D(u,v) = \sqrt{(u - P/2)^2 + (v - Q/2)^2}$ , dove $P$ e $Q$ sono le dimensioni (padded) dell'immagine nello spazio delle frequenze.

**Spiegazione della Formula e dei Simboli**

La formula matematica è una **funzione a gradino**:

$$
H(u,v) =
\begin{cases}
1 & \text{se } D(u,v) \leq D_0 \\
0 & \text{se } D(u,v) > D_0
\end{cases}
$$

![image.png](Lezione%2011%20Fourier/image%2016.png)

- $H(u,v)$: È la **funzione di trasferimento del filtro**. È una matrice delle stesse dimensioni di $F(u,v)$. Ogni suo elemento (tra 0 e 1) dice di quanto moltiplicare la corrispondente componente di frequenza $F(u,v)$ .
- $D(u,v)$: È la **distanza dal centro** del rettangolo delle frequenze per il punto di coordinate $(u,v)$. Rappresenta la "frequenza spaziale generale" di quel punto.
- D_0: È la **frequenza di taglio (cutoff frequency)**. È un numero (es. 10, 30, 50) che definisce il **raggio del cerchio** di taglio. Più $D_0$ è piccolo, più frequenze vengono tagliate e più forte è la sfocatura.

**Diagramma e Immagini**

- **Grafico 3D:** Viene mostrato un grafico prospettico di $H(u,v)$. Appare come un **cilindro perfetto** o un "tappo" piatto. La superficie superiore è perfettamente piatta a quota 1 (passaggio totale) fino al bordo definito da $D_0$, dove cade verticalmente a quota 0 (blocco totale). Questo visualizza il taglio netto e ideale.

![image.png](Lezione%2011%20Fourier/image%2017.png)

- **Immagine 2D del filtro:** Mostra $H(u,v)$ come un'immagine in scala di grigi. Si vede un **cerchio bianco perfetto** su sfondo nero. Il bianco (valore 1) corrisponde alle frequenze che passano, il nero (valore 0) a quelle bloccate. Il raggio del cerchio è $D_0$.
- **Sezione Radiale:** È un grafico 2D che traccia il valore di $H$ in funzione della distanza $D$ dal centro. È una linea orizzontale a 1 che, nel punto $D = D_0$, cade a picco a 0, formando un angolo di 90°. Questo grafico è il modo più chiaro per confrontare i diversi tipi di filtri.
- **Esempi di Applicazione:** Viene mostrata l'immagine di Lena filtrata con diversi valori di $D_0$. Con $D_0$ molto piccolo (es. 10), l'immagine è fortemente sfocata, quasi un blob. Aumentando $D_0$ (es. 160), si trattengono più dettagli. Tuttavia, in tutte le immagini filtrate con il filtro ideale si notano forti **anelli di "ringing" o "rippling"** (oscillazioni) attorno ai bordi più marcati (come il contorno del cappello). Questo è un **artefatto introdotto dal taglio netto**, dovuto al fenomeno di Gibbs, ed è il motivo per cui questo filtro, pur essendo semplice teoricamente, non è usato nella pratica.

---

### Filtro Low-Pass di Butterworth

Il filtro di Butterworth è stato introdotto per risolvere il problema del "ringing" del filtro ideale, fornendo un **taglio più morbido e graduale**.

### **Concetto a Parole**

Invece di un passaggio da 1 a 0 istantaneo, il filtro di Butterworth definisce una **transizione graduale** attorno alla frequenza di taglio \( D_0 \). Il punto \( D_0 \) non è più il punto di "spegnimento", ma il punto in cui il filtro **attenta della metà** (valore 0.5). Il filtro dice: "Le frequenze molto più basse di \( D_0 \) passano quasi inalterate. Man mano che la frequenza si avvicina a \( D_0 \), le attenua sempre di più. Le frequenze molto più alte di \( D_0 \) sono fortemente attenuate, ma raramente azzerate del tutto".

Un parametro aggiuntivo, l'**ordine \( n \)**, controlla la **pendenza della transizione**. Più \( n \) è alto, più la transizione è ripida, avvicinandosi al comportamento del filtro ideale (e reintroducendo un po' di ringing). Con \( n=1 \), la transizione è molto morbida.

### **Spiegazione della Formula e dei Simboli**

La formula è:
\[
H(u,v) = \frac{1}{1 + \left[ \frac{D(u,v)}{D_0} \right]^{2n}}
\]

- \( H(u,v), D(u,v), D_0 \): Hanno lo stesso significato di prima.
- \( n \): È l'**ordine del filtro** (un intero positivo, tipicamente 1, 2, 3...). È il nuovo "knob" di controllo.
- Analizziamo la formula passo-passo:
    1. Si calcola il rapporto \( \frac{D(u,v)}{D_0} \). Se \( D = D_0 \), questo rapporto è 1.
    2. Lo si eleva alla \( 2n \). Se \( D = D_0 \) e \( n=1 \), diventa \( 1^2 = 1 \).
    3. Si somma 1: \( 1+1=2 \).
    4. Si fa il reciproco: \( 1/2 = 0.5 \). **Ecco perché a \( D=D_0 \), \( H=0.5 \)**.
    5. Se \( D \) è molto minore di \( D_0 \) (basse frequenze), il rapporto è vicino a 0, quindi \( H \) è vicino a \( 1/(1+0) = 1 \).
    6. Se \( D \) è molto maggiore di \( D_0 \) (alte frequenze), il rapporto è grande, elevato a \( 2n \) diventa enorme, quindi \( H \) è vicino a 0.

### **Diagramma e Immagini (Pagine 59-62)**

- **Grafico 3D e Sezione Radiale:** Il grafico 3D non è più un cilindro piatto, ma una **collina morbida** che digrada dolcemente dai lati. La sezione radiale mostra una **curva decrescente continua e liscia**. Non ci sono discontinuità.
- **Confronto con l'Ideale:** La differenza chiave è visibile nella sezione radiale. La curva del Butterworth, specialmente con \( n=1 \) o \( n=2 \), è molto arrotondata attorno a \( D_0 \). Questo evita le brusche interruzioni che causano il ringing.
- **Risultato sull'Immagine:** L'immagine di Lena filtrata con un Butterworth (es. \( D_0=50, n=2 \)) apparirà **sfocata in modo uniforme**, senza gli evidenti aloni o oscillazioni (ringing) del filtro ideale. La sfocatura è più "naturale". La transizione tra aree a fuoco e sfocate è graduale.

---

### Filtro Gaussiano

Il filtro Gaussiano è un caso speciale, molto importante per la sua proprietà matematica e per la qualità dei risultati.

### **Concetto a Parole**

Il filtro Gaussiano implementa la transizione più morbida possibile. La sua curva di risposta ha la ben nota forma "a campana" (o la sua versione ribaltata). Non ha un vero e proprio "ginocchio" o punto di transizione netto; l'attenuazione inizia subito, ma in modo estremamente lieve per le basse frequenze, aumentando esponenzialmente per le alte. Inoltre, ha una proprietà unica: **la Trasformata di Fourier di una Gaussiana è un'altra Gaussiana**. Questo lo rende matematicamente molto elegante e computazionalmente vantaggioso in certe implementazioni.

### **Spiegazione della Formula e dei Simboli**

La formula è un'esponenziale:
\[
H(u,v) = e^{-\frac{D^2(u,v)}{2 D_0^2}}
\]

- \( e \): La base del logaritmo naturale (~2.718).
- L'esponente è negativo, quindi più \( D \) è grande, più l'esponenziale diventa piccolo (vicino a 0).
- \( D_0 \) qui non è il punto a 0.5. Per questa formula, quando \( D(u,v) = D_0 \), allora \( H(u,v) = e^{-1/2} \approx 0.607 \). Quindi, a differenza del Butterworth, a \( D_0 \) il filtro attenua solo di circa il 39%.
- Per fare un confronto equo con gli altri filtri (dove a \( D_0 \) l'attenuazione è del 50%), a volte la formula si scrive come \( H(u,v) = e^{-\frac{D^2(u,v)}{2 \sigma^2}} \), dove \( \sigma \) (sigma) è la deviazione standard, e si imposta \( \sigma = D_0 \) per avere un certo comportamento. Nelle slide la formula è quella sopra.

### **Diagramma e Immagini (Pagine 63-66)**

- **Grafico 3D e Sezione Radiale:** La forma 3D è una classica **collina gaussiana**, una superficie liscia e convessa. La sezione radiale è la celebre **curva a campana di Gauss**, perfettamente liscia e senza alcuna discontinuità né cambi di curvatura bruschi.
- **Risultato sull'Immagine:** Il filtraggio con un Gaussiano produce lo **sfocato più esteticamente gradevole e privo di artefatti**. È lo standard per operazioni di blurring di alta qualità. Non introduce ringing. L'effetto è molto uniforme e naturale.

---

### Filtro High-Pass Ideale con \( D_0=50 \)

Il filtro passa-alto è l'esatto **complemento a 1** del filtro passa-basso. Il suo scopo è **attenuare o eliminare le basse frequenze**, lasciando passare le alte.

### **Concetto a Parole**

Mentre il passa-basso trattiene il "centro" dello spettro e taglia i "bordi", il passa-alto fa l'opposto: **taglia il centro e trattiene i bordi**. Poiché le basse frequenze contengono l'informazione sui toni generali e sul contrasto medio (la "forma" principale degli oggetti), rimuoverle fa sì che l'immagine risultante:

- Appaia **molto scura** (perché la componente media, DC, viene rimossa).
- Mostri **solo i bordi** e le variazioni rapide (dettagli, texture).
- Perda quasi completamente l'informazione sulle regioni uniformi.

### **Spiegazione della Formula e dei Simboli**

Per l'ideale:
\[
H_{HP}(u,v) =
\begin{cases}
0 & \text{se } D(u,v) \leq D_0 \\
1 & \text{se } D(u,v) > D_0
\end{cases}
\]
**Nota:** Questa è semplicemente \( 1 - H_{LP}(u,v) \) per il corrispondente passa-basso ideale.
Con \( D_0=50 \), significa che tutte le frequenze a distanza minore o uguale a 50 pixel dal centro (un cerchio di raggio 50) vengono azzerate. Tutte le altre passano intatte.

### **Diagramma e Immagini (Pagine 68-69)**

- **Grafico 3D:** Sembra un "pozzo" cilindrico. Al centro (fino a \( D_0 \)) la superficie è a quota 0, poi salta istantaneamente a quota 1 e rimane piatta.
- **Immagine 2D del Filtro:** È l'opposto dell'immagine del passa-basso: un **cerchio nero** (valore 0) al centro su uno **sfondo bianco** (valore 1).
- **Risultato sull'Immagine:** L'immagine risultante (ad esempio, Lena) sarà un'immagine estremamente scura in cui si vedranno **soltanto i contorni più netti e forti** (linee del viso, bordi del cappello, dettagli delle piume). Le aree uniformi (guance, sfondo) saranno quasi nere. Anche qui, a causa della natura ideale del filtro, i bordi evidenziati potrebbero presentare artefatti di ringing.

---

### Filtro High-Pass di Butterworth e Gaussiano

Analogamente al caso passa-basso, esistono versioni "morbide" del passa-alto per evitare artefatti.

### **Concetto a Parole e Formule**

Sono definiti come il complemento dei rispettivi filtri passa-basso.

- **Butterworth Passa-Alto:**
\[
H_{HP}(u,v) = \frac{1}{1 + \left[ \frac{D_0}{D(u,v)} \right]^{2n}} = 1 - \frac{1}{1 + \left[ \frac{D(u,v)}{D_0} \right]^{2n}}
\]
Nota che il rapporto \( D_0/D(u,v) \) è l'inverso di quello del passa-basso. Per \( D \) grandi (alte freq.), \( H \) tende a 1. Per \( D \) piccoli (basse freq.), \( H \) tende a 0. A \( D = D_0 \), \( H = 0.5 \).
- **Gaussiano Passa-Alto:**
\[
H_{HP}(u,v) = 1 - e^{-\frac{D^2(u,v)}{2 D_0^2}}
\]
È semplicemente 1 meno il Gaussiano passa-basso.

### **Diagramma e Risultati (Pagine 70-73)**

- **Grafici:** Le sezioni radiali saranno curve che partono da valori bassi (vicino a 0) al centro e salgono dolcemente verso 1 ai lati. Il Gaussiano ha la transizione più dolce.
- **Risultato sull'Immagine:** L'effetto di evidenziazione dei bordi sarà **più graduale e meno drastico** rispetto al filtro ideale. I bordi appariranno come linee chiare su uno sfondo grigio scuro (non nero), perché alcune basse frequenze non sono completamente eliminate. Questo produce spesso un effetto di "rilievo" o "sharpening" più naturale e meno soggetto ad artefatti.

---

### Filtri Band-Reject nel Dominio della Frequenza

Questa è una classe di filtri specializzata, usata per risolvere problemi specifici.

### **Concetto a Parole**

Il filtro "band-reject" o "band-stop" **attenua selettivamente una specifica banda (anello) di frequenze**, lasciando passare sia le frequenze più basse di questa banda, sia quelle più alte. L'applicazione classica è nella **rimozione del rumore periodico**.

**Esempio Pratico:** Se un'immagine è stata scannerizzata e presenta delle **righe orizzontali sottili e periodiche** (rumore del sensore), queste righe nello spettro di Fourier appariranno come **punti luminosi isolati** (o una linea) in una posizione specifica, lontana dal centro. Un filtro band-reject, posizionato proprio su quelle frequenze, può "bucare" (mettendo a zero) solo quelle componenti indesiderate, rimuovendo le righe dall'immagine senza sfocare eccessivamente il resto.

### **Tipi di Filtri Band-Reject (Pagina 74, 78)**

Come per i filtri precedenti, ne esistono di ideali, Butterworth e Gaussiani. La loro forma caratteristica è un **"buco" o un "avvallamento" anulare** nello spettro 2D.

1. **Ideale:** Crea un anello perfetto di spessore \( W \) a distanza \( D_0 \) dal centro, in cui \( H=0 \). Fuori dall'anello, \( H=1 \). Causa ringing.
2. **Butterworth:** Crea un avvallamento graduale attorno alla frequenza centrale \( D_0 \). Il parametro \( W \) definisce l'ampiezza della banda attenuata, \( n \) la pendenza delle pareti dell'avvallamento.
3. **Gaussiano:** Crea un avvallamento dalla forma di una gaussiana "invertita" lungo la direzione radiale. È il più morbido.

### **Spiegazione della Formula (Es. Ideale)**

\[
H(u,v) =
\begin{cases}
0 & \text{se } D_0 - W/2 \leq D(u,v) \leq D_0 + W/2 \\
1 & \text{altrimenti}
\end{cases}
\]

- \( D_0 \): **Frequenza centrale** della banda da respingere.
- \( W \): **Larghezza (width)** della banda. Controlla quanto è spesso l'anello che viene azzerato.

---

### Applicazione

La pagina "Applicazione" (79) e quelle successive (80-82) mostrano, tramite un esempio pratico e schematico, **l'intero flusso di lavoro del filtraggio nel dominio della frequenza**. Anche se il contenuto testuale è minimo, il diagramma di flusso è implicito nelle spiegazioni precedenti e si articola così:

1. **Input:** Immagine originale \( f(x,y) \).
2. **Pre-Processing:** Applicazione dello *zero-padding* (se necessario per evitare aliasing nella convoluzione circolare) alla matrice dell'immagine.
3. **Trasformazione:** Calcolo della DFT (spesso via FFT per efficienza) per ottenere \( F(u,v) \).
4. **Centraggio:** Applicazione dello *shift* per portare la frequenza zero al centro di \( F(u,v) \).
5. **Definizione del Filtro:** Creazione della matrice \( H(u,v) \) delle stesse dimensioni di \( F(u,v) \), secondo il tipo (Ideale, Butterworth, Gaussiano) e i parametri ( \( D_0, n, W \) ) scelti. Anche \( H(u,v) \) va shiftata.
6. **Filtraggio:** Moltiplicazione punto-punto: \( G(u,v) = F(u,v) \cdot H(u,v) \). Questa è l'operazione di filtraggio vera e propria, resa possibile dal Teorema della Convoluzione.
7. **De-Centraggio:** Applicazione dello *shift inverso* a \( G(u,v) \).
8. **Trasformazione Inversa:** Calcolo della IDFT (Inverse DFT) su \( G(u,v) \) per tornare al dominio spaziale, ottenendo \( g(x,y) \).
9. **Post-Processing:** Rimozione dello zero-padding aggiunto all'inizio.
10. **Output:** Immagine filtrata \( g(x,y) \), che mostra l'effetto del filtro (sfocatura, evidenziazione bordi, rimozione rumore periodico).

Questo processo è universale e si applica a tutti i tipi di filtri (low-pass, high-pass, band-reject) che hai studiato. La scelta di \( H(u,v) \) determina il risultato finale.