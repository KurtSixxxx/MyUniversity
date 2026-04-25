class RocketPro extends Rocket{
   
  RocketPro(){
    super();
    posX = random(width/2 + widthR, width-widthR); ;
    posY = random(heightR, height-heightR);
    vY *= 2;
  }
  
    void display(){
    stroke(0);
    strokeWeight(3);
    fill(255,0,0);
    rect(posX, posY, widthR, heightR);
    triangle(posX,posY, posX+widthR/2,posY-heightR/2, posX+widthR,posY);
    
    float posYc = posY;
    float alpha = 150;
    fill(255,255,0, alpha);
    circle(posX+widthR/2, posYc+heightR, widthR);
    
    disegnaScia();
  }
  
void disegnaScia(){
  noStroke();
  
  // Facciamo un ciclo di 10 cerchi che "escono" dal fondo del razzo
  for (int i = 0; i < 10; i++) {
    // Calcoliamo l'opacità: più i è alto (cerchio lontano), più alpha è basso
    float alpha = 150 - (i * 15); 
    
    // Calcoliamo la dimensione: il cerchio si rimpicciolisce man mano
    float diametro = widthR - (i * 2);
    
    // Il colore diventa più arancione man mano che si allontana
    fill(255, 255 - (i * 20), 0, alpha);
    
    // Posizioniamo il cerchio sotto il razzo
    // L'aggiunta di (i * 5) sposta ogni cerchio un po' più in basso del precedente
    circle(posX + widthR/2, posY + heightR + (i * 5), diametro);
    }
  }
}

/*
Metto il cerchio giallo al centro in basso del rect
poi creo una sua posy, tipo posyCer
e faccio
posyCer = posY
poi faccio posyCer++
e metto anche che all'aumentare di posyCer diminuisce l'opacità gialla di colore
*/
