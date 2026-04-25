class Auto{

  //Attributi
  float w, h, posX, posY, vX;
  float diameter;
  
  //Costruttore
  Auto(){
      vX = random(2,4);
      
      w = random(60,200);
      h = w/3;
      
      posX = random(w, width-w);
      posY = height / 3.0; //CHIARIRE PERCHè NON HO CAPITO
      
      diameter = w / 5.0;
  }
  
  //Metodi
  void display(){
    noStroke();
    
    fill(255,0,0);
    rectMode(CORNER);
    rect(posX,posY, w,h);
    
    fill(0);
    ellipse((posX + (w / 3.0)), (posY + h), diameter, diameter); // Ruota 1
    ellipse((posX + (w * 2 / 3.0)), (posY + h), diameter, diameter); // Ruota 2
  }
  
  void move(){
   posX += vX;
    if(posX >= width){
      posX = -w;
    }
  }
  
  void run(){
    display();
    move();
  }
  
}
