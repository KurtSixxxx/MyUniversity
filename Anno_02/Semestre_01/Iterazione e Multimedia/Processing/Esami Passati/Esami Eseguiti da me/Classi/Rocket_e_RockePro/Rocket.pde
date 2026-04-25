class Rocket{
float c1 = random(0,255);
float c2 = random(0,255);
float c3 = random(0,255);
  //Attributi
  float posX,posY,vY,widthR,heightR;
  
  //Costruttore
  Rocket(){
    posX = random(widthR, width/2-widthR);
    posY = random(heightR, height-heightR);
    vY = random(3,8);
    widthR = 40;
    heightR = 80;
  }
  
  void display(){
    stroke(0);
    strokeWeight(3);
    fill(c1,c2,c3);
    rect(posX, posY, widthR, heightR);
    triangle(posX,posY, posX+widthR/2,posY-heightR/2, posX+widthR,posY);
  }
  
  void move(){
    posY -= vY;
    
    if(posY + widthR <= -heightR){
      posY = height-10;
    }
  }
  
  void run(){
    display();
    move();
  }
}
