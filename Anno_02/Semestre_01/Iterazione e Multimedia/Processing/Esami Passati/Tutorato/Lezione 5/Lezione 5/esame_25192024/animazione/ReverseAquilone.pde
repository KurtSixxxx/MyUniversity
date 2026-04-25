class ReverseAquilone extends Aquilone{
  ReverseAquilone(float posx, float posy, float v, float s){
    super(posx, posy, v, s);
    this.s=this.s*(2.0/3.0);
    this.h=this.h*(2.0/3.0);
    color tmp=c1;
    this.c1=this.c2;
    this.c2=tmp;
  }
  
  void fermo(){
    float c = dist(x,y,x+s,y);
    float r = dist(x,y,mouseX,mouseY);
    if(r > c)
     move();
  }
  
  void display(){
    body();
    fermo();
  }
}
