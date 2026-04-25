PImage im, iq;
int k=2;
void setup(){
  size(1024, 512);
  im=loadImage("lena.png");
  im.filter(GRAY);
  image(im, 0,0);
  iq=quantizza(im, k);
  image(iq, width/2, 0);
}


void draw(){
}

PImage quantizza(PImage I, int k){
  PImage R=I.copy();
  R.loadPixels();
  int q;
  for(int i=0; i<R.pixels.length; i++){
    q=floor(red(R.pixels[i])*k/256);
    //q=int(float(q)/(k-1)*255);
    q=(int)lerp(0,255, float(q)/(k-1)); //meglio farlo con questo metodo
    R.pixels[i]=color(q);
  }
  R.updatePixels();
  return R;
}

void keyPressed(){
  if(key=='+' && k<256){
    k++;
  }
  if(key=='-' && k>2){
    k--;
  }
  println(k);
  image(quantizza(im, k), 512, 0);
}
