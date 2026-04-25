class AutoElettrica extends Auto{

  //Attributi
  color c;
  
  //Costruttore
  AutoElettrica(){
    super(); // 1. Chiama il costruttore di Auto (crea w, h, posX, ecc.)
    
    // 2. Sovrascrivi solo quello che deve essere diverso
    vX = vX * 2; 
    posY = (height * 2) / 3.0; // Questa va in basso
    c = color(0, random(30, 255), 0); // Colore verde random
  }
  
   void display(){
    noStroke();
    fill(c);
    rectMode(CORNER);
    rect(posX,posY, w,h);
    
    fill(0);
    ellipse((posX + (w / 3.0)), (posY + h), diameter, diameter); // Ruota 1
    ellipse((posX + (w * 2 / 3.0)), (posY + h), diameter, diameter); // Ruota 2
    
    //Triangolo equilatero giallo al centro dell'auto
    fill(255,255,0);
    triangle((posX+w/2), (posY+5), posX + (w/3.0), (posY+h-5), posX + (w*2/3.0), (posY+h-5));
    }
    
 }
