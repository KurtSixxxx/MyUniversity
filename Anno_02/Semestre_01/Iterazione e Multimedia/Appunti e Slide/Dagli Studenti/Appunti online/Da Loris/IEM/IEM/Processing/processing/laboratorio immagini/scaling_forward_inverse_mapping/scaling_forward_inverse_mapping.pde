PImage Im, Ir,Iri;
float scale=1;

void setup()
{
  Im=loadImage("lena.png");
  size(1025,512);
  Ir=scaleF(Im,scale,scale);
  Iri=scaleI(Im,scale,scale);
  //image(Im,0,0);
  image(Ir,0,0);
  image(Iri,512,0);
}

void draw(){}

PImage scaleF(PImage I, float cx, float cy)
{
  PImage R=I.copy();
  R.loadPixels();
  for(int i=0; i<R.pixels.length;i++)
  {
    R.pixels[i]=color(0);
  }
  
  float x,y;
  float v1,w1;
  
  for(int v=0; v<I.width;v++)
  {
    for(int w=0; w<I.height;w++)
    {
      v1=v-I.width/2;
      w1=w-I.height/2;
      
      x=v1*cx;
      y=w1*cy;
      
      x=x+I.width/2;
      y=y+I.height/2;
      
      R.set(round(x),round(y),I.get(v,w));
    }
  }
  
  R.updatePixels();
  
  return R;
}
PImage scaleI(PImage I, float cx, float cy)
{
  PImage R=I.copy();
  R.loadPixels();
  for(int i=0; i<R.pixels.length;i++)
  {
    R.pixels[i]=color(0);
  }
  
  float v,w;
  float x1,y1;
  
  for(int x=0; x<I.width;x++)
  {
    for(int y=0; y<I.height;y++)
    {
      x1=x-I.width/2;
      y1=y-I.height/2;
      
      v=x1*1/cx;
      w=y1*1/cy;
      
      v=v+I.width/2;
      w=w+I.height/2;
      
      R.set(x,y,I.get(round(v),round(w)));
      
    }
  }
  
  R.updatePixels();
    
  return R;
}


void keyPressed()
{
  if(key=='+')
  {
    scale+=.1;
  }
  
  if(key=='-')
  {
    scale-=.1;
  }
  
  println(scale);
  Ir=scaleF(Im,scale,scale);
  image(Ir,0,0);
  Iri=scaleI(Im,scale,scale);
  image(Iri,512,0);
}
