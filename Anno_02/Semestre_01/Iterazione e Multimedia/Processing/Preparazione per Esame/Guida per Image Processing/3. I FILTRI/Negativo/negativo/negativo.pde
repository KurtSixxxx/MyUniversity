//Il negativo si ottiene sottraendo da 255 ogni componente

PImage ImOriginale, ImNegativa;

//Creiamo la funzione per il negativo
PImage negativo(PImage originale){
  PImage risultato = originale.copy(); //Facciamo come sempre la copia
  risultato.loadPixels();  //Carichiamo in pixel dell'immagine di input in quella di output
  
  for(int i = 0; i < risultato.pixels.length; i++){ //Iteriamo su tutti i pixel e preleviamo le componenti colori
    color c = risultato.pixels[i];
    
    //Per ogni componente sottraiamo 255
    float r = 255 - red(c);
    float g = 255 - green(c);
    float b = 255 - blue(c);
    
    risultato.pixels[i] = color(r, g, b); //aggiorniamo ogni componente colore del pixel
  }
    risultato.updatePixels(); //facciamo l'update dei pixel
    
    return risultato; //e ovviamente ritorniamo il risultato
}

void setup(){
  size(512, 256);
  
  ImOriginale = loadImage("lena.png");
  ImOriginale.resize(256,256);
  
  ImNegativa = negativo(ImOriginale); //chiamiamo la funione
 
  ImNegativa.resize(256,256);
  
  image(ImOriginale, 0,0);
  image(ImNegativa, 256,0);
}
