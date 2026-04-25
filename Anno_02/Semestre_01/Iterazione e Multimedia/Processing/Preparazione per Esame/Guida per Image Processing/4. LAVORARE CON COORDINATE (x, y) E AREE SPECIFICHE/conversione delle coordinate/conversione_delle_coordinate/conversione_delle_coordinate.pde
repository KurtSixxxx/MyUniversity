/*
Passo 1: Passare dall'indice lineare alle coordinate
Finora facevamo:

for (int i = 0; i < pixels.length; i++) {
  // lavoriamo con i
}

Ora faremo:

for (int y = 0; y < altezza; y++) {
  for (int x = 0; x < larghezza; x++) {
    int i = x + y * larghezza;  // formula per trovare l'indice
    // lavoriamo con (x, y) e anche con i se serve
  }
}
*/

PImage operazioneSuCoordinate(PImage originale){
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = risultato.width;
  int h = risultato.height;
  
  for(int y = 0; y < h; y++){
    for(int x = 0; x < w; x++){
      int i = x * y + w; //Indice della matrice linearizzata
      
      color c = risultato.pixels[i];
      
      float r = red(c);
      float g = green(c);
      float b = blue(c);
      
    // QUI PUOI USARE x e y PER DECIDERE COSA FARE
      if (/* condizione basata su x e y */) {
        // modifica speciale per questa zona
      }  
      
      risultato.pixels[i] = color(r, g, b);
    }
  }
  
  risultato.updatePixels();
  return risultato;
}
