class Warp{
    
  //Attributi
  float posX, posY, sx;
  color c;
  
  float r1 = 35;
  float r2 = 30;
  float r3 = 25;
  
  //Costruttore
  Warp(){
    this.posX = random(50,550);
    this.posY = random(50,550);
    this.sx   = random(2,23);
    this.c    = color(random(0,255), random(0,255), random(0,255));
  }

  //Metodi
  void display(){    
    noStroke();
    ellipseMode(RADIUS);
    fill(0);
    ellipse(this.posX,this.posY, r1,r1);
    fill(128);
    ellipse(this.posX,this.posY, r2,r2);
    fill(c);
    ellipse(this.posX,this.posY, r3,r3);
    
    textSize(40);
    fill(255);
    textAlign(CENTER, CENTER);
    text(int(sx), this.posX,this.posY);
  }
  
  Bullet shot(){
    if(isIn() == true){
      return new Bullet(this.posX, this.posY, this.sx, this.c);
    }
      return null;
    }

  boolean isIn(){
    if(dist(this.posX,this.posY, mouseX,mouseY) <= r3){
      return true;
    }else{
      return false;
    }
  }
}
