PImage Im,Ib;
int K;
void setup()
{
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  size(1024,512);
  image(Im,0,0);
  K=7;
  Ib=bitplane(Im,K);
  image(Ib,512,0);
}

void draw()
{
}

PImage bitplane(PImage I, int nb)
{
  PImage R=I.copy();
  R.loadPixels();
  
  int x;
  int r;
  
  for(int i=0; i<R.pixels.length; i++)
  {
    x=int(blue(R.pixels[i]));
    r=(x>>nb)&1;
    
    R.pixels[i]=color(255*r);
  
  }
  
  R.updatePixels();
  return R;
}

void keyPressed(){
  if((key=='+') && (K<7))
  {
    Ib=bitplane(Im,++K);
    image(Ib,512,0);
  }
  
  if((key=='-') && (K>0))
  {
    Ib=bitplane(Im,--K);
    image(Ib,512,0);
  }
}

/*

RANGO

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
{}

PImage massimo(PImage I, int N)
{
  PImage R=createImage(I.width, I.height, RGB);
  PImage tmp;
  int off=N/2;
  float[] tmpF;
  
  tmpF= new float[N*N];
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
    {
      tmp=I.get(x-off,y-off,N,N);
      tmp.loadPixels();
      
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=green(tmp.pixels[i]);
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
  float[] tmpF;
  
  int xs;
  int ys;
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
    {
      
      xs=x-off;
      ys=y-off;
      
      //tmp=I.get(x-off,y-off,N,N);
      tmp=I.get(max(0,xs),max(0,ys),min(N,min(N+xs,I.width-xs)),min(N,min(N+ys,I.height-ys)));
      tmp.loadPixels();
      
      tmpF=new float[tmp.pixels.length];
      
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=green(tmp.pixels[i]);
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
  float[] tmpF;
  
  float med;
  
  int xs;
  int ys;
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
    {
      
      xs=x-off;
      ys=y-off;
      
      //tmp=I.get(x-off,y-off,N,N);
      tmp=I.get(max(0,xs),max(0,ys),min(N,min(N+xs,I.width-xs)),min(N,min(N+ys,I.height-ys)));
      tmp.loadPixels();
      
      tmpF=new float[tmp.pixels.length];
      
      for(int i=0; i<tmp.pixels.length; i++)
      {
        tmpF[i]=green(tmp.pixels[i]);
      }
      
      tmpF=sort(tmpF);
      int s=tmp.pixels.length;
      
      if(s%2==1)
      med=tmpF[s/2];
      else
      {
        med=(tmpF[s/2]+tmpF[s/2-1])/2;
      }
      
      
      R.set(x,y,color(med));
    }
  }
  
  
  return R;
}
*/

/*

CONVOLUZIONE

PImage Im, In3, In5, Il, Is, IsX;
//creo i kernel
float n3=1/9.0;
float[][] nbox3={{n3, n3, n3},
                  {n3, n3, n3},
                  {n3, n3, n3}};


float n5=1.0/25;
float[][] nbox5={{n5,n5,n5,n5,n5},
                  {n5,n5,n5,n5,n5},
                  {n5,n5,n5,n5,n5},
                  {n5,n5,n5,n5,n5},
                  {n5,n5,n5,n5,n5}};

float[][] lapl={ {-1,0,-1},
                  {0,4,0},
                  {-1,0,-1}};

float[][] sobX={ {-1,-2,-1},
                  {0,0,0},
                  {1,2,1}};
float[][] sharp={{-1,0,-1},
                  {0,5,0},
                  {-1,0,-1}};
float[][] random={{2,-2,-3},
                  {2,-1,0.5},
                  {-1,4,2}};


void setup(){

  size(1536,1024);
  Im=loadImage("lena.png");
  Im.filter(GRAY);
  //convoluzione su matrici e conversione in PImage
  In3=converti(convoluzione(Im,random));
  In5=converti(convoluzione(Im,nbox5));
  Il=converti(convoluzione(Im,lapl));
  Is=converti(convoluzione(Im,sharp));
  IsX=converti(convoluzione(Im,sobX));
  image(Im,0,0);
  image(In3,512,0);
  image(In5,1024,0);
  image(Il,0,512);
  image(Is,512,512);
  image(IsX,1024,512);
}

void draw(){}

float[][] convoluzione(PImage I, float[][] K)
{
  float[][] R=new float[I.height][I.width];
  
  //kernel MxN
  int M=K.length;
  int N=K[0].length;
  
  PImage tmp;
  float res;
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
    {
      tmp=I.get(x-N/2, y-M/2, N, M);
      res=0;
      
      for(int p=0; p<N; p++)
      {
        for(int q=0; q<M; q++)
        {
          res=res+green(tmp.get(p,q))*K[q][p];
        }
      }
      
      R[y][x]= res;
      
    
    }
  }
  
  return R;
  
}

PImage converti(float[][] F)
{
  PImage R=createImage(F[0].length,F.length,RGB);
  float res=0;
  for(int x=0; x<R.width; x++)
  {
    for(int y=0; y<R.height; y++)
    {
      res=constrain(F[y][x],0,255);
      R.set(x,y,color(res));
    }
  }
  
  return R;
}


*/

/*

SCALING

PImage Im, Ir,Iri;
float scale=1;;

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
  for(int i=0; i<R.pixels.length; i++)
  {
    R.pixels[i]=color(0);
  }
  
  float x,y;
  float v1,w1;
  
  for(int v=0; v<I.width; v++)
  {
    for(int w=0; w<I.height; w++)
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


PImage scaleI(PImage I,float cx, float cy)
{
  PImage R=I.copy();
  R.loadPixels();
  for(int i=0; i<R.pixels.length; i++)
  {
    R.pixels[i]=color(0);
  }
  
  float v,w;
  float x1,y1;
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
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


void keyPressed(){
  if(key=='+')
  {
    scale+=.1;
  }
  
  if(key=='-')
  {
    scale-=.1;
  }
  
  
  Ir=scaleF(Im,scale,scale);
  image(Ir,0,0);
  
  Iri=scaleI(Im,scale,scale);
  image(Iri,512,0);
}
*/


/*

ROTATE

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
  for(int i=0; i<R.pixels.length; i++)
  {
    R.pixels[i]=color(0);
  }
  
  float x,y;
  float v1,w1;
  
  for(int v=0; v<I.width; v++)
  {
    for(int w=0; w<I.height; w++)
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
  for(int i=0; i<R.pixels.length; i++)
  {
    R.pixels[i]=color(0);
  }
  
  float v,w;
  float x1,y1;
  
  for(int x=0; x<I.width; x++)
  {
    for(int y=0; y<I.height; y++)
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


void keyPressed(){
  if(key=='+')
  {
    ang+=5;
  }
  
  if(key=='-')
  {
    ang-=5;
  }
  
  ang=ang%360;
  
  Ir=rotateF(Im,radians(ang));
  image(Ir,0,0);
  
  Iri=rotateI(Im,radians(ang));
  image(Iri,512,0);
}*/
