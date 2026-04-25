//Lo stretching "allarga" l'istogramma per occupare tutto il range disponibile, aumentando il contrasto.

PImage stretching(PImage I){
  PImage R = I.copy(); //Facciamo la copia dell'immagine originale
  
  float max, min; //Creiamo max e min per i valori dell'istogramma
  R.loadPixels(); //Carichiamo in memoria i pixels dell'immagine
  
  max = red(R.pixels[0]);  //Impostiamo sia min che max attualmente a 0
  min = red(R.pixels[0]);  
  
  for(int i = 0; i < R.pixels.length; i++){ //Iteriamo sull'immagine in ricerca di minimo e massimo
    if(red(R.pixels[i] < min){
      min = red(R.pixels[i]);
    }
    if(red(R.pixels[i] > max){
      max = red(R.pixels[i]);
  }
  
  //Formula stretching: 255 * (oldValue - min) / (max - min)
  for(int i = 0; i < R.pixels.length; i++){
    R.pixels[i] = color(255 * (red(R.pixels[i] - min)) / (max - min)); 
  }
  
  R.updatePixels();
  return R;
}
