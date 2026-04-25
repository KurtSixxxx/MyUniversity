# Lezione 8: Operazioni puntuali

### Istogramma

In un’immagine digitale per conoscere la distribuzione delle frequenze dei toni di grigio si utilizza l’istogramma.

L’istogramma è un grafico che ci fornisce per ogni livello di grigio il numero di pixel che hanno quella intensità.

$$
H(k) = \text{il numero di pixel aventi valore k}
$$

La somma di tutti gli $H$ è esattamente l’immagine $\text{mxn}$.

E’ importante sottolineare che l’istogramma non tiene conto della distribuzione spaziale, infatti due immagini diverse possono avere lo stesso istogramma, poiché si basa solo sui toni di grigio.

![image.png](Lezione%208%20Operazioni%20puntuali/image.png)

Una “lettura” veloce dell’istogramma può essere effettuata tenendo a mente questi due concetti:

- Immagine chiara: istogramma più denso a destra
    
    ![image.png](Lezione%208%20Operazioni%20puntuali/image%201.png)
    
- Immagine scura: istogramma più denso a sinistra
    
    ![image.png](Lezione%208%20Operazioni%20puntuali/image%202.png)
    

### Contrast Stretching (Espansione del contrasto)

Prima di introdurre il concetto di Contrast Stretching è importante spiegare cos'è la **dinamica di un’immagine**.

Quando si parla di dinamica di un'immagine, si intende l'**intervallo di valori di intensità che l'immagine utilizza**. In altre parole: quanto l'immagine riesce a coprire lo spettro che va dal nero più scuro al bianco più chiaro.

In un'immagine in scala di grigi a 8 bit, i valori possibili vanno da **0** (nero) a **255** (bianco). Questa è la dinamica massima. In mezzo a questi valori ci sono i grigi, però spesso un'immagine non utilizza tutto questo intervallo [0, 255]. Magari in una immagine il pixel più scuro vale 90 e quello più chiaro vale 140. Questo è un chiaro esempio in cui l'immagine ha una dinamica molto ridotta ma potrebbe utilizzarne una molto più ampia.

La **dinamica** è quindi una **misura** di **quanto è “spalmata” l’informazione luminosa nell’immagine**. Se i valori sono distribuiti su tutto l’intervallo disponibile, l’immagine avrà contrasti forti e dettagli ben distinguibili. Se invece sono concentrati in una fascia stretta, l’immagine apparirà piatta, grigia, poco leggibile.

In sintesi: la dinamica di un’immagine è **l’intervallo dei livelli di intensità effettivamente utilizzati per rappresentarla**.

Adesso che sappiamo cos’è la dinamica, possiamo capire che molto spesso in un’immagine c’è il problema del poco utilizzo della dinamica disponibile. Questo causa un’immagine visivamente “spenta”, con pochi dettagli e poco contrasto, perché le differenze di intensità sono compresse in un intervallo ristretto.

L’idea del **contrast stretching** è di **ridistribuire i livelli di intensità** in modo da **sfruttare** meglio **l’intero intervallo disponibile**. Si prende l’intervallo effettivamente usato dall’immagine e lo si “stira” per farlo coincidere con l’intervallo completo. Così le differenze tra pixel diventano più evidenti e i dettagli emergono con maggior chiarezza.

Si ottiene applicando **algoritmi** che spostano i valori dei pixel da un bin dell’istogramma a un altro.

Il bin di un istogramma è  semplicemente **un contenitore di valori**. Ogni bin rappresenta **un intervallo di intensità**, e dentro quel contenitore finiscono tutti i pixel che hanno un valore compreso in quell’intervallo. Però un bin **non è obbligato a rappresentare un solo valore**. Può rappresentare anche un intervallo più ampio, per esempio da 0 a 7, da 8 a 15, e così via.
Il significato del bin è quindi questo: **è la casella che raccoglie i pixel con intensità simile**. L’altezza del bin nell’istogramma indica quanti pixel dell’immagine hanno valori che cadono in quell’intervallo. Se un bin è alto, vuol dire che quell’intensità è molto presente nell’immagine. Se un bin è vuoto, vuol dire che quell’intervallo di valori **non viene mai usato**.

Dopo l’applicazione del contrast stretching, l’istogramma dell’immagine cambia aspetto in modo evidente. Non è più massa compatta concentrata in una zona ristretta, ma assume una forma come quella di un pettine, con bin alternati pieni e vuoti. Questo non è un difetto, ma una conseguenza diretta dell’operazione: i livelli originariamente concentrati vengono mappati su due livelli più distanti tra loro, lasciando “buchi” intermedi.

Il **contrast stretching non crea nuove informazioni, ma rende più leggibili quelle già presenti**. I dettagli c’erano anche prima, ma erano compressi in una gamma troppo stretta per essere percepiti bene dall’occhio umano. Espandendo la dinamica, l’immagine diventa più chiara, più contrastata e visivamente più utile.

![image.png](Lezione%208%20Operazioni%20puntuali/image%203.png)

![image.png](Lezione%208%20Operazioni%20puntuali/image%204.png)

### Aritmetica sulle immagini

Operando aritmeticamente può accadere che un pixel abbia:

1. Un valore negativo;
2. Un valore maggiore del massimo (tipicamente 255);
3. Un valore non intero (facilmente risolubile con una approssimazione o un troncamento);

I problemi a. e b. vengono chiamati “**problemi di range**”, e vi sono due soluzioni:

- Settare a 0 (nero) i valori negativi e 255 (bianco) i valori maggiori di 255.
- Ri-normalizzare il range trasformando ciascun valore secondo l’equazione:

$$
v_{\text{nuovo}} = 255 \space \cdot \space \frac{(v_{\text{vecchio}} - min_{\text{osservato}})}{(max_{\text{osservato}} - min_{\text{osservato}})}
$$

Cerchiamo di spiegare l’equazione:

- $v$: Sta per **valore**. Indica l'intensità di grigio di un pixel (per esempio, quanto è chiaro o scuro).
- **vecchio ($v_{vecchio}$)**: È il **valore originale** del pixel nell'immagine che vogliamo migliorare, quella che appare "spenta" o poco contrastata.
- **osservato ($MIN_{osservato}$ e $MAX_{osservato}$)**: Si riferisce ai valori minimi e massimi che **troviamo effettivamente** dentro l'immagine originale. Se in una foto il pixel più scuro ha valore 80 e il più chiaro 140, allora il tuo $MIN_{osservato}$ è 80 e il $MAX_{osservato}$ è 140.
- **nuovo ($V_{nuovo}$)**: È il **risultato finale**, ovvero il nuovo valore che il pixel assumerà dopo che avremo "stirato" il contrasto per coprire tutta la dinamica

Filo logico dell’equazione:

- **Sottrazione ($v_{vecchio} - MIN_{osservato}$)**: Sottraendo il minimo, "spostiamo" l'istogramma in modo che il pixel più scuro parta da zero.
- **Rapporto ($\frac{...}{MAX - MIN}$)**: Dividendo per la differenza tra massimo e minimo, capiamo in che posizione percentuale si trova il pixel rispetto al totale dei toni usati.
- **Moltiplicazione per 255**: Infine, proiettiamo quella posizione sulla scala massima (8-bit) per ottenere il nuovo grigio

### Equalizzazione

Quando abbiamo un’**istogramma uniforme** o appiattito allora abbiamo un’**immagine equalizzata**: il **contributo** di ogni differente tonalità di **grigio** è pressappoco **uguale**.

L’equalizzazione si ottiene usando appositi algoritmi. E’ importante specificare che **non sempre l’equalizzazione migliora l’immagine**.

![image.png](Lezione%208%20Operazioni%20puntuali/image%205.png)

![Come si vede qui, nonostante l’immagine sia equalizzata, l’immagine non risulta “bella” alla vista.](Lezione%208%20Operazioni%20puntuali/image%206.png)

Come si vede qui, nonostante l’immagine sia equalizzata, l’immagine non risulta “bella” alla vista.

### Algoritmo di Equalizzazione

$$
p_r(r_k) = \frac{n_k}{MN} \\ k = 0, 1, 2, ..., L - 1
$$

Questo è semplicemente il calcolo della **Probabilità. Lo useremo come lo strumento per mappare la distribuzione dei colori.**

- $n_k$ é il conteggio puro. Indica quanti pixel nell’immagine hanno esattamente quel livello di grigio $k$.
- $MN$ è il numero totale di pixel dell’immagine (Larghezza $M$ $\times$ Altezza $N$).
- $p_r(r_k)$ è il risultato della divisione. Non ti dice “quanti” pixel ci sono, ma **che percentuale** dell’immagine è occupata da quel colore (un numero tra 0 e 1).

![image.png](Lezione%208%20Operazioni%20puntuali/image%207.png)

- **Asse X** $(r_k)$: Sono i livelli di grigio possibili (es. 0, 1, 2, …, fino a 255). E’ la scala del colore.
- **Asse Y** $(p_r(r_k))$: E’ la probabilità che abbiamo appena calcolato $(\frac{n_k}{MN})$. Indica la “frequenza” o l’altezza della barretta per quel colore.

In pratica il grafico è una mappa che dice “quanto è probabile trovare il grigio $r_k$ in questa immagine”.

$$
s_k = T(r_k) = (L - 1) \sum_{j=0}^{k}p_r(r_j)
$$

Questa invece è la formula di equalizzazione, è una tecnica di "ridistribuzione" statistica.

- $r_k$ → livelli di grigio
- $p_r(r_k) = \frac{n_k}{MN}$ → probabilità di occorrenza di un livello di grigio
- $n_k$ → numero di pixel con quel livello di grigio
- $MN$ → tutti i pixel, ossia la matrice immagine (Larghezza $\times$ Altezza)
- $s_k$ → nuovi valori di grigio
- $T(r_k)$ → funzione di trasformazione → somma cumulata della probabilità
- $L-1$ → valore massimo dei valori di grigio (es. 7 per una immagine a 3 bit)

Esempio di applicazione: 

Sia data una immagine a 3 bit (L=8) con 64x64 pixel (MN=4096) con la seguente distribuzione di intensità.

La probabilità si ottiene dividendo il nuovo numero di pixel per il totale $MN$:

- $s_0=1 \rightarrow 790 / 4096 = 0.19$
- $s_1=3 \rightarrow 1023 / 4096 = 0.25$
- ...e così via.

![image.png](Lezione%208%20Operazioni%20puntuali/image%208.png)

- Livello di grigio $r_0 = 0$ e ha $790$px → corrispondenti a probabilità $0.19$
- Livello di grigio $r_1 = 1$ e ha $1023$px → corrispondenti a probabilità $0.25$
- per trovare il nuovo valore $s_0$ → moltiplichiamo il massimo livello possibile ($7$) per la probabilità di quel livello $s_0$ → $7 \cdot 0.19 = 1.33$, che arrotondato diventa $1$.
- per il livello successivo $s_1$, sommiamo la probabilità di $r_0$ e $r_1$ prima di moltiplicare, quindi → s$_1 = 7 \cdot (0.19 + 0.25) = 7 \cdot 0.44 = 3.08$, che arrotondato diventa $3$

Ecco tutti i passaggi:

| $r_k$ | $P_r(r_k) = \frac{n_k}{MN}$ | Operazioni | $s_k$ |
| --- | --- | --- | --- |
| $r_0 = 0$ | $0.19$ | $7 \cdot 0.19 = 1.33 → 1$ | $1$ |
| $r_1 = 1$ | $0.25$ | $7 \cdot (0.19 + 0.25) = 7 \cdot 0.44 = 3.08 → 3$ | $3$ |
| $r_2 = 2$ | $0.21$ | $7 \cdot (0.44 + 0.21) = 7 \cdot 0.65 = 4.55 → 5$ | $5$ |
| $r_3 = 3$ | $0.16$ | $7 \cdot (0.65 + 0.16) = 7 \cdot 0.81 = 5.67 → 6$ | $6$ |
| $r_4 = 4$  | $0.08$ | $7 \cdot (0.81 + 0.08) = 7 \cdot 0.89 = 6.23 → 6$ | $6$ |
| $r_5 = 5$ | $0.06$ | $7 \cdot (0.89 + 0.06) = 7 \cdot 0.95 = 6.65 → 7$ | $7$ |
| $r_6 = 6$ | $0.03$ | $7 \cdot (0.95 + 0.03) = 7 \cdot 0.98 = 6.86 → 7$ | $7$ |
| $r_7 = 7$ | $0.02$ | $7 \cdot (0.98 + 0.02) = 7 \cdot 1 = 7$ | $7$ |

![image.png](Lezione%208%20Operazioni%20puntuali/image%209.png)

## Operazioni sulle immagini e Operatori puntuali

Un'immagine è una griglia di numeri e manipolare un'immagine significa semplicemente applicare una **regola matematica** a ciascuno di quei numeri, in modo indipendente. La nostra bussola sarà la formula magica:

$$
 g(x,y) = T[f(x,y)]
$$

### **Fase 1: Le Basi**

Prima di tuffarci nella matematica, dobbiamo metterci d'accordo sul "campo di gioco". Per non impazzire, gli ingegneri hanno fatto una semplificazione geniale:

1. **Lavoriamo in Bianco e Nero (Scala di Grigi).** Perché? Perché è semplicissimo. In un'immagine in bianco e nero, ogni **pixel** (il quadratino più piccolo dell'immagine) è descritto da **un solo numero**. Di solito, questo numero va da 0 a 255.
    - **0 = Nero assoluto.**
    - **255 = Bianco assoluto.**
    - **128 = Grigio medio.**
    Tutto qui. Un numero, una luminosità.
2. **E i colori?** Un'immagine a colori (RGB) è come se fossero **tre immagini in bianco e nero sovrapposte**: una per il Rosso (R), una per il Verde (G), una per il Blu (B). Quindi, tutto quello che impareremo sul bianco e nero, potrà essere applicato **tre volte** (una per canale) per modificare un'immagine a colori. È un trucco per semplificare la vita.

**La Prima Grande Verità:** Un'operazione sulle immagini è qualsiasi cosa che **alteri i numeri** della griglia. Cambi i numeri, cambi l'immagine che vedi.

### **Fase 2: La Formula-Chiave - Smontiamola Pezzo per Pezzo**

$$
 ⁍
$$

Questa formula è il vocabolario di base. Se la capisci, capisci tutto il capitolo. Non è magia, è solo un modo preciso per dire una cosa semplice.

Immagina una catena di montaggio in una fabbrica di mattoncini Lego:

- Arriva un mattoncino grezzo.
- Passa in una macchina che lo modifica.
- Esce il mattoncino finito.

Ecco, per le immagini è **esattamente lo stesso**.

- **$f(x,y)$** - **L'Input (il mattoncino grezzo).** È il **valore originale** del pixel che si trova alla posizione $(x,y)$. Le coordinate $(x,y)$ sono solo l'"indirizzo" del pixel (esempio: colonna 10, riga 5). $f$ è il numero, ad esempio **100** (un grigio medio).
- **$T$** - **La Trasformazione (la macchina in fabbrica).** È la **regola** che vogliamo applicare. Può essere "aggiungi 50", "fai il negativo", "raddoppia il valore". È il "cosa" vogliamo fare.
- **$g(x,y)$** - **L'Output (il mattoncino finito).** È il **nuovo valore** che il pixel avrà dopo essere passato attraverso la macchina $T$.

**Esempio Numerico Concretissimo:**
Supponiamo che la regola $T$ sia: **"Aggiungi 30 di luminosità"**.
Hai un pixel in posizione (2,2) con valore $f(2,2) = 80$.
Cosa succede?
$g(2,2) = T[80] = 80 + 30 = 110$.
Il pixel in (2,2) ora vale **110**, ed è quindi più chiaro.

**Ricorda:** $x$ e $y$ servono solo a trovare il pixel. Il calcolo si fa **sul suo valore numerico**.

### **Fase 3: I Tipi di Operazioni - Puntuali, Locali, Globali**

Ora, la macchina $T$ per decidere come cambiare un pixel, quanti pixel intorno può guardare? Questa distinzione è fondamentale.

- **Operazione Puntuale (il nostro focus):** La macchina $T$ è **miope**. Guarda **solo ed esclusivamente** il pixel che sta processando. Per cambiare il pixel in (2,2), guarda solo il valore $f(2,2)$. Non gli importa nulla dei pixel vicini. È come un operaio che modifica un singolo mattoncino senza guardare quelli accanto.
- **Operazione Locale:** La macchina $T$ guarda un **piccolo quartiere** intorno al pixel. Ad esempio, per sfocare, prende il pixel centrale e i suoi 8 vicini, ne fa la media e assegna quel valore al centro. Qui $T$ lavora su un gruppo.
- **Operazione Globale:** La macchina $T$ deve analizzare **l'intera immagine** (tutti i pixel) per decidere come cambiare anche solo un pixel. È il caso più complesso.

**Noi ci concentriamo solo sulle operazioni PUNTUALI.** Sono le più semplici da capire e da implementare.

### **Fase 4: Cosa Sono gli Operatori Puntuali?**

Abbiamo detto che un operatore puntuale guarda solo il valore del pixel stesso. Questo ha una conseguenza potentissima: possiamo descrivere completamente l'operatore con una **tabella di corrispondenza** o un **grafico**.

- **Definizione formale:** Un operatore puntuale prende in input il valore di un pixel e restituisce un nuovo valore che **dipende solo ed esclusivamente** da quel valore in input.
- **La LUT (Look-Up Table - Tabella di Consultazione):** Dato che un pixel in scala di grigi può avere solo 256 valori possibili (0-255), possiamo creare una tabella che, per ogni possibile input, ci dice l'output.

| IN (Input) | 0 | 1 | 2 | ... | 50 | ... | 200 | ... | 255 |
| --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
| **OUT (Output)** | T(0) | T(1) | T(2) | ... | T(50) | ... | T(200) | ... | T(255) |

**Come funziona nella pratica?** Il computer, invece di fare calcoli complicati per milioni di pixel, fa questo:

1. Trova un pixel di valore 50.
2. Va alla riga "50" della tabella LUT.
3. Legge il valore corrispondente, ad esempio 180.
4. Sostituisce 50 con 180.
Fine. Velocissimo.

### **Fase 5: Il Grafico Cartesiano della LUT**

![image.png](Lezione%208%20Operazioni%20puntuali/image%2010.png)

![image.png](Lezione%208%20Operazioni%20puntuali/image%2011.png)

Il grafico è semplicemente la **rappresentazione visiva della tabella LUT**.

- **Asse X (Orizzontale):** Rappresenta il **valore di INGRESSO del pixel** ($f(x,y)$). A sinistra (0) hai il **nero**, a destra (255) hai il **bianco**.
- **Asse Y (Verticale):** Rappresenta il **valore di USCITA del pixel** ($g(x,y)$). In basso (0) c'è il **nero**, in alto (255) il **bianco**.

**Come si legge?**

1. Prendi un valore di input sull'asse X (es. 100).
2. Sali verticalmente fino a incontrare la **curva** (la linea nel grafico).
3. Da quel punto, vai in orizzontale verso l'asse Y e leggi il valore di output.

**La Curva è la Regola $T$.** La sua forma ti dice tutto:

- Se la curva è **sopra la linea diagonale** (la linea che va da (0,0) a (255,255)), significa che per ogni input, l'output è **più alto**. Traduzione: **STIAMO SCHIARENDO L'IMMAGINE.**
- Se la curva è **sotto la diagonale**, l'output è sempre più basso dell'input. Traduzione: **STIAMO SCURENDO L'IMMAGINE.**
- Se la curva coincide con la diagonale, input = output. Non succede nulla.

Facciamo un esempio:

In questo caso il valore in input (asse x orizzontale) 85, viene cambiato in output (asse y verticale) 135.
E questo verrà fatto per ogni pixel dell’immagine che avrà valore di input 85.

---

In questo secondo caso abbiamo **definito 4 punti di controllo** sulla curva.

**Cosa fanno questi punti?** Obbligano la regola di trasformazione a passare per questi 4 comandi precisi:

1. Se il valore di input è **46**, l'output **deve essere** 32.
2. Se il valore di input è **97**, l'output **deve essere** 123.
3. Se il valore di input è **167**, l'output **deve essere** 108.
4. Se il valore di input è **191**, l'output **deve essere** 182.

![image.png](Lezione%208%20Operazioni%20puntuali/image%2012.png)

![image.png](Lezione%208%20Operazioni%20puntuali/image%2013.png)

**Ma la magia vera è questa:** Il software, per rispettare TUTTI questi comandi contemporaneamente, **calcola automaticamente una curva continua** (una regola morbida) che passa per tutti questi punti.

**Il risultato finale NON è che trasformo solo 4 tipi di pixel.** Il risultato è che ho creato **un'unica regola complessa** che trasformerà **TUTTI i 256 possibili valori di input**, in modo fluido e logico.

**Esempi:**

- Un pixel di valore **46** diventerà **32** (come da mio comando n.1).
- Un pixel di valore **70** (per cui non ho dato comandi) sarà trasformato secondo la curva interpolata: forse diventerà **95**.
- Un pixel di valore **150** (altro valore senza comando) diventerà, diciamo, **115**.
- Un pixel di valore **191** diventerà **182** (come da mio comando n.4).

In pratica, con quei 4 punti non ho trasformato 4 valori, ma ho **modellato l'intera funzione di trasformazione** per l'intera gamma di grigi.

### **Fase 6: Esempi di Operatori Puntuali Semplici**

Ora applichiamo il linguaggio che abbiamo imparato.

1. **IL NEGATIVO (Inversione)**
    - **Formula:** $g(x,y) = 255 - f(x,y)$
    - **Spiegazione:** Sottrai il valore del pixel da 255 (il bianco massimo). Stai misurando la sua "distanza dal bianco" e trasformandola nella "distanza dal nero".
    - **Esempio:** Pixel = 10 (nero quasi puro). $255 - 10 = 245$ (bianco quasi puro).
    - **Grafico LUT:** È una **retta decrescente** che va dall'angolo in alto a sinistra (0,255) a quello in basso a destra (255,0). Dice: "Più sei chiaro in ingresso, più ti rendo scuro in uscita, e viceversa."
        
        ![image.png](Lezione%208%20Operazioni%20puntuali/image%2014.png)
        
2. **BINARIZZAZIONE (Soglia)
Si ottiene scegliendo una soglia $T$ e mettendo a nero tutti i pixel il cui valore è minore a $T$ e a bianco tutti gli altri.**
    - **Formula:** Se $f(x,y) < \text{SOGLIA}$, allora $g(x,y)=0$. Altrimenti, $g(x,y)=255$.
    - **Spiegazione:** È una decisione secca, senza mezze misure. Scegli un valore di soglia (es. 128). Tutto ciò che è più scuro di quel grigio medio diventa nero puro (0). Tutto ciò che è più chiaro diventa bianco puro (255).
    - **Grafico LUT:** È una linea a **gradino**. Piatta a 0 fino alla soglia, poi un salto verticale, e poi piatta a 255.
3. **INCUPIMENTO e SCHIARIMENTO**

![image.png](Lezione%208%20Operazioni%20puntuali/image%2015.png)

![image.png](Lezione%208%20Operazioni%20puntuali/image%2016.png)

### **Fase 7: Trasformazioni Non Lineari - Logaritmo e Potenza (Gamma)**

Qui entriamo nel territorio delle curve "storte", non rette. Sono potenti perché trattano in modo diverso i toni scuri e quelli chiari.

### **A) TRASFORMAZIONE LOGARITMICA**

- **Formula:**

$$
⁍
$$

- **Smontiamo la formula:**
    - $log$ è il **logaritmo**. La sua caratteristica principale è che **cresce molto all'inizio e poi sempre più piano**. Come una corsa dove i primi metri si fanno in fretta, ma poi ci si stanca e si rallenta.
    - $+1$ è un trucco tecnico: il logaritmo di 0 non esiste, quindi aggiungiamo 1 per evitare problemi.
    - $c$ è una **costante di scala**. Serve solo a "stirare" il risultato del logaritmo in modo che riempia bene l'intervallo 0-255. Non è il cuore della trasformazione.
- **Cosa fa ai pixel?** **ESPANDE I TONI SCURI e COMPRIME I TONI CHIARI.**
    - Un pixel scuro (es. 20) viene "trascinato" molto verso l'alto dalla rapida crescita iniziale del log. Diventa molto più chiaro.
    - Un pixel chiaro (es. 240) si trova nella "zona piatta" del log. Viene aumentato di poco.
- **A cosa serve?** A visualizzare immagini con una **gamma dinamica altissima**, come una foto con finestre luminose e angoli bui. Il logaritmo "schiaccia" le enormi differenze in una scala che i nostri occhi (e i nostri monitor) possono gestire.
- **Grafico LUT:** Una curva che sale **molto ripida all'inizio** (asse X basso) e poi si **appiattisce** verso la fine.

Prendiamo la linea che è **"Log"**. Seguiamola:

- A **L/2** (cioè a metà dell'asse X, dove i pixel sono di luminosità media), la curva "Log" è **ancora abbastanza ripida**, **ma molto meno ripida rispetto all'inizio**.
- Solo quando ci avviciniamo a **L** (l'input massimo, i pixel bianchi puri) la curva "Log" diventa veramente **"piatta"**, cioè la sua pendenza si avvicina a zero.
- La curva logaritmica ha una pendenza (inclinazione) molto elevata per gli input bassi (espansione delle ombre), e una pendenza che diminuisce progressivamente fino a diventare molto bassa per gli input alti (compressione delle luci). Il pixel a L/2 (chiaro) si trova già in una zona a pendenza ridotta, quindi subisce una trasformazione meno drastica rispetto a un pixel scuro.

![Screenshot 2026-01-22 025041.png](Lezione%208%20Operazioni%20puntuali/Screenshot_2026-01-22_025041.png)

### **B) TRASFORMAZIONE di POTENZA (GAMMA)**

![image.png](Lezione%208%20Operazioni%20puntuali/image%2017.png)

![image.png](Lezione%208%20Operazioni%20puntuali/image%2018.png)

- **Formula:** $g(x,y) = c * [f(x,y)]^γ$ (dove $γ$ è la lettera greca "gamma").
- **Smontiamo la formula:**
    - $[f(x,y)]^γ$ significa: "prendi il valore del pixel ed elevatelo alla potenza γ". **La potenza γ è il PARAMETRO CHE CONTROLLA TUTTO.**
    - $c$ è, anche qui, una costante di normalizzazione per tornare a 0-255.
- **Cosa fa ai pixel? Dipende TUTTO da γ:**
    - **Se γ < 1 (es. γ=0.4):** L'effetto è simile al logaritmo. I valori bassi (vicini a 0) vengono **messi in grande evidenza** (es. $50^{0.4}$ è molto più grande di 50/255). Si **schiariscono le ombre**. Questo si usa per **compensare i monitor vecchi (CRT)** che tendevano a scurire le immagini (avevano un γ naturale di ~2.5). Applicando γ=0.4 all'immagine PRIMA di mandarla al monitor, si annulla l'effetto.
    - **Se γ > 1 (es. γ=2.0):** Effetto OPPOSTO. I valori bassi vengono **schiacciati verso il nero**, mentre i valori alti vengono **espansi**. Si aumenta il contrasto nelle alte luci. Si scuriscono le ombre.
    - **Se γ = 1:** La trasformazione è lineare (g = c*f). Non è interessante.
- **Grafico LUT:**
    - γ < 1: Curva **convessa verso l'alto** (sale forte all'inizio).
    - γ > 1: Curva **concava verso l'alto** (sale piano all'inizio, forte alla fine).
    - γ = 1: È una retta (la diagonale, se c è scelto bene).

![image.png](Lezione%208%20Operazioni%20puntuali/image%2019.png)

### **Fase 8: Variazioni di Contrasto e Curve Non Monotone**

1. **AUMENTO/DIMINUZIONE del CONTRASTO:**
    - **Concetto:** Il contrasto è la **differenza** tra i toni chiari e scuri.
    - **Come si fa con una LUT?** Modificando la **pendenza (inclinazione)** della curva.
        - **Per AUMENTARE il contrasto:** La curva diventa **più ripida** (magari partendo da un punto più basso e finendo in uno più alto). I pixel scuri diventano ancora più scuri (output < input), i pixel chiari ancora più chiari (output > input). Le differenze si **amplificano**.
        - **Per DIMINUIRE il contrasto:** La curva diventa **più piatta**. Tutti i valori, sia scuri che chiari, vengono "spinti" verso un grigio medio. Le differenze si **attenuano**. L'immagine sembra più slavata.
    - Non è una formula fissa, è un **concetto visivo applicato alla curva LUT**.
2. **CURVE NON MONOTONE (Solarizzazione):**
    - Finora tutte le curve erano **monotone crescenti**: se l'input aumenta, anche l'output aumenta (o al massimo resta uguale).
    - Ma la LUT può essere **qualsiasi funzione**! Può anche salire e poi scendere. Queste si chiamano **non monotone**.
    - **L'effetto "Solarizzazione"** è l'esempio classico: la curva sale normalmente, poi, dopo un certo punto (una soglia), **incomincia a scendere**. Cosa significa?
        - Un pixel di valore 100 diventa 150 (schiarito).
        - Un pixel di valore 200 (più chiaro di 100) potrebbe diventare 120 (più scuro di 150!).
    - Il risultato visivo è un'inversione surreale dei toni nelle aree più luminose, un effetto artistico.

---

[Guida](Lezione%208%20Operazioni%20puntuali/Guida%202f01cf23380e80e3b8ced0c3fb2a6fb8.md)