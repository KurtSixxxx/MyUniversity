class Casetta extends Casa{
  color c = color(255);
  Casetta(float x, float y, float velx){
    super(x,y,velx);
  }
  
  void body(){
    noFill();
    rectMode(CENTER);
    stroke(c);
    rect(x, y, 30, 30);
    triangle(x-20, y-15, x, y-30, x+20, y-15);
    fill(255);
    rect(x, y+10, 5, 10);
  }
  
  void move(){
    if(x+20<=0){
      x=width+20;
    }
    x-=velx;
  }
} 
