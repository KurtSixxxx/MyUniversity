PImage lena, lenaLog;

PImage logFilter(PImage I){
  PImage R = I.copy();
  R.loadPixels();
  
  float C = 255/log(256);
  
  for(int i = 0; i < R.pixels.length; i++){
    float r = C * log(1 + red(R.pixels[i])); 
    float g = C * log(1 + green(R.pixels[i]));
    float b = C * log(1 + blue(R.pixels[i]));
    
    R.pixels[i] = color(r,g,b);
  }
  R.updatePixels();
  return R;
}

void setup() {
  size(1024, 512);
  lena = loadImage("lena.png");
  lenaLog = logFilter(lena);
}

void draw() {
  image(lena, 0, 0);
  image(lenaLog, 512, 0);
}
