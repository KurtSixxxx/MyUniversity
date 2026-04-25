void setup(){
  size(500,500);
}

void draw(){
  if(mousePressed){ //E' una variabile booleana. False se non premiamo nulla, True se premiamo qualcosa.
    //mouseButton conserva quale abbiamo premuto
    //mouseButton è una variabile di tipo intero
    if(mouseButton==LEFT){ //Se premiamo tasto sinistro stampa L
      println("L");
  }
    if(mouseButton==RIGHT){ //Se premiamo tasto destro stampa R
      println("R");
    }
  }
  
  if(keyPressed){ //keyPressed è booleana come mousePressed
  //key è una funzione di tipo char
    if(key == 'a' || key == 'A'){
      println("ho premuto 'a'");
    }
  }
}