ArrayList<Ball> b;
float x,y,sy;
int R;

void setup(){
  size(512,256);
  R = 40;
  sy = 5;
  b = new ArrayList<Ball>();
}

void draw(){
  background(0);
  for(Ball i : b)
    i.display();
}

void keyPressed(){
  if(key=='R' || key=='r')
    setup();
}

void mousePressed(){
  x = random(R/2,width-R/2);
  y = random(R/2, height-R/2);
  if(mouseButton==LEFT)
    b.add(new Ball(x,y,R,sy));
  if(mouseButton==RIGHT)
    b.add(new HyperBall(x,y,R,sy,color(#0000ff)));
}
