float [] d= new float[10];

void setup(){
  size(800,800);
  noFill();
  for(int i=0; i<d.length; i++){
    i=i*10;
  }
  stroke(random(255), 0, random(255));
}

void draw(){
   int y=(height-150);
   int x=(width-150);
   background(255);
   /*for(int y=150; y<=(height-150)-d/2; y+=d){
     for(int x=150; x<=(width-150)-d/2; x+=d){
       ellipse(x,y,d,d);
     }
   }*/
   for(int i=d.length-1; i>=0; i++){
     ellipse(x, y,d[i], d[i]);
   }
}
