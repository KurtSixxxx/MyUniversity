class Ball{
  float x,y;
  int R;
  float sy=5;
  
  Ball(float posx, float posy, int R, float sy){
    this.x=posx;
    this.y=posy;
    this.R=R;
    this.sy=sy;
  }
  
  void body(){
    noStroke();
    fill(#ff0000);
    ellipse(x,y,R,R);
  }
  
  void move(){
    if(y>=height || y<=0)
      sy*=-1;
    y+=sy;
  }
  
  void display(){
    body();
    move();
  }
}
