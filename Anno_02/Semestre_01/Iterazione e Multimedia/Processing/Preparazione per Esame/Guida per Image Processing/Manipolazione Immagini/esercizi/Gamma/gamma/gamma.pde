PImage lena, lenaGamma;
float gm = 2.2;

PImage gammaFilter(PImage I, float gm) {
  PImage R = I.copy();
  R.loadPixels();
  float c = 1 / pow(255, gm - 1);

  for (int i = 0; i < R.pixels.length; i++) {
    float r = c * pow(red(R.pixels[i]), gm);
    float g = c * pow(green(R.pixels[i]), gm);
    float b = c * pow(blue(R.pixels[i]), gm);

    R.pixels[i] = color(r, g, b);
  }
  R.updatePixels();
  return R;
}

void setup() {
  size(1024, 512);
  lena = loadImage("lena.png");
  lenaGamma = gammaFilter(lena, gm);
}

void draw() {
  image(lena, 0, 0);
  image(lenaGamma, 512, 0);
}

void keyPressed() {
  if (key == '+') {
    gm += 0.2;
    lenaGamma = gammaFilter(lena, gm);
  }
  if (key == '-') {
    gm -= 0.2;
    lenaGamma = gammaFilter(lena, gm);
  }
}
