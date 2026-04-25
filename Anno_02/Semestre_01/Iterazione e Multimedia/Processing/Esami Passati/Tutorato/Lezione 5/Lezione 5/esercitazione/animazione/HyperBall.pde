class HyperBall extends Ball{
  color c = color(#0000ff);
  
  HyperBall(float posx, float posy, int R, float sy, color c){
    super(posx, posy, R, sy);
    this.c=c;
  }
  
  void body(){
    float r,g,b;
    if(dist(mouseX, mouseY, x, y) < R){
      r = random(0,255);
      g = random(0,255);
      b = random(0,255);
      c = color(r,g,b);
    }
    noStroke();
    fill(c);
    ellipse(x,y,R,R);
  }
}
