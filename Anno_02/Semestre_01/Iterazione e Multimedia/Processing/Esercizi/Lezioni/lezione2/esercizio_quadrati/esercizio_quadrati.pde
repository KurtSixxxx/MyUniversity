size(500,500);
background(0);
noStroke();
fill(220,220,220,100);
int passo=15;
int lato=100;
for(int x=0; x<width; x+=passo)
{
  if(x+lato<width && x+lato<height)
  rect(x,x,lato,lato);
}
