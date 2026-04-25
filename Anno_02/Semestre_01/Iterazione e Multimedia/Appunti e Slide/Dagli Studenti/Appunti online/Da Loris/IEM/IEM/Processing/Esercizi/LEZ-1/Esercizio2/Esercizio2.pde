size(400,400);
noStroke();
frameRate(30);
background(0);
int d1=width/2;
int d2=height/2;
fill(255, 100);

for(int dim=0; dim<=width/2; dim+=20){
  rect(dim, dim, d1, d2);
}

/*int x=0;
  int y=0;
  rect(x,y,d1,d2);
  rect(x+20, y+20, d1, d2);
  rect(x+40, y+40, d1, d2);
  rect(x+60, y+60, d1, d2);
  rect(x+80, y+80, d1, d2);
  rect(x+100, y+100, d1, d2);
  rect(x+120, y+120, d1, d2);
  rect(x+140, y+140, d1, d2);
  rect(x+160, y+160, d1, d2);
  rect(x+180, y+180, d1, d2);
  rect(x+200, y+200, d1, d2);*/
