class Ball{
 //metodo costruttore
  float posX, posY, size; //definiamo posizione x, y e dimensione della pallina
  float sx, sy; //velocità per x e per y
  
  Ball(float x, float y, float s, float sx, float sy){ //così stiamo assegnando i parametri float a ciò che ci interessa.
    this.posX = x; //ad esempio io voglio che il primo parametro che passo sia il valore di posX
    this.posY = y;
    this.size = s;
    this.sx = sx;
    this.sy = sy;
  }
  
  Ball(float x, float y, float s){ //Questo è il numero di parametri che usiamo se..
  this(x,y,s,0,0); //...voglio umna pallina che sta ferma, infatti la velocirtà è a zero. Dunque qualora io passassi solo 3 valori avrò una pallina ferma
  }
  
  void display(){ //la funzione display si occupa della parte grafica della pallina
  fill(128,0,128); //colore
  noStroke(); //nessun bordo
  ellipse(posX, posY, size, size); //posizone e dimensione pallina
  }
  
  void move(){ //così ci gestiamo il la posizione e la velocità
    posX+=sx;
    posY+=sy;
    
    /*if (posY==height){
      sy=0;
    }*/
    }
  
  void bounce(){ //così ci gestiamo il rimbalzo della pallina
  //Poichè la pallina non deve uscire dalla canvas, impostiamo size/2, ossia il raggio della pallina, e poi il massimo della canvas meno il raggio
   if(posX < 0+size/2 || posX > width-size/2){ //rimbalzo a destra/sinistra
    sx=-sx; //e cambiamo la direzione
   }
   //la stessa cosa la si fa per l'asse y
   if(posY < 0+size/2 || posY > height-size/2){ //rimbalzo in alto/basso
    sy=-sy; //e cambiamo la direzione
    //posY=height-size/2;
   }
  }
  
  void gravity(){
  sy+=0.2; //la gravità ovviamente aumenta verso il basso, perché spinge verso il basso
  }
  
  void run(){ //invocando run si attiveranno tutti i metodi della classe Ball
    gravity();
    move();
    bounce();
    display();
  }
  
}
