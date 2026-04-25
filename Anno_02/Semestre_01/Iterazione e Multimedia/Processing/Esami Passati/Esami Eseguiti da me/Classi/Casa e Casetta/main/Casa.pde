class Casa{
  
/*
Caratteristiche:
  - La classe è identificata da una posizione. -> float posX e posY
  - Una velocità lungo x randomica tra 2 e 10 px/frame. -> float vX = random(2,10)
  - Appare come una casa di colore giallo, con lato 30px. -> float size = 30
  - Viene creata in posizione randomica nella canvas -> random(size, width - size), random(size, heigth - size)
  - Si muove inizialmente da sinistra a destra. -> posX = -posX
  - Quando urta contro i bordi della canvas cambia verso di percorrenza. -> if(...){posX = -posX}
*/  

  //Attributi
  float posX, posY;
  float vX;    //random(2,10)
  float size; // = 30
  
  //Costruttore
  Casa(float x, float y, float v, float s){
    this.posX = x;
    this.posY = y;
    this.vX = v;
    this.size = s;
  }
  
  //Metodi
  void display(){
  stroke(255,255,0);
  strokeWeight(3);
  noFill();
  
  size = 30;
  rectMode(CENTER);
  rect(posX,posY, size,size);
  
  triangle(posX-size/2,posY-size/2, posX,posY-size/2*2, posX+size/2,posY-size/2);
  }
  
  void bounce(){
    if(posX < size/2 || posX > width - size/2){
      vX = -vX;
    }
  }
  
  void move(){
    posX -= 1 * vX;
  }
  
  void run(){
    display();
    move();
    bounce();
  }

}
