/*
esempio 1: pacman
int dir = 1; //controlla la direzione orizzontale
int v = 4; //controlla la velocità
int r = 40; //definisce il raggio del corpo di pacman
int x = r; //controlla la posizione orizzontale del centro di pacman(coordinata x)
int a = 30; //ampiezza dell'apertura della bocca
int dira = -1; //direzione del movimento , -1 bocca si chiude, 1 bocca si apre

void setup() {
  size(800,500);
  ellipseMode(RADIUS);
}

void draw() {
  background(0);
  fill(255,255,0);
  //serve per fare il corpo di pacman
  if(dir == 1){
    arc(x,height/2,r,r,radians(a),radians(360-a));
  }
  if(dir == -1){
    arc(x,height/2,r,r,radians(180+a),radians(360+180-a));
  }
  
  fill(0);
  ellipse(x,height/2-20,3,3);
  
  if(x >= width-r || x < r){
    dir = -dir;
  }
  
  if(a > 30 || a < 0){
    dira = -dira;
  }
  //serve per fare muovere la bocca di pacman
  a+=dira;
  //serve per farlo muovere avanti e indietro
  x+=dir*v;
}
*/
/*
//esempio 2: mirino colorato loop
float [] r = new float[5]; //dichiarazione array di float che può contenere 5 elementi

void setup(){
  size(800,800);
  //ellipseMode in modalità default è posto in center
  for(int i = 0; i <r.length ;i++){ //sono i diametri dei cerchi
    r[i] = i * 100;
  }
}


void draw(){
  background(0);
  for(int i = r.length-1;i >= 0;i--){ //crea cerchi concentrici
    fill(random(255),random(255),random(255)); //imposta colori randomici
    ellipse(width/2,height/2,r[i],r[i]); 
  }
}
//serve per bloccare il disegno
void mousePressed(){
  noLoop();
}
//se lo rilascio mi fa il loop
void mouseReleased(){
  loop();
}

void keyPressed(){
  noLoop();
}

void keyReleased(){
  loop();
}
*/
/*
//esempio 3: movimento quadratino
int x = 20;//posizione x iniziale
int y; //posizione y iniziale(sarà impostata in setup)
int squareSize = 50; //dimensione del quadrato
int moveSpeed = 20;

void setup(){
  size(800,800);
  y = height / 2; //inizializza l'elemento al centro della canvas
  rectMode(CORNER); //il rettangolo è disegnato nell'angolo superiore sinistro
}

void draw(){
  background(0);
  fill(255);
  rect(x,y,squareSize,squareSize);
}

void keyPressed(){
  if(key == CODED){
    if(keyCode == LEFT){
      x-=moveSpeed;
    }
    if(keyCode == RIGHT){
      x+=moveSpeed;
    }
    if(keyCode == UP){
      y-=moveSpeed;
    }
    if(keyCode == DOWN){
      y+=moveSpeed;
    }
  }
  
  if(x < 0){
    x = 0;
  }
  if(x > width - squareSize){
    x = width - squareSize;
  }
  if(y < 0){
    y = 0;
  }
  if(y > width - squareSize){
    y = height - squareSize;
  }
}
*/
/*
esempio 4: resetta background randomico
int l = 50;
boolean aKeyWasPressed = false; 

void setup(){
  size(500,500);
  background(0,255,0);
  noStroke();
  
  for(int y = 0; y < height; y+=l){
    for(int x = 0; x < width; x+=l){
      fill(random(250),130);
      rect(x+random(-5,5),y+random(-5,5),l,l);
    }
  }
}

void draw(){
  if(mousePressed){
    if(mouseButton==LEFT){
      println("left");
    }
    if(mouseButton==RIGHT){
      println("right");
    }
  }
  if(keyPressed){
    if(key == 'a'){
      println("hai premuto il tasto a");
      aKeyWasPressed = true;
    }
  }
}

void keyReleased(){
  if(key == 'a'){
    aKeyWasPressed = false;
  }
}

void mousePressed(){
  setup();
}
*/
/*
esempio 6: linea in loop con stop e restart
int pos = 0;
int dir = 1;
int vel = 3;

void setup(){
  size(500,500);
}

void draw(){
  background(255);
  stroke(0);
  strokeWeight(2);
  
  line(pos,0,pos,height);
  if(pos > width || pos < 0){
    dir = -dir;
  }
  pos+=dir*vel;
}

void keyPressed(){
    if(key == 'a'){
      noLoop();
      println("Animazione stoppata, premi s per ripartire");
    }
    if(key == 's'){
      loop();
      println("Animazione ripartita");
    }
}
*/
/*
esempio 7: stringhe che si muovono(mouseX,mouseY)
void setup(){
  size(800,800);
  noFill();
}

void draw(){
  background(155);
  textSize(40);
  text("A1",185,50);
  text("C1",mouseX,mouseY);
  stroke(255,0,0);
  line(185,50,mouseX,mouseY);
  stroke(0);
  bezier(185,50,mouseX,mouseY,190,300,15,300);
}
*/
/*
esempio 8: pacman versione più semplice con PIE
size(800,800);
background(255);
fill(255,255,0);
arc(100,height/2,100,100,radians(30),radians(330),PIE);
*/
/*
esempio 9: pacman scomposto per utilizzare PI,HALF_PI,ecc.
size(800,800);
background(0);
fill(255,255,0);
//0-90
arc(100,height/2,100,100,0,HALF_PI);
//0-270
arc(200,height/2,100,100,0,PI+HALF_PI);
//errore PI>0
arc(300,height/2,100,100,PI,0);
arc(400,height/2,100,100,PI,TWO_PI);
arc(500,height/2,100,100,PI,2*PI);
arc(600,height/2,100,100,QUARTER_PI,HALF_PI);
arc(700,height/2,100,100,0,radians(30));
*/
/*
esempio 10: schema di ellissi con movimento mouse con cambio colore
int d=50;
void setup(){
 
  size(800,800);
  background(255,255,0);
  colorMode(RGB,width);
}
void draw(){
  //println(mouseX+" - "+mouseY);
  for(int y=d/2; y<height; y+=d)
  {
    for(int x=d/2; x<width; x+=d)
    {
      if(dist(x,y,mouseX,mouseY)<d/2)
      {
        fill(0,0,width);
      }
      else
      {
        fill(x,y,0);
      }  
      ellipse(x,y,d,d);
    }
  }
}
*/
/*
//esempio 11: apparizione temporanea del cerchio
void setup()
{
  size(500,500);
  background(0);
  println("Sono nel setup");
  frameRate(60);
}

void draw(){

  if(millis()>15000 && millis()<16000)
  ellipse(width/2,height/2,50,50);
  
}
*/
/*
esempio 12: quadrati in sequenza trasparenti in diagonale principale
size(500,500);
background(255);
noStroke();
fill(220,220,220,100);
int passo=15;
int lato=100;
for(int x=0; x<width; x+=passo)
{
  //if(x+lato<width && x+lato<height)
  rect(x,x,lato,lato);
}
*/
