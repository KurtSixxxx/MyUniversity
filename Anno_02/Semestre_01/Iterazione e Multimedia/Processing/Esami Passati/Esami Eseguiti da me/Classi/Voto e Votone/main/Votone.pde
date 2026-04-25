class Votone extends Voto{
  
  Votone(){
   super();
   this.vX = 0;
 }

   void display(){   
   stroke(255,255,255);
   strokeWeight(3);
   
   textSize(28);
   textAlign(CENTER);
   text(value, posX, posY+5);
   if(value > 24){
   textSize(15);
   text("LODE", posX, posY+30);
   }
  
   noFill();
   rectMode(CENTER);
   rect(posX, posY, 30,30);
 }
 
  void move(){
   posX -= 0 + vX;
 }
}
