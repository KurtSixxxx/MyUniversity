//Filtro logaritmo
PImage lena, lenaL;

PImage logaritmo(PImage I){
  PImage R = I.copy();
  
  R.loadPixels();
  I.loadPixels();
  
  float r,g,b;
  //Costante C
  float C = 255/log(256);
  
  for(int i = 0; i < R.pixels.length; i++){
     // colore = c *log(1, componente colore);
     // +1 evita il log(0) = infinito
     r = C * log(1 + red(I.pixels[i]));
     g = C * log(1 + green(I.pixels[i])); 
     b = C * log(1 + blue(I.pixels[i]));
     
     R.pixels[i] = color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(1024,512);
  lena = loadImage("lena.png");
  lenaL = logaritmo(lena);
  image(lena,0,0);
  image(lenaL,512,0);
}
