class HyperBall extends Ball{
  color c = color(0,0,255);
  HyperBall(float x, float y, float sy, int r, color c){
    super(x, y, sy, r);
    this.c=c;
  }
  
  void body(){
    if(dist(mouseX, mouseY, x, y) < r){
      int red = int(random(0,255));
      int green = int(random(0,255));
      int blue = int(random(0,255));
      c = color(red,green,blue);
    }
    noStroke();
    fill(c);
    ellipse(x, y, r, r);
  }
  
  void display(){
    body();
    move();
  }
}
