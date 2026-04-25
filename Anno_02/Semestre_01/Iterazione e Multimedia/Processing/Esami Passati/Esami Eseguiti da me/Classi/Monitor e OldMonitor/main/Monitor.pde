  class Monitor{
  
  /*
  - Implementare una classe Monitor con le seguenti caratteristiche:
  la classe è identificata da:
      una posizione,
      una velocità lungo x,
      una lunghezza w di 60 px
      e una altezza h. 
  Appare come un oggetto a forma di monitor di colore random,
  di dimensioni tali da avere altezza aspect ratio 16:9.
  Il bordo del monitor è spesso 5 pixel, anch'esso di colore random.
  Si muove in base alle sue velocità.
  Quando Monitor esce dalla parte destra dello schermo rientra dalla parte sinistra e viceversa.
  
  */  
 
  //Attributi
  float posX, posY;
  float vX;
  float w;
  float h;
  
  float r, g, b;
  float bR, bG, bB;
  
  //Costruttore
  Monitor(){
    this.w = 60;
    this.h = w * (9.0 / 16.0);
    
    this.posX = w/2 + 5 + 10; // w/2 è la distanza dal centro del monitor al bordo, 5 è la dimensione del bordo, e 10 è la dimensione richiesta di distanza tra il bordo della canvas e l'oggetto. ma viene comunque ritagliato
    this.posY = h/2 + 5 + 10;
    
    this.vX = 0;
    while(vX == 0){
      vX = random(-5, 5);
    }
    
    this.r = random(255);
    this.g = random(255);
    this.b = random(255);
      this.bR = random(255);
      this.bG = random(255);
      this.bB = random(255);
  }
      
    //Metodi
    void display(){
      
    stroke(bR, bG, bB);
    strokeWeight(5);
    
    fill(r, g, b);
    
    rectMode(CENTER);
    rect(posX,posY, w,h);
    line(posX,posY+h/2, posX,posY+h);
    line(posX-h/2,posY+h, posX+h/2,posY+h);
    }
  
    void move(){
    posX += 1 * vX;
    }
  
    void bounce(){
      if(posX-w/2 >= width){
        posX = -w/2;
      }else if(posX+w/2 <= 0){
        posX = width + w/2;
      }
    }
  
    void run(){
      display();
      move();
      bounce();
    }
  }
