float shX;
float shY;
float scale;
void setup(){
  size(500,500);
  shX=0.1;
  shY=0.1;
  scale=0.1;
  fill(0,255,0);
  stroke(255,0,0);
  strokeWeight(5);
  rectMode(CENTER);
}

void draw(){
  background(255);
  pushMatrix();
  translate(150,200);
  shearX(shX);
  shearY(shY);
  //scale(scale);
  rect(0,0,50,50);
  popMatrix();
  //scale+=0.1;
  shX+=0.01;
  shY+=0.01;
}
