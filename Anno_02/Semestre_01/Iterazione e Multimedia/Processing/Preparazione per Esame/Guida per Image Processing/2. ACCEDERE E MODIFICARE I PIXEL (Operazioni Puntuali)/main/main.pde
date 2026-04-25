PImage Im;

//Funzione di tipo PImage che restituisce un'immagine modificata
PImage modificaImmagine(PImage originale){
  
  //REGOLA 1: Si lavora sempre su una copia
  PImage risultato = originale.copy();

  //REGOLA 2: Carica i pixel prima di modificarli
  risultato.loadPixels();
  
  //REGOLA 3: Cicla su tutti i pixel
  for(int i = 0; i < risultato.pixels.length; i++){
      color c = risultato.pixels[i];
     
     //Estrai i colori
      float r = red(c);        // componente rosso (0-255)
      float g = green(c);      // componente verde (0-255)
      float b = blue(c);       // componente blu (0-255)
      float luminosita = brightness(c);  //scala di grigi (0-255)
      
     //Adesso modifichiamo i colori
     risultato.pixels[i] = color(r,g,b);
  }
  
  //REGOLA 5: Aggiorna i pixel dopo le modifiche
  risultato.updatePixels();
  
  return risultato;
}

void setup(){
  size(512,512);
  Im = loadImage("lena.png");
  image(Im, 0, 0);
}
