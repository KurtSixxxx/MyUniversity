PImage lena, lenaLogaritmo;

PImage logaritmo(PImage O){
  PImage R = O.copy();
  
  R.loadPixels();
  O.loadPixels();
  
  float r,g,b;
  
  // Costante per mappare il risultato nel range 0-255. log(1+255) è il valore massimo che possiamo ottenere
  float C = 255/log(256);
  
  for(int i = 0; i < R.pixels.length; i++){
    // La trasformazione logaritmica: s = c * log(1 + componente_colore).
    // Il "+1" evita log(0) che è infinito.
    r = C * log(1 + red(O.pixels[i]));
    g = C * log(1 + green(O.pixels[i]));
    b = C * log(1 + blue(O.pixels[i]));
    
    R.pixels[i] = color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(1024,512);
  lena = loadImage("lena.png");
  lenaLogaritmo = logaritmo(lena);
  image(lena, 0,0);
  image(lenaLogaritmo, 512,0);
}
