int d=40;
void setup(){
  size(1000,1000);
}

//Gestione distanza da mouse a figura
void draw(){
  background(0);
  for(int y=0; y<=height; y+=d){
    for(int x=0; x<=width; x+=d){
      if(dist(x,y,mouseX,mouseY)<d/2){
        fill(255,0,0);
      }else{
        fill(255);
      }
      ellipse(x,y,d,d);
    }
  }
}
