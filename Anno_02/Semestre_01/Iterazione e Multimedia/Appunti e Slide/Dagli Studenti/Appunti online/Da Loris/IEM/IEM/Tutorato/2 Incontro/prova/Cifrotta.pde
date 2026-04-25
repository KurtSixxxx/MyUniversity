class Cifrotta extends Cifra{
  Cifrotta(int w, char n){
    super(w, n);
    vel = -vel;
    y=height;
  }
  
  void body(){
    fill(255);
    textSize(32);
    text(n,x,y);
    noFill();
    stroke(255);
    textAlign(CENTER, CENTER);
    ellipse(x,y,35,35);
  }
  
  void move(){
    if(y<=0){
      y=height;
    }
    y+=vel;
  }
}
