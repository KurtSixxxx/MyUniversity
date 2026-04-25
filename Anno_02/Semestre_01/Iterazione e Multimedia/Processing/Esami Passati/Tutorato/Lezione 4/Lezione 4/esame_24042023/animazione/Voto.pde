class Voto{
  float x, y;
  int sp;
  int v;
  
  Voto(){
    this.x = random(15,width-15);
    this.y = random(15,height-15);
    this.sp = int(random(2,10));
    this.v = int(random(18,30));
    rectMode(CENTER);
    textAlign(CENTER,CENTER);
    textSize(28);
  }
  
  void body(){
    noFill();
    stroke(255,255,0);
    rect(x,y,30,30);
    fill(255,255,0);
    text(v,x,y);
  }
  
  void move(){
    if(x+15>=width || x-15<=0)
      sp*=-1;
    x+=sp;
  }
  
  void display(){
    body();
    move();
  }
}
