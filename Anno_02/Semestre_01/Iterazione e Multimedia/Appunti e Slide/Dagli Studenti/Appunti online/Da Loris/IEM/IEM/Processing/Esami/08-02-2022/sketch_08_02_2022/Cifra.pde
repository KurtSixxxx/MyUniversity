class Cifra{
  float x, y, vel;
  char num;
  
  Cifra(char num){
    this.x = random(width);
    this.y = 0;
    this.vel = random(2,10);
    this.num=num;
  }
  
  void body(){
    fill(255,255,0);
    textSize(32);
    text(num, x, y);
  }
  
  void move(){
    if(y>=height){
      y=0;
    }
    y+=vel;
  }
  
  void display(){
    body();
    move();
  }
}
