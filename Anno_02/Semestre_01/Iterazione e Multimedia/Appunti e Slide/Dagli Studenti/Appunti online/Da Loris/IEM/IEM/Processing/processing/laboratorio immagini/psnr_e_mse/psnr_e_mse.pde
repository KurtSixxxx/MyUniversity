PImage Im, Ic, Ir;
float mseO, mseP, mseR, psnrO, psnrP, psnrR;

void setup() {
  size(1536, 512);
  background(0);

  // Carica immagine in scala di grigi
  Im = loadImage("lena.png");
  Im.filter(GRAY);

  // Ingrandimento con resize (interpolato)
  Ic = Im.copy();
  Ic.resize(256, 256);
  Ic.resize(512, 512);

  // Ingrandimento con replicazione pixel (nearest neighbor)
  Ir = Im.copy();
  Ir.resize(256, 256);
  Ir = replication2x(Ir);

  // Visualizzazione
  image(Im, 0, 0);
  image(Ic, 512, 0);
  image(Ir, 1024, 0);

  // Calcolo MSE e PSNR
  mseO = MSE(Im, Im);
  mseP = MSE(Im, Ic);
  mseR = MSE(Im, Ir);

  psnrO = PSNR(Im, Im);
  psnrP = PSNR(Im, Ic);
  psnrR = PSNR(Im, Ir);

  // Output
  println("MSE con se stessa:     " + mseO);
  println("MSE resize Processing: " + mseP);
  println("MSE replicazione:      " + mseR);
  println("PSNR con se stessa:     " + psnrO);
  println("PSNR resize Processing: " + psnrP);
  println("PSNR replicazione:      " + psnrR);
}

void draw() {
  // Niente da fare qui
}

// ✅ Algoritmo di upscaling per replicazione pixel 2x
PImage replication2x(PImage I) {
  PImage R = createImage(2 * I.width, 2 * I.height, RGB);
  I.loadPixels();
  R.loadPixels();

  for (int y = 0; y < I.height; y++) {
    for (int x = 0; x < I.width; x++) {
      color c = I.get(x, y);
      int x2 = x * 2;
      int y2 = y * 2;
      R.set(x2,     y2,     c);
      R.set(x2 + 1, y2,     c);
      R.set(x2,     y2 + 1, c);
      R.set(x2 + 1, y2 + 1, c);
    }
  }

  R.updatePixels();
  return R;
}

// ✅ Calcolo MSE (errore quadratico medio)
float MSE(PImage I1, PImage I2) {
  if (I1.width != I2.width || I1.height != I2.height) {
    println("Errore: immagini di dimensioni diverse");
    return -1;
  }

  I1.loadPixels();
  I2.loadPixels();
  float sum = 0;

  for (int i = 0; i < I1.pixels.length; i++) {
    float d = blue(I1.pixels[i]) - blue(I2.pixels[i]);
    sum += d * d;
  }

  return sum / I1.pixels.length;
}

// ✅ Calcolo PSNR (rapporto segnale-rumore)
float PSNR(PImage I1, PImage I2) {
  float mse = MSE(I1, I2);
  if (mse <= 0) return Float.POSITIVE_INFINITY;
  return 10 * log10((255 * 255) / mse);
}

// ✅ Logaritmo in base 10
float log10(float x) {
  return log(x) / log(10);
}
