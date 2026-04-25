PImage Im, I1, I2;
float s;
int h;

void setup(){
  size(768,256);
  s = random(0.5,1.5);
  h = int(random(10,80));
  Im = loadImage("lena.jpg");
  Im.resize(256,256);
  image(Im,0,0);
  I1 = sBlock2(Im, h);
  image(I1,256,0);
  I2 = sBlock2(Im, h, s);
  image(I2,512,0);
}

void draw(){}

void keyPressed(){
  if(key=='r' || key=='R')
    setup();
}

PImage sBlock1(PImage I, int h){
  PImage R = I.copy();
  
  int x1 = int(random(h/2,I.width-h/2));
  int y1 = int(random(h/2,I.width-h/2));
  int x2 = int(random(h/2,I.width-h/2));
  int y2 = int(random(h/2,I.width-h/2));
  
  float g;
  float b;
  
  for(int i = x1-h/2; i<x1+h/2; i++){
    for(int j = y1-h/2; j<y1+h/2; j++){
      g=green(R.get(i,j));
      b=blue(R.get(i,j));
      R.set(i,j,color(0,g,b));
    }
  }
  
  for(int i = x2-h/2; i<x2+h/2; i++){
    for(int j = y2-h/2; j<y2+h/2; j++){
      g=green(R.get(i,j));
      b=blue(R.get(i,j));
      R.set(i,j,color(0,g,b));
    }
  }
  
  return R;
}

PImage sBlock2(PImage I, int h){
  PImage R = I.copy();
  
  int x1 = int(random(h/2,I.width-h/2));
  int y1 = int(random(h/2,I.width-h/2));
  int x2 = int(random(h/2,I.width-h/2));
  int y2 = int(random(h/2,I.width-h/2));
  
  float g1;
  float b1;
  float g2;
  float b2;
  
  PImage quad1, quad2;
  
  quad1 = R.get(x1-h/2,y1-h/2,h,h);
  quad2 = R.get(x2-h/2,y2-h/2,h,h);
  
  for(int i=0; i<quad1.pixels.length; i++){
    g1 = green(quad1.pixels[i]);
    b1 = blue(quad1.pixels[i]);
    g2 = green(quad2.pixels[i]);
    b2 = blue(quad2.pixels[i]);
    
    quad1.pixels[i] = color(0,g1,b1);
    quad2.pixels[i] = color(0,g2,b2);
  }
  
  R.set(x1-h/2,y1-h/2,quad1);
  R.set(x2-h/2,y2-h/2,quad2);
  
  return R;
}

PImage sBlock2(PImage I, int h, float s){
  PImage R = I.copy();
  
  int x1 = int(random(h/2,I.width-h/2));
  int y1 = int(random(h/2,I.width-h/2));
  int x2 = int(random(h/2,I.width-h/2));
  int y2 = int(random(h/2,I.width-h/2));
  
  float g1;
  float b1;
  float g2;
  float b2;
  
  PImage quad1, quad2;
  
  quad1 = R.get(x1-h/2,y1-h/2,h,h);
  quad2 = R.get(x2-h/2,y2-h/2,h,h);
  
  for(int i=0; i<quad1.pixels.length; i++){
    g1 = green(quad1.pixels[i]);
    b1 = blue(quad1.pixels[i]);
    g2 = green(quad2.pixels[i]);
    b2 = blue(quad2.pixels[i]);
    
    quad1.pixels[i] = color(0,g1,b1);
    quad2.pixels[i] = color(0,g2,b2);
  }
  
  quad1 = scaleF(quad1, s);
  quad2 = scaleF(quad2, s);
  
  R.set(x1-h/2,y1-h/2,quad1);
  R.set(x2-h/2,y2-h/2,quad2);
  
  return R;
}

PImage scaleF(PImage I, float s){
  PImage R=createImage(I.width, I.height, RGB);
  
  R.loadPixels();
  
  for(int i=0; i<R.pixels.length;i++){
    R.pixels[i]=color(0);
  }
  
  float x,y;
  float u1,v1;
  
  for(int u=0; u<I.width;u++){
    for(int v=0; v<I.height;v++){
      
      u1=u-I.width/2;
      v1=v-I.height/2;
      
      x=u1*s;
      y=v1*s;
      
      x=x+I.width/2;
      y=y+I.height/2;
      
      R.set(round(x),round(y),I.get(u,v));
      
    }
  }
  return R;
}

PImage scaleI(PImage I, float s){
  PImage R=createImage(I.width, I.height, RGB);
  
  R.loadPixels();
  for(int i=0; i<R.pixels.length;i++){
    R.pixels[i]=color(0);
  }
  
  float u,v;
  float x1,y1;
  
  for(int x=0; x<I.width; x++){
    for(int y=0; y<I.height; y++){
      
      x1=x-I.width/2;
      y1=y-I.height/2;
      
      u=x1*1/s;
      v=y1*1/s;
      
      u=u+I.width/2;
      v=v+I.height/2;
      
      R.set(x,y,I.get(round(u),round(v)));
    }
  }
  
  return R;
}

PImage rotateF(PImage I, float theta){
  PImage R=createImage(I.width, I.height, RGB);
  
  R.loadPixels();
  for(int i=0; i<R.pixels.length;i++){
    R.pixels[i]=color(0);
  }
  
  float x,y;
  float u1,v1;
  for(int u=0; u<I.width;u++){
    for(int v=0; v<I.height;v++){
      //Questa traslazione serve ad effettuare l'operazione rispetto al centro dell'immagine
      u1=u-I.width/2;
      v1=v-I.height/2;
      
      x=u1*cos(theta)-v1*sin(theta);
      y=u1*sin(theta)+v1*cos(theta);
      
      //Devo aggiustare le coordinate poiché il calcolo è avvenuto rispetto al centro
      x=x+I.width/2;
      y=y+I.height/2;
      
      R.set(round(x),round(y),I.get(u,v));
      
    }
  }
  
  return R;
}

PImage rotateI(PImage I, float theta){
  PImage R=createImage(I.width, I.height, RGB);
  
  R.loadPixels();
  for(int i=0; i<R.pixels.length;i++){
    R.pixels[i]=color(0);
  }
  
  float u,v;
  float x1,y1;
  
  for(int x=0; x<I.width;x++){
    for(int y=0; y<I.height;y++){
      
      x1=x-I.width/2;
      y1=y-I.height/2;
      
      u=x1*cos(theta)+y1*sin(theta);
      v=-x1*sin(theta)+y1*cos(theta);
      
      u=u+I.width/2;
      v=v+I.height/2;
      
      R.set(x,y,I.get(round(u),round(v)));
      
    }
  }
  
  return R;
}
