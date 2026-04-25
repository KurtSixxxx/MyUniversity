PImage Im, ImHash2, ImHash3;

PImage hash1(PImage I, int h, int k) {
  PImage O = I.copy();
  O.filter(GRAY);
  O.loadPixels();
  
  for(int y = 0; y < O.height; y++){
    for(int w = 0; w < O.width; w++){
      if(y == k || y == h || w == k || w == h){
          O.pixels[y] = color(0);
          O.pixels[w] = color(0);
        }
    }
  }
  O.updatePixels();
  return O;
}

void setup() {
  size(768, 256);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  Im.resize(256,256);
  ImHash2 = hash1(Im, 4, 8);
}

void draw(){
  background(255);
  image(Im, 0,0);
  image(ImHash2, 256, 0);
  //image(ImHash3, 512,0);
}

void reset() {
}

void keyPressed() {
  if(key == 'r' || key == 'R'){
    reset();
  }
}
