int r=0;
int g=0;
int b=0;
int d=50;

size(500,500);
background(255);
fill(r,g,b);
for(int y=0; y<=height; y+=d){
  for(int x=0; x<=width; x+=d){
    noStroke();
    fill(r,g,b);
    rect(x, y, d, d);
    r+=2;
    g+=2;
    b+=2;
  }
}
