PImage J,G,B,T,B1;
int n=8;
boolean q=true;

void setup(){
  size(1500,500);
  J=loadImage("jojos.png");
  image(J,0,0,500,500);
  G=J.copy();
  B=J.copy();
  B.filter(GRAY);
  T=B.copy();
  G=imtoGray(G);
  image(G,500,0,500,500);
}

void draw(){
  B1=estraiPianoN(B,n);
  image(B1,1000,0,500,500);
  if(keyPressed == true && key=='1')
     n=1;
  if(keyPressed == true && key=='2')
     n=2;
  if(keyPressed == true && key=='3')
     n=3;
  if(keyPressed == true && key=='4')
     n=4;
  if(keyPressed == true && key=='5')
     n=5;
  if(keyPressed == true && key=='6')
     n=6;
  if(keyPressed == true && key=='7')
     n=7;
  if(keyPressed == true && key=='8')
     n=8;     
  if(keyPressed==true && key=='s' && q==true){
    salvaBitPlane(T);
    q=!q;
  }
}

PImage imtoGray(PImage I){
  PImage C=I.copy();
  float r,g,b,x;
  C.loadPixels();
  for(int i=0; i<C.pixels.length; i++){
    r=0.5*red(C.pixels[i]);
    g=0.2*green(C.pixels[i]);
    b=0.3*blue(C.pixels[i]);
    x=r+g+b;
    C.pixels[i]=color(x);
  }
  return C;
}

PImage estraiPianoN(PImage I,int n){
  PImage C=I.copy();
  int x;
  C.loadPixels();
  for(int i=0; i<C.pixels.length; i++){
    x=C.pixels[i];
    x=x>>(n-1)&1;
    C.pixels[i]=color(255*x);
  }
  return C;
}

void salvaBitPlane(PImage I){
  PImage C;
  PImage S;
  int x;
  for(int n=0; n<8; n++){
    C=I.copy();
    C.loadPixels();
    for(int i=0; i<C.pixels.length; i++){
      x=C.pixels[i];
      x=x>>(n)&1;
      C.pixels[i]=color(255*x);
    }
    S=C.copy();
    S.save("b"+n+".png");
  }
}
