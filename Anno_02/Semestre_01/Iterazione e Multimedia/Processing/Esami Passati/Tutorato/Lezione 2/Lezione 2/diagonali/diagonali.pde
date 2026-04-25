PImage I, I1, I2, I3, I4;
int N = 5;

void setup(){
  size(512,512);
  I = loadImage("lena.jpg");
  I.resize(256, 256);
}

void draw(){
  I1=diag(I);
  I2=diag_inv(I);
  I3=diag_p(I);
  I4=diag_inv_p(I);
  image(I1,0,0);
  image(I2,256,0);
  image(I3,0,256);
  image(I4,256,256);
}

PImage diag(PImage I){
  PImage R=createImage(I.width, I.height, RGB);
  R = I.copy();
  color c = color(0,255,255);
  for(int i=0; i<I.width; i++)
    R.set(i,i,c);
  return R;
}

PImage diag_inv(PImage I){
  PImage R=createImage(I.width, I.height, RGB);
  R = I.copy();
  color c = color(0,255,255);
  for(int i=0; i<I.width; i++)
    R.set(I.width-1-i,i,c);
  return R;
}

PImage diag_p(PImage I){
  PImage R=createImage(I.width, I.height, RGB);
  R = I.copy();
  color c = color(255,0,255);
  for(int i=0; i<R.pixels.length; i+=(I.width+1))
    R.pixels[i]=c;
  return R;
}

PImage diag_inv_p(PImage I){
  PImage R=createImage(I.width, I.height, RGB);
  R = I.copy();
  color c = color(255,0,255);
  for(int i=I.width-1; i<R.pixels.length; i+=(I.width-1))
    R.pixels[i]=c;
  return R;
}
