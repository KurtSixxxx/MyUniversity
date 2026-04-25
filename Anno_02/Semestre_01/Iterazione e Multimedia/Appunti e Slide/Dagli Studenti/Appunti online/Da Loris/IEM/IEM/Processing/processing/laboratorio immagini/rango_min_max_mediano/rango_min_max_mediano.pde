PImage Im,Imax,Imin,Imed;

void setup()
{
  size(1024,1024);
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  Imax=massimo(Im,11);
  Imin=minimo(Im,11);
  Imed=mediano(Im,11);
  image(Im,0,0);
  image(Imax,512,0);
  image(Imin,0,512);
  image(Imed,512,512);
}
void draw()
{
}


PImage massimo(PImage I, int N)
{
  PImage R=createImage(I.width, I.height, RGB);
  
  PImage tmp;
  int off=N/2;
  float [] tmpF;
  
  tmpF=new float[N*N];
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0;y<I.height; y++)
    {
      tmp=I.get(x-off,y-off,N,N);
      tmp.loadPixels();
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=red(tmp.pixels[i]);
      }
      
      R.set(x,y,color(max(tmpF)));
    }
  }
  
  return R;
}

PImage minimo(PImage I, int N)
{
  PImage R=createImage(I.width, I.height, RGB);
  
  PImage tmp;
  int off=N/2;
  float [] tmpF;
  
  //tmpF=new float[N*N];
  int xs, ys;
 
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0;y<I.height; y++)
    {
      
       xs=x-off;
       ys=y-off;
   
   
      //tmp=I.get(x-off,y-off,N,N);
      tmp=I.get(max(0,xs),max(0,ys),min(N,min(N+xs,I.width-xs)),min(N,min(N+ys,I.height-ys)));
      tmp.loadPixels();
      
      tmpF=new float[tmp.pixels.length];
      
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=red(tmp.pixels[i]);
      }
      
      R.set(x,y,color(min(tmpF)));
    }
  }
  
  return R;
}

PImage mediano(PImage I, int N)
{
  PImage R=createImage(I.width, I.height, RGB);
  
  PImage tmp;
  int off=N/2;
  float [] tmpF;
  
  //tmpF=new float[N*N];
  int xs, ys;
  float med;
 
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0;y<I.height; y++)
    {
      
       xs=x-off;
       ys=y-off;
   
   
      //tmp=I.get(x-off,y-off,N,N);
      tmp=I.get(max(0,xs),max(0,ys),min(N,min(N+xs,I.width-xs)),min(N,min(N+ys,I.height-ys)));
      tmp.loadPixels();
      
      tmpF=new float[tmp.pixels.length];
      
      int s=tmp.pixels.length;
      
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=red(tmp.pixels[i]);
      }
      
      tmpF=sort(tmpF);
      
      if(s%2==1)
      {
        med=tmpF[s/2];
      }
      else
      {
        med=(tmpF[s/2]+tmpF[s/2-1])/2;
      }
  
      R.set(x,y,color(med));
    }
  }
  
  return R;
}
