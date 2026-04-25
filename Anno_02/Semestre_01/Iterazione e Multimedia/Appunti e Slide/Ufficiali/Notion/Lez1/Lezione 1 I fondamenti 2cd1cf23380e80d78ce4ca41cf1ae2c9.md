# Lezione 1: I fondamenti

### Multimedia

L’aggettivo **multimedia** viene attribuito ad un sistema che si avvale di diversi tipi di media (testi, suoni, immagini, video). Gli strumenti utilizzati dai media sono i **dispositivi multimediali digitali**.

L’uomo fruisce di tali sistemi multimediali attraverso i suoi sensi (vista, udito). Tutti i media sono analogici per principio, e vengono poi resi digitali, questo tramite il processo di **digitalizzazione**, il quale consente a segnali reali di essere convertiti in una sequenza di cifre manipolabili dal computer. Ad esempio, la differenza tra un analogico reso digitale può essere quello di un vinile, che viene riprodotto tramite la lettura dei suoi solchi dalla punta di un giradischi, e che quindi riproduce onde; che viene convertito in MP3, quindi digitale, ossia una sequenza di bit che riproducono un suono.

I media digitali hanno dei grandi vantaggi:

- Sono facilmente riproducibili
- Hanno alta qualità
- Si mantengono nel tempo
- Vengono utilizzati supporti piccoli e facilmente trasportabili per fruirne
- Sono interattivi (pagine web, tv digitale, servizi di streaming musicale)

### Contenuti multimediali

Si parla di “contenuti multimediali” quando per comunicare un’informazione ci si avvale di molti media, cioè dei mezzi di comunicazioni di massa, quali: immagini, video, musica e testo. Ad esempio, un’enciclopedia multimediale (come Wikipedia) a differenza di una normale enciclopedia cartacea, ha la peculiarità di poter associare ad ogni voce non solo la sua spiegazione testuale, ma anche fotografie, disegni esplicativi, filmati, suoni…

Grazie alle potenzialità espressivo-comunicative la multimedialità si è diffusa in ogni settore.

### Le immagini

### Le leggi della percezione visiva

1. **Legge della vicinanza**
Le parti più vicine di un insieme entrato a contatto con il nostro campo visivo tendono ad essere percepite come unità raggruppate. Ad esempio, nella figura sottostante, i segmenti verticali qui sotto vengono percepiti come coppie piuttosto che come singole linee.
    
    ![image.png](Lezione%201%20I%20fondamenti/image.png)
    
2. **Legge della chiusura**
Le figure chiuse si vedono più facilmente di quelle aperte. Quadrati, cerchi, triangoli e figure simili, all’occhio umano risalgono di più delle semplici linee o segmenti.
    
    ![image.png](Lezione%201%20I%20fondamenti/image%201.png)
    
3. **Legge dell’uguaglianza (o della somiglianza)**
Elementi uguali, o che si assomigliano, vengono percepiti come insieme o come un’unica figura. Ad esempio, nell’immagine sottostante, i puntini bianchi e neri vengono percepiti come linee orizzontali.
    
    ![image.png](Lezione%201%20I%20fondamenti/image%202.png)
    
4. **Legge della continuità**
Un insieme di punti posti uno di seguito all’altro vengono visti come una struttura unitaria (come nella foto sopra).
Per lo stesso motivo, quando si uniscono o sovrappongono forme diverse continuiamo a vederle distinte. Ad esempio, nella figura sottostante, il cerchio ed il quadrato vengono percepiti come figure complete, e non come figure dove mancano alcune parti o sono “modificate”.
    
    ![image.png](Lezione%201%20I%20fondamenti/image%203.png)
    
5. **Legge della buona forma**
Figure diverse, quando si uniscono, finiscono per avere ciascuna la propria forma, anche se in realtà questo non compare perché non visibile all’occhio umano. Ad esempio, nell’immagine sottostante, quando le figure di B vengono sovrapposte in A, vengono percepiti come un cerchio ed un quadrato completi, anche se realmente non lo sono.
    
    ![image.png](Lezione%201%20I%20fondamenti/image%204.png)
    
6. **Legge dell’illusione**
La mente tende naturalmente a vedere figure chiuse, a completare contorni interrotti, a percepire figure semplici, regolari, strutture unitarie e compatte; anche se non lo sono realmente. Ad esempio, nelle due figure sottostanti, il triangolo nero o bianco che risulta all’occhio, è una figura nascosta, un fantasma, che non è reale materialmente bensì illusoria.
    
    ![image.png](Lezione%201%20I%20fondamenti/image%205.png)
    

Le immagini digitali sono campionate per essere rappresentare da un numero finito di campioni (i pixel). E dunque un’immagine è una metodica di rappresentazione secondo coordinate spaziali indipendenti di un oggetto.

La prima differenza di cui bisogna parlare in fatto di immagini digitali è quella tra immagini raster e vettoriali.

![image.png](Lezione%201%20I%20fondamenti/1fbfd1e7-c81d-473d-bebc-dca82a8c294e.png)

- **Immagini raster**:
Sono formate da un reticolo di pixel accostati l’uno all’altro, e ad ognuno di loro viene assegnato un colore. La maggior parte delle immagini disponibili nel web (GIF, JPG, BMP, ecc..) lo sono. Il principale difetto di queste immagini è che esse perdono qualità e dettaglio se vengono ingrandite, rappresentando il tipico effetto “pixellato”. Le immagini realizzate con Photoshop sono quasi sempre immagini raster.
- Immagini vettoriali:
Le immagini vettoriali sono costituite da vettori. Il vantaggio di questo tipo di immagini è che possono essere ingrandite quanto si vuole e questo non comporta alcuna perdita di qualità.
D’altro canto, trattandosi solo di linee e punti queste immagini non possono gestire file complessi, ad esempio fotografie. Questo tipo di grafica viene adottata per esempio dalle aziende per realizzare loghi che dovranno essere rappresentati sia in dimensioni ridotte (come ad esempio bigliettini da visita) che su grandi dimensioni (come ad esempio striscioni pubblicitari).

Entriamo nel dettaglio della rappresentazione matematica delle immagini:

- Raster: nella coordinata x,y c’è un pixel rosso, nella coordinata x+1,y+1 c’è un pixel verde, ecc…
- Vettoriale: c’è un segmento che unisce il pixel x al pixel y, un altro segmento unisce altri pixel, ecc…

Differenze:

| Raster | Vector |
| --- | --- |
| Quali puntini devo colorare? | Quali linee devo tracciare? |
| Disegno a mano libera | Disegno tecnico |

Esempio concreto di scalabilità

![image.png](Lezione%201%20I%20fondamenti/image%206.png)

![image.png](Lezione%201%20I%20fondamenti/image%207.png)

### Range dinamico

Poiché le immagini digitali sono rappresentate da un numero finito di intensità, è importante saper riconoscere quali sono i limiti dell’occhio umano e quanto è in grado di percepire i diversi tipi di intensità.
Sappiamo che l’intensità percepita è rappresentata da una funzione logaritmica dell’intensità incidente nell’occhio. Il sistema visivo umano, però, non opera su tutto questo range di intensità incidente, ma solo su una porzione di esso. E’ in grado, inoltre, di saper distinguere in maniera differente se si trova in una zona chiara o in una zona scura.

Uno strumento che rende più chiara la comprensione del range dinamico sono le Bande di Mach

![image.png](Lezione%201%20I%20fondamenti/image%208.png)

Come vediamo, le bande sopra hanno un’intensità costante, ma l’intensità percepita nei bordi tende ad approssimarsi.
Con questo si arriva al contrasto simultaneo…

![image.png](Lezione%201%20I%20fondamenti/4c2420b3-761f-4a55-8d5b-89b2ba64b2f3.png)

In queste tre immagini, il quadrato centrale ha sempre la stessa intensità, ma all’occhio umano viene percepito diversamente in base allo sfondo su cui si trova. Se lo sfondo è scuro il quadrato al centro appare più chiaro, e viceversa.

### Rappresentazione di un immagine

Un’immagine digitale viene rappresentata da una funzione bidimensionale $f(x,y)$.

$x$ e $y$ sono le coordinate spaziali, ed $f(x,y)$ è proporzionale alla luce incidente nell’oggetto e alla luce riflessa nell’oggetto, rispettivamente indicate con $i$ ed $r$. 

Quindi $f(x,y) = i(x,y)\space r(x,y)$

E dunque: 

$i$ è la luce incidente

$r$ è la luce riflessa

Range dei valori di i ed r:

$$
0 < i(x,y) < \infin
\\
0 < r(x,y) < 1
$$

Alcuni valori tipici di illuminazione e riflettanza:
$i$: la luce del sole può produrre più di $90000 lm/m^2$ di illuminazione sulla superficie terrestre. La luna piena raggiunge $0.1 lm/m^2$ di illuminazione.
$r$: 0.01 per il velluto nero, 0.80 per un muro verniciato di bianco, 0.90 per l’argento e 0.93 per la neve.

### Convenzioni:

È importante ricordare che il primo elemento della matrice che rappresenta un’immagine digitale si trova sempre **in alto a sinistra**. Infatti ci troviamo nel quarto quadrante del piano cartesiano, ma con l'unica eccezione che qui i valori delle coordinate sono positivi, con l’asse *y* orientato verso il basso.

In teoria, il valore di una funzione immagine $f(x,y)$ è un **numero reale**, quindi può assumere valori continui come $1.2345, 1.200001, \pi$. 
E’ importante ricordare che il piano XY in cui stanno le coordinate dell’immagine è detto dominio spaziale e le variabili x,y sono dette variabili spaziali o coordinate spaziali.
Tuttavia, il computer che si occupa di rappresentare le immagini digitali **non può gestire valori continui**, ma solo un **numero finito di valori discreti**. Una funzione continua, invece, può assumere infiniti valori.
Per questo motivo è necessario scegliere valori discreti che appartengano a un insieme finito o numerabile, ovvero valori che siano effettivamente rappresentabili dal computer. Questo passaggio dal **continuo** al **discreto** avviene tramite i processi di **campionamento** e **quantizzazione**.
Ecco come accade:

- **Campionamento**: 
**Il campionamento consiste nel discretizzare lo spazio dell’immagine**. Immaginando un’immagine come una matrice di pixel, si prende un’immagine continua e si decide una **griglia di punti**, dove ogni punto diventa un pixel.
Se immaginiamo un immagine di 1920 x 1080 pixel, abbiamo 2.073.600 pixel a disposizione.
Più campioni → più dettaglio
Meno campioni → immagine più sgranata
Per questo motivo un’immagine 1280 × 720 ha una risoluzione inferiore rispetto a un’immagine Full HD 1920 × 1080.
- **Quantizzazione**:
**La quantizzazione è il processo che risponde alla domanda:** **con quali numeri rappresento il colore o l’intensità luminosa?** La luce, nel mondo reale, può assumere infiniti valori; la quantizzazione seleziona solo alcuni di questi valori per rappresentarla digitalmente.
Caso classico: immagine in scala di grigi a 8 bit.
Come sappiamo, 8 bit = 1 byte; e di conseguenza ogni bit può assumere solo due valori, ossia 0 o 1. Questo vuol dire che 1 byte può assumere $2^8$ (256) valori, 0-255. In questo caso, 0 rappresenta il nero, 255 il bianco, mentre tutti gli altri valori rappresentano livelli intermedi della scala di grigi.
Per tale motivo, in una immagine che usa meno livelli otteniamo un'immagine con meno intensità di grigio e con valori meno "morbidi". Cioè lo stacco tra un valore ed un altro è più evidente per via del minor numero di colori rappresentabili sulla scala di grigi. E quindi mostra transizioni che diventano brusche e compaiono bande visibili tra i livelli di grigio.

Dunque un **pixel** (*picture element*) è il valore quantizzato misurato da ciascun sensore di cattura delle immagini.

Durante lo studio di questa materia useremo le immagini raster e non le vettoriali. L’immagine sarà rappresentata da una matrice di elementi dove il valore della cella è detto Pixel. E inoltre, per convenzione, conteremo le righe e le colonne da 1 e non da zero. Come detto prima, l’origine è posta in alto a sinistra.

![Pixel](Lezione%201%20I%20fondamenti/image%209.png)

Pixel

### Modi di vedere un’immagine

- Come una matrice di numeri di dimensioni $M\times N$.
    
    ![image.png](Lezione%201%20I%20fondamenti/image%2010.png)
    
- Come immagine colorata, in questo caso il software traduce il valore della cella della matrice in colore, detto appunto pixel.
    
    ![image.png](Lezione%201%20I%20fondamenti/image%2011.png)
    
- Come una superficie 3D. In questo caso nel piano xy stanno le coordinate del pixel, nell’asse z sta il valore di grigio che se è vicino al piano, vuol dire che è un valore piccolo e quindi scuro, se è alto vuol dire che è un valore chiaro e formerà dei picchi.
    
    ![image.png](Lezione%201%20I%20fondamenti/165506f8-a7c8-4719-af95-31eba5e60112.png)
    

### Tipologie di immagini e bit per pixel

1. **Bianco/Nero**
1 bit per pixel
Nella posizione (i,j) ci sarà o il valore 0 il valore 1
    
    ![image.png](Lezione%201%20I%20fondamenti/6c51b622-bbe9-4b03-81f2-645ddc3f8956.png)
    
2. **Scala di grigio**
8 bit per pixel
Nella posizione (i,j) ci sarà un valore compreso tra [0, 255]
    
    ![image.png](Lezione%201%20I%20fondamenti/image%2012.png)
    
3. **A colori**
8 bit per canale. Poiché i canali sono 3 avrò 24 bit.
Nella posizione (i,j) ci sarà una terna del tipo (x, y, z) con x, y, z che assumono valori compresi tra [0, 255]
    
    ![image.png](Lezione%201%20I%20fondamenti/f8184d93-dce8-4407-9408-a94a884fe15e.png)
    

### Immagini RGB

![image.png](Lezione%201%20I%20fondamenti/image%2013.png)

Abbiamo 3 livelli per ogni immagine RGB: nel primo le coordinate del rosso, nel secondo del verde e nel terzo del blu.

Un’immagine RGB non è composta da tre immagini colorate (rossa, verde e blu), ma da **tre matrici separate in scala di grigi**, una per ogni canale: **R**, **G** e **B**.

Ogni canale:

- è una matrice di pixel
- usa **8 bit** per pixel
- può assumere valori da **0 a 255**
- rappresenta **l’intensità** di quel colore, non il colore stesso

In particolare:

- il canale **R** indica *quanto rosso* è presente in ogni pixel
- il canale **G** indica *quanto verde*
- il canale **B** indica *quanto blu*

Se un pixel ha valore alto in un canale, quel colore è molto presente; se il valore è basso, quel colore è quasi assente.

Quando i canali vengono visualizzati separatamente, spesso sono mostrati colorati (rosso, verde o blu) solo per comodità visiva. In realtà, **nei dati ogni canale è una semplice immagine in scala di grigi**.

Il colore finale di ogni pixel si ottiene combinando i tre valori di intensità z (R, G e B) nella stessa posizione (x,y).

![Screenshot 2025-12-21 181518.png](Lezione%201%20I%20fondamenti/Screenshot_2025-12-21_181518.png)

![image.png](Lezione%201%20I%20fondamenti/image%2014.png)