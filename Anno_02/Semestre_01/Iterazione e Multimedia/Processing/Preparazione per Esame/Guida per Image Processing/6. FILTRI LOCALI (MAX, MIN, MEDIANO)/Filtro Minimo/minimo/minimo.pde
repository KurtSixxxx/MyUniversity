//Uguale al massimo, ma cerchi il minimo:

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
      // Dentro il ciclo...
      float minVal = 255;
      for (int i = 0; i < intorno.pixels.length; i++) {
        float val = brightness(intorno.pixels[i]);
        if (val < minVal) minVal = val;
      }
      risultato.pixels[pos] = color(minVal);
  }
  
  risultato.updatePixels();
  return risultato;
}
