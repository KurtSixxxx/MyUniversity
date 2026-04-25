class AmazingBlock extends Block{
  float a; //angolo
  AmazingBlock(float posx, float posy, int w, int h, int speed, color c, float angle){
    super(posx,posy,w,h,speed,c);
    this.a=angle;
  }
  
  void body(){
    rectMode(CENTER);
    fill(a%256, 255-a%256, 255);
    noStroke();
    rect(0,0,w,h);
  }
  
  void rotation(){
    translate(x,y);
    rotate(a);
    a+=0.5;
  }
  
  void display(){
    body();
    rotation();
  }
}
