class Block{
  float x, y, w, h;
  float sx = 4;
  
  Block(float x, float y, float w, float h){
    this.x = x;
    this.y = y;
    this.w = w;
    this.h = h;
  }
  
  void display(){
    fill(0,255,0);
    noStroke();
    rect(x,y,w,h);
   }
   
  void move(){
    x += sx;
      if(x >= width || x+w/2 <= 0){
        sx = -sx;
      }
  }
  
  void run(){
    display();
    move();
  }
}
