PImage lena, lenaGamma;

PImage gamma(PImage O, float gm){ // Prende come parametri l'immagine a cui applicare il filtro ed il valore di gamma.
  PImage R = createImage(O.width, O.height, RGB); //Creiamo una immagine vuota in RGB con altezza e larghezza dell'Immagine in ingresso.
  
  // Carichiamo in memoria entrambi i pixel delle immagini.
  R.loadPixels();
  O.loadPixels();
  
  float r,g,b; // Creiamo delle variabili float per ogni componente colore
  
  float c = 1/pow(255,gm-1); // Questa è la costante di normalizzazione. 
  
  for(int i = 0; i < R.pixels.length; i++){ // Applico la formula di correzione gamma ad ogni canale.
    r = c * pow(red(O.pixels[i]),gm);
    g = c * pow(green(O.pixels[i]),gm);
    b = c * pow(blue(O.pixels[i]),gm);
    
    R.pixels[i] = color(r,g,b); // Ricostruisco il nuovo colore e lo assegno alla stessa posizione nell'array
  } 
  
  R.updatePixels();
  return R;
}

void setup(){
  size(1024,512);
  lena = loadImage("lena.png");
  
  float gm = 0.188;
  lenaGamma = gamma(lena, gm);
  image(lena,0,0);
  image(lenaGamma,512,0);
}
