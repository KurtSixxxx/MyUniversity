class Ball{
  float x, y,sy;
  int r;
  color c = color(255,0,0);
  
  Ball(float x, float y, float sy, int r){
    this.x=x;
    this.y=y;
    this.sy=sy;
    this.r=r;
  }
  
  void body(){
    noStroke();
    fill(c);
    ellipse(x, y, r, r);
  }
  
  void move(){
    if(y >= height || y<=0){
      sy*=-1;
    }
    y+=sy;
  }
  
  void display(){
    body();
    move();
  }
}
