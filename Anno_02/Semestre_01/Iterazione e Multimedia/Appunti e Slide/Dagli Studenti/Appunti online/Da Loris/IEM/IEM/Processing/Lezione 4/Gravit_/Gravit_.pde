float x=240;
float y=0;
float speed=0;
float gravity=0.1;

void setup(){
  size(500,250);
  frameRate(240);
}

void draw(){
  background(255);
  fill(175);
  stroke(0);
  rectMode(CENTER);
  rect(x,y,30,30);
  
  y+=speed;
  speed+=gravity;
  
  if(y>height){
    speed=speed*-0.80;
    y=height;
  }
}
