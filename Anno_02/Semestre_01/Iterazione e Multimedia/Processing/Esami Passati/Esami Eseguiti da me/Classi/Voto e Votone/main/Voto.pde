 class Voto{
 //Attributi
 float posX, posY;
 float vX;
 float w = 30;
 int value = ((int)random(18, 30));
 
 Voto(){
   this.posX = random(30, width-w);
   this.posY = random(30, height-w);
   this.vX = random(2,10);
 }
 
 void display(){   
   stroke(255,255,0);
   strokeWeight(3);
   
   textSize(28);
   textAlign(CENTER, CENTER);
   text(value, posX, posY);
  
   noFill();
   rectMode(CENTER);
   rect(posX,posY, w,w);
 }
 
 void move(){
   posX -= vX;
 }
 
  void bounce(){
    if(posX - w/2 < 0 || posX + w/2 > width){
      vX = -vX;
      }
    }
 
   void run(){
     display();
     move();
     bounce();
   }
 }
