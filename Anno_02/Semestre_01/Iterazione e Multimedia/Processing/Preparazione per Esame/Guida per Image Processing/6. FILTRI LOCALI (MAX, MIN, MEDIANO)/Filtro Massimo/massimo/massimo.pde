//Il filtro massimo sostituisce ogni pixel con il valore MASSIMO dei suoi vicini.

PImage filtroMassimo(PImage originale, int N) {
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int raggio = N/2;
  
  for (int y = raggio; y < originale.height - raggio; y++) {
    for (int x = raggio; x < originale.width - raggio; x++) {
      
      // Estraggo l'intorno N×N
      PImage intorno = originale.get(x - raggio, y - raggio, N, N);
      intorno.loadPixels();
      
      // Cerco il massimo
      float maxVal = 0;
      for (int i = 0; i < intorno.pixels.length; i++) {
        float val = brightness(intorno.pixels[i]);
        if (val > maxVal) maxVal = val;
      }
      
      // Assegno il massimo al pixel centrale
      int pos = x + y * originale.width;
      risultato.pixels[pos] = color(maxVal);
    }
  }
  
  risultato.updatePixels();
  return risultato;
}
