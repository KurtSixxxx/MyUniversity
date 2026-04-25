PImage originale;

PImage coloraDiag(PImage I){
  PImage R = I.copy();
  R.loadPixels();
  
  int w = R.width;
  int h = R.height;

  for(int y = 0; y < h; y++){
    for(int x = 0; x < w; x++){
        int i = x + y * w;
        color c = R.pixels[i];
        
        float r = red(c);
        float g = green(c);
        float b = blue(c);
        
      if(y < x){
        r = 255;
      }else{ //(y > x)
        g = 255;
      }
        R.pixels[i] = color(r,g,b);
    }
  }
  
  R.updatePixels();
  return R;
}

void setup(){
  size(256,256);
  originale = loadImage("lena.png");
  originale.resize(256,256);
  originale = coloraDiag(originale);
  image(originale, 0, 0);
}
