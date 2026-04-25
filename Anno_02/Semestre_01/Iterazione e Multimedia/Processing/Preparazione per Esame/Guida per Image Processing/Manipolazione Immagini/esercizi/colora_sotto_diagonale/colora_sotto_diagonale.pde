//Come colorare sopra e sotto diagonale

PImage originale, coloreDiagonale;

PImage colo(PImage originale) {
  PImage risultato = originale.copy(); //Facciamo copia dell'orginale
  risultato.loadPixels(); //Carichiamo i pixels

  int w = risultato.width; //w = larghezza
  int h = risultato.height; //h = altezza

  for (int y = 0; y < h; y++) { // finché y è minore dell'altezza
    for (int x = 0; x < w; x++) { // finché x è minore della larghezza
      int i = x + y * w; //Usiamo la "formulina" per l'indice
      color c = risultato.pixels[i]; //preleviamo il colore

      //Estraiamo le componenti colore
      float r = red(c);
      float g = green(c);
      float b = blue(c);

      if(x == y){
        r = 255;
      }else if(x + y == w - 1){
        g = 255;
      }else if(y < x){
        b = 255;
      }else{
        r = 255;
        g = 255;
      }

      //Aggiorniamo i colori dei pixel
      risultato.pixels[i] = color(r, g, b);
    }
  }
  risultato.updatePixels();
  return risultato;
}

void setup() {
  size(512, 512);
  originale = loadImage("lena.png");
  originale = colo(originale);
  image(originale, 0, 0);
}
