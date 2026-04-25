//esame 08-02-22
PImage I, Iw, Im;
int n;

void setup(){
  size(768, 256);
  I=loadImage("lena.png");
  I.filter(GRAY);
  Iw=wow(I);
  Im=mas(Iw, 3);
  image(I,0,0,256,256);
  image(Iw,256,0,256,256);
  image(Im, 512,0, 256, 256);
}

void draw(){
}

void keyPressed(){
  
  if(key=='r' || key=='R'){
    setup();
  }
}

PImage wow(PImage I){
  PImage R = createImage(I.width, I.height, RGB);
  PImage up = I.get(0,0,I.width, I.height/2);
  PImage down = I.get(0,I.height/2, I.width, I.height/2);
  R.set(0,0,down);
  R.set(0,I.height/2,up);
  /*for(int i=R.pixels.length/2+R.width/2; i<R.pixels.length; i+=R.width+1){
    R.pixels[i]=color(255);
  }*/
  
  for(int i=R.height/2; i<R.height; i++){
    R.set(i,i,color(255));
  }
  
  
  return R;
}

PImage mas(PImage I, int n){
  PImage R= createImage(I.width, I.height, RGB);
  PImage temp = createImage(n,n,RGB);
  float [] tempF= new float[n*n];
  int off = n/2;
  
  for (int x=0; x<R.width; x++){
    for(int y=0; y<R.height; y++){
      temp = I.get(x-off,y-off,n,n);
      for(int i=0; i<temp.pixels.length; i++){
        tempF[i] = red(temp.pixels[i]);
      }
      R.set(x,y,color(max(tempF)));
    }
  }
  return R;
}


//Media
/*PImage media(PImage I, int N){
  PImage R= createImage(I.width, I.height, RGB);
  PImage temp;
  int off=N/2;
  float somma;
  float media;
  float [] tempf = new float [N*N];
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      somma=0;
      temp= I.get(x-off, y-off, N, N);
      for(int i=0; i<temp.pixels.length; i++){
        tempf[i]=green(temp.pixels[i]);
      }
      for(int i=0; i<tempf.length; i++){
        somma+=tempf[i];
      }
      media=somma/tempf.length;
      R.set(x,y,color(media));
    }
  }
  
  return R;
}*/w
