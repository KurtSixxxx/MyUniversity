PImage Im,ImN,ImG,ImL;

void setup(){
  
  Im=loadImage("lena.png");
  Im.resize(256,256);
  size(512,512);
  image(Im,0,0);
  
  ImN=negativo(Im);
  image(ImN,256,0);
  
  ImG=gamma(Im,2);
  image(ImG,0,256);
  
  ImL=logaritmo(Im);
  image(ImL,256,256);

}

void draw(){}

PImage negativo(PImage I)
{
  PImage R=I.copy();
  
  float r,g,b;
  R.loadPixels();
  
  for(int i=0; i<R.pixels.length; i++)
  {
    r=255-red(R.pixels[i]);
    g=255-green(R.pixels[i]);
    b=255-blue(R.pixels[i]);
    
    R.pixels[i]=color(r,g,b);
  }
  return R;
}

PImage gamma(PImage I, float gm)
{
  PImage R=createImage(I.width,I.height, RGB);
  
  R.loadPixels();
  I.loadPixels();
  float r,g,b;
  float c=1/pow(255,gm-1);
  
  for(int i=0; i<R.pixels.length; i++)
  {
  
    r=c*pow(red(I.pixels[i]),gm);
    g=c*pow(green(I.pixels[i]),gm);
    b=c*pow(blue(I.pixels[i]),gm);
    
    R.pixels[i]=color(r,g,b);
  }
  
  R.updatePixels();
  return R;
}

PImage logaritmo(PImage I)
{
  PImage R=I.copy();
  
  R.loadPixels();
  I.loadPixels();
  
  float r,g,b;
  float C=255/log(256);
  
  for(int i=0; i<R.pixels.length; i++)
  {
    r=C*log(1+red(I.pixels[i]));
    g=C*log(1+green(I.pixels[i]));
    b=C*log(1+blue(I.pixels[i]));
    
    R.pixels[i]=color(r,g,b);
  }
  
  R.updatePixels();
  
  return R;
}

/*PImage I;
float r,g,b=0;
color c;

void setup(){
  
  I=createImage(500,500,RGB);
  size(500,500);
  //I.loadPixels();
  for(int y=0; y<I.height; y++)
  {
    for(int x=0; x<I.width; x++)
    {
      r=lerp(0,255,float(x)/I.width);
      g=lerp(0,255,float(y)/I.height);
      c=color(r,g,b);
      //I.pixels[pos(x,y,I.width)]=c;
      I.set(x,y,c);
    }
  }
  
  //I.updatePixels();
  

}
void draw(){
  image(I,0,0);
}

int pos(int x, int y, int w)
{
  return x+y*w;
}*/


/*

matrice linearizzata

PImage I;
float r,g,b;
color c,c1;
int ar;

void setup(){
  I=loadImage("lena.png");
  size(512,512);
  ar=0;
  c=color(255,255,0);
  I.loadPixels();
  for(int i=0; i<I.width; i++)
  {
      I.pixels[pos(i,i,I.width)]=c;
  }
  I.updatePixels();
}

void draw(){
  image(I,0,0);
}

void keyPressed(){
  if(key=='r')
  {
    ar--;
  }
  else if(key=='R')
  {
    ar++;
  }
  
  I.loadPixels();
  println(I.pixels.length);
  for(int i=0; i<I.pixels.length; i++)
  {
    c1=I.pixels[i];
    c1=color(red(c1)+ar, green(c1), blue(c1));
    I.pixels[i]=c1;
    
  }
  I.updatePixels();
  println(ar);

}

int pos(int x, int y, int w)
{
  return x+y*w;
}
*/

/*

estrazione colore da lena.png
PImage H;
color c;
int x,y;

void setup(){

  size(500,500);
  H=loadImage("lena.png");
  H.resize(200,200);
  c=color(0);
  x=width/2-H.width/2;
  y=height/2-H.height/2;
  
}

void draw(){
  background(c);
  c=H.get(mouseX-x,mouseY-y);
  println(mouseX-x);
  image(H,x,y);

}*/



/*
PImage I;
String url="https://media.laregione.ch/files/domains/laregione.ch/images/4by1/s_-homer-quando-va-essere-quel-pdcb.jpg";
int g=0;

void settings(){

  I=loadImage(url);
  I.resize(int(I.width/4.5),int(I.height/4.5));
  size(500,500);

} 

void draw(){
  background(0);
    image(I,0,0);
}

void keyTyped(){
  
  if(key=='+')
  {
    g++;
    I.filter(BLUR,g);
    println("Blur:"+g);
  }

}*/


/*
subImage

PImage I, subI;
String url;


void setup(){
  size(432,432);
  url="https://media.laregione.ch/files/domains/laregione.ch/images/4by1/s_-homer-quando-va-essere-quel-pdcb.jpg";
  I=loadImage(url);
  I.resize(int(I.width/2.5),int(I.height/2.5));
  subI=I.get(I.width/2,I.height/2,150,150);
  I.filter(GRAY);
  image(I,0,0);
  image(subI,width/2,height/2);
  subI.save("HomerPorzione.png");
  saveFrame("disegno.png");
}



void draw(){}
*/

/*PImage im;

void setup(){
  size(600,600);
  im=loadImage("lena.png");
  println("Larghezza: "+im.width);
  println("Altezza: "+im.height);
}

void draw(){
    background(0);
    image(im,0,0);
}

void mousePressed(){
  im.resize(im.width/2,im.height/2);
}

void keyTyped(){
  if(key=='s' || key=='S')
  {
    println(savePath("lenaPiccola.png"));
    im.save(savePath("out/lenaPiccola.png"));
  }
  
  if(key=='c' || key=='C')
  {
    println("Salvo la canvas...");
    saveFrame("lenaCanvas.png");
  }
}*/
