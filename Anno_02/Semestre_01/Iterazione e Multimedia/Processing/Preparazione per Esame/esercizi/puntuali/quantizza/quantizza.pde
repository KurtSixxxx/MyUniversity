//Quantizzazione ricuce il numero di colori.
//L'immagine sarà in scala di grigi.
PImage lena, lenaQ;

PImage quantizza(PImage I, int k) {
  PImage R = I.copy();
  R.loadPixels();
  
  int q; //Livello quantizzato

  for (int i = 0; i < R.pixels.length; i++) {
    //Primo passo: quantizzazione
    //Facciamo il mapping del valore in un intervallo [0, k-1]
    //Con il floor arrotondiamo all'intero inferiore. Così avremo k livelli
    q = floor((blue(R.pixels[i]) * k) / 256);
    println("PRIMO PASSO: Valore di q: "+q+ " Valore di k: "+k);

    //Secondo passo: rimappa per vederlo come livello di grigio nell'inytervallo [0,255]
    // (float(q) / (k-1)) mi dà un valore tra 0 e 1. Moltiplicato per 255 lo riporta nel range corretto.
    q = int((float(q) / (k - 1)) * 255);
    println("SECONDO PASSO: Valore di q: "+q+ "Valore di k: "+k);
    R.pixels[i] = color(q);
  }

  R.updatePixels();
  return R;
}

void setup() {
  size(1024, 512);
  lena = loadImage("lena.png");
    int k = 8;
  lenaQ = quantizza(lena, k);
  image(lena, 0,0);
  image(lenaQ, 512,0);
}
