PImage lena, lenaLog;

PImage quantizza(PImage I, int k){
  PImage R = I.copy();
  int q;
  
  for(int i = 0; i < R.pixels.length; i++){
    q = floor((blue(R.pixels[i]) * k) / 256);
    
    q = int((float(q) / (k - 1)) * 255);
  }
  
}

void setup(){
  size(1024,512);
  int k = 3;
  lena = loadImage("lena.png");
  lenaLog = logaritmo(lena, k);
  image(lena, 0,0);
  image(lenaLog, 512,0);
}
