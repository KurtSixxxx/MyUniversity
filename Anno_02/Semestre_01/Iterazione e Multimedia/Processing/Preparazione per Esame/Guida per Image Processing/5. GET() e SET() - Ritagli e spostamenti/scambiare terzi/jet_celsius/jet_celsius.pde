PImage I1, I2;

// Input: [A][B][C]  (3 parti uguali)
// Output: [C][B][A]

PImage swap(PImage originale){
  PImage risultato = originale.copy();
  risultato.updatePixels();
  
  int w = originale.width;
  int h = originale.height;
  int w3 = w/3;
  
  // Prendo i 3 terzi
  PImage sinistro = originale.get(0,0, w3,h);
  PImage centrale = originale.get(w3,0, w3,h);
  PImage destro = originale.get(2*w3,0, w,h);
  
  // Riordino: destro, centrale, sinistro
  risultato.set(0,0,destro);
  risultato.set(w3,0,centrale);
  risultato.set(2*w3,0,sinistro);
  
  return risultato;
}

void setup(){
  size(512,512);
  I1 = loadImage("lena.png");
  I2 = swap(I1);
  
  image(I2, 0,0);
}
