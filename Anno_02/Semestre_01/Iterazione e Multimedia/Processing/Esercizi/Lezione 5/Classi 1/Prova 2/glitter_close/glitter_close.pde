// Iniziamo dichiarando la lista. In C sarebbe come definire un puntatore a una struttura dinamica.
// La dicitura <Ball> è il "filtro": diciamo alla lista che può contenere solo oggetti Ball o i suoi "figli".
ArrayList <Ball> ab;

void setup(){
  size(800,500);
  
  // INIZIALIZZAZIONE: Qui creiamo fisicamente la "borsa" (la lista) in memoria.
  // Senza il 'new', la variabile 'ab' è vuota (NULL). È come fare una malloc in C: 
  // stiamo chiedendo lo spazio per far esistere la lista.
  ab = new ArrayList <Ball>(); 
}

void draw(){
  // EFFETTO SCIA (Trail): Invece di usare background() che pulisce tutto ogni volta, 
  // disegnamo un rettangolo nero grande quanto lo schermo ma quasi trasparente (opacità 40).
  // I disegni precedenti rimangono sotto, ma vengono "velati" di nero un po' alla volta 
  // fino a sparire, creando l'illusione della scia.
  noStroke();
  fill(0,40);
  rect(0,0,width,height);

  // CICLO FOR-EACH: È un modo rapido per dire a Processing:
  // "Prendi ogni pallina che trovi dentro la lista 'ab', chiamala 'b' per un istante, 
  // e fagli fare quello che c'è scritto tra le graffe".
  for(Ball b : ab){
    // Diciamo alla singola pallina 'b' di attivare la sua routine di vita.
    b.run();
  }
}

void keyPressed(){ 
  // Se premiamo 'n' o 'N', fabbrichiamo una nuova pallina e la infiliamo nella borsa (add).
  if (key == 'n' || key == 'N'){
    // Creiamo una pallina con posizione, dimensione e velocità casuali (random).
    ab.add(new Ball(random(50,450), random(50,450), random(25,70), random(1,10), random(1,10)));
  }
  
  // Lo switch gestisce lo stato della canvas (Pausa o Riparti).
  switch(key){
    case 'p' :{ 
      noLoop(); // Blocca il ciclo draw(): tutto si ferma come in un fermo immagine.
      break;
    }
    
    case 's' :{ 
      loop();   // Riattiva il ciclo draw(): il tempo ricomincia a scorrere.
      break;
    }
    
    default:{}
  }
}
