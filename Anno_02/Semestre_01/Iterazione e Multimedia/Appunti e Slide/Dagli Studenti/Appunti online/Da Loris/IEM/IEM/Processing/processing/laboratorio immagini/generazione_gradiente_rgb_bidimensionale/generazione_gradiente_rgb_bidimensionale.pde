PImage I;
color c;

void setup(){
  I = createImage(500, 500, RGB);
  size(500, 500);

  for (int y = 0; y < I.height; y++) {
    for (int x = 0; x < I.width; x++) {
      float r = lerp(0, 255, float(x) / I.width);
      float g = lerp(0, 255, float(y) / I.height);
      float b = 0;
      c = color(r, g, b);
      I.set(x, y, c);
    }
  }
  I.updatePixels();
}

void draw() {
  image(I, 0, 0);
}

int pos(int x,int y,int w){
  return x+y*w;
}
