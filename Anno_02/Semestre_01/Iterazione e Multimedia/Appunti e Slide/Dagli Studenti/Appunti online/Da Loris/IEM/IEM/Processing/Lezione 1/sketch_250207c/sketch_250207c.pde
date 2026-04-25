void setup(){
  size(500,500);
  println("sono nel setup");
  frameRate(30);
  background(0);
}

void draw(){
  println("sono nel draw "+frameCount+" frame sono passati");
  if(frameCount > 150){
    ellipse(width/2, height/2, 50, 50); 
  }
}
