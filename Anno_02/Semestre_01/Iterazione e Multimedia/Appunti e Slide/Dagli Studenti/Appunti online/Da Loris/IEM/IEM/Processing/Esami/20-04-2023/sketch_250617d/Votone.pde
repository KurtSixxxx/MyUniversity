class Votone extends Voto{
  Votone(float x, float y, float velx){
    super(x,y,velx);
  }
  
  void body(){
    noFill();
    stroke(255);
    rectMode(CENTER);
    rect(x, y, 30, 30);
    fill(255);
    textSize(28);
    textAlign(CENTER, CENTER);
    text(num, x, y);
    
    if(num >= 24){
      textSize(28);
      textAlign(CENTER, TOP);
      text("LODE", x, y+10);
    }
  }
  
  void move(){}
}
