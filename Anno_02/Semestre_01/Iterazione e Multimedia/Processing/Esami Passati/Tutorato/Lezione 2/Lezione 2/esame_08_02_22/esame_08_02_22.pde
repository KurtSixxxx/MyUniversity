PImage I,Iw,Im;
int n;

void setup(){
  size(768,256);
  I=loadImage("lena.jpg");
  I.filter(GRAY);
  I.resize(256,256);
  Iw=wow(I);
  Im=mas(Iw, 15);
  image(I,0,0);
  image(Iw,256,0);
  image(Im,512,0);
}

void draw(){}

void keyPressed(){
  if(key=='R' || key=='r')
    setup();
}

PImage wow(PImage I){
  PImage R = createImage(I.width, I.height, RGB);
  PImage up = I.get(0,0,I.width,I.height/2);
  PImage down = I.get(0,I.height/2,I.width,I.height/2);
  /*PImage white = createImage(5,5,RGB);
  for(int i=0; i<white.pixels.length; i++)
    white.pixels[i]=color(255);*/
  R.set(0,0,down);
  R.set(0,I.height/2,up);
  for(int i=R.pixels.length/2+R.width/2; i<R.pixels.length; i+=R.width+1)
    R.pixels[i]=color(255);
  /*for(int i=R.height/2; i<R.height; i++)
    R.set(i,i,white);*/
  return R;
}

PImage mas(PImage I, int n){
  PImage R = createImage(I.width, I.height, RGB);
  PImage tmp = createImage(n, n, RGB);
  float [] tmpF = new float[n*n];
  int off = n/2;
  
  for(int x=0; x<R.width; x++){
    for(int y=0; y<R.height; y++){
      tmp = I.get(x-off,y-off,n,n);
      for(int i=0; i<tmp.pixels.length; i++)
        tmpF[i]=red(tmp.pixels[i]);
      R.set(x,y,color(max(tmpF)));
    }
  }
  return R;
}
