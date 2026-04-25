PImage ImOriginale;
PImage ImModificata;
int K = 5;

void setup() {
  size(1024, 512);
  // Assicurati che l'immagine sia nella cartella "data" dello sketch
  ImOriginale = loadImage("lena.png"); 
  ImOriginale.resize(512, 512); // Ridimensiono per sicurezza
  ImModificata = saltPepper(ImOriginale, K);
}

void draw() {
  background(255);
  image(ImOriginale, 0, 0);
  image(ImModificata, 512, 0);
  
  // Feedback visivo del valore di K
  fill(0);
  text("K attuale: " + K, 10, 20);
}

PImage saltPepper(PImage img, int K) {
  PImage out = img.copy();
  out.loadPixels();
  
  float prob = (K / 2.0); 
  
  for (int i = 0; i < out.pixels.length; i++) {
    float r = random(100);
    
    if (r < prob) {
      out.pixels[i] = color(255);
    } else if (r > (100 - prob)) {
      out.pixels[i] = color(0);
    }
  } // Fine del ciclo for
  
  out.updatePixels(); // Va chiamato solo una volta alla fine del ciclo
  return out;         // Va chiamato solo una volta alla fine della funzione
}

void keyPressed() {
  if (key == '+') {
    K = constrain(K + 5, 0, 100); // Constrain evita che K esca dai limiti
  } else if (key == '-') {
    K = constrain(K - 5, 0, 100);
  }
  // Ricalcola l'immagine ogni volta che K cambia
  ImModificata = saltPepper(ImOriginale, K);
}
