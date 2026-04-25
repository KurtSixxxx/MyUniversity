PImage I1, I2;

PImage swapRotation(PImage originale){
  PImage risultato = originale.copy();
  risultato.loadPixels();
  
  int w = originale.width;
  int h = originale.height;
  int w2 = w/2;
  int h2 = h/2;
  
  PImage q1 = originale.get(0,0, w2,h2); //A
  PImage q2 = originale.get(w2,0, w,h2); //B
  PImage q3 = originale.get(0,h2, w,h2); //C
  PImage q4 = originale.get(w2,h2, w,h); //D

  risultato.set(0,0, q4);
  risultato.set(w2,0, q3);
  risultato.set(0,h2, q2);
  risultato.set(w2,h2, q1);
  
  return risultato;
}

void setup(){
  size(1024, 512);
  I1 = loadImage("lena.png");
  I2 = swapRotation(I1);
  
  image(I1, 0,0);
  image(I2, 512,0);
}
