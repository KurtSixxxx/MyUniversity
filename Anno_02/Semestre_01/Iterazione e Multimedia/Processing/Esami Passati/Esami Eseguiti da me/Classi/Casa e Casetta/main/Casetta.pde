class Casetta extends Casa{

  //Costruttore
  Casetta(float x, float y, float v, float s){
    super(x,y,v,s);
  }
  
  //Metodi
  void display(){
  stroke(255);
  strokeWeight(3);
  noFill();
  
  size = 30;
  rectMode(CENTER);
  rect(posX,posY, size,size);
  fill(255);
  rect(posX,posY+10, 10,10);
  
  triangle(posX-size/2,posY-size/2, posX,posY-size/2*2, posX+size/2,posY-size/2);
  }
  
  void bounce(){
    if(posX >= width){
      posX = 0;
    }else if(posX <= 0){
      posX = width;
    }
  }
  
  void move(){
    posX -= 1 * vX;
   }
}
