PImage originale;

PImage coloraQuadranti(PImage I) {
  PImage R = I.copy();
  R.loadPixels();

  int w = I.width;
  int h = I.height;

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int i = x + y * w;

      if (x >= w/2 && y < h/2) {           // solo strettamente sopra
        R.pixels[i] = color(255, 255, 0);
      } else if (x < w/2 && y >= h/2) {    // solo strettamente a sinistra
        R.pixels[i] = color(0, 0, 255);
      }
    }
  }
  R.updatePixels();
  return R;
}

void setup() {
  size(256, 256);
  originale = loadImage("lena.png");
  originale.resize(256, 256);
  originale = coloraQuadranti(originale);
  image(originale, 0, 0);
}
