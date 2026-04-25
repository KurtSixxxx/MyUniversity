PImage im, is, ie;
float[] H1,H2;
void setup(){
  im=loadImage("lena.png");
  im.filter(GRAY);
  size(1536,512);
  is=stretching(im);
  H1=istogramma(im);
  H2=istogramma(is);
  ie=equalizza(im);
  
  image(im,0,0);
  image(is,512,0);
  image(ie,1024,0);
  
  println(H1[0]);
  println(H2[0]);
}
