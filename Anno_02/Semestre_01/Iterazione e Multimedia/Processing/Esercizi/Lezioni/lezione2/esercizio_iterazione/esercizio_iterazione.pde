size(1040, 500);
background(#FFFF00);

int d=50; //Diametro
ellipseMode(CORNER);
for(int y=0; y<height; y+=d) {
  for(int x=0; x<width; x+=d) {
    ellipse(x,y,d,d);
  }
}
