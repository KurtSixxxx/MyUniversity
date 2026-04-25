/*
esempio 1: griglia di cerchi
size(800,500);
background(255);

//esempio cerchi con diametro uguale attaccati per lato(caso con corner, altri casi producono altre cose) 
ellipseMode(CORNER); //punto di partenza angolo superiore sinistro
//ellipseMode(CENTER); //centro ellisse
//ellipseMode(RADIUS); //centro dell'ellisse
//ellipseMode(CORNERS); //punto di partenza angolo superiore sinistro
int diametro = 50;
for(int j = 0; j < height; j/=diametro){ //controlla la posizione verticale dell'ellisse
  for(int i = 0; i < width; i/=diametro){ //controlla la posizione orizzontale dell'ellisse
    ellipse(i,j,diametro,diametro); //(coordinate angolo superiore,larghezza,altezza)
  }
}
(se sommo):Poiché i e j partono da 0 e aumentano, le ellissi vengono disegnate iniziando dall'angolo 
superiore sinistro del canvas e si muovono verso destra per ogni riga
con - diametro, * diametro, / diametro ottengo un ciclo infinito
*/
/*
esempio 2: pattern di linee convergenti verso destra colorate
size(500,450);
background(255);

int lf = 50; //offset di spazziatura verso destra
strokeWeight(20); //imposta lo spessore delle linee disegnate in seguito
for(int x = 0; x < width; x+=50){ //itera lungo l'asse orizzontale
  if((x+lf)<=width){ //condizione per evitare che non sconfinino oltre il bordo destro
   stroke(x%256,(x+70)%256,(x+450)%256); //
   line(x,0,x+lf,height/2);
   line(x,height,x+lf,height/2);
  }
}
*/
/*
esempio 3: disegno di una forma chiusa
size(500,400);
background(255);
beginShape();
vertex(120,200);
vertex(120,300);
vertex(200,120);
vertex(200,100);
endShape(CLOSE);
*/
/*
esempio 4: utilizzo modalità beginShape
size(500,400);
background(255);
fill(0,150,200);
noStroke();
beginShape(TRIANGLE_STRIP);
vertex(100, 100); // V1
vertex(100, 200); // V2
vertex(200, 100); // V3 -> Triangolo 1: V1, V2, V3
vertex(200, 200); // V4 -> Triangolo 2: V2, V3, V4
vertex(300, 100); // V5 -> Triangolo 3: V3, V4, V5
vertex(300, 200); // V6 -> Triangolo 4: V4, V5, V6
endShape(CLOSE);
*/
/*
esempio 5: esempi di quadrati con bordi diversi, giunzione del contorno
size(500,400);
background(255);
strokeWeight(20);
rect(50,25,70,70);
strokeJoin(ROUND);
rect(150,25,70,70);
strokeJoin(BEVEL);
rect(250,25,70,70);
strokeJoin(MITER);
rect(350,25,70,70);
println("Mi chiamo pippo");
*/
/*
esempio 6: strokeCap
size(500,450);
background(255);
strokeWeight(50);
strokeCap(SQUARE);
line(50,25,150,150);
strokeCap(PROJECT);
line(150,25,250,150);
strokeCap(ROUND);
line(250,25,350,150);
*/
/*
esempio 7: tipo di notazione colori
size(500,500);
background(255);
noStroke();
color yellow = #ffff00;
color red = color(255,0,0);
color green = color(0,255,0);
color blue = color(0,0,255);
fill(yellow);
ellipse(250,250,150,150);
fill(red);
ellipse(300,300,120,120);
fill(blue);
ellipse(500,100,200,200);
fill(green);
ellipse(200,200,120,120);
*/
/*
esempio 8: esempio di applicazione di noFill()
size(500,500);
background(255);
noFill();
ellipse(250,250,150,150);
rect(24,50,12,23);
*/
/*
esempio 9: canale di trasparenza(alpha)
size(800,500);
background(255);
noStroke();
fill(255,0,0);
ellipse(300,400,400,400);
fill(255,255,0,125);
ellipse(100,100,300,300);
*/
/*
esempio 10: mirino
size(500,500);
background(255);
noStroke();
fill(0);
ellipse(width/2,height/2,150,150);
fill(255);
ellipse(width/2,height/2,125,125);
fill(0);
ellipse(width/2,height/2,100,100);
fill(255);
ellipse(width/2,height/2,75,75);
fill(0);
ellipse(width/2,height/2,50,50);
fill(255);
ellipse(width/2,height/2,25,25);
*/
/*
//esempio 11: versione iterata mirino
//imposta la dimensione del canvas
void setup() {
  size(500,500);
  background(255);
  noStroke(); //rimuove il contorno dell'ellissi
}

void draw() {
  //calcola il centro del canvas
  float centerX = width/2;
  float centerY = height/2;
  
  //ciclo per disegnare i cerchi concentrici
  for(int diametro = 150; diametro >= 25; diametro-=25){
    //se il diametro è un multiplo di 50 il colore è nero, altrimenti è bianco
    if(diametro % 50 == 0){
      fill(0);
    }else{
      fill(255);
    }
    
    ellipse(centerX,centerY,diametro,diametro);
  }
}
*/
