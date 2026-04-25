PImage lena, lenaBitplane;
int bit = 0;

PImage bitPlane(PImage I, int bit){
  PImage R = I.copy();
  R.loadPixels();
  
  int x; // Valore del pixel
  int r; // Bit estratto (0 o 1)
  
  for(int i = 0; i < R.pixels.length; i++){
    x = int(red(R.pixels[i]));
    r = (x >> bit) & 1;
    
    R.pixels[i] = color(255 * r);
  }
  
  R.updatePixels();
  return R;
}

void setup() {
  size(1024, 512);
  lena = loadImage("lena.png");
  lenaBitplane = bitPlane(lena, bit);
}

void draw() {
  image(lena, 0, 0);
  image(lenaBitplane, 512, 0);
}

void keyPressed(){
 if(key == '+'){
    bit++;
    bit = constrain(bit, 0, 7);
    lenaBitplane = bitPlane(lena, bit);
 }
 if(key == '-'){
   bit--;
   bit = constrain(bit, 0, 7);
   lenaBitplane = bitPlane(lena, bit);
 }
}
