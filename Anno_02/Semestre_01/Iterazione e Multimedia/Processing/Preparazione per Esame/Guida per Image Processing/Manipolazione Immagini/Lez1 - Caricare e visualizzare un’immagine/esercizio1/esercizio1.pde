PImage lena;

void setup(){
  size(768,256);
  lena = loadImage("lena.png");
  lena.resize(256,256);
}

void draw(){
  image(lena, 0, 0);
  image(lena, 256, 0);
}
