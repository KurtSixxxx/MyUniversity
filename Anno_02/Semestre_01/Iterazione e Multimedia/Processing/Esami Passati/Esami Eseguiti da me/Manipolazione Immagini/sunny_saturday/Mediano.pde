PImage filtroMediano(PImage originale, int N) {
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = originale.width;
  int h = originale.height;
  int raggio = N/2;
  
  for (int y = raggio; y < h - raggio; y++) {
    for (int x = raggio; x < w - raggio; x++) {
      
      // Array per i 9 valori
      float[] valori = new float[9];
      int idx = 0;
      
      // Raccogli i 9 valori
      for (int dy = -raggio; dy <= raggio; dy++) {
        for (int dx = -raggio; dx <= raggio; dx++) {
          int nx = x + dx;
          int ny = y + dy;
          int posVicino = nx + ny * w;
          valori[idx] = brightness(originale.pixels[posVicino]);
          idx++;
        }
      }
      
      // Ordina e prendi il mediano
      valori = sort(valori);
      float mediano = valori[4];  // per 3x3, il mediano è il 5° elemento, ovviamente qui è 4 perché si conta da zero.
      
      int posCentrale = x + y * w;
      risultato.pixels[posCentrale] = color(mediano);
    }
  }
  
  risultato.updatePixels();
  return risultato;
}
