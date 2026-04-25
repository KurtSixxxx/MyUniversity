# Multimedia Security and Biometry - Lezione 5

---

### Treshold

In biometria, la **soglia (threshold)** è il valore di corrispondenza minimo che un sistema deve raggiungere per confermare un'identità. Funziona come un compromesso tra **sicurezza** (evitare accessi non autorizzati) e **usabilità** (facilitare l'accesso agli utenti legittimi). 

Regolando la soglia, si gestiscono due tipi di errore: 

- **Falsa accettazione (FAR)**: Un impostore viene accettato per errore. Un sistema con una soglia bassa rischia di avere un FAR più alto, sacrificando la sicurezza a favore di un uso più semplice.
- **Falso rifiuto (FRR)**: Un utente legittimo viene respinto per errore. Un sistema con una soglia alta riduce il rischio di false accettazioni, ma rende l'accesso più difficile per gli utenti legittimi, aumentando l'FRR. 

Quando il sistema confronta i dati biometrici, produce un "punteggio di corrispondenza" che viene poi comparato alla soglia. Se il punteggio supera la soglia, l'accesso è concesso. In questo modo, modificando il valore della soglia, si calibra l'equilibrio tra i due tipi di errore in base alle esigenze specifiche del contesto (ad esempio, un'alta sicurezza per una banca, o una maggiore usabilità per lo sblocco di un telefono).

### Possibili errori

Un soggetto è accettato da un sistema di riconoscimento se supera una certa soglia (score) di similarità con uno o più elementi in galleria. Quindi facciamo match tra la probabilità e i valori in galleria.

Possono verificarsi 4 tipi di errore.

1. L'identità dichiara è vera e il soggetto è accettato (Genuine Acceptance - indicata come Genuine Match) ✓

2. L'identità dichiarata è vera ma il soggetto non è acccettato (False Rejection) ✘

3. Un impostore viene rigettato (Genuine Reject) ✓

4. Un impostore viene accettato (False Acceptance) ✘

[Analogia con tamponi es. covid19, esiste un margine di errore (Treshold), che ognuno degli acquirenti dovrebbe controllare. Quindi è importante che il tasso d'errore sia il più basso possibile.]

##### Possibili errori: come comparare i sistemi

**FAR (False Acceptance Rate)**

- **Definizione:** Indica la frequenza con cui il sistema accetta erroneamente un individuo non autorizzato. È il rischio che un impostore riesca a superare il controllo biometrico.
- **Implicazioni:** Un FAR alto implica un sistema meno sicuro, perché è più facile ingannarlo. L'obiettivo è sempre avere un FAR il più basso possibile, specialmente in contesti che richiedono un'elevata sicurezza, come l'accesso a informazioni riservate o ad aree sensibili. 

**FRR (False Rejection Rate)**

- **Definizione:** Indica la frequenza con cui il sistema rifiuta erroneamente un individuo autorizzato, negandogli l'accesso pur avendone diritto.
- **Implicazioni:** Un FRR alto si traduce in una scarsa esperienza utente, con utenti legittimi che devono ripetere la scansione o l'autenticazione più volte, causando frustrazione. In applicazioni dove la convenienza è cruciale (ad esempio, lo sblocco di uno smartphone), si cerca di mantenere l'FRR basso.

Altre frequenze che possiamo misurare sono:

- ERR
  
  - **Significato**: L'ERR è il punto in cui il tasso di falsa accettazione (FAR) e il tasso di falso rifiuto (FRR) si equivalgono.
  
  - **Valutazione**: Un valore di ERR più basso indica una maggiore precisione del sistema, suggerendo un buon equilibrio tra sicurezza e usabilità.

- DET
  
  - **Significato**: È una curva grafica che visualizza il compromesso tra l'FRR (sull'asse y) e il FAR (sull'asse x), mostrando la variazione dei tassi di errore al cambiare della soglia.
  
  - **Utilizzo**: Le curve DET sono particolarmente utili per confrontare la performance di diversi sistemi biometrici e per visualizzare chiaramente come la soglia influenzi l'equilibrio tra i due tipi di errore.

- ROC
  
  - **Significato**: La curva ROC è un altro strumento grafico che illustra il compromesso tra il tasso di veri positivi (True Positive Rate) e il tasso di falsi positivi (False Positive Rate), che nel contesto biometrico corrispondono rispettivamente a 1-FRR e FAR.
  
  - **Utilizzo**: Viene utilizzata per valutare la capacità complessiva di un sistema di discriminare tra utenti legittimi e impostori. Un sistema più accurato avrà una curva ROC che si avvicina all'angolo in alto a sinistra del grafico, dove il tasso di veri positivi è alto e il tasso di falsi positivi è basso.

Tutti i campioni (samples) che ricaviamo tramite queste statistiche sono etichettati con l'identità corretta (ground truth)

...

##### Misure di errore:

Definiamo degli insiemi di Prob:

- Prob = tratti biometrici che vengono proposti al sistema in fase di riconoscimento

- $P_G$ = insieme delle prob che sono genuine (persone salvate nella galleria)

- $P_N$ = insieme delle prob che non sono presenti nella galleria ma nel dataset

$$
FRR(t) = \frac{|\{p_j : s_{xj} \leq t, id(g_x) = id(p_j)\}|}{|\{p_j : id(g_x) = id(p_j)\}|}
$$

$$
FAR(t) = \frac{|\{p_j: s_{jx} \geq t \wedge  id(g_x) \neq id(p_j)\}|}{|\{p_j: id(g_x) \neq id(p_j)\}|}
$$

[Controlla slide per integrare appunti Fino a ROC (parte 3) ]

Si va da 0 a 1 in ogni asse
L'area del quadrato su cui misuriamo è = 1
La metà, quindi una diagonale che passa da 0 (origine) a 1 in alto a destra equivale a 0.5
Quando misuriamo l'affidabilità di un sistema si valuta l'area all'interno del trapezio che si è formato.

### Database FERET

Si confronta l'immagine di autenticazione di una donna in input con 4 contenuti nella galleria
Ognuno dei "match" (che siano andati a buon fine o no) forniscono uno score, ed in relazione a questo si setta una treshold.

Se facciamo tante prove, cambiando prob e template, possiamo calcolare tutti i rate dei vari tipi di errore.

<?Calcolo di false alarm?>

DIR. Il rango di "grado 5" dice che abbiamo 5 persone in esame. (Rango di $p_j$)

Se il rango di pj è minore di k si trova nel range
