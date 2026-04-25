PImage scambiaMetàVerticale(PImage originale) {
  PImage risultato = originale.copy();
  
  int w = originale.width;
  int h = originale.height;
  
  // Prendo la metà superiore
  PImage sopra = originale.get(0, 0, w, h/2);
  
  // Prendo la metà inferiore
  PImage sotto = originale.get(0, h/2, w, h/2);
  
  // Le incollo scambiate
  risultato.set(0, 0, sotto);      // metà inferiore va sopra
  risultato.set(0, h/2, sopra);    // metà superiore va sotto
  
  return risultato;
}
