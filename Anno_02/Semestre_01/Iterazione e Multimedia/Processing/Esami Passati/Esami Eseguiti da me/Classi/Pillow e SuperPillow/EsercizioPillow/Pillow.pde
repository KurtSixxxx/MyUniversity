class Pillow{
  
  float x, y, w, h, sx;
  
  Pillow(){
    x = random(w, width - w);
    y = random(h, height/2 - h);
    sx = 2;
    w = 40;
    h = 80;
  }
  
  void display(){
    noStroke();
    fill(255);
    rectMode(CENTER);
    rect(x,y,h,w);
  }
  
  void move(){
    x += sx;
    if (x <= 0 || x >= width) {
      sx = -sx;
    }
  }
  
  void run(){
    display();
    move();
  }

}
