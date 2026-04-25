//In un ArrayList, il tipo viene dichiarato così: <Ball>, questa dichiarazione ha la peculiarità di poter includere nel nostro array di dimensione variabilà tutta la gerarchia delle classi, quindi classi padri e classi figlie
ArrayList <Ball> ab;

void setup(){
  size(800,500);
  ab = new ArrayList <Ball>(); //??????????
}

void draw(){
//Impostiamo che le palline lasciano la scia (che non ho capito come funziona)
noStroke();
fill(0,40);
rect(0,0,width,height);
  //Per scorrere gli elementi di un ArrayList che ha una dimensione variabile utilizziamo un for un po' "speciale"
  //Il for in questione: for (Ball b : ab)
  // per ogni elementi di 'ab' estrailo e mettilo in una variabile temporanea che si chiama 'b' ed è di tipo 'Ball'
  for(Ball b:ab){
  b.run();
  }
}

void keyPressed(){ //Se premiamo n aggiunge sulla canvas aggiunge una nuova pallina
  if (key == 'n' || key == 'N'){
    //vogliamo fare che appare randomicamente nello schermo
    ab.add(new Ball(random(50,450),random(50,450),random(25,70),random(1,10),random(1,10)));
  }
  
 switch(key){
 case 'p' :{ //premere p equivale a mettere in pausa
   noLoop();
   break;
  }
  
  case 's' :{ //premere s equivale a far ripartire
    loop();
    break;
  }
  
  default:{}
 }
}
