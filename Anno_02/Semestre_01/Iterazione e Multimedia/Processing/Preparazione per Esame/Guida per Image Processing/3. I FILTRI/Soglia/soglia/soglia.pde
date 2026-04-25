PImage ImOriginale, ImModificata;

float controlloSoglia(float luminosita, float soglia){
  if(luminosita < soglia) return 0;
  else return 255;
}

PImage soglia(PImage originale, float valoreSoglia){ 
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  for(int i = 0; i < risultato.pixels.length; i++){
    color b = risultato.pixels[i];
    
    float luminosita = floor(brightness(b));
    luminosita = controlloSoglia(luminosita, valoreSoglia);
    
    risultato.pixels[i] = color(luminosita);
  }
    risultato.updatePixels();
    return risultato;
}

void setup(){
  size(512, 256);
  ImOriginale = loadImage("lena.png");
  ImOriginale.resize(256,256);
  
  ImModificata = soglia(ImOriginale, 160.0);
  ImModificata.resize(256,256);
  
  image(ImOriginale, 0,0);
  image(ImModificata, 256,0);
}
