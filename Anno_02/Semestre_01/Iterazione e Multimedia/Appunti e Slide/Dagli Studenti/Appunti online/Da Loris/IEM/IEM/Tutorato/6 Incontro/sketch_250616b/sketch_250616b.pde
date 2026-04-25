PImage Im, I1, I2;
int h, k, n;

void setup(){
  size(768, 256);
  Im = loadImage("lena.png");
  Im.filter(GRAY);
  Im.resize(256, 256);
  image(Im, 0, 0);
  h = int(random(1, 256));
  k = int(random(1, 256));
  n = int(random(5, 15));
  I1 = linee(Im, h, k);
  image(I1, 256, 0);
  I2 = linee(Im, h, k, n);
  image(I2, 512, 0);
}

void draw(){}

PImage linee(PImage I, int h, int k){
  PImage R= I.copy();
  for(int i=0; i<I.width; i++){
    R.set(i,h,color(255));
    R.set(i,k,color(255));
    R.set(h,i,color(255));
    R.set(k,i,color(255));
  }
  
  for(int i=0; i<R.pixels.length; i+=R.width+1){
    R.pixels[i] = color(255);
  }
  
  /*for(int i=0; i<R.width; i++){
    R.set(i,i,color(255));
  }*/
  return R;
}

PImage linee(PImage I, int h, int k, int n){
  PImage R = createImage(I.width, I.height, RGB);
  PImage temp;
  float [] tempF = new float[n*n];
  int offset = n/2;
  float c;
  
  for(int x=0; x<R.width; x++){
    for(int y=0; y<R.height; y++){
      temp = I.get(x-offset, y-offset, n, n);
      for(int i=0; i<temp.pixels.length; i++){
        tempF[i] = red(temp.pixels[i]);
      }
      c = min(tempF);
      R.set(x,y,color (c));
    }
  }
  
  R = linee(R,h,k);
  return R;
}


void keyPressed(){
  if(key=='r' || key == 'R'){
    setup();
  }
}
