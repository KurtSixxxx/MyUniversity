//Filtro gamma
PImage lena, lenaG;

PImage gamma(PImage I, float gm) {
  PImage R = I.copy(); //Copia immagine originale
  R.loadPixels(); //Carica in memoria i pixels

  float r, g, b; //Crea variabili per nuove componenti colore
  float c = 1 / pow(255, gm-1); //La normalizzazione per calcolare il gamma. c = 1/255^(gm-1)

  for (int i = 0; i < R.pixels.length; i++) { //Itera la matrice di pixels linearizzata per tutta la lunghezza
  //Ad ogni componente colore (r,g,b) moltiplico la costamte di normalizzazione per il pixel è elevato al valore di gamma
    r = c * pow(red(I.pixels[i]), gm);
    g = c * pow(green(I.pixels[i]), gm);
    b = c * pow(blue(I.pixels[i]), gm);
    
    R.pixels[i] = color(r,g,b); //Compongo il nuovo colore del pixel
  }

  R.updatePixels(); //Ricarico i pixel nuovi
  return R; //Resitutisco l'immagine
}

void setup() {
  size(1024, 512);
  float gm = 0.5;
  lena = loadImage("lena.png");
  lenaG = gamma(lena, gm);
  image(lena, 0, 0);
  image(lenaG, 512, 0);
}
