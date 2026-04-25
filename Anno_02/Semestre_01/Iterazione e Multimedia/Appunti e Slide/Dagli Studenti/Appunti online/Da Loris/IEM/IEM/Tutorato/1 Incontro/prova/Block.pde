class Block{
  color c;
  float x, y;
  int w, h, sx;
  Block(float posx, float posy, int w, int h, int speed, color c){
    this.x=posx;
    this.y=posy;
    this.w=w;
    this.h=h;
    this.sx=speed;
    this.c=c;
  }
  
  void point_break(){
    stroke(255,0,0);
    
  }
  
  void body(){
    rectMode(CORNER);
    noStroke();
    fill(c);
    rect(x, y, w, h);
  }
  
  void move(){
    if(x+w>width || x<0){
      x=-sx;
    }
    /*if(x>=width){
      x=0;
    }*/
    x+=sx;
  }
  
  void display(){
    body();
    move();
  }
}
