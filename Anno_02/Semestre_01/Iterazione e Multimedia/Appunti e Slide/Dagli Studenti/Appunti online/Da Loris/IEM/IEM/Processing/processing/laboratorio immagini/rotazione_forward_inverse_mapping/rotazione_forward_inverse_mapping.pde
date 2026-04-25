PImage Im, Ir,Iri;
int ang=0;

void setup()
{
  Im=loadImage("lena.png");
  size(1025,512);
  Ir=rotateF(Im,radians(ang));
  Iri=rotateI(Im,radians(ang));
  //image(Im,0,0);
  image(Ir,0,0);
  image(Iri,512,0);
}

void draw(){}

PImage rotateF(PImage I, float theta)
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
      
      x=v1*cos(theta)-w1*sin(theta);
      y=v1*sin(theta)+w1*cos(theta);
      
      x=x+I.width/2;
      y=y+I.height/2;
      
      R.set(round(x),round(y),I.get(v,w));
    }
  }
  
  R.updatePixels();
  
  return R;
}
PImage rotateI(PImage I, float theta)
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
      
      v=x1*cos(theta)+y1*sin(theta);
      w=-x1*sin(theta)+y1*cos(theta);
      
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
    ang+=5;
  }
  
  if(key=='-')
  {
    ang-=5;
  }
  
  ang=ang%360;
  println(ang);
  Ir=rotateF(Im,radians(ang));
  image(Ir,0,0);
  Iri=rotateI(Im,radians(ang));
  image(Iri,512,0);
}
