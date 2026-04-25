class Cifrotta extends Cifra{
  Cifrotta(char num){
    super(num);
    this.y=height;
    vel=-vel;
  }
  
  void body(){
    fill(255);
    textSize(32);
    text(num, x, y);
    textAlign(CENTER, CENTER);
    noFill();
    stroke(255);
    ellipse(x, y, 35, 35);
  }
  
  void move(){
    if(y<=0){
      y=height;
    }
    y+=vel;
  }
}
