PImage originale;

PImage swapTerzi(PImage I) {
  PImage R = I.copy();
  R.loadPixels();
  int w = I.width;
  int h = I.height;
  int terzo = w/3;

  PImage terzoSinistro = R.get(0, 0, terzo, h);
  PImage centro = R.get(terzo, 0, terzo, h);
  PImage terzoDestro = R.get(terzo*2, 0, terzo, h);

  //terzoDestro.set(0, 0, terzoSinistro);
  //terzoSinistro.set(w/3 * 2, 0, terzoDestro);

  R.set(0, 0, terzoDestro);
  R.set(terzo, 0, centro);
  R.set(2*terzo, 0, terzoSinistro);

  return R;
}

void setup() {
  size(256, 256);
  originale = loadImage("lena.png");
  originale.resize(256, 256);
  originale = swapTerzi(originale);
  image(originale, 0, 0);
}
