float k = 0.5;
PImage I, I2, I3, I4;

void setup(){
  size(512, 512);
}

void draw(){
  I = loadImage("lena.png");
  I.resize(256,256);
  image(I, 0, 0);
  I2 = loadImage("fiore.jpg");
  I2.resize(256,256);
  image(I2, 256, 256);
  I3 = fusion(I, I2, k);
  image(I3, 256, 0);
  I4 = subtract(I, I2, k);
  image(I4, 0, 256);
}

PImage fusion(PImage I, PImage I2, float k){
  PImage R = createImage(I.width, I.height, RGB);
  R.loadPixels();
  I.loadPixels();
  I2.loadPixels();
  float r,g,b;
  for(int i=0; i<R.pixels.length; i++){
    color c1 = I.pixels[i];
    color c2 = I2.pixels[i];
    r = (k*(red(c1))+(1-k)*(red(c2)))/2;
    g = (k*(green(c1))+(1-k)*(green(c2)))/2;
    b = (k*(blue(c1))+(1-k)*(blue(c2)))/2;
    
    R.pixels[i] = color(r,g,b);
  }
  R.updatePixels();
  return R;
}

PImage subtract(PImage I, PImage I2, float k){
  PImage R = createImage(I.width, I.height, RGB);
  R.loadPixels();
  I.loadPixels();
  I2.loadPixels();
  float r,g,b;
  for(int i=0; i<R.pixels.length; i++){
    color c1 = I.pixels[i];
    color c2 = I2.pixels[i];
    r = (red(c1)-(k*red(c2)))/2;
    g = (green(c1)-(k*green(c2)))/2;
    b = (blue(c1)-(k*blue(c2)))/2;
    
    R.pixels[i] = color(r,g,b);
  }
  R.updatePixels();
  return R;
}

void keyPressed(){
  if(key == '+' && k <= 1){
    k+=0.05;
    println(k);
  }else if(key == '-' && k >= 0){
    k-=0.05;
    println(k);
  }
}
