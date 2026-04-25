class Votone extends Voto{
  Votone(){ super(); }
  
  void body(){
    noFill();
    stroke(255);
    rect(x,y,30,30);
    fill(255);
    text(v,x,y);
    if(v > 24)
      text("LODE", x, y+30);
  }
  
  void move() {};
}
