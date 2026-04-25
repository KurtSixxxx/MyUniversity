PImage lena, lenaSoglia;
float valore = 128;

PImage soglia(PImage originale, float valore) {
  PImage R = originale.copy();
  R.loadPixels();
  //R.resize(256, 256); //Ridimensiono così itero direttamente su meno pixels.

  for (int i = 0; i < R.pixels.length; i++) {
    float luminosità = brightness(R.pixels[i]); 
    if (luminosità > valore) {
      R.pixels[i] = color(255);
    } else {
      R.pixels[i] = color(0);
    }
  }
  
  R.updatePixels();
  return R;
}

void setup() {
  size(768, 256);
  lena = loadImage("lena.png");
  lena.resize(256, 256);
  lenaSoglia = soglia(lena, valore); // calcolo inziale 
  image(lena, 0, 0);
  image(lenaSoglia, 256, 0);
}

void draw() {
  background(200);
  image(lena, 0, 0);
  image(lenaSoglia, 256, 0);
}

void keyPressed() {
  if (key == '+') {
    valore += 5;
    valore = constrain(valore, 0, 255);
    lenaSoglia = soglia(lena, valore);  // ricalcola solo quando serve
  }
  if (key == '-') {
    valore -= 5;
    valore = constrain(valore, 0, 255);
    lenaSoglia = soglia(lena, valore);
  }
}
