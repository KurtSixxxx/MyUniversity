PImage scambiaQuadratiDiagonalmente(PImage originale) {
  PImage risultato = originale.copy();
  
  int w = originale.width;
  int h = originale.height;
  int w2 = w/2;
  int h2 = h/2;
  
  // Prendo i 4 quadranti
  PImage q1 = originale.get(0, 0, w2, h2);        // alto sx
  PImage q2 = originale.get(w2, 0, w2, h2);       // alto dx
  PImage q3 = originale.get(0, h2, w2, h2);       // basso sx
  PImage q4 = originale.get(w2, h2, w2, h2);      // basso dx
  
  // Scambio in diagonale (1 con 4, 2 con 3)
  risultato.set(0, 0, q4);        // q4 va in alto sx
  risultato.set(w2, 0, q3);       // q3 va in alto dx
  risultato.set(0, h2, q2);       // q2 va in basso sx
  risultato.set(w2, h2, q1);      // q1 va in basso dx
  
  return risultato;
}
