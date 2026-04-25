/*esempio 1: pallina che rimbalza
float y = 25;
float x;
float speed = 0;
float gravity = 0.1;

void setup(){
  size(800,800);
  x = width/2;
}

void draw(){
  background(255);
  fill(255,0,0);          // colore rosso per la pallina
  stroke(0,0,255);         // bordo blu
  ellipse(x, y, 50, 50);   // disegna la pallina

  // Applica la gravità alla velocità
  speed = speed + gravity;

  // Aggiorna la posizione
  y = y + speed;

  // Rimbalzo se tocca il suolo
  if (y > height - 25) {
    y = height - 25;       // corregge posizione per evitare "sprofondamento"
    speed = speed * -0.65; // rimbalzo smorzato
  }
}
*/
/*esempio 2: rumore,sbarre che si muovono
void setup(){
  size(800,800);
}

void draw(){
  background(200);
  for(int x = 40; x < width; x+=40){
    //float rum = mouseX/10; //se sposto il mouse verso sinistra aumenta il rumore
    float rum = map(mouseX,0,width,0,width/10);
    float rumi = random(-rum,+rum);
    float rumf = random(-rum,+rum);
    
    line(x+rumi,100,x+rumf,height-100);
  }
}
*/
/*esempio 3: pallina con mouse che si sposta dal vuoto al centro
int raggio = 50;
float lato = raggio*sqrt(2);
float move = lato/2;
float x,y;

void setup(){
  size(500,500);
  ellipseMode(RADIUS);
}

void draw(){
  background(100);
  fill(255);
  ellipse(width/2,height/2,raggio,raggio);//i primi due servono per posizionare l'oggetto,gli ultimi due servono per la dimensione
  x = map(mouseX,0,width,-move,move);
  y = map(mouseY,0,height,-move,move);
  fill(0);
  ellipse(x+width,y+width/2,100,100);
}
*/
/*esempio 4: pallina che si muove lasciando scia
float x,y;

void setup(){
  size(700,700);
  background(0);
}

void draw(){
  x = map(mouseX,0,width,250,450);
  y = map(mouseY,0,height,250,450);
  ellipse(x,y,40,40);
}
*/
/*esempio 5: se allontano verso x aumenta la dimensione della pallina,se avvicino riduco la dimensione
void setup(){
  size(700,700);
}

void draw(){
  background(100);
  float r = map(mouseX,0,width,20,250);
  ellipse(width/2,height/2,r,r);
  println(r);
}
*/
/*esempio 5: cerchio che aumenta e riduce la dimensione, se non presso esso continua ad aumentare la propria dimensione
int x,y;
int r = 30;
int dir = 1;

void setup(){
  size(500,500);
  x = width/2;
  y = height/2;
  ellipseMode(RADIUS);
}

void draw(){
  background(200);
  float d = dist(x,y,mouseX,mouseY);
  if(r==20 || r>width/2)
  dir = -dir;
  
  if(d > r){
   r+=dir;
   fill(0);
  }else{
    fill(255);
  }
  ellipse(x,y,r,r);
}
*/
/*esempio 6: quadrattini che cadono in cascata randomici
float[] y = new float[1000];
int v = 1;
float moltiplicatore;

void setup(){
  size(500,500);
  noStroke();
  fill(random(255),random(255),random(255));
  for(int i = 0; i < y.length; i++){
    y[i] = random(-1000,0);
  }
  moltiplicatore = width/float(y.length);
}

void draw(){
  background(0);
  for(int i = 0; i < y.length;i++){
    y[i]+=v;
    float x = i*moltiplicatore;
    rect(x,y[i],20,30);
  }
}
*/
/*esempio 7: tipo tela paint, disegno con mouse
void setup(){
  size(500,500);
  stroke(255,0,0);
  strokeWeight(10);
  background(255);
}

void draw(){
  if(mousePressed){
    line(pmouseX,pmouseY,mouseX,mouseY);
  }
  if(keyPressed){
    if(key=='y'){
      stroke(255,255,0);
    }
  }
}

void keyPressed(){
  if(key=='g')
  stroke(0,255,0);//cambia colore
  
  if(key=='b')
  stroke(0,0,255);
  
  if(key=='r')
  stroke(255,0,0);
  
  if(key=='c')
  stroke(random(255),random(255),random(255));
  
  if(key==' ')
  background(255);
  
}
*/
/*esempio 7:pallina che si muove e lascia scia
float x,y;
void setup(){
  size(700,700);
  noStroke();
  //frameRate(2);
}

void draw(){
  fill(0,25);
  rect(0,0,width,height);
  fill(255);
  x = lerp(x,mouseX,0.1);
  y = lerp(y,mouseY,0.1);
  ellipse(x,y,60,60);
}
*/
/*esempio 8: interpolazione pallina che è distanziata di 0.1
size(700,700);
int x1=10;//P0
int y1=10;//P0
int x2 = 300;//P1
int y2 = 300;

for(int i = 0; i <= 10; i++){
  strokeWeight(15);
  stroke(255,0,0);
  float perc=i/10.0;
  float x = lerp(x1,x2,perc);
  float y = lerp(y1,y2,perc);
  println(perc);
  point(x,y);
}
*/
