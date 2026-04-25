PImage lena, lenaNegativo;

PImage negativo(PImage I){
  PImage R = I.copy();
  R.loadPixels();
  float r,g,b;
  
  for(int i = 0; i < R.pixels.length; i++){
    r = 255 - red(R.pixels[i]);
    g = 255 - green(R.pixels[i]);
    b = 255 - green(R.pixels[i]);
    
    R.pixels[i] = color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(1024, 512);
  lena = loadImage("lena.png");
  lenaNegativo = negativo(lena);
  image(lena, 0,0);
  image(lenaNegativo, 512,0);
}
