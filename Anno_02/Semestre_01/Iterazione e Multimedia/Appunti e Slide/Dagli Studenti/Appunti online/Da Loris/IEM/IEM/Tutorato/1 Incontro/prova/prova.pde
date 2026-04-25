//DA MODIFICARE

Block bl;
AmazingBlock ab;
float x, y;
int v;
color c;
int w, h;
int r,g,b;

void setup(){
  size(800,800);
  w=40;
  h=60;
  x=random(0,width-w);
  y=random(0, height-h);
  r=int(random(0, 255));
  g=int(random(0,255));
  b=int(random(0,255));
  c=color(r,g,b);
  v=10;
  
  bl=new Block(x,y,w,h,v,c);
  
  ab= new AmazingBlock(x,y,w,h,v,c, 1.0);
}

void draw(){
  background(0);
  bl.display();
  ab.display();
}

void keyPressed(){
  if(key=='r' || key=='R'){
    setup();
  }
  if(key=='s'||key=='S'){
    stop();
  }
  if(key=='l'||key=='L'){
    loop();
  }
  if(key=='n'||key=='N'){
    noLoop();
  }
  if(key=='q'||key=='Q'){
    exit();
  }
}
