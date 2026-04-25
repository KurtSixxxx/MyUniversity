//Il mediano prende il valore centrale dopo aver ordinato tutti i vicini.

PImage filtroMedianoConGet(PImage originale, int N) {
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int raggio = N/2;
  
  for (int y = raggio; y < originale.height - raggio; y++) {
    for (int x = raggio; x < originale.width - raggio; x++) {
      
      // Prendo l'intorno con get()
      PImage intorno = originale.get(x - raggio, y - raggio, N, N);
      intorno.loadPixels();
      
      // Copio i valori in un array
      float[] valori = new float[N*N];
      for (int i = 0; i < intorno.pixels.length; i++) {
        valori[i] = brightness(intorno.pixels[i]);
      }
      
      // Ordino e prendo il mediano
      valori = sort(valori);
      float mediano = valori[valori.length/2];
      
      int pos = x + y * originale.width;
      risultato.pixels[pos] = color(mediano);
    }
  }
  
  risultato.updatePixels();
  return risultato;
}
