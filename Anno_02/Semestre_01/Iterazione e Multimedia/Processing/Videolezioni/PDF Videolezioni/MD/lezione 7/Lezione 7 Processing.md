# Lezione 7 Processing

// spiega cosa dobbiamo fare -> replicazione

### Funzioni di Zooming-In (replicazione), MSE e PSNR

```processing
PImage Im, Ic, Ir;
/*  Abbiamo 3 immagini:
  - Im (Originale): E' l'immagine di partenza (che viene convertita poi in scala di grigi con filter(GRAY))
  - Ic (Processing): E' l'immagine che viene usata per testare il ridimensionamento integrato di Processing (che di default usa il l'interpolazione bilinerare, più sfocata)
  - Ir (Replication): E' l'immagine che usiamo per testare la funzione scritta da noi. Con il metodo "Nearest Neighbor", più "pixelato".
  La funzione vuole fare zooming-in di una foto in 256, e renderla 512; quindi deve "Inventare" i pixel mancanti.
*/

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

float PSNR (PImage I1, PImage I2){ //Qui scriviamo la formula di PSNR sottoforma di funzione in Java
  float res = 0;
  float mse = MSE(I1, I2);
  res = 10 * log(255*255/mse)/log(10);
  return res;
}

void setup(){
  size(1536, 512);
  Im = loadImage("lena.png"); // Carichiamo lena
  Im.filter(GRAY); // Applichiamo il filtro di grigio

  // Processing (Bilineare di default)
  Ic = Im.copy();
  Ic.resize(256, 256);
  Ic.resize(512, 512);

  // Replication (ossia la funzione creata da noi, lo zooming-in 2x per intenderci)
  Ir = Im.copy();
  Ir.resize(256, 256);
  Ir = replication2x(Ir); // Chiami la funzione

  image(Im, 0, 0);
  image(Ic, 512, 0);
  image(Ir, 1024, 0);

  float mseO = MSE(Im,Im);
  float mseP = MSE(Im,Ic);
  float mseR = MSE(Im,Ir);

  float psnrO = PSNR(Im, Im);
  float psnrP = PSNR(Im, Ic);
  float psnrR = PSNR(Im, Ir);

  println("MSE con se stessa: "+mseO);
  println("PSNR con se stessa: "+psnrO);
  println("MSE processing: "+mseP);
  println("PSNR processing: "+psnrP);
  println("MSE replication: "+mseR);
  println("PNSR replication: "+psnrR);
}
```

## Funzioni di equalizzazione e stretching

```processing
//Equalizzazione
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

## Funzioni di convoluzione

```processing
// CONVOLUZIONE
PImage Im, In3, In5, Il, Is, IsX;

// Creo i kernel
float n3 = 1.0/9.0;
float[][] nbox3 = { {n3, n3, n3}, 
                    {n3, n3, n3}, 
                    {n3, n3, n3} };

float n5 = 1.0/25.0;
float[][] nbox5 = { {n5, n5, n5, n5, n5}, 
                    {n5, n5, n5, n5, n5}, 
                    {n5, n5, n5, n5, n5}, 
                    {n5, n5, n5, n5, n5}, 
                    {n5, n5, n5, n5, n5} };

//Laplaciano
float[][] lapl = { {-1, 0, -1}, 
                   { 0, 4,  0}, 
                   {-1, 0, -1} };

//SobelX
float[][] sobX = { {-1, -2, -1}, 
                   { 0,  0,  0}, 
                   { 1,  2,  1} };

//Sharpening
float[][] sharp = { {-1, 0, -1}, 
                    { 0, 5,  0}, 
                    {-1, 0, -1} };

float[][] random = { {2, -2, -3}, 
                     {2, -1, 0.5}, 
                     {-1, 4,  2} };

void setup() {
  size(1536, 1024);
  Im = loadImage("lena.png");
  Im.filter(GRAY);

  // Convoluzione su matrici e conversione in PImage
  In3 = converti(convoluzione(Im, nbox3));
  In5 = converti(convoluzione(Im, nbox5));
  Il  = converti(convoluzione(Im, lapl));
  Is  = converti(convoluzione(Im, sharp));
  IsX = converti(convoluzione(Im, sobX));

  // Visualizzazione immagini
  image(Im, 0, 0);
  image(In3, 512, 0);
  image(In5, 1024, 0);
  image(Il, 0, 512);
  image(Is, 512, 512);
  image(IsX, 1024, 512);
}

void draw() {
  // Lasciato vuoto intenzionalmente
}

float[][] convoluzione(PImage I, float[][] K) {
  float[][] R = new float[I.height][I.width];
  int N = K[0].length; // Larghezza kernel
  int M = K.length;    // Altezza kernel
  PImage tmp;
  float res;

  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      // Estrae la sotto-immagine centrata nel pixel corrente
      tmp = I.get(x - N/2, y - M/2, N, M);
      res = 0;
      for (int p = 0; p < N; p++) {
        for (int q = 0; q < M; q++) {
          res += green(tmp.get(p, q)) * K[q][p];
        }
      }
      R[y][x] = res;
    }
  }
  return R;
}

PImage converti(float[][] F) {
  PImage R = createImage(F[0].length, F.length, RGB);
  for (int x = 0; x < R.width; x++) {
    for (int y = 0; y < R.height; y++) {
      // Normalizza i valori tra 0 e 255
      int val = int(constrain(F[y][x], 0, 255));
      R.set(x, y, color(val));
    }
  }
  return R;
}
```

## Filtri di rango (massimo, minimo e mediano)

```processing
// FILTRI DI RANGO (Massimo, Minimo, Mediano)
PImage Im, Imax, Imin, Imed;

void setup() {
  size(1024, 1024);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  
  // Applichiamo i filtri con una finestra di dimensione 11x11
  Imax = massimo(Im, 11);
  Imin = minimo(Im, 11);
  Imed = mediano(Im, 11);
  
  // Visualizzazione a griglia
  image(Im, 0, 0);       // Originale (Top-Left)
  image(Imax, 512, 0);   // Massimo (Top-Right)
  image(Imin, 0, 512);   // Minimo (Bottom-Left)
  image(Imed, 512, 512); // Mediano (Bottom-Right)
}

void draw() {
  // Vuoto
}

// Filtro di Massimo (Dilatazione)
PImage massimo(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int off = N/2;
  
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      // Estrazione sotto-immagine con gestione automatica dei bordi (get)
      PImage tmp = I.get(x - off, y - off, N, N);
      tmp.loadPixels();
      
      float[] valori = new float[tmp.pixels.length];
      for (int i = 0; i < tmp.pixels.length; i++) {
        valori[i] = red(tmp.pixels[i]);
      }
      R.set(x, y, color(max(valori)));
    }
  }
  return R;
}

// Filtro di Minimo (Erosione)
PImage minimo(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int off = N/2;
  
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      PImage tmp = I.get(x - off, y - off, N, N);
      tmp.loadPixels();
      
      float[] valori = new float[tmp.pixels.length];
      for (int i = 0; i < tmp.pixels.length; i++) {
        valori[i] = red(tmp.pixels[i]);
      }
      R.set(x, y, color(min(valori)));
    }
  }
  return R;
}

// Filtro Mediano (Rimozione Rumore)
PImage mediano(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  int off = N/2;
  
  for (int x = 0; x < I.width; x++) {
    for (int y = 0; y < I.height; y++) {
      PImage tmp = I.get(x - off, y - off, N, N);
      tmp.loadPixels();
      
      int nPixel = tmp.pixels.length;
      float[] valori = new float[nPixel];
      
      for (int i = 0; i < nPixel; i++) {
        valori[i] = red(tmp.pixels[i]);
      }
      
      // Ordiniamo i valori per trovare la mediana
      valori = sort(valori);
      float med;
      
      if (nPixel % 2 == 1) {
        med = valori[nPixel/2];
      } else {
        med = (valori[nPixel/2] + valori[nPixel/2 - 1]) / 2.0;
      }
      
      R.set(x, y, color(med));
    }
  }
  return R;
}

```

## Funzioni di bitplane

```processing
// BITPLANE
PImage Im, Ib;
int K;

void setup() {
  size(1024, 512);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  
  K = 7; // Partiamo dal bit più significativo (MSB)
  Ib = bitplane(Im, K);
  
  image(Im, 0, 0);   // Originale a sinistra
  image(Ib, 512, 0); // Bitplane a destra
  println("Visualizzazione Bit: " + K);
}

void draw() {
  // Vuoto
}

// Funzione per estrarre l'n-esimo piano dei bit
PImage bitplane(PImage I, int nb) {
  PImage R = I.copy();
  R.loadPixels();
  
  for (int i = 0; i < R.pixels.length; i++) {
    // Estraiamo il valore (usiamo blue, ma essendo GRAY i canali sono uguali)
    int x = int(blue(R.pixels[i]));
    
    // Operazione bitwise: shift a destra di 'nb' posizioni e AND con 1
    int r = (x >> nb) & 1;
    
    // Moltiplichiamo per 255 per visualizzare il bit come bianco (1) o nero (0)
    R.pixels[i] = color(r * 255);
  }
  
  R.updatePixels();
  return R;
}

// Controllo interattivo con la tastiera
void keyPressed() {
  if ((key == '+') && (K < 7)) {
    K++;
    Ib = bitplane(Im, K);
    image(Ib, 512, 0);
    println("Visualizzazione Bit: " + K);
  }
  
  if ((key == '-') && (K > 0)) {
    K--;
    Ib = bitplane(Im, K);
    image(Ib, 512, 0);
    println("Visualizzazione Bit: " + K);
  }
}

```
