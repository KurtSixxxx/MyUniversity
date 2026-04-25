//Colorare un quadrante di giallo

PImage Im, YellowIm;

PImage quadranteGiallo(PImage originale){
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = risultato.width;
  int h = risultato.height;
  
  for(int y = 0; y < h; y++){
    for(int x = 0; x < w; x++){
      int i = x + y * w;
      
      if(x <= w/2 && y <= h/2){
        risultato.pixels[i] = color(255,255,0);
      }
    }
  }
  
  risultato.updatePixels();
  
  return risultato; 
}

void setup(){
  size(512,256);
  Im = loadImage("lena.png");
  Im.resize(256,256);
  YellowIm = quadranteGiallo(Im);
  YellowIm.resize(256,256);
  image(Im, 0,0);
  image(YellowIm, 256,0);
}
