class Casa{
  float x, y, velx;
  color c = color(255,255,0);
  
  Casa(float x, float y, float velx){
    this.x=x;
    this.y=y;
    this.velx = velx;
  }
  
  void body(){
    noFill();
    rectMode(CENTER);
    stroke(c);
    rect(x, y, 30, 30);
    triangle(x-20, y-15, x, y-30, x+20, y-15);
  }
  
  void move(){
    if(x+15>=width || x-15<=0){
      velx*=-1;
    }
    x+=velx;
  }
  
  void display(){
    body();
    move();
  }
}
