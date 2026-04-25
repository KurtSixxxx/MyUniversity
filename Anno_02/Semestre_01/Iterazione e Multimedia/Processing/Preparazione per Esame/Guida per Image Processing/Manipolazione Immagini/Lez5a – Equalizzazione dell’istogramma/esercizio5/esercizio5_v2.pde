PImage lena, lenaEQ;

/*
Teoria
  L’istogramma è un array di 256 valori (da 0 a 255). Ogni posizione k dice quanto spesso appare il livello di grigio k nell’immagine.
   Il professore normalizza l’istogramma, cioè divide ogni conteggio per il numero totale di pixel, ottenendo probabilità (valori tra 0 e 1). In questo modo l’istogramma è indipendente dalla dimensione dell’immagine.
   
Passi
 Creare un array float di 256 elementi, tutti inizializzati a 0.
 Caricare i pixel con loadPixels().
 Per ogni pixel, estrarre il valore di rosso (perché in scala di grigi rosso=verde=blu).
 Convertire in int (con int() o implicitamente) e usarlo come indice per incrementare il contatore.
 Dopo il conteggio, dividere ogni elemento per il numero totale di pixel (I.pixels.length). Così otteniamo la frequenza relativa.
*/

float[] istogramma(PImage I) {
  float[] H = new float[256]; //L'array è di float per contenere le probabilità (0.0 … 1.0).
  I.loadPixels();

  for (int i = 0; i < I.pixels.length; i++) {
    // Prendo il valore di rosso (in scala di grigi è uguale a verde e blu)
    int valore = int(red(I.pixels[i]));   // valore tra 0 e 255
    H[valore]++;

    int totale = I.pixels.length;
    for (int i = 0; i < 256; i++) {
      H[i] = H[i] / totale;    // ora H[i] è la probabilità (0..1)
    }
    return H;
  }

  /*
Teoria
   L’equalizzazione vuole ridistribuire i livelli di grigio in modo che l’istogramma sia il più uniforme possibile.
   Il metodo usa la funzione di distribuzione cumulativa (CDF).
   Se H è l’istogramma normalizzato (probabilità), il cumulativo C si ottiene sommando progressivamente:
   C[0] = H[0], C[1] = H[0]+H[1], …, C[255] = 1.
   
   Per ogni pixel con luminosità originale v, il nuovo valore è:
   nuovo = 255 * C[v]
   Questo mappa i valori in modo che le frequenze diventino più uniformi.
   
Passi
   Creare una copia dell’immagine originale (per non modificarla).
   Calcolare l’istogramma normalizzato con la funzione istogramma().
   Trasformare l’istogramma in cumulativo:
   partendo da i=1, sommare a H[i] il valore precedente.
   Caricare i pixel della copia.
   Per ogni pixel, ottenere il valore di grigio originale (canale rosso), usarlo come indice nell’array cumulativo, moltiplicare per 255, e assegnare il nuovo colore.
   Aggiornare i pixel e restituire l’immagine.
*/

  PImage equalizza(PImage I) {
    PImage R = I.copy();
    float[] H = istogramma(I);

    for (int i = 1; i < 256; i++) {
      H[i] = H[i-1] + H[i];
    }

    R.loadPixels();

    for (int i = 0; i < R.pixels.length; i++) {
      // Prendo il livello di grigio originale (uso il canale rosso)
      int originale = int(red(R.pixels[i]));
      // Nuovo valore = 255 * cumulativo[originale]
      int nuovo = int(255 * H[originale]);
      // Assegno il colore (in scala di grigi, tutti i canali uguali)
      R.pixels[i] = color(nuovo);
    }
    
    R.loadPixels();
    return R;
  }

  void setup() {
    size(768, 256);
    lena = loadImage("lena.png");
    lena.resize(256, 256);
    lenaEQ = equalizza(lena);
    image(lena, 0, 0);
    image(lenaEQ, 256, 0);
  }
