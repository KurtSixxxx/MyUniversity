PImage Im, Is, Ie;

void setup(){
  size(1536,812);
  background(0);
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  Is=stretching(Im);
  Ie=equalizza(Im);
  
  image(Im,0,0);
  image(Is,512,0);
  image(Ie,1024,0);
  
  float [] H1,H2,H3;
  H1=istogramma(Im);
  H2=istogramma(Is);
  H3=istogramma(Ie);
  
  rectMode(CORNERS);
  noStroke();
  fill(255,255,0);
  for (int i=0;i<256;i++)
  {
    rect(i*2,height-(H1[i]*256*100),i*2+2,height);
    rect(Im.width+i*2,height-(H2[i]*256*100),Im.width+i*2+2,height);
    rect(Im.width*2+i*2,height-(H3[i]*256*100),Im.width*2+i*2+2,height);
  }
}
void draw(){}

PImage stretching(PImage I)
{
  PImage R=I.copy();
  
  float max,min;
  R.loadPixels();
  
  max=red(R.pixels[0]);
  min=red(R.pixels[0]);
  
  for(int i=1; i<R.pixels.length; i++)
  {
    if(red(R.pixels[i])<min)
    min=red(R.pixels[i]);
    
    if(red(R.pixels[i])>max)
    max=red(R.pixels[i]);
  }
  
  for(int i=0; i<R.pixels.length; i++)
  {
    R.pixels[i]=color(255*(red(R.pixels[i])-min)/(max-min));
  }
  
  R.updatePixels();
  
  return R;
}


float [] istogramma(PImage I)
{
  float[] H=new float[256];
  for(int i=0; i<256; i++)
  {
    H[i]=0;
  }
  
  I.loadPixels();
  for(int i=0; i<I.pixels.length; i++)
  {
    H[int(red(I.pixels[i]))]++;
  }
  
  for(int i=0; i<256; i++)
  {
    H[i]=H[i]/I.pixels.length;
  }
  
  return  H;
  
}

PImage equalizza(PImage I)
{
  PImage R=I.copy();
  
  float [] H=istogramma(I);
  
  //Istogramma cumulativo
  for(int i=1; i<256; i++)
  H[i]=H[i-1]+H[i];
  
  
 R.loadPixels();
 
 for(int i=0; i<R.pixels.length; i++)
 {
   R.pixels[i]=color(255*H[int(red(R.pixels[i]))]);
 }
 
 R.updatePixels();
  
  return R;
}

/*

ZOOMING

PImage Im, Ic, Ir;
float mseO, mseP, mseR, psnrO, psnrP, psnrR;

void setup(){
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  size(1536,512);
  
  Ic=Im.copy();
  Ic.resize(256,256);
  Ic.resize(512,512);
  
  Ir=Im.copy();
  Ir.resize(256,256);
  Ir=replication2x(Ir);
  
  image(Im,0,0);
  image(Ic,512,0);
  image(Ir,1024,0);
  
  mseO=MSE(Im,Im);
  mseP=MSE(Im,Ic);
  mseR=MSE(Im,Ir);
  
  psnrO=PSNR(Im,Im);
  psnrP=PSNR(Im,Ic);
  psnrR=PSNR(Im,Ir);
  
  println("MSE con se stessa:"+mseO);
  println("MSE processing:"+mseP);
  println("MSE replication 2x:"+mseR);
  
  println("PSNR con se stessa:"+psnrO);
  println("PSNR processing:"+psnrP);
  println("PSNR replication 2x:"+psnrR);
  
}

void draw(){

}

PImage replication2x(PImage I)
{
  PImage R=createImage(2*I.width,2*I.height,RGB);
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
    {
      R.set(2*x,2*y,I.get(x,y));
      R.set(2*x+1,2*y,I.get(x,y));
      R.set(2*x,2*y+1,I.get(x,y));
      R.set(2*x+1,2*y+1,I.get(x,y));
    }
  }
  
  
  return R;
}

float MSE(PImage I1, PImage I2)
{
  float res=0;
  I1.loadPixels();
  I2.loadPixels();
  
  for(int i=0; i<I1.pixels.length; i++)
  {
    res+=pow(blue(I1.pixels[i])-blue(I2.pixels[i]),2);
  }
  res=res/I1.pixels.length;
  
  return res;
}


float PSNR(PImage I1, PImage I2)
{
  float res=0;
  float mse=MSE(I1,I2);
  
  res=10*log(255*255/mse)/log(10);
  
  return res;
  
}

float log10(int x)
{
  return (log(x)/log(10));
}

float log2(int x)
{
  return (log(x)/log(2));
}

*/


/*

QUANTIZZAZIONE

PImage Im, Iq;
int K;

void setup(){
  K=2;
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  size(1024,512);
  
  Iq=quantizza(Im,K);
  
  image(Im,0,0);
  image(Iq,512,0);
  
}

void draw(){}

PImage quantizza(PImage I, int k)
{
  PImage R=I.copy();
  R.loadPixels();
  
  int q;
  
  for(int i=0; i<R.pixels.length; i++)
  {
    q=floor((blue(R.pixels[i])*k)/256);
    
    q=int((float(q)/(k-1))*255);
    
    R.pixels[i]=color(q);
  }
  
  R.updatePixels();
  
  return R;
}


void keyPressed(){
  
  if((key=='+') && (K<256))
  {
    K++;
    image(quantizza(Im,K),512,0);
  }
  
  if((key=='-') && (K>2))
  {
    K--;
    image(quantizza(Im,K),512,0);
  }


}*/
