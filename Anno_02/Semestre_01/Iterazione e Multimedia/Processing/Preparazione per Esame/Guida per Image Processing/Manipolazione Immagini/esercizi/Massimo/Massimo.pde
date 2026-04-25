//Filtro massimo
PImage lena, lenaMax;
int N = 5;

PImage maxFilter(PImage I, int N) {
  //PImage R = I.copy(); è equivalente
  PImage R = createImage(I.width, I.height, RGB); //Creiamo una immagine con le stesse dimensioni dell'originale.
  R.loadPixels();
  PImage tmp; //Creiamo tmp, sarà la finestra N*N
  int offset = N/2; //Così centriamo la finestra
  float[] tmpF = new float [N * N]; //Allochiamo un array per la finestra N X N

  //Iteriamo sull'immagine
  for (int y = 0; y < R.height; y++) {
    for (int x = 0; x < R.width; x++) {
      tmp = I.get(x - offset, y - offset, N, N); //Preleviamo la finestra che ci serve
      tmp.loadPixels();  //Carichiamo i pixel dell'intorno

      //Copia i valori di grigio nell'array tmpF
      for (int i = 0; i < tmp.pixels.length; i++) {
        tmpF[i] = red(tmp.pixels[i]);
      }
      //Calcola il massimo dell'array tmpF con max(), e assegna il colore corrispondente
      R.set(x, y, color(max(tmpF)));
    }
  }
  //Una volta fatto il lavoro su tutta l'immagine, restituisci R
  return R;
}

void setup() {
  size(1024, 512);
  lena = loadImage("lena.png");
  lenaMax = maxFilter(lena, N);
  image(lena, 0, 0);
  image(lenaMax, 512, 0);
}
