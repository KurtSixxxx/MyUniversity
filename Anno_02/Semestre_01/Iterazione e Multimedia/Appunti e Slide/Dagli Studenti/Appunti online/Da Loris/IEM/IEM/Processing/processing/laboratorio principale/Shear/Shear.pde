/*Shear x,y(stretcha e allarga in diagonale e ritorna per passare dalla diagonale sinistra al centro*/
float shX=0.1;
float shY=0.1;


void setup(){
  fill(0,255,0);
  stroke(255,0,0);
  strokeWeight(5);
  rectMode(CENTER);
  size(500,500);
}

void draw(){
  background(255);
  translate(width/2,height/2);
  shearX(shX);
  ellipse(0,0,150,150);
  shX+=0.01;
  shY+=0.01;
}
  
