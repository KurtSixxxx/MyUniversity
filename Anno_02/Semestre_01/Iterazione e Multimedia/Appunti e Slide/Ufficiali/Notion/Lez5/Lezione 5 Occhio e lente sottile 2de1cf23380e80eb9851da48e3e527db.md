# Lezione 5: Occhio e lente sottile

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/06d08fde-b39c-43b6-b038-d2a4214a7d17.png)

---

**Come si forma l’immagine nell’occhio?**

Per lo studio dell’image processing è importante conoscere come l’occhio umano percepisce una immagine e come la elabora.

### L’occhio

Nell’occhio umano è presente la retina, una membrana che ricopre la parte posteriore dell’occhio, formata da coni e bastoncelli che sono i fotorecettori.

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image.png)

- **I coni**
Sono circa 6/7 milioni, concentrati nella zona centrale della retina, la fovea.
Estremamente sensibili al colore ed ogni cono è collegato ad un nervo ottico.
Sono responsabili della vista fototica o policroma.
- **I bastoncelli**
Sono circa 75/150 milioni distribuiti su tutta la retina. Poco sensibili al colore e collegati a gruppi ad un nervo ottico.
Sono responsabili della vista scopotica o monocroma.
- **La fovea**
E’ una regione di 1,5mm x 1,5mm.
Il numero di coni presenti è di circa 337.500 elementi.
Un CCD può contenere lo stesso numero di recettori in almeno 5mm x 5mm.

### Come si forma l’immagine nell’occhio: il PinHole

Per comprendere come si forma l’immagine nell’occhio è opportuno capire il modello del **Pin Hole**.
Si tratta di un modello teorico in cui si approssima l’occhio con una scatola.
All’interno della scatola, su una parete in cui incide la luce, viene posizionata una pellicola particolarmente sensibile ad essa. Mentre nella parete opposta si pratica un foro con uno spillo (pin hole).

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%201.png)

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%202.png)

Il raggio del foro è proporzionale alla radice quadrata della distanza ($d$) per la lunghezza d’onda ($\lambda$) della luce emessa.

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%203.png)

Se viene effettuato un foro puntiforme troppo piccolo genera fenomeni di diffrazione. 

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%204.png)

Un pinhole reale, invece, presenterà un foro con una precisa forma geometrica.

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%205.png)

Un pinhole reale “spalma” la luce proveniente da un impulso su una area finita

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%206.png)

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%207.png)

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%208.png)

Questa differenza tra apertura infinitesima e apertura reale fa riferimento al fenomeno di **diffrazione**.

Quando un’onda (la luce) incide su un apertura si allarga a semisfera.
L’onda si allarga lungo i bordi del foro, e allargandosi si sovrappone con se stessa formando interferenze distruttive e costruttive.

Più il foro è grande, più la figura di diffrazione è piccola. Mentre più piccolo è il foro, più la figura di diffrazione è grande.
La dimensione della figura di diffrazione dipende anche dalla lunghezza d’onda della luce: maggiore è la lunghezza d’onda, maggiore è la diffrazione.

[](Lezione%205%20Occhio%20e%20lente%20sottile/Untitled%202e11cf23380e8075b8b5f766377c29f5.md)

### Lenti sottili

Perché le lenti sottili? Un foro fa entrare solo un filo di luce, e questo vuol dire una immagine debole, quasi invisibile. Invece una lente è una superficie che raccoglie tutta la luce possibile e la concentra regalandoci una immagine luminosa e nitida.

**Regole Geometriche**

Una lente sottile è una lente il cui diametro è maggiore del suo spessore massimo.

Ogni lente ha due punti detti fuochi, e sono equidistanti dalla lente.

1. Se un raggio di luce arriva dritto parallelo all’asse della lente, la lente lo piega e lo fa passare esattamente per il fuoco dall’altra parte
2. Se un raggio di luce parte dal fuoco e colpisce la lente, questa la raddrizza e la fa uscire dall’altra parte parallela all’asse

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%209.png)

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%2010.png)

Quindi, per scoprire dove si formerà l’immagine, basta osservare due raggi. Uno parallelo all’asse ottico che verrà deformato dalla lente e passerà per uno dei due fuochi.
Il secondo che prima di passare per la lente attraversa il fuoco e successivamente diventa parallelo all’asse ottico. Una volta che anche questo sarà uscito dalla lente, il punto in cui si incrociano i due raggi è il punto in cui si crea l’immagine.

### Equazione della lente sottile

Dunque, per determinare la posizione e la nitidezza di un’immagine proiettata da una lente utilizziamo l’equazione della lente sottile.

$$
\frac{1}{u} + \frac{1}{v} = \frac{1}{f} 
$$

Analizziamo tutte le variabili.

![image.png](Lezione%205%20Occhio%20e%20lente%20sottile/image%2011.png)

- $u$ è la distanza tra l’oggetto e la lente
- $v$ è la distanza tra la lente e l’immagine
- $f$ è lunghezza focale della lente, cioè quel segmento che parte da un fuoco, attraversa la lente e arriva all’altro fuoco
- $k$ è l’altezza dell’oggetto
- $h$ è l’altezza dell’immagine

Ecco i 3 scopi principali dell’equazione:

1. **Capire dove si forma l’immagine (La Messa a Fuoco)**
L’equazione serve a calcolare dove finiranno i raggi di luce dopo aver attraversato la lente.
Se sposti l’oggetto (cambi $u$), il punto in cui l’immagine è nitida si sposta di conseguenza (cambia $v$)
Ad esempio, nelle fotocamere digitali, poiché la lente ha un fuoco fisso ($f$ costante), l’equazione spiega perché dobbiamo rimuovere meccanicamente il sensore avanti o indietro per “intercettare” il punto in cui i raggi si incontrano e non avere una foto sfocata.
2. **Spiegare come fa l’occhio a vedere (L’Adattamento)**
L’occhio umano è come una fotocamera speciale, perché il suo sensore (cioè la retina) è fissa e non può muoversi per intercettare l’immagine.
L’equazione descrive come i muscoli dell’occhio deformano il cristallino per cambiare la lunghezza focale ($f$), permettendoci di mettere a fuoco tutto.
3. Calcolare quanto sarà grande il soggetto (**La Magnificazione**)
La magnificazione (o ingrandimento) è il processo che serve ad aumentare la grandezza ottica (digitale) del soggetto rispetto alla sua grandezza reale.
E’ dunque il numero che descrive il fattore di ingrandimento dell’oggetto. Se questo numero è inferiore ad 1 allora si parla di riduzione o rimpicciolimento.
La magnificazione si esprime come il **rapporto tra la distanza della lente dall’immagine ($v$) e la distanza della lente dall’oggetto ($u$).**
    
    $$
    m = v/u
    $$
    
    $m$ viene chiamato “***fattore di magnificazione***”.
    
    **Utilizzo della formula**
    
    Partiamo dall’equazione originale:
    
    $\frac{1}{u} + \frac{1}{v} = \frac{1}{f}$
    
    Questa dice: “Se metto insieme **distanza dell’oggetto** e **distanza dell’immagine**, ottengo qualcosa che chiamiamo lente fissa (f)”.
    
    Immagina così:
    
    - $(u)$ = quanto lontano è un oggetto (tipo un giocattolo) dalla lente
    - $(v)$ = quanto lontano l’immagine appare dopo la lente (tipo dove appare l’ombra del giocattolo)
    - $(f)$ = potere della lente, fisso, come la forza di una lente magica
    
    Passo 1: moltiplico tutto per $(v)$
    
    $\frac{1}{u} + \frac{1}{v} = \frac{1}{f} \quad \Rightarrow \quad \frac{v}{u} + 1 = \frac{v}{f}$
    
    Spiegazione semplice: moltiplicare per $(v)$ è come dire “voglio togliere i denominatori e rendere tutto più facile da leggere”.
    
    - $(\frac{1}{u} \cdot v = \frac{v}{u})$
    - $(\frac{1}{v} \cdot v = 1)$
    - $(\frac{1}{f} \cdot v = \frac{v}{f})$
    
    Passo 2: sostituisco $(\frac{v}{u})$  con $(m)$, ossia il fattore di magnificazione.
    
    $m + 1 = \frac{v}{f}$
    
    Questo è solo un trucco per non avere frazioni complicate, così (m) diventa “quanto l’immagine è grande rispetto all’oggetto”.
    
    Passo 3: invertiamo i termini
    
    **$\frac{v}{f} = m + 1$**
    
    Questo è semplice: stiamo solo scrivendo la stessa cosa in un modo più comodo per poi trovare $(f)$.
    
    Passo 4: troviamo $(f)$
    
    $f = \frac{v}{m+1}$
    
    Adesso possiamo capire $(f)$ come “quanto vale la lente” se sappiamo $(v)$ e $(m)$.
    
    Passo 5: sostituiamo $(v)$ con $(u \cdot m)$
    
    $(\frac{v}{u} = m \Rightarrow v = u \cdot m)$
    
    $f = \frac{v}{m+1} = \frac{u \cdot m}{m+1}$
    
    Ora abbiamo una formula finale molto semplice:
    
    - Se sai quanto è lontano l’oggetto $(u)$ e quanto è grande il rapporto di ingrandimento $(m)$, puoi calcolare la forza della lente $(f)$.
    
    **Esempi di magnificazione**
    
    Immagina un occhio che osserva una palma alta $15$ metri posta ad una distanza $u$ di $100$  metri,
    Sapendo che la distanza tra il centro ottico della lente dell’occhio e la retina ($v$) è $17$, è possibile calcolare l’altezza dell’immagine proiettata sulla retina, cioè: $15/100 = h/0.017$ e cioè $h = 2,55 mm$.
    
    Dati che abbiamo:
    
    - Altezza reale della palma: (H = 15 , \text{m})
    - Distanza della palma dall’occhio: (u = 100 , \text{m})
    - Distanza dalla lente dell’occhio alla retina: (v = 0.017 , \text{m}) (cioè 17 mm)
    - Altezza dell’immagine sulla retina: (h = ?)
    
    Step 1: usare il rapporto tra oggetto e immagine
    La formula usata è questa:
    $\frac{\text{altezza oggetto}}{\text{distanza oggetto}} = \frac{\text{altezza immagine}}{\text{distanza immagine}}$
    
    In simboli:
    $\frac{H}{u} = \frac{h}{v}$
    Questa formula viene dalla geometria dei triangoli simili: immagina il cono di luce che va dall’oggetto alla retina; è come un piccolo triangolo dentro un triangolo grande.
    
    Step 2: sostituire i numeri
    $\frac{15}{100} = \frac{h}{0.017}$
    
    - 15 metri = altezza della palma
    - 100 metri = distanza della palma dall’occhio
    - (h) = altezza dell’immagine sulla retina (incognita)
    - 0.017 metri = distanza dalla lente alla retina
    
    Step 3: risolvere per (h)
    Moltiplichiamo entrambi i lati per (0.017) per isolare (h):
    
    $h = 0.017 \cdot \frac{15}{100}$
    
    Step 4: fare i calcoli passo passo
    
    1. Dividiamo $(15 / 100 = 0.15)$
    2. Moltiplichiamo $(0.017 \cdot 0.15)$
    
    Facciamo con calma:
    
    - $(0.017 \cdot 0.1 = 0.0017)$
    - $(0.017 \cdot 0.05 = 0.00085)$
    - Sommiamo: $(0.0017 + 0.00085 = 0.00255 , \text{m})$
    
    Convertiamo in millimetri:
    $0.00255 , \text{m} = 2.55 , \text{mm}$
    
    **Risultato finale:** l’immagine della palma sulla retina è lunga circa **2,55 mm**.