class Aquilone{
  float x, y, v, s, h;
  color c1;
  color c2;
  
  Aquilone(float x, float y, float v, float s){
    this.x=x;
    this.y=y;
    this.v=v;
    this.s=s/2;
    this.h=(s*1.5)/2;
    this.c1= color(255,255,0);
    this.c2= color(255,0,0);
  }
  
  void body(){
    noStroke();
    fill(c1);
    quad(x-s, y, x, y-h, x+s, y, x, y+h);
    stroke(c2);
    line(x-s, y, x+s, y);
    line(x, y-h, x, y+h);
  }
  
  void move(){
    if(x-s>=width && v>0){
      x=-2*s;
    }else if(x+s <= 0 && v<0){
      x=width+2*s;
    }
    x+=v;
  }
  
  void display(){
    body();
    move();
  }
}
