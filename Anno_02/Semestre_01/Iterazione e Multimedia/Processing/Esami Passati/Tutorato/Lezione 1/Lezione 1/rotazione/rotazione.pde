float a;

void setup(){
  size(500,500);
  a = 0;
}

void draw(){
  background(0);
  translate(width/2,height/2);
  rotate(a);
  stroke(#ff0000);
  strokeWeight(10);
  line(0,0,0,-100);
  a-=0.05;
}
