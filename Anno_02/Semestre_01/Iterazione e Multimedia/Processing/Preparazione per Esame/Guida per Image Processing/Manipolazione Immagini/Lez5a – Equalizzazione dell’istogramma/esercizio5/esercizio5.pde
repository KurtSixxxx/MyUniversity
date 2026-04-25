/*
PImage lena, lenaEQ;

//Funzione di istogramma che conta il numero di pixel di un livello di luminosità
int[] istogrammaConteggi(PImage I) {
  I.loadPixels();

  int[] H = new int[256];

  for (int i = 0; i < I.pixels.length; i++) {
    int valore = int(brightness(I.pixels[i]));
    H[valore]++;
  }

  return H;
}

//Funzione di istogramma cumulativo
int[] istogrammaCumulativo(PImage I) {
  int[] H = istogrammaConteggi(I);
  int[] cumulativo = new int[H.length];

  cumulativo[0] = H[0];

  for (int i = 1; i < H.length; i++) {
    cumulativo[i] = cumulativo[i-1] + H[i];
  }

  return cumulativo;
}

int[] creaLUT(PImage I) {
  int[] cumulativo = istogrammaCumulativo(I);
  int totalePixel = I.width * I.height;
  int[] lut = new int[256];

  for (int i = 0; i < 256; i++) {
    lut[i] = int(255.0 * cumulativo[i] / totalePixel);
  }

  return lut;
}

PImage equalizza(PImage I) {
  PImage ImageEQ = I.copy();
  ImageEQ.filter(GRAY);
  ImageEQ.loadPixels();
  int[] mappa = creaLUT(ImageEQ);
  for (int i = 0; i < ImageEQ.pixels.length; i++) {
    int luminosità = int(brightness(ImageEQ.pixels[i]));
    int nuovoValore = mappa[luminosità];
    ImageEQ.pixels[i] = color(nuovoValore);
  }
  ImageEQ.updatePixels();
  return ImageEQ;
}

void setup() {
  size(768, 256);
  lena = loadImage("lena.png");
  lena.resize(256, 256);
  lenaEQ = equalizza(lena);
  image(lena, 0, 0);
  image(lenaEQ, 256, 0);
}

*/
