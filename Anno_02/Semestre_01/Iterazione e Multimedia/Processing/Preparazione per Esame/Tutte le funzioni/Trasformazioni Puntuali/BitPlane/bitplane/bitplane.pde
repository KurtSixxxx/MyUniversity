PImage lena, lenaBitPlane;

//La tua funzione "scortica" l'immagine e ti mostra solo lo strato che hai scelto con nb.
PImage bitplane(PImage O, int nb){
  PImage R = O.copy();
  R.loadPixels();
  
  int x; //Valore del pixel
  int r; //Bit estratto (0 o 1);
  
  for(int i = 0; i < R.pixels.length; i++){
    x = int(blue(R.pixels[i])); //Prendo il valore di una componente colore qualsiasi
    //Shifto a destra: spostiamo i bit di 'x' di 'nb' posizioni a destra
    // &1 (AND bit a bit con 1) maschera tutti i bit tranne il meno significativo.
    // Il risultato è 1 se il bit nb era 1, 0 altrimenti.
    r = (x >> nb) & 1;
    
    // Assegno il colore: se r=1, 255*1 = 255 (bianco), se r=0, 255*0 = 0 (nero).
    R.pixels[i] = color(255 * r);
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(1024,512);
  lena = loadImage("lena.png");
  //Il valore di nb deve andare da 0 a 7
  int nb = 7;
  lenaBitPlane = bitplane(lena, nb);
  image(lena, 0,0);
  image(lenaBitPlane, 512,0);
}
