class MongolfieraMotorizzata extends Mongolfiera{
  
  float c = random(0,255);
  
  MongolfieraMotorizzata(){
    super();
    y = (height * 2) / 3.0;
  }
  
  void display(){
    fill(c);
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
    
    if(x+d/2 >= width || x-d/2 <= 0){
      v = -v;
    }
  }
  
}
