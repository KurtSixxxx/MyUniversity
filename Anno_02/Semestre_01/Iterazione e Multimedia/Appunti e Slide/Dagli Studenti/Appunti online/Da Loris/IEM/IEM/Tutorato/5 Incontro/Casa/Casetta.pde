class Casetta extends Casa{
  Casetta(){
    super();
  }
  
  void body(){
    rectMode(CENTER);
    stroke(255);
    noFill();
    rect(x,y,30,30);
    triangle(x, y-30, x-20, y-15, x+20, y-15);
    rect(x, y+10, 5, 10);
  }
  
  void move(){
    if(x>=width){
      x=width;
    }
    x-=v;
  }
}
