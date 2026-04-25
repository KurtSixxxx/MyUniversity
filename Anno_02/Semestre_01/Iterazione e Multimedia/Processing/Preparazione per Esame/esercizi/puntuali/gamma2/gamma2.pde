PImage lena, lenaG;

PImage gamma(PImage I, float gm){
  PImage R = I.copy();
  R.loadPixels();
  
  float r,g,b;
  float c = 1/pow(255,gm-1);
  
  for(int i = 0; i < R.pixels.length; i++){
    r = c * pow(red(R.pixels[i]),gm);
    g = c * pow(green(R.pixels[i]),gm);
    b = c * pow(blue(R.pixels[i]),gm);
    
    R.pixels[i] = color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(1024,512);
  float gm = 0.3;
  lena = loadImage("lena.png");
  lenaG = gamma(lena, gm);
  image(lena,0,0);
  image(lenaG,512,0);
}
