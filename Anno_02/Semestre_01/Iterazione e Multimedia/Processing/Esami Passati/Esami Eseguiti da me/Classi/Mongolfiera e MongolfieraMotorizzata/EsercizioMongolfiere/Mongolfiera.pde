class Mongolfiera{
  float x,y,v,h,w,d;
  
  Mongolfiera(){
    x = random(d, width-d);
    y = height/3.0;
    w = 60;
    h = 30;
    d = 70;
    v = random(2,10);
  }
  
  void display(){
    fill(0,255,0);
    ellipse(x,y,d,d);
    
    rectMode(CENTER);
    fill(255,255,0);
    rect(x,y+65,w,h);
    
    fill(0);
    strokeWeight(3);
    line(x-d/2, y, x-w/2, y+65);
    line(x+d/2, y, x+w/2, y+65);
}
  
  void move(){
    x += v;
    if(x-d/2 >= width){
        x = -d/2;
    }else if(x+d/2 <= 0){
        x = width + d/2;
    }
  }
  
  void run(){
  display();
  move();
  }
}
