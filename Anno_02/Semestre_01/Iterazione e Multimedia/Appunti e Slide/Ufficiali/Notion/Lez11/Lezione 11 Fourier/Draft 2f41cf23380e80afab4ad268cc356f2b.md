# Draft

[Ripasso prerequisiti](Draft/Ripasso%20prerequisiti%202f51cf23380e80aab3f4de698468e354.md)

**Concetto 1: L'immagine come segnale e le "onde"**

Di solito pensiamo a una foto come a un insieme di oggetti (un viso, un albero). In questo contesto, invece, dobbiamo vederla come un **segnale**.

Immagina di scorrere il dito su una riga orizzontale di un'immagine in bianco e nero:

- Quando incontri pixel neri, il valore è basso.
- Quando incontri pixel bianchi, il valore è alto.
- Se ci sono strisce alternate (bianco-nero-bianco-nero), il valore sale e scende regolarmente.

Fourier ha avuto un'idea geniale: ha detto che **qualsiasi segnale che si ripete (periodico)** può essere costruito semplicemente sommando tante **onde semplici (seni e coseni)** di diverse velocità e altezze

---

### 1. Funzioni Periodiche e Serie di Fourier

Ho capito che una **funzione periodica** (ad esempio un'onda sinusoidale che si ripete nel tempo) può essere espressa come **somma di seni e coseni** con diverse frequenze e ampiezze. In pratica, un'oscillazione visivamente complessa può essere scomposta in una serie di oscillazioni più "semplici" (sinusoidi) che, sommate tra loro, ricostruiscono l'onda originale. Questo processo di scomposizione e ricostruzione si realizza tramite la **Serie di Fourier**.

### 2. Funzioni Non Periodiche e Trasformata di Fourier

Se invece abbiamo una **funzione non periodica** (cioè che non si ripete in modo regolare), essa può essere espressa come **integrale di seni e coseni** moltiplicati per opportune **funzioni-peso** (o coefficienti). Questo strumento è la **Trasformata di Fourier**.

In sintesi, attraverso gli strumenti di Fourier possiamo **scomporre e ricostruire** un segnale o una funzione **senza perdere informazioni**.

### 3. Applicazione all'Image Processing

Nell'**elaborazione delle immagini** (image processing) questo approccio è applicabile perché possiamo interpretare un'immagine come un **segnale che varia nello spazio** (in due dimensioni). In questo contesto, il valore della funzione in ogni punto (pixel) definisce la sua intensità (es. il **livello di grigio**).

### 4. Parametri di un'Onda

Per descrivere un'onda si utilizzano questi parametri:

- **Ampiezza**: l'intensità dell'onda, spesso espressa in decibel (dB). Rappresenta, graficamente, la distanza dall'asse orizzontale al picco massimo ("quanto è grande").
- **Periodo (T)**: il tempo impiegato per compiere un ciclo completo (es. da un picco al picco successivo).
- **Frequenza (f)**: il numero di cicli che si ripetono in un'unità di tempo. È l'inverso del periodo (f = 1/T).

### 5. Formula di Eulero e Numeri Complessi

Per ogni numero reale **x** (interi, decimali, costanti come π) vale la **formula di Eulero**:

- e^(ix) = cos x + i sen x
- e^(-ix) = cos x - i sen x
dove **i** è l'unità immaginaria (√-1).

Un **numero complesso** è della forma **a + bi**, dove:

- **a** è la parte reale (coordinata sull'asse orizzontale).
- **b** è la parte immaginaria (coordinata sull'asse verticale, moltiplicata per **i**).
Viene rappresentato graficamente sul **Piano di Gauss** (o piano complesso).

Un numero complesso **z = a + bi** può essere visto anche come un **vettore** (una freccia) che parte dall'origine (0,0) e arriva al punto (a, b). Questo vettore ha due caratteristiche fondamentali:

1. **Modulo (o Ampiezza)**: la lunghezza della freccia, calcolata come |z| = √(a² + b²). Rappresenta la "distanza dall'origine" o, nel contesto di Fourier, l'"intensità" di una componente.
2. **Fase (o Argomento)**: l'angolo **φ** che il vettore forma con il semiasse reale positivo. Indica la "direzione" del vettore.

### 6. Trasformata di Fourier e sue Componenti

La Trasformata di Fourier di una funzione produce un risultato complesso, tipicamente analizzato attraverso tre grandezze derivate:

- **Spettro della Trasformata/Spettro di Ampiezza (o Spettro)**: mostra **quanto** (con quale intensità) è presente ciascuna frequenza nel segnale. Si ottiene dal modulo dei coefficienti complessi.
- **Angolo di Fase/Spettro di Fase**: mostra **dove** (con quale sfasamento) inizia ciascuna componente sinusoidale. Si ottiene dall'argomento (fase) dei coefficienti complessi. La fase determina da quale punto del suo ciclo l'onda inizia.
- **Potenza Spettrale/Spettro di Potenza (o Densità Spettrale di Potenza)**: mostra **quanta energia** è associata a ciascuna frequenza. È proporzionale al quadrato dell'ampiezza (modulo al quadrato).

[Spiegazione](Draft/Spiegazione%202f51cf23380e8092b450f32d31f62e46.md)

### 7. Esempi Pratici di Funzioni Periodiche e Non

Per chiarire la differenza:

- **Funzione Periodica**: qualcosa che si ripete in modo regolare, come il motivo di una **carta da parati a righe o a scacchi**.
- **Funzione Non Periodica**: un evento unico o un pattern irregolare, come l'immagine di **Lena** (una foto famosa nel campo dell'image processing). Essa non contiene forme che si ripetono identiche in tutte le direzioni; presenta dettagli e variazioni uniche. La **Trasformata di Fourier** ci permette di trattare anche queste immagini "singole" come se fossero composte dalla sovrapposizione di onde.