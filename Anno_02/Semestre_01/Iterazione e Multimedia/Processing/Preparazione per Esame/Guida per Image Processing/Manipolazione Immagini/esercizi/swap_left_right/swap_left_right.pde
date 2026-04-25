PImage originale;

PImage swap(PImage I) {
  PImage R = I.copy();
  int w = I.width;
  int h = I.height;

  PImage sinistra = I.get(0, 0, w/2, h);
  PImage destra = I.get(w/2, 0, w/2, h);

  R.set(0, 0, destra);
  R.set(w/2, 0, sinistra);

  return R;
}

void setup() {
  size(256, 256);
  originale = loadImage("lena.png");
  originale.resize(256, 256);
  originale = swap(originale);
  image(originale, 0, 0);
}
