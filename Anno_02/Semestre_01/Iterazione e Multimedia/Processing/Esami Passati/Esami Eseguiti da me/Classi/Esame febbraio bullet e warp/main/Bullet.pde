class Bullet{
  
  //Attributi
  float posX, posY, sx;
  color c;
  float r = 10;
  
  //Costruttore
  Bullet(float x, float y, float s, color c){
    this.posX = x;
    this.posY = y;
    this.sx = s;
    this.c = c;
  }
  
  //Metodi
  void display(){
    noStroke();
    fill(c);
    ellipseMode(RADIUS);
    ellipse(posX,posY ,r,r);
  }
  
  void move(){
    posX += sx;
  }
  
  void run(){
    display();
    move();
  }
}
