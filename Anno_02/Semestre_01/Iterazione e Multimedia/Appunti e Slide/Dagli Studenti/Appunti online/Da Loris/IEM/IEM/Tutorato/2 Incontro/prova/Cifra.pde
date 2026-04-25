class Cifra{
  int w, vel, y, x;
  char n;
  
  Cifra(int w, char num){
    this.w=w;
    this.n=num;
    vel=int(random(2,10));
    x=int(random(0, w));
    y=0;
  }
  
  void body(){
    fill(255,255,0);
    textSize(32);
    text(n,x,y);
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
