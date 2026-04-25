class Casa{
  float x,y,v;
  
  Casa(){
    this.x=random(20,width-20);
    this.y=random(30,height-15);
    this.v=random(2,10);
  }
  
  void body(){
    rectMode(CENTER);
    stroke(#ffff00);
    noFill();
    rect(x,y,30,30);
    triangle(x,y-30,x-20,y-15,x+20,y-15);
  }
  
  void move(){
    if(x+20>=width || x-20<=0)
      v*=-1;
    x+=v;
  }
  
  void display(){
    body();
    move();
  }
}
