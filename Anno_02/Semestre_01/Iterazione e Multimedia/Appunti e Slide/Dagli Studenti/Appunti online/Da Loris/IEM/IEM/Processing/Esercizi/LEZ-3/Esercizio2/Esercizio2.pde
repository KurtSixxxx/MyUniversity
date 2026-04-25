int [] cerchio= new int[10];

void setup(){
  size(500,500);
  stroke(255);
  for(int i=0; i<cerchio.length; i++){
    cerchio[i]=i*100;
  }
  noFill();
}


void draw(){
  background(0);
  int x=width/2;
  int y=height/2;
  for(int i=cerchio.length-1; i>=0; i--){
    ellipse(x,y,cerchio[i],cerchio[i]);
    cerchio[i]++;
  }
}
