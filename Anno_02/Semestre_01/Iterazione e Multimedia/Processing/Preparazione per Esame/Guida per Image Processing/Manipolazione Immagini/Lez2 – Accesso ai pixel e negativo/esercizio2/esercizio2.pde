PImage lena, lenaNeg;

PImage negativo(PImage originale){
  PImage R = originale.copy();
  R.loadPixels();
  
  float r, g, b;
  for(int i = 0; i < R.pixels.length; i++){
    r = 255 - red(R.pixels[i]);
    g = 255 - green(R.pixels[i]); 
    b = 255 - blue(R.pixels[i]); 
    
    R.pixels[i] = color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(768,256);
  lena = loadImage("lena.png");
  lenaNeg = negativo(lena);
  lena.resize(256,256);
  lenaNeg.resize(256,256);
  image(lena, 0,0);
  image(lenaNeg, 256,0);
}
