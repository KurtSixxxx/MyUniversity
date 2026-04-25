void setup(){
  size(768, 256);
  PImage I = loadImage("lena.png");
  I.resize(256,256);
  image(I,0,0);
  PImage Iw = wow(I);
  Iw.resize(256,256);
  image(Iw, 256, 0);
  PImage Im = mas(Iw, 3);
  Im.resize(256,256);
  image(Im, 512, 0);
  filter(GRAY);
}

PImage wow(PImage I){
  PImage R = createImage(I.width, I.height, GRAY);
  PImage up = I.get(0, 0, I.width, I.height/2);
  PImage down = I.get(0, I.height/2, I.width, I.height);
  
  for(int i=0; i<up.pixels.length+1; i++){
    up.set(i,i,color(255));
  }
  
  R.set(0,0, down);
  R.set(0, I.height/2, up);
  return R;
}

PImage mas(PImage I, int n){
  PImage R = createImage(I.width, I.height, RGB);
  PImage temp = createImage(n,n,RGB);
  float [] tempF=new float [n*n];
  int offset= n/2;
  
  for(int x=0; x<R.width; x++){
    for(int y=0; y<R.height; y++){
      temp=I.get(x-offset,y-offset,n,n);
      for(int i=0; i<temp.pixels.length; i++){
        tempF[i] = red(temp.pixels[i]);
      }
      R.set(x,y,color(max(tempF)));
    }
  }
  
  return R;
}

void draw(){}

void keyPressed(){
  if(key=='r' || key=='R'){
    setup();
  }
}
