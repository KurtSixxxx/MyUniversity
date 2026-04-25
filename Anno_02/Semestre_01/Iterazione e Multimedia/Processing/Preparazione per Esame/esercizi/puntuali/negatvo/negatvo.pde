PImage lena, lenaN;

PImage negativo(PImage I){ //Prende come parametro l'immagine di cui fare il negativo
  PImage R = I.copy(); //Copia l'immagine per non alterarne i pixel
  R.loadPixels(); //Carica in memoria i pixel
  
  float r,g,b; //Crea variabili di nuove componenti colore
  
  for(int i = 0; i < R.pixels.length; i++){ //Itera sulla matrice linearizzata dell'immagine
    r = 255 - red(R.pixels[i]); //Prende il red del pixel e vi sottrae 255
    g = 255 - green(R.pixels[i]); //Prende il green del pixel e vi sottrae 255
    b = 255 - blue(R.pixels[i]); //Prende il blue del pixel e vi sottrae 255
    
    R.pixels[i] = color(r,g,b); //Ad ogni pixel assegna il nuovo colore
  }
  
  R.updatePixels(); //Ricarica i pixel
  return R; //Ritorna l'immagine
}

void setup(){
  size(1024,512);
  lena = loadImage("lena.png");
  lenaN = negativo(lena);
  image(lena,0,0);
  image(lenaN,512,0);
}
