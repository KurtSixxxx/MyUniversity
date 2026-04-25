PImage Im, Ik;
int K;
void setup(){
  size(512,256);
  Im=loadImage("lena.png");
  K=100;
}

void draw(){
  Ik=rgbQuant(Im, K);
  image(Im,0,0);
  image(Ik,256,0);
  textSize(30);
  text(K, 25, 25);
}

PImage rgbQuant(PImage I, int k){
  PImage R=I.copy();
  R.loadPixels();
  int r,g,b;
  for(int i=0;i<R.pixels.length;i++){
    r=floor((red(R.pixels[i])*k)/256);
    g=floor((green(R.pixels[i])*k)/256);
    b=floor((blue(R.pixels[i])*k)/256);
    R.pixels[i]=color(r,g,b);
  }
  R.updatePixels();
  return R; 
}

void keyPressed(){
  if(key=='+' && K<256)
    K++;
  if(key=='-' && K>100)
    K--;
}
