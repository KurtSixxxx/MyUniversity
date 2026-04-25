PImage equalizza(PImage I){
  PImage R = I.copy(); //Facciamo la copia dell'immagine
  float [] H = istogramma(I) //Carichiamo l'istogramma (con la funzione che abbiamo creato in precedenza)

  //Usiamo l'istogramma cumulativo, ogni posizione i diventa la somma di se stessa più le precedenti. Questo crea una funziione che va da 0 a 1.
  for(int i = 1; i < 256; i++){
    H[i] = H[i-1] + H[i];
  }
  
  R.loadPixels(); //Carichiamo in memoria i pixels dell'immagine
  for(int i = 0; i < R.pixels.length; i++){
    R.pixels[i] = color(255 * H[int(red(pixels[i]))]);
//Prende il colore originale del pixel, usa quel colore come indice dell'istogramma
//Moltiplica per 255 per riportarlo in scala di grigi
//Lo assegna al pixel
  }
  R.updatePixels(); // Applica le modifiche ai pixel dell'immagine R.
  return R; // Restituisce l'immagine equalizzata
}
