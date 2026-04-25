# Funzioni di Manipolazione delle Immagini in Processing

---

## 1. Trasformazioni Puntuali

*Funzioni che modificano il valore dei singoli pixel in base al loro valore originale.*

- **`negativo(PImage I)`** – Calcola il negativo di un'immagine invertendo i valori RGB.

- **`gamma(PImage I, float gm)`** – Applica la correzione gamma.

- **`logaritmo(PImage I)`** – Applica la compressione del range dinamico tramite trasformazione logaritmica.

- **`quantizza(PImage I, int k)`** – Riduce il numero di livelli di intensità (colori) dell'immagine a `2^k` livelli.

- **`bitplane(PImage I, int nb)`** – Estrae un singolo piano di bit (bit-plane slicing) dall'immagine.

Ecco i codici:

```processing
//Negativo
PImage negativo(PImage I){ // Prende come parametro l'immagine a cui appicare il filtro.
  PImage R = I.copy(); // Creo una copia dell'originale per non modificarlo direttamente.

  float r,g,b; // Variabili per le nuove componenti di colore.
  I.loadPixels();
  R.loadPixels();  // Carichiamo i pixel dell'immagine R in memoria.

// L'array 'pixels' è linearizzato: contiene tutti i valori di colore in una lunga lista.
// Ricostruisco il nuovo colore e lo assegno alla stessa posizione nell'array.// L'ordine è per righe: prima tutti i pixel della riga 0, poi della riga 1, ecc.
  for(int i=0; i<R.pixels.length; i++){ // Sulla matrice linearizzata, iteriamo e sottraiamo il massimo della scala di grigi (255) ad ogni pixel nella sua componente colore.
    r=255-red(R.pixels[i]);
    g=255-green(R.pixels[i]);
    b=255-blue(R.pixels[i]);

    R.pixels[i] = color(r,g,b); // Ricostruisco il nuovo colore e lo assegno alla stessa posizione nell'array
  }
// Dopo aver modificato 'pixels', devo chiamare updatePixels() per rendere effettive le modifiche.
  R.updatePixels();
  return R; // Restituisce l'immagine.
}
```

```processing
// Gamma
PImage gamma(PImage I, float gm){ // Prende come parametri l'immagine a cui applicare il filtro ed il valore di gamma.
  PImage R = createImage(I.width,I.height, RGB); //Creiamo una immagine vuota in RGB con altezza e larghezza dell'Immagine in ingresso.

  // Carichiamo in memoria entrambi i pixel delle immagini.
  R.loadPixels();    
  I.loadPixels(); // Dobbiamo leggere i pixel dell'originale.
  float r,g,b;    // Creiamo delle variabili float per ogni componente colore.
  float c=1/pow(255,gm-1);  
 // Questa è la costante di normalizzazione. La formula completa è: out = 255 * (in/255)^(gm)
 // Che si può riscrivere come: out = (1/255^(gm-1)) * in^(gm)
 // Dove c = 1/255^(gm-1)

  for(int i=0; i<R.pixels.length; i++){
    // Applico la formula di correzione gamma ad ogni canale.
    r=c*pow(red(I.pixels[i]),gm);
    g=c*pow(green(I.pixels[i]),gm);
    b=c*pow(blue(I.pixels[i]),gm);


    R.pixels[i] = color(r,g,b); // Ricostruisco il nuovo colore e lo assegno alla stessa posizione nell'array
  }

  R.updatePixels();
  return R;
}

//Punto chiave: La correzione gamma è una funzione di potenza. gm > 1 scurisce le zone chiare, gm < 1 le schiarisce. La costante c serve a mantenere il range di output tra 0 e 255.
```

```processing
// Logaritmo
PImage logaritmo(PImage I){
  PImage R=I.copy();

  R.loadPixels();
  I.loadPixels();

  float r,g,b;
// Costante per mappare il risultato nel range 0-255.
// log(1+255) è il valore massimo che possiamo ottenere. 255/log(256) è il fattore di scala.
  float C=255/log(256);

  for(int i=0; i<R.pixels.length; i++){
    // La trasformazione logaritmica: s = c * log(1 + r).
    // Il "+1" evita log(0) che è infinito.
    r=C*log(1+red(I.pixels[i]));
    g=C*log(1+green(I.pixels[i]));
    b=C*log(1+blue(I.pixels[i]));

    R.pixels[i]=color(r,g,b);
  }

  R.updatePixels();
  return R;
}

// Punto chiave: Il logaritmo comprime il range dinamico. È utile quando le zone scure hanno dettagli che non si vedono. Le zone scure (valori bassi) vengono "amplificate" rispetto a quelle chiare.
```

```processing
// Quantizza
PImage quantizza(PImage I, int k) {
  PImage R = I.copy();
  R.loadPixels();

  int q; // Livello quantizzato

  for (int i = 0; i < R.pixels.length; i++) {
    // --- PRIMO PASSO: quantizzazione ---
    // (blue(R.pixels[i]) * k) / 256: mappa il valore 0-255 in un intervallo 0-(k-1).
    // floor() arrotonda all'intero inferiore. Questo crea "k" livelli.
    q = floor((blue(R.pixels[i]) * k) / 256);

    // --- SECONDO PASSO: rimappatura per la visualizzazione ---
    // Ora q è tra 0 e k-1. Per vederlo come un livello di grigio, lo riporto nel range 0-255.
    // (float(q) / (k-1)) mi dà un valore tra 0 e 1. Moltiplicato per 255 lo riporta nel range corretto.
    q = int((float(q) / (k - 1)) * 255);

    R.pixels[i] = color(q);
  }

  R.updatePixels();
  return R;
}

// Punto chiave: La quantizzazione riduce il numero di colori. Il primo passaggio fa la quantizzazione vera e propria, il secondo è solo per visualizzare il risultato come immagine in scala di grigi.
```

```processing
// BitPlane
PImage bitplane(PImage I, int nb) {
  PImage R = I.copy();
  R.loadPixels();

  int x; // Valore del pixel
  int r; // Bit estratto (0 o 1)

  for (int i = 0; i < R.pixels.length; i++) {
    x = int(blue(R.pixels[i])); // Prendo il valore di blu (in una scala di grigi, tutti i canali sono uguali)

    // Operatore di shift a destra (>>): sposta i bit di 'x' di 'nb' posizioni a destra.
    // In questo modo, il bit che ci interessa (nb) diventa il bit meno significativo.
    // &1 (AND bit a bit con 1) maschera tutti i bit tranne il meno significativo.
    // Il risultato è 1 se il bit nb era 1, 0 altrimenti.
    r = (x >> nb) & 1;

    // Assegno il colore: se r=1, 255*1 = 255 (bianco), se r=0, 255*0 = 0 (nero).
    R.pixels[i] = color(255 * r);
  }

  R.updatePixels();
  return R;
}

// Punto chiave: Ogni pixel è rappresentato da un numero (es. 8 bit). Questa funzione estrae un singolo bit (0 o 1) da quel numero, creando un'immagine binaria (bianco e nero). I bit più significativi (nb alto) contengono le informazioni principali dell'immagine, quelli meno significativi (nb basso) il rumore fine.
```

---

## 2. Istogrammi e Contrasto

*Funzioni per l'analisi statistica e il miglioramento del contrasto.*

- **`istogramma(PImage I)`** – Calcola l'istogramma normalizzato (frequenze relative delle intensità).

- **`stretching(PImage I)`** – Effettua l'espansione del contrasto (contrast stretching) lineare.

- **`equalizza(PImage I)`** – Applica l'equalizzazione dell'istogramma per distribuire uniformemente le intensità.

Con lo stretching può essere che ci sia un livello vuoto e quindi il famoso istogramma a pettine, cioè si assicura di usare massimo e minimo.
E invece l'equalizzazione usa tutti i livelli, e quindi appiattisce l'istogramma.

Ecco i codici:

```processing
//Istogramma
//La funzione di istogramma conta quanto spesso appare ogni livello di grigio (0-255)
float [] istogramma(PImage I){ //Gli passiamo come parametro l'immagine da analizzare
  float[] H = new float[256]; //Creiamo un array di 256 numeri (uno per ogni possibile livello di grigio)
  for(int i=0; i<256; i++){ //Iteriamo per tutti i livelli
    H[i]=0; //E inizializziamo per adesso tutto a zero
  }

  I.loadPixels(); //Carichiamo i dati dei pixel dell'immagine per poterli leggere
  for(int i=0; i<I.pixels.length; i++){ //Scansionisamo ogni pixel, leggiamo i valoi del rosso (grigio) (in realtà potremmo farlo anche con G e B) e incremetiamo di 1 la posizione corrispondente nell'array dell'istogramma H
    H[int(red(I.pixels[i]))]++; //Si usa int() per castare
  }

  for(int i=0; i<256; i++){ //Con questo for iteriamo di nuovo i livelli
    H[i]=H[i]/I.pixels.length //E dividiamo ogni valore per il numero totale di pixel. Adesso H contiene la probabilità (0.0 a 1.0) che un pixel abbia quel colore
  }

  return H; //Restituiamo l'istogramma
}
```

```processing
// Stretching
PImage stretching(PImage I) {
  PImage R = I.copy();

  float max, min;
  R.loadPixels();

  // Inizializzo min e max con il valore del primo pixel.
  max = red(R.pixels[0]);
  min = red(R.pixels[0]);

  // Trovo il valore di grigio minimo e massimo effettivi nell'immagine.
  for (int i = 1; i < R.pixels.length; i++) {
    if (red(R.pixels[i]) < min)
      min = red(R.pixels[i]);
    if (red(R.pixels[i]) > max)
      max = red(R.pixels[i]);
  }

  // Applico la formula dello stretching: newValue = 255 * (oldValue - min) / (max - min)
  // Questa è un'equazione di una retta che mappa l'intervallo [min, max] nell'intervallo [0, 255].
  for (int i = 0; i < R.pixels.length; i++) {
    R.pixels[i] = color(255 * (red(R.pixels[i]) - min) / (max - min));
  }

  R.updatePixels();
  return R;
}

// Punto chiave: Lo stretching "allarga" l'istogramma per occupare tutto il range disponibile, aumentando il contrasto. Funziona bene se l'istogramma originale è concentrato in una piccola zona.
```

```processing
// Equalizza
PImage equalizza(PImage I){ //Questa funzione redistribuisce i colori per migliorare il contrasto.
  PImage R = I.copy(); //Creiamo una copia dell'immagine originale come da buona prassi 
  float [] H = istogramma(I); //Chiamiamo la funzione per ottenere l'istogramma dell'immagine

  //Istrogramma cumulativo: ogni posizione 'i' diventa la somma di se stessa e di tutte le precedenti, questo crea una funzione che va da 0 a 1
  for(int i=1;i<256; i++){
    H[i]=H[i-1]+H[i];
  }

  R.loadPixels(); //Carica i pizel dalla copia
  for(int i=0; i < R.pixels.length; i++){
    R.pixels[i]=color(255*H[int(red(R.pixels[i]))]);
/*
for(int i=0; i<R.pixels.length; i++) { ... }: Ciclo su tutti i pixel:
    int(red(R.pixels[i])): Prende il colore originale del pixel.
    H[...]: Usa quel colore come indice nell'istogramma cumulativo.
    color(255 * ...): Moltiplica il valore cumulativo (0.0-1.0) per 255 per riportarlo in scala di grigi e lo assegna al pixel.
*/
  }
  R.updatePixels(); // Applica le modifiche ai pixel dell'immagine R.
  return R; // Restituisce l'immagine equalizzata
}

// Punto chiave: L'equalizzazione usa l'istogramma cumulativo come funzione di mapping. È una tecnica più potente dello stretching, perché non si limita ai soli min e max, ma ridistribuisce tutti i livelli in base alla loro frequenza.
```

---

## 3. Filtri Spaziali (Convoluzione e Rango)

*Operazioni che considerano un intorno di pixel (finestra N×N).*

- **`convoluzione(PImage I, float[][] K)`** – Applica un kernel di convoluzione generico (es. smoothing, sharpening, rilevamento bordi) *(p. 16)*.

- **`massimo(PImage I, int N)`** – Filtro statistico non lineare che assegna al pixel centrale il valore massimo dell'intorno *(p. 12)*.

- **`minimo(PImage I, int N)`** – Filtro statistico che assegna il valore minimo dell'intorno *(p. 13)*.

- **`mediano(PImage I, int N)`** – Filtro per la riduzione del rumore (tipo sale e pepe) che assegna il valore mediano.

Ecco i codici:

```processing
// Convoluzione
float[][] convoluzione(PImage I, float[][] K) {
  // La matrice risultato R ha dimensioni: altezza x larghezza dell'immagine originale.
  // Nota: l'indicizzazione è R[y][x] (prima la riga, poi la colonna).
  float[][] R = new float[I.height][I.width];

  // Dimensioni del kernel (M = righe, N = colonne)
  int M = K.length;       // Altezza del kernel
  int N = K[0].length;    // Larghezza del kernel

  PImage tmp;  // Finestra corrente estratta dall'immagine
  float res;   // Risultato della convoluzione per il pixel (x,y)

  // Scorro TUTTI i pixel dell'immagine di destinazione (che ha le stesse dimensioni di I)
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      // Estraggo un intorno NxM centrato in (x,y).
      // x-N/2, y-M/2 è l'angolo in alto a sinistra dell'intorno.
      // Se l'intorno esce dai bordi, Processing gestisce automaticamente il problema
      // restituendo un'immagine più piccola (solo la parte interna). Questo è un comportamento
      // di default, ma non sempre ideale.
      tmp = I.get(x - N/2, y - M/2, N, M);

      res = 0; // Azzero il risultato per il pixel corrente

      // Convoluzione: somma pesata dei pixel dell'intorno con i coefficienti del kernel.
      // p e q scorrono le dimensioni dell'intorno (e del kernel).
      for (int p = 0; p < N; p++) {         // Scorro le colonne (larghezza)
        for (int q = 0; q < M; q++) {       // Scorro le righe (altezza)
          // green(tmp.get(p, q)): prendo il valore di grigio del pixel (p,q) nell'intorno.
          // K[q][p]: coefficiente corrispondente del kernel (attenzione: K[q][p] e non K[p][q]).
          // Moltiplico e accumulo.
          res = res + green(tmp.get(p, q)) * K[q][p];
        }
      }

      // Assegno il risultato alla posizione (y,x) nella matrice R.
      R[y][x] = res;
    }
  }

  return R; // Restituisce la matrice di float, NON un'immagine!
}
```

```processing
// Massimo
PImage massimo(PImage I, int N) {
  // Crea una nuova immagine vuota delle stesse dimensioni di I.
  PImage R = createImage(I.width, I.height, RGB);
  PImage tmp;          // Finestra corrente
  int off = N / 2;     // Offset per centrare la finestra
  float[] tmpF;        // Array per i valori di grigio dell'intorno

  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      // Estrae un intorno NxN centrato in (x,y)
      tmp = I.get(x - off, y - off, N, N);
      tmp.loadPixels(); // Carica i pixel dell'intorno

      // Alloca un array della dimensione giusta (N*N)
      tmpF = new float[N * N];

      // Copia i valori di grigio (canale verde) nell'array tmpF
      for (int i = 0; i < tmp.pixels.length; i++) {
        tmpF[i] = green(tmp.pixels[i]);
      }

      // Calcola il massimo dell'array e assegna il colore corrispondente al pixel (x,y)
      R.set(x, y, color(max(tmpF)));
    }
  }

  return R;
}
```

```processing
// Minimo
PImage minimo(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  PImage tmp;
  int off = N / 2;
  float[] tmpF;

  int xs; // Coordinata x di partenza della finestra (clampata)
  int ys; // Coordinata y di partenza della finestra (clampata)

  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {

      xs = x - off;
      ys = y - off;

      // Estrae l'intorno, ma con gestione esplicita dei bordi:
      // max(0, xs) assicura di non andare sotto 0.
      // min(N, ...) calcola la larghezza effettiva dell'intorno senza uscire dall'immagine.
      tmp = I.get(max(0, xs), max(0, ys),
                  min(N, min(N + xs, I.width - xs)),
                  min(N, min(N + ys, I.height - ys)));
      tmp.loadPixels();

      // Crea un array della dimensione ESATTA dell'intorno estratto
      tmpF = new float[tmp.pixels.length];

      for (int i = 0; i < tmp.pixels.length; i++) {
        tmpF[i] = green(tmp.pixels[i]);
      }

      // Calcola il minimo e assegna
      R.set(x, y, color(min(tmpF)));
    }
  }

  return R;
}
```

```processing
// Mediano
PImage mediano(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  PImage tmp;
  int off = N / 2;
  float[] tmpF;

  float med; // Valore mediano

  int xs, ys;

  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {

      xs = x - off;
      ys = y - off;

      // Gestione bordi come in minimo()
      tmp = I.get(max(0, xs), max(0, ys),
                  min(N, min(N + xs, I.width - xs)),
                  min(N, min(N + ys, I.height - ys)));
      tmp.loadPixels();

      tmpF = new float[tmp.pixels.length];

      for (int i = 0; i < tmp.pixels.length; i++) {
        tmpF[i] = green(tmp.pixels[i]);
      }

      tmpF = sort(tmpF); // Ordina l'array in ordine crescente
      int s = tmp.pixels.length;

      // Calcolo della mediana:
      if (s % 2 == 1) {
        // Se il numero di elementi è dispari, prendo quello centrale
        med = tmpF[s / 2];
      } else {
        // Se è pari, faccio la media dei due centrali
        med = (tmpF[s / 2] + tmpF[s / 2 - 1]) / 2;
      }

      R.set(x, y, color(med));
    }
  }

  return R;
}
```

---

## 4. Generazione di Rumore

- **`salePepe(PImage I)`** – Aggiunge rumore "sale e pepe" all'immagine, convertendo casualmente alcuni pixel in bianco (sale) o nero (pepe). Solitamente utilizza una probabilità fissa (es. 5%).

- **`salePepe(PImage I, float K)`** – Aggiunge rumore "sale e pepe" all'immagine con una probabilità controllata dal parametro `K` (es. `K = 0.05` per il 5% di pixel alterati). I pixel vengono trasformati in bianco o nero con uguale probabilità.

Ecco i codici:

```processing
// Sale e Pepe
// Versione con probabilità fissa (es. 5%)
PImage salePepe(PImage I) {
  PImage R = I.copy();
  R.loadPixels();
  for (int i = 0; i < R.pixels.length; i++) {
    float rnd = random(1);
    if (rnd < 0.025) {            // 2.5% di probabilità per il sale
      R.pixels[i] = color(255);    // Bianco (sale)
    } else if (rnd < 0.05) {       // 2.5% di probabilità per il pepe
      R.pixels[i] = color(0);      // Nero (pepe)
    }
    // 95% dei pixel rimane invariato
  }
  R.updatePixels();
  return R;
}
```

```processing
// Sale e Pepe con probabilità K
// Versione con probabilità controllata K
PImage salePepe(PImage I, float K) {
  PImage R = I.copy();
  R.loadPixels();
  for (int i = 0; i < R.pixels.length; i++) {
    float rnd = random(1);
    if (rnd < K/2) {               // K/2 di probabilità per il sale
      R.pixels[i] = color(255);     // Bianco (sale)
    } else if (rnd < K) {           // K/2 di probabilità per il pepe
      R.pixels[i] = color(0);       // Nero (pepe)
    }
    // (1-K)% dei pixel rimane invariato
  }
  R.updatePixels();
  return R;
}
```

---

## 5. Trasformazioni geometriche

*Operazioni di ridimensionamento, rotazione e interpolazione.*

- **`replication2x(PImage I)`** – Ingrandimento 2× tramite l'algoritmo del vicino più prossimo (pixel replication) *(p. 9)*.

- **`scaleF(PImage I, float cx, float cy)`** – Scaling con mappatura diretta (Forward mapping) *(p. 17)*.

- **`scaleI(PImage I, float cx, float cy)`** – Scaling con mappatura inversa (Inverse mapping), generalmente preferibile per evitare buchi *(p. 18)*.

- **`rotateF(PImage I, float theta)`** – Rotazione con mappatura diretta *(p. 19)*.

- **`rotateI(PImage I, float theta)`** – Rotazione con mappatura inversa.

Ecco i codici:

```processing
// Zooming-In con Replicazione (Nearest Neighboor)
PImage replication2x(PImage I) {
  PImage R = createImage(2 * I.width, 2 * I.height, RGB);  // Crea una nuova immagine con dimenisioni doppie
  I.loadPixels(); // Carica i pixel
  for (int x = 0; x < I.width; x++) {  // Facciamo un doppio for per scansionare ogni singolo pixel dell'immagine 256x256
    for (int y = 0; y < I.height; y++) {
      color c = I.get(x, y);
      // Copia il pixel in un blocco 2x2
      // Dato che adesso ogni pixel deve occupare lo spazio di quattro pixel, lo "spalma" su un quadratino 2x2 nella nuva immagine
      R.set(2*x,     2*y,     c); // In alto a sinistra
      R.set(2*x + 1, 2*y,     c); // In alto a destra
      R.set(2*x,     2*y + 1, c); // In basso a sinistra
      R.set(2*x + 1, 2*y + 1, c); // I basso a destra (nella matrice 2x2 ovviamente)
    }
  }
  return R;
}
```

```processing
// Scale Forward Mapping
PImage scaleF(PImage I, float cx, float cy) {
  PImage R = I.copy(); // Parte dall'immagine originale (stesse dimensioni)
  R.loadPixels();

  // Inizializza TUTTI i pixel a nero (0). Importante: i pixel non scritti resteranno neri.
  for (int i = 0; i < R.pixels.length; i++) {
    R.pixels[i] = color(0);
  }

  float x, y;       // Coordinate di destinazione (nell'immagine R)
  float v1, w1;     // Coordinate centrate nell'originale

  // Scorro TUTTI i pixel dell'immagine ORIGINALE (v, w)
  for (int v = 0; v < I.width; v++) {
    for (int w = 0; w < I.height; w++) {

      // 1. Porto le coordinate (v, w) ad essere centrate in (0,0)
      //    Sottraggo la metà della larghezza/altezza
      v1 = v - I.width / 2;
      w1 = w - I.height / 2;

      // 2. Applico lo scaling (moltiplico per i fattori cx, cy)
      x = v1 * cx;
      y = w1 * cy;

      // 3. Rimetto le coordinate nel sistema originale (aggiungo la metà)
      x = x + I.width / 2;
      y = y + I.height / 2;

      // 4. Scrivo il pixel dell'originale (v,w) nella posizione (x,y) dell'immagine R
      //    round() arrotonda all'intero più vicino perché le coordinate devono essere intere
      R.set(round(x), round(y), I.get(v, w));
    }
  }

  R.updatePixels();
  return R;
}
```

```processing
// Scale Inverse Mapping
PImage scaleI(PImage I, float cx, float cy) {
  PImage R = I.copy(); // Parte dall'immagine originale (stesse dimensioni)
  R.loadPixels();

  // Inizializza tutti i pixel a nero (non strettamente necessario, ma buona prassi)
  for (int i = 0; i < R.pixels.length; i++) {
    R.pixels[i] = color(0);
  }

  float v, w;       // Coordinate di origine (nell'immagine I)
  float x1, y1;     // Coordinate centrate nel risultato

  // Scorro TUTTI i pixel dell'immagine RISULTATO (x, y)
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {

      // 1. Porto le coordinate (x, y) ad essere centrate in (0,0)
      x1 = x - I.width / 2;
      y1 = y - I.height / 2;

      // 2. Applico lo scaling inverso (divido per i fattori)
      //    Questa è la differenza fondamentale con scaleF: qui cerco da dove viene il pixel
      v = x1 * (1 / cx);
      w = y1 * (1 / cy);

      // 3. Rimetto le coordinate nel sistema originale
      v = v + I.width / 2;
      w = w + I.height / 2;

      // 4. Prendo il pixel dall'originale (v,w) e lo scrivo nella posizione (x,y) di R
      R.set(x, y, I.get(round(v), round(w)));
    }
  }

  R.updatePixels();
  return R;
}
```

```processing
// Rotazione con mappatura diretta
PImage rotateF(PImage I, float theta) {
  PImage R = I.copy();
  R.loadPixels();

  // Inizializza tutti i pixel a nero
  for (int i = 0; i < R.pixels.length; i++) {
    R.pixels[i] = color(0);
  }

  float x, y;       // Coordinate di destinazione
  float v1, w1;     // Coordinate centrate nell'originale

  // Scorro tutti i pixel dell'ORIGINALE
  for (int v = 0; v < I.width; v++) {
    for (int w = 0; w < I.height; w++) {

      // Centratura
      v1 = v - I.width / 2;
      w1 = w - I.height / 2;

      // Applico la rotazione (formula di rotazione 2D in senso antiorario)
      //   x' = x*cos(θ) - y*sin(θ)
      //   y' = x*sin(θ) + y*cos(θ)
      x = v1 * cos(theta) - w1 * sin(theta);
      y = v1 * sin(theta) + w1 * cos(theta);

      // Ritorno al sistema di coordinate originale
      x = x + I.width / 2;
      y = y + I.height / 2;

      // Scrivo il pixel nell'immagine risultato
      R.set(round(x), round(y), I.get(v, w));
    }
  }

  R.updatePixels();
  return R;
}
```

```processing
// Rotazione con mappatura inversa
PImage rotateI(PImage I, float theta) {
  PImage R = I.copy();
  R.loadPixels();

  // Inizializza tutti i pixel a nero (non strettamente necessario)
  for (int i = 0; i < R.pixels.length; i++) {
    R.pixels[i] = color(0);
  }

  float v, w;       // Coordinate di origine
  float x1, y1;     // Coordinate centrate nel risultato

  // Scorro tutti i pixel del RISULTATO
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {

      // Centratura
      x1 = x - I.width / 2;
      y1 = y - I.height / 2;

      // Applico la rotazione inversa
      // Per ruotare un punto indietro, uso la matrice inversa (che è la trasposta)
      //   v = x*cos(θ) + y*sin(θ)
      //   w = -x*sin(θ) + y*cos(θ)
      v = x1 * cos(theta) + y1 * sin(theta);
      w = -x1 * sin(theta) + y1 * cos(theta);

      // Ritorno al sistema di coordinate originale
      v = v + I.width / 2;
      w = w + I.height / 2;

      // Prendo il pixel dall'originale e lo assegno al risultato
      R.set(x, y, I.get(round(v), round(w)));
    }
  }

  R.updatePixels();
  return R;
}
```

---

## 6. Valutazione della Qualità e Utilità

- **`MSE(PImage I1, PImage I2)`** – Calcola l'Errore Quadratico Medio tra due immagini *(p. 9)*.

- **`PSNR(PImage I1, PImage I2)`** – Calcola il Rapporto Segnale/Rumore di Picco *(p. 10)*.

- **`pos(int x, int y, int w)`** – Funzione di utilità per calcolare l'indice di un pixel in un array monodimensionale (matrice linearizzata) *(p. 3)*.

- **`converti(float[][] F)`** – Converte una matrice di valori `float` (risultato di una convoluzione) in un oggetto `PImage`

Ecco i codici:

```processing
// MSE
float MSE (PImage I1, PImage I2){
    float res = 0;
    I1.loadPixels();
    I2.loadPixels();

    for(int i = 0; i < I1.pixels.length; i++){ //Prendiamo la matrice linearizzata
       res += pow(red(I1.pixels[i]) - red(I2.pixels[i]), 2); //Eleviamo al quadrato la differenza di pixel. Scegliamo il canale rosso ma potremmo sceglierne anche altri
    }
    res = res/I1.pixels.length; //Questo corrisponde a 1/MN
    return res;
}
```

```processing
// PSNR
float PSNR (PImage I1, PImage I2){
  float res = 0;
  float mse = MSE(I1, I2);

  res = 10 * log(255*255/mse)/log(10);
  return res;
} 
```

```processing
// Pos
int pos(int x, int y, int w) {
  // Restituisce l'indice lineare corrispondente alle coordinate (x, y)
  // in un'immagine di larghezza 'w'.
  //
  // L'array pixels[] di Processing è linearizzato per righe:
  // - Prima tutti i pixel della riga 0 (da x=0 a x=w-1)
  // - Poi tutti i pixel della riga 1, e così via.
  //
  // Quindi l'indice si calcola come: (riga * larghezza) + colonna
  return x + y * w;
}
```

Punti chiave:

- **A cosa serve**: Quando si lavora con l'array pixels[], non si può usare direttamente (x, y) perché l'array è monodimensionale. Questa funzione converte le coordinate 2D in un indice lineare.

- **Formula**: indice = x + y * larghezza
  
  - x è la colonna (offset all'interno della riga)
  
  - y * w salta tutte le righe precedenti

- **Esempio**: In un'immagine 512×512, il pixel in alto a sinistra (0,0) ha indice 0 + 0*512 = 0. Il pixel in basso a destra (511,511) ha indice 511 + 511*512 = 511 + 261632 = 262143, che è l'ultimo elemento dell'array (perché 512×512 = 262144 pixel, e gli array partono da 0).

```processing
// Converti
PImage converti(float[][] F) {
  // Crea una nuova immagine RGB con le dimensioni della matrice F.
  // F[0].length è il numero di colonne (larghezza)
  // F.length è il numero di righe (altezza)
  PImage R = createImage(F[0].length, F.length, RGB);

  float res = 0; // Variabile per il valore temporaneo (dopo clamping)

  // Scorro tutti i pixel dell'immagine da creare
  for (int x = 0; x < R.width; x++) {
    for (int y = 0; y < R.height; y++) {

      // Prendo il valore dalla matrice F.
      // Attenzione: F è indicizzata come [y][x] (prima riga, poi colonna)
      // Questo perché nella convoluzione abbiamo costruito R[y][x] = res
      float valore = F[y][x];

      // Clamping: costringo il valore a stare nell'intervallo [0, 255]
      // I risultati della convoluzione possono essere negativi o maggiori di 255.
      // constrain() è una funzione di Processing che fa proprio questo:
      // se valore < 0, res = 0; se valore > 255, res = 255; altrimenti res = valore.
      res = constrain(valore, 0, 255);

      // Assegno il colore (scala di grigi) al pixel (x, y)
      R.set(x, y, color(res));
    }
  }

  return R;
}
```
