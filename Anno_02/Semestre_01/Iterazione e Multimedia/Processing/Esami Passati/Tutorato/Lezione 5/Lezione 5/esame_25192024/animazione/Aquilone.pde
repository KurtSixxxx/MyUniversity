class Aquilone{
  float x,y;
  float v;
  float s;
  float h;
  color c1,c2;
  
  Aquilone(float posx, float posy, float v, float s){
    this.x=posx;
    this.y=posy;
    this.v=v;
    this.s=s/2;
    this.h=(s*1.5)/2;
    this.c1 = color(#ffff00);
    this.c2 = color(#ff0000);
  }
  
  void body(){
    noStroke();
    fill(c1);
    quad(x-s,y,x,y-h,x+s,y,x,y+h);
    stroke(c2);
    line(x-s,y,x+s,y);
    line(x,y-h,x,y+h);
  }
  
  void move(){
    if(x-s>=width && v>0)
      x=-2*s;
    if(x+s<=0 && v<0)
      x=width+2*s;
    x+=v;
  }
  
  void display(){
    body();
    move();
  }
    
}
