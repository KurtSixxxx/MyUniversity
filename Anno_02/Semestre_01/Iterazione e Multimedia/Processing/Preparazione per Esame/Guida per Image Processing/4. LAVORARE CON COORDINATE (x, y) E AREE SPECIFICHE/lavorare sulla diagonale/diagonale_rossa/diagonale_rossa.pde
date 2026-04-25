//Colorare la diagonale di rosso

PImage Im, RedDiag;

PImage diagonaleRossa(PImage originale) {
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = risultato.width;
  int h = risultato.height;
  
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int i = x + y * w;
      
      if (x == y) {  // SULLA DIAGONALE PRINCIPALE
        risultato.pixels[i] = color(255, 0, 0);  // ROSSO
      }
      // else: lascia originale
    }
  }
  
  risultato.updatePixels();
  return risultato;
}

void setup(){
  size(512,256);
  Im = loadImage("lena.png");
  Im.resize(256,256);
  RedDiag = diagonaleRossa(Im);
  RedDiag.resize(256,256);
  image(Im, 0,0);
  image(RedDiag, 256,0);
}
