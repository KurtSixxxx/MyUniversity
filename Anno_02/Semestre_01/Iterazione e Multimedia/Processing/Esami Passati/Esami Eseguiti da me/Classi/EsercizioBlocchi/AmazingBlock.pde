class AmazingBlock extends Block{
  float angle = random(0,360);
  
   AmazingBlock(float x, float y, float w, float h){
     super(x,y,w,h);
   }
  
    void display(){
      fill(angle%256, 255-angle%256, 255);
      noStroke();
      pushMatrix();
        translate(width/2, height/2+h);
        rotate(radians(angle));
        rectMode(CENTER);
        rect(0,0,w,h);
      popMatrix();
   }
  
    void move(){
    x += sx;
      if(x >= width || x+w/2 <= 0){
        sx = -sx;
      }
    angle += 5;
    }
  
  void run(){
    display();
    move();
  }
  
  
}
