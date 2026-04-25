Block bl;
Block b2;
AmazingBlock ab;
float x,y;
int v;
color c;
int w,h;
int r,g,b;
float a;

void setup(){
  size(256,256);
  w = int(random(20,70));
  h = int(random(20,70));
  v = 5;
  x=random(0,width-w);
  y=random(0,height-h);
  r=int(random(0,255));
  g=int(random(0,255));
  b=int(random(0,255));
  c = color(r,g,b);
  bl = new Block(x,y,w,h,v,c);
  b2 = new Block();
  x=random(0,width-w);
  y=random(0,height-h);
  a = random(0,255);
  ab = new AmazingBlock(x,y,w,h,v,c,a);
}

void draw(){
  background(0);
  bl.display();
  b2.point_break();
  ab.display();
}

void keyPressed(){
  if(key=='R' || key=='r')
    setup();
  if(key=='S' || key=='s')
    stop();
  if(key=='l' || key=='L')
    loop();
  if(key=='n' || key=='N')
    noLoop();
  if(key=='q' || key=='Q')
    exit();
}


  
