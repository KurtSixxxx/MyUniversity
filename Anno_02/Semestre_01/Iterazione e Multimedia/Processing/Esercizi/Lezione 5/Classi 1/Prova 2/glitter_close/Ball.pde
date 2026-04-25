class Ball {
  // ATTRIBUTI: Le caratteristiche fisiche che ogni pallina "sa" di avere.
  float posX, posY, size; 
  float sx, sy; 

  // COSTRUTTORE PRINCIPALE: È il momento in cui la pallina "nasce".
  // Prende i valori che arrivano da fuori e li salva dentro le sue variabili (this).
  Ball(float x, float y, float s, float sx, float sy){ 
    this.posX = x; 
    this.posY = y;
    this.size = s;
    this.sx = sx;
    this.sy = sy;
  }
  
  // SECONDO COSTRUTTORE (Overloading): Per creare palline ferme.
  Ball(float x, float y, float s){ 
    // TRUCCO: Questo 'this(...)' dice a Processing di non riscrivere tutto il codice sopra,
    // ma di usare il costruttore principale passando però 0 come velocità X e Y.
    // È una scorciatoia per dire: "Fai tutto come sopra, ma forzala a stare immobile".
    this(x,y,s,0,0); 
  }
  
  void display(){ 
    fill(128,0,128); // Viola
    noStroke(); 
    ellipse(posX, posY, size, size); // Disegna la forma usando le sue coordinate.
  }
  
  void move(){ 
    // Aggiorniamo la posizione aggiungendo la velocità: lo spazio si percorre nel tempo.
    posX += sx;
    posY += sy;
  }
  
  void bounce(){ 
    // RIMBALZO X: Se tocca il bordo sinistro (0) o destro (width), invertiamo la velocità X.
    if(posX < size/2 || posX > width - size/2){ 
      sx = -sx; 
    }
    
    // RIMBALZO Y: Se tocca il bordo alto (0) o basso (height), invertiamo la velocità Y.
    // Usiamo size/2 perché la coordinata di una pallina è nel centro, quindi dobbiamo contare il raggio.
    if(posY < size/2 || posY > height - size/2){ 
      sy = -sy; 
      // Nota: Qui c'è il rischio teletrasporto se tocca il tetto, ma la logica è:
      // "Se hai colpito un bordo verticale, cambia direzione!"
    }
  }
  
  void gravity(){
    // La gravità è un'accelerazione: aggiunge costantemente un piccolo valore alla velocità Y.
    // Più passa il tempo, più la pallina "cade" velocemente.
    sy += 0.2; 
  }
  
  void run(){ 
    // Questo è il "Cervello": raggruppa tutte le azioni in ordine logico.
    // Prima calcoliamo la fisica, poi mostriamo il risultato.
    gravity();
    move();
    bounce();
    display();
  }
}
