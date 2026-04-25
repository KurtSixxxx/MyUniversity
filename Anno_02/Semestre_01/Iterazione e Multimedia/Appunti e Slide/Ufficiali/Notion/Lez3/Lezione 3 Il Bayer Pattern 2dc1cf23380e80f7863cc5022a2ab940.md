# Lezione 3: Il Bayer Pattern

### Acquisizione delle immagini digitali

Quando la luce colpisce un oggetto, una parte viene assorbita ed una parte viene riflessa. Quella che viene riflessa, dà origine al colore percepito.
Per creare una immagine digitale, è essenziale che tale luce riflessa sia catturata da un sensore che si occupa di elaborarla.

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image.png)

### Il sensore

L’energia che colpisce il sensore viene trasformata in impulso elettrico dal sensore che è composto da un materiale particolarmente sensibile alla luce. Tale impulso elettrico è successivamente digitalizzato.

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%201.png)

Ci sono diversi tipi di sensori:

- **Singolo sensore**
Gli scanner usano un singolo sensore che viene spostato lungo la sorgente da digitalizzare.
Questi sensori (tipici degli **scanner digitali**) sono costituiti da un unico elemento captante. Per poter digitalizzare una sorgente, come un foglio o una fotografia, il sensore deve essere **spostato meccanicamente** lungo tutta la superficie dell'oggetto. Le fonti mostrano che questo movimento può essere una combinazione di **moto lineare** e **rotazione**, a seconda della meccanica interna del dispositivo.
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%202.png)
    
- **Sensore in linea**
Le macchine per fare le TAC usano dei sensori che sono disposti in un’unica linea.
Il dispositivo acquisisce **una riga dell'immagine alla volta** per ogni incremento del movimento. Per completare la scansione dell'intero soggetto, il sensore (o l'oggetto stesso) deve compiere un **moto lineare** costante in modo che la "striscia" di sensori passi sopra ogni sezione dell'area da riprendere.
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%203.png)
    
- **Sensori in 2D array**
Nelle macchine fotografiche digitali, i sensori sono disposti su una matrice. Non è necessario spostare il sensore, come nei due casi precedenti, per effettuare una scansione. I più diffusi sensori di questo tipo sono i **CCD**.
    
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%204.png)
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%205.png)
    

### CCD: Charged Coupled Device

Si tratta di dispostivi elettronici che se colpiti da fotoni (luce) assumono una carica positiva. Le celle del CCD non possono caricarsi oltre un certo limite: sono dei secchi d’acqua che non possono riempirsi oltre alla loro capacità. 
Il numero di celle per area di esposizione è un **parametro di qualità** della fotocamera misurato in **MEGAPIXEL**.

**Schema di misurazione.**
Dopo che le cariche sono state acquisite da una matrice di celle, debbono essere trasferite in un a memoria digitale. La scansione avviene in C fasi, una fase per ciascuna colonna della matrice.
Ad ogni fase viene trasferita in memoria la prima colonna della matrice, nello stesso tempo tutti gli elementi (dalla seconda colonna in poi) vengono trasferiti dalla propria colonna a quella precedente.

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%206.png)

### CFA: Color Filter Array

Poiché ogni cella è in grado di memorizzare **un solo colore** per volta e non una terna, occorre scegliere qual è il modello di memorizzazione ottimale (CFA).
I due colori mancanti per completare la terna, saranno ottenuti per interpolazione dai pixel vicini (Color Interpolation). Il grado di accuratezza del risultato dipende da quanto è sofisticato il metodo di interpolazione.

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%207.png)

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%208.png)

![Possibili modelli di CFA](Lezione%203%20Il%20Bayer%20Pattern/image%209.png)

Possibili modelli di CFA

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2010.png)

### Il Bayer Pattern

Lo schema più utilizzato è il Bayer Pattern. E’ stato proposto nel 1976 da Byce Bayer ed è utilizzato dal 1980 in tutti i dispositivi elettronici.
Esso rappresenta un rapporto **1 : 2 : 1** per **R : G : B** dove i pixel verdi sono disposti sulle “diagonali”.
Esso privilegia le misure del canale verde perché è quello più importante alla percezione della vista umana.
Una immagine in Bayer Pattern viene memorizzata nel formato “raw”.

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2011.png)

![Screenshot 2026-01-02 202238.png](Lezione%203%20Il%20Bayer%20Pattern/Screenshot_2026-01-02_202238.png)

Poiché tramite il Bayer Pattern per ogni pixel si memorizza solo una componente di colore, tutte le altre dovranno essere ottenute per interpolazione dai pixel vicini.

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2012.png)

Più dettagliatamente nell’immagine sottostante viene descritto il processo dal sensore CCD all’immagine finale.

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2013.png)

### Color Interpolation

- La matrice di dati rilasciata dal sensore può essere visualizzata come immagine. In questo caso si vedrebbe una immagine in scala di grigi.
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2014.png)
    
- L’aver conservato solo una componente della terna del colore comporta la visione dell’immagine come se fosse composta da un mosaico.
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2015.png)
    
- Per ottenere una immagine a colori occorre procedere con un algoritmo di color interpolation, che ricava i valori mancanti per ogni singola terna dei dati dell’intorno.
Poiché dall’immagine a colori sparisce l’effetto a mosaico, l’algoritmo di color interpolation viene anche chiamato algoritmo di “**demosaicking**”.
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2016.png)
    

### Color interpolation: replication/Nearest-neighbor interpolation

Per ogni singolo pixel gli elementi mancanti della terna vengono copiati dall’intorno. Questa tecnica viene anche chiamata “**Nearest-neighbor interpolation**”

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2017.png)

- **Color interpolation: bilinear
Abbiamo l’informazione di R e manca G e B**
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2018.png)
    
- **Color interpolation: bilinear
Abbiamo l’informazione di G e manca R e B**
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2019.png)
    
- **Color interpolation: bilinear
Abbiamo l’informazione di B e manca R e G**
    
    ![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2020.png)
    

![image.png](Lezione%203%20Il%20Bayer%20Pattern/image%2021.png)