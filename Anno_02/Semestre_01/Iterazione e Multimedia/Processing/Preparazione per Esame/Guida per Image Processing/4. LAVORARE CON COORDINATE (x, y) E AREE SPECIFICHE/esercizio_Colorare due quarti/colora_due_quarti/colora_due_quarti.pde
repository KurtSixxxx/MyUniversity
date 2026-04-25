PImage I1, I2;

PImage colora(PImage originale){
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = risultato.width;
  int h = risultato.height;
  
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      int i = x + y * w;
      color c = risultato.pixels[i];
      
      float r = red(c);
      float g = green(c);
      float b = blue(c);
      
      if(x >= w/2 && y <= h/2){
        risultato.pixels[i] = color(255,0,0);
      }else if(x <= w/2 && y <= h/2){
        risultato.pixels[i] = color(0,0,255);
      }
    }
  }
  risultato.updatePixels();
  return risultato;
}

void setup(){
  size(512, 256);
  I1 = loadImage("lena.png");
  I1.resize(256,256);
  
  I2 = colora(I1);
  I2.resize(256,256);
  
  image(I1, 0,0);
  image(I2, 256,0);
} 
