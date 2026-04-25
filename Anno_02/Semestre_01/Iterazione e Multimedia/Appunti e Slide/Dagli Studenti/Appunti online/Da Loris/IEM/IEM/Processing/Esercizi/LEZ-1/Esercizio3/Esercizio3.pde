size(600,600);
background(255);

line(0, height/2, width, height/2);
strokeWeight(2);
int d1=0;
int d2=0;
noFill();
for(int x=25; x<=width/2; x+=25){
  ellipse(x, height/2, d1, d2);
  d1+=50;
  d2+=50;
}
/*ellipse(25, height/2, 50, 50);
ellipse(50, height/2, 100, 100);
ellipse(75, height/2, 150, 150);
ellipse(100, height/2, 200, 200);
ellipse(125, height/2, 250, 250);*/
