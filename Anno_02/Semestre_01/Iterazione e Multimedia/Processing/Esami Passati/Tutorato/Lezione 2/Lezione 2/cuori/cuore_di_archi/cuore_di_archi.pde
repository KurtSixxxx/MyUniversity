size(500,500);
background(100);
translate(width/2,(height/2)-50);
scale(1,-1);
float x = 80;
float y = 0;
int r = 160;

fill(255,0,0);
arc(x,0,r,r,-HALF_PI,2*PI-PI);
arc(-x,0,r,r,0,PI+HALF_PI);
noStroke();
rect(-x,-x,r,x);
stroke(0);
beginShape();
vertex(-140,-53);
vertex(0,-180);
vertex(140,-53);
endShape();
