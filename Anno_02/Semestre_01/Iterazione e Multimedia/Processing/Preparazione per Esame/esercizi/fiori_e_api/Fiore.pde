class Fiore{
  //Attributi
  float x, y, size;
  color colore = color(255,255,0); //inizialmente color(255,255,0), giallo
  
  //Costruttore
  Fiore(float x, float y, float size){
     this.x = x;
     this.y = y;
     this.size = size;
  }
  
  //Metodi
  void pollinate(){
    colore = color(random(255), random(255), random(255));
    size *= 0.9; //Perché 0.9 e non 1.0 ?
    if(size < 10) size = 10;
    //size = constrain(size, 10, 100);
  }
  
  void display(){
    noStroke();
    fill(colore);
    ellipse(x,y,size,size);
  }
}
