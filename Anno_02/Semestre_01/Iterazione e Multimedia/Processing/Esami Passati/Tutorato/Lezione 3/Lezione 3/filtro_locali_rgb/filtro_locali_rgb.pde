PImage I, I1, I2, I3, I4;
int N = 1;

void setup(){
  size(512,512);
  I = loadImage("lena.jpg");
  I.resize(256, 256);
}

void draw(){
  I1=minimo(I,N);
  I2=massimo(I,N);
  I3=mediano(I,N);
  I4=stretching(I);
  image(I4,0,0);
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
  float[] tmpR,tmpG,tmpB;
  
  tmpR=new float[N*N];
  tmpG=new float[N*N];
  tmpB=new float[N*N];
  
  for(int x=0; x<I.width; x++){
     for(int y=0;y<I.height; y++){
       tmp=I.get(x-off,y-off,N,N);
       
       tmp.loadPixels();
       
       for(int i=0; i<tmp.pixels.length;i++){
         tmpR[i]=red(tmp.pixels[i]);
         tmpG[i]=green(tmp.pixels[i]);
         tmpB[i]=blue(tmp.pixels[i]);
       }
         
       R.set(x,y,color(min(tmpR),min(tmpG),min(tmpB)));
     }
  }
  return R;
}

PImage massimo(PImage I, int N){
  PImage R=createImage(I.width, I.height, RGB);
  PImage tmp;
  int off=N/2;
  float[] tmpR,tmpG,tmpB;
  
  tmpR=new float[N*N];
  tmpG=new float[N*N];
  tmpB=new float[N*N];
  
  for(int x=0; x<I.width; x++){
     for(int y=0;y<I.height; y++){
       tmp=I.get(x-off,y-off,N,N);
       
       tmp.loadPixels();
       
       for(int i=0; i<tmp.pixels.length;i++){
         tmpR[i]=red(tmp.pixels[i]);
         tmpG[i]=green(tmp.pixels[i]);
         tmpB[i]=blue(tmp.pixels[i]);
       }
         
       R.set(x,y,color(max(tmpR),max(tmpG),max(tmpB)));
     }
  }
  return R;
}


PImage mediano(PImage I, int N){
  PImage R=createImage(I.width, I.height, RGB);
  PImage tmp;
  int off=N/2;
  float medR,medG,medB;
  float[] tmpR,tmpG,tmpB;
  
  tmpR=new float[N*N];
  tmpG=new float[N*N];
  tmpB=new float[N*N];
  
  for(int x=0; x<I.width; x++){
     for(int y=0;y<I.height; y++){
       tmp=I.get(x-off,y-off,N,N);
       
       tmp.loadPixels();
       
       for(int i=0; i<tmp.pixels.length;i++){
         tmpR[i]=red(tmp.pixels[i]);
         tmpG[i]=green(tmp.pixels[i]);
         tmpB[i]=blue(tmp.pixels[i]);
       }
         
       tmpR = sort(tmpR);
       tmpG = sort(tmpG);
       tmpB = sort(tmpB);
       
       if((N*N)%2==1){
         medR=tmpR[(N*N)/2];
         medG=tmpG[(N*N)/2];
         medB=tmpB[(N*N)/2];
       }
       else{
         medR=(tmpR[(N*N)/2]+tmpR[(N*N)/2-1])/2;
         medG=(tmpG[(N*N)/2]+tmpG[(N*N)/2-1])/2;
         medB=(tmpB[(N*N)/2]+tmpB[(N*N)/2-1])/2;
       }
         
       R.set(x,y,color(medR,medG,medB));
     }
  }
  return R;
}

PImage media(PImage I, int N){
  PImage R = createImage(I.width, I.height, RGB);
  PImage tmp;
  int off=N/2;
  float avgR,avgG,avgB;
  
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      avgR=0;
      avgG=0;
      avgB=0;
      tmp = I.get(x-off, y-off, N, N);
      for(int i=0; i<tmp.pixels.length; i++){
        avgR+=red(tmp.pixels[i]);
        avgG+=green(tmp.pixels[i]);
        avgB+=blue(tmp.pixels[i]);
      }
      avgR=avgR/(N*N);
      avgG=avgG/(N*N);
      avgB=avgB/(N*N);
      R.set(x,y,color(avgR,avgG,avgB));
    }
  }
  return R;
}
