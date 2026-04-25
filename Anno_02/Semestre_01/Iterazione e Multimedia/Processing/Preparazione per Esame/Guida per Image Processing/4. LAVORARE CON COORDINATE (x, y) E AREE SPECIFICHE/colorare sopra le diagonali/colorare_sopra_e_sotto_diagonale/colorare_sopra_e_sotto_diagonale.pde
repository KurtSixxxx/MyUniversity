PImage originale, coloreDiagonale;

PImage colo(PImage originale){
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = risultato.width;
  int h = risultato.height;
  
  for(int y = 0; y < h; y++){
    for(int x = 0; x < w; x++){
      int i = x + y * w;
      color c = risultato.pixels[i];
      
      float r = red(c);
      float g = green(c);
      float b = blue(c);
      
      if(x > y){
        r = 255;
      }else if(x < y){
        b = 255;
      }
      
      risultato.pixels[i] = color(r, g, b);
    }
  }
  
  risultato.updatePixels();
  
  return risultato;
}

void setup(){
  size(512,256);
  originale = loadImage("lena.png");
  originale.resize(256,256);
  
  coloreDiagonale = colo(originale);
  coloreDiagonale.resize(256,256);
  
  image(originale, 0,0);
  image(coloreDiagonale, 256,0);
}
