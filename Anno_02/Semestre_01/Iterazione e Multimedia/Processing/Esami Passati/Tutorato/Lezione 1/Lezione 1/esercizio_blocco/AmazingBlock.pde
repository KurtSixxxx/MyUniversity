class AmazingBlock extends Block{
  float a;
  float b;
  AmazingBlock(float posx, float posy, int w, int h, int speed, color c, float angle){
    super(posx,posy,w,h,speed,c);
    b = blue(c);
    this.a=angle;
  }
  
  void body(){
    rectMode(CENTER);
    noStroke();
    fill(a%256,255-a%256,b);
    rect(0,0,w,h);
  }
  
  void rotation(){
    translate(x,y);
    rotate(a);
    a+=5;
  }
  
  void display(){
    rotation();
    move();
    body();
  }
}
