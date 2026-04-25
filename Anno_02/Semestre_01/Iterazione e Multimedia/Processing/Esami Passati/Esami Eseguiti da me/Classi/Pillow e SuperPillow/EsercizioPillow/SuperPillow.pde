class SuperPillow extends Pillow{
  
   float angle;
   
   SuperPillow(){
     super();
     x = random(w, width - w);
     y = random(height/2 + h, height - h);
     angle = random(0,360);
   }
   
   void display() {
  noStroke();
  rectMode(CENTER); // Fondamentale per ruotare attorno al centro

  pushMatrix();
    // 1. Sposta l'origine nel punto (x,y)
    translate(x, y); 
    // 2. Ruota il sistema di coordinate
    rotate(radians(angle)); 
    
    // 3. DISEGNA QUI (usando 0,0 come coordinate perché hai già traslato)
    fill(255);
    rect(0, 0, h, w); // Il rettangolo ora ruota
    
    fill(128);
    ellipse(0, 0, w, w); // Anche l'ellisse ruota
  popMatrix();
}

   void move(){
    if(dist(x,y, mouseX,mouseY) <= w/2){
        angle += 5;    
    }
  }
}
