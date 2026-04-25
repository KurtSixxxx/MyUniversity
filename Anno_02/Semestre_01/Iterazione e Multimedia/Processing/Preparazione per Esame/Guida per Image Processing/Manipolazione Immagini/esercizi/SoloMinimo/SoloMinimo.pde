PImage minimo(PImage I, int N) {
  PImage R = createImage(I.width, I.height, RGB);
  R.loadPixels();

  PImage tmp;
  int off = N/2;
  float[] tmpF;

  int xs;
  int ys;

  for (int y = 0; y < R.height; y++) {
    for (int x = 0; x < R.width; x++) {

      //Ci servono per costringere quel valore a stare dentro [0, larghezza-1] (o [0, altezza-1]). Ossia gestire i bordi.
      xs = x - off;
      ys = y - off;

      tmp = I.get(max(0, xs), max(0, ys), min(N, min(N + xs, R.width - xs)), min(N, min(N + ys, R.height - ys)));
      tmp.loadPixels();

      tmpF = new float[tmp.pixels.length];

      for (int i = 0; i < tmp.pixels.length; i++) {
        tmpF[i] = green(tmp.pixels[i]);
      }
      R.set(x, y, color(min(tmpF)));
    }
  }
  return R;
}
