//La funzione di istogramma conta quanto spesso appare ogni livello di grigio (0-255)

float [] istogramma(PImage I){ //Gli passiamo come parametro l'immagine di cui vogliamo l'istogramma, che sarà un array
  float[] H = new float[256]; //Ovviamente creiamo un array che contenga tutti i 256 livelli di grigio
  for(int i = 0; i < 256; i++){ //Iteiamo su ogni livello di grigio
    H[i] = 0; //E per adesso lo impostiamo a 0
  }
  
  I.loadPixels(); //Carichiamo in memoria i pixels della nostra immaginr
  
  for(int i = 0; i < I.pixels.length; i++){ //Iteriamo sulla marice normalizzata
    H[int(red(I.pixels[i]))]++; //Contiamo quanti pixel ci sono per il livello di grigio i, facciamo il casting ad intero e lo aggiungiamo  all'array
  }
  
  //---Normalizzazione dell'Istogramma---
  for(int i = 0; i < 256; i++){ //Ora iteriamo di nuovo sull'array istogramma
   H[i] = H[i]/I.pixels.length; //Divisiamo ogni valore per il numero toale di pixel. Adesso H contiene la probabilità di che un pixel abbia quel colore.
  }
  
  return H;
}
