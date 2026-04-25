ArrayList <Ball> b;
int r;
float posx, posy, sy;
color c;


void setup(){
  size(512, 256);
  b = new ArrayList <Ball>();
}

void draw(){
  background(0);
  posx = random(width);
  posy = random(height);
  sy=5;
  r = 40;
  c=color(0,0,255);
  for(Ball b : b){
    b.display();
  }
}

void keyPressed(){
  if(key == 'r' || key == 'R'){
    setup();
  }
}

void mousePressed(){
  if(mouseButton == LEFT){
    b.add(new Ball(posx, posy, sy, r));
  }else if(mouseButton == RIGHT){
    b.add(new HyperBall(posx,posy, sy, r, c));
  }
}
