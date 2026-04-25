# Lezione 2: Operazioni sulle matrici

Un **immagine raster** può essere **rappresentata** da una **matrice**. Su una immagine **possono essere fatte tutte** le **operazioni** che si possono fare sulle **matrici**, ma non è detto che tali operazioni abbiano un senso logico, ad esempio cosa vuol dire moltiplicare due immagini a un punto di vista visivo?
Noi useremo le operazioni matriciali come base per operazioni più complesse.

Quando faremo l’operazione di prodotto tra due matrici non useremo la regola del riga per colonna, ma piuttosto il **punto a punto** degli elementi corrispondenti. In questo modo:

$$
 \begin{bmatrix}1 & 0 & 2 \\-1 & 3 & 1 \\\end{bmatrix} \cdot \begin{bmatrix}3 & 1 \\2 & 1\\1 & 0 \\\end{bmatrix}= \begin{bmatrix}5 & 1 \\4 & 2 \\\end{bmatrix}
$$

### Neighborhood $N_p$

- I vicini 4 connessi in un dato pixel sono quelli alla sua destra, alla sua sinistra, quelli sopra e quelli sotto
    
    ![image.png](Lezione%202%20Operazioni%20sulle%20matrici/8bfbb717-881f-4887-907b-6fc97e5348f6.png)
    
- I vicini 8 connessi sono quelli 4 connessi a cui si aggiungono i 4 pixel in diagonale
    
    ![image.png](Lezione%202%20Operazioni%20sulle%20matrici/e331fe04-cce2-432d-825c-90a41a51e4c3.png)
    

### Operazioni affini

Si tratta di una **classe di operazioni** delle immagini che non producono la variazione del valore del **pixel** ma ne **determinano** solamente la **nuova posizione**. Esse sono le operazioni di **identità, la rotazione, la traslazione, lo scaling, lo shear.**

Le operazioni affini possono essere definite con una **matrice 3x3** **chiamata T**. La forma più comune è la definizione tramite matrice.

### Forward mapping

Il forward mapping è un metodo in cui:

- prendi ogni pixel dell’immagine in input
- lo trasformi con una formula matematica
- scopri dove va a finire nell’immagine di output

I pixel di input vengono definiti dalle coordinate $(v, \space w)$, mentre quelli di output dalle coordinate $(x, \space y)$. Infine, come detto prima, T è la matrice affine che descrive le operazioni affini di trasformazione (traslazione, rotazione, scala, ecc…).

In pratica: T dice come spostare i pixel.

Per ottenere il valore, basta utilizzare la formula: $[x \space y \space 1] = [v \space w \space 1] \cdot T$

Cosa significa? Prendi in input il pixel alle coordinate $(v, \space w)$, lo scrivi come vettore $[v \space w \space 1]$, lo moltiplichi per la matrice T e ottieni la nuova posizione $(x, \space y)$.

Il numero 1 serve per poter includere le operazioni di traslazione.

Passo passo:

- scorri tutti i pixel dell’immagine di input
- per ogni pixel $(v, \space w)$:
    - applichi la trasformazione
    - calcoli $(x, \space y)$
- metti il valore del pixel di input nella posizione $(x, \space y)$ dell’immagine di input

**Esempio concreto:**

Immagina una traslazione a destra di 10 pixel. Sappiamo che l’asse orizzontale è x, dunque:

- pixel di input $(v = 5, \space w = 7)$
- trasformazione “+10 su x”

Risultato

- pixel di output: (x = 15, y = 7)

Hai preso un pixel e gli hai detto dove andare.

Aggiungendo l'**1**, stiamo praticamente portando il nostro pixel 2D in uno spazio 3D, ma lo appoggiamo su un "vassoio" che si trova all'altezza $z = 1$.

### La "Mappa" della Matrice Affine $3 \times 3$

In questa tabella vedi cosa controlla ogni cella. Ricorda che le colonne decidono il risultato finale (x o y), mentre le righe decidono quale dato in input andare a pescare (v, w o l'1 delle coordinate omogenee).

$T = \begin{pmatrix}
\color{blue}{s_x \text{ (Scala X)}} & \color{green}{r \text{ (Ruota)}} & 0 \\
\color{green}{r \text{ (Ruota)}} & \color{blue}{s_y \text{ (Scala Y)}} & 0 \\
\color{red}{t_x \text{ (Sposta X)}} & \color{red}{t_y \text{ (Sposta Y)}} & 1
\end{pmatrix}$

Prima colonna = x
Seconda colonna = y
Terza colonna = “colonna di servizio per le coordinate omogenee sulla traslazione”

[Svolgimento esercizi](Lezione%202%20Operazioni%20sulle%20matrici/Svolgimento%20esercizi%202d11cf23380e80b6b137f81c6d70ed5a.md)

### Inverse mapping

Abbiamo visto il forward mapping, l’unico problema causato da questi straordinari calcoli è che lasciano dei buchi sull’immagine in output.

![image.png](Lezione%202%20Operazioni%20sulle%20matrici/image.png)

![image.png](Lezione%202%20Operazioni%20sulle%20matrici/image%201.png)

L'**Inverse Mapping** è la strategia più utilizzata nell'elaborazione delle immagini perché risolve in modo elegante i problemi che abbiamo visto con il Forward Mapping (come i "buchi" o l'effetto "sale e pepe").

**1. L’Algoritmo**

1. **Crea** una griglia vuota per l'immagine di output.
2. **Scansiona** ogni pixel (x, y) della nuova immagine.
3. **Applica la Matrice Inversa** $T^{-1}$ per trovare le coordinate originali (v, w).
4. **Preleva il colore** dalla posizione (v, w) dell'immagine originale.
5. **Copia** il colore nella posizione (x, y) dell'output

**Tabella Rapida delle Trasformazioni Inverse** 

| Operazione | Se l'andata (T) è… | L’inversa ($T^{-1}$) sarà… |
| --- | --- | --- |
| Traslazione | Sposta di +10 | Sposta di -10 |
| Scalatura | Ingrandisce di (x2) | Rimpicciolisce di (x0.5) |
| Rotazione | Ruota di $\theta$ | Ruota di **$\theta$**  antiorario (Trasposta) |

[Esercizi Guida (Svolti)](Lezione%202%20Operazioni%20sulle%20matrici/Esercizi%20Guida%20(Svolti)%202d11cf23380e80c297ccda1d7c4d84ad.md)

### Interpolazione

Nel corso delle trasformazioni, potrebbero esserci dei valori di pixel che non sono mai individuati dalle formule. Per essi si applica un **processo di interpolazione**. Ossia il processo che, **partendo da dati reali, stima i dati non conosciuti**. L’interpolazione non comporta un miglioramento della qualità, ma piuttosto ci fornisce dei valori ignoti mancanti stimandoli da valori reali.

### Zooming

L’interpolazione è effettuata anche nei processi di zooming.

Se parliamo di ***Zooming In***, in 2x vuol dire che le dimensioni dell’immagine verranno raddoppiate. Parlando di uno zoom 2x in una matrice m x n allora diverrà 2m x 2n, ciò indica che il totale di pixel verrà quadruplicato. Ovviamente ci sono altri tipi di scala nello zooming, e non solo 2x.

![Zooming In 2x](Lezione%202%20Operazioni%20sulle%20matrici/image%202.png)

Zooming In 2x

Dopo aver posizionato i valori già noti, occorre stimare i valori nelle zone vuote.

### Vari tipi di interpolazione

- **Nearest neighbor (o replication)**
- **Bilinear**
- **Bicubic**

![image.png](Lezione%202%20Operazioni%20sulle%20matrici/image%203.png)

### Nearest neighbor / Replication

L'interpolazione **nearest neighbor** per le immagini funziona **copiando il valore del pixel più vicino ai nuovi pixel creati** quando si ingrandisce una matrice di pixel.

Pensa ad un'immagine che puoi rappresentare come una **matrice di pixel**, dove ogni elemento della matrice ha un valore che rappresenta il colore o l'intensità del pixel. Se vuoi **ridimensionare** l'immagine (ad esempio ingrandirla), hai bisogno di "inventare" nuovi pixel che riempiano lo spazio tra quelli originali.

Supponiamo di voler zoomare un’immagine di dimensione 2x2 in 4x4.

| A | B |
| --- | --- |
| C | D |

Quando espandi a una matrice 4x4, ci saranno nuovi "spazi vuoti" in mezzo che devono essere riempiti. Con il metodo nearest neighbor, ogni nuovo pixel viene semplicemente **riempito copiando il valore del pixel più vicino** della matrice originale.

La matrice ingrandita 4x4 con nearest neighbor potrebbe diventare:

| A | A | B | B |
| --- | --- | --- | --- |
| A | A | B | B |
| C | C | D | D |
| C | C | D | D |

Questo fa sì che le aree dei nuovi pixel siano piuttosto **squadrate** e non fluide, perché non c'è una transizione graduale tra i colori. Questo può creare un effetto a **blocchi**, soprattutto se l'immagine viene ingrandita molto.

### Bilineare

L’interpolazione bilineare utilizza i quattro pixel più vicini al punto. Supponendo di avere le coordinate $(x,y)$ della posizione a cui assegnare un nuovo valore di intensità, e supponendo che $v(x,y)$ equivalga al valore stesso dell’intensità, si può utilizzare un’equazione:

$$
v(x,y) = ax + by +cxy+d
$$

Dove $a$, $b$, $c$ e $d$, ossia i **quattro coefficienti** vengono **determinati** utilizzando i **valori di intensità** dei **quattro pixel** noti **attorno al punto**.

E $(x, y)$ rappresenta le coordinate della posizione dove vuoi stimare il valore dell’intensità.

I quattro coefficienti $a$, $b$, $c$ e $d$ vengono calcolati risolvendo un **sistema di quattro equazioni**. Queste equazioni derivano dai valori di intensità dei quattro pixel noti che circondano il punto  . Quindi, il valore di intensità nel nuovo punto dipende da una combinazione ponderata di questi quattro pixel.

Determinare i coefficienti $a$, $b$, $c$, $d$ nella formula dell'interpolazione bilineare:
$v(x, y) = ax + by + cxy + d$

### Passo 1: Identificare i Valori di Intensità

Abbiamo i seguenti valori di intensità associati alle coordinate:

- $V(1, 1) = 1$
- $V(1, 3) = 2$
- $V(3, 1) = 6$
- $V(3, 3) = 7$

### Passo 2: Costruire le Equazioni

Utilizziamo i valori di intensità per costruire un sistema di equazioni. Ogni equazione corrisponde a un punto noto e ci permette di esprimere le intensità in funzione dei coefficienti $a$, $b$, $c$, $d$.

### Equazione per il Punto $(0, 0)$

1. **Punto**: $(0, 0)$
    - Questo punto corrisponde a $V(1, 1) = 1$.
    - Sostituendo nella formula:
    $v(0, 0) = a(0) + b(0) + c(0)(0) + d = d$
    - Quindi abbiamo:
    $d = 1$

### Equazione per il Punto (1, 0)

1. **Punto**: $(1, 0)$
    - Questo punto corrisponde a  $V(1, 3) = 2.$
    - Sostituendo nella formula:
    $v(1, 0) = a(1) + b(0) + c(1)(0) + d = a + d$
    - Sostituiamo il valore di $d = 1$:
    $a + 1 = 2$
    - Risolvendo:
    $a = 2 - 1 = 1$

### Equazione per il Punto (0, 1)

1. **Punto**: $(0, 1)$
    - Questo punto corrisponde a $V(3, 1) = 6$.
    - Sostituendo nella formula:
    $v(0, 1) = a(0) + b(1) + c(0)(1) + d = b + d$
    - Sostituiamo il valore di $d = 1$:
    $b + 1 = 6$
    - Risolvendo:
    $b = 6 - 1 = 5$

### Equazione per il Punto (1, 1)

1. **Punto**: $(1, 1)$
    - Questo punto corrisponde a $V(3, 3) = 7$.
    - Sostituendo nella formula:
    $v(1, 1) = a(1) + b(1) + c(1)(1) + d = a + b + c + d$
    - Sostituiamo i valori trovati per $a$, $b$, e $d$:
        - Con $a=1$, $b=5$, e $d=1$:
        - Quindi:
        $v(1, 1)=a+b+c+d=7$
        Diventando:
        $1 + 5 + c + 1 = 7$
        Risolvendo:
        $c + 7 = 7$
        Quindi:
        $c=7-7=0$

### Passo 3: Coefficienti

Dopo aver costruito tutte le equazioni e risolto per i coefficienti abbiamo:

- Coefficiente:
    - $d=1$
    - $a=1$
    - $b=5$
    - $c=0$

### Passo 4: Formula di Interpolazione

Ora possiamo inserire questi coefficienti nella formula dell'interpolazione bilineare:
$v(x,y) = ax + by + cxy + d$

Diventando:

$v(x,y) = x + 5y + 0xy + 1$

### Passo 5: Calcolare l'Intensità

Ora possiamo calcolare il valore di intensità per un punto specifico. Ad esempio, per il punto $(x,y)=(2,2)$:
$v(2,2) = (2) + (5)(2) + (0)(2)(2) + (1)$

Calcoliamo:
$= 2 + 10 + 0 + 1\\
= 13$

Quindi il valore stimato dell'intensità al punto (2,2) è **13**.

---

### Bicubic

L’interpolazione bicubica utilizza i **sedici pixel più vicini al punto**. Per ottenere i valori bisogna utilizzare questa equazione:

$$
v(x,y)=\sum_{i=0}^{3}\sum_{j=0}^{3}\space a_{ij} \space x^iy^j
$$

I sedici coefficienti sono determinati attraverso sedici equazioni in sedici incognite che possono essere scritte utilizzando i sedici punti più vicino a (x, y).
Ovviamente l’interpolazione bicubica conserva meglio i dettagli e fornisce un’immagine più fluida rispetto all’interpolazione bilinare o replicata.

![image.png](Lezione%202%20Operazioni%20sulle%20matrici/image%204.png)

**Cosa fare ai bordi?**
Un **problema** è quello dei bordi: come fare l’interpolazione ai bordi?
Possibili soluzioni:

1. Non fare nulla
2. Interpolare con i valori presenti anche se in numero minore di quelli usati per altri pixel.

**Considerare solo le zone centrali dell’immagine:** in questo caso non si calcolano i valori ai bordi.

![image.png](Lezione%202%20Operazioni%20sulle%20matrici/image%205.png)

Dopo aver fatto i calcoli replicare le ultime righe e colonne: in questo caso per fare i calcoli si replicano semplicemente i valori nelle righe e nelle colonne “isolate”.

![image.png](Lezione%202%20Operazioni%20sulle%20matrici/image%206.png)

### Zooming Out

Se lo zoom è fatto con un numero inferiore ad 1, si ottiene ovviamente una immagine più piccola dell’originale, dato che di default la dimensione dell’immagine originale corrisponde ad uno zoom pari ad 1.

Se riduco l’immagine, ho un processo detto di “**decimazione**”.

Data una immagine $m \times n$ con uno zooming out di 0,5, si otterrà una immagine di $m/2 \times n/2$.

### Decimazione

- **Metodo 1**
Ogni quattro pixel se ne sceglie uno.
    
    ![image.png](Lezione%202%20Operazioni%20sulle%20matrici/image%207.png)
    
- **Metodo 2**
Di quatto pixel se ne calcola il valore medio.
Quindi si fa la somma dei pixel e si divide per il numero di essi.
In questo caso si sommano i 4 pixel e si divide il risultato per 4.
    
    ![image.png](Lezione%202%20Operazioni%20sulle%20matrici/48c87855-4e0c-43bf-ab3a-cc095c65499f.png)
    

### Stima della qualità di un algoritmo

Esistono 2 **algoritmi per stimare la qualità di un’immagine dopo il processo di interpolazione e compressione** (ad esempio il passaggio a JPEG). 

Ci aiutano a misurare quanto un’immagine sia stata “danneggiata”  alterata rispetto all’immagine originale denominata perfetta.

- **MSE (Mean Square Error - Errore Quadratico Medio)**
L’MSE rappresenta la **distanza matematica pura** tra due immagini.
Immagina di sovrapporre l’immagine originale ($I$) e quella modificata ($I’$) e di confrontare ogni singolo pixel nella stesso posizione $(x,y)$.

**Come funziona?** Per ogni coppia di pixel corrispondenti, l’algoritmo calcola la differenza di intensità, la eleva al **quadrato** (per rendere l’errore sempre positivo e “punire” maggiormente le differenze grandi) e infine calcola la **media** di tutti questi quadrati sulla superficie dell’immagine $(M \times N)$.

**Significato del valore:** Più il valore dell’MSE è **vicino allo zero**, maggiore è la fedeltà dell’immagine modificata rispetto all’originale. Se l’MSE fosse zero, allora le due immagini sarebbero identiche bit per bit.
    
    $$
    MSE = \frac{1}{MN} \sum_{x=1}^{M} \sum_{y=1}^{N} \left[ I'(x,y) - I(x,y) \right]^2
    $$
    
- **PSNR (Peak Signal to Noise Ratio - Rapporto segnale/rumore di picco)**
    
    Il **PSNR (Peak Signal to Noise Ratio)** è un parametro matematico utilizzato per **misurare la qualità di un'immagine** che ha subito un processo di modifica (come la compressione JPEG o l'ingrandimento) rispetto all'immagine originale.
    
    Immagina il PSNR come un punteggio di fedeltà. Per calcolarlo, devi obbligatoriamente confrontare due immagini: quella "perfetta" originale e quella modificata. 
    
    **Il rapporto tra "Segnale" e "Rumore"**
    Il nome stesso ti dice cosa sta misurando:
    
    - **Peak Signal (Segnale di Picco):** rappresenta il valore massimo che un pixel può avere. Nelle immagini standard a 8 bit, questo valore è **255**.
    - **Noise (Rumore):** rappresenta l'errore introdotto, ovvero la differenza tra i pixel dell'immagine originale e quella modificata. Questo errore viene calcolato tramite l'**MSE** (Errore Quadratico Medio).
    
    L'algoritmo mette in rapporto questi due dati usando una scala logaritmica espressa in **decibel (dB)**.
    
    Come leggere il risultato
    
    A differenza dell'MSE (dove un valore basso è positivo), per il **PSNR vale la regola: più è alto, meglio è**.
    
    - Un **PSNR elevato** indica che l'immagine modificata è molto simile all'originale (alta qualità).
    - Un **PSNR basso** indica che c'è molta differenza (distorsione) e quindi la qualità è scarsa.
    
    **Perché si usa il logaritmo?**
    
    Si utilizza una scala logaritmica perché la percezione umana dell'intensità luminosa non è lineare, ma segue appunto una funzione logaritmica. Il PSNR cerca quindi di trasformare un errore numerico in un valore che si avvicini (anche se in modo imperfetto) alla sensibilità dell'occhio.
    
    **I limiti (Cosa il PSNR "non vede")**
    Nonostante sia il parametro più diffuso, il PSNR ha dei difetti importanti legati al sistema visivo umano (**HVS**):
    
    - **Sensibilità spaziale:** Se sposti un'immagine di un solo pixel (traslazione) o la ruoti leggermente, per l'occhio umano l'immagine è identica, ma per il PSNR il punteggio crolla drasticamente perché i pixel non corrispondono più matematicamente nella griglia.
    - **Mancanza di contesto:** Il PSNR tratta ogni errore allo stesso modo, mentre l'occhio umano è più o meno sensibile agli errori a seconda che si trovino in zone chiare, scure o con molti dettagli.
    
    **In sintesi:** **Il PSNR trasforma la "distanza" matematica tra due immagini (l'errore MSE) in un indice di qualità espresso in decibel.** Se stai comprimendo una foto e il PSNR aumenta, significa che stai facendo un buon lavoro e che l'immagine finale è più **"fedele"** all'originale.
    
    $$
    PSNR = -10 \log_{10} \frac{MSE}{S^2}
    \\
    \\
    PSNR = 20 \log_{10} \left( \frac{S}{\sqrt{MSE}} \right)
    \\
    \\
    PSNR = 10 \log_{10} \left( \frac{S^2}{MSE} \right)
    $$