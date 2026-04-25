/*Scaling*/
float scale=0.3;
int dir_scale=1;
void setup(){
  background(255);
  fill(0,255,0);
  stroke(255,0,0);
  strokeWeight(5);
  rectMode(CENTER);
  size(500,500);
  frameRate(10);
}

void draw(){
  background(255);
  translate(width/2,height/2);
  scale(scale);
  rect(0,0,width,height);
}


  
