# Lezione 6: Campionamento e quantizzazione

![unnamed.png](Lezione%206%20Campionamento%20e%20quantizzazione/unnamed.png)

---

Un **segnale continuo** è qualcosa che esiste in **ogni istante** e in **ogni punto**.
Ad esempio il suono nell’aria, la luce che arriva ad un sensore, un immagine reale davanti agli occhi: il segnale continuo non è fatto a pezzi, non ha “scatti”: varia **senza interruzioni**.

Poiché i computer non possono gestire segnali continui si lavora con numeri finiti, ed è qui che entra in gioco il campionamento.

### Campionamento

Il **campionamento** si basa sullo scegliere un numero finito di **campioni rappresentativi del segnale** continuo.

Ogni campione corrisponde ad una misura del segnale in un punto preciso (nello spazio o nel tempo).
Di conseguenza: avere più campioni vuol dire avere più informazioni, meno campioni vuol dire avere meno informazioni.

### Problemi del campionamento sbagliato

1. **Campionamento troppo basso**
    
    Se il tasso di campionamento è troppo basso (ossia abbiamo pochi campioni):
    
    - Si perdono dettagli
    - Si perde informazione
    - Il segnale ricostruito è più “povero”
    
    Ma questo a volte è voluto, perché:
    
    - Salvare troppi campioni richiede troppa memoria
    - Si accetta una perdita pur di avere dati gestibili ottenute in dimensioni maneggevoli
2. **Aliasing**
    
    Se il campionamento è troppo basso rispetto al contenuto del segnale:
    
    - Compaiono dettagli che NON esistono
    - Il segnale viene alterato, e dunque cambiato in qualcos’altro.
    
    Questo fenomeno si chiama aliasing, e poiché imprevedibile richiede attenzione.
    
    Alias significa falsa identità: una frequenza alta viene interpretata come una frequenza bassa.
    

### Dominio del tempo e dominio della frequenza

Quando osserviamo un segnale, come un suono o un’immagine, possiamo guardarlo in due modi diversi, chiamati **domini**.

1. **Dominio del tempo (o dello spazio)**
    
    ![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image.png)
    
    Nel dominio del tempo guardiamo **come cambia il segnale nel tempo** (**o nello spazio**, se parliamo di immagini).
    
    - Per un suono: vediamo quanto il volume sale o scende ogni secondo.
    - Per un’immagine: vediamo quanto chiaro o scuro è ogni punto dell’immagine lungo la superficie.
    
    In questo dominio osserviamo la forma grezza del segnale, esattamente **come appare “dal vivo”**.
    
2. **Dominio della frequenza**
    
    ![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%201.png)
    
    Nel dominio della frequenza guardiamo di **quali frequenze è composto** il segnale, cioè **quanto velocemente cambia**.
    
    - Frequenze basse → cambiamenti lenti, come grandi macchie o curve larghe in un’immagine.
    - Frequenze alte → cambiamenti rapidi, come linee sottili o dettagli minuti.

Passare dal dominio del tempo/spazio al dominio della frequenza ci permette di capire quali dettagli sono presenti nel segnale.

**Per trasformare un segnale dal domino del tempo a quello della frequenza si usa la Serie di Fourier.**

La **serie di Fourier** dice che qualsiasi segnale, anche molto complesso, può essere visto come **somma di onde sinusoidali di diverse frequenze**.

- Ogni onda sinusoidale rappresenta un “ritmo” specifico di cambiamento.
- Il segnale originale è la somma di tutte queste onde.

In questo modo possiamo separare il segnale nei suoi ingredienti di frequenza.

Una volta che il segnale è nel dominio delle frequenze, possiamo individuare la **frequenza più alta** presente.

- Questa frequenza è importante, perché ci dice quanto velocemente cambiano i dettagli in più minuti
- Determina quante volte dobbiamo campionare il segnale per catturare tutti i dettagli senza errori (Nyquist rate e aliasing)

### Nyquist Rate

Per scegliere il giusto valore di campionamento si ricorre al teorema di Shannon, che si basa sul Nyquist Rate.

Si definisce Nyquist Rate il doppio della più alta frequenza, contenuta in un segnale continuo e limitato.

Come si calcola in pratica?

Immaginiamo di osservare un fenomeno si un determinato intervallo di tempo o di spazio (ad esempio, una riga di pixel di una foto):

- Se il fenomeno rimane costante per tutto l’intervallo, la sua frequenza è 1.
- Se il fenomeno cambia, dividi l’intervallo i parti sempre più piccole (2, 3, 4…) finché non trovi una suddivisione tale che, dentro ogni singolo “intervallino”, il segnale sia praticamente costante.

![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%202.png)

- Se hai dovuto dividere l’intervallo in $N$ parti, allora $2N$ è il tuo Nyquist rate.

Come detto prima, il Nyquist Rate è il pilastro del Teorema del campionamento di Shannon. Questo teorema afferma che se raccogliamo campioni con una frequenza almeno doppia rispetto alla frequenza Nyquist (quindi **$2N$** nel nostro esempio operativo) allora il segnale può essere ricostruito in modo fedele e perfetto in ogni suo punto.

Se questo non accade allora può accadere l’aliasing o il risultato visivo è disastroso per via di compara di artefatti o comparsa di dettagli fantasma. Tutti fenomeni che abbiamo discusso prima.

Esempio concreto:
Supponiamo di avere un'immagine larga 720 pixel dove il dettaglio più piccolo (ad esempio un singolo tratto di un disegno) misura **4 pixel.**

- Dividiamo lo spazio totale per la grandezza del dettaglio: $720/4 = 180$ tratti.
- Il Nyquist rate sarà il doppio di questi tratti: $2 \times 180 = 360$.
- Conclusione: Se prendiamo almeno 360 campioni (misure), l’immagine ricostruita sarà identica all’originale. Se ne prendessimo solo 180, l'immagine risulterebbe rovinata e piena di errori.

![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%203.png)

Adesso facciamo un esempio di campionamento sbagliato

Ipotizziamo, per la stessa immamgine di voler trascurare i tratti fini (4 px) e volerci concentrare su quelli più evidenti (6 px). Allora la nostra ipotetica “frequenza più alta” sarà:

- $720/6 = 120$  tratti.
- Nyquist rate $2 \times 120 = 240$
- Prendiamo solo $240$  campioni e ricostruiremo con interpolazione binomiale l’immagine

![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%204.png)

![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%205.png)

Un altro tipo di campionamento errato.

### Sottocampionamento

Cosa succede invece quando si campiona ad una frequenza inferiore a quella del Nyquist rate? 
Si perdono dettagli significativi e spesso si introducono dettagli che nemmeno esistono.

Questo effetto è detto “frequency aliasing” o semplicemente “aliasing”.
Con l’aliasing quelle che erano alte frequenze sono state “mascherate” come basse frequenze nella fase di campionamento.

Ecco un effetto di sottocampionamento.

![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%206.png)

![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%207.png)

![image.png](Lezione%206%20Campionamento%20e%20quantizzazione/image%208.png)

L'aliasing è sempre presente, anche se usiamo sensori eccellenti un minimo di aliasing (quel fenomeno per cui il segnale viene alterato e appaiono dettagli "fantasma") esiste sempre.
Perché la realtà ha dettagli infinitamente piccoli (alte frequenze), mentre ogni strumento digitale ha un limite fisico oltre il quale non può andare.

Per poter campionare un segnale (ovvero trasformarlo in una serie di punti), dobbiamo imporre che quel segnale sia limitato.
In parole semplici: dobbiamo "decidere" che oltre una certa velocità di dettaglio non ci interessa guardare. Nel momento in cui mettiamo questo "recinto" (limite) per poter scattare le nostre foto o registrare i nostri suoni, creiamo involontariamente le condizioni perché l'aliasing si presenti.

La **soluzione**? L'aliasing può essere ridotto applicando una funzione di smussamento sul segnale originale prima del campionamento.
Cos'è lo smussamento? È essenzialmente un leggero "sfocamento" (**blurring**).
Come funziona? Se so che il mio sensore non è abbastanza veloce per catturare i dettagli finissimi (come le righe sottili di una camicia che creano l'effetto **Moiré**), io "sfoco" leggermente l'immagine originale. Eliminando quei dettagli troppo fini che il sensore non capirebbe, evito che vengano scambiati per "fantasmi" o onde inesistenti, rendendo l'immagine molto più naturale e "accettabile" all'occhio umano.

![Effetto Moirè](Lezione%206%20Campionamento%20e%20quantizzazione/image%209.png)

Effetto Moirè

### Quantizzazione

Mentre il campionamento decide “dove” guardare, la quantizzazione decide “cosa” vede il sensore.

I sensori delle fotocamere (i CCD) sono apparecchiature analogiche, che misurano la luce sottoforma di numeri REALI (infiniti decimali). Tuttavia, il computer non può gestire questi numeri all’infinito, dunque ha bisogno di arrotondare questi valori e mantenerli in un certo range. La **quantizzazione** è proprio questo **processo di arrotondamento e discretizzazione dei valori di luminosità.**

Perché non possiamo essere precisi al $100 \%$? 
Oltre ai limiti di memoria, i sensori soffrono di rumore, il quale è dovuto a perturbazioni termiche o difetti tecnici. Ad esempio, nei CCD esiste la “dark current”: anche a obbiettivo chiuso, passano piccole correnti che creano disturbi. Quantizzare serve quindi anche a “pulire” queste piccole variazioni insignificanti, raggruppandole in livelli definiti.

**La procedura**:
Per trasformare ciò che i sensori CCD catturano in numeri, dividiamo la scala di grigi (dal nero al bianco) in un numero finito di $N$ livelli.

1. Suddivisione: si fissano delle soglie (chiamate t_{0}, t_{1}, ecc…). Se la luce misurata cade tra le due soglie, viene assegnata a quel particolare “livello”.
2. Etichettatura: ogni livello riceve un’etichetta numerica (es. Livello 0, Livello 1…)

[**`DA SITEMARE`**]

**//////////////////////////////////**

---

## 1. Introduzione alla quantizzazione

I sensori misurano valori **analogici** (reali), ad esempio la luminosità di un pixel.

Per memorizzare o elaborare questi valori digitalmente, si usa la **quantizzazione**:

- La quantizzazione **arrotonda** i valori reali a un numero finito di livelli.
- Ogni livello ha un **valore rappresentativo** che viene memorizzato.
- Questo processo riduce il numero di bit necessari, ma introduce **errore di quantizzazione**.

---

## 2. Procedura generale della quantizzazione

Sia `[a, b]` il range dei valori reali e si voglia quantizzare in **n livelli**:

1. Si scelgono **n+1 soglie**:
    
    ```
    t0 = a < t1 < t2 < ... < tn = b
    
    ```
    
2. Un valore `x` viene assegnato al livello `k` se:
    
    ```
    tk ≤ x < tk+1
    
    ```
    
    - L’ultimo valore `b` viene assegnato all’ultimo livello `n-1`.
3. Ogni livello ha un **valore rappresentativo Qi**.

**In pratica:** il range `[a, b]` viene diviso in intervalli, e ogni intervallo è un livello numerico memorizzabile.

---

## 3. Quantizzazione uniforme

La quantizzazione uniforme divide il range di ingresso **in blocchi uguali**.

- Range ingresso: 0 … N-1
- Range uscita: 0 … K-1, con K ≤ N
- Formula:
    
    ```
    L' = (L * K) / N
    
    ```
    
    - L = livello in ingresso
    - L' = livello quantizzato in uscita
    - K = numero livelli in uscita
    - N = numero livelli in ingresso

### Esempio

- Ingresso: 0–255 (N = 256)
- Uscita: 0–7 (K = 8)

```
L = 10 → L' = (10*8)/256 = 0
L = 20 → L' = 0
L = 30 → L' = 0
L = 32 → L' = 1

```

**Osservazione:** tutti i valori piccoli finiscono nello stesso livello. I valori aumentano di livello in blocchi uguali.

---

## 4. Quantizzazione non uniforme

La quantizzazione non uniforme divide il range **in blocchi di dimensione variabile**, più stretti nei valori importanti.

- Formula generale:
    
    ```
    L' = f(L, N, K)
    
    ```
    
    - La funzione `f` definisce come i valori vengono ri-quantizzati.
- Viene usata quando alcune zone del range richiedono **più precisione** (ad esempio i toni scuri nelle immagini).

---

## 5. Quantizzazione logaritmica

È un caso particolare di quantizzazione non uniforme.

- Formula:
    
    ```
    L' = (log2(L) * K) / log2(N)
    
    ```
    
    - log2(L) = parte intera del logaritmo in base 2
    - N = numero livelli in ingresso
    - K = numero livelli in uscita

**Caso comune:** N = 256, K = 8 →

```
L' = log2(L)

```

### Esempi pratici

| L | log2(L) | L' |
| --- | --- | --- |
| 1 | 0 | 0 |
| 5 | 2 | 2 |
| 14 | 3 | 3 |
| 60 | 5 | 5 |
| 200 | 7 | 7 |

**Osservazione:**

- Più livelli nei toni scuri → più dettagli
- Pochi livelli nei toni chiari → valori compressi

### Mini-tabella mentale utile per 0–255 → 8 livelli

| Intervallo L | L′ |
| --- | --- |
| 1 – 1 | 0 |
| 2 – 3 | 1 |
| 4 – 7 | 2 |
| 8 – 15 | 3 |
| 16 – 31 | 4 |
| 32 – 63 | 5 |
| 64 – 127 | 6 |
| 128 – 255 | 7 |

**Frase da dire all’orale:**

> “La quantizzazione logaritmica assegna più livelli ai valori bassi di luminosità, mantenendo dettagli nei toni scuri, mentre i toni chiari sono compressi.”
> 

---

## 6. Riepilogo dei tipi di quantizzazione

| Tipo | Come divide il range | Quando si usa |
| --- | --- | --- |
| Uniforme | Blocchi uguali | Scanner generici, immagini standard |
| Non uniforme | Blocchi variabili | Zone di interesse con più precisione |
| Logaritmica (non uniforme) | Blocchi più piccoli per valori bassi | Fotocamere digitali, radiografie |

---

Se vuoi, posso fare anche **una tabella con esempi di valori concreti da 0 a 255** sia **uniforme** sia **logaritmica**, così hai **tutto pronto per l’esame** e puoi solo leggere e memorizzare.

Vuoi che faccia anche quella?

Perfetto! Ecco una **tabella completa di esempi concreti da 0 a 255** per entrambe le quantizzazioni: uniforme e logaritmica, pronta da mettere su Notion. Ho scelto **8 livelli di uscita (0–7)**, che è il caso più comune e semplice da memorizzare.

---

# Esempio pratico completo – Quantizzazione 0–255 → 8 livelli

### 1. Quantizzazione uniforme

Formula:

```
L' = (L * K) / N

```

- N = 256 (range ingresso 0–255)
- K = 8 (livelli uscita 0–7)

| L (ingresso) | L′ (uscita uniforme) |
| --- | --- |
| 0 – 31 | 0 |
| 32 – 63 | 1 |
| 64 – 95 | 2 |
| 96 – 127 | 3 |
| 128 – 159 | 4 |
| 160 – 191 | 5 |
| 192 – 223 | 6 |
| 224 – 255 | 7 |

**Osservazione:** intervalli uguali (256/8 = 32). Ogni blocco di 32 valori diventa un livello.

---

### 2. Quantizzazione logaritmica

Formula:

```
L' = log2(L)

```

- Prendi la **parte intera del log2(L)**
- Livelli uscita: 0–7

| L (ingresso) | L′ (uscita logaritmica) |
| --- | --- |
| 1 | 0 |
| 2 – 3 | 1 |
| 4 – 7 | 2 |
| 8 – 15 | 3 |
| 16 – 31 | 4 |
| 32 – 63 | 5 |
| 64 – 127 | 6 |
| 128 – 255 | 7 |

**Osservazione:** intervalli **piccoli per valori bassi** (più dettagli nei toni scuri), intervalli **grandi per valori alti** (toni chiari compressi).

---

### 3. Confronto rapido

| L (ingresso) | Uniforme | Logaritmica |
| --- | --- | --- |
| 10 | 0 | 3 |
| 50 | 1 | 5 |
| 100 | 3 | 6 |
| 200 | 6 | 7 |
| 255 | 7 | 7 |

**Frase utile all’esame:**

> “La quantizzazione uniforme divide tutti i valori in blocchi uguali, mentre la logaritmica dà più livelli ai valori bassi per preservare i dettagli dei toni scuri.”
> 

---

Se vuoi, posso anche fare **un mini-schema grafico tipo “barra con livelli”** per uniforme e logaritmica, così la differenza visiva resta impressa e puoi ricordarla subito all’esame. Vuoi che lo faccia?