int dir=1;
int a=30;
int x=25;
int dira=-1;
void setup(){
  size(500,500);
  
}

void draw(){
  background(0);
  if(dir==1){
    fill(255,255,0);
    arc(x,height/2,50,50,radians(a), radians(360-a));
    fill(0);
    ellipse(x+5, height/2-10, 5, 5);
  }
  if(dir==-1){
    fill(255,255,0);
    arc(x,height/2,50,50,radians(180+a), radians(360+180-a));
    fill(0);
    ellipse(x-5, height/2-10, 5, 5);
  }
  if(x>width-25 || x<25){
    dir=-dir;
  }
  
  if(a<=0 || a>30){
    dira=-dira;
  }
  a+=dira;
  x+=dir*5;
}
