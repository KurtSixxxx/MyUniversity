class Block{
  float x, y;
  int w, h, sx;
  color c;
  Block(float posx, float posy, int w, int h, int speed, color c){
    this.x=posx;
    this.y=posy;
    this.w=w;
    this.h=h;
    this.sx=speed;
    this.c=c;
  }
  
  Block(){
    this.x=random(0,width);
    this.y=random(0,height);
  }
  
  void point_break(){
    stroke(255,0,0);
    strokeWeight(10);
    point(x,y);
  }
  
  void body(){
    noStroke();
    fill(c);
    rect(x,y,w,h);
  }
  
  void move(){
    if(x>=width)
      x=0;
    x+=sx;
  }
  
  void display(){
    body();
    move();
  }
}
