// - 01.52.00 Iniziamo a studiare la quantizzazione in Processing

PImage Im, Iq;
int K = 2;

void setup(){
  size(1024,512);
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  image(Im, 0, 0);

  Iq = quantizza(Im, K);
  image(Iq,512,0);
}

void draw(){
}

PImage quantizza(PImage I, int k){
  PImage R = I.copy();
  R.loadPixels();
  int q;
  for(int i = 0; i < R.pixels.length; i++){
    q = floor(red(R.pixels[i])*k/256);
    //Un metodo uguale è: q = int(lerp(0,255,float(q)/(k-1)));
    q = int(float(q)/(k-1) * 255);
    R.pixels[i] = color(q);
  }
  R.updatePixels();
  return R;
}

void keyPressed(){
  if(key=='+' && K < 256){
    K++;
   }

   if(key=='-' && K > 2){
    K--;
   }

   println(K);
   image(quantizza(Im,K), 512, 0);
}
