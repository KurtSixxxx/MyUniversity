class ReverseAquilone extends Aquilone{
  color temp;
  ReverseAquilone(float x, float y, float v, float s){
    super(x, y, v, s);
    this.s = this.s*(2.0/3.0);
    this.h = this.h*(2.0/3.0);
    temp = c1;
    this.c1 = this.c2;
    this.c2=this.temp;
  }
  
  void fermo(){
    float c = dist(x, y, x-s, y);
    float r = dist(x, y, mouseX, mouseY);
    if(r>c){
      move();
    }
  }
  
  void display(){
    body();
    fermo();
  }
}
