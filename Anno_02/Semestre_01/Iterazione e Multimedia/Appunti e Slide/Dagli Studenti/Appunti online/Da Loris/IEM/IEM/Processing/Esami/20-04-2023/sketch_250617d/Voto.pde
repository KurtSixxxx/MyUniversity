class Voto{
  float x, y, velx;
  int num;
  Voto(float x, float y, float velx){
    this.x=x;
    this.y=y;
    this.velx=velx;
    this.num =(int)random(18,30);
  }
  
  void body(){
    noFill();
    stroke(255,255,0);
    rectMode(CENTER);
    rect(x, y, 30, 30);
    fill(255,255,0);
    textSize(28);
    textAlign(CENTER, CENTER);
    text(num, x, y);
  }
  
  void move(){
    if(x+15 >= width || x-15<=0){
      velx*=-1;
    }
    x+=velx;
  }
  
  void display(){
    body();
    move();
  }
}
