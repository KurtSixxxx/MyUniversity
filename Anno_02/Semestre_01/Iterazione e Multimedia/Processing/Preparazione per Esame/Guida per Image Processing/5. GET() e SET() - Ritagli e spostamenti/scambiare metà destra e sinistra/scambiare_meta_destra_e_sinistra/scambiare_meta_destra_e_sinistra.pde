PImage scambiaMetàOrizzontale(PImage originale) {
  PImage risultato = originale.copy();  // partiamo da una copia
  
  int w = originale.width;
  int h = originale.height;
  
  // Prendo la metà sinistra
  PImage sinistra = originale.get(0, 0, w/2, h);
  
  // Prendo la metà destra
  PImage destra = originale.get(w/2, 0, w/2, h);
  
  // Le incollo scambiate
  risultato.set(0, 0, destra);      // metà destra va a sinistra
  risultato.set(w/2, 0, sinistra);  // metà sinistra va a destra
  
  return risultato;
}
