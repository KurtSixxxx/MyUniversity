PImage lena, lenaQuantizzata;

PImage quantizza(PImage O, int k){
  PImage R = O.copy();
  R.loadPixels();
  
  int q; // Livello quantizzato
  
  for(int i = 0; i < R.pixels.length; i++){
    // --- PRIMO PASSO: quantizzazione ---
    q = floor((blue(R.pixels[i]) * k) / 256); // mappa il valore 0-255 in un intervallo 0-(k-1). floor() arrotonda all'intero inferiore. Questo crea "k" livelli.
    // --- SECONDO PASSO: rimappatura per la visualizzazione ---
    q = int((float(q) / (k - 1)) * 255);  // Ora q è tra 0 e k-1. Per vederlo come un livello di grigio, lo riporto nel range 0-255.
    // (float(q) / (k-1)) mi dà un valore tra 0 e 1. Moltiplicato per 255 lo riporta nel range corretto.
    R.pixels[i] = color (q);
   }
   
   R.updatePixels();
   return R;
}

void setup(){
  size(1024,512);
  lena = loadImage("lena.png");
  int k = 3;
  lenaQuantizzata = quantizza(lena, k);
  image(lena, 0,0);
  image(lenaQuantizzata, 512,0);
}
