size(700,500);
background(255);
int y=height/2;
int d=100;

stroke(233,156,237);
strokeWeight(5);
for(int x=100; x<width; x+=100){
  ellipse(x, y, d, d);
  d-=15;
}
