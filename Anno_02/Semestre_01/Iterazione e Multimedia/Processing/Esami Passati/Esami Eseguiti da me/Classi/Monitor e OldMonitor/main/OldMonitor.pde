class OldMonitor extends Monitor{
  
  /*
  Estendere tramite ereditarietà la classe Monitor definendo OldMonitor.
  Questi differisce da Monitor poiché i suoi colori sono Verde (schermo) e Grigio (bordo),
  e la sua dimensione ha medesima lunghezza del monitor, ma aspect ratio a 4:3.
  In aggiunta, fintato che il puntatore del mouse si trova approssimativamente all'interno di OldMonitor, l'oggetto resta immobile.
  */

  //Costruttore
  OldMonitor(){
    super();
    this.h = w * (3.0 / 4.0);
    
    this.posX = 60+10;
    this.posY = height - (h/2 + 5 + 30);
  }
  
    void display(){

    stroke(127);
    strokeWeight(5);
    
    fill(0, 255, 0);
    
    rectMode(CENTER);
    rect(posX,posY, w,h);
    line(posX,posY+h/2, posX,posY+h);
    line(posX-h/2,posY+h, posX+h/2,posY+h);
    }
    
    void move() {
  // Se NON è vero che il mouse è dentro il rettangolo...
   if ( !(mouseX > posX - w/2 && mouseX < posX + w/2 && mouseY > posY - h/2 && mouseY < posY + h/2)) {
    super.move(); // ...allora muoviti come un Monitor normale
  }
}
  
}
