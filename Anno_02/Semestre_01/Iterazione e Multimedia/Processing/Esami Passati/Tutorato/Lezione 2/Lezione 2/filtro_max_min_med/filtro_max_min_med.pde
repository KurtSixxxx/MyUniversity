PImage I, I1, I2, I3;
int N = 5;

void setup(){
  size(512,512);
  I = loadImage("lena.jpg");
  I.resize(256, 256);
}

void draw(){
  I1=minimo(I,N);
  I2=massimo(I,N);
  I3=mediano(I,N);
  image(I,0,0);
  image(I1,256,0);
  image(I2,0,256);
  image(I3,256,256);
}

void keyPressed(){
  if(key=='+' && N<=15)
    N++;
  if(key=='-' && N>=5)
    N--;
}

PImage minimo(PImage I, int N){
  PImage R=createImage(I.width, I.height, RGB);
  PImage tmp;
  int off=N/2;
  float[] tmpF;
  
  tmpF=new float[N*N];
  
  for(int x=0; x<I.width; x++){
     for(int y=0;y<I.height; y++){
       tmp=I.get(x-off,y-off,N,N);
       
       tmp.loadPixels();
       
       for(int i=0; i<tmp.pixels.length;i++)
         tmpF[i]=green(tmp.pixels[i]);
         
       R.set(x,y,color(min(tmpF)));
     }
  }
  return R;
}

PImage massimo(PImage I, int N){
  PImage R=createImage(I.width, I.height, RGB);
  PImage tmp;
  int off=N/2;
  float[] tmpF;
  
  tmpF=new float[N*N];
  
  for(int x=0; x<I.width; x++){
     for(int y=0;y<I.height; y++){
       tmp=I.get(x-off,y-off,N,N);
       
       tmp.loadPixels();
       
       for(int i=0; i<tmp.pixels.length;i++)
         tmpF[i]=green(tmp.pixels[i]);
         
       R.set(x,y,color(max(tmpF)));
     }
  }
  return R;
}


PImage mediano(PImage I, int N){
  PImage R=createImage(I.width, I.height, RGB);
  PImage tmp;
  int off=N/2;
  float[] tmpF;
  float med;
  tmpF=new float[N*N];
  
  for(int x=0; x<I.width; x++){
     for(int y=0;y<I.height; y++){
       tmp=I.get(x-off,y-off,N,N);
       
       tmp.loadPixels();
       
       for(int i=0; i<tmp.pixels.length;i++)
         tmpF[i]=green(tmp.pixels[i]);
         
       tmpF = sort(tmpF);
       
       if((N*N)%2==1)
         med=tmpF[(N*N)/2];
       else
         med=(tmpF[(N*N)/2]+tmpF[(N*N)/2-1])/2;
         
       R.set(x,y,color(med));
     }
  }
  return R;
}
