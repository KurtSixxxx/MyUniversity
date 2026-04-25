/*con - e + modifico i colori dell'immagine*/
PImage I, I_original;
float r, g, b;
color c, c1;
int ar;

void setup() {
  size(512, 512);
  I = loadImage("lena.png");
  I.resize(512, 512); // assicurati che la dimensione sia 512x512
  I_original = I.copy(); // salviamo la versione originale
  ar = 0;

  c = color(255, 255, 0); // giallo

  I.loadPixels();
  for (int i = 0; i < I.width; i++) {
    I.pixels[pos(i, i, I.width)] = c;
  }
  I.updatePixels();
}

void draw() {
  image(I, 0, 0);
}

void keyPressed() {
  if (key == '-') {
    ar--;
  } else if (key == '+') {
    ar++;
  }

  println("ar = " + ar);

  I = I_original.copy(); // ripartiamo sempre dall'originale
  I.loadPixels();

  for (int i = 0; i < I.pixels.length; i++) {
    color c1 = I.pixels[i];
    float r = constrain(red(c1) + ar, 0, 255);
    float g = constrain(green(c1), 0, 255);
    float b = constrain(blue(c1), 0, 255);
    I.pixels[i] = color(r, g, b);
  }

  // Ridisegniamo la diagonale gialla
  for (int i = 0; i < I.width; i++) {
    I.pixels[pos(i, i, I.width)] = color(255, 255, 0);
  }

  I.updatePixels();
}

// Funzione per linearizzare coordinate (x, y) in indice 1D
int pos(int x, int y, int w) {
  return x + y * w;
}
